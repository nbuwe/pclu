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
    errcode err;
    CLUREF temp, tag, value;
    CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to copy fcns */

    tag.num = one.cell->tag;
    value.num = one.cell->value;
    err = oneofOPnew(tag, value, &temp);
    if (err != ERR_ok) resignal(err);
    CUR_PROC_VAR.proc = (CLUPROC)table[one.cell->tag - 1];
    err = table[one.cell->tag - 1]->proc(value, &temp.cell->value);
    if (err != ERR_ok) resignal(err);
    ans->cell = temp.cell;
    signal(ERR_ok);
}


errcode
oneofOPo2v(CLUREF one, CLUREF *ans)
{
    errcode err;
    CLUREF temp;

    err = variantOPnew(CLUREF_make_num(one.cell->tag),
		       CLUREF_make_num(one.cell->value),
		       &temp);
    if (err != ERR_ok) resignal(err);
    ans->cell = temp.cell;
    signal(ERR_ok);
}


errcode
oneofOPv2o(CLUREF vnt, CLUREF *ans)
{
    errcode err;
    CLUREF temp;

    err = oneofOPnew(CLUREF_make_num(vnt.cell->tag),
		     CLUREF_make_num(vnt.cell->value),
		     &temp);
    if (err != ERR_ok) resignal(err);
    ans->cell = temp.cell;
    signal(ERR_ok);
}


errcode
oneofOPsimilar(CLUREF one1, CLUREF one2, CLUREF *ans)
{
    CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to similar fcns */
    errcode err;
    CLUREF value1, value2;

    if (one1.cell->tag != one2.cell->tag) {
	ans->tf = false;
	signal(ERR_ok);
    }
    value1.num = one1.cell->value;
    value2.num = one2.cell->value;
    CUR_PROC_VAR.proc = (CLUPROC)table[one1.cell->tag - 1];
    err = table[one1.cell->tag - 1]->proc(value1, value2, ans);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
oneofOP_gcd(CLUREF one, CLUREF tab, CLUREF *ans)
{
    CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to _gcd fcns */
    errcode err;
    CLUREF temp_oneof, temp_seq, sz, tag;

    tag.num = one.cell->tag;
    sequenceOPnew2(tag, &temp_seq);
    for (long i = 0; i < one.cell->tag; ++i) {
	temp_seq.vec->data[i] = (long)table[i];
    }
    err = oneofOPnew(CLU_4, temp_seq, &temp_oneof);
    if (err != ERR_ok) resignal(err);
    sz.num = 2*CLUREFSZ + GCD_REF_SIZE;
    err = gcd_tabOPinsert(tab, sz, temp_oneof, one, ans);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
oneofOPencode(CLUREF one, CLUREF ist)
{
    errcode err;
    CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to encode fcns */
    CLUREF temp;

    temp.num = one.cell->tag;
    err = istreamOPputi(ist, temp);
    if (err != ERR_ok) resignal(ERR_ok);
    temp.num = one.cell->value;
    CUR_PROC_VAR.proc = (CLUPROC)table[one.cell->tag - 1];
    err = table[one.cell->tag - 1]->proc(temp, ist);
    if (err == ERR_not_possible) signal(err);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
oneofOPdecode(CLUREF ist, CLUREF *ans)
{
    errcode err;
    CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to decode fcns */
    CLUREF tag, val, temp;

    err = istreamOPgeti(ist, &tag);
    if (err != ERR_ok) resignal(ERR_ok);

    /* error checking on tag value */
    CUR_PROC_VAR.proc = (CLUPROC)table[tag.num - 1];
    err = table[tag.num - 1]->proc(ist, &val);
    if (err == ERR_not_possible) signal(err);
    if (err == ERR_end_of_file) signal(err);
    if (err != ERR_ok) resignal(err);

    err = oneofOPnew(tag, val, &temp);
    if (err != ERR_ok) resignal(err);
    ans->cell = temp.cell;
    signal(ERR_ok);
}


errcode
oneofOPequal(CLUREF one1, CLUREF one2, CLUREF *ans)
{
    CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to equal fcns */
    errcode err;
    CLUREF value1, value2;

    if (one1.cell->tag != one2.cell->tag) {
	ans->tf = false;
	signal(ERR_ok);
    }
    value1.num = one1.cell->value;
    value2.num = one2.cell->value;
    CUR_PROC_VAR.proc = (CLUPROC)table[one1.cell->tag - 1];
    err = table[one1.cell->tag - 1]->proc(value1, value2, ans);
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
