/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_set_priority		*/
/*						*/

#include <sys/time.h>
#include <sys/resource.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>


errcode
_set_priority(CLUREF which, CLUREF who, CLUREF prio)
{
    int status;

    status = setpriority(which.num, who.num, prio.num);
    if (status < 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    signal(ERR_ok);
}
