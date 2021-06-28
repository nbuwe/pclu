/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_get_priority		*/
/*						*/

#include <sys/time.h>
#include <sys/resource.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>


errcode
_get_priority(CLUREF which, CLUREF who, CLUREF *ans)
{
    int prio;

    errno = 0;		  /* prio = -1 is a legitimate return value */
    prio = getpriority(which.num, who.num);
    if (errno != 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    ans->num = prio;
    signal(ERR_ok);
}
