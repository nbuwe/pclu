/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_ioctl			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <sys/ioctl.h>
#include <errno.h>


/*
 * _ioctl = proc [T: type] (fdesc, reqh, reql: int, argp: T, disp: int)
 *            signals (not_possible(string))
 *     % issue REQ ioctl on given file descriptor with given argument(s)
 *     % REQ is given in halves, high and low
 *     % if ARGP is not an int, DISP should generally be 4
 *   end _ioctl
 *
 * uwe: It's not entirely clear to me how this is supposed to be used.
 *
 * The original obviously never worked anyway b/c it used H << 16 + L
 * to reassemble the 32-bit request, which means H << (16 + L) - not
 * (H << 16) + L it intends to say.
 *
 * Also this file doesn't provide _ioctl_of_t_reqs and _ioctl_ownreqs,
 * so the code calling _ioctl[]() just wouldn't link.
 */
errcode
_ioctl(CLUREF fdesc, CLUREF reqh, CLUREF reql, CLUREF argp, CLUREF disp)
{
    int status;

    unsigned long req = (reqh.num << 16) | reql.num;
    status = ioctl(fdesc.num, req, argp.vec->data[disp.num]);
    if (status != 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }
    signal(ERR_ok);
}
