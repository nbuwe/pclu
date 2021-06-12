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
    errcode err;
    CLUREF temp1, temp2;
    int nz, i, carry;
    bool done;

    if (num.num > 9) num.num = 9;
    if (num.num <= 0) num.num = 1;
    done = false;

    if (digs.str->data[num.num] >= '5') {
	for (i = num.num - 1; i >= 0; --i) {
	    if (digs.str->data[i] == '9') {
		digs.str->data[i] = '0';
	    }
	    else {
		digs.str->data[i] = digs.str->data[i] + 1;
		done = true;
		break;
	    }
	}
	if (done == false) {
	    digs.str->data[0] = '1';
	    ans1->num = 1;
	    ans2->num = 1;
	    signal(ERR_ok);
	}
    }

    nz = num.num;
    for (i = num.num - 1; i >= 0; --i) {
	if (digs.str->data[i] != '0')
	    break;
	nz -= 1;
    }
    ans1->num = 0;
    ans2->num = nz;
    signal(ERR_ok);
}
