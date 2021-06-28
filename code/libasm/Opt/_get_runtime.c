/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_get_runtime		*/
/*						*/

#include <sys/time.h>
#include <sys/resource.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>
#include <stdint.h>


errcode
_get_runtime(CLUREF *sec, CLUREF *msec, CLUREF *usec)
{
    int status;

    struct rusage rusage;
    status = getrusage(RUSAGE_SELF, &rusage);
    if (status != 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    uint_fast32_t micros = rusage.ru_utime.tv_usec	/* user */
			 + rusage.ru_stime.tv_usec;	/* system */

    usec->num = micros % 1000;
    uint_fast32_t carry = micros / (1000 * 1000);	/* seconds */

    msec->num = (micros / 1000) - (carry * 1000);

    sec->num = rusage.ru_utime.tv_sec		/* user */
	     + rusage.ru_stime.tv_sec		/* system */
	     + carry;				/* from micros sum */

    signal(ERR_ok);
}
