/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_local_time		*/
/*						*/

#include <time.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>


errcode
_local_time(CLUREF left, CLUREF right, CLUREF *ans)
{
    errcode err;

    /*
     * XXX: TODO: this days we should worry about 64-bit time_t on
     * 32-bit hosts, not about 32-bit time_t on 16-bit hosts.
     */
    time_t clock = (left.num << 16) + right.num;

    struct tm *tm = localtime(&clock);
    if (tm == NULL) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    CLUREF day, mon, year, hour, min, sec;
    day.num = tm->tm_mday;
    mon.num = tm->tm_mon + 1;
    year.num = tm->tm_year + 1900;
    hour.num = tm->tm_hour;
    min.num = tm->tm_min;
    sec.num = tm->tm_sec;

    CLUREF temp;
    err = dateOPcreate(day, mon, year, hour, min, sec, &temp);
    if (err != ERR_ok)
	resignal(err);

    *ans = temp;
    signal(ERR_ok);
}
