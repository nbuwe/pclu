/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			file_exists		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>
#include <unistd.h>

errcode file_nameOPunparse(CLUREF x, CLUREF *ret_1);
errcode file_name_fill(CLUREF fn, CLUREF dsuffix, CLUREF *ret_1);



errcode
file_exists(CLUREF fn, CLUREF *ans)
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

    /* For now, emulate Berkeley behavior: if name is empty
       access is ok: 3/24/94 dcurtis */
    if (name.str->data[0] == '\0') {
	ans->tf = true;
	signal(ERR_ok);
    }

    status = access(name.str->data, F_OK);
    if (status != 0) {
	if (errno == ENOENT || errno == ENOTDIR) {
	    ans->tf = false;
	    signal(ERR_ok);
	}
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    ans->tf = true;
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}
