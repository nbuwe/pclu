/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*								*/
/*		NULL IMPLEMENTATION				*/
/*								*/


#include "pclu_err.h"
#include "pclu_sys.h"

errcode istreamOPgeti(CLUREF ist, CLUREF *ret_1);
errcode istreamOPputi(CLUREF ist, CLUREF i);
errcode pstreamOPtext(CLUREF ps, CLUREF s, CLUREF *ret_1);

errcode nullOPprint(CLUREF n, CLUREF pst);


errcode
nullOPequal(CLUREF nn1, CLUREF nn2, CLUREF *ans)
{
    CLU_NOREF(nn1);
    CLU_NOREF(nn2);

    ans->tf = true;
    signal(ERR_ok);
}


errcode
nullOPsimilar(CLUREF nn1, CLUREF nn2, CLUREF *ans)
{
    CLU_NOREF(nn1);
    CLU_NOREF(nn2);

    ans->tf = true;
    signal(ERR_ok);
}


errcode
nullOPcopy(CLUREF n, CLUREF *ans)
{
    ans->num = n.num;
    signal(ERR_ok);
}


errcode
nullOPdebug_print(CLUREF n, CLUREF pst)
{
    errcode err;

    err = nullOPprint(n, pst);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
nullOPprint(CLUREF n, CLUREF pst)
{
    errcode err;
    CLUREF temp_str, ans;

    CLU_NOREF(n);

    err = stringOPcons("nil", CLU_1, CLU_3, &temp_str);
    if (err != ERR_ok) resignal(err);

    err = pstreamOPtext(pst, temp_str, &ans);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
nullOPencode(CLUREF n, CLUREF ist)
{
    errcode err;

    err = istreamOPputi(ist, n);
    if (err == ERR_not_possible) signal(err);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
nullOPdecode(CLUREF ist, CLUREF *ans)
{
    CLUREF temp;
    errcode err;

    err = istreamOPgeti(ist, &temp);
    if (err == ERR_end_of_file) signal(err);
    if (err == ERR_not_possible) signal(err);
    if (err != ERR_ok) resignal(err);

    if (temp.num != 0) {
	elist[0] = bad_format_STRING;
	signal(ERR_not_possible);
    }

    ans->num = 0;
    signal(ERR_ok);
}


errcode
nullOP_gcd(CLUREF s, CLUREF tab, CLUREF *ans)
{
    CLU_NOREF(s);
    CLU_NOREF(tab);

    ans->num = -1;
    signal(ERR_ok);
}



OWN_ptr null_own_init = { .init_flag = 1 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &null_own_init,		\
    .op_owns = &null_own_init,			\
}

CLU_proc null_oe_copy = CLU_proc_INIT(nullOPcopy);
CLU_proc null_oe_equal = CLU_proc_INIT(nullOPequal);
CLU_proc null_oe_similar = CLU_proc_INIT(nullOPsimilar);
CLU_proc null_oe_print = CLU_proc_INIT(nullOPprint);
CLU_proc null_oe_encode = CLU_proc_INIT(nullOPencode);
CLU_proc null_oe_decode = CLU_proc_INIT(nullOPdecode);
CLU_proc null_oe__gcd = CLU_proc_INIT(nullOP_gcd);
CLU_proc null_oe_debug_print = CLU_proc_INIT(nullOPdebug_print);

/* extends struct OPS */
typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[8];
} null_OPS;

null_OPS null_ops_actual = {
    8,
    &null_own_init,
    &null_own_init,
    {
	{ &null_oe_copy, "copy" },
	{ &null_oe_equal, "equal" },
	{ &null_oe_similar, "similar" },
	{ &null_oe_print, "print" },
	{ &null_oe_encode, "encode" },
	{ &null_oe_decode, "decode" },
	{ &null_oe__gcd, "_gcd" },
	{ &null_oe_debug_print, "debug_print" },
    }
};

null_OPS *null_ops = &null_ops_actual;
