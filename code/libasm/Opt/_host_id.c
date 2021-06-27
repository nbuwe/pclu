/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_host_id		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <unistd.h>


errcode
_host_id(CLUREF *ans1, CLUREF *ans2)
{
    long hostid = gethostid();
    ans1->num = hostid >> 16;	/* XXX */
    ans2->num = hostid & 0xffff;
    signal(ERR_ok);
}
