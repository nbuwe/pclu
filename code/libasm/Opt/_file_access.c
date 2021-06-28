/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			_file_access		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>
#include <unistd.h>

errcode stringOPconcat(CLUREF s1, CLUREF s2, CLUREF *ans);
errcode working_dir(CLUREF *ret_1);



errcode
_file_access(CLUREF fs, CLUREF mode, CLUREF *ans)
{
    errcode err;
    int status;

    CLUREF name = fs;
    if (fs.str->data[0] != '/') {
	CLUREF wd;
	err = working_dir(&wd);
	if (err != ERR_ok)
	    goto ex_0;

	err = stringOPconcat(wd, fs, &name);
	if (err != ERR_ok)
	    goto ex_0;
    }

    status = access(name.str->data, mode.num);
    if (status == 0)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}
