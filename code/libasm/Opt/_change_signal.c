/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_change_signal		*/
/*						*/

#include <signal.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>


errcode
_change_signal(CLUREF sig, CLUREF label, CLUREF *ans)
{
    int err;
    struct sigaction vec, ovec;

    vec.sa_handler = (void (*)())label.ref;
#if defined(LINUX) && !defined(OLD_LINUX)
    vec.sa_mask.__val[0] = 0xff7bf0e0;
#else
    vec.sa_mask = 0xff7bf0e0;
#endif
    vec.sa_flags = 1;

    err = sigaction(sig.num, &vec, &ovec);
    if (err != 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }
    ans->num = (int)ovec.sa_handler;
    signal(ERR_ok);
}
