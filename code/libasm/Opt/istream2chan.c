/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			istream2chan		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

errcode istreamOPget_chan(CLUREF ist, CLUREF *ret_1);


errcode
istream2chan(CLUREF st, CLUREF *ans)
{
    errcode err;

    CLUREF chan;
    err = istreamOPget_chan(st, &chan);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	goto ex_0;

    *ans = chan;
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}
