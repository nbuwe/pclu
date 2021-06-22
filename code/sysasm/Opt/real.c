/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*	unreal	IMPLEMENTATION OF		*/
/*			REAL			*/
/*						*/

/* Include this early b/c of "log" */
#include <math.h>

#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdio.h>

errcode istreamOPgeti(CLUREF ist, CLUREF *ret_1);
errcode istreamOPputi(CLUREF ist, CLUREF i);
errcode pstreamOPtext(CLUREF ps, CLUREF s, CLUREF *ret_1);

errcode realOPprint(CLUREF r, CLUREF pst);


/* This is the real (real cluster).  Many of these procedures
   should be inlined.  They are all here for reference.  Full
   reals are implemented: no bits are left for tags.
*/

/*
real = cluster is add, sub, mul, minus, div, power, abs, min, max,
		 i2r, r2i, trunc, exponent, mantissa, parse, unparse,
		 lt, le, ge, gt,
		 equal, similar, copy, print, encode, decode, _gcd
*/



errcode
realOPadd(CLUREF r1, CLUREF r2, CLUREF *ans)
{
    float temp = r1.real + r2.real;

    ans->real = temp;
    signal(ERR_ok);
}


errcode
realOPsub(CLUREF r1, CLUREF r2, CLUREF *ans)
{
    float temp = r1.real - r2.real;

    ans->real = temp;
    signal(ERR_ok);
}


errcode
realOPmul(CLUREF r1, CLUREF r2, CLUREF *ans)
{
    float temp = r1.real * r2.real;

    ans->real = temp;
    signal(ERR_ok);
}


errcode
realOPminus(CLUREF r1, CLUREF *ans)
{
    ans->real = -r1.real;
    signal(ERR_ok);
}


errcode
realOPdiv(CLUREF num, CLUREF den, CLUREF *ans)
{
    if (den.real == 0)
	signal(ERR_zero_divide);

    ans->real = num.real/den.real;
    signal(ERR_ok);
}


errcode
realOPpower(CLUREF r, CLUREF exp, CLUREF *ans)
{
    double temp, dr, dexp;

    dr = (double) r.real;
    dexp = (double) exp.real;
    temp = pow(dr, dexp);
    if (isnan(temp))
	signal(ERR_overflow);

    ans->real = temp;
    signal(ERR_ok);
}


errcode
realOPabs(CLUREF r, CLUREF *ans)
{
    if (r.real >= 0) {
	ans->real = r.real;
	signal(ERR_ok);
    }

    ans->real = -r.real;
    signal(ERR_ok);
}


errcode
realOPmin(CLUREF r1, CLUREF r2, CLUREF *ans)
{
    if (r1.real <= r2.real)
	ans->real = r1.real;
    else
	ans->real = r2.real;
    signal(ERR_ok);
}


errcode
realOPmax(CLUREF r1, CLUREF r2, CLUREF *ans)
{
    if (r1.real >= r2.real)
	ans->real = r1.real;
    else
	ans->real = r2.real;
    signal(ERR_ok);
}


errcode
realOPi2r(CLUREF i, CLUREF *ans)
{
    ans->real = (float)i.num;
    signal(ERR_ok);
}


errcode
realOPr2i(CLUREF r, CLUREF *ans)
{
    ans->num = (long)r.real;
    signal(ERR_ok);
}


errcode
realOPtrunc(CLUREF r, CLUREF *ans)
{
    long temp;

    if (r.real > intOPmaxint)
	signal(ERR_overflow);

    temp = (long) r.real;

    ans->num = temp;
    signal(ERR_ok);
}


errcode
realOPexponent(CLUREF r, CLUREF *ans)
{
    CLUREF exp;
    float mant;

    if (r.real == 0.0)
	signal(ERR_undefined);

    if (r.real < 0.0)
	r.real = -r.real;

    exp.num = 0;
    mant = r.real;
    for(; mant > 10.0;) {
	mant = mant/10.0;
	++exp.num;
    }
    for(; mant < 1.0;) {
	mant = mant*10.0;
	--exp.num;
    }

    ans->num = exp.num;
    signal(ERR_ok);
}


errcode
realOPmantissa(CLUREF r, CLUREF *ans)
{
    float mant;
    bool minus;

    if (r.real == 0.0) {
	ans->real = 0.0;
    }

    if (r.real < 0.0) {
	minus = true;
	r.real = -r.real;
    }
    else {
	minus = false;
    }

    mant = r.real;
    for(; mant > 10.0;) {
	mant = mant/10.0;
    }
    for(; mant < 1.0;) {
	mant = mant*10.0;
    }

    if (minus == false)
	ans->real = mant;
    else
	ans->real  = -mant;
    signal(ERR_ok);
}


errcode
realOPparse(CLUREF s, CLUREF *ans)
{
    float temp;
    int cnt;

    cnt = sscanf(s.str->data, "%f", &temp);
    if (cnt == 0)
	signal(ERR_bad_format);

    ans->real = temp;
    signal(ERR_ok);
}


errcode
realOPunparse(CLUREF r, CLUREF *ans)
{
    errcode err;
    int uerr;
    char temp[100];
    CLUREF temp2, size;

    uerr = sprintf(temp, "%e", (double)r.real);
    if (uerr == -1)
	signal(ERR_bad_format);

    size.num = strlen(temp);
    err = stringOPcons(temp, CLU_1, size, &temp2);
    if (err != ERR_ok)
	resignal(err);

    ans->str = temp2.str;
    signal(ERR_ok);
}


errcode
realOPlt(CLUREF r1, CLUREF r2, CLUREF *ans)
{
    ans->tf = false;
    if (r1.real < r2.real)
	ans->tf = true;
    signal(ERR_ok);
}


errcode
realOPle(CLUREF r1, CLUREF r2, CLUREF *ans)
{
    ans->tf = false;
    if (r1.real <= r2.real)
	ans->tf = true;
    signal(ERR_ok);
}


errcode
realOPgt(CLUREF r1, CLUREF r2, CLUREF *ans)
{
    ans->tf = false;
    if (r1.real > r2.real)
	ans->tf = true;
    signal(ERR_ok);
}


errcode
realOPge(CLUREF r1, CLUREF r2, CLUREF *ans)
{
    ans->tf = false;
    if (r1.real >= r2.real)
	ans->tf = true;
    signal(ERR_ok);
}


errcode
realOPequal(CLUREF r1, CLUREF r2, CLUREF *ans)
{
    ans->tf = false;
    if (r1.real == r2.real)
	ans->tf = true;
    signal(ERR_ok);
}


errcode
realOPsimilar(CLUREF r1, CLUREF r2, CLUREF *ans)
{
    ans->tf = false;
    if (r1.real == r2.real)
	ans->tf = true;
    signal(ERR_ok);
}


errcode
realOPcopy(CLUREF r, CLUREF *ans)
{
    ans->real = r.real;
    signal(ERR_ok);
}


errcode
realOPdebug_print(CLUREF r, CLUREF pst)
{
    errcode err;

    err = realOPprint(r, pst);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
realOPprint(CLUREF r, CLUREF pst)
{
    errcode err;
    CLUREF temp, ans;

    err = realOPunparse(r, &temp);
    if (err != ERR_ok)
	resignal(err);

    err = pstreamOPtext(pst, temp, &ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
realOPencode(CLUREF r, CLUREF ist)
{
    errcode err;

    err = istreamOPputi(ist, r);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
realOPdecode(CLUREF ist, CLUREF *ans)
{
    errcode err;

    err = istreamOPgeti(ist, ans);
    if (err == ERR_not_possible || err == ERR_end_of_file)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    /* add a sanity check here??? */
    signal(ERR_ok);
}


errcode
realOP_gcd(CLUREF r, CLUREF tab, CLUREF *ans)
{
    CLU_NOREF(r);
    CLU_NOREF(tab);

    ans->num = -1;
    signal(ERR_ok);
}


OWN_ptr real_own_init = { .init_flag = 1 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &real_own_init,		\
    .op_owns = &real_own_init,			\
}

static CLU_proc real_oe_add = CLU_proc_INIT(realOPadd);
static CLU_proc real_oe_sub = CLU_proc_INIT(realOPsub);
static CLU_proc real_oe_mul = CLU_proc_INIT(realOPmul);
static CLU_proc real_oe_minus = CLU_proc_INIT(realOPminus);
static CLU_proc real_oe_div = CLU_proc_INIT(realOPdiv);
static CLU_proc real_oe_power = CLU_proc_INIT(realOPpower);
static CLU_proc real_oe_abs = CLU_proc_INIT(realOPabs);
static CLU_proc real_oe_min = CLU_proc_INIT(realOPmin);
static CLU_proc real_oe_max = CLU_proc_INIT(realOPmax);
static CLU_proc real_oe_parse = CLU_proc_INIT(realOPparse);
static CLU_proc real_oe_unparse = CLU_proc_INIT(realOPunparse);
static CLU_proc real_oe_lt = CLU_proc_INIT(realOPlt);
static CLU_proc real_oe_le = CLU_proc_INIT(realOPle);
static CLU_proc real_oe_gt = CLU_proc_INIT(realOPgt);
static CLU_proc real_oe_ge = CLU_proc_INIT(realOPge);
static CLU_proc real_oe_equal = CLU_proc_INIT(realOPequal);
static CLU_proc real_oe_similar = CLU_proc_INIT(realOPsimilar);
static CLU_proc real_oe_copy = CLU_proc_INIT(realOPcopy);
static CLU_proc real_oe_print = CLU_proc_INIT(realOPprint);
static CLU_proc real_oe_encode = CLU_proc_INIT(realOPencode);
static CLU_proc real_oe_decode = CLU_proc_INIT(realOPdecode);
static CLU_proc real_oe__gcd = CLU_proc_INIT(realOP_gcd);
static CLU_proc real_oe_debug_print = CLU_proc_INIT(realOPdebug_print);


static struct /* OPS */ {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[23];
} real_ops_actual = {
    23,
    &real_own_init,
    &real_own_init,
    {
	{ &real_oe_add, "add" },
	{ &real_oe_sub, "sub" },
	{ &real_oe_mul, "mul" },
	{ &real_oe_minus, "minus" },
	{ &real_oe_div, "div" },
	{ &real_oe_power, "power" },
	{ &real_oe_abs, "abs" },
	{ &real_oe_min, "min" },
	{ &real_oe_max, "max" },
	{ &real_oe_parse, "parse" },
	{ &real_oe_unparse, "unparse" },
	{ &real_oe_lt, "lt" },
	{ &real_oe_le, "le" },
	{ &real_oe_gt, "gt" },
	{ &real_oe_ge, "ge" },
	{ &real_oe_equal, "equal" },
	{ &real_oe_similar, "similar" },
	{ &real_oe_copy, "copy" },
	{ &real_oe_print, "print" },
	{ &real_oe_encode, "encode" },
	{ &real_oe_decode, "decode" },
	{ &real_oe__gcd, "_gcd" },
	{ &real_oe_debug_print, "debug_print" },
    }
};

struct OPS *real_ops = (struct OPS *)&real_ops_actual;
