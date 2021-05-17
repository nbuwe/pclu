/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*							*/
/*		ONEOF IMPLEMENTATION			*/
/*							*/

#include "pclu_err.h"
#include "pclu_sys.h"

errcode gcd_tabOPinsert(CLUREF tab, CLUREF z, CLUREF inf, CLUREF x, CLUREF *ret_1);
errcode istreamOPgeti(CLUREF ist, CLUREF *ret_1);
errcode istreamOPputi(CLUREF ist, CLUREF i);
errcode pstreamOPstart(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPstop(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPtext(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode variantOPnew(CLUREF tag, CLUREF val, CLUREF *ans);

errcode oneofOPprint(CLUREF one, CLUREF pst);
const char * const *find_names(const OWN_ptr *owns); /* used by variant.c */


errcode
oneofOPnew(CLUREF tag, CLUREF val, CLUREF *ans)
{
    CLUREF temp;

    clu_alloc(sizeof(CLU_cell), &temp);
    temp.cell->typ.mark = 0;
    temp.cell->typ.val = CT_VAR;
    temp.cell->typ.refp = 0;
    temp.cell->typ.spare = 0;
    temp.cell->tag = tag.num;
    temp.cell->value = val.num;

    ans->cell = temp.cell;
    signal(ERR_ok);
}


errcode
oneofOPcopy(CLUREF one, CLUREF *ans)
{
    CLUREF temp;
    errcode err;

    CLUREF tag = { .num = one.cell->tag };
    err = oneofOPnew(tag, CLU_0, &temp);
    if (err != ERR_ok) resignal(err);

    /* call tag's copy function to do the work */
    const OWN_ptr *owns = CUR_PROC_VAR.proc->op_owns;
    const CLUPROC *copy = (CLUPROC *)owns->info;

    CLUREF value = { .num = one.cell->value };
    CUR_PROC_VAR.proc = copy[one.cell->tag - 1];
    err = (*CUR_PROC_VAR.proc->proc)(value, &temp.cell->value);
    if (err != ERR_ok) resignal(err);

    ans->cell = temp.cell;
    signal(ERR_ok);
}


errcode
oneofOPo2v(CLUREF one, CLUREF *ans)
{
    CLUREF temp;
    errcode err;

    CLUREF tag = { .num = one.cell->tag };
    CLUREF value = { .num = one.cell->value };
    err = variantOPnew(tag, value, &temp);
    if (err != ERR_ok) resignal(err);

    ans->cell = temp.cell;
    signal(ERR_ok);
}


errcode
oneofOPv2o(CLUREF variant, CLUREF *ans)
{
    CLUREF temp;
    errcode err;

    CLUREF tag = { .num = variant.cell->tag };
    CLUREF value = { .num = variant.cell->value };
    err = oneofOPnew(tag, value, &temp);
    if (err != ERR_ok) resignal(err);

    ans->cell = temp.cell;
    signal(ERR_ok);
}


errcode
oneofOPsimilar(CLUREF one1, CLUREF one2, CLUREF *ans)
{
    errcode err;

    if (one1.cell->tag != one2.cell->tag) {
	ans->tf = false;
	signal(ERR_ok);
    }

    /* call tag's similar function to do the work */
    const OWN_ptr *owns = CUR_PROC_VAR.proc->op_owns;
    const CLUPROC *similar = (CLUPROC *)owns->info;

    CLUREF value1 = { .num = one1.cell->value };
    CLUREF value2 = { .num = one2.cell->value };
    CUR_PROC_VAR.proc = similar[one1.cell->tag - 1];
    err = (*CUR_PROC_VAR.proc->proc)(value1, value2, ans);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
oneofOP_gcd(CLUREF one, CLUREF tab, CLUREF *ans)
{
    errcode err;

    const OWN_ptr *owns = CUR_PROC_VAR.proc->op_owns;
    const CLUPROC *_gcd = (CLUPROC *)owns->info;

    CLUREF gproclist;
    CLUREF len = { .num = one.cell->tag };
    sequenceOPnew2(len, &gproclist);
    for (long i = 0; i < one.cell->tag; ++i) {
	gproclist.vec->data[i] = (long)_gcd[i];
    }

    CLUREF ginfo;
    CLUREF d_cell_tag = CLU_4;
    err = oneofOPnew(d_cell_tag, gproclist, &ginfo);
    if (err != ERR_ok) resignal(err);

    CLUREF size = { .num = 2 * CLUREFSZ + GCD_REF_SIZE };
    err = gcd_tabOPinsert(tab, size, ginfo, one, ans);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
oneofOPencode(CLUREF one, CLUREF ist)
{
    errcode err;

    /* encode the tag */
    CLUREF tag = { .num = one.cell->tag };
    err = istreamOPputi(ist, tag);
    if (err != ERR_ok) resignal(ERR_ok);

    /* call tag's encode function to encode the value */
    const OWN_ptr *owns = CUR_PROC_VAR.proc->op_owns;
    const CLUPROC *encode = (CLUPROC *)owns->info;

    CLUREF value = { .num = one.cell->value };
    CUR_PROC_VAR.proc = encode[one.cell->tag - 1];
    err = (*CUR_PROC_VAR.proc->proc)(value, ist);
    if (err == ERR_not_possible) signal(err);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
oneofOPdecode(CLUREF ist, CLUREF *ans)
{
    CLUREF temp;
    errcode err;

    /* decode the tag */
    CLUREF tag;
    err = istreamOPgeti(ist, &tag);
    if (err != ERR_ok) resignal(ERR_ok);

    /* call tag's decode function to decode the value */
    const OWN_ptr *owns = CUR_PROC_VAR.proc->op_owns;
    const CLUPROC *decode = (CLUPROC *)owns->info;

    CLUREF value;
    CUR_PROC_VAR.proc = decode[tag.num - 1];
    err = (*CUR_PROC_VAR.proc->proc)(ist, &value);
    if (err == ERR_not_possible) signal(err);
    if (err == ERR_end_of_file) signal(err);
    if (err != ERR_ok) resignal(err);

    err = oneofOPnew(tag, value, &temp);
    if (err != ERR_ok) resignal(err);

    ans->cell = temp.cell;
    signal(ERR_ok);
}


errcode
oneofOPequal(CLUREF one1, CLUREF one2, CLUREF *ans)
{
    errcode err;

    if (one1.cell->tag != one2.cell->tag) {
	ans->tf = false;
	signal(ERR_ok);
    }

    /* call tag's equal function to do the work */
    const OWN_ptr *owns = CUR_PROC_VAR.proc->op_owns;
    const CLUPROC *equal = (CLUPROC *)owns->info;

    CLUREF value1 = { .num = one1.cell->value };
    CLUREF value2 = { .num = one2.cell->value };
    CUR_PROC_VAR.proc = equal[one1.cell->tag - 1];
    err = (*CUR_PROC_VAR.proc->proc)(value1, value2, ans);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
oneofOPdebug_print(CLUREF one, CLUREF pst)
{
    errcode err;
    err = oneofOPprint(one, pst);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
oneofOPprint(CLUREF one, CLUREF pst)
{
    OWN_ptr *owns = CUR_PROC_VAR.proc->op_owns;
    CLUPROC *table = (CLUPROC *)owns->info; /* ptr to print fcns */
    errcode err;
    CLUREF temp_str, temp_st2, tag, value, ans;

    err = stringOPcons("<", CLU_1, CLU_1, &temp_str);
    if (err != ERR_ok) resignal(err);

    err = pstreamOPstart(pst, temp_str, &ans);
    if (err != ERR_ok) resignal(err);
    if (ans.tf == false) {
	err = pstreamOPstop(pst, temp_str, &ans);
	if (err != ERR_ok) resignal(err);
	signal(ERR_ok);
    }

    /* find the tag's name in owns */
    const char * const *names = find_names(owns);
    const char *name = names[one.cell->tag - 1];
    size_t size = strlen(name);
    stringOPcons(name, CLU_1, CLUREF_make_num(size), &temp_str);

    err = pstreamOPtext(pst, temp_str, &ans);
    if (err != ERR_ok) resignal(err);

    err = stringOPcons(": ", CLU_1, CLU_2, &temp_str);
    if (err != ERR_ok) resignal(err);

    err = pstreamOPtext(pst, temp_str, &ans);
    if (err != ERR_ok) resignal(err);

    /* call the tag's print function */
    value.num = one.cell->value;
    CUR_PROC_VAR.proc = (CLUPROC)table[one.cell->tag - 1];
    err = table[one.cell->tag - 1]->proc(value, pst);
    if (err != ERR_ok) resignal(err);

    err = stringOPcons(">", CLU_1, CLU_1, &temp_str);
    if (err != ERR_ok) resignal(err);

    err = pstreamOPstop(pst, temp_str, &ans);
    if (err != ERR_ok) resignal(err);

    signal(ERR_ok);
}


/*
 * Find the field names saved in the owns for print and debug_print by
 * find_selector_ops() after the function table.
 */
const char * const *
find_names(const OWN_ptr *owns)
{
    for (size_t i = 0; i < 41; ++i) {
	CLUPROC p = (CLUPROC)owns->info[i];
	if (p == NULL)
	    continue;
	if (*(long *)p == 0)
	    continue;
	if ((p->typ.mark == 0)
	    && (p->typ.val == CT_PROC)
	    && (p->typ.refp == 0)
	    && (p->typ.spare == 0))
	    continue;

	return (const char **)&owns->info[i];
    }
    return NULL;
}



OWN_ptr oneof_own_init = { .init_flag = 0 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &oneof_own_init,		\
    .op_owns = &oneof_own_init,		\
}

CLU_proc oneof_oe_equal = CLU_proc_INIT(oneofOPequal);
CLU_proc oneof_oe_similar = CLU_proc_INIT(oneofOPsimilar);
CLU_proc oneof_oe_copy = CLU_proc_INIT(oneofOPcopy);
CLU_proc oneof_oe_print = CLU_proc_INIT(oneofOPprint);
CLU_proc oneof_oe_encode = CLU_proc_INIT(oneofOPencode);
CLU_proc oneof_oe_decode = CLU_proc_INIT(oneofOPdecode);
CLU_proc oneof_oe__gcd = CLU_proc_INIT(oneofOP_gcd);
CLU_proc oneof_oe_debug_print = CLU_proc_INIT(oneofOPdebug_print);


/* extends struct OPS */
typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[8];
} selector_OPS;

selector_OPS oneof_ops_actual = {
    8,
    &oneof_own_init,
    &oneof_own_init,
    {
	{ &oneof_oe_equal, "equal"},
	{ &oneof_oe_similar, "similar"},
	{ &oneof_oe_copy, "copy"},
	{ &oneof_oe_print, "print"},
	{ &oneof_oe_encode, "encode"},
	{ &oneof_oe_decode, "decode"},
	{ &oneof_oe__gcd, "_gcd"},
	{ &oneof_oe_print, "debug_print"}
    }
};

OPSPTR oneof_ops = (OPSPTR)&oneof_ops_actual;
