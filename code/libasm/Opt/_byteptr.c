/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_byteptr		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode _rtn_infoOPis_proc();
extern errcode _rtn_infoOPis_iter();
extern errcode _printn();

extern errcode _bytevecOP_gcd();
extern OWN_ptr _bytevec_own_init;
extern OWN_ptr int_own_init;
extern errcode intOP_gcd();

typedef struct {
    CLUTYPE typ;
    CLUREF buf;			/* bytevec */
    CLUREF idx;
    CLUREF max;
} BP;


errcode
_byteptrOPcreate(CLUREF bv, CLUREF i, CLUREF cnt, CLUREF *ans)
{
    int size = bv.vec->size;
    int len;
    BP *temp;
    CLUREF t;

    if (i.num - 1 > size)
	signal(ERR_bounds);

    if (cnt.num >= 0)
	signal(ERR_negative_size);

    /* this code ought to take the size of the rest of the bytevec,
       not the size of the bytevec */
    len = cnt.num + i.num - 1;
    if (len > size)
	len = size;

    clu_alloc(sizeof(BP), &temp);
    temp->typ.val = 0;
    temp->typ.mark = 0;
    temp->typ.refp = 0;
    temp->buf.vec = bv.vec;
    temp->idx.num = i.num + 2;
    temp->max.num = len + 3;
    t = *((CLUREF *)&temp);

    ans->vec = t.vec;
    signal(ERR_ok);
}


errcode
_byteptrOPreset(CLUREF bp, CLUREF bv, CLUREF i, CLUREF cnt)
{
    BP *b = (BP *)bp.ref;
    int size = bv.vec->size;
    int len;

    if (i.num - 1 > size)
	signal(ERR_bounds);

    if (cnt.num < 0)
	signal(ERR_negative_size);

    /* this code ought to take the size of the rest of the bytevec,
       not the size of the bytevec */
    len = cnt.num + i.num - 1;
    if (len > size)
	len = size;

    b->buf.vec = bv.vec;
    b->idx.num = i.num + 2;
    b->max.num = len + 3;
    signal(ERR_ok);
}


errcode
_byteptrOPnext(CLUREF bp, CLUREF *ans)
{
    BP *b = (BP *)bp.ref;

    if (b->idx.num + 1 > b->max.num)
	signal(ERR_bounds);

    b->idx.num += 1;
    ans->ch = b->buf.vec->data[b->idx.num];
    signal(ERR_ok);
}


errcode
_byteptrOPpeek(CLUREF bp, CLUREF *ans)
{
    BP *b = (BP *)bp.ref;

    if (b->idx.num + 1 > b->max.num)
	signal(ERR_bounds);

    ans->ch = b->buf.vec->data[b->idx.num + 1];
    signal(ERR_ok);
}


errcode
_byteptrOPdeposit(CLUREF bp, CLUREF c)
{
    BP *b = (BP *)bp.ref;

    if ((b->idx.num + 1) > b->max.num)
	signal(ERR_bounds);

    b->idx.num += 1;
    b->buf.vec->data[b->idx.num] = c.ch;
    signal(ERR_ok);
}


errcode
_byteptrOPadjust(CLUREF bp, CLUREF disp)
{
    BP *b = (BP *)bp.ref;

    int newidx = disp.num + b->idx.num;
    if (newidx < 2 || newidx >b->max.num)
	signal(ERR_bounds);

    b->idx.num = newidx;
    signal(ERR_ok);
}


errcode
_byteptrOPempty(CLUREF bp, CLUREF *ans)
{
    BP *b = (BP *)bp.ref;

    if (b->idx.num == b->max.num)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_byteptrOPget_buf(CLUREF bp, CLUREF *ans)
{
    BP *b= (BP *)bp.ref;

    ans->vec = b->buf.vec;
    signal(ERR_ok);
}


errcode
_byteptrOPget_index(CLUREF bp, CLUREF *ans)
{
    BP *b = (BP *)bp.ref;

    ans->num = b->idx.num - 2;
    signal(ERR_ok);
}


errcode
_byteptrOPget_count(CLUREF bp, CLUREF *ans)
{
    BP *b = (BP *)bp.ref;

    ans->num = b->max.num - b->idx.num;
    signal(ERR_ok);
}


errcode
_byteptrOPequal(CLUREF bp1, CLUREF bp2, CLUREF *ans)
{
    if (bp1.num == bp2.num)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_byteptrOPsimilar(CLUREF bp1, CLUREF bp2, CLUREF *ans)
{
    BP *b1 = (BP *)bp1.ref;
    BP *b2 = (BP *)bp2.ref;

    if (b1->buf.num == b2->buf.num
	&& b1->idx.num == b2->idx.num
	&& b1->max.num == b2->max.num)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_byteptrOPcopy(CLUREF bp, CLUREF *ans)
{
    BP *b = (BP *)bp.ref;
    BP *temp;
    CLUREF t;


    clu_alloc(sizeof(BP), &temp);
    temp->typ = b->typ;
    temp->buf = b->buf;
    temp->idx.num = b->idx.num;
    temp->max.num = b->max.num;
    t = *(CLUREF *)b;

    ans->vec = t.vec;
    signal(ERR_ok);
}


errcode
_byteptrOP_gcd(CLUREF bp, CLUREF tab, CLUREF *ans)
{
    errcode err;
    CLUREF temp_oneof, temp_seq, temp_proc1, temp_proc2, sz;

    proctypeOPnew(CLU_0, &temp_proc1);
    temp_proc1.proc->proc = _bytevecOP_gcd;
    temp_proc1.proc->type_owns = &_bytevec_own_init;
    temp_proc1.proc->op_owns = &_bytevec_own_init;

    proctypeOPnew(CLU_0, &temp_proc2);
    temp_proc2.proc->proc = intOP_gcd;
    temp_proc2.proc->type_owns = &int_own_init;
    temp_proc2.proc->op_owns = &int_own_init;

    sequenceOPnew2(CLU_3, &temp_seq);
    temp_seq.vec->data[0] = temp_proc1.num;
    temp_seq.vec->data[1] = temp_proc2.num;
    temp_seq.vec->data[2] = temp_proc2.num;

    err = oneofOPnew(CLU_3, temp_seq, &temp_oneof);
    if (err != ERR_ok)
	resignal(err);

    sz.num = sizeof(BP);
    err = gcd_tabOPinsert(tab, sz, temp_oneof, bp, ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


typedef struct {
    int count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[13];
} _byteptr_OPS;

static CLU_proc _byteptr_oe_create = { .proc = _byteptrOPcreate };
static CLU_proc _byteptr_oe_equal = { .proc = _byteptrOPequal };
static CLU_proc _byteptr_oe_similar = { .proc = _byteptrOPsimilar };
static CLU_proc _byteptr_oe_copy = { .proc = _byteptrOPcopy };
static CLU_proc _byteptr_oe__gcd = { .proc = _byteptrOP_gcd };
static CLU_proc _byteptr_oe_reset = { .proc = _byteptrOPreset };
static CLU_proc _byteptr_oe_peek = { .proc = _byteptrOPpeek };
static CLU_proc _byteptr_oe_deposit = { .proc = _byteptrOPdeposit };
static CLU_proc _byteptr_oe_adjust = { .proc = _byteptrOPadjust };
static CLU_proc _byteptr_oe_empty = { .proc = _byteptrOPempty };
static CLU_proc _byteptr_oe_get_buf = { .proc = _byteptrOPget_buf };
static CLU_proc _byteptr_oe_get_index = { .proc = _byteptrOPget_index };
static CLU_proc _byteptr_oe_get_count = { .proc = _byteptrOPget_count };

static OWN_ptr _byteptr_own_init = { .init_flag = 1 };

static _byteptr_OPS _byteptr_ops_actual = {
    13,
    &_byteptr_own_init,
    &_byteptr_own_init,
    {
	{ &_byteptr_oe_create, "create" },
	{ &_byteptr_oe_equal, "equal" },
	{ &_byteptr_oe_similar, "similar" },
	{ &_byteptr_oe_copy, "copy" },
	{ &_byteptr_oe__gcd, "_gcd" },
	{ &_byteptr_oe_reset, "reset" },
	{ &_byteptr_oe_peek, "peek" },
	{ &_byteptr_oe_deposit, "deposit" },
	{ &_byteptr_oe_adjust, "adjust" },
	{ &_byteptr_oe_empty, "empty" },
	{ &_byteptr_oe_get_buf, "get_buf" },
	{ &_byteptr_oe_get_index, "get_index" },
	{ &_byteptr_oe_get_count, "get_count" },
    }
};

struct OPS *_byteptr_ops = (struct OPS *)&_byteptr_ops_actual;
