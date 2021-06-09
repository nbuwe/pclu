/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			_set_alarm		*/
/*						*/

#include <signal.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <sys/time.h>
#include <errno.h>

static void CLU_alarm(int);

static volatile bool itimer_flag = false;


errcode
_set_alarm(CLUREF secs, CLUREF *ans)
{
    int uerr;
    char *addr;
    errcode err;
    CLUREF temp;
    struct sigaction vec;
    struct itimerval value;
    int which;

    if (secs.num > 0) {
	vec.sa_handler = clu_alarm;
	sigfillset(&vec.sa_mask);
	vec.sa_flags = 1;
	uerr = sigaction(SIGALRM, &vec, NULL);
    }

    which = ITIMER_REAL;
    value.it_interval.tv_sec = 0;
    value.it_interval.tv_usec = 0;
    value.it_value.tv_sec = secs.num;
    value.it_value.tv_usec = 0;

    ans->tf = itimer_flag;
    itimer_flag = false;

    uerr = setitimer(which, &value, 0);
    signal(ERR_ok);
}


static void
CLU_alarm(int sig)
{
    itimer_flag = true;
}
