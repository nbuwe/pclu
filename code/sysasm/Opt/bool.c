/* Copyright Massachusetts Institute of Technology 1990,1991 */

#include "pclu_err.h"
#include "pclu_sys.h"

errcode istreamOPgeti(CLUREF ist, CLUREF *ret_1);
errcode istreamOPputi(CLUREF ist, CLUREF i);
errcode pstreamOPtext(CLUREF ps, CLUREF s, CLUREF *ret_1);

errcode boolOPprint(CLUREF b, CLUREF pst);


errcode
boolOPand(CLUREF b1, CLUREF b2, CLUREF *ans)
{
    ans->tf = b1.tf && b2.tf;
    signal(ERR_ok);
}


errcode
boolOPor(CLUREF b1, CLUREF b2, CLUREF *ans)
{
    ans->tf = b1.tf || b2.tf;
    signal(ERR_ok);
}


errcode
boolOPnot(CLUREF b1, CLUREF *ans)
{
    ans->tf = ~b1.tf & 1;
    signal(ERR_ok);
}


errcode
boolOPequal(CLUREF b1, CLUREF b2, CLUREF *ans)
{
    ans->tf = ((b1.tf & 1) == (b2.tf & 1));
    signal(ERR_ok);
}


errcode
boolOPsimilar(CLUREF b1, CLUREF b2, CLUREF *ans)
{
    ans->tf = (b1.tf & 1) == (b2.tf & 1);
    signal(ERR_ok);
}


errcode
boolOPcopy(CLUREF b1, CLUREF *ans)
{
    ans->tf = b1.tf;
    signal(ERR_ok);
}


errcode
boolOPdebug_print(CLUREF b, CLUREF pst)
{
    errcode err;

    err = boolOPprint(b, pst);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
boolOPprint(CLUREF b, CLUREF pst)
{
    CLUREF ans;
    errcode err;

    static CLUREF true_STRING = { .str = NULL };
    static CLUREF false_STRING = { .str = NULL };
    if (true_STRING.str == NULL) {
	err = stringOPcons("true", CLU_1, CLU_4, &true_STRING);
	if (err != ERR_ok) resignal(err);

	err = stringOPcons("false", CLU_1, CLU_5, &false_STRING);
	if (err != ERR_ok) resignal(err);
    }

    if (b.tf)
	err = pstreamOPtext(pst, true_STRING, &ans);
    else
	err = pstreamOPtext(pst, false_STRING, &ans);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
boolOPencode(CLUREF b, CLUREF ist)
{
    errcode err;

    err = istreamOPputi(ist, b);
    if (err == ERR_not_possible) signal(err);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


errcode
boolOPdecode(CLUREF ist, CLUREF *ans)
{
    CLUREF temp;
    errcode err;

    err = istreamOPgeti(ist, &temp);
    if (err == ERR_not_possible || err == ERR_end_of_file) signal(err);
    if (err != ERR_ok) resignal(err);

    if (temp.num == 0 || temp.num == 1) {
	ans->tf = temp.tf;
	signal(ERR_ok);
    }
    else {
	elist[0] = bad_format_STRING;
	signal(ERR_not_possible);
    }
}


errcode
boolOP_gcd(CLUREF b, CLUREF tab, CLUREF *ans)
{
    ans->num = -1;
    signal(ERR_ok);
}



OWN_ptr bool_own_init = { .init_flag = 1 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &bool_own_init,		\
    .op_owns = &bool_own_init,			\
}

CLU_proc bool_oe_and = CLU_proc_INIT(boolOPand);
CLU_proc bool_oe_or = CLU_proc_INIT(boolOPor);
CLU_proc bool_oe_not = CLU_proc_INIT(boolOPnot);
CLU_proc bool_oe_equal = CLU_proc_INIT(boolOPequal);
CLU_proc bool_oe_similar = CLU_proc_INIT(boolOPsimilar);
CLU_proc bool_oe_copy = CLU_proc_INIT(boolOPcopy);
CLU_proc bool_oe_print = CLU_proc_INIT(boolOPprint);
CLU_proc bool_oe_encode = CLU_proc_INIT(boolOPencode);
CLU_proc bool_oe_decode = CLU_proc_INIT(boolOPdecode);
CLU_proc bool_oe__gcd = CLU_proc_INIT(boolOP_gcd);
CLU_proc bool_oe_debug_print = CLU_proc_INIT(boolOPdebug_print);


/* extends struct OPS */
typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[11];
} bool_OPS;

bool_OPS bool_ops_actual = {
    11,
    &bool_own_init,
    &bool_own_init,
    {
	{ &bool_oe_equal, "equal" },
	{ &bool_oe_similar, "similar" },
	{ &bool_oe_copy, "copy" },
	{ &bool_oe_print, "print" },
	{ &bool_oe_encode, "encode" },
	{ &bool_oe_decode, "decode" },
	{ &bool_oe__gcd, "_gcd" },
	{ &bool_oe_debug_print, "debug_print" },
	{ &bool_oe_and, "and" },
	{ &bool_oe_or, "or" },
	{ &bool_oe_not, "not" },
    }
};

bool_OPS *bool_ops = &bool_ops_actual;
