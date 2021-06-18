/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*							*/
/*		RECORD IMPLEMENTATION			*/
/*							*/

#include "pclu_err.h"
#include "pclu_sys.h"

errcode gcd_tabOPinsert(CLUREF tab, CLUREF z, CLUREF inf, CLUREF x, CLUREF *ret_1);
errcode istreamOPgeti(CLUREF ist, CLUREF *ret_1);
errcode istreamOPputi(CLUREF ist, CLUREF i);
errcode pstreamOPpause(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPstart(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPstop(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPtext(CLUREF ps, CLUREF s, CLUREF *ret_1);

errcode recordOPprint(CLUREF rec, CLUREF pst);


errcode
recordOPnew(CLUREF size, CLUREF *ans)
{
    CLUREF temp;
    clu_alloc((size.num - 1)* (sizeof(CLUREF)) + sizeof(CLU_sequence), &temp);
    temp.vec->typ.mark = 0;
    temp.vec->typ.val = CT_REC;
    temp.vec->typ.refp = 0;
    temp.vec->typ.spare = 0;
    temp.vec->size = size.num;

    ans->vec = temp.vec;
    signal(ERR_ok);
}


errcode recordOPcopy(CLUREF r, CLUREF *ans)
{
    CLUPROC *field_copy = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;
    errcode err;
    CLUREF r2;
    CLUREF size, e1, e2;
    long i;

    size.num = r.vec->size;
    clu_alloc((size.num - 1)* (sizeof(CLUREF)) + sizeof(CLU_sequence), &r2);
    r2.vec->typ.mark = 0;
    r2.vec->typ.val = CT_REC;
    r2.vec->typ.refp = 0;
    r2.vec->typ.spare = 0;
    r2.vec->size = size.num;

    for (i = 0; i < size.num ; ++i) {
	e1.num = r.vec->data[i];

	CUR_PROC_VAR.proc = field_copy[i];
	err = (*field_copy[i]->proc)(e1, &e2);
	r2.vec->data[i] = e2.num;
	if (err != ERR_ok)
	    resignal(err);
    }

    ans->vec = r2.vec;
    signal(ERR_ok);
}


errcode
recordOPcopy1(CLUREF r, CLUREF *ans)
{
    CLUREF r2;
    CLUREF size;
    long i;

    size.num = r.vec->size;
    clu_alloc((size.num - 1)* (sizeof(CLUREF)) + sizeof(CLU_sequence), &r2);
    r2.vec->typ.mark = 0;
    r2.vec->typ.val = CT_REC;
    r2.vec->typ.refp = 0;
    r2.vec->typ.spare = 0;
    r2.vec->size = r.vec->size;

    for (i = 0; i < r.vec->size; ++i)
	r2.vec->data[i] = r.vec->data[i];

    ans->vec = r2.vec;
    signal(ERR_ok);
}


errcode
recordOPsimilar(CLUREF r1, CLUREF r2, CLUREF *ans)
{
    CLUPROC *field_similar = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;
    long i;
    errcode err;
    CLUREF e1, e2;

    if (r1.vec->size != r2.vec->size) {
	ans->tf = false;
	signal(ERR_ok);
    }

    for (i = 0; i < r1.vec->size; ++i) {
	e1.num = r1.vec->data[i];
	e2.num = r2.vec->data[i];

	CUR_PROC_VAR.proc = field_similar[i];
	err = (*field_similar[i]->proc)(e1, e2, ans);
	if (err != ERR_ok)
	    resignal(err);
	if (ans->tf == false)
	    signal(ERR_ok);
    }
    signal(ERR_ok);
}


errcode
recordOP_gcd(CLUREF r, CLUREF tab, CLUREF *ans)
{
    CLUPROC *field_gcd = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;
    long i;
    errcode err;
    CLUREF temp_oneof, temp_seq, sz;

    sz.num = r.vec->size;
    sequenceOPnew2(sz, &temp_seq);
    for (i = 0; i < r.vec->size; i++) {
	temp_seq.vec->data[i] = (long)field_gcd[i];
    }

    err = oneofOPnew(CLU_3, temp_seq, &temp_oneof);
    if (err != ERR_ok)
	resignal(err);

    sz.num = 2 * CLUREFSZ + r.vec->size * GCD_REF_SIZE;
    err = gcd_tabOPinsert(tab, sz, temp_oneof, r, ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
recordOPequal(CLUREF r1, CLUREF r2, CLUREF *ans)
{
    if (r1.ref == r2.ref)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
recordOPr_gets_r(CLUREF r1, CLUREF r2)
{
    bcopy((char *)r2.vec->data, (char *)r1.vec->data, r1.vec->size * CLUREFSZ);
    signal(ERR_ok);
}


errcode
recordOPr_gets_s(CLUREF r1, CLUREF r2)
{
    bcopy((char *)r2.vec->data, (char *)r1.vec->data, r1.vec->size * CLUREFSZ);
    signal(ERR_ok);
}


errcode
recordOPdebug_print(CLUREF r, CLUREF pst)
{
    errcode err;

    /*
     * NB: Abuse^W rely on the fact that print and debug_print have
     * similar op_owns, so call print but with debug_print field ops.
     * Should probably just do a tail call.
     */
    err = recordOPprint(r, pst);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
recordOPprint(CLUREF r, CLUREF pst)
{
    CLUPROC *field_print = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;
    char **field_name = (char **)(field_print + r.vec->size);
    long i;
    errcode err;
    CLUREF temp_str, temp_str2, temp_str3, e1;
    CLUREF size, ans;

    err = stringOPcons("{", CLU_1, CLU_1, &temp_str);
    if (err != ERR_ok) resignal(err);

    err = pstreamOPstart(pst, temp_str, &ans);
    if (err != ERR_ok)
	resignal(err);
    if (ans.tf == false)
	goto done;

    err = stringOPcons(",", CLU_1, CLU_1, &temp_str);
    if (err != ERR_ok) resignal(err);
    err = stringOPcons(": ", CLU_1, CLU_2, &temp_str2);
    if (err != ERR_ok) resignal(err);

    for (i = 0; i < r.vec->size; ++i) {
	if (i != 0) {
	    err = pstreamOPpause(pst, temp_str, &ans);
	    if (err != ERR_ok)
		resignal(err);
	    if (ans.tf == false)
		break;
	}

	size.num = strlen(field_name[i]);
	stringOPcons(field_name[i], CLU_1, size, &temp_str3);

	err = pstreamOPtext(pst, temp_str3, &ans);
	if (err != ERR_ok)
	    resignal(err);

	err = pstreamOPtext(pst, temp_str2, &ans);
	if (err != ERR_ok)
	    resignal(err);

	e1.num = r.vec->data[i];
	CUR_PROC_VAR.proc = field_print[i];
	err = (*field_print[i]->proc)(e1, pst);
	if (err != ERR_ok)
	    resignal(err);
    }
  done:
    err = stringOPcons("}", CLU_1, CLU_1, &temp_str);
    if (err != ERR_ok)
	resignal(err);

    err = pstreamOPstop(pst, temp_str, &ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
recordOPencode(CLUREF r, CLUREF ist)
{
    CLUPROC *field_encode = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;
    long i;
    errcode err;
    CLUREF e1;

    err = istreamOPputi(ist, CLUREF_make_num(r.vec->size));
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    for (i = 0; i < r.vec->size; ++i) {
	e1.num = r.vec->data[i];

	CUR_PROC_VAR.proc = field_encode[i];
	err = (*field_encode[i]->proc)(e1, ist);
	if (err == ERR_not_possible)
	    signal(err);
	if (err != ERR_ok)
	    resignal(err);
    }
    signal(ERR_ok);
}


errcode
recordOPdecode(CLUREF ist, CLUREF *ans)
{
    CLUPROC *field_decode = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;
    long i;
    errcode err;
    CLUREF temp, size;

    err = istreamOPgeti(ist, &size);
    if (err == ERR_not_possible)
	signal(err);
    if (err == ERR_end_of_file)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    err = recordOPnew(size, &temp);
    if (err != ERR_ok)
	resignal(err);

    for (i = 0; i < temp.vec->size; ++i) {
	CUR_PROC_VAR.proc = field_decode[i];
	err = (*field_decode[i]->proc)(ist, &temp.vec->data[i]);
	if (err == ERR_not_possible)
	    signal(err);
	if (err == ERR_end_of_file)
	    signal(err);
	if (err != ERR_ok)
	    resignal(err);
    }

    ans->vec = temp.vec;
    signal(ERR_ok);
}


errcode recordOPsimilar1(rec1, rec2, ans)
CLUREF rec1, rec2, *ans;
{
    CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; 
    long i;
    errcode err;
    CLUREF e1, e2;

    if (rec1.vec->size != rec2.vec->size) {
	ans->tf = false;
	signal(ERR_ok);
    }

    for (i = 0; i < rec1.vec->size; i++) {
	e1.num = rec1.vec->data[i];
	e2.num = rec2.vec->data[i];

	CUR_PROC_VAR.proc = (CLUPROC)table[i];
	err = table[i]->proc(e1, e2, ans);
	if (err != ERR_ok)
	    resignal(err);
	if (ans->tf == false)
	    signal(ERR_ok);
    }
    signal(ERR_ok);
}



OWN_ptr record_own_init = { .init_flag = 0 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &record_own_init,		\
    .op_owns = &record_own_init,		\
}

static CLU_proc record_oe_equal = CLU_proc_INIT(recordOPequal);
static CLU_proc record_oe_copy = CLU_proc_INIT(recordOPcopy);
static CLU_proc record_oe_similar = CLU_proc_INIT(recordOPsimilar);
static CLU_proc record_oe_print = CLU_proc_INIT(recordOPprint);
static CLU_proc record_oe_encode = CLU_proc_INIT(recordOPencode);
static CLU_proc record_oe_decode = CLU_proc_INIT(recordOPdecode);
static CLU_proc record_oe__gcd = CLU_proc_INIT(recordOP_gcd);
static CLU_proc record_oe_debug_print = CLU_proc_INIT(recordOPdebug_print);

static struct /* OPS */ {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[8];
} record_ops_actual = {
    8,
    &record_own_init,
    &record_own_init,
    {
	{ &record_oe_equal, "equal" },
	{ &record_oe_copy, "copy" },
	{ &record_oe_similar, "similar" },
	{ &record_oe_print, "print" },
	{ &record_oe_encode, "encode" },
	{ &record_oe_decode, "decode" },
	{ &record_oe__gcd, "_gcd" },
	{ &record_oe_debug_print, "debug_print" },
    }
};

struct OPS *record_ops = (struct OPS *)&record_ops_actual;
