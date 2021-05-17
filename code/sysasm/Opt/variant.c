/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*							*/
/*		VARIANT IMPLEMENTATION			*/
/*							*/

#include "pclu_err.h"
#include "pclu_sys.h"

errcode gcd_tabOPinsert(CLUREF tab, CLUREF z, CLUREF inf, CLUREF x, CLUREF *ret_1);
errcode istreamOPgeti(CLUREF ist, CLUREF *ret_1);
errcode istreamOPputi(CLUREF ist, CLUREF i);
errcode pstreamOPstart(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPstop(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPtext(CLUREF ps, CLUREF s, CLUREF *ret_1);

const char * const *find_names(const OWN_ptr *owns); /* in oneof.c */
extern errcode variantOPprint();


errcode
variantOPnew(CLUREF tag, CLUREF val, CLUREF *ans)
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
variantOPcopy(CLUREF vnt, CLUREF *ans)
{
    CLUREF temp;
    errcode err;

    CLUREF tag = { .num = vnt.cell->tag };
    err = variantOPnew(tag, CLU_0, &temp);
    if (err != ERR_ok) resignal(err); 

    /* call tag's copy function to do the work */
    const OWN_ptr *owns = CUR_PROC_VAR.proc->op_owns;
    const CLUPROC *copy = (CLUPROC *)owns->info;

    CLUREF value = { .num = vnt.cell->value };
    CUR_PROC_VAR.proc = copy[vnt.cell->tag - 1];
    err = (*CUR_PROC_VAR.proc->proc)(value, &temp.cell->value);
    if (err != ERR_ok) resignal(err);

    ans->cell = temp.cell;
    signal(ERR_ok);
}


errcode
variantOPsimilar(CLUREF vnt1, CLUREF vnt2, CLUREF *ans)
{
    errcode err;

    if (vnt1.cell->tag != vnt2.cell->tag) {
	ans->tf = false;
	signal(ERR_ok);
    }

    /* call tag's similar function to do the work */
    const OWN_ptr *owns = CUR_PROC_VAR.proc->op_owns;
    const CLUPROC *similar = (CLUPROC *)owns->info;

    CLUREF value1 = { .num = vnt1.cell->value };
    CLUREF value2 = { .num = vnt2.cell->value };
    CUR_PROC_VAR.proc = similar[vnt1.cell->tag - 1];
    err = (*CUR_PROC_VAR.proc->proc)(value1, value2, ans);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
variantOP_gcd(CLUREF vnt, CLUREF tab, CLUREF *ans)
{
    errcode err;

    const OWN_ptr *owns = CUR_PROC_VAR.proc->op_owns;
    const CLUPROC *_gcd = (CLUPROC *)owns->info;

    CLUREF gproclist;
    CLUREF len = { .num = vnt.cell->tag };
    sequenceOPnew2(len, &gproclist);
    for (long i = 0; i < vnt.cell->tag; ++i) {
	gproclist.vec->data[i] = (long)_gcd[i];
    }

    CLUREF ginfo;
    CLUREF d_cell_tag = CLU_4;
    err = oneofOPnew(d_cell_tag, gproclist, &ginfo);
    if (err != ERR_ok) resignal(err);

    CLUREF size = { .num = 2 * CLUREFSZ + GCD_REF_SIZE };
    err = gcd_tabOPinsert(tab, size, ginfo, vnt, ans);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
variantOPequal(CLUREF vnt1, CLUREF vnt2, CLUREF *ans)
{
    if (vnt1.ref == vnt2.ref)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
variantOPdebug_print(CLUREF vnt, CLUREF pst)
{
    errcode err;

    err = variantOPprint(vnt, pst);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
variantOPprint(CLUREF vnt, CLUREF pst)
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
    const char *name = names[vnt.cell->tag - 1];
    size_t size = strlen(name);
    stringOPcons(name, CLU_1, CLUREF_make_num(size), &temp_str);

    err = pstreamOPtext(pst, temp_str, &ans);
    if (err != ERR_ok) resignal(err);

    err = stringOPcons(": ", CLU_1, CLU_2, &temp_str);
    if (err != ERR_ok) resignal(err);

    err = pstreamOPtext(pst, temp_str, &ans);
    if (err != ERR_ok) resignal(err);

    /* call the tag's print function */
    value.num = vnt.cell->value;
    CUR_PROC_VAR.proc = (CLUPROC)table[vnt.cell->tag - 1];
    err = table[vnt.cell->tag - 1]->proc(value, pst);
    if (err != ERR_ok) resignal(err);

    err = stringOPcons(">", CLU_1, CLU_1, &temp_str);
    if (err != ERR_ok) resignal(err);

    err = pstreamOPstop(pst, temp_str, &ans);
    if (err != ERR_ok) resignal(err);

    signal(ERR_ok);
}


errcode
variantOPencode(CLUREF vnt, CLUREF ist)
{
    errcode err;

    /* encode the tag */
    CLUREF tag = { .num = vnt.cell->tag };
    err = istreamOPputi(ist, tag);
    if (err != ERR_ok) resignal(ERR_ok);

    /* call tag's encode function to encode the value */
    const OWN_ptr *owns = CUR_PROC_VAR.proc->op_owns;
    const CLUPROC *encode = (CLUPROC *)owns->info;

    CLUREF value = { .num = vnt.cell->value };
    CUR_PROC_VAR.proc = encode[vnt.cell->tag - 1];
    err = (*CUR_PROC_VAR.proc->proc)(value, ist);
    if (err == ERR_not_possible) signal(err);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
variantOPdecode(CLUREF ist, CLUREF *ans)
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

    err = variantOPnew(tag, value, &temp);
    if (err != ERR_ok) resignal(err);

    ans->cell = temp.cell;
    signal(ERR_ok);
}


errcode
variantOPv_gets_v(CLUREF vnt1, CLUREF vnt2)
{
    vnt1.cell->tag = vnt2.cell->tag;
    vnt1.cell->value = vnt2.cell->value;
    signal(ERR_ok);
}


errcode
variantOPv_gets_o(CLUREF vnt, CLUREF one)
{
    vnt.cell->tag = one.cell->tag;
    vnt.cell->value = one.cell->value;
    signal(ERR_ok);
}


errcode
variantOPcopy1(CLUREF vnt, CLUREF *ans)
{
    CLUREF temp;
    errcode err;

    CLUREF tag = { .num = vnt.cell->tag };
    CLUREF value = { .num = vnt.cell->value };
    err = variantOPnew(tag, value, &temp);
    if (err != ERR_ok) resignal(err);

    ans->cell = temp.cell;
    signal(ERR_ok);
}


errcode
variantOPsimilar1(CLUREF vnt1, CLUREF vnt2, CLUREF *ans)
{
    errcode err;

    if (vnt1.cell->tag != vnt2.cell->tag) {
	ans->tf = false;
	signal(ERR_ok);
    }

    /* call tag's equal function to do the work */
    const OWN_ptr *owns = CUR_PROC_VAR.proc->op_owns;
    const CLUPROC *equal = (CLUPROC *)owns->info;

    CLUREF value1 = { .num = vnt1.cell->value };
    CLUREF value2 = { .num = vnt2.cell->value };
    CUR_PROC_VAR.proc = equal[vnt1.cell->tag - 1];
    err = (*CUR_PROC_VAR.proc->proc)(value1, value2, ans);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}



OWN_ptr variant_own_init = { .init_flag = 1 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &variant_own_init,		\
    .op_owns = &variant_own_init,		\
}

CLU_proc variant_oe_equal = CLU_proc_INIT(variantOPequal);
CLU_proc variant_oe_copy = CLU_proc_INIT(variantOPcopy);
CLU_proc variant_oe_similar = CLU_proc_INIT(variantOPsimilar);
CLU_proc variant_oe_print = CLU_proc_INIT(variantOPprint);
CLU_proc variant_oe_encode = CLU_proc_INIT(variantOPencode);
CLU_proc variant_oe_decode = CLU_proc_INIT(variantOPdecode);
CLU_proc variant_oe__gcd = CLU_proc_INIT(variantOP_gcd);
CLU_proc variant_oe_debug_print = CLU_proc_INIT(variantOPdebug_print);


/* extends struct OPS */
typedef struct {
long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[8];
} selector_OPS;

selector_OPS variant_ops_actual = {
    8,
    &variant_own_init,
    &variant_own_init,
    {
	{ &variant_oe_equal, "equal" },
	{ &variant_oe_copy, "copy" },
	{ &variant_oe_similar, "similar" },
	{ &variant_oe_print, "print" },
	{ &variant_oe_encode, "encode" },
	{ &variant_oe_decode, "decode" },
	{ &variant_oe__gcd, "_gcd" },
	{ &variant_oe_debug_print, "debug_print" },
    }
};

selector_OPS *variant_ops = &variant_ops_actual;
