/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_bin_id			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <sys/time.h>


errcode
_bin_id(CLUREF *ans)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    ans->num = tv.tv_sec;
    signal(ERR_ok);
}
