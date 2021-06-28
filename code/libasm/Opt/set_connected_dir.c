/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			set_connected_dir	*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>
#include <unistd.h>

errcode _OPenviron(CLUREF name, CLUREF *ans);
errcode file_nameOPcreate(CLUREF dir, CLUREF name, CLUREF suffix, CLUREF other, CLUREF *ret_1);
errcode file_nameOPget_dir(CLUREF x, CLUREF *ret_1);
errcode file_name_fill(CLUREF fn, CLUREF dsuffix, CLUREF *ret_1);


/*
 * Change current directory.
 *
 * uwe: Strangely, connected_dir() getter is in sysasm, not here in
 * libasm, alongside the setter.
 */
errcode
set_connected_dir(CLUREF fs)
{
    errcode err;
    int status;

    CLUREF dirname;
    if (fs.str->size == 0) {
	CLUREF home;
	stringOPcons("HOME", CLU_1, CLU_4, &home);
	err = _environ(home, &dirname);
	if (err != ERR_ok)
	    goto ex_0;
    }
    else {
	CLUREF fname;
	err = file_nameOPcreate(fs,
				CLU_empty_string,
				CLU_empty_string,
				CLU_empty_string,
				&fname);
	if (err == ERR_bad_format)
	    signal(err);
	if (err != ERR_ok)
	    goto ex_0;

	err = file_name_fill(fname, CLU_empty_string, &fname);
	if (err != ERR_ok)
	    goto ex_0;

	err = file_nameOPget_dir(fname, &dirname);
	if (err != ERR_ok)
	    goto ex_0;
    }

    status = chdir(dirname.str->data);
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
