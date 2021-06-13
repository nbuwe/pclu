/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_tagcell		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode gcd_tabOPinsert(CLUREF tab, CLUREF z, CLUREF inf, CLUREF x, CLUREF *ans);


/*
 * What _tagcell[T] requires of T.
 */
static const struct /* REQS */ {
    long count;
    struct REQ_ENTRY entry[1];
} _tagcell_of_t_reqs_actual = {
    1, {
	{ "_gcd" },
    }
};

const struct REQS * const _tagcell_of_t_reqs
    = (const struct REQS *)&_tagcell_of_t_reqs_actual;


/*
 * An interface to T for a _tagcell[T] instance (as specified by REQS).
 */
typedef struct /* OPS */ {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY _gcd;
} _tagcell_of_t_OPS;


/*
 * Own data of a _tagcell[T] instance.
 */
typedef struct /* OWN_ptr */ {
    long _tagcell_own_init;	/* unused */
    const _tagcell_of_t_OPS * const t_ops;
} _tagcell_OWN_DEFN;


/*
 * Tell instantiation code how to construct an _OWN_DEFN object for an
 * instantce.  What "own_count" really tells is where the parameters
 * start (OPS for types, values for constants).
 */
const OWN_req _tagcell_ownreqs = { sizeof(_tagcell_OWN_DEFN), 1 };



errcode
_tagcellOPcreate(CLUREF tg, CLUREF val, CLUREF *ans)
{
    if (tg.num >= cellOPmaxtag)
	signal(ERR_toobig);

    CLUREF tt;
    clu_alloc(sizeof(CLU_cell), &tt);
    CLUTYPE_set(tt.cell->typ, CT_TAG);
    tt.cell->tag = tg.num;
    tt.cell->value = val.num;

    ans->cell = tt.cell;
    signal(ERR_ok);
}


errcode
_tagcellOPcopy(CLUREF tt, CLUREF *ans)
{
    errcode err;

    CLUREF tt2;
    err = _tagcellOPcreate(CLUREF_make_num(tt.cell->tag),
			   CLUREF_make_num(tt.cell->value),
			   &tt2);
    if (err != ERR_ok)
	resignal(err);

    ans->cell = tt2.cell;
    signal(ERR_ok);
}


errcode
_tagcellOPget(CLUREF tt, CLUREF *ans1, CLUREF *ans2)
{
    ans1->num = tt.cell->tag;
    ans2->num = tt.cell->value;
    signal(ERR_ok);
}


errcode
_tagcellOPset(CLUREF tt, CLUREF tg, CLUREF val)
{
    if (tg.num > cellOPmaxtag)
	signal(ERR_toobig);

    tt.cell->tag = tg.num;
    tt.cell->value = val.num;
    signal(ERR_ok);
}


errcode
_tagcellOPset_value(CLUREF tt, CLUREF val)
{
    tt.cell->value = val.num;
    signal(ERR_ok);
}


errcode
_tagcellOPequal(CLUREF t1, CLUREF t2, CLUREF *ans)
{
    if (t1.ref == t2.ref)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_tagcellOP_gcd(CLUREF tt, CLUREF tab, CLUREF *ans)
{
    errcode err;
    _tagcell_OWN_DEFN *type_own_ptr
	= (_tagcell_OWN_DEFN *)CUR_PROC_VAR.proc->type_owns;

    CLUREF ginfo;		// := ginfo$make_e_sell(T$_gcd)
    CLUREF tOP_gcd = { .proc = type_own_ptr->t_ops->_gcd.fcn };
    err = oneofOPnew(CLU_5, tOP_gcd, &ginfo);
    if (err != ERR_ok)
	resignal(err);

    CLUREF sz = { .num = GCD_REF_SIZE + 2 * CLUREFSZ };
    err = gcd_tabOPinsert(tab,  sz, ginfo, tt, ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}



OWN_ptr _tagcell_own_init; 	/* dummy */

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &_tagcell_own_init,		\
    .op_owns = &_tagcell_own_init,		\
}

static CLU_proc _tagcell_oe_create = CLU_proc_INIT(_tagcellOPcreate);
static CLU_proc _tagcell_oe_equal = CLU_proc_INIT(_tagcellOPequal);
static CLU_proc _tagcell_oe_copy = CLU_proc_INIT(_tagcellOPcopy);
static CLU_proc _tagcell_oe_get = CLU_proc_INIT(_tagcellOPget);
static CLU_proc _tagcell_oe_set = CLU_proc_INIT(_tagcellOPset);
static CLU_proc _tagcell_oe_set_value = CLU_proc_INIT(_tagcellOPset_value);
static CLU_proc _tagcell_oe__gcd = CLU_proc_INIT(_tagcellOP_gcd);

typedef struct /* OPS*/ {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[7];
} _tagcell_OPS;

static _tagcell_OPS _tagcell_ops_actual = {
    7,
    &_tagcell_own_init,
    &_tagcell_own_init,
    {
	{ &_tagcell_oe_create, "create" },
	{ &_tagcell_oe_equal, "equal" },
	{ &_tagcell_oe_copy, "copy" },
	{ &_tagcell_oe_get, "get" },
	{ &_tagcell_oe_set, "set" },
	{ &_tagcell_oe_set_value, "set_value" },
	{ &_tagcell_oe__gcd, "_gcd" },
    }
};

struct OPS *_tagcell_ops = (struct OPS *)&_tagcell_ops_actual;
