/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			rename_file		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>
#include <stdio.h>

extern errcode file_name_fill(CLUREF fn, CLUREF dsuffix, CLUREF *ret_1);
extern errcode file_nameOPunparse(CLUREF x, CLUREF *ret_1);


errcode
rename_file(CLUREF ofn, CLUREF nfn)
{
    int status;
    errcode err;

    CLUREF onewfn;
    err = file_name_fill(ofn, CLU_empty_string, &onewfn);
    if (err != ERR_ok)
	resignal(err);

    CLUREF oname;
    err = file_nameOPunparse(onewfn, &oname);
    if (err != ERR_ok)
	resignal(err);

    CLUREF nnewfn;
    err = file_name_fill(nfn, CLU_empty_string, &nnewfn);
    if (err != ERR_ok)
	resignal(err);

    CLUREF nname;
    err = file_nameOPunparse(nnewfn, &nname);
    if (err != ERR_ok)
	resignal(err);

    status = rename(oname.str->data, nname.str->data);
    if (status != 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }
    signal(ERR_ok);
}
