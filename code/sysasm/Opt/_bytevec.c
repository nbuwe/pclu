/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*							*/
/*		BYTEVEC IMPLEMENTATION			*/
/*							*/

/* TODO: comp, build, move_rl, move_b (not referenced) 	*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdio.h>

extern errcode gcd_tabOPinsert(CLUREF tab, CLUREF z, CLUREF inf, CLUREF x, CLUREF *ans);
extern errcode stringOPdebug_print(CLUREF s, CLUREF pst);

#define	CLU_roundup(x, y)	((((x)+((y)-1))/(y))*(y))


static inline size_t
_bytevecOPOPmemsize(size_t size)
{
    /*
     * string header w/out the "inflexible" data[] array
     * and extra space for NUL at the end
     */
    size += offsetof(CLU_string, data) + 1;

    /* round up to word size */
    size = CLU_roundup(size, CLUREFSZ);

    return size;
}


static void
_bytevecOPOPalloc(size_t size, CLUREF *pnew)
{
    size_t bufsz = _bytevecOPOPmemsize(size);

    clu_alloc_atomic(bufsz, pnew);
    CLUTYPE_set(pnew->str->typ, CT_STRING);
    pnew->str->size = size;
}



errcode
_bytevecOPcreate(CLUREF sz, CLUREF *ans)
{
    if (sz.num > MAX_STR)
	signal(ERR_toobig);

    CLUREF bv;
    _bytevecOPOPalloc(sz.num, &bv);

    ans->str = bv.str;
    signal(ERR_ok);
}


errcode
_bytevecOPcopy(CLUREF bv1, CLUREF *ans)
{
    CLUREF bv2;
    _bytevecOPOPalloc(bv1.str->size, &bv2);

    /*
     * The destination is at least one byte larger than the size and
     * the allocator zeroes out the returned memory, so we get the
     * trailing NUL byte by construction.
     */
    memcpy(bv2.str->data, bv1.str->data, bv1.str->size);

    ans->str = bv2.str;
    signal(ERR_ok);
}


errcode
_bytevecOPfetch(CLUREF bv, CLUREF i, CLUREF *ans)
{
    if (i.num < 1)
	signal(ERR_bounds);
    if (i.num > bv.str->size)
	signal(ERR_bounds);

    ans->ch = bv.str->data[i.num - 1];
    signal(ERR_ok);
}


errcode
_bytevecOPstore(CLUREF bv, CLUREF i, CLUREF c)
{
    if (i.num < 1)
	signal(ERR_bounds);
    if (i.num > bv.str->size)
	signal(ERR_bounds);

    bv.str->data[i.num - 1] = c.ch;
    signal(ERR_ok);
}


errcode
_bytevecOPsize(CLUREF bv, CLUREF *ans)
{
    ans->num = bv.str->size;
    signal(ERR_ok);
}


errcode
_bytevecOPequal(CLUREF bv1, CLUREF bv2, CLUREF *ans)
{
    if (bv1.str == bv2.str)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_bytevecOPindexc(CLUREF c, CLUREF bv, CLUREF first, CLUREF *ans)
{
    long i;

    if (first.num < 1)
	signal(ERR_bounds);
    if (first.num > (bv.str->size + 1))
	signal(ERR_bounds);

    for (i = first.num; i <= bv.str->size; ++i) {
	if (bv.str->data[i - 1] == c.ch) {
	    ans->num = i;
	    signal(ERR_ok);
	}
    }
    ans->num = 0;
    signal(ERR_ok);
}


/*
 * find bv1 in bv2; start looking at bv2[first];
 * some way to use matchc and/or locc?
 */
errcode
_bytevecOPindexv(CLUREF bv1, CLUREF bv2, CLUREF first, CLUREF *ans)
{
    bool found;
    long i,j;

    if (first.num < 1)
	signal(ERR_bounds);
    if (first.num > (bv2.str->size + 1))
	signal(ERR_bounds);

    for (i = first.num; i + bv1.str->size - 1 <= bv2.str->size; ++i) {
	found = true;
	for (j = 1; j <= bv1.str->size; ++j) {
	    if (bv2.str->data[i - 1 + j - 1] != bv1.str->data[j - 1]) {
		found = false;
		break;
	    }
	}
	if (found == true) {
	    ans->num = i;
	    signal(ERR_ok);
	}
    }
    ans->num = 0;
    signal(ERR_ok);
}


/*
 * find bv1 in bv2; start looking at bv2[first];
 * case doesn't matter
 */
errcode
_bytevecOPnc_indexv(CLUREF bv1, CLUREF bv2, CLUREF first, CLUREF *ans)
{
    bool found;
    long i,j;
    char temp_c1, temp_c2;

    if (first.num < 1)
	signal(ERR_bounds);
    if (first.num > (bv2.str->size + 1))
	signal(ERR_bounds);

    for (i = first.num; i + bv1.str->size - 1 <= bv2.str->size; ++i) {
	found = true;
	for (j = 1; j <= bv1.str->size; ++j) {
	    temp_c1 = bv1.str->data[j - 1];
	    if (temp_c1 >= MIN_CAP_CHAR && temp_c1 <= MAX_CAP_CHAR)
		temp_c1 += OFF_CHAR;
	    temp_c2 = bv2.str->data[i - 1 + j - 1];
	    if (temp_c2 >= MIN_CAP_CHAR && temp_c2 <= MAX_CAP_CHAR)
		temp_c2 += OFF_CHAR;
	    if (temp_c1 != temp_c2) {
		found = false;
		break;
	    }
	}
	if (found == true) {
	    ans->num = i;
	    signal(ERR_ok);
	}
    }
    ans->num = 0;
    signal(ERR_ok);
}


/* original code tries to use more efficient instructions
	if the bytevecs are not identical,
	if they are the same and the destination is less than the source,
	if they are the same and the dest is gtr than the source and the
		size of the dest is greater than the copycount
	if a single character is being propagated through a bytevec
*/
errcode
_bytevecOPcomp(CLUREF v1, CLUREF v2, CLUREF *ans)
{
    CLU_NOREF(v1);
    CLU_NOREF(v2);
    CLU_NOREF(ans);

    fprintf(stderr, "_bytevec$comp not implemented\n");
    signal(ERR_failure);
}


errcode
_bytevecOPmove_rl(CLUREF v1, CLUREF s1, CLUREF v2, CLUREF s2, CLUREF len)
{
    CLU_NOREF(v1);
    CLU_NOREF(s1);
    CLU_NOREF(v2);
    CLU_NOREF(s2);
    CLU_NOREF(len);

    fprintf(stderr, "_bytevec$move_rl not implemented\n");
    signal(ERR_failure);
}


errcode _bytevecOPmove_b(CLUREF v1, CLUREF s1, CLUREF v2, CLUREF s2, CLUREF len)
{
    CLU_NOREF(v1);
    CLU_NOREF(s1);
    CLU_NOREF(v2);
    CLU_NOREF(s2);
    CLU_NOREF(len);

    fprintf(stderr, "_bytevec$move_b not implemented\n");
    signal(ERR_failure);
}


errcode
_bytevecOPbuild(CLUREF v1, CLUREF *ans)
{
    CLU_NOREF(v1);
    CLU_NOREF(ans);

    fprintf(stderr, "_bytevec$build not implemented\n");
    signal(ERR_failure);
}


errcode
_bytevecOPmove_lr(CLUREF bv1, CLUREF s1, CLUREF bv2, CLUREF s2, CLUREF len)
{
    if (len.num < 0)
	signal(ERR_negative_size);

    if (len.num == 0)
	signal(ERR_ok);

    if (s1.num < 1)
	signal(ERR_bounds);
    if (s1.num > bv1.str->size)
	signal(ERR_bounds);

    if (s2.num < 1)
	signal(ERR_bounds);
    if (s2.num >bv2.str->size)
	signal(ERR_bounds);

    long copycount = len.num;
    if (copycount + s1.num > bv1.str->size)
	copycount = bv1.str->size - s1.num + 1;
    if (copycount + s2.num > bv2.str->size)
	copycount = bv2.str->size - s2.num + 1;

    for (long i = 0; i < copycount; ++i) {
	bv2.str->data[s2.num -1 + i] = bv1.str->data[s1.num - 1 + i];
    }
    signal(ERR_ok);
}


/* moves chars from a sequence of chars to a bytevec */
errcode
_bytevecOPmove_v(CLUREF qc1, CLUREF s1, CLUREF bv2, CLUREF s2, CLUREF len)
{
    if (len.num < 0)
	signal(ERR_negative_size);

    if (s1.num < 1)
	signal(ERR_bounds);
    if (s1.num > qc1.vec->size)
	signal(ERR_bounds);

    if (s2.num < 1)
	signal(ERR_bounds);
    if (s2.num >bv2.str->size)
	signal(ERR_bounds);

    long copycount = len.num;
    if (copycount + s1.num > qc1.vec->size)
	copycount = qc1.vec->size - s1.num + 1;
    if (copycount + s2.num > bv2.str->size)
	copycount = bv2.str->size - s2.num + 1;

    for (long i = 0; i < copycount; ++i) {
	bv2.str->data[s2.num - 1 + i] = qc1.vec->data[s1.num - 1 + i];
    }
    signal(ERR_ok);
}


errcode
_bytevecOP_gcd(CLUREF bv, CLUREF tab, CLUREF *ans)
{
    errcode err;

    CLUREF ginfo; 		// := ginfo$make_a_bvec(nil)
    err = oneofOPnew(CLU_1, CLU_0, &ginfo);
    if (err != ERR_ok)
	resignal(err);

    long sz = _bytevecOPOPmemsize(bv.str->size);
    err = gcd_tabOPinsert(tab, CLUREF_make_num(sz), ginfo, bv, ans);
    if (err != ERR_ok)
	resignal(err);
    signal(ERR_ok);
}


errcode
_bytevecOPdebug_print(CLUREF bv, CLUREF ps)
{
    errcode err;

    err = stringOPdebug_print(bv, ps);
    if (err != ERR_ok)
	resignal(err);
    signal(ERR_ok);
}



OWN_ptr _bytevec_own_init = { .init_flag = 1 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &_bytevec_own_init,		\
    .op_owns = &_bytevec_own_init,		\
}

static CLU_proc _bytevec_oe_create = CLU_proc_INIT(_bytevecOPcreate);
static CLU_proc _bytevec_oe_copy = CLU_proc_INIT(_bytevecOPcopy);
static CLU_proc _bytevec_oe_fetch = CLU_proc_INIT(_bytevecOPfetch);
static CLU_proc _bytevec_oe_store = CLU_proc_INIT(_bytevecOPstore);
static CLU_proc _bytevec_oe_size = CLU_proc_INIT(_bytevecOPsize);
static CLU_proc _bytevec_oe_equal = CLU_proc_INIT(_bytevecOPequal);
static CLU_proc _bytevec_oe_indexc = CLU_proc_INIT(_bytevecOPindexc);
static CLU_proc _bytevec_oe_indexv = CLU_proc_INIT(_bytevecOPindexv);
static CLU_proc _bytevec_oe_nc_indexv = CLU_proc_INIT(_bytevecOPnc_indexv);
static CLU_proc _bytevec_oe_move_lr = CLU_proc_INIT(_bytevecOPmove_lr);
static CLU_proc _bytevec_oe_move_v = CLU_proc_INIT(_bytevecOPmove_v);
static CLU_proc _bytevec_oe__gcd = CLU_proc_INIT(_bytevecOP_gcd);
static CLU_proc _bytevec_oe_debug_print = CLU_proc_INIT(_bytevecOPdebug_print);


/* extends struct OPS */
typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[13];
} _bytevec_OPS;

static _bytevec_OPS _bytevec_ops_actual = {
    13,
    &_bytevec_own_init,
    &_bytevec_own_init,
    {
	{ &_bytevec_oe_create, "create" },
	{ &_bytevec_oe_copy, "copy" },
	{ &_bytevec_oe_fetch, "fetch" },
	{ &_bytevec_oe_store, "store" },
	{ &_bytevec_oe_size, "size" },
	{ &_bytevec_oe_equal, "equal" },
	{ &_bytevec_oe_indexc, "indexc" },
	{ &_bytevec_oe_indexv, "indexv" },
	{ &_bytevec_oe_nc_indexv, "nc_indexv" },
	{ &_bytevec_oe_move_lr, "move_lr" },
	{ &_bytevec_oe_move_v, "move_v" },
	{ &_bytevec_oe__gcd, "_gcd" },
	{ &_bytevec_oe_debug_print, "debug_print" },
    }
};

struct OPS *_bytevec_ops = (struct OPS *)&_bytevec_ops_actual;
