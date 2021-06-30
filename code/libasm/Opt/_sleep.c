/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_sleep			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <time.h>



errcode
_sleep(CLUREF millis)
{
    int status;

    if (millis.num == 0)
	signal(ERR_ok);

#if 0				/* not specd to signal this */
    if (millis.num < 0)
	signal(ERR_negative_time);
#endif

    struct timespec req;
    req.tv_sec = millis.num / 1000;
    req.tv_nsec = (millis.num % 1000) * 1000 * 1000;

    struct timespec rem;
    status = nanosleep(&req, &rem);
#if 0				/* not specd to signal this */
    if (status < 0) {		/* interrupted (remaining: int)  */
	elist[0].num = rem.tv_sec * 1000 + rem.tv_nsec / (1000 * 1000);
	signal("ERR_interrupted");
    }
#else
    CLU_NOREF(status);
#endif

    signal(ERR_ok);
}
