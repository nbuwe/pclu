
/* Copyright Massachusetts Institute of Technology 1990,1991 */

#ifndef lint
static char rcsid[] = "$Header: /pm/src/site/pclu/code/base/RCS/variant.c,v 1.6 91/08/29 14:55:03 dcurtis Exp $";
#endif
/* $Log:	variant.c,v $
 * Revision 1.6  91/08/29  14:55:03  dcurtis
 * fixed oneofOPnew call's arguments to conform (removed elist)
 * 
 * Revision 1.5  91/06/06  13:32:37  root
 * added copyright notice
 * 
 * Revision 1.4  91/06/05  13:27:19  root
 * added elist to sequence$new2
 * 
 * Revision 1.3  91/06/03  14:29:26  root
 * sparcstation compatibility: int->CLUREF
 * 
 * Revision 1.2  91/05/31  12:57:34  root
 * fixed aggregate initialization in ops_actual
 * fixed ints vs CLUREFS in copy & copy1
 * added start & length arguments to string$cons calls
 * added result values to pstream calls
 * 
 * Revision 1.1  91/02/04  15:49:58  mtv
 * Initial revision
 * 
 */

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


errcode variantOPnew(tag, val, ans)
CLUREF tag, val;
CLUREF *ans;
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


errcode variantOPcopy(variant, ans)
CLUREF variant, *ans;
{
CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to copy fcns */
errcode err;
CLUREF tag, value, temp;

	tag.num = variant.cell->tag;
	value.num = variant.cell->value;
	err = variantOPnew(tag, value, &temp);
	if (err != ERR_ok) resignal(err); 
	CUR_PROC_VAR.proc = (CLUPROC)table[variant.cell->tag - 1];
	err = table[variant.cell->tag - 1]->proc(value, &temp.cell->value);
	if (err != ERR_ok) resignal(err);
	ans->cell = temp.cell;
	signal(ERR_ok);
	}

errcode variantOPsimilar(vnt1, vnt2, ans)
CLUREF vnt1, vnt2, *ans;
{
CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to similar fcns */
errcode err;
CLUREF value1, value2;

	if (vnt1.cell->tag != vnt2.cell->tag) {
			ans->tf = false;
			signal(ERR_ok);
			}
	value1.num = vnt1.cell->value;
	value2.num = vnt2.cell->value;
	CUR_PROC_VAR.proc = (CLUPROC)table[vnt1.cell->tag - 1];
	err = table[vnt1.cell->tag - 1]->proc(value1, value2, ans);
	if (err != ERR_ok) resignal(err);
	signal(ERR_ok);
	}

errcode variantOP_gcd(vnt, tab, ans)
CLUREF vnt, tab, *ans;
{
CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to _gcd fcns */
errcode err;
long i;
CLUREF temp_oneof, temp_seq, sz;

	sz.num = vnt.cell->tag;
        sequenceOPnew2(sz, &temp_seq);
        for (i = 0; i < vnt.cell->tag; i++) {
                temp_seq.vec->data[i] = (long)table[i];
                }

	err = oneofOPnew(CLU_4, temp_seq, &temp_oneof);
	if (err != ERR_ok) resignal(err);
	sz.num = 2*CLUREFSZ + GCD_REF_SIZE;
	err = gcd_tabOPinsert(tab, sz, temp_oneof, vnt, ans);
	if (err != ERR_ok) resignal(err);
	signal(ERR_ok);
	}

errcode variantOPequal(vnt1, vnt2, ans)
CLUREF vnt1, vnt2, *ans;
{
	if (vnt1.ref == vnt2.ref) ans->tf = true;
	else ans->tf = false;
	signal(ERR_ok);
	}

errcode variantOPdebug_print(vnt, pst)
CLUREF vnt, pst;
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


errcode variantOPencode(vnt, ist)
CLUREF vnt, ist;
{
errcode err;
CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to encode fcns */
CLUREF tag, value;

	tag.num = vnt.cell->tag;
	value.num = vnt.cell->value;
	err = istreamOPputi(ist, tag);
	if (err != ERR_ok) resignal(ERR_ok);
	CUR_PROC_VAR.proc = (CLUPROC)table[vnt.cell->tag - 1];
	err = table[vnt.cell->tag - 1]->proc(value, ist);
	if (err == ERR_not_possible) signal(err);
	if (err != ERR_ok) resignal(err);
	signal(ERR_ok);
	}

errcode variantOPdecode(ist, ans)
CLUREF ist, *ans;
{
errcode err;
CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to decode fcns */
CLUREF tag, value, temp;

	err = istreamOPgeti(ist, &tag);
	if (err != ERR_ok) resignal(ERR_ok);

	/* error checking on tag value */

	CUR_PROC_VAR.proc = (CLUPROC)table[tag.num - 1];
	err = table[tag.num - 1]->proc(ist, &value);
	if (err == ERR_not_possible) signal(err);
	if (err == ERR_end_of_file) signal(err);
	if (err != ERR_ok) resignal(err);
	err = variantOPnew(tag, value, &temp);
	if (err != ERR_ok) resignal(err);
	ans->cell = temp.cell;
	signal(ERR_ok);
	}

errcode variantOPv_gets_v(vnt1, vnt2)
CLUREF vnt1, vnt2;
{
	vnt1.cell->tag = vnt2.cell->tag;
	vnt1.cell->value = vnt2.cell->value;
	signal(ERR_ok);
	}

errcode variantOPv_gets_o(vnt, one)
CLUREF vnt, one;
{
	vnt.cell->tag = one.cell->tag;
	vnt.cell->value = one.cell->value;
	signal(ERR_ok);
	}


errcode variantOPcopy1(vnt, ans)
CLUREF vnt, *ans;
{
errcode err;
CLUREF tag, value, temp;

	tag.num = vnt.cell->tag;
	value.num = vnt.cell->value;
	err = variantOPnew(tag, value, &temp);
	if (err != ERR_ok) resignal(err);
	ans->cell = temp.cell;
	signal(ERR_ok);
	}

errcode variantOPsimilar1(vnt1, vnt2, ans)
CLUREF vnt1, vnt2, *ans;
{
CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to equal fcns */
errcode err;
CLUREF value1, value2;

	if (vnt1.cell->tag != vnt2.cell->tag) {
			ans->tf = false;
			signal(ERR_ok);
			}
	value1.num = vnt1.cell->value;
	value2.num = vnt2.cell->value;
	CUR_PROC_VAR.proc = (CLUPROC)table[vnt1.cell->tag - 1];
	err = table[vnt1.cell->tag - 1]->proc(value1, value2, ans);
	if (err != ERR_ok) resignal(err);
	signal(ERR_ok);

	}


typedef struct 
{
PROC *fcn;
char *name;
	} SEL_ENTRY;

typedef struct {
long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
struct OP_ENTRY entry[8];
	} selector_OPS;

typedef struct {
long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
struct OP_ENTRY equal;
struct OP_ENTRY copy;
struct OP_ENTRY similar;
struct OP_ENTRY print;
struct OP_ENTRY encode;
struct OP_ENTRY decode;
struct OP_ENTRY _gcd;
struct OP_ENTRY debug_print;
struct OP_ENTRY copy1;
struct OP_ENTRY similar1;
	} selector_TABLE;

OWN_ptr variant_own_init = {1, 0};

CLU_proc variant_oe_equal = {{0,0,0,0}, variantOPequal, &variant_own_init, &variant_own_init};
CLU_proc variant_oe_copy = {{0,0,0,0}, variantOPcopy, &variant_own_init, &variant_own_init};
CLU_proc variant_oe_similar = {{0,0,0,0}, variantOPsimilar, &variant_own_init, &variant_own_init};
CLU_proc variant_oe_print = {{0,0,0,0}, variantOPprint, &variant_own_init, &variant_own_init};
CLU_proc variant_oe_encode = {{0,0,0,0}, variantOPencode, &variant_own_init, &variant_own_init};
CLU_proc variant_oe_decode = {{0,0,0,0}, variantOPdecode, &variant_own_init, &variant_own_init};
CLU_proc variant_oe__gcd = {{0,0,0,0}, variantOP_gcd, &variant_own_init, &variant_own_init};
CLU_proc variant_oe_debug_print = {{0,0,0,0}, variantOPdebug_print, &variant_own_init, &variant_own_init};

selector_OPS variant_ops_actual = {8, 
    &variant_own_init,
    &variant_own_init, {
{&variant_oe_equal, "equal"},
{&variant_oe_copy, "copy"}, 
{&variant_oe_similar, "similar"},
{&variant_oe_print, "print"},
{&variant_oe_encode, "encode"},
{&variant_oe_decode, "decode"},
{&variant_oe__gcd, "_gcd"},
{&variant_oe_debug_print, "debug_print"}
}};

selector_OPS *variant_ops = &variant_ops_actual;

