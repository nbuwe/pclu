/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			link_file		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>
#include <unistd.h>

errcode file_nameOPunparse(CLUREF x, CLUREF *ret_1);
errcode file_name_fill(CLUREF fn, CLUREF dsuffix, CLUREF *ret_1);


errcode
link_file(CLUREF ofn, CLUREF nfn)
{
    errcode err;
    int status;

    CLUREF oname;
    err = file_name_fill(ofn, CLU_empty_string, &oname);
    if (err != ERR_ok)
	goto ex_0;

    err = file_nameOPunparse(oname, &oname);
    if (err != ERR_ok)
	goto ex_0;

    CLUREF nname;
    err = file_name_fill(nfn, CLU_empty_string, &nname);
    if (err != ERR_ok)
	goto ex_0;

    err = file_nameOPunparse(nname, &nname);
    if (err != ERR_ok)
	goto ex_0;

    status = link(oname.ref, nname.ref);
    if (status == 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}
