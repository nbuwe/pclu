/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*							*/
/*		STRUCT IMPLEMENTATION			*/
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

errcode structOPprint(CLUREF s, CLUREF pst);


static void
structOPOPalloc(size_t size, CLUREF *pnew)
{
    size_t bufsz = offsetof(CLU_sequence, data) + size * CLUREFSZ;

    clu_alloc(bufsz, pnew);
    CLUTYPE_set(pnew->vec->typ, CT_REC);
    pnew->vec->size = size;
}



errcode
structOPnew(CLUREF size, CLUREF *ans)
{
    CLUREF s;
    structOPOPalloc(size.num, &s);

    *ans = s;
    signal(ERR_ok);
}


/*
 * Shallow copy.  Internal helper for structOPreplace_N().
 */
errcode
structOPblit(CLUREF s, CLUREF *ans)
{
    CLUREF s2;
    structOPOPalloc(s.vec->size, &s2);
    memcpy(s2.vec->data, s.vec->data, s.vec->size * CLUREFSZ);

    *ans = s2;
    signal(ERR_ok);
}


errcode
structOPcopy(CLUREF s, CLUREF *ans)
{
    errcode err;
    CLUPROC *field_copy = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;

    CLUREF s2;
    structOPOPalloc(s.vec->size, &s2);

    for (long i = 0; i < s.vec->size; ++i) {
	CLUREF elt = { .num = s.vec->data[i] };

	CUR_PROC_VAR.proc = field_copy[i];
	err = (*field_copy[i]->proc)(elt, &s2.vec->data[i]);
	if (err != ERR_ok)
	    goto ex_0;
    }

    *ans = s2;
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }

}


errcode
structOPsimilar(CLUREF s1, CLUREF s2, CLUREF *ans)
{
    errcode err;
    CLUPROC *field_similar = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;

    if (s1.vec->size != s2.vec->size) {
	ans->tf = false;
	signal(ERR_ok);
    }

    for (long i = 0; i < s1.vec->size; ++i) {
	CLUREF elt1 = { .num = s1.vec->data[i] };
	CLUREF elt2 = { .num = s2.vec->data[i] };

	CUR_PROC_VAR.proc = field_similar[i];
	err = (*field_similar[i]->proc)(elt1, elt2, ans);
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
structOPequal(CLUREF s1, CLUREF s2, CLUREF *ans)
{
    errcode err;
    CLUPROC *field_equal = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;

    if (s1.vec->size != s2.vec->size) {
	ans->tf = false;
	signal(ERR_ok);
    }

    for (long i = 0; i < s1.vec->size; ++i) {
	CLUREF elt1 = { .num = s1.vec->data[i] };
	CLUREF elt2 = { .num = s2.vec->data[i] };

	CUR_PROC_VAR.proc = field_equal[i];
	err = (*field_equal[i]->proc)(elt1, elt2, ans);
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
structOP_gcd(CLUREF s, CLUREF tab, CLUREF *ans)
{
    errcode err;
    CLUPROC *field_gcd = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;

    CLUREF gproclist;
    sequenceOPnew2(CLUREF_make_num(s.vec->size), &gproclist);
    for (long i = 0; i < s.vec->size; ++i) {
	gproclist.vec->data[i] = (long)field_gcd[i];
    }

    CLUREF ginfo;		// := ginfo$make_c_sel(gproclist)
    err = oneofOPnew(CLU_3, gproclist, &ginfo);
    if (err != ERR_ok)
	goto ex_0;

    CLUREF sz = { .num = 2 * CLUREFSZ + s.vec->size * GCD_REF_SIZE };
    err = gcd_tabOPinsert(tab, sz, ginfo, s, ans);
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
structOPs2r(CLUREF s, CLUREF *ans)
{
    errcode err;

    CLUREF r;
    err = recordOPnew(CLUREF_make_num(s.vec->size), &r);
    if (err != ERR_ok)
	goto ex_0;

    memcpy(r.vec->data, s.vec->data, s.vec->size * CLUREFSZ);

    *ans = r;
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}


/*
 * Just forward to structOPblit?
 */
errcode
structOPr2s(CLUREF r, CLUREF *ans)
{
    CLUREF s;
    structOPOPalloc(r.vec->size, &s);
    memcpy(s.vec->data, r.vec->data, r.vec->size * CLUREFSZ);

    *ans = s;
    signal(ERR_ok);
}


errcode
structOPdebug_print(CLUREF s, CLUREF pst)
{
    errcode err;

    /*
     * NB: Abuse^W rely on the fact that print and debug_print have
     * similar op_owns, so call print but with debug_print field ops.
     * Should probably just do a tail call.
     */
    err = structOPprint(s, pst);
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
structOPprint(CLUREF s, CLUREF pst)
{
    errcode err;
    CLUREF ans;

    CLUPROC *field_print
	= (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;
    char **field_name
	= (char **)(field_print + s.vec->size);

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

    for (long i = 0; i < s.vec->size; ++i) {
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

	CLUREF value = { .num = s.vec->data[i] };
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
structOPencode(CLUREF s, CLUREF ist)
{
    errcode err;
    CLUPROC *field_encode = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;

    err = istreamOPputi(ist, CLUREF_make_num(s.vec->size));
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	goto ex_0;

    for (long i = 0; i < s.vec->size; ++i) {
	CLUREF field = { .num = s.vec->data[i] };

	CUR_PROC_VAR.proc = field_encode[i];
	err = (*field_encode[i]->proc)(field, ist);
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
structOPdecode(CLUREF ist, CLUREF *ans)
{
    errcode err;
    CLUPROC *field_decode = (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;

    CLUREF size;
    err = istreamOPgeti(ist, &size);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	goto ex_0;

    CLUREF s;
    err = structOPnew(size, &s);
    if (err != ERR_ok)
	goto ex_0;

    for (long i = 0; i < s.vec->size; ++i) {
	CUR_PROC_VAR.proc = field_decode[i];
	err = (*field_decode[i]->proc)(ist, &s.vec->data[i]);
	if (err == ERR_not_possible)
	    signal(err);
	if (err == ERR_end_of_file)
	    signal(err);
	if (err != ERR_ok)
	    goto ex_0;
    }

    *ans = s;
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}



OWN_ptr struct_own_init = { .init_flag = 0 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &struct_own_init,		\
    .op_owns = &struct_own_init,		\
}

static CLU_proc struct_oe_equal = CLU_proc_INIT(structOPequal);
static CLU_proc struct_oe_copy = CLU_proc_INIT(structOPcopy);
static CLU_proc struct_oe_similar = CLU_proc_INIT(structOPsimilar);
static CLU_proc struct_oe_print = CLU_proc_INIT(structOPprint);
static CLU_proc struct_oe_encode = CLU_proc_INIT(structOPencode);
static CLU_proc struct_oe_decode = CLU_proc_INIT(structOPdecode);
static CLU_proc struct_oe__gcd = CLU_proc_INIT(structOP_gcd);
static CLU_proc struct_oe_debug_print = CLU_proc_INIT(structOPdebug_print);


static struct /* OPS */ {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[8];
} struct_ops_actual = {
    8,
    &struct_own_init,
    &struct_own_init,
    {
	{ &struct_oe_equal, "equal" },
	{ &struct_oe_copy, "copy" },
	{ &struct_oe_similar, "similar" },
	{ &struct_oe_print, "print" },
	{ &struct_oe_encode, "encode" },
	{ &struct_oe_decode, "decode" },
	{ &struct_oe__gcd, "_gcd" },
	{ &struct_oe_debug_print, "debug_print" },
    }
};

struct OPS *struct_ops = (struct OPS *)&struct_ops_actual;
