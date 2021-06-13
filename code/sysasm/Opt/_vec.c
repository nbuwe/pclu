/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_vec			*/
/*    sort of a mutable sequence		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode gcd_tabOPinsert(CLUREF tab, CLUREF z, CLUREF inf, CLUREF x, CLUREF *ans);
extern errcode sequenceOPinternal_print(CLUREF s, CLUREF pst, CLUREF pfcn);


/*
 * What _vec[T] requires of T.
 */
static struct /* REQS */ {
    int count;
    struct REQ_ENTRY entry[2];
} _vec_of_t_reqs_actual = {
    2, {
	{ "_gcd" },
	{ "debug_print" },
    }
};

const struct REQS * const _vec_of_t_reqs
    = (const struct REQS *)&_vec_of_t_reqs_actual;


/*
 * An interface to T for a _vec[T] instance (as specified by REQS).
 */
typedef struct {
    int count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY _gcd;
    struct OP_ENTRY debug_print;
} _vec_of_t_OPS;


/*
 * Own data of a _vec[T] instance.
 */
typedef struct /* OWN_ptr */ {
    long _vec_own_init;		/* unused */
    const _vec_of_t_OPS * const t_ops;
} _vec_OWN_DEFN;


/*
 * Tell instantiation code how to construct an _OWN_DEFN object for an
 * instantce.  What "own_count" really tells is where the parameters
 * start (OPS for types, values for constants).
 */
const OWN_req _vec_ownreqs = { sizeof(_vec_OWN_DEFN), 1 };



errcode
_vecOPcreate(CLUREF sz, CLUREF *ans)
{
    /*
     * Using sequenceOPnew for empty _vec's is NOT A GOOD IDEA:
     * sequences are immutable, but _vec's are used for array stores
     * by gc_read and there is but a single empty sequence in the
     * world and mtv's array$addh frees stores that are being
     * replaced.  7/23/93 dcurtis
     */
#if 0
    if (sz.num == 0) {
	err = sequenceOPnew(&temp);
	ans->vec = temp.vec;
	signal(ERR_ok);
    }
#endif

    if (sz.num < 0)
	signal(ERR_negative_size);
    if (sz.num > MAX_SEQ)
	signal(ERR_toobig);

    size_t bufsz = offsetof(CLU_sequence, data) + sz.num * CLUREFSZ;

    CLUREF v;
    clu_alloc(bufsz, &v);
    CLUTYPE_set(v.vec->typ, CT_AGG);
    v.vec->size = sz.num;
    // v.vec->data[] is zeroed out by the allocator

    ans->vec = v.vec;
    signal(ERR_ok);
}


errcode
_vecOPcopy(CLUREF v, CLUREF *ans)
{
    errcode err;

    CLUREF v2;
    err = _vecOPcreate(CLUREF_make_num(v.vec->size), &v2);
    if (err != ERR_ok)
	resignal(err);

    memcpy(v2.vec->data, v.vec->data, v.vec->size * CLUREFSZ);

    ans->vec = v2.vec;
    signal(ERR_ok);
}


errcode
_vecOPfetch(CLUREF v, CLUREF i, CLUREF *ans)
{
    if (i.num < 1)
	signal(ERR_bounds);
    if (i.num > v.vec->size)
	signal(ERR_bounds);

    ans->num = v.vec->data[i.num - 1];
    signal(ERR_ok);
}


errcode
_vecOPstore(CLUREF v, CLUREF i, CLUREF val)
{
    if (i.num < 1)
	signal(ERR_bounds);
    if (i.num > v.vec->size)
	signal(ERR_bounds);

    v.vec->data[i.num - 1] = val.num;
    signal(ERR_ok);
}


errcode
_vecOPsize(CLUREF v, CLUREF *ans)
{
    ans->num = v.vec->size;
    signal(ERR_ok);
}


errcode
_vecOPequal(CLUREF v1, CLUREF v2, CLUREF *ans)
{
    if (v1.ref == v2.ref)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_vecOPmove_lr(CLUREF v1, CLUREF s1, CLUREF v2, CLUREF s2, CLUREF len)
{
    if (len.num == 0)
	signal(ERR_ok);

    if (len.num < 0)
	signal(ERR_negative_size);
    if (s1.num > v1.vec->size)
	signal(ERR_bounds);
    if (s2.num > v2.vec->size)
	signal(ERR_bounds);

    int copycount = len.num;
    if (s1.num + copycount > v1.vec->size)
	copycount = v1.vec->size - s1.num + 1;
    if (s2.num + copycount > v2.vec->size)
	copycount = v2.vec->size - s2.num + 1;
    for (int i = 0; i < copycount; ++i) {
	v2.vec->data[s2.num + i - 1] = v1.vec->data[s1.num + i - 1];
    }
    signal(ERR_ok);
}


errcode
_vecOPmove_rl(CLUREF v1, CLUREF s1, CLUREF v2, CLUREF s2, CLUREF len)
{
    if (len.num == 0)
	signal(ERR_ok);

    if (len.num < 0)
	signal(ERR_negative_size);
    if (s1.num > v1.vec->size)
	signal(ERR_bounds);
    if (s2.num > v2.vec->size)
	signal(ERR_bounds);

    int copycount = len.num;
    if (s1.num + copycount > v1.vec->size)
	copycount = v1.vec->size - s1.num + 1;
    if (s2.num + copycount > v2.vec->size)
	copycount = v2.vec->size - s2.num + 1;
    for (int i = copycount - 1; i >= 0; --i) {
	v2.vec->data[s2.num + i - 1] = v1.vec->data[s1.num + i - 1];
    }
    signal(ERR_ok);
}


errcode
_vecOP_gcd(CLUREF v, CLUREF tab, CLUREF *ans)
{
    errcode err;
    _vec_OWN_DEFN *type_own_ptr
	= (_vec_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns;

    CLUREF ginfo;		// := ginfo$make_b_vec(T$gcd)
    CLUREF tOP_gcd = { .proc = type_own_ptr->t_ops->_gcd.fcn };
    err = oneofOPnew(CLU_2, tOP_gcd, &ginfo);
    if (err != ERR_ok)
	resignal(err);

    CLUREF sz = {
	.num = offsetof(CLU_sequence, data) // header
	     + v.vec->size * GCD_REF_SIZE   // elements
    };
    err = gcd_tabOPinsert(tab, sz, ginfo, v, ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
_vecOPdebug_print(CLUREF v, CLUREF pst)
{
    errcode err;
    _vec_OWN_DEFN *type_own_ptr
	= (_vec_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns;

    CLUREF tOPdebug_print = { .proc = type_own_ptr->t_ops->debug_print.fcn };
    err = sequenceOPinternal_print(v, pst, tOPdebug_print);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}



OWN_ptr _vec_own_init;		/* dummy */

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &_vec_own_init,		\
    .op_owns = &_vec_own_init,			\
}

static CLU_proc _vec_oe_create = CLU_proc_INIT(_vecOPcreate);
static CLU_proc _vec_oe_equal = CLU_proc_INIT(_vecOPequal);
static CLU_proc _vec_oe_copy = CLU_proc_INIT(_vecOPcopy);
static CLU_proc _vec_oe_fetch = CLU_proc_INIT(_vecOPfetch);
static CLU_proc _vec_oe_store = CLU_proc_INIT(_vecOPstore);
static CLU_proc _vec_oe_size = CLU_proc_INIT(_vecOPsize);
static CLU_proc _vec_oe_move_lr = CLU_proc_INIT(_vecOPmove_lr);
static CLU_proc _vec_oe_move_rl = CLU_proc_INIT(_vecOPmove_rl);
static CLU_proc _vec_oe__gcd = CLU_proc_INIT(_vecOP_gcd);
static CLU_proc _vec_oe_debug_print = CLU_proc_INIT(_vecOPdebug_print);


static struct /* OPS */ {
    int count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[10];
} _vec_ops_actual = {
    10,
    &_vec_own_init,
    &_vec_own_init,
    {
	{ &_vec_oe_create, "create" },
	{ &_vec_oe_equal, "equal" },
	{ &_vec_oe_copy, "copy" },
	{ &_vec_oe_fetch, "fetch" },
	{ &_vec_oe_store, "store" },
	{ &_vec_oe_size, "size" },
	{ &_vec_oe_move_lr, "move_lr" },
	{ &_vec_oe_move_rl, "move_rl" },
	{ &_vec_oe__gcd, "_gcd" },
	{ &_vec_oe_debug_print, "debug_print" },
    }
};

struct OPS *_vec_ops = (struct OPS *)&_vec_ops_actual;
