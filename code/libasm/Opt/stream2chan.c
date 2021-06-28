/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			stream2chan		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

errcode streamOPget_chan(CLUREF st, CLUREF *ret_1);


errcode
stream2chan(CLUREF st, CLUREF *ans)
{
    errcode err;

    CLUREF chan;
    err = streamOPget_chan(st, &chan);
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
