/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_byteptr8		*/
/*						*/

/*	TODO:  indexing into wordvec needs to be fixed */

#include "pclu_err.h"
#include "pclu_sys.h"


// insert = proc (tab: cvt, z: int, inf: ginfo, x: _obj) returns (int)
extern errcode gcd_tabOPinsert(CLUREF tab, CLUREF z, CLUREF inf, CLUREF x, CLUREF *ans);

// _gcd = proc (self: cvt, tab: gcd_tab) returns (int)
extern errcode _wordvecOP_gcd(CLUREF self, CLUREF tab, CLUREF *ans);
extern OWN_ptr _wordvec_own_init;

extern errcode intOP_gcd(CLUREF self, CLUREF tab, CLUREF *ans);
extern OWN_ptr int_own_init;


// rep = record
typedef struct {
    CLUTYPE typ;
    CLUREF buf;		// : wordvec
    CLUREF idx;		// : int
    CLUREF max;		// : int
} WP;


errcode
_byteptr8OPcreate(CLUREF wv, CLUREF i, CLUREF cnt, CLUREF *ans)
{
    int size = wv.vec->size;
    int len;
    WP *temp;
    CLUREF t;

    if (i.num - 1 > size)
	signal(ERR_bounds);

    if (cnt.num >= 0)
	signal(ERR_negative_size);

    /* this code ought to take the size of the rest of the wordvec,
       not the size of the wordvec */
    len = cnt.num + i.num - 1;
    if (len > size)
	len = size;

    clu_alloc(sizeof(WP), &temp);
    temp->typ.val = 0;
    temp->typ.mark = 0;
    temp->typ.refp = 0;

    temp->buf.vec = wv.vec;
    temp->idx.num = i.num + 2;
    temp->max.num = len + 3;

    t = *((CLUREF *)&temp);
    ans->vec = t.vec;
    signal(ERR_ok);
}


errcode
_byteptr8OPreset(CLUREF bp, CLUREF wv, CLUREF i, CLUREF cnt)
{
    WP *b = (WP *)bp.ref;
    int size = wv.vec->size;
    int len;

    if (i.num - 1 > size)
	signal(ERR_bounds);

    if (cnt.num < 0)
	signal(ERR_negative_size);

    /* this code ought to take the size of the rest of the wordvec,
       not the size of the wordvec */
    len = cnt.num + i.num - 1;
    if (len > size)
	len = size;

    b->buf.vec = wv.vec;
    b->idx.num = i.num + 2;
    b->max.num = len + 3;
    signal(ERR_ok);
}


errcode
_byteptr8OPnext(CLUREF bp, CLUREF *ans)
{
    WP *b = (WP *)bp.ref;

    if (b->idx.num + 1 > b->max.num)
	signal(ERR_bounds);

    b->idx.num += 1;
    ans->word = b->buf.vec->data[b->idx.num];
    signal(ERR_ok);
}


errcode
_byteptr8OPpeek(CLUREF bp, CLUREF *ans)
{
    WP *b = (WP *)bp.ref;

    if (b->idx.num + 1 > b->max.num)
	signal(ERR_bounds);

    ans->word = b->buf.vec->data[b->idx.num + 1];
    signal(ERR_ok);
}


errcode
_byteptr8OPdeposit(CLUREF bp, CLUREF c)
{
    WP *b = (WP *)bp.ref;

    if ((b->idx.num + 1) > b->max.num)
	signal(ERR_bounds);

    b->idx.num += 1;
    b->buf.vec->data[b->idx.num] = c.word;
    signal(ERR_ok);
}


errcode
_byteptr8OPadjust(CLUREF bp, CLUREF disp)
{
    WP *b = (WP *)bp.ref;

    int newidx = disp.num + b->idx.num;
    if (newidx < 2 || newidx >b->max.num)
	signal(ERR_bounds);

    b->idx.num = newidx;
    signal(ERR_ok);
}


errcode
_byteptr8OPempty(CLUREF bp, CLUREF *ans)
{
    WP *b = (WP *)bp.ref;

    if (b->idx.num == b->max.num)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_byteptr8OPget_buf(CLUREF bp, CLUREF *ans)
{
    WP *b= (WP *)bp.ref;

    ans->vec = b->buf.vec;
    signal(ERR_ok);
}


errcode
_byteptr8OPget_index(CLUREF bp, CLUREF *ans)
{
    WP *b = (WP*)bp.ref;

    ans->num = b->idx.num - 2;
    signal(ERR_ok);
}


errcode
_byteptr8OPget_count(CLUREF bp, CLUREF *ans)
{
    WP *b = (WP*)bp.ref;

    ans->num = b->max.num - b->idx.num;
    signal(ERR_ok);
}


errcode
_byteptr8OPequal(CLUREF bp1, CLUREF bp2, CLUREF *ans)
{
    if (bp1.num == bp2.num)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_byteptr8OPsimilar(CLUREF bp1, CLUREF bp2, CLUREF *ans)
{
    WP *b1 = (WP *)bp1.ref;
    WP *b2 = (WP *)bp2.ref;

    if (b1->buf.num == b2->buf.num
	&& b1->idx.num == b2->idx.num
	&& b1->max.num == b2->max.num)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_byteptr8OPcopy(CLUREF bp, CLUREF *ans)
{
    WP *b = (WP *)bp.ref;
    WP *temp;
    CLUREF t;

    clu_alloc(sizeof(WP), &temp);
    temp->typ = b->typ;
    temp->buf = b->buf;
    temp->idx.num = b->idx.num;
    temp->max.num = b->max.num;
    t = *(CLUREF *)b;

    ans->vec = t.vec;
    signal(ERR_ok);
}


/*
 * _gcd = proc (bp: _byteptr, tab: gcd_tab) returns (int)
 */
errcode
_byteptr8OP_gcd(CLUREF bp, CLUREF tab, CLUREF *ans)
{
    errcode err;

    CLUREF wordvec_gproc;	// := _wordvec$_gcd
    proctypeOPnew(CLU_0, &wordvec_gproc);
    wordvec_gproc.proc->proc = _wordvecOP_gcd;
    wordvec_gproc.proc->type_owns = &_wordvec_own_init;
    wordvec_gproc.proc->op_owns = &_wordvec_own_init;

    CLUREF int_gproc;		// := int$_gcd
    proctypeOPnew(CLU_0, &int_gproc);
    int_gproc.proc->proc = intOP_gcd;
    int_gproc.proc->type_owns = &int_own_init;
    int_gproc.proc->op_owns = &int_own_init;

    CLUREF sel_gproclist;	// := gproclist$[...]
    sequenceOPnew2(CLU_3, &sel_gproclist);
    sel_gproclist.vec->data[0] = wordvec_gproc.num; /* buf */
    sel_gproclist.vec->data[1] = int_gproc.num;	    /* idx */
    sel_gproclist.vec->data[2] = int_gproc.num;	    /* max */

    CLUREF ginfo;		// := ginfo$make_c_sel(...)
    err = oneofOPnew(CLU_3, sel_gproclist, &ginfo);
    if (err != ERR_ok)
	resignal(err);

    CLUREF sz = { .num = sizeof(WP) };

    // return (gcd_tab$insert(tab, sz, ginfo, bp))
    err = gcd_tabOPinsert(tab, sz, ginfo, bp, ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}



OWN_ptr _byteptr8_own_init = { .init_flag = 1 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &_byteptr8_own_init,		\
    .op_owns = &_byteptr8_own_init,		\
}

static CLU_proc _byteptr8_oe_create = CLU_proc_INIT(_byteptr8OPcreate);
static CLU_proc _byteptr8_oe_equal = CLU_proc_INIT(_byteptr8OPequal);
static CLU_proc _byteptr8_oe_similar = CLU_proc_INIT(_byteptr8OPsimilar);
static CLU_proc _byteptr8_oe_copy = CLU_proc_INIT(_byteptr8OPcopy);
static CLU_proc _byteptr8_oe__gcd = CLU_proc_INIT(_byteptr8OP_gcd);
static CLU_proc _byteptr8_oe_reset = CLU_proc_INIT(_byteptr8OPreset);
static CLU_proc _byteptr8_oe_peek = CLU_proc_INIT(_byteptr8OPpeek);
static CLU_proc _byteptr8_oe_deposit = CLU_proc_INIT(_byteptr8OPdeposit);
static CLU_proc _byteptr8_oe_adjust = CLU_proc_INIT(_byteptr8OPadjust);
static CLU_proc _byteptr8_oe_empty = CLU_proc_INIT(_byteptr8OPempty);
static CLU_proc _byteptr8_oe_get_buf = CLU_proc_INIT(_byteptr8OPget_buf);
static CLU_proc _byteptr8_oe_get_index = CLU_proc_INIT(_byteptr8OPget_index);
static CLU_proc _byteptr8_oe_get_count = CLU_proc_INIT(_byteptr8OPget_count);

static struct /* OPS */ {
    int count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[13];
} _byteptr8_ops_actual = {
    13,
    &_byteptr8_own_init,
    &_byteptr8_own_init,
    {
	{ &_byteptr8_oe_create, "create" },
	{ &_byteptr8_oe_equal, "equal" },
	{ &_byteptr8_oe_similar, "similar" },
	{ &_byteptr8_oe_copy, "copy" },
	{ &_byteptr8_oe__gcd, "_gcd" },
	{ &_byteptr8_oe_reset, "reset" },
	{ &_byteptr8_oe_peek, "peek" },
	{ &_byteptr8_oe_deposit, "deposit" },
	{ &_byteptr8_oe_adjust, "adjust" },
	{ &_byteptr8_oe_empty, "empty" },
	{ &_byteptr8_oe_get_buf, "get_buf" },
	{ &_byteptr8_oe_get_index, "get_index" },
	{ &_byteptr8_oe_get_count, "get_count" },
    }
};

struct OPS *_byteptr8_ops = (struct OPS *)&_byteptr8_ops_actual;
