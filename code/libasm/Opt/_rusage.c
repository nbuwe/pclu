/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_rusage			*/
/*						*/

#include <sys/time.h>
#include <sys/resource.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>


errcode
_rusage(CLUREF who, CLUREF buf)
{
    if ((size_t)buf.str->size < sizeof(struct rusage))
	signal(ERR_bounds);

    int status = getrusage(who.num, (struct rusage *)buf.str->data);
    if (status != 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    signal(ERR_ok);
}
