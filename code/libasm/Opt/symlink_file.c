/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			symlink_file		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>
#include <unistd.h>

errcode file_nameOPunparse(CLUREF x, CLUREF *ret_1);
errcode file_name_fill(CLUREF fn, CLUREF dsuffix, CLUREF *ret_1);


errcode
symlink_file(CLUREF ofn, CLUREF nfn)
{
    errcode err;
    int uerr;
    CLUREF wd, oname, nname, home;

    err = file_name_fill(ofn, CLU_empty_string, &oname);
    if (err != ERR_ok)
	resignal(err);

    err = file_nameOPunparse(oname, &oname);
    if (err != ERR_ok)
	resignal(err);

    err = file_name_fill(nfn, CLU_empty_string, &nname);
    if (err != ERR_ok)
	resignal(err);

    err = file_nameOPunparse(nname, &nname);
    if (err != ERR_ok)
	resignal(err);

    uerr = symlink(oname.ref, nname.ref);
    if (uerr == 0) {
	signal(ERR_ok);
    }
    elist[0] = _unix_erstr(errno);
    signal(ERR_not_possible);
}
