/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_set_limit		*/
/*						*/

#include <sys/time.h>
#include <sys/resource.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>


errcode
_set_limit(CLUREF resource, CLUREF soft)
{
    struct rlimit rlimit;
    int status;

    status = getrlimit(resource.num, &rlimit);
    if (status != 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    rlimit.rlim_cur = soft.num;
    status = setrlimit(resource.num, &rlimit);
    if (status != 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    signal(ERR_ok);
}
