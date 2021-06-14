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

errcode structOPblit(CLUREF strct, CLUREF *ans);
errcode structOPprint(CLUREF str, CLUREF pst);


#define structOPOPmemsize(_size) (offsetof(CLU_sequence, data) + (_size) * CLUREFSZ)

errcode
structOPnew(CLUREF size, CLUREF *ans)
{
    CLUREF temp;

    clu_alloc(structOPOPmemsize(size.num), &temp);
    temp.vec->typ.mark = 0;
    temp.vec->typ.val = CT_REC;
    temp.vec->typ.refp = 0;
    temp.vec->typ.spare = 0;
    temp.vec->size = size.num;

    ans->vec = temp.vec;
    signal(ERR_ok);
}


errcode
structOPblit(CLUREF strct, CLUREF *ans)
{
    CLUREF temp;

    clu_alloc(structOPOPmemsize(strct.vec->size), &temp);
    temp.vec->typ.mark = 0;
    temp.vec->typ.val = CT_REC;
    temp.vec->typ.refp = 0;
    temp.vec->typ.spare = 0;
    temp.vec->size = strct.vec->size;
    bcopy((char*)strct.vec->data, (char*)temp.vec->data, strct.vec->size*CLUREFSZ);

    ans->vec = temp.vec;
    signal(ERR_ok);
}


errcode
structOPcopy(CLUREF strct, CLUREF *ans)
{
    CLUPROC *field_copy =
	(CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;
    errcode err;
    CLUREF temp, elt;
    long i;

    clu_alloc(structOPOPmemsize(strct.vec->size), &temp);
    temp.vec->typ.mark = 0;
    temp.vec->typ.val = CT_REC;
    temp.vec->typ.refp = 0;
    temp.vec->typ.spare = 0;
    temp.vec->size = strct.vec->size;

    for (i = 0; i < strct.vec->size; ++i) {
	elt.num = strct.vec->data[i];
	CUR_PROC_VAR.proc = field_copy[i];
	err = (*field_copy[i]->proc)(elt, &temp.vec->data[i]);
	if (err != ERR_ok)
	    resignal(err);
    }

    ans->vec = temp.vec;
    signal(ERR_ok);
}


errcode
structOPsimilar(CLUREF rec1, CLUREF rec2, CLUREF *ans)
{
    CLUPROC *field_similar
	= (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;
    long i;
    errcode err;
    CLUREF elt1, elt2;

    if (rec1.vec->size != rec2.vec->size) {
	ans->tf = false;
	signal(ERR_ok);
    }

    for (i = 0; i < rec1.vec->size; ++i) {
	elt1.num = rec1.vec->data[i];
	elt2.num = rec2.vec->data[i];
	CUR_PROC_VAR.proc = field_similar[i];
	err = (*field_similar[i]->proc)(elt1, elt2, ans);
	if (ans->tf == false)
	    signal(ERR_ok);
    }
    signal(ERR_ok);
}


errcode
structOPequal(CLUREF str1, CLUREF str2, CLUREF *ans)
{
    CLUPROC *field_equal
	= (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;
    long i;
    errcode err;
    CLUREF elt1, elt2;

    if (str1.vec->size != str2.vec->size) {
	ans->tf = false;
	signal(ERR_ok);
    }
    for (i = 0; i < str1.vec->size; ++i) {
	elt1.num = str1.vec->data[i];
	elt2.num = str2.vec->data[i];
	CUR_PROC_VAR.proc = field_equal[i];
	err = (*field_equal[i]->proc)(elt1, elt2, ans);
	if (ans->tf == false)
	    signal(ERR_ok);
    }
    signal(ERR_ok);
}


errcode
structOP_gcd(CLUREF str, CLUREF tab, CLUREF *ans)
{
    CLUPROC *field_gcd
	= (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;
    errcode err;
    long i;
    CLUREF ginfo, gproclist, sz;

    sz.num = str.vec->size;
    sequenceOPnew2(sz, &gproclist);
    for (i = 0; i < str.vec->size; ++i) {
	gproclist.vec->data[i] = (long)field_gcd[i];
    }

    err = oneofOPnew(CLU_3, gproclist, &ginfo);
    if (err != ERR_ok)
	resignal(err);

    sz.num = 2*CLUREFSZ + (str.vec->size * GCD_REF_SIZE);
    err = gcd_tabOPinsert(tab, sz, ginfo, str, ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
structOPs2r(CLUREF str, CLUREF *ans)
{
    errcode err;
    CLUREF temp, sz;

    sz.num = str.vec->size;
    err = recordOPnew(sz, &temp);
    if (err != ERR_ok)
	resignal(err);

    bcopy((char*)str.vec->data, (char*)temp.vec->data, str.vec->size*CLUREFSZ);

    ans->vec = temp.vec;
    signal(ERR_ok);
}


errcode
structOPr2s(CLUREF rec, CLUREF *ans)
{
    errcode err;
    CLUREF temp, sz;

    sz.num = rec.vec->size;
    err = structOPnew(sz, &temp);
    if (err != ERR_ok)
	resignal(err);

    bcopy((char*)rec.vec->data, (char*)temp.vec->data, rec.vec->size*CLUREFSZ);

    ans->vec = temp.vec;
    signal(ERR_ok);
}


errcode
structOPdebug_print(CLUREF str, CLUREF pst)
{
    errcode err;

    err = structOPprint(str, pst);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
structOPprint(CLUREF str, CLUREF pst)
{
    CLUPROC *field_print
	= (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;
    char **field_name
	= (char **)(field_print + str.vec->size);
    long i;
    errcode err;
    CLUREF temp_str, temp_str2, temp_str3, ref, size, ans;

    err = stringOPcons("{", CLU_1, CLU_1, &temp_str);
    if (err != ERR_ok)
	resignal(err);

    err = pstreamOPstart(pst, temp_str, &ans);
    if (err != ERR_ok)
	resignal(err);
    if (ans.tf == false)
	goto done;

    err = stringOPcons(",", CLU_1, CLU_1, &temp_str);
    if (err != ERR_ok)
	resignal(err);

    err = stringOPcons(": ", CLU_1, CLU_2, &temp_str2);
    if (err != ERR_ok)
	resignal(err);

    for (i = 0; i < str.vec->size; ++i) {
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

	ref.num = str.vec->data[i];
	CUR_PROC_VAR.proc = field_print[i];
	err = (*field_print[i]->proc)(ref, pst);
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
structOPencode(CLUREF str, CLUREF ist)
{
    CLUPROC *field_encode
	= (CLUPROC *)CUR_PROC_VAR.proc->op_owns->info;
    long i;
    errcode err;
    CLUREF ref;

    err = istreamOPputi(ist, CLUREF_make_num(str.vec->size));
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    for (i = 0; i < str.vec->size; ++i) {
	ref.num = str.vec->data[i];
	CUR_PROC_VAR.proc = field_encode[i];
	err = (*field_encode[i]->proc)(ref, ist);
	if (err == ERR_not_possible)
	    signal(err);
	if (err != ERR_ok)
	    resignal(err);
    }
    signal(ERR_ok);
}


errcode
structOPdecode(CLUREF ist, CLUREF *ans)
{
    CLUPROC *field_decode
	= (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info;
    long i;
    errcode err;
    CLUREF temp, size;

    err = istreamOPgeti(ist, &size);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    err = structOPnew(size, &temp);
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
