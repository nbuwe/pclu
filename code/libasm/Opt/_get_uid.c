/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_get_uid		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <unistd.h>


/*
 * Returns real user ID, effective user ID.
 */
errcode
_get_uid(CLUREF *uid, CLUREF *euid)
{
    uid->num = getuid();
    euid->num = geteuid();
    signal(ERR_ok);
}
