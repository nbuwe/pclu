/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			_select			*/
/*						*/

/* 12/16/94: dwc: made types compatible: os supports 256 fds, but
			clu still supports only 32 fds, but code
			now type-checks cleanly
*/

/* 2/26/01: dwc: rewritten again --- not tested... */

#include <sys/time.h>
#include <errno.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

errcode
_select(CLUREF cnt, CLUREF reads, CLUREF writes, CLUREF excepts, CLUREF millis,
	CLUREF *ans1, CLUREF *ans2, CLUREF *ans3, CLUREF *ans4)
{
    int nfound;
    struct timeval timeout;
    fd_set rwreads;
    fd_set rwwrites;
    fd_set rwexcepts;
    int bit;
    int i;

    FD_ZERO(&rwreads);
    FD_ZERO(&rwwrites);
    FD_ZERO(&rwexcepts);

    bit = 1;
    for (i = 0 ; i < 32 ; ++i) {
	if (reads.num & bit)
	    FD_SET(i, &rwreads);
	bit = bit << 1;
    }

    bit = 1;
    for (i = 0 ; i < 32 ; ++i) {
	if (writes.num & bit)
	    FD_SET(i, &rwwrites);
	bit = bit << 1;
    }

    bit = 1;
    for (i = 0 ; i < 32 ; ++i) {
	if (excepts.num & bit)
	    FD_SET(i, &rwexcepts);
	bit = bit << 1;
    }

    timeout.tv_sec = millis.num / 1000;
    timeout.tv_usec = millis.num % 1000;

    nfound = select(cnt.num, &rwreads, &rwwrites, &rwexcepts, &timeout);

    if (nfound >= 0) {
	ans1->num = nfound;

	ans2->num = 0;
	bit = 1;
	for (i = 0 ; i < 32 ; ++i) {
	    if (FD_ISSET(i, &rwreads))
		ans2->num |= bit;
	    bit = bit << 1;
	}

	ans3->num = 0;
	bit = 1;
	for (i = 0 ; i < 32 ; ++i) {
	    if (FD_ISSET(i, &rwwrites))
		ans3->num |= bit;
	    bit = bit << 1;
	}

	ans4->num = 0;
	bit = 1;
	for (i = 0 ; i < 32 ; ++i) {
	    if (FD_ISSET(i, &rwexcepts))
		ans4->num |= bit;
	    bit = bit << 1;
	}

	signal(ERR_ok);
    }
    if (nfound == -1 && errno == EINTR) {
	ans1->num = 0;
	ans2->num = 0;
	ans3->num = 0;
	ans4->num = 0;
	signal(ERR_ok);
    }

    elist[0] = _unix_erstr(errno);
    signal(ERR_not_possible);
}
