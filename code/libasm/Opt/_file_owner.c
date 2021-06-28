/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			_file_owner		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <sys/types.h>
#include <sys/stat.h>

#include <errno.h>

errcode file_nameOPunparse(CLUREF x, CLUREF *ret_1);
errcode file_name_fill(CLUREF fn, CLUREF dsuffix, CLUREF *ret_1);



errcode
_file_owner(CLUREF fn, CLUREF *ans1, CLUREF *ans2)
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

    struct stat st;
    status = stat(name.str->data, &st);
    if (status != 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    ans1->num = st.st_uid;
    ans2->num = st.st_gid;
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}
