/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		Unparse a Real Number		*/
/* given a string representation of the mantissa, */
/*	 & number of desired digits		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdio.h>
#include <string.h>

errcode stringOPcons(const char *buf, CLUREF start, CLUREF len, CLUREF *ans);


/*
 * _unparse_real = proc (x: real) returns (bool, _bytevec, int)
 */
errcode
_unparse_real(CLUREF r, CLUREF *ans1, CLUREF *ans2, CLUREF *ans3)
{
    CLUREF minus, digits, exp;	/* return values */
    errcode err;

    if (r.real == 0.0) {
	err = stringOPcons("0", CLU_1, CLU_1, &digits);
	if (err != ERR_ok)
	    resignal(err);

	ans1->tf = false;
	ans2->str = digits.str;
	ans3->num = 0;
	signal(ERR_ok);
    }

    if (r.real < 0.0) {
	minus.tf = true;
	r.real = -r.real;
    }
    else {
	minus.tf = false;
    }

    float mant = r.real;
    exp.num = 0;
    while (mant >= 1.0) {
	mant = mant / 10.0;
	++exp.num;
    }
    while (mant < 0.1) {
	mant = mant * 10.0;
	--exp.num;
    }

    /* print the mantissa as 9 digits after the decimal dot */
    char buf[32];
    int nchars = snprintf(buf, sizeof(buf), "%11.9f", (double)mant);
    if (nchars < 0)
	signal(ERR_bad_format);

    /* skip the leading "0." and get the mantissa digits */
    size_t len = strlen(buf) - 2;
    err = stringOPcons(buf, CLU_3, CLUREF_make_num(len), &digits);
    if (err != ERR_ok)
	resignal(err);

    ans1->tf = minus.tf;
    ans2->str = digits.str;
    ans3->num = exp.num;
    signal(ERR_ok);
}
