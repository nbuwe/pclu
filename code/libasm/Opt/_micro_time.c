/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_micro_time		*/
/*						*/
/*	returns microseconds since 1970 GMT	*/
/*		low 32 bits only		*/
/*						*/

#include <sys/time.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdint.h>


/*
 * Return real time in microseconds since unknown event in past.
 */
errcode
_micro_time(CLUREF *ans)
{
    struct timeval tp;
    gettimeofday(&tp, NULL);

    /* let it overflow: we're only interested in the lsb's */
    ans->num = ((uint64_t)tp.tv_sec * 1000 * 1000) + tp.tv_usec;
    signal(ERR_ok);
}
