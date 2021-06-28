/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_change_owner		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>
#include <unistd.h>

errcode file_nameOPunparse(CLUREF x, CLUREF *ret_1);
errcode file_name_fill(CLUREF fn, CLUREF dsuffix, CLUREF *ret_1);



errcode
_change_owner(CLUREF fn, CLUREF userid, CLUREF groupid)
{
    errcode err;
    int status;

    CLUREF newfn;
    err = file_name_fill(fn, CLU_empty_string, &newfn);
    if (err != ERR_ok)
	goto ex_0;

    CLUREF name;
    err = file_nameOPunparse(newfn, &name);
    if (err != ERR_ok)
	goto ex_0;

    status = chown(name.str->data, userid.num, groupid.num);
    if (status != 0) {
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
