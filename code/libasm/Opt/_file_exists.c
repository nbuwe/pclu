/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			_file_exists		*/
/*						*/

#include <sys/types.h>
#include <sys/stat.h>

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>
#include <stdint.h>

errcode stringOPconcat(CLUREF s1, CLUREF s2, CLUREF *ans);
errcode working_dir(CLUREF *ret_1);



errcode
_file_exists(CLUREF fs, CLUREF ftype, CLUREF *ans)
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

    struct stat st;
    status = stat(name.str->data, &st);
    if (status != 0) {
	if (errno == ENOENT || errno == ENOTDIR) {
	    ans->tf = false;
	    signal(ERR_ok);
	}
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    if ((st.st_mode & S_IFMT) >> 12 == (uintptr_t)ftype.num)
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
