/* Copyright Massachusetts Institute of Technology 1990,1991 */
/* Copyright Massachusetts Institute of Technology 1989 */

/* This is the int (integer cluster).  Many of these procedures
   should be inlined.  They are all here for reference.  Full
   ints are implemented: no bits are left for tags.
*/
/*
int = cluster is add, sub, mul, minus, div, power, mod, abs, min, max,
		 from_to_by, from_to, parse, unparse, lt, le, ge, gt,
		 equal, similar, copy, print, encode, decode, _gcd
*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>

errcode gcd_tabOPinsert(CLUREF tab, CLUREF z, CLUREF inf, CLUREF x, CLUREF *ret_1);
errcode istreamOPgeti(CLUREF ist, CLUREF *ret_1);
errcode istreamOPputi(CLUREF ist, CLUREF i);
errcode pstreamOPtextc(CLUREF ps, CLUREF c, CLUREF *ret_1);
errcode stringOPfetch(CLUREF s, CLUREF i, CLUREF *ans);
errcode stringOPsize(CLUREF s, CLUREF *ans);

errcode intOPprint(CLUREF i, CLUREF pst);


errcode
intOPadd(CLUREF i1, CLUREF i2, CLUREF *ans)
{
    long temp;

    temp = i1.num + i2.num;
    if (i1.num < 0 && i2.num < 0 && temp >= 0)
	signal(ERR_overflow);
    if (i1.num > 0 && i2.num > 0 && temp <= 0)
	signal(ERR_overflow);

    ans->num = temp;
    signal(ERR_ok);
}


errcode
intOPsub(CLUREF i1, CLUREF i2, CLUREF *ans)
{
    long temp;

    temp = i1.num - i2.num;
    if (i1.num < 0 && (-i2.num) < 0 && temp >= 0)
	signal(ERR_overflow);
    if (i1.num > 0 && (-i2.num) > 0 && temp <= 0)
	signal(ERR_overflow);

    ans->num = temp;
    signal(ERR_ok);
}


errcode
intOPmul(CLUREF i1, CLUREF i2, CLUREF *ans)
{
    long temp;
    long abs_temp;
    long abs_i1;
    long abs_i2;

    /* be careful: leastint*0 is 0, leastint*1 is leastint,
                   leastint*n (n != 1,0) => overflow */

    /* handle zero first */
    if (i1.num == 0 || i2.num == 0) {
	ans->num = 0;
	signal(ERR_ok);
    }

    /* handle one */
    if (i1.num == 1) {
	ans->num = i2.num;
	signal(ERR_ok);
    }
    if (i2.num == 1) {
	ans->num = i1.num;
	signal(ERR_ok);
    }

    /* deal with cases where one of the numbers is the smallest integer */
    if (i1.num == intOPleastint || i2.num == intOPleastint)
	signal(ERR_overflow);

    /* form absolute values */
    if (i1.num >= 0)
	abs_i1 = i1.num;
    else
	abs_i1 = -i1.num;
    if (i2.num >= 0)
	abs_i2 = i2.num;
    else
	abs_i2 = -i2.num;

    /* if both absolute values are less than
       square root of max value then all is ok */
    if (abs_i1 < intOPsqrtmax && abs_i2 < intOPsqrtmax) {
	ans->num = i1.num * i2.num;
	signal(ERR_ok);
    }

    /* if both integers greater than square root of max value then no good */
    if (abs_i1 > intOPsqrtmax && abs_i2 > intOPsqrtmax)
	signal(ERR_overflow);

    /* now just multiply and check that result is greater than components */
    temp = i1.num * i2.num;
    if (temp != intOPleastint) {
	if (temp >= 0)
	    abs_temp = temp;
	else
	    abs_temp = -temp;
	if (abs_temp >= abs_i1 && abs_temp >= abs_i2) {
	    ans->num = temp;
	    signal(ERR_ok);
	}
	signal(ERR_overflow);
    }
    else {
	if (i1.num < 0 && i2.num > 0)
	    signal(ERR_ok);
	if (i1.num > 0 && i2.num < 0)
	    signal(ERR_ok);
	signal(ERR_overflow);
    }
}


errcode
intOPminus(CLUREF i1, CLUREF *ans)
{
    if (i1.num == intOPleastint)
	signal(ERR_overflow);

    ans->num = -i1.num;
    signal(ERR_ok);
}


/*
 * CLU specifies floored division (truncation toward minus infinity)
 * and the remainder is always positive.  The C standard specifies
 * symmetric division (truncation towards zero) and the remainder can
 * be negative.
 *
 * CLU: num/den = ans + remainder where 0 <= remainder < |den|
 *	=> -20/6 = -4 not -3
 * C: -20/6 = -3
 */

errcode
intOPdiv(CLUREF num, CLUREF den, CLUREF *ans)
{
    bool adjust;
    long temp;

    if (den.num == 0)
	signal(ERR_zero_divide);

    if (num.num < 0)
	adjust = true;
    else
	adjust = false;

    temp = num.num/den.num;
    if (temp * den.num != num.num) {
	if (adjust && (temp < 0)) temp--;
	if (adjust && (temp > 0)) temp++;
	if (adjust && (temp == 0) && (den.num < 0)) temp++;
	if (adjust && (temp == 0) && (den.num > 0)) temp--;
    }

    ans->num = temp;
    signal(ERR_ok);
}



extern double pow(double, double);

errcode
intOPpower(CLUREF i, CLUREF exp, CLUREF *ans)
{
    double temp, di, dexp;
    long temp2;

    /* these tests may be redundant with pow */
    if (exp.num <= 0) {
	if (exp.num == 0) {
	    ans->num = 1;
	    signal(ERR_ok);
	}
	signal(ERR_negative_exponent);
    }

    errno = 0;
    di = (double) i.num;
    dexp = (double) exp.num;
    temp = pow(di, dexp);
    temp2 = temp;
    if (errno == 0) {
	ans->num = temp2;
	signal(ERR_ok);
    }
    signal(ERR_overflow);
}


/*
 * CLU specifies floored division (truncation toward minus infinity)
 * and the remainder is always positive.  The C standard specifies
 * symmetric division (truncation towards zero) and the remainder can
 * be negative.
 *
 * int$mod: i mod base = res
 *     0 <= res < |base|
 *     i = base * q + res    for some number q
 */
errcode
intOPmod(CLUREF i, CLUREF base, CLUREF *ans)
{
    long temp;
    bool flip;

    if (base.num == 0)
	signal(ERR_zero_divide);

    errno = 0;

    if (i.num < 0) {
	i.num = -i.num;
	flip = true;
    }
    else {
	flip = false;
    }

    if (base.num < 0)
	base.num = -base.num;

    temp = i.num % base.num;
    if (errno == 0) {
	if (flip && temp != 0)
	    temp = base.num - temp;
	ans->num = temp;
	signal(ERR_ok);
    }
    signal(ERR_overflow);
}


errcode
intOPabs(CLUREF i, CLUREF *ans)
{
    if (i.num >= 0) {
	ans->num = i.num;
	signal(ERR_ok);
    }

    if (i.num == intOPleastint)
	signal(ERR_overflow);

    ans->num = -i.num;
    signal(ERR_ok);
}


errcode
intOPmin(CLUREF i1, CLUREF i2, CLUREF *ans)
{
    if (i1.num <= i2.num)
	ans->num = i1.num;
    else
	ans->num = i2.num;
    signal(ERR_ok);
}


errcode
intOPmax(CLUREF i1, CLUREF i2, CLUREF *ans)
{
    if (i1.num >= i2.num)
	ans->num = i1.num;
    else
	ans->num = i2.num;
    signal(ERR_ok);
}


errcode
intOPparse(CLUREF s, CLUREF *ans)
{
    CLUREF count, start, index;
    CLUREF firstchar, thischar;
    int i;
    long total = 0;
    errcode err;

    err = stringOPsize(s, &count);
    CLU_NOREF(err);

    if (count.num == 0)
	signal(ERR_bad_format);

    start.num = 1;
    err = stringOPfetch(s, start, &firstchar);
    CLU_NOREF(err);

    if (firstchar.ch == '-' || firstchar.ch == '+') {
	start.num = start.num + 1;
	count.num = count.num - 1;
	if (count.num == 0)
	    signal(ERR_bad_format);
    }
    else
	firstchar.ch = '+';

    index.num = start.num;
    for (i = 0; i < count.num; ++i) {
	err = stringOPfetch(s, index, &thischar);
	CLU_NOREF(err);

	if (thischar.ch >= '0' && thischar.ch <= '9') {
	    total = total * 10 - (thischar.ch - '0');
	    if (total > 0)
		signal(ERR_overflow);
	    index.num += 1;
	}
	else
	    signal(ERR_bad_format);
    }

    if (firstchar.ch == '+') {
	if (total == intOPleastint)
	    signal(ERR_overflow);
	total = -total;
    }

    ans->num = total;
    signal(ERR_ok);
}


errcode
intOPunparse(CLUREF i, CLUREF *ans)
{
    CLUREF beg, len;
    char buf[intOPmaxdigits+1]; 
    char sign;
    bool least = false;
    int ind;
    int first = 0;
    int last = intOPmaxdigits;
    char digit;
    errcode err;

    if (i.num == intOPleastint) {
	++i.num;
	least = true;
    }

    sign = '+';
    if (i.num < 0) {
	sign = '-';
	i.num = -i.num;
    }

    for (ind = last; ind >= first; --ind) {
	digit = i.num % 10;
	i.num = i.num/10;
	if (least == true) {
	    ++digit;
	    least = false;
	    if (digit == 10) {
		digit = 0;
		++i.num;
	    }
	}
	digit += '0';
	buf[ind] = digit;
	if (i.num == 0) {
	    --ind;
	    break;
	}
    }

    if (sign == '-') {
	buf[ind] = sign;
	--ind;
    }

    ++ind;
    beg.num = ind + 1;
    len.num = last - ind + 1;
    err = stringOPcons(buf, beg, len, ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
intOPlt(CLUREF i1, CLUREF i2, CLUREF *ans)
{
    ans->tf = false;
    if (i1.num < i2.num)
	ans->tf = true;
    signal(ERR_ok);
}


errcode
intOPle(CLUREF i1, CLUREF i2, CLUREF *ans)
{
    ans->tf = false;
    if (i1.num <= i2.num)
	ans->tf = true;
    signal(ERR_ok);
}


errcode
intOPgt(CLUREF i1, CLUREF i2, CLUREF *ans)
{
    ans->tf = false;
    if (i1.num > i2.num)
	ans->tf = true;
    signal(ERR_ok);
}


errcode
intOPge(CLUREF i1, CLUREF i2, CLUREF *ans)
{
    ans->tf = false;
    if (i1.num >= i2.num)
	ans->tf = true;
    signal(ERR_ok);
}


errcode
intOPequal(CLUREF i1, CLUREF i2, CLUREF *ans)
{
    ans->tf = false;
    if (i1.num == i2.num)
	ans->tf = true;
    signal(ERR_ok);
}


errcode
intOPsimilar(CLUREF i1, CLUREF i2, CLUREF *ans)
{
    ans->tf = false;
    if (i1.num == i2.num)
	ans->tf = true;
    signal(ERR_ok);
}


errcode
intOPcopy(CLUREF i, CLUREF *ans)
{
    ans->num = i.num;
    signal(ERR_ok);
}


errcode
intOPdebug_print(CLUREF i, CLUREF pst)
{
    errcode err;

    err = intOPprint(i, pst);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
intOPprint(CLUREF i, CLUREF pst)
{
    errcode err;

    bool positive;
    long temp, j, k;
    char digits[20];
    CLUREF ch, ans;

    temp = i.num;
    if (i.num < 0 ) {
	positive = false;
	temp = -i.num;
    }
    else
	positive = true;

    for (j = 0 ; ; ++j) {
	digits[j] = temp % 10;
	temp = temp / 10;
	if (temp == 0)
	    break;
    }

    if (positive == false) {
	ch.ch = '-';
	err = pstreamOPtextc(pst, ch, &ans);
	if (err != ERR_ok)
	    resignal(err);
    }

    for (k = j; k > -1 ; --k) {
	ch.ch = digits[k] + '0';
	err = pstreamOPtextc(pst, ch, &ans);
	if (err != ERR_ok)
	    resignal(err);
    }

    signal(ERR_ok);
}


errcode
intOPencode(CLUREF i, CLUREF ist)
{
    errcode err;

    err = istreamOPputi(ist, i);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
intOPdecode(CLUREF ist, CLUREF *ans)
{
    errcode err;

    err = istreamOPgeti(ist, ans);
    if (err == ERR_not_possible || err == ERR_end_of_file)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
intOPfrom_to_by(CLUREF from, CLUREF to, CLUREF by,
	     errcode (*iterbod)(), void *user_locals, errcode *ecode2)
{
    errcode err;
    CLUREF iv_1;

    if (from.num > to.num && by.num > 0)
	signal(ERR_ok);
    if (from.num < to.num && by.num < 0)
	signal(ERR_ok);

    iv_1 = from;
    while (true) {
	err = (*iterbod)(iv_1, user_locals, ecode2);
	if (err == ERR_ok) {
	    iv_1.num += by.num;
	    if (by.num >= 0 && iv_1.num <= to.num)
		continue;
	    if (by.num >= 0 && iv_1.num > to.num)
		signal(ERR_ok);
	    if (by.num < 0 && iv_1.num >= to.num)
		continue;
	    if (by.num < 0 && iv_1.num < to.num)
		signal(ERR_ok);
	}

	if (err == ERR_iterbodyreturn) signal(err);
	/* 9/9/93 dwc: just propagate break, do not convert to ok */
	if (err == ERR_break) signal(ERR_break);
	if (err == ERR_iterbodyexit) signal(err);
	if (err == ERR_iterbodysignal) 	signal(err);
	if (err == ERR_iteriterbodysignal) signal(err);
	if (err == ERR_iteriterbodyexit) signal(err);
	if (err == ERR_iteriterbodyreturn) signal(err);
    }
}


errcode
intOPfrom_to(CLUREF from, CLUREF to,
	     errcode (*iterbod)(), void *user_locals, errcode *ecode2)
{
    errcode err;
    CLUREF iv_1;

    if (from.num > to.num)
	signal(ERR_ok);

    iv_1 = from;
    while (true) {
	err = (*iterbod)(iv_1, user_locals, ecode2);
	if (err == ERR_ok) {
	    iv_1.num += 1;
	    if (iv_1.num <= to.num)
		continue;
	    if (iv_1.num > to.num)
		signal(ERR_ok);
	}

	if (err == ERR_iterbodyreturn) signal(err);
	/* 9/9/93 dwc: just propagate break, do not convert to ok */
	if (err == ERR_break) signal(ERR_break);
	if (err == ERR_iterbodyexit) signal(err);
	if (err == ERR_iterbodysignal) signal(err);
	if (err == ERR_iteriterbodysignal) signal(err);
	if (err == ERR_iteriterbodyexit) signal(err);
	if (err == ERR_iteriterbodyreturn) signal(err);
    }
}


errcode
intOP_gcd(CLUREF i, CLUREF tab, CLUREF *ans)
{
    CLU_NOREF(i);
    CLU_NOREF(tab);

    ans->num = -1;
    signal(ERR_ok);
}



OWN_ptr int_own_init = { .init_flag = 1 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &int_own_init,			\
    .op_owns = &int_own_init,			\
}

static CLU_proc int_oe_equal = CLU_proc_INIT(intOPequal);
static CLU_proc int_oe_similar = CLU_proc_INIT(intOPsimilar);
static CLU_proc int_oe_copy = CLU_proc_INIT(intOPcopy);
static CLU_proc int_oe_print = CLU_proc_INIT(intOPprint );
static CLU_proc int_oe_encode = CLU_proc_INIT(intOPencode);
static CLU_proc int_oe_decode = CLU_proc_INIT(intOPdecode);
static CLU_proc int_oe__gcd = CLU_proc_INIT(intOP_gcd);
static CLU_proc int_oe_debug_print = CLU_proc_INIT(intOPdebug_print);

static CLU_proc int_oe_add = CLU_proc_INIT(intOPadd);
static CLU_proc int_oe_sub = CLU_proc_INIT(intOPsub);
static CLU_proc int_oe_mul = CLU_proc_INIT(intOPmul);
static CLU_proc int_oe_minus = CLU_proc_INIT(intOPminus);
static CLU_proc int_oe_div = CLU_proc_INIT(intOPdiv);
static CLU_proc int_oe_power = CLU_proc_INIT(intOPpower);
static CLU_proc int_oe_mod = CLU_proc_INIT(intOPmod);
static CLU_proc int_oe_abs = CLU_proc_INIT(intOPabs);
static CLU_proc int_oe_min = CLU_proc_INIT(intOPmin);
static CLU_proc int_oe_max = CLU_proc_INIT(intOPmax);
static CLU_proc int_oe_unparse = CLU_proc_INIT(intOPunparse);
static CLU_proc int_oe_parse = CLU_proc_INIT(intOPparse);
static CLU_proc int_oe_lt = CLU_proc_INIT(intOPlt);
static CLU_proc int_oe_le = CLU_proc_INIT(intOPle);
static CLU_proc int_oe_gt = CLU_proc_INIT(intOPgt);
static CLU_proc int_oe_ge = CLU_proc_INIT(intOPge);

static CLU_proc int_oe_from_to = CLU_proc_INIT(intOPfrom_to);
static CLU_proc int_oe_from_to_by = CLU_proc_INIT(intOPfrom_to_by);


static struct /* OPS */ {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[26];
} int_ops_actual = {
    26,
    &int_own_init,
    &int_own_init,
    {
	{ &int_oe_equal, "equal" },
	{ &int_oe_similar, "similar" },
	{ &int_oe_copy, "copy" },
	{ &int_oe_print, "print" },
	{ &int_oe_encode, "encode" },
	{ &int_oe_decode, "decode" },
	{ &int_oe__gcd, "_gcd" },
	{ &int_oe_debug_print, "debug_print" },

	{ &int_oe_add, "add" },
	{ &int_oe_sub, "sub" },
	{ &int_oe_mul, "mul" },
	{ &int_oe_minus, "minus" },
	{ &int_oe_div, "div" },
	{ &int_oe_power, "power" },
	{ &int_oe_mod, "mod" },
	{ &int_oe_abs, "abs" },
	{ &int_oe_min, "min" },
	{ &int_oe_max, "max" },
	{ &int_oe_parse, "parse" },
	{ &int_oe_unparse, "unparse" },
	{ &int_oe_lt, "lt" },
	{ &int_oe_le, "le" },
	{ &int_oe_gt, "gt" },
	{ &int_oe_ge, "ge" },

	{ &int_oe_from_to, "from_to" },
	{ &int_oe_from_to_by, "from_to_by" },
    }
};

struct OPS *int_ops = (struct OPS *)&int_ops_actual;
