/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*							*/
/*		SEQUENCE IMPLEMENTATION			*/
/*							*/

/* somewhat unfortunate to be using 'num' throughout */

#include "pclu_err.h"
#include "pclu_sys.h"

errcode gcd_tabOPinsert(CLUREF tab, CLUREF z, CLUREF inf, CLUREF x, CLUREF *ans);
errcode arrayOPOPnewdesc(CLUREF *ans);
errcode arrayOPOPnewstore(CLUREF desc, long size);
errcode istreamOPgeti(CLUREF ist, CLUREF *ret_1);
errcode istreamOPputi(CLUREF ist, CLUREF i);
errcode pstreamOPpause(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPstart(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPstop(CLUREF ps, CLUREF s, CLUREF *ret_1);

errcode sequenceOPinternal_print(CLUREF s, CLUREF pst, CLUREF pfcn);


/*
 * What sequence[T] requires of T.
 */
static const struct /* REQS */ {
    long count;
    struct REQ_ENTRY entry[8];
} sequence_of_t_reqs_actual = {
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

const struct REQS * const sequence_of_t_reqs
    = (const struct REQS *)&sequence_of_t_reqs_actual;


/*
 * An interface to T for a sequence[T] instance (as specified by REQS).
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
} sequence_of_t_OPS;


/*
 * Own data of a sequence[T] instance.
 */
typedef struct /* OWN_ptr */ {
    long array_own_init;	/* unused */
    const sequence_of_t_OPS * const t_ops;
} sequence_OWN_DEFN;


/*
 * Tell instantiation code how to construct an _OWN_DEFN object for an
 * instantce.  What "own_count" really tells is where the parameters
 * start (OPS for types, values for constants).
 */
const OWN_req sequence_ownreqs = { sizeof(sequence_OWN_DEFN), 1 };



static inline void
sequenceOPOPalloc(size_t size, CLUREF *pnew)
{
    clu_alloc(offsetof(CLU_sequence, data) + size * CLUREFSZ, pnew);
    CLUTYPE_set(pnew->vec->typ, CT_AGG);
    pnew->vec->size = size;
}


errcode
sequenceOPnew(CLUREF *ans)
{
    static CLUREF CLU_empty_sequence;
    static bool init = false;
    if (!init) {
	sequenceOPOPalloc(0, &CLU_empty_sequence);
	init = true;
    }

    *ans = CLU_empty_sequence;
    signal(ERR_ok);
}


errcode
sequenceOPnew2(CLUREF size, CLUREF *ans)
{
    CLUREF s;
    sequenceOPOPalloc(size.num, &s);

    *ans = s;
    signal(ERR_ok);
}


errcode
sequenceOPcons(CLUREF x, CLUREF *ans)
{
    ans->vec = x.vec;
    signal(ERR_ok);
}


errcode
sequenceOPe2s(CLUREF x, CLUREF *ans)
{
    CLUREF s;
    sequenceOPOPalloc(1, &s);
    s.vec->data[0] = x.num;

    *ans = s;
    signal(ERR_ok);
}


errcode
sequenceOPsize(CLUREF x, CLUREF *ans)
{
    ans->num = x.vec->size;
    signal(ERR_ok);
}


errcode
sequenceOPsubseq(CLUREF s, CLUREF first, CLUREF length, CLUREF *ans)
{
    CLUREF s2;
    long i, copycount;

    if (first.num < 1)
	signal(ERR_bounds);

    if (first.num == 1 && length.num == s.vec->size) {
	ans->vec = s.vec;
	signal(ERR_ok);
    }

    if (first.num > (s.vec->size + 1))
	signal(ERR_bounds);
    if (length.num < 0)
	signal(ERR_negative_size);

    if (length.num == 0) {
	sequenceOPnew(ans);
	signal(ERR_ok);
    }

    copycount = length.num;
    if (copycount + first.num - 1 > s.vec->size)
	copycount = s.vec->size - first.num + 1;

    sequenceOPOPalloc(copycount, &s2);
    for (i = 0; i < copycount; i++) {
	s2.vec->data[i] = s.vec->data[first.num-1+i];
    }

    ans->vec = s2.vec;
    signal(ERR_ok);
}


errcode
sequenceOPfill(CLUREF length, CLUREF x, CLUREF *ans)
{
    if (length.num < 0)
	signal(ERR_negative_size);

    if (length.num > MAX_SEQ) {
	elist[0] = huge_allocation_request_STRING;
	signal(ERR_failure);
    }

    if (length.num == 0) {
	sequenceOPnew(ans);
	signal(ERR_ok);
    }

    CLUREF s;
    sequenceOPOPalloc(length.num, &s);
    for (long i = 0; i < length.num; ++i)
	s.vec->data[i] = x.num;

    *ans = s;
    signal(ERR_ok);
}


errcode
sequenceOPfill_copy(CLUREF length, CLUREF x, CLUREF *ans)
{
    errcode err;
    const sequence_of_t_OPS *ops
	= ((sequence_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;

    if (length.num < 0)
	signal(ERR_negative_size);

    if (length.num > MAX_SEQ) {
	elist[0] = huge_allocation_request_STRING;
	signal(ERR_failure);
    }

    if (length.num == 0) {
	sequenceOPnew(ans);
	signal(ERR_ok);
    }

    CLUREF s;
    sequenceOPOPalloc(length.num, &s);

    CLUREF tOPcopy = { .proc = ops->copy.fcn };
    for (long i = 0; i < length.num; ++i) {
	CUR_PROC_VAR = tOPcopy;
	err = (*tOPcopy.proc->proc)(x, &s.vec->data[i]);
	if (err != ERR_ok)
	    resignal(err);
    }

    *ans = s;
    signal(ERR_ok);
}


errcode
sequenceOPfetch(CLUREF s, CLUREF i, CLUREF *ans)
{
    if (i.num <= 0)
	signal(ERR_bounds);
    if (i.num > s.vec->size)
	signal(ERR_bounds);

    ans->num = s.vec->data[i.num - 1];
    signal(ERR_ok);
}


errcode
sequenceOPbottom(CLUREF s, CLUREF *ans)
{
    if (s.vec->size == 0)
	signal(ERR_bounds);

    ans->num = s.vec->data[0];
    signal(ERR_ok);
}


errcode
sequenceOPtop(CLUREF s, CLUREF *ans)
{
    if (s.vec->size == 0)
	signal(ERR_bounds);

    long top = s.vec->size;
    ans->num = s.vec->data[top - 1];
    signal(ERR_ok);
}


errcode
sequenceOPreplace(CLUREF s, CLUREF ind, CLUREF x, CLUREF *ans)
{
    if (ind.num <= 0)
	signal(ERR_bounds);

    size_t size = s.vec->size;
    if ((size_t)ind.num > size)
	signal(ERR_bounds);

    CLUREF s2;
    sequenceOPOPalloc(size, &s2);
    memcpy(s2.vec->data, s.vec->data, size * CLUREFSZ);
    s2.vec->data[ind.num - 1] = x.num;

    *ans = s2;
    signal(ERR_ok);
}


errcode
sequenceOPaddh(CLUREF s, CLUREF x, CLUREF *ans)
{
    size_t size = s.vec->size;
    if ((size + 1) * sizeof(CLUREF) > MAX_SEQ) {
	elist[0] = huge_allocation_request_STRING;
	signal(ERR_failure);
    }

    CLUREF s2;
    sequenceOPOPalloc(size + 1, &s2);
    memcpy(s2.vec->data, s.vec->data, size * CLUREFSZ);
    s2.vec->data[size] = x.num;

    *ans = s2;
    signal(ERR_ok);
}


errcode
sequenceOPaddl(CLUREF s, CLUREF x, CLUREF *ans)
{
    size_t size = s.vec->size;
    if ((size + 1) * sizeof(CLUREF) > MAX_SEQ) {
	elist[0] = huge_allocation_request_STRING;
	signal(ERR_failure);
    }

    CLUREF s2;
    sequenceOPOPalloc(size + 1, &s2);
    s2.vec->data[0] = x.num;
    memcpy(&s2.vec->data[1], s.vec->data, size * CLUREFSZ);

    *ans = s2;
    signal(ERR_ok);
}


errcode
sequenceOPremh(CLUREF s, CLUREF *ans)
{
    size_t size = s.vec->size;
    if (size == 0)
	signal (ERR_bounds);

    if (size == 1) {
	sequenceOPnew(ans);
	signal(ERR_ok);
    }

    CLUREF s2;
    sequenceOPOPalloc(size - 1, &s2);
    memcpy(s2.vec->data, s.vec->data, (size - 1) * CLUREFSZ);

    *ans = s2;
    signal(ERR_ok);
}


errcode
sequenceOPreml(CLUREF s, CLUREF *ans)
{
    size_t size = s.vec->size;
    if (size == 0)
	signal (ERR_bounds);

    if (size == 1) {
	sequenceOPnew(ans);
	signal(ERR_ok);
    }

    CLUREF s2;
    sequenceOPOPalloc(size - 1, &s2);
    memcpy(s2.vec->data, &s.vec->data[1], (size - 1) * CLUREFSZ);

    *ans = s2;
    signal(ERR_ok);
}


errcode
sequenceOPconcat(CLUREF s1, CLUREF s2, CLUREF *ans)
{
    if (s1.vec->size == 0) {
	*ans = s2;
	signal(ERR_ok);
    }
    if (s2.vec->size == 0) {
	*ans = s1;
	signal(ERR_ok);
    }

    size_t size = s1.vec->size + s2.vec->size;
    if (size > MAX_SEQ) {
	elist[0] = huge_allocation_request_STRING;
	signal(ERR_failure);
    }

    CLUREF s;
    sequenceOPOPalloc(size, &s);
    memcpy(&s.vec->data[0], s1.vec->data, s1.vec->size * CLUREFSZ);
    memcpy(&s.vec->data[s1.vec->size], s2.vec->data, s2.vec->size * CLUREFSZ);

    *ans = s;
    signal(ERR_ok);
}


errcode
sequenceOPa2s(CLUREF a, CLUREF *ans)
{
    CLUREF s;
    sequenceOPOPalloc(a.array->ext_size, &s);
    s.vec->typ.refp = a.array->typ.refp;

    memcpy(s.vec->data,
	   &a.array->store->data[a.array->int_low],
	   a.array->ext_size * CLUREFSZ);

    *ans = s;
    signal(ERR_ok);
}


errcode
sequenceOPs2a(CLUREF s, CLUREF *ans)
{
    errcode err;

    CLUREF a;
    err = arrayOPOPnewdesc(&a);
    if (err != ERR_ok)
	resignal(err);

    err = arrayOPOPnewstore(a, s.vec->size);
    if (err != ERR_ok)
	resignal(err);

    memcpy(a.array->store->data, s.vec->data, s.vec->size * CLUREFSZ);
    a.array->ext_low = 1;
    a.array->ext_high = s.vec->size;
    a.array->ext_size = s.vec->size;

    *ans = a;
    signal(ERR_ok);
}


errcode
sequenceOPempty(CLUREF s, CLUREF *ans)
{
    if (s.vec->size == 0)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
sequenceOPequal(CLUREF s1, CLUREF s2, CLUREF *ans)
{
    errcode err;
    const sequence_of_t_OPS *ops
	= ((sequence_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;

    if (s1.vec->size != s2.vec->size) {
	ans->tf = false;
	signal(ERR_ok);
    }

    if (s1.vec->size == 0) {
	ans->tf = true;
	signal(ERR_ok);
    }

    CLUREF equal = CLU_true;
    CLUREF tOPequal = { .proc = ops->equal.fcn };

    for (long i = 0; i < s1.vec->size; ++i) {
	CLUREF elt1 = { .num = s1.vec->data[i] };
	CLUREF elt2 = { .num = s2.vec->data[i] };

	CUR_PROC_VAR = tOPequal;
	err = (*tOPequal.proc->proc)(elt1, elt2, &equal);
	if (err != ERR_ok)
	    resignal(err);

	if (!equal.tf)
	    break;
    }

    *ans = equal;
    signal(ERR_ok);
}


errcode
sequenceOPsimilar(CLUREF s1, CLUREF s2, CLUREF *ans)
{
    errcode err;
    const sequence_of_t_OPS *ops
	= ((sequence_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;

    if (s1.vec->size != s2.vec->size) {
	ans->tf = false;
	signal(ERR_ok);
    }

    if (s1.vec->size == 0) {
	ans->tf = true;
	signal(ERR_ok);
    }

    CLUREF similar = CLU_true;
    CLUREF tOPsimilar = { .proc = ops->similar.fcn };

    for (long i = 0; i < s1.vec->size; ++i) {
	CLUREF elt1 = { .num = s1.vec->data[i] };
	CLUREF elt2 = { .num = s2.vec->data[i] };

	CUR_PROC_VAR = tOPsimilar;
	err = (*tOPsimilar.proc->proc)(elt1, elt2, &similar);
	if (err != ERR_ok)
	    resignal(err);

	if (!similar.tf)
	    break;
    }

    *ans = similar;
    signal(ERR_ok);
}


errcode
sequenceOPcopy(CLUREF s1, CLUREF *ans)
{
    errcode err;
    const sequence_of_t_OPS *ops
	= ((sequence_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;

    if (s1.vec->size == 0) {
	*ans = s1;
	signal(ERR_ok);
    }

    CLUREF s2;
    sequenceOPOPalloc(s1.vec->size, &s2);

    CLUREF tOPcopy = { .proc = ops->copy.fcn };
    for (long i = 0; i < s1.vec->size; i++) {
	CLUREF elt1 = { .num = s1.vec->data[i] };

	CUR_PROC_VAR = tOPcopy;
	err = (*tOPcopy.proc->proc)(elt1, &s2.vec->data[i]);
	if (err != ERR_ok)
	    resignal(err);
    }

    *ans = s2;
    signal(ERR_ok);
}


errcode
sequenceOPindexes(CLUREF s,
		  errcode (*iterbod)(), void *user_locals, errcode *ecode2)
{
    errcode err;
    CLUREF iv_1;

    if (s.vec->size == 0)
	signal(ERR_ok);

    iv_1.num = 1;
    for (;;) {
	err = (*iterbod)(iv_1, user_locals, ecode2);
	if (err == ERR_ok) {
	    iv_1.num += 1;
	    if (iv_1.num <= s.vec->size) continue;
	    if (iv_1.num >  s.vec->size) signal(ERR_ok);
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
sequenceOPelements(CLUREF s,
		   errcode (*iterbod)(), void *user_locals, errcode *ecode2)
{
    errcode err;
    CLUREF iv_1;

    if (s.vec->size == 0)
	signal(ERR_ok);

    long index = 1;
    for (;;) {
	iv_1.num = s.vec->data[index - 1];
	err = (*iterbod)(iv_1, user_locals, ecode2);
	if (err == ERR_ok) {
	    index += 1;
	    if (index <= s.vec->size) continue;
	    if (index >  s.vec->size) signal(ERR_ok);
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
sequenceOPdebug_print(CLUREF s, CLUREF pst)
{
    errcode err;
    const sequence_of_t_OPS *ops
	= ((sequence_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;

    CLUREF tOPdebug_print = { .proc = ops->debug_print.fcn };
    err = sequenceOPinternal_print(s, pst, tOPdebug_print);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
sequenceOPprint(CLUREF s, CLUREF pst)
{
    errcode err;
    const sequence_of_t_OPS *ops
	= ((sequence_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;

    CLUREF tOPprint = { .proc = ops->print.fcn };
    err = sequenceOPinternal_print(s, pst, tOPprint);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
sequenceOPinternal_print(CLUREF s, CLUREF pst, CLUREF pfcn)
{
    errcode err;
    CLUREF ans;

    static CLUREF lbrack, comma, rbrack;
    static bool init = false;
    if (init == false) {
	stringOPcons("[", CLU_1, CLU_1, &lbrack);
	stringOPcons(",", CLU_1, CLU_1, &comma);
	stringOPcons("]", CLU_1, CLU_1, &rbrack);
	init = true;
    }

    err = pstreamOPstart(pst, lbrack, &ans);
    if (err != ERR_ok)
	resignal(err);

    if ((ans.tf == false) || (s.vec->size == 0)) {
	err = pstreamOPstop(pst, rbrack, &ans);
	if (err != ERR_ok)
	    resignal(err);

	signal(ERR_ok);
    }

    for (long i = 0; i < s.vec->size; ++i) {
	CLUREF elt = { .num = s.vec->data[i] };

	if (i != 0) {		/* print separator */
	    err = pstreamOPpause(pst, comma, &ans);
	    if (err != ERR_ok)
		resignal(err);

	    if (ans.tf == false)
		break;
	}

	CUR_PROC_VAR = pfcn;
	err = (*pfcn.proc->proc)(elt, pst);
	if (err != ERR_ok)
	    resignal(err);
    }

    err = pstreamOPstop(pst, rbrack, &ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
sequenceOPencode(CLUREF s, CLUREF ist)
{
    errcode err;
    const sequence_of_t_OPS *ops
	= ((sequence_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;

    err = istreamOPputi(ist, CLUREF_make_num(s.vec->size));
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    CLUREF tOPencode = { .proc = ops->encode.fcn };
    for (long i = 0; i < s.vec->size; ++i) {
	CLUREF elt = { .num = s.vec->data[i] };

	CUR_PROC_VAR = tOPencode;
	err = (*tOPencode.proc->proc)(elt, ist);
	if (err == ERR_not_possible)
	    signal(err);
	if (err != ERR_ok)
	    resignal(err);
    }

    signal(ERR_ok);
}


errcode
sequenceOPdecode(CLUREF ist, CLUREF *ans)
{
    errcode err;
    const sequence_of_t_OPS *ops
	= ((sequence_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;

    CLUREF size;
    err = istreamOPgeti(ist, &size);
    if (err == ERR_end_of_file)
	signal(err);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    if (size.num == 0) {
	sequenceOPnew(ans);
	signal(ERR_ok);
    }

    CLUREF s;
    sequenceOPnew2(size, &s);

    CLUREF tOPdecode = { .proc = ops->decode.fcn };
    for (long i = 0; i < size.num; ++i) {
	CLUREF elt;
	CUR_PROC_VAR = tOPdecode;
	err = (*tOPdecode.proc->proc)(ist, &elt);
	if (err == ERR_not_possible)
	    signal(err);
	if (err != ERR_ok)
	    resignal(err);

	s.vec->data[i] = elt.num;
    }

    *ans = s;
    signal(ERR_ok);
}


errcode
sequenceOP_gcd(CLUREF s, CLUREF tab, CLUREF *ans)
{
    errcode err;
    const sequence_of_t_OPS *ops
	= ((sequence_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns)->t_ops;

    CLUREF ginfo;		// := ginfo$make_b_vec(t$_gcd)
    CLUREF tOP_gcd = { .proc = ops->_gcd.fcn };
    err = oneofOPnew(CLU_2, tOP_gcd, &ginfo);
    if (err != ERR_ok)
	resignal(err);

    CLUREF sz = {
	.num = offsetof(CLU_sequence, data) // header
	     + s.vec->size * GCD_REF_SIZE   // elements
    };
    err = gcd_tabOPinsert(tab, sz, ginfo, s, ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}



OWN_ptr sequence_own_init = { .init_flag = 0 }; /* dummy */

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &sequence_own_init,		\
    .op_owns = &sequence_own_init,		\
}

static CLU_proc sequence_oe_new = CLU_proc_INIT(sequenceOPnew);
static CLU_proc sequence_oe_cons = CLU_proc_INIT(sequenceOPcons);
static CLU_proc sequence_oe_e2s = CLU_proc_INIT(sequenceOPe2s);
static CLU_proc sequence_oe_size = CLU_proc_INIT(sequenceOPsize);
static CLU_proc sequence_oe_subseq = CLU_proc_INIT(sequenceOPsubseq);
static CLU_proc sequence_oe_fill = CLU_proc_INIT(sequenceOPfill);
static CLU_proc sequence_oe_fill_copy = CLU_proc_INIT(sequenceOPfill_copy);
static CLU_proc sequence_oe_fetch = CLU_proc_INIT(sequenceOPfetch);
static CLU_proc sequence_oe_bottom = CLU_proc_INIT(sequenceOPbottom);
static CLU_proc sequence_oe_top = CLU_proc_INIT(sequenceOPtop);
static CLU_proc sequence_oe_replace = CLU_proc_INIT(sequenceOPreplace);
static CLU_proc sequence_oe_addh = CLU_proc_INIT(sequenceOPaddh);
static CLU_proc sequence_oe_addl = CLU_proc_INIT(sequenceOPaddl);
static CLU_proc sequence_oe_remh = CLU_proc_INIT(sequenceOPremh);
static CLU_proc sequence_oe_reml = CLU_proc_INIT(sequenceOPreml);
static CLU_proc sequence_oe_concat = CLU_proc_INIT(sequenceOPconcat);
static CLU_proc sequence_oe_a2s = CLU_proc_INIT(sequenceOPa2s);
static CLU_proc sequence_oe_s2a = CLU_proc_INIT(sequenceOPs2a);
static CLU_proc sequence_oe_empty = CLU_proc_INIT(sequenceOPempty);
static CLU_proc sequence_oe_elements = CLU_proc_INIT(sequenceOPelements);
static CLU_proc sequence_oe_indexes = CLU_proc_INIT(sequenceOPindexes);
static CLU_proc sequence_oe_equal = CLU_proc_INIT(sequenceOPequal);
static CLU_proc sequence_oe_similar = CLU_proc_INIT(sequenceOPsimilar);
static CLU_proc sequence_oe_copy = CLU_proc_INIT(sequenceOPcopy);
static CLU_proc sequence_oe_print = CLU_proc_INIT(sequenceOPprint);
static CLU_proc sequence_oe_encode = CLU_proc_INIT(sequenceOPencode);
static CLU_proc sequence_oe_decode = CLU_proc_INIT(sequenceOPdecode);
static CLU_proc sequence_oe__gcd = CLU_proc_INIT(sequenceOP_gcd);
static CLU_proc sequence_oe_debug_print = CLU_proc_INIT(sequenceOPdebug_print);

static struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[29];
} sequence_ops_actual = {
    29,
    &sequence_own_init,
    &sequence_own_init,
    {
	{ &sequence_oe_new, "new" },
	{ &sequence_oe_cons, "cons" },
	{ &sequence_oe_e2s, "e2s" },
	{ &sequence_oe_size, "size" },
	{ &sequence_oe_subseq, "subseq" },
	{ &sequence_oe_fill, "fill" },
	{ &sequence_oe_fill_copy, "fill_copy" },
	{ &sequence_oe_fetch, "fetch" },
	{ &sequence_oe_bottom, "bottom" },
	{ &sequence_oe_top, "top" },
	{ &sequence_oe_replace, "replace" },
	{ &sequence_oe_addh, "addh" },
	{ &sequence_oe_addl, "addl" },
	{ &sequence_oe_remh, "remh" },
	{ &sequence_oe_reml, "reml" },
	{ &sequence_oe_concat, "concat" },
	{ &sequence_oe_a2s, "a2s" },
	{ &sequence_oe_s2a, "s2a" },
	{ &sequence_oe_empty, "empty" },
	{ &sequence_oe_elements, "elements" },
	{ &sequence_oe_indexes, "indexes" },
	{ &sequence_oe_equal, "equal" },
	{ &sequence_oe_similar, "similar" },
	{ &sequence_oe_copy, "copy" },
	{ &sequence_oe_print, "print" },
	{ &sequence_oe_encode, "encode" },
	{ &sequence_oe_decode, "decode" },
	{ &sequence_oe__gcd, "_gcd" },
	{ &sequence_oe_debug_print, "debug_print" },
    }
};

struct OPS *sequence_ops = (struct OPS *)&sequence_ops_actual;
