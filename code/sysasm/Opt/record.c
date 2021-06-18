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


static void
recordOPOPalloc(size_t size, CLUREF *pnew)
{
    size_t bufsz = offsetof(CLU_sequence, data) + size * CLUREFSZ;

    clu_alloc(bufsz, pnew);
    CLUTYPE_set(pnew->vec->typ, CT_REC);
    pnew->vec->size = size;
}


errcode
recordOPnew(CLUREF size, CLUREF *ans)
{
    CLUREF r;
    recordOPOPalloc(size.num, &r);

    *ans = r;
    signal(ERR_ok);
}


errcode recordOPcopy(CLUREF r, CLUREF *ans)
{
    errcode err;
    CLUPROC *field_copy = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;

    CLUREF r2;
    recordOPOPalloc(r.vec->size, &r2);

    for (long i = 0; i < r.vec->size; ++i) {
	CLUREF elt = { .num = r.vec->data[i] };

	CUR_PROC_VAR.proc = field_copy[i];
	err = (*field_copy[i]->proc)(elt, &r2.vec->data[i]);
	if (err != ERR_ok)
	    goto ex_0;
    }

    *ans = r2;
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}


errcode
recordOPcopy1(CLUREF r, CLUREF *ans)
{
    CLUREF r2;
    recordOPOPalloc(r.vec->size, &r2);

    for (long i = 0; i < r.vec->size; ++i)
	r2.vec->data[i] = r.vec->data[i];

    *ans = r2;
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
	    goto ex_0;

	if (ans->tf == false)
	    break;
    }
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}


errcode
recordOP_gcd(CLUREF r, CLUREF tab, CLUREF *ans)
{
    errcode err;
    CLUPROC *field_gcd = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;


    CLUREF gproclist;
    sequenceOPnew2(CLUREF_make_num(r.vec->size), &gproclist);
    for (long i = 0; i < r.vec->size; ++i) {
	gproclist.vec->data[i] = (long)field_gcd[i];
    }

    CLUREF ginfo;		// := ginfo$make_c_sel(gproclist)
    err = oneofOPnew(CLU_3, gproclist, &ginfo);
    if (err != ERR_ok)
	goto ex_0;

    CLUREF sz = { .num = 2 * CLUREFSZ + r.vec->size * GCD_REF_SIZE };
    err = gcd_tabOPinsert(tab, sz, ginfo, r, ans);
    if (err != ERR_ok)
	goto ex_0;

    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
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
    memcpy(r1.vec->data, r2.vec->data, r1.vec->size * CLUREFSZ);
    signal(ERR_ok);
}


errcode
recordOPr_gets_s(CLUREF r1, CLUREF r2)
{
    memcpy(r1.vec->data, r2.vec->data, r1.vec->size * CLUREFSZ);
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
	goto ex_0;

    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}


errcode
recordOPprint(CLUREF r, CLUREF pst)
{
    errcode err;
    CLUREF ans;

    CLUPROC *field_print = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;
    char **field_name = (char **)(field_print + r.vec->size);

    static CLUREF lcurly, colon, comma, rcurly;
    static bool init = false;
    if (!init) {
	stringOPcons("{",  CLU_1, CLU_1, &lcurly);
	stringOPcons(": ", CLU_1, CLU_2, &colon);
	stringOPcons(",",  CLU_1, CLU_1, &comma);
	stringOPcons("}",  CLU_1, CLU_1, &rcurly);
	init = true;
    }

    err = pstreamOPstart(pst, lcurly, &ans);
    if (err != ERR_ok)
	goto ex_0;

    if (ans.tf == false)
	goto done;

    for (long i = 0; i < r.vec->size; ++i) {
	if (i != 0) {
	    err = pstreamOPpause(pst, comma, &ans);
	    if (err != ERR_ok)
		goto ex_0;

	    if (ans.tf == false)
		break;
	}

	CLUREF name;
	CLUREF size = { .num = strlen(field_name[i]) };
	stringOPcons(field_name[i], CLU_1, size, &name);
	err = pstreamOPtext(pst, name, &ans);
	if (err != ERR_ok)
	    goto ex_0;

	err = pstreamOPtext(pst, colon, &ans);
	if (err != ERR_ok)
	    goto ex_0;

	CLUREF value = { .num = r.vec->data[i] };
	CUR_PROC_VAR.proc = field_print[i];
	err = (*field_print[i]->proc)(value, pst);
	if (err != ERR_ok)
	    goto ex_0;
    }

  done:
    err = pstreamOPstop(pst, rcurly, &ans);
    if (err != ERR_ok)
	goto ex_0;

    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
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
	goto ex_0;

    for (i = 0; i < r.vec->size; ++i) {
	e1.num = r.vec->data[i];

	CUR_PROC_VAR.proc = field_encode[i];
	err = (*field_encode[i]->proc)(e1, ist);
	if (err == ERR_not_possible)
	    signal(err);
	if (err != ERR_ok)
	    goto ex_0;
    }
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}


errcode
recordOPdecode(CLUREF ist, CLUREF *ans)
{
    errcode err;
    CLUPROC *field_decode = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;

    CLUREF size;
    err = istreamOPgeti(ist, &size);
    if (err == ERR_not_possible)
	signal(err);
    if (err == ERR_end_of_file)
	signal(err);
    if (err != ERR_ok)
	goto ex_0;

    CLUREF r;
    err = recordOPnew(size, &r);
    if (err != ERR_ok)
	goto ex_0;

    for (long i = 0; i < r.vec->size; ++i) {
	CUR_PROC_VAR.proc = field_decode[i];
	err = (*field_decode[i]->proc)(ist, &r.vec->data[i]);
	if (err == ERR_not_possible)
	    signal(err);
	if (err == ERR_end_of_file)
	    signal(err);
	if (err != ERR_ok)
	    goto ex_0;
    }

    *ans = r;
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}


errcode
recordOPsimilar1(CLUREF r1, CLUREF r2, CLUREF *ans)
{
    errcode err;
    CLUPROC *field_similar1 = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;

    if (r1.vec->size != r2.vec->size) {
	ans->tf = false;
	signal(ERR_ok);
    }

    for (long i = 0; i < r1.vec->size; ++i) {
	CLUREF e1 = { .num = r1.vec->data[i] };
	CLUREF e2 = { .num = r2.vec->data[i] };

	CUR_PROC_VAR.proc = field_similar1[i];
	err = (*field_similar1[i]->proc)(e1, e2, ans);
	if (err != ERR_ok)
	    goto ex_0;

	if (ans->tf == false)
	    break;
    }
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
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
