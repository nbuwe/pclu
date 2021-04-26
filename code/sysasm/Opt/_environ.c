/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		_ENVIRON			*/
/*	fetch value for environment variable	*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdlib.h>
#include <string.h>

errcode stringOPcons(const char *buf, CLUREF start, CLUREF len, CLUREF *ans);


/*
 * _environ = proc (name: string) returns (string) signals (not_found)
 *
 * pclu_sys.h renames _environ that the CLU compiler emits for it to
 * _OPenviron to avoid (potential) name clash.
 */
errcode
_OPenviron(CLUREF name, CLUREF *ans)
{
    CLUREF temp;
    errcode err;

    const char *value = getenv(name.str->data);
    if (value == NULL)
	signal(ERR_not_found);

    size_t len = strlen(value);
    err = stringOPcons(value, CLU_1, CLUREF_make_num(len), &temp);
    if (err != ERR_ok)
	resignal(err);

    ans->str = temp.str;
    signal(ERR_ok);
}
