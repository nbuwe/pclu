/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_adv			*/
/*	a clone of the array type		*/
/*		with more intimate operations	*/
/*						*/
/* TODO: make pred fields real			*/

#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode arrayOPOPnewdesc(CLUREF *ans);
extern errcode arrayOPinternal_print(CLUREF a, CLUREF pst, CLUREF pfcn);

// insert = proc (tab: cvt, z: int, inf: ginfo, x: _obj) returns (int)
extern errcode gcd_tabOPinsert(CLUREF tab, CLUREF z, CLUREF inf, CLUREF x, CLUREF *ans);


/*
 * What _adv[T] requires of T.
 */
static const struct /* REQS */ {
    long count;
    const struct REQ_ENTRY entry[2];
} _adv_of_t_reqs_actual = {
    2, {
	{ "_gcd" },
	{ "debug_print" },
    }
};

const struct REQS * const _adv_of_t_reqs
    = (const struct REQS *)&_adv_of_t_reqs_actual;


/*
 * An interface to T for an _adv[T] instance (as specified by REQS).
 */
typedef struct /* OPS */ {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY _gcd;
    struct OP_ENTRY debug_print;
} _adv_of_t_OPS;


/*
 * Own data of an _adv[T] instance.
 */
typedef struct /* OWN_ptr */ {
    long _adv_own_init;		/* unused */
    const _adv_of_t_OPS * const t_ops;
} _adv_OWN_DEFN;


/*
 * Tell instantiation code how to construct an _adv_OWN_DEFN object
 * for an _adv[T] instantce.  What "own_count" really tells is where
 * the parameters start (OPS for types, values for constants).
 */
const OWN_req _adv_ownreqs = { sizeof(_adv_OWN_DEFN), 1 };



errcode
_advOPcreate(CLUREF low, CLUREF pred, CLUREF v, CLUREF *ret_1)
{
    CLUREF temp;
    errcode err;

    if (low.num < MIN_ARR_INDEX)
	signal(ERR_bounds);

    err = arrayOPOPnewdesc(&temp);
    if (err != ERR_ok)
	goto ex_0;

    temp.array->ext_low = low.num;
    temp.array->ext_size = v.vec->size;
    temp.array->ext_high = low.num + v.vec->size - 1;
    temp.array->int_low = 0;
    temp.array->int_size = v.vec->size;
    temp.array->store = v.store;

    ret_1->array = temp.array;
    signal(ERR_ok);

  ex_0: {
	if (err == ERR_failure)
	    signal(ERR_failure);
	elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}


errcode
_advOPequal(CLUREF adv1, CLUREF adv2, CLUREF *ret_1)
{
    if (adv1.num == adv2.num)
	ret_1->tf = true;
    else
	ret_1->tf = false;
    signal(ERR_ok);
}


errcode
_advOPget_low(CLUREF adv, CLUREF *ret_1)
{
    ret_1->num = adv.array->ext_low;
    signal(ERR_ok);
}


errcode
_advOPset_low(CLUREF adv, CLUREF low)
{
    if (low.num < MIN_ARR_INDEX)
	signal(ERR_bounds);

    if (low.num + adv.array->ext_size > MAX_ARR_INDEX)
	signal(ERR_bounds);

    adv.array->ext_low = low.num;
    adv.array->ext_high = low.num + adv.array->ext_size - 1;
    signal(ERR_ok);
}


errcode
_advOPget_size(CLUREF adv, CLUREF *ret_1)
{
    ret_1->num = adv.array->ext_size;
    signal(ERR_ok);
}


errcode
_advOPset_size(CLUREF adv, CLUREF size)
{
    if (size.num < 0)
	signal(ERR_bounds);

    if (adv.array->ext_size + size.num > MAX_ARR_INDEX)
	signal(ERR_bounds);

    if (adv.array->store->size - adv.array->int_low - size.num < 0)
	signal(ERR_bounds);

    adv.array->ext_size = size.num;
    adv.array->ext_high = size.num + adv.array->ext_low - 1;
    signal(ERR_ok);
}


errcode
_advOPget_start(CLUREF adv, CLUREF *ret_1)
{
    ret_1->num = adv.array->int_low + 1;
    signal(ERR_ok);
}


errcode
_advOPset_start(CLUREF adv, CLUREF strt)
{
    long new_size;
    long new_strt;

    if (strt.num < 1)
	signal(ERR_bounds);

    new_strt = strt.num - 1;
    new_size = adv.array->int_low - new_strt + adv.array->ext_size;

    if (new_size < 0)
	signal(ERR_bounds);

    if (adv.array->ext_low + new_size > MAX_ARR_INDEX)
	signal(ERR_bounds);

    adv.array->ext_size = new_size;
    adv.array->int_low = new_strt;
    adv.array->ext_high = adv.array->ext_low + new_size - 1;
    signal(ERR_ok);	/* trim back store as well? */
}


errcode
_advOPget_predict(CLUREF adv, CLUREF *ret_1)
{
    ret_1->num = adv.array->int_size;
    signal(ERR_ok);
}


errcode
_advOPset_predict(CLUREF adv, CLUREF pred)
{
    signal(ERR_ok);
}


errcode
_advOPget_vector(CLUREF adv, CLUREF *ret_1)
{
    ret_1->store = adv.array->store;
    signal(ERR_ok);
}


errcode
_advOPset_vector(CLUREF adv, CLUREF v)
{
    if (adv.array->ext_low + v.vec->size > MAX_ARR_INDEX)
	signal(ERR_bounds);

    adv.array->int_size = v.vec->size;
    adv.array->ext_size = v.vec->size;
    adv.array->ext_high = adv.array->ext_low + adv.array->ext_size - 1;
    adv.array->store = (CLUSTORE)v.vec;
    adv.array->int_low = 0;
    signal(ERR_ok);
}


errcode
_advOP_gcd(CLUREF adv, CLUREF tab, CLUREF *ans)
{
    _adv_OWN_DEFN *type_own_ptr = (_adv_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns;
    errcode err;
    CLUREF temp_oneof, temp_oneof_2, sz, fcn;

    fcn.proc = type_own_ptr->t_ops->_gcd.fcn;
    err = oneofOPnew(CLU_7, fcn, &temp_oneof);
    if (err != ERR_ok)
	resignal(err);

    err = oneofOPnew(CLU_6, temp_oneof, &temp_oneof_2);
    if (err != ERR_ok)
	resignal(err);

    sz.num = GCD_REF_SIZE + 6 * CLUREFSZ;
    err = gcd_tabOPinsert(tab, sz, temp_oneof_2, adv, ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);

  ex_0: {
	if (err == ERR_failure)
	    signal(ERR_failure);
	elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}


errcode
_advOPdebug_print(CLUREF adv, CLUREF ps)
{
    _adv_OWN_DEFN *type_own_ptr = (_adv_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns;
    errcode err;
    CLUREF pfcn;

    pfcn.proc = type_own_ptr->t_ops->debug_print.fcn;
    err = arrayOPinternal_print(adv, ps, pfcn);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


OWN_ptr _adv_own_init; /* dummy */

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &_adv_own_init,		\
    .op_owns = &_adv_own_init,			\
}

static CLU_proc _adv_oe_create = CLU_proc_INIT(_advOPcreate);
static CLU_proc _adv_oe_equal = CLU_proc_INIT(_advOPequal);
static CLU_proc _adv_oe_get_low = CLU_proc_INIT(_advOPget_low);
static CLU_proc _adv_oe_get_predict = CLU_proc_INIT(_advOPget_predict);
static CLU_proc _adv_oe_get_size = CLU_proc_INIT(_advOPget_size);
static CLU_proc _adv_oe_get_start = CLU_proc_INIT(_advOPget_start);
static CLU_proc _adv_oe_get_vector = CLU_proc_INIT(_advOPget_vector);
static CLU_proc _adv_oe_set_low = CLU_proc_INIT(_advOPset_low);
static CLU_proc _adv_oe_set_predict = CLU_proc_INIT(_advOPset_predict);
static CLU_proc _adv_oe_set_size = CLU_proc_INIT(_advOPset_size);
static CLU_proc _adv_oe_set_start = CLU_proc_INIT(_advOPset_start);
static CLU_proc _adv_oe_set_vector = CLU_proc_INIT(_advOPset_vector);
static CLU_proc _adv_oe__gcd = CLU_proc_INIT(_advOP_gcd);
static CLU_proc _adv_oe_debug_print = CLU_proc_INIT(_advOPdebug_print);

/* extends struct OPS */
typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[14];
} _adv_OPS;

static _adv_OPS _adv_ops_actual = {
    14,
    &_adv_own_init,
    &_adv_own_init, {
	{ &_adv_oe_create, "create" },
	{ &_adv_oe_equal, "equal" },
	{ &_adv_oe_get_low, "get_low" },
	{ &_adv_oe_get_predict, "get_predict" },
	{ &_adv_oe_get_size, "get_size" },
	{ &_adv_oe_get_start, "get_start" },
	{ &_adv_oe_get_vector, "get_vector" },
	{ &_adv_oe_set_low, "set_low" },
	{ &_adv_oe_set_predict, "set_predict" },
	{ &_adv_oe_set_size, "set_size" },
	{ &_adv_oe_set_start, "set_start" },
	{ &_adv_oe_set_vector, "set_vector" },
	{ &_adv_oe__gcd, "_gcd" },
	{ &_adv_oe_debug_print, "debug_print" },
    }
};

struct OPS *_adv_ops = (struct OPS *)&_adv_ops_actual;
