/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_signal			*/
/*						*/

#ifdef LINUX
/*
 * Work around a bug in gc-7.x that defines GC_jmp_buf in gc_priv.h
 * instead of declaring it.  Make it work with -fno-common.
 */
#define GC_jmp_buf GC_jmp_buf_libasm__signal
#include <gc/private/gc_priv.h>
#endif

#include <signal.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>
#include <unistd.h>

#ifdef LINUX
#define gcflag GC_collection_in_progress()
#else
extern int gcflag;
#endif

errcode sequenceOPfill(CLUREF length, CLUREF x, CLUREF *ans);
#ifdef CLU_DEBUG_IMPL
extern errcode debugOPwhere_cmd(CLUREF args);
#undef _exit /* _OPexit */
#endif

typedef void (VPROC)();

void _signalOPhand(int sig);
int sigetmask(sigset_t *setp);
void sigfixmask(sigset_t *setp, int m);


static int _signalOPflags;
static int _signalOPholds;
static int _signalOPcnts[32];
static VPROC *_signalOPohands[32];
static int _signalOPomasks[32];
static int _signalOPostks[32];
static CLUREF _signalOPmsgs;



errcode
_signalOPset(CLUREF sig, CLUREF hold)
{
    int omask;
    struct sigaction vec, ovec;

    if (sig.num < 0 || sig.num > 32)
	signal(ERR_bad_code);

    if (!hold.tf) {
	vec.sa_handler = _signalOPhand;
	sigfixmask(&vec.sa_mask, 0xf8e70020);
	/* vec.sa_mask = 0xf8e70020; */
	vec.sa_flags = 0;
	/* vec.sa_flags = SA_STACK; */
	sigaction(sig.num, &vec, &ovec);
	if (~(_signalOPflags & (1 << (sig.num - 1)))) {
	    _signalOPflags |= 1 << (sig.num - 1); 
	    _signalOPohands[sig.num - 1] = ovec.sa_handler;
	    _signalOPomasks[sig.num - 1] = sigetmask(&ovec.sa_mask);
	    /* _signalOPomasks[sig.num - 1] = ovec.sa_mask; */
	    _signalOPostks[sig.num - 1] = ovec.sa_flags;
	}
	if (_signalOPholds & (1 << (sig.num - 1))) {
	    _signalOPholds &= ~(1 << (sig.num - 1));
	    omask = sigblock(0);
	    omask &= ~(1 << (sig.num - 1));
	    sigsetmask(omask);
	}
    }
    else {
	_signalOPholds |= (1 << (sig.num - 1));
	sigblock( 1 << (sig.num - 1) );
    }

    signal(ERR_ok);
}

void _signalOPhand(sig)
int sig;
{
#if 0
    printf("signal caught: %d\n", sig);
#endif
    _signalOPcnts[sig-1] += 1;
    if (gcflag)
	return;

    if (_signalOPmsgs.vec == NULL)
	return;

    CLUREF msgs = _signalOPmsgs;
    if (msgs.vec->data[sig - 1] != 0) {
	CLUREF str = { .num = msgs.vec->data[sig - 1] };
	write(1, str.str->data, str.str->size);
    }

#ifdef CLU_DEBUG_IMPL
    /* print backtrace on a fatal error */
    if (sig == SIGBUS || sig == SIGSEGV) {
	debugOPwhere_cmd(CLU_empty_string);
	_exit(-1);
    }
#endif

    return;
}


errcode
_signalOPunset(CLUREF sig)
{
    int omask;
    struct sigaction vec;

    if (sig.num < 0 || sig.num > 32)
	signal(ERR_bad_code);

    if (_signalOPflags & (1 << (sig.num - 1))) {
	_signalOPflags &= ~(1 << (sig.num - 1));
	vec.sa_handler = _signalOPohands[sig.num - 1];
	sigfixmask(&vec.sa_mask, _signalOPomasks[sig.num - 1]);
#if 0
	vec.sa_mask = _signalOPomasks[sig.num - 1];
#endif
	vec.sa_flags = _signalOPostks[sig.num - 1];
	sigaction(sig.num, &vec, 0);
    }

    if (_signalOPholds & (1 << (sig.num - 1))) {
	_signalOPholds &= ~(1 << (sig.num - 1));
	omask = sigblock(0);
	omask &= ~(1 << (sig.num - 1));
	sigsetmask(omask);
    }

    signal(ERR_ok);
}


errcode
_signalOPget(CLUREF sig, CLUREF *ans)
{
    if (sig.num < 0 || sig.num > 32)
	signal(ERR_bad_code);

    ans->num = _signalOPcnts[sig.num - 1];
    _signalOPcnts[sig.num - 1] = 0;
    signal(ERR_ok);
}


errcode
_signalOPset_message(CLUREF sig, CLUREF msg)
{
    errcode err;
    CLUREF msgs;

    if (sig.num < 0 || sig.num > 32)
	signal(ERR_bad_code);

    if (_signalOPmsgs.vec == NULL) {
	err = sequenceOPfill(CLU_32, CLU_0, &_signalOPmsgs);
	if (err != ERR_ok)
	    resignal(err);
    }

    msgs = _signalOPmsgs;
    msgs.vec->data[sig.num - 1] = msg.num;
    signal(ERR_ok);
}


errcode
_signalOPget_message(CLUREF sig, CLUREF *ans)
{
    CLUREF msgs;

    if (sig.num < 0 || sig.num > 32)
	signal(ERR_bad_code);

    msgs = _signalOPmsgs;
    if (_signalOPmsgs.vec == NULL || msgs.vec->data[sig.num - 1] == 0) {
	ans->vec = CLU_empty_string.vec;
	signal(ERR_ok);
    }

    ans->num = msgs.vec->data[sig.num - 1];
    signal(ERR_ok);
}


#if 0 && defined(CLU_DEBUG_IMPL)	/* disable for now */
errcode
_signalOPprint(void)
{
    if (_signalOPmsgs.vec == NULL) {
	write(1, "table empty\n", 12);
	return ERR_ok;
    }

    CLUREF msgs = _signalOPmsgs;
    for (int i = 0; i < 32; ++i) {
	if (msgs.vec->data[i] == 0) {
	    write(1, "slot empty\n", 11);
	}
	else {
	    write(1, "slot full\n", 10);
	}
    }
    return ERR_ok;
}
#endif	/* CLU_DEBUG_IMPL */


void
sigfixmask(sigset_t *setp, int m)
{
    sigemptyset(setp);
    for (int i = 0; i < 32; ++i) {
	unsigned int bit = 1u << i;
	if (m & bit)
	    sigaddset(setp, i+1);
    }
}


int
sigetmask(sigset_t *setp)
{
    int result = 0;
    for (int i = 1; i <= 32; ++i) {
	if (sigismember(setp, i))
	    result |= 1 << (i-1);
    }
    return result;
}
