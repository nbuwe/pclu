/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		ARRAY IMPLEMENTATION		*/
/*						*/
/*						*/

/* FIX: since low can be a negative number and size can be greater
 * 	than all positive numbers need to change int_low from having
 * 	a minimum of 0
 */

/* Mystery -- how is array bounds (not size) overflow detected?
 * May be necessary to strengthen rep invariant for detecting bounds
 * overflow.
 */

/* NOTA BENE: if rep changes, look at sequence$s2a, a2s    */

#include "pclu_err.h"
#include "pclu_sys.h"

/*
 * Work around a bug in gc-7.x that defines GC_jmp_buf in gc_priv.h
 * instead of declaring it.  Make it work with -fno-common.
 */
#define GC_jmp_buf GC_jmp_buf_libasm_array
#include <gc/private/gc_priv.h>

errcode gcd_tabOPinsert(CLUREF tab, CLUREF z, CLUREF inf, CLUREF x, CLUREF *ans);
errcode intOPprint(CLUREF i, CLUREF pst);
errcode istreamOPgeti(CLUREF ist, CLUREF *ret_1);
errcode istreamOPputi(CLUREF ist, CLUREF i);
errcode pstreamOPget_max_width(CLUREF ps, CLUREF *ret_1);
errcode pstreamOPpause(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPstart(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPstop(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPtext(CLUREF ps, CLUREF s, CLUREF *ret_1);

errcode arrayOPinternal_print(CLUREF a, CLUREF pst, CLUREF pfcn);


/*
 * What array[T] requires of T.
 */
static struct /* REQS */ {
    long count;
    struct REQ_ENTRY entry[8];
} array_of_t_reqs_actual = {
    8, {
	{ "equal" },
	{ "copy" },
	{ "similar" },
	{ "print" },
	{ "encode" },
	{ "decode" },
	{ "_gcd" },
	{ "debug_print" },
    }
};

const struct REQS * const array_of_t_reqs
    = (const struct REQS *)& array_of_t_reqs_actual;


/*
 * An interface to T for an array[T] instance (as specified by REQS).
 */
typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY equal;
    struct OP_ENTRY copy;
    struct OP_ENTRY similar;
    struct OP_ENTRY print;
    struct OP_ENTRY encode;
    struct OP_ENTRY decode;
    struct OP_ENTRY _gcd;
    struct OP_ENTRY debug_print;
} array_of_t_OPS;


/*
 * Own data of an array[T] instance.
 */
typedef struct /* OWN_ptr */ {
    long array_own_init;	/* unused */
    const array_of_t_OPS * const t_ops;
} array_OWN_DEFN;


/*
 * Tell instantiation code how to construct an _OWN_DEFN object for an
 * instantce.  What "own_count" really tells is where the parameters
 * start (OPS for types, values for constants).
 */
const OWN_req array_ownreqs = { sizeof(array_OWN_DEFN), 1 };



#ifdef DEBUG_ARRAY
void
assertfailed()
{
}


static void
check_RI(CLUREF a)
{
    if (! ((a.array->int_size >= 0) &&
	   (a.array->int_low >= 0) &&
	   (a.array->ext_size >= 0) &&
	   (a.array->ext_size == a.array->ext_high - a.array->ext_low + 1) &&
	   (a.array->int_low + a.array->ext_size <= a.array->int_size) &&
	   (a.array->int_size == a.array->store->size)))
	assertfailed();
}
#endif	/* DEBUG_ARRAY */


/*
 * Computes the minimum size (number of elements) actually allocated
 * for an array of size n.  Knows secrets about the storage manager.
 */
long
arrayOPOPminimum_size(long n)
{
    long store_size = BYTES_TO_WORDS(offsetof(CLU_store, data));
    long ans;

    ans = n + store_size;
#ifndef LINUX
    if (ans < MAXOBJSZ) {
#ifdef MERGE_SIZES
	extern long size_map[];
	ans = size_map[ans];
#endif
    }
    else {
	ans = WORDS_TO_BYTES(ans) + sizeof(struct hblkhdr);
	ans = (ans + HBLKMASK) & ~HBLKMASK;
	ans = BYTES_TO_WORDS(ans - sizeof(struct hblkhdr));
    }
#endif
    return (ans - store_size);
}


/*
 * Computes a desirable internal size for an array with n elems.
 * Assumes the array may continue to grow.
 * Ensures result >= n.
 * Knows secrets about the storage manager.
 */
long
arrayOPOPsize_for_growth(long n)
{
    long pad = n >> 2;
    long max_pad = BYTES_TO_WORDS(HBLKSIZE - offsetof(CLU_store, data));
    long min_pad = 2;

    if (pad < min_pad)
	pad = min_pad;
    if (pad > max_pad)
	pad = max_pad;

    return (n + pad);
}


errcode
arrayOPOPnewdesc(CLUREF *ans)
{
    CLUREF desc;
    clu_alloc(sizeof(CLU_array), &desc);
    CLUTYPE_set(desc.array->typ, CT_ARRAY);

    *ans = desc;
    signal(ERR_ok);
}


errcode
arrayOPOPnewstore(CLUREF desc, long size)
{
    size = arrayOPOPminimum_size(size);

    CLUREF store;
    clu_alloc(offsetof(CLU_store, data) + size * sizeof(CLUREF), &store);
    CLUTYPE_set(store.store->typ, CT_STORE);
    store.store->size = size;

    desc.array->store = store.store;
    desc.array->int_low = 0;
    desc.array->int_size = size;

    signal(ERR_ok);
}


errcode
arrayOPcreate(CLUREF low, CLUREF *ans)
{
#if 0 /* ODD DWC */
    if (low.num < (long)MIN_ARR_INDEX) {
	elist[0].str = array_bounds_overflow_STRING;
	signal(ERR_failure);
    }
#endif

    /* allocate array descriptor */
    CLUREF desc;
    clu_alloc(sizeof(CLU_array), &desc);
    CLUTYPE_set(desc.array->typ, CT_ARRAY);

    /* allocate storage for data */
    CLUREF store;
    clu_alloc(sizeof(CLU_store), &store);
    CLUTYPE_set(store.store->typ, CT_STORE);
    store.store->size = 1;

    desc.array->store = store.store;
    desc.array->int_low = 0;
    desc.array->int_size = 1;
    desc.array->ext_low = low.num;
    desc.array->ext_size = 0;
    desc.array->ext_high = low.num - 1;

#ifdef DEBUG_ARRAY
    check_RI(desc);
#endif
    *ans = desc;
    signal(ERR_ok);
}


errcode
arrayOPnew(CLUREF *ans)
{
    /* allocate array descriptor */
    CLUREF desc;
    clu_alloc(sizeof(CLU_array), &desc);
    CLUTYPE_set(desc.array->typ, CT_ARRAY);

    /* allocate storage for data */
    CLUREF store;
    clu_alloc(sizeof(CLU_store), &store);
    CLUTYPE_set(store.store->typ, CT_STORE);
    store.store->size = 1;

    desc.array->store = store.store;
    desc.array->int_low = 0;
    desc.array->int_size = 1;
    desc.array->ext_low = 1;
    desc.array->ext_size = 0;
    desc.array->ext_high = 0;

#ifdef DEBUG_ARRAY
    check_RI(desc);
#endif
    *ans = desc;
    signal(ERR_ok);
}


errcode
arrayOPpredict(CLUREF low, CLUREF size, CLUREF *ans)
{
    long s;

#if 0 /* ODD... DWC */
    if (low.num < MIN_ARR_INDEX) {
	printf ("low.num %d\n", low.num);
	printf ("((long)MIN_ARR_INDEX) %d\n", ((long)MIN_ARR_INDEX));
	elist[0].str = array_bounds_overflow_STRING;
	signal(ERR_failure);
    }
#endif

    if (size.num >= 0)
	s = size.num;
    else
	s = - size.num;
    if (s > (long)MAX_ARR_SIZE)
	s = (long)MAX_ARR_SIZE;

    /* NORMALIZE size */
    s = arrayOPOPminimum_size(s);

    /* allocate array descriptor */
    CLUREF desc;
    clu_alloc(sizeof(CLU_array), &desc);
    CLUTYPE_set(desc.array->typ, CT_ARRAY);

    /* allocate storage for data */
    CLUREF store;
    clu_alloc(offsetof(CLU_store, data) + s * sizeof(CLUREF), &store);
    CLUTYPE_set(store.store->typ, CT_STORE);
    store.store->size = s;

    desc.array->store = store.store;
    desc.array->int_low = 0;
    desc.array->int_size = s;
    desc.array->ext_low = low.num;
    desc.array->ext_size = 0;
    desc.array->ext_high = low.num - 1;

    *ans = desc;
    signal(ERR_ok);
}


errcode
arrayOPcons(CLUREF q, CLUREF *ans)
{
    CLUREF temp;
    arrayOPOPnewdesc(&temp);
    arrayOPOPnewstore(temp, q.vec->size);

    for (long i = 0 ; i < q.vec->size; ++i) {
	temp.array->store->data[i] = q.vec->data[i];
    }
    temp.array->ext_low = 1;
    temp.array->ext_size = q.vec->size;
    temp.array->ext_high = q.vec->size;

#ifdef DEBUG_ARRAY
    check_RI(temp);
#endif
    *ans = temp;
    signal(ERR_ok);
}


errcode
arrayOPcons2(CLUREF low, CLUREF q, CLUREF *ans)
{
    CLUREF temp;
    arrayOPOPnewdesc(&temp);
    arrayOPOPnewstore(temp, q.vec->size);

    for (long i = 0 ; i < q.vec->size; ++i) {
	temp.array->store->data[i] = q.vec->data[i];
    }
    temp.array->ext_low = low.num;
    temp.array->ext_size = q.vec->size;
    temp.array->ext_high = low.num + q.vec->size - 1;

#ifdef DEBUG_ARRAY
    check_RI(temp);
#endif
    *ans = temp;
    signal(ERR_ok);
}


#if 0
errcode
arrayOP_cons2(CLUREF low, CLUREF q, CLUREF *ans)
{
}
#endif


errcode
arrayOPempty(CLUREF a, CLUREF *ans)
{
    if (a.array->ext_size == 0)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
arrayOPlow(CLUREF a, CLUREF *ans)
{
    ans->num = a.array->ext_low;
    signal(ERR_ok);
}


errcode
arrayOPhigh(CLUREF a, CLUREF *ans)
{
    ans->num = a.array->ext_high;
    signal(ERR_ok);
}


errcode
arrayOPsize(CLUREF a, CLUREF *ans)
{
    ans->num = a.array->ext_size;
    signal(ERR_ok);
}


errcode
arrayOPset_low(CLUREF a, CLUREF low)
{
#ifdef DEBUG_ARRAY
    check_RI(a);
#endif
#if 0
    if (low.num < (long)MIN_ARR_INDEX || low.num > (long)MAX_ARR_INDEX) {
	elist[0].str = array_bounds_overflow_STRING;
	signal(ERR_failure);
    }
#endif
    a.array->ext_low = low.num;
    a.array->ext_high = low.num + a.array->ext_size - 1;

#ifdef DEBUG_ARRAY
    check_RI(a);
#endif
    signal(ERR_ok);
}


errcode				/* signals bounds, negative_size */
arrayOPtrim(CLUREF a, CLUREF low, CLUREF size)
{
#ifdef DEBUG_ARRAY
    check_RI(a);
#endif
    if (low.num < a.array->ext_low)
	signal(ERR_bounds);
    if (size.num > a.array->ext_size)
	signal(ERR_bounds);
    if (size.num < 0)
	signal(ERR_negative_size);

    a.array->ext_low = low.num;
    if (size.num < a.array->ext_size)
	a.array->ext_size = size.num;
    a.array->ext_high = low.num + size.num - 1;

#ifdef DEBUG_ARRAY
    check_RI(a);
#endif
    signal(ERR_ok);
}

errcode				/* signals negative_size */
arrayOPfill(CLUREF low, CLUREF size, CLUREF elt, CLUREF *ans)
{
    if (size.num < 0)
	signal(ERR_negative_size);
#if 0
    if (low.num < (long)MIN_ARR_INDEX) {
	elist[0].str = array_bounds_overflow_STRING;
	signal(ERR_failure);
    }
#endif
    if (low.num + size.num > (long)MAX_ARR_SIZE) {
	elist[0] = array_bounds_overflow_STRING;
	signal(ERR_failure);
    }

    CLUREF temp;
    arrayOPOPnewdesc(&temp);
    arrayOPOPnewstore(temp, size.num);

    temp.array->ext_low = low.num;
    temp.array->ext_size = size.num;
    temp.array->ext_high = low.num + size.num - 1;

    for (long i = 0; i < size.num; ++i) {
	temp.array->store->data[i] = elt.num;
    }

#ifdef DEBUG_ARRAY
    check_RI(temp);
#endif
    *ans = temp;
    signal(ERR_ok);
}


/* use t$copy */
errcode				/* signals negative_size */
arrayOPfill_copy(CLUREF low, CLUREF size, CLUREF elt, CLUREF *ans)
{
    const array_of_t_OPS *ops
	= ((array_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;
    CLUREF temp;
    errcode err;
    long i;

    if (size.num < 0)
	signal(ERR_negative_size);
#if 0
    if (low.num < (long)MIN_ARR_INDEX) {
	elist[0].str = array_bounds_overflow_STRING;
	signal(ERR_failure);
    }
#endif
    if (low.num + size.num > (long)MAX_ARR_SIZE) {
	elist[0] = array_bounds_overflow_STRING;
	signal(ERR_failure);
    }

    arrayOPOPnewdesc(&temp);
    arrayOPOPnewstore(temp, size.num);

    temp.array->ext_low = low.num;
    temp.array->ext_size = size.num;
    temp.array->ext_high = low.num + size.num - 1;

    CLUREF tOPcopy = { .proc = ops->copy.fcn };
    for (i = 0; i < size.num; ++i) {
	CUR_PROC_VAR = tOPcopy;
	err = (*tOPcopy.proc->proc)(elt, &temp.array->store->data[i]);
	if (err != ERR_ok)
	    resignal(err);
    }

#ifdef DEBUG_ARRAY
    check_RI(temp);
#endif
    *ans = temp;
    signal(ERR_ok);
}


errcode 			/* signals bounds */
arrayOPfetch(CLUREF a, CLUREF idx, CLUREF *ans)
{
    long int_index;		/* internal index */

    if (idx.num < a.array->ext_low || idx.num > a.array->ext_high)
	signal(ERR_bounds);

    int_index = idx.num - a.array->ext_low + a.array->int_low;
    ans->num = a.array->store->data[int_index];
    signal(ERR_ok);
}


errcode 			/* signals bounds */
arrayOPbottom(CLUREF a, CLUREF *ans)
{
    if (a.array->ext_size == 0)
	signal(ERR_bounds);

    ans->num = a.array->store->data[a.array->int_low];
    signal(ERR_ok);
}


errcode 			/* signals bounds */
arrayOPtop(CLUREF a, CLUREF *ans)
{
    if (a.array->ext_size == 0)
	signal(ERR_bounds);

    ans->num = a.array->store->data[a.array->int_low + a.array->ext_size - 1];
    signal(ERR_ok);
}


errcode				/* signals bounds */
arrayOPstore(CLUREF a, CLUREF idx, CLUREF elt)
{
    long int_index;		/* internal index */

    if (idx.num < a.array->ext_low || idx.num > a.array->ext_high)
	signal(ERR_bounds);

    int_index = idx.num - a.array->ext_low + a.array->int_low;
    a.array->store->data[int_index] = elt.num;

#ifdef DEBUG_ARRAY
    check_RI(a);
#endif
    signal(ERR_ok);
}


/* arrayOPOPsize_for_growth should be tuned */

errcode
arrayOPaddh(CLUREF a, CLUREF elt)
{
    long new_size, ext_size, int_low;

#ifdef DEBUG_ARRAY
    check_RI(a);
#endif
    ext_size = a.array->ext_size;
    int_low = a.array->int_low;

    if (ext_size >= (long)MAX_ARR_SIZE) {
	elist[0] = array_bounds_overflow_STRING;
	signal(ERR_failure);
    }

    if (a.array->ext_size == 0)
	a.array->int_low = int_low = 0;

    if (a.array->int_size <= ext_size + int_low) {
	new_size = arrayOPOPsize_for_growth(ext_size + 1);
	if (new_size <= a.array->int_size) {
	    /* Shift data to low end.  ENHANCE: Consider shrinking a. */
	    memmove(&a.array->store->data[0],
		    &a.array->store->data[int_low],
		    ext_size * sizeof(CLUREF));
	    /* trash garbage pointers */
	    memset(&a.array->store->data[ext_size], '\0',
		   int_low * sizeof(CLUREF));
	    a.array->int_low = int_low = 0;
	}
	else {
	    /* Allocate new store. */
#define gc_free GC_free
	    extern void gc_free();
	    CLUSTORE old_store = a.array->store;

	    arrayOPOPnewstore(a, new_size);
	    memcpy(&a.array->store->data[0],
		   &old_store->data[int_low],
		   ext_size * sizeof(CLUREF));
	    gc_free(old_store);
	    int_low = 0;
	}
    }

    a.array->store->data[int_low + ext_size] = elt.num;
    a.array->ext_size += 1;
    a.array->ext_high += 1;

#ifdef DEBUG_ARRAY
    check_RI(a);
#endif
    signal(ERR_ok);
}


/* the addl algorithm should be improved to see if the store already
 * has room in it for the new element */

errcode
arrayOPaddl(CLUREF a, CLUREF elt)
{
    long new_size;
    long old_int_low;
    CLUREF oldstore;
    long i;

#ifdef DEBUG_ARRAY
    check_RI(a);
#endif
    new_size = a.array->ext_size + 1;
    if (new_size > (long)MAX_ARR_SIZE) {
	elist[0] = array_bounds_overflow_STRING;
	signal(ERR_failure);
    }

    oldstore.store = a.array->store;
    old_int_low = a.array->int_low;

    arrayOPOPnewstore(a, new_size);

    for (i = 1 ; i < new_size ; ++i) {
	a.array->store->data[i] = oldstore.store->data[old_int_low + i - 1];
    }
    a.array->store->data[0] = elt.num;
    a.array->ext_size = new_size;
    a.array->ext_low -= 1;

#ifdef DEBUG_ARRAY
    check_RI(a);
#endif
    signal(ERR_ok);
}


errcode				/* signals bounds */
arrayOPremh(CLUREF a, CLUREF *ans)
{
#ifdef DEBUG_ARRAY
    check_RI(a);
#endif
    if (a.array->ext_size == 0)
	signal(ERR_bounds);

    size_t hidx = a.array->int_low + a.array->ext_size - 1;
    CLUREF *phigh = (CLUREF *)&a.array->store->data[hidx];

    *ans = *phigh;
    phigh->num = 0;		/* enhance gc */

    --a.array->ext_high;
    --a.array->ext_size;

#ifdef DEBUG_ARRAY
    check_RI(a);
#endif
    signal(ERR_ok);
}


errcode				/* signals bounds */
arrayOPreml(CLUREF a, CLUREF *ans)
{
#ifdef DEBUG_ARRAY
    check_RI(a);
#endif
    if (a.array->ext_size == 0)
	signal(ERR_bounds);

    size_t lidx = a.array->int_low;
    CLUREF *plow = (CLUREF *)&a.array->store->data[lidx];

    *ans = *plow;
    plow->num = 0;		/* enhance gc */

    ++a.array->int_low;
    ++a.array->ext_low;
    --a.array->ext_size;

#ifdef DEBUG_ARRAY
    check_RI(a);
#endif
    signal(ERR_ok);
}


errcode
arrayOPelements(CLUREF a,
		errcode (*iterbod)(), void *user_locals, errcode *ecode2)
{
    CLUREF iv_1;
    long index, int_index;
    struct {
	char **user_locals;
	errcode (*proc)();
	errcode err;
	errcode ecode2;
	CLUREF  a;
	long limit;
    } locals;

   locals.a = a;
   locals.user_locals = user_locals;
   locals.proc = iterbod;
   locals.limit = a.array->ext_high;

   if (a.array->ext_size == 0)
       signal(ERR_ok);

   index = a.array->ext_low;
   int_index = a.array->int_low;
   for (;;) {
       if (index < a.array->ext_low || index > a.array->ext_high) {
	   elist[0] = array_bounds_exception_STRING;
	   signal(ERR_failure);
       }
       iv_1.num = a.array->store->data[int_index];
       locals.err = (*iterbod)(iv_1, user_locals, ecode2);
       if (locals.err == ERR_ok) {
	   index += 1;
	   int_index += 1;
	   if (index <= locals.limit) continue;
	   if (index >  locals.limit) signal(ERR_ok);
       }
       if (locals.err == ERR_iterbodyreturn) signal(locals.err);
       /* 9/9/93 dwc: just propagate break, do not convert to ok */
       if (locals.err == ERR_break) signal(ERR_break);
       if (locals.err == ERR_iterbodyexit) signal(locals.err);
       if (locals.err == ERR_iterbodysignal) signal(locals.err);
       if (locals.err == ERR_iteriterbodysignal) signal(locals.err);
       if (locals.err == ERR_iteriterbodyexit) signal(locals.err);
       if (locals.err == ERR_iteriterbodyreturn) signal(locals.err);
   }
}


errcode
arrayOPindexes(CLUREF a,
	       errcode (*iterbod)(), void *user_locals, errcode *ecode2)
{
    errcode err;
    CLUREF iv_1;
    long limit;

    if (a.array->ext_size == 0)
	signal(ERR_ok);

    limit = a.array->ext_high;   /* capture initial size */
    iv_1.num = a.array->ext_low;
    for (;;) {
	err = (*iterbod)(iv_1, user_locals, ecode2);
	if (err == ERR_ok) {
	    iv_1.num += 1;
	    if (iv_1.num <= limit) continue;
	    if (iv_1.num >  limit) signal(ERR_ok);
	}
	if (err == ERR_iterbodyreturn) signal(err);
	/* 9/9/93 dwc: just propagate break, do not convert to ok */
	if (err == ERR_break) signal(ERR_break);
	if (err == ERR_iterbodyexit) signal(err);
	if (err == ERR_iterbodysignal) signal(err);
	if (err == ERR_iteriterbodysignal) signal(err);
	if (err == ERR_iteriterbodyexit) signal(err);
	if (err == ERR_iteriterbodyreturn) signal(err);
    }
}


errcode
arrayOPequal(CLUREF a1, CLUREF a2, CLUREF *ans)
{
    if (a1.array == a2.array)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
arrayOPsimilar(CLUREF a1, CLUREF a2, CLUREF *ans) /* use t$similar */
{
    const array_of_t_OPS *ops
	= ((array_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;
    long i, j, count;
    errcode err;
    CLUREF ans2, elt1, elt2;

    if (a1.array->ext_size != a2.array->ext_size) {
	ans->tf = false;
	signal(ERR_ok);
    }
    if (a1.array->ext_low != a2.array->ext_low) {
	ans->tf = false;
	signal(ERR_ok);
    }
    if (a1.array->ext_size == 0) {
	ans->tf = true;
	signal(ERR_ok);
    }

    /* ANOTHER CASE TO CHECK FOR BOUNDS? */
    CLUREF tOPsimilar = { .proc = ops->similar.fcn };
    for (i = a1.array->int_low, j = a2.array->int_low, count = a1.array->ext_low;
	 count <= a1.array->ext_high;
	 ++i, ++j, ++count)
    {
	elt1.num = a1.array->store->data[i];
	elt2.num = a2.array->store->data[i];

	CUR_PROC_VAR = tOPsimilar;
	err = (*tOPsimilar.proc->proc)(elt1, elt2, &ans2);
	if (err != ERR_ok)
	    resignal(err);

	if (ans2.tf == false) {
	    ans->tf = false;
	    signal(ERR_ok);
	}
    }
    ans->tf = true;
    signal(ERR_ok);
}


errcode
arrayOPsimilar1(CLUREF a1, CLUREF a2, CLUREF *ans) /* use t$equal */
{
    const array_of_t_OPS *ops
	= ((array_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;
    long i, j, count;
    errcode err;
    CLUREF elt1, elt2, ans2;

    if (a1.array->ext_size != a2.array->ext_size) {
	ans->tf = false;
	signal(ERR_ok);
    }
    if (a1.array->ext_low != a2.array->ext_low) {
	ans->tf = false;
	signal(ERR_ok);
    }
    if (a1.array->ext_size == 0) {
	ans->tf = true;
	signal(ERR_ok);
    }

    /* ANOTHER CASE TO CHECK FOR BOUNDS? */
    CLUREF tOPequal = { .proc = ops->equal.fcn };
    for (i = a1.array->int_low, j = a2.array->int_low, count = a1.array->ext_low;
	 count <= a1.array->ext_high;
	 ++i, ++j, ++count)
    {
	elt1.num = a1.array->store->data[i];
	elt2.num = a2.array->store->data[i];

	CUR_PROC_VAR = tOPequal;
	err = (*tOPequal.proc->proc)(elt1, elt2, &ans2);
	if (err != ERR_ok)
	    resignal(err);

	if (ans2.tf == false) {
	    ans->tf = false;
	    signal(ERR_ok);
	}
    }
    ans->tf = true;
    signal(ERR_ok);
}


errcode
arrayOPcopy(CLUREF a1, CLUREF *ans) /* deep: use t$copy */
{
    const array_of_t_OPS *ops
	= ((array_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;
    CLUREF temp, elt;
    errcode err;
    long i;

#ifdef DEBUG_ARRAY
    check_RI(a1);
#endif

    arrayOPOPnewdesc(&temp);
    arrayOPOPnewstore(temp, a1.array->ext_size);

    temp.array->ext_low = a1.array->ext_low;
    temp.array->ext_size = a1.array->ext_size;
    temp.array->ext_high = a1.array->ext_high;

    CLUREF tOPcopy = { .proc = ops->copy.fcn };
    for (i = 0; i < a1.array->ext_size; ++i) {
	elt.num = a1.array->store->data[i + a1.array->int_low];
	/* added _int_low 7/24/90 */

	CUR_PROC_VAR = tOPcopy;
	err = (*tOPcopy.proc->proc)(elt, &temp.array->store->data[i]);
	if (err != ERR_ok)
	    resignal(err);
    }

#ifdef DEBUG_ARRAY
    check_RI(temp);
#endif
    *ans = temp;
    signal(ERR_ok);
}


errcode
arrayOPcopy1(CLUREF a1, CLUREF *ans) /* shallow: do NOT use t$copy */
{
    CLUREF temp;
    long i,j,k;

#ifdef DEBUG_ARRAY
    check_RI(a1);
#endif

    arrayOPOPnewdesc(&temp);
    arrayOPOPnewstore(temp, a1.array->ext_size);

    temp.array->ext_low = a1.array->ext_low;
    temp.array->ext_size = a1.array->ext_size;
    temp.array->ext_high = a1.array->ext_high;

    j = a1.array->int_low;
    k = temp.array->int_low;
    for (i = 0; i < a1.array->ext_size; ++i, ++j, ++k) {
	temp.array->store->data[k] = a1.array->store->data[j];
    }

#ifdef DEBUG_ARRAY
    check_RI(temp);
#endif
    *ans = temp;
    signal(ERR_ok);
}


errcode
arrayOPdebug_print(CLUREF a, CLUREF pst) /* use t$debug_print */
{
    errcode err;
    const array_of_t_OPS *ops
	= ((array_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;

    CLUREF tOPdebug_print = { .proc = ops->debug_print.fcn };
    err = arrayOPinternal_print(a, pst, tOPdebug_print);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
arrayOPprint(CLUREF a, CLUREF pst) /* use t$print */
{
    errcode err;
    const array_of_t_OPS *ops
	= ((array_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;

    CLUREF tOPprint = { .proc = ops->print.fcn };
    err = arrayOPinternal_print(a, pst, tOPprint);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
arrayOPinternal_print(CLUREF a, CLUREF pst, CLUREF pfcn)
{
    errcode err;
    CLUREF ans, max, num;
    long i,j;

    static CLUREF lbrack, dotdot, colon, comma, rbrack;
    static bool init = false;
    if (init == false) {
	stringOPcons("[", CLU_1, CLU_1, &lbrack);
	stringOPcons("..", CLU_1, CLU_2, &dotdot);
	stringOPcons(": ", CLU_1, CLU_2, &colon);
	stringOPcons(",", CLU_1, CLU_1, &comma);
	stringOPcons("]", CLU_1, CLU_1, &rbrack);
	init = true;
    }

    err = pstreamOPtext(pst, lbrack, &ans);
    if (err != ERR_ok)
	resignal(err);

    num.num = a.array->ext_low;
    err = intOPprint(num, pst);
    if (err != ERR_ok)
	resignal(err);

    err = pstreamOPget_max_width(pst, &max);
    if (err != ERR_ok)
	resignal(err);

    if (a.array->ext_size >= max.num) {
	err = pstreamOPtext(pst, dotdot, &ans);
	if (err != ERR_ok)
	    resignal(err);

	num.num = a.array->ext_high;
	err = intOPprint(num, pst);
	if (err != ERR_ok)
	    resignal(err);
    }

    err = pstreamOPstart(pst, colon, &ans);
    if (err != ERR_ok)
	resignal(err);

    if (ans.tf == false || a.array->ext_size == 0) {
	err = pstreamOPstop(pst, rbrack, &ans);
	if (err != ERR_ok)
	    resignal(err);

	signal(ERR_ok);
    }

    /* the original code has a bounds check in the following loop */
    for (i = 0, j = a.array->int_low; i < a.array->ext_size; ++i, ++j) {
	if (i != 0) {
	    err = pstreamOPpause(pst, comma, &ans);
	    if (err != ERR_ok)
		resignal(err);

	    if (ans.tf == false)
		break;
	}
	num.num = a.array->store->data[j];
	CUR_PROC_VAR = pfcn;
	err = pfcn.proc->proc(num, pst);
	if (err != ERR_ok)
	    resignal(err);
    }

    err = pstreamOPstop(pst, rbrack, &ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}



errcode				    /* signals not_possible(string) */
arrayOPencode(CLUREF a, CLUREF ist) /* use t$encode */
{
    const array_of_t_OPS *ops
	= ((array_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;
    errcode err;
    long i;
    CLUREF num;

    num.num = a.array->ext_low;
    err = istreamOPputi(ist, num);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    num.num = a.array->ext_size;
    err = istreamOPputi(ist, num);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    num.num = a.array->int_size;
#if 0
    /* removed predict... for mtv 9/93 */
    err = istreamOPputi(ist, num);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);
#endif

    if (a.array->ext_size == 0)
	signal(ERR_ok);

    CLUREF tOPencode = { .proc = ops->encode.fcn };
    for (i = 0; i < a.array->ext_size; ++i) {
	num.num = a.array->store->data[i];

	CUR_PROC_VAR = tOPencode;
	err = (*tOPencode.proc->proc)(num, ist);
	if (err == ERR_not_possible)
	    signal(err);
	if (err != ERR_ok)
	    resignal(err);
    }
    signal(ERR_ok);
}


errcode		       /* signals not_possible(string), end_of_file */
arrayOPdecode(CLUREF ist, CLUREF *ans) /* use t$decode */
{
    const array_of_t_OPS *ops
	= ((array_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;
    errcode err;

    CLUREF low;
    err = istreamOPgeti(ist, &low);
    if (err == ERR_end_of_file)
	signal(err);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);
#if 0
    if (low.num < (long)MIN_ARR_INDEX) {
	elist[0] = bad_format_STRING;
	signal(ERR_failure);
    }
#endif

    CLUREF size;
    err = istreamOPgeti(ist, &size);
    if (err == ERR_end_of_file)
	signal(err);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    if (size.num > (long)MAX_ARR_SIZE) {
	elist[0] = bad_format_STRING;
	signal(ERR_failure);
    }
    if (size.num + low.num > (long)MAX_ARR_INDEX) {
	elist[0] = bad_format_STRING;
	signal(ERR_failure);
    }

#if 0
    CLUREF predict;
    err = istreamOPgeti(ist, &predict);
    if (err == ERR_end_of_file)
	signal(err);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    if (predict.num > (long)MAX_ARR_SIZE) {
	elist[0] = bad_format_STRING;
	signal(ERR_failure);
    }
#endif

    CLUREF temp;
    err = arrayOPfill(low, size, CLU_0, &temp);
    if (err != ERR_ok)
	resignal(err);

    if (size.num == 0) {
	*ans = temp;
	signal(ERR_ok);
    }

    CLUREF tOPdecode = { .proc = ops->decode.fcn };
    for (long i = 0; i < size.num; ++i) {
	CLUREF elt;

	CUR_PROC_VAR = tOPdecode;
	err = (*tOPdecode.proc->proc)(ist, &elt);
	if (err == ERR_end_of_file)
	    signal(err);
	if (err == ERR_not_possible)
	    signal(err);
	if (err != ERR_ok)
	    resignal(err);

	temp.array->store->data[i] = elt.num;
    }

    *ans = temp;
    signal(ERR_ok);
}


errcode
arrayOP_gcd(CLUREF a, CLUREF tab, CLUREF *ans) /* use t$_gcd */
{
    errcode err;
    const array_of_t_OPS *ops
	= ((array_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;

    CLUREF ginfo;		// := ginfo$make_g_arp(t$_gcd)
    CLUREF tOP_gcd = { .proc = ops->_gcd.fcn };
    err = oneofOPnew(CLU_7, tOP_gcd, &ginfo);
    if (err != ERR_ok)
	resignal(err);

    CLUREF ginfo2;		// := ginfo$make_f_adv(ginfo)	% wrap
    err = oneofOPnew(CLU_6, ginfo, &ginfo2);
    if (err != ERR_ok)
	resignal(err);

    CLUREF sz = {
	.num = offsetof(CLU_array, store) // plain data at the start
	     + GCD_REF_SIZE		  // CLU_array::store
    };
    err = gcd_tabOPinsert(tab, sz, ginfo2, a, ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}



OWN_ptr array_own_init = { .init_flag = 0 }; /* dummy */

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &array_own_init,		\
    .op_owns = &array_own_init,			\
}

static CLU_proc array_oe_create = CLU_proc_INIT(arrayOPcreate);
static CLU_proc array_oe_new = CLU_proc_INIT(arrayOPnew);
static CLU_proc array_oe_predict = CLU_proc_INIT(arrayOPpredict);
static CLU_proc array_oe_cons = CLU_proc_INIT(arrayOPcons);
static CLU_proc array_oe_empty = CLU_proc_INIT(arrayOPempty);
static CLU_proc array_oe_low = CLU_proc_INIT(arrayOPlow);
static CLU_proc array_oe_high = CLU_proc_INIT(arrayOPhigh);
static CLU_proc array_oe_size = CLU_proc_INIT(arrayOPsize);
static CLU_proc array_oe_set_low = CLU_proc_INIT(arrayOPset_low);
static CLU_proc array_oe_trim = CLU_proc_INIT(arrayOPtrim);
static CLU_proc array_oe_fill = CLU_proc_INIT(arrayOPfill);
static CLU_proc array_oe_fill_copy = CLU_proc_INIT(arrayOPfill_copy);
static CLU_proc array_oe_fetch = CLU_proc_INIT(arrayOPfetch);
static CLU_proc array_oe_bottom = CLU_proc_INIT(arrayOPbottom);
static CLU_proc array_oe_top = CLU_proc_INIT(arrayOPtop);
static CLU_proc array_oe_store = CLU_proc_INIT(arrayOPstore);
static CLU_proc array_oe_addh = CLU_proc_INIT(arrayOPaddh);
static CLU_proc array_oe_addl = CLU_proc_INIT(arrayOPaddl);
static CLU_proc array_oe_remh = CLU_proc_INIT(arrayOPremh);
static CLU_proc array_oe_reml = CLU_proc_INIT(arrayOPreml);
static CLU_proc array_oe_equal = CLU_proc_INIT(arrayOPequal);
static CLU_proc array_oe_similar = CLU_proc_INIT(arrayOPsimilar);
static CLU_proc array_oe_copy = CLU_proc_INIT(arrayOPcopy);
static CLU_proc array_oe_similar1 = CLU_proc_INIT(arrayOPsimilar1);
static CLU_proc array_oe_copy1 = CLU_proc_INIT(arrayOPcopy1);
static CLU_proc array_oe_indexes = CLU_proc_INIT(arrayOPindexes);
static CLU_proc array_oe_elements = CLU_proc_INIT(arrayOPelements);
static CLU_proc array_oe_encode = CLU_proc_INIT(arrayOPencode);
static CLU_proc array_oe_decode = CLU_proc_INIT(arrayOPdecode);
static CLU_proc array_oe__gcd = CLU_proc_INIT(arrayOP_gcd);
static CLU_proc array_oe_print = CLU_proc_INIT(arrayOPprint);
static CLU_proc array_oe_debug_print = CLU_proc_INIT(arrayOPdebug_print);

static struct /* OPS */ {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[32];
} array_ops_actual = {
    32,
    &array_own_init,
    &array_own_init,
    {
	{ &array_oe_create, "create" },
	{ &array_oe_new, "new" },
	{ &array_oe_predict, "predict" },
	{ &array_oe_cons, "cons" },
	{ &array_oe_empty, "empty" },
	{ &array_oe_low, "low" },
	{ &array_oe_high, "high" },
	{ &array_oe_size, "size" },
	{ &array_oe_set_low, "set_low" },
	{ &array_oe_trim, "trim" },
	{ &array_oe_fill, "fill" },
	{ &array_oe_fill_copy, "fill_copy" },
	{ &array_oe_fetch, "fetch" },
	{ &array_oe_bottom, "bottom" },
	{ &array_oe_top, "top" },
	{ &array_oe_store, "store" },
	{ &array_oe_addh, "addh" },
	{ &array_oe_addl, "addl" },
	{ &array_oe_remh, "remh" },
	{ &array_oe_reml, "reml" },
	{ &array_oe_equal, "equal" },
	{ &array_oe_similar, "similar" },
	{ &array_oe_copy, "copy" },
	{ &array_oe_similar1, "similar1" },
	{ &array_oe_copy1, "copy1" },
	{ &array_oe_indexes, "indexes" },
	{ &array_oe_elements, "elements" },
	{ &array_oe_encode, "encode" },
	{ &array_oe_decode, "decode" },
	{ &array_oe__gcd, "_gcd" },
	{ &array_oe_print, "print" },
	{ &array_oe_debug_print, "debug_print" },
    }
};

struct OPS *array_ops = (struct OPS *)&array_ops_actual;
