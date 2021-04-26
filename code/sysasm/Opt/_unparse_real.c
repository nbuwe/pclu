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

errcode stringOPcons(const char *s, CLUREF start, CLUREF len, CLUREF *ans);


/*
 * _unparse_real = proc (x: real) returns (bool, _bytevec, int)
 */
errcode
_unparse_real(CLUREF r, CLUREF *ans1, CLUREF *ans2, CLUREF *ans3)
{
    errcode err;
    int uerr;
    char temp[100];
    CLUREF minus, exp, temp2, size;
    float mant;

    if (r.real == 0.0) {
	err = stringOPcons("0", CLU_1, CLU_1, &temp2);
	ans1->tf = false;
	ans2->str = temp2.str;
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

    exp.num = 0;
    mant = r.real;
    while (mant >= 1.0) {
	mant = mant / 10.0;
	exp.num += 1;
    }
    while (mant < 0.1) {
	mant = mant * 10.0;
	exp.num -= 1;
    }

    uerr = sprintf(temp, "%11.9f", (double)mant);
    if (uerr == -1)
	signal(ERR_bad_format);

    size.num = strlen(temp) - 2;
    err = stringOPcons(temp, CLU_3, size, &temp2);
    if (err != ERR_ok)
	resignal(err);

    ans1->tf = minus.tf;
    ans2->str = temp2.str;
    ans3->num = exp.num;
    signal(ERR_ok);
}
