/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_get_gid		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <unistd.h>


/*
 * Returns real group ID, effective group ID.
 */
errcode
_get_gid(CLUREF *gid, CLUREF *egid)
{
    gid->num = getgid();
    egid->num = getegid();
    signal(ERR_ok);
}
