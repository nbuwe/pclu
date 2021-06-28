/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			file_date		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <sys/types.h>
#include <sys/stat.h>

#include <errno.h>

errcode file_nameOPunparse(CLUREF x, CLUREF *ret_1);
errcode file_name_fill(CLUREF fn, CLUREF dsuffix, CLUREF *ret_1);
errcode _local_time(CLUREF left, CLUREF right, CLUREF *ans);



errcode
file_date(CLUREF fn, CLUREF read, CLUREF *ans)
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

    time_t time = read.tf ? st.st_atime : st.st_mtime;

    /*
     * XXX: This strange API pattern is probably a leftover from
     * tagged ints that were, consequently, less than 32-bit.
     */
    err = _local_time(CLUREF_make_num(time >> 16),
		      CLUREF_make_num(time & 0xffff),
		      ans);
    if (err != ERR_ok)
	goto ex_0;

    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}
