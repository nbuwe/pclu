/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			delete_file		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>
#include <unistd.h>

extern errcode file_name_fill(CLUREF fn, CLUREF dsuffix, CLUREF *ret_1);
extern errcode file_nameOPunparse(CLUREF x, CLUREF *ret_1);


errcode
delete_file(CLUREF fn)
{
    errcode err;
    int status;

    CLUREF newfn;
    err = file_name_fill(fn, CLU_empty_string, &newfn);
    if (err != ERR_ok)
	resignal(err);

    CLUREF namestr;
    err = file_nameOPunparse(newfn, &namestr);
    if (err != ERR_ok)
	resignal(err);

    status = unlink(namestr.str->data);
    if (status != 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }
    signal(ERR_ok);
}
