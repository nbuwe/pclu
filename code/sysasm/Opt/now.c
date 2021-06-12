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

#include <errno.h>

extern errcode _local_time(CLUREF left, CLUREF right, CLUREF *ans);


errcode
now(CLUREF *ans)
{
    errcode err;
    int status;

    struct timeval tv;
    status = gettimeofday(&tv, NULL);
    if (status != 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_failure);
    }

    CLUREF date;
    CLUREF left, right;
    left.num = tv.tv_sec >> 16;
    right.num = tv.tv_sec & 0xffff;
    err = _local_time(left, right, &date);
    if (err != ERR_ok)
	resignal(err);

    *ans = date;
    signal(ERR_ok);
}
