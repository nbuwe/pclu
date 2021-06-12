/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			now			*/
/*						*/

#include <sys/time.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"


errcode
now(CLUREF *ans)
{
    CLUREF temp;
    errcode err;
    int unix_err;
    struct timeval tp;
    struct timezone tzp;
    CLUREF left, right;

    unix_err = gettimeofday(&tp, &tzp);

    left.num = tp.tv_sec >> 16;
    right.num = tp.tv_sec & 0Xffff;
    err = _local_time(left, right, &temp);
    if (err != ERR_ok)
	resignal(err);

    ans->num = temp.num;
    signal(ERR_ok);
}
