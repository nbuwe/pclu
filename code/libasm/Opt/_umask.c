/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_umask			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <sys/types.h>
#include <sys/stat.h>



errcode
_umask(CLUREF mask, CLUREF *ans)
{
    mode_t omask = umask(mask.num); /* always succeeds */

    ans->num = omask;
    signal(ERR_ok);
}
