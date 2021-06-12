/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		Round a Real Number		*/
/* given a string representation of the mantissa, */
/*	 & number of desired digits		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"


errcode
_round_real(CLUREF digs, CLUREF num, CLUREF *ans1, CLUREF *ans2)
{
    if (num.num > 9) num.num = 9;
    if (num.num <= 0) num.num = 1;

    if (digs.str->data[num.num] >= '5') {
	bool done = false;
	for (int i = num.num - 1; i >= 0; --i) {
	    if (digs.str->data[i] == '9') {
		digs.str->data[i] = '0';
	    }
	    else {
		digs.str->data[i] = digs.str->data[i] + 1;
		done = true;
		break;
	    }
	}
	/* sic.  it's probably not the best variable name... */
	if (done == false) {
	    digs.str->data[0] = '1';
	    ans1->num = 1;
	    ans2->num = 1;
	    signal(ERR_ok);
	}
    }

    int nz = num.num;
    for (int i = num.num - 1; i >= 0; --i) {
	if (digs.str->data[i] != '0')
	    break;
	nz -= 1;
    }
    ans1->num = 0;
    ans2->num = nz;
    signal(ERR_ok);
}
