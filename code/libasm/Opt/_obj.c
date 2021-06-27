/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_obj			*/
/*						*/

/* may return false positives */

#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdint.h>

extern int heaplo;
extern int heaphi;

/* unimplemented */
errcode _rtn_infoOPis_proc(CLUREF s, CLUREF *ans);
errcode _rtn_infoOPis_iter(CLUREF s, CLUREF *ans);

errcode intOPprint(CLUREF i, CLUREF pst);



errcode
_objOPis_ref(CLUREF x, CLUREF *ans)
{
    if (x.num >= heaplo)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_objOPis_int_(CLUREF x, CLUREF *ans)
{
    CLU_NOREF(x);		/* XXX */
    ans->tf = true;
    signal(ERR_ok);
}


errcode
_objOPis_real_(CLUREF x, CLUREF *ans)
{
    CLU_NOREF(x);		/* XXX */
    ans->tf = false;
    signal(ERR_ok);
}


errcode
_objOPis_uninit_(CLUREF x, CLUREF *ans)
{
    if ((uintptr_t)x.num == 0x80808080)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_objOPis_proc_(CLUREF x, CLUREF *ans)
{
    errcode err;

    if (x.num <= heaphi || x.vec->typ.val != CT_PROC) {
	ans->tf = false;
	signal(ERR_ok);
    }

    /* XXX: unimplemented, always returns false */
    err = _rtn_infoOPis_proc(x, ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
_objOPis_iter_(CLUREF x, CLUREF *ans)
{
    errcode err;

    if (x.num <= heaphi || x.vec->typ.val != CT_PROC) {
	ans->tf = false;
	signal(ERR_ok);
    }

    /* XXX: unimplemented, always returns false */
    err = _rtn_infoOPis_iter(x, ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
_objOPis_routine_(CLUREF x, CLUREF *ans)
{
    if (x.num <= heaphi || x.vec->typ.val != CT_PROC) {
	ans->tf = false;
	signal(ERR_ok);
    }

    ans->tf = true;
    signal(ERR_ok);
}


errcode
_objOPis_vec(CLUREF x, CLUREF *ans)
{
    if (x.num < heaplo || x.vec->typ.val != CT_AGG) {
	ans->tf = false;
	signal(ERR_ok);
    }

    ans->tf = true;
    signal(ERR_ok);
}


errcode
_objOPis_bvec(CLUREF x, CLUREF *ans)
{
    if (x.num < heaplo || x.vec->typ.val != CT_STRING) {
	ans->tf = false;
	signal(ERR_ok);
    }

    ans->tf = true;
    signal(ERR_ok);
}


errcode
_objOPis_cell(CLUREF x, CLUREF *ans)
{
    if (x.num < heaplo || x.vec->typ.val != CT_VAR) {
	ans->tf = false;
	signal(ERR_ok);
    }

    ans->tf = true;
    signal(ERR_ok);
}


/* need to distinguish any's from variants */
errcode
_objOPis_anyize(CLUREF x, CLUREF *ans)
{
    if (x.num < heaplo || x.vec->typ.val != CT_VAR) {
	ans->tf = false;
	signal(ERR_ok);
    }

    ans->tf = true;
    signal(ERR_ok);
}


/* check array vs dope vector definition */
errcode
_objOPis_adv(CLUREF x, CLUREF *ans)
{
    if (x.num < heaplo || x.vec->typ.val != CT_ARRAY) {
	ans->tf = false;
	signal(ERR_ok);
    }

    ans->tf = true;
    signal(ERR_ok);
}


/* have no idea what an entry vector is */
errcode
_objOPis_entry_vector(CLUREF x, CLUREF *ans)
{
    if (x.num <= heaphi || x.vec->typ.val != CT_PROC) {
	ans->tf = false;
	signal(ERR_ok);
    }

    /* is it a closure: look for movl/jump instrs */
    ans->tf = true;
    signal(ERR_ok);
}


errcode
_objOPget_addr(CLUREF x, CLUREF *ans)
{
    ans->num = x.num;
    signal(ERR_ok);
}


errcode
_objOPget_left(CLUREF x, CLUREF *ans)
{
    ans->num = (x.num >> 16) & 0xffff;
    signal(ERR_ok);
}


errcode
_objOPget_right(CLUREF x, CLUREF *ans)
{
    ans->num = x.num & 0xffff;
    signal(ERR_ok);
}


errcode
_objOPlt(CLUREF x, CLUREF y, CLUREF *ans)
{
    if ((uintptr_t)x.num < (uintptr_t)y.num)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_objOPle(CLUREF x, CLUREF y, CLUREF *ans)
{
    if ((uintptr_t)x.num <= (uintptr_t)y.num)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_objOPge(CLUREF x, CLUREF y, CLUREF *ans)
{
    if ((uintptr_t)x.num >= (uintptr_t)y.num)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_objOPgt(CLUREF x, CLUREF y, CLUREF *ans)
{
    if ((uintptr_t)x.num > (uintptr_t)y.num)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_objOPequal(CLUREF x, CLUREF y, CLUREF *ans)
{
    if (x.num == y.num)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_objOPsimilar(CLUREF x, CLUREF y, CLUREF *ans)
{
    if (x.num == y.num)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_objOPcopy(CLUREF x, CLUREF *ans)
{
    ans->num = x.num;
    signal(ERR_ok);
}


errcode
_objOPprint(CLUREF x, CLUREF ps)
{
    errcode err;

    err = intOPprint(x, ps);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


OWN_ptr _obj_own_init = { .init_flag = 1 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &_obj_own_init,		\
    .op_owns = &_obj_own_init,			\
}

static CLU_proc _obj_oe_copy = CLU_proc_INIT(_objOPcopy);
static CLU_proc _obj_oe_equal = CLU_proc_INIT(_objOPequal);
static CLU_proc _obj_oe_similar = CLU_proc_INIT(_objOPsimilar);
static CLU_proc _obj_oe_print = CLU_proc_INIT(_objOPprint);
static CLU_proc _obj_oe_lt = CLU_proc_INIT(_objOPlt);
static CLU_proc _obj_oe_le = CLU_proc_INIT(_objOPle);
static CLU_proc _obj_oe_ge = CLU_proc_INIT(_objOPge);
static CLU_proc _obj_oe_gt = CLU_proc_INIT(_objOPgt);

static struct /* OPS */ {
    int count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[9];
} _obj_ops_actual = {
    9,
    &_obj_own_init,
    &_obj_own_init, {
	{ &_obj_oe_copy, "copy" },
	{ &_obj_oe_equal, "equal" },
	{ &_obj_oe_similar, "similar" },
	{ &_obj_oe_print, "debug_print" },
	{ &_obj_oe_print, "print" },
	{ &_obj_oe_lt, "lt" },
	{ &_obj_oe_le, "le" },
	{ &_obj_oe_ge, "ge" },
	{ &_obj_oe_gt, "gt" },
    }
};

struct OPS *_obj_ops = (struct OPS *)&_obj_ops_actual;
