/* Copyright Massachusetts Institute of Technology 1990,1991 */

#include <signal.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <sys/types.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

errcode _fixup_file_name(CLUREF fn, CLUREF dirok, CLUREF *ret_1);
errcode _local_time(CLUREF left, CLUREF right, CLUREF *ans);
errcode boolOPprint(CLUREF b, CLUREF pst);
errcode file_nameOPparse(CLUREF s, CLUREF *ret_1);
errcode file_nameOPprint(CLUREF x, CLUREF ps);
errcode file_nameOPunparse(CLUREF x, CLUREF *ret_1);
errcode file_name_fill(CLUREF fn, CLUREF dsuffix, CLUREF *ret_1);
errcode intOPprint(CLUREF i, CLUREF pst);
errcode pstreamOPpause(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPstart(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPstop(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode pstreamOPtext(CLUREF ps, CLUREF s, CLUREF *ret_1);
errcode stringOPconcat(CLUREF s1, CLUREF s2, CLUREF *ans);
errcode stringOPcons(const char *buf, CLUREF start, CLUREF len, CLUREF *ans);
errcode stringOPsubstr(CLUREF s, CLUREF start, CLUREF len, CLUREF *ans);

void sigfixmask(sigset_t *setp, int m);


errcode _chanOP_open(CLUREF fn, CLUREF flags, CLUREF fmode, CLUREF *uchan);

extern int _chanOPtstop();
extern int _chanOPtdie();
extern errcode _chanOPOPset_tty();
extern errcode _chanOPOP_put_doit(bool lit, int fd, CLUREF bv, int low, int size);
extern errcode _chanOPOPreadit();

typedef struct {
    CLUREF fn;			/* file name */
    CLUREF rd;			/* read fd */
    CLUREF wr;			/* write fd */
    CLUREF typ;			/* type */
    CLUREF new;			/* new: discard on abort */
    CLUREF perm;		/* permanent */
} _chan;

/* _char::typ values */
#define tty 0
#define bty 1
#define nul 2
#define oth 3

#define SIGNAL_MASK 0xff7bf0e0

static long _chan_defmode;
long wrpipe = 0;
static long rdpipe = 0;
static _chan * _chan_pri = NULL;
static _chan * _chan_pro = NULL;
static _chan * _chan_ero = NULL;
static _chan * _chan_nul = NULL;
static struct termios isbuf;
static struct termios sbuf;

int speeds[16] = {50, 75, 110, 134, 150, 200, 300, 600, 1200, 1800, 2400, 4800,
		  9600, 19200, 38400};

/*
 * open = proc (fn: file_name, mode: string, fmode: int) returns (cvt)
 *                signals (not_possible(string))
 *
 * Version that takes named mode ("read", "write", ...)
 */
errcode
_chanOPopen(CLUREF fn, CLUREF mode, CLUREF fmode, CLUREF *uchan)
{
    CLUREF flags = CLUREF_make_num(-1);

    /* map to open(2) flags */
    const char *how = mode.str->data;
    if (!strcmp(how, "read"))
	flags.num = O_RDONLY;
    else if (!strcmp(how, "write"))
	flags.num = O_WRONLY | O_TRUNC | O_CREAT;
    else if (!strcmp(how, "append"))
	flags.num = O_WRONLY | O_APPEND | O_CREAT;
    else if (!strcmp(how, "random"))
	flags.num = O_RDWR | O_TRUNC | O_CREAT;
    else if (!strcmp(how, "modify"))
	flags.num = O_RDWR | O_CREAT;

    if (flags.num == -1) {
	elist[0] = illegal_access_mode_STRING;
	signal(ERR_not_possible);
    }

    /* and hand off */
    return _chanOP_open(fn, flags, fmode, uchan);
}


/*
 * _open = proc (fn: file_name, flags: int, fmode: int) returns (cvt)
 *                 signals (not_possible(string))
 *
 * Version that takes open(2) flags bitmask (O_RDONLY, ...)
 */
errcode
_chanOP_open(CLUREF fn, CLUREF flags, CLUREF fmode, CLUREF *uchan)
{
    CLUREF fullname;
    _chan *newch;
    CLUREF fname;
    int acc;
    int fd;
    errcode err;
    int current_mode;
    struct termios obuf;
    CLUREF temp_str;

    clu_alloc(sizeof(_chan), &newch);
    err = stringOPcons("", CLU_1, CLU_0, &temp_str);
    if (err != ERR_ok) goto def_err_hdlr;
    err = file_name_fill(fn, temp_str, &fullname);
    if (err != ERR_ok) goto def_err_hdlr;
    newch->fn = fullname;
    err = file_nameOPunparse(newch->fn, &fname);
    /* assume fname is zero terminated */
    newch->new.tf = false;
    if (flags.num & O_WRONLY || flags.num & O_RDWR) {
	newch->new.tf = true;
	if (flags.num & O_TRUNC || flags.num & O_CREAT) {
	    acc = access(fname.str->data, F_OK);
	    if (acc == 0) newch->new.tf = false;
	}
    }
    current_mode = 0666;
    if (_chan_defmode != 0) current_mode = _chan_defmode;
    if (fmode.num != 0) current_mode = fmode.num;
    fd = open(fname.str->data, flags.num, current_mode);
    if (fd < 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }
    newch->rd.num = -1;
    newch->wr.num = -1;
    if (flags.num & O_RDWR || (!flags.num & 1)) {
	newch->rd.num = fd;}
    if (flags.num & O_RDWR || flags.num & O_WRONLY) {
	newch->wr.num = fd;}
    newch->typ.num = oth;
    err = tcgetattr(fd, &obuf);
    if (err == 0) {
	newch->typ.num = tty;
	if (newch->rd.num == newch->wr.num) {
	    obuf.c_iflag |= ICRNL;
	    obuf.c_oflag |= OPOST + ONLCR;
	    obuf.c_lflag &= ~(ICANON + ECHO);
	    obuf.c_cc[VMIN] = 1;
	    obuf.c_cc[VTIME] = 0;
	    err = tcsetattr(fd, TCSANOW, &obuf);
	    if (err != 0) {
		close(fd);
		elist[0] = _unix_erstr(errno);
		signal(ERR_not_possible);
	    }
	}
    }
    err = _fixup_file_name(newch->fn, CLU_0, &fullname);
    if (err != ERR_ok) goto def_err_hdlr;
    newch->fn = fullname;
    uchan->ref = (char *)newch;
    signal(ERR_ok);
  def_err_hdlr:
    elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
}

errcode _chanOPpipe(ans1, ans2)
    CLUREF *ans1, *ans2;
{
    _chan *temp_chan1, *temp_chan2;
    int fildes[2];
    CLUREF temp_str, fname;
    int result;
    errcode err;

    err = stringOPcons("/dev/pipe", CLU_1, CLU_9, &temp_str);
    if (err != 0) goto def_err_hdlr;
    err = file_nameOPparse(temp_str, &fname);
    if (err != 0) goto def_err_hdlr;
    clu_alloc(sizeof(_chan), &temp_chan1);
    temp_chan1->fn.str = fname.str;
    temp_chan1->wr.num = -1;
    temp_chan1->typ.num = oth;
    clu_alloc(sizeof(_chan), &temp_chan2);
    temp_chan2->fn.str = fname.str;
    temp_chan2->rd.num = -1;
    temp_chan2->typ.num = oth;

    result = pipe(fildes);
    if (result == -1) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }
    temp_chan1->rd.num = fildes[0];
    temp_chan2->wr.num = fildes[1];
    ans1->ref = (char *) temp_chan1;
    ans2->ref = (char *) temp_chan2;
    signal(ERR_ok);
  def_err_hdlr:
    elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
}

errcode _chanOPsocket(family, socktype, protocol, ans)
    CLUREF family, socktype, protocol;
CLUREF *ans;
{
    _chan *temp_chan;
    CLUREF temp_str, fname;
    int result;
    errcode err;

    err = stringOPcons("/dev/socket", CLU_1, CLU_11, &temp_str);
    if (err != 0) goto def_err_hdlr;
    err = file_nameOPparse(temp_str, &fname);
    if (err != 0) goto def_err_hdlr;
    clu_alloc(sizeof(_chan), &temp_chan);
    temp_chan->fn.str = fname.str;
    temp_chan->typ.num = oth;

    result = socket(family.num, socktype.num, protocol.num);
    if (result == -1) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }
    temp_chan->rd.num = result;
    temp_chan->wr.num = result;
    ans->ref = (char *) temp_chan;
    signal(ERR_ok);
  def_err_hdlr:
    elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
}


errcode
_chanOPsocketpair(CLUREF domain, CLUREF socktype, CLUREF protocol,
		  CLUREF *ans1, CLUREF *ans2)
{
    _chan *temp_chan1, *temp_chan2;
    int fildes[2];
    CLUREF temp_str, fname;
    int result;
    errcode err;

    err = stringOPcons("/dev/socket", CLU_1, CLU_11, &temp_str);
    if (err != 0)
	goto def_err_hdlr;

    err = file_nameOPparse(temp_str, &fname);
    if (err != 0)
	goto def_err_hdlr;

    clu_alloc(sizeof(_chan), &temp_chan1);
    temp_chan1->fn.str = fname.str;
    temp_chan1->typ.num = oth;

    clu_alloc(sizeof(_chan), &temp_chan2);
    temp_chan2->fn.str = fname.str;
    temp_chan2->typ.num = oth;

    result = socketpair(domain.num, socktype.num, protocol.num, fildes);
    if (result == -1) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    temp_chan1->rd.num = fildes[0];
    temp_chan1->wr.num = fildes[0];

    temp_chan2->rd.num = fildes[1];
    temp_chan2->wr.num = fildes[1];

    ans1->ref = (char *)temp_chan1;
    ans2->ref = (char *)temp_chan2;
#if 0 /* XXX */
    signal(ERR_ok);
#endif

  def_err_hdlr:
    elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
}


errcode
_chanOPprimary_input(CLUREF *newchan)
{
    _chan *temp_chan;
    errcode err;
    CLUREF chanref;

    if (_chan_pri != NULL) {
	newchan->ref = (char *)_chan_pri;
	signal(ERR_ok);
    }

    clu_alloc(sizeof(_chan), &temp_chan);
    _chan_pri = temp_chan;
    _chan_pri->wr.num = -1;
    _chan_pri->rd.num = 0;

    chanref.ref = (char*)_chan_pri;
    err =  _chanOPOPset_tty(chanref, &chanref);
    if (err != ERR_ok)
	goto def_err_hdlr;

    newchan->ref = (char *)_chan_pri;
    signal(ERR_ok);

  def_err_hdlr:
    elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
}


errcode
_chanOPprimary_output(CLUREF *newchan)
{
    _chan * temp_chan;
    errcode err;
    CLUREF chanref;

    if (_chan_pro != NULL) {
	newchan->ref = (char *)_chan_pro;
	signal(ERR_ok);
    }

    clu_alloc(sizeof(_chan), &temp_chan);
    _chan_pro = temp_chan;
    _chan_pro->rd.num = -1;
    _chan_pro->wr.num = 1;

    chanref.ref = (char*)_chan_pro;
    err = _chanOPOPset_tty(chanref, &chanref);
    if (err != ERR_ok)
	goto def_err_hdlr;

    newchan->ref = (char *)_chan_pro;
    signal(ERR_ok);

  def_err_hdlr:
    elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
}


errcode
_chanOPerror_output(CLUREF *newchan)
{
    _chan * temp_chan;
    errcode err;
    CLUREF fname;
    CLUREF temp_str;

    if (_chan_ero != NULL) {
	newchan->ref = (char *)_chan_ero;
	signal(ERR_ok);
    }

    err = stringOPcons("/dev/e", CLU_1, CLU_6, &temp_str);
    if (err != 0)
	goto def_err_hdlr;

    err = file_nameOPparse(temp_str, &fname);
    if (err != 0)
	goto def_err_hdlr;

    clu_alloc(sizeof(_chan), &temp_chan);
    _chan_ero = temp_chan;
    _chan_ero->fn.str = fname.str;
    _chan_ero->rd.num = -1;
    _chan_ero->wr.num = 2;
    _chan_ero->typ.num = oth;
    _chan_ero->perm.tf = true;

    newchan->ref = (char *)_chan_ero;
    signal(ERR_ok);

  def_err_hdlr:
    elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
}


errcode
_chanOPnul(CLUREF *newchan)
{
    _chan * temp_chan;
    errcode err;
    CLUREF fname;
    CLUREF temp_str;
    int result;

    if (_chan_nul != NULL) {
	newchan->ref = (char *)_chan_nul;
	signal(ERR_ok);
    }

    result = open("/dev/null", O_RDWR, 0);
    if (result < 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_failure);
    }

    err = stringOPcons("/dev/null", CLU_1, CLU_9, &temp_str); /* MTV */
    if (err != 0)
	goto def_err_hdlr;

    err = file_nameOPparse(temp_str, &fname);
    if (err != 0)
	goto def_err_hdlr;

    clu_alloc(sizeof(_chan), &temp_chan);
    _chan_nul = temp_chan;
    _chan_nul->fn.str = fname.str;
    _chan_nul->rd.num = -1;
    _chan_nul->wr.num = result;
    _chan_nul->typ.num = nul;
    _chan_nul->perm.tf = true;

    newchan->ref = (char *)_chan_nul;
    signal(ERR_ok);

  def_err_hdlr:
    elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
}


errcode
_chanOPcontrol(CLUREF chref, CLUREF cmd, CLUREF arg, CLUREF *ans)
{
    int fd, result;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    if (cmd.num == 0) {
	elist[0] = cannot_duplicate__chan_STRING;
	signal(ERR_not_possible);
    }

    result = fcntl(fd, cmd.num, arg.num);
    if (result == -1) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    ans->num = result;
    signal(ERR_ok);
}


errcode
_chanOPlock(CLUREF chref, CLUREF op)
{
    int fd, result;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    result = flock(fd, op.num);
    if (result == -1) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    signal(ERR_ok);
}


errcode
_chanOPsync(CLUREF chref)
{
    int fd, result;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	signal(ERR_ok);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    result = fsync(fd);
    if (result == -1) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    signal(ERR_ok);
}


errcode
_chanOP_save_tty(void)
{
    int err;

    /*
     * added the following cbreak so that ctrl-c would not hang the shell
     * when running pclu from a makefile and using tcsh or sh.
     * sh still needs a reset.
     * 8/5/92 dcurtis
    */
    if (_chan_pri != NULL && _chan_pri->typ.num == tty && wrpipe <= 0) {
	err = tcgetattr(0, &isbuf);
	CLU_NOREF(err);		/* XXX */

	sbuf.c_lflag |= (ICANON + ECHO);
	tcsetattr(0, TCSANOW, &sbuf);
	printf("\n");
#if 0
	int zcnt = 0;
	ioctl(0, TIOCFLUSH, zcnt);
#endif
    }
    signal(ERR_ok);
}


errcode
_chanOP_restore_tty(/* void */)
{
    if (_chan_pri != NULL && _chan_pri->typ.num == tty && wrpipe <= 0) {
	tcsetattr(0, TCSANOW, &isbuf);
    }
    signal(ERR_ok);
}


errcode
_chanOPOPset_tty(CLUREF chref, CLUREF *newch)
{
    int result;
    errcode err;
    CLUREF fname;
    struct stat d0;
    struct stat d1;
    struct termios tbuf;
    struct sigaction vec, ovec, oovec;
    int s;
    CLUREF temp;
    _chan *ch = (_chan *)chref.ref;

    err = stringOPcons("/dev/p", CLU_1, CLU_6, &temp);
    if (err != ERR_ok)
	resignal(err);

    err = file_nameOPparse(temp, &fname);
    if (err != ERR_ok)
	goto def_err_hdlr;

    ch->fn.str = fname.str;
    ch->perm.tf = true;
    if (ch->rd.num != -1)
	s = ch->rd.num;
    else
	s = ch->wr.num;

    result = tcgetattr(s, &sbuf);
    if (result != 0) {
	ch->typ.num = oth;
	signal(ERR_ok);
    }

    result = fstat(1, &d1);
    result = fstat(0, &d0);
    if (d1.st_dev != d0.st_dev
	|| d1.st_ino != d0.st_ino)
    {
	ch->typ.num = bty;
	newch->ref = (char *)ch;
	signal(ERR_ok);
    }

    /* file descriptors 0 and 1 represent the same dev & inode */
    /*	i.e. this is stdin/stdout */
    ch->rd.num = 0;
    ch->wr.num = 1;
    _chan_pri = ch;
    _chan_pro = ch;
    bcopy(&sbuf, &tbuf, (sizeof (struct termios)));
    tbuf.c_iflag |= ICRNL;
    tbuf.c_oflag |= OPOST + ONLCR;
    tbuf.c_lflag &= ~(ICANON + ECHO);
    tbuf.c_cc[VMIN] = 1;
    tbuf.c_cc[VTIME] = 0;
#if 0
    printf("old %x new %x\n", sbuf.sg_flags, tbuf.sg_flags);
#endif
    result = tcsetattr(0, TCSANOW, &tbuf);
    if (result != 0)
	goto unix_err_hdlr;

    if (wrpipe == 0) { /* no debugger */
	vec.sa_handler = (void (*)())_chanOPtdie;
	sigfixmask(&vec.sa_mask, SIGNAL_MASK);
#if 0
	vec.sa_mask = SIGNAL_MASK;
#endif
	vec.sa_flags = 0;	/* 02/03/98 */

	result = sigaction(SIGINT, &vec, &ovec);
	if (result != 0)
	    goto unix_err_hdlr;

	result = sigaction(SIGQUIT, &vec, &ovec);
	if (result != 0)
	    goto unix_err_hdlr;

	if (ovec.sa_handler != NULL) {
	    result = sigaction(SIGQUIT, &ovec, &oovec);
	    if (result != 0)
		goto unix_err_hdlr;
	}

	result = sigaction(SIGILL, &vec, &ovec);
	if (result != 0)
	    goto unix_err_hdlr;

	result = sigaction(SIGBUS, &vec, &ovec);
	if (result != 0)
	    goto unix_err_hdlr;

	result = sigaction(SIGSEGV, &vec, &ovec);
	if (result != 0)
	    goto unix_err_hdlr;

	vec.sa_handler = (void (*)())_chanOPtstop;
	result = sigaction(SIGTSTP, &vec, &ovec);
	if (result != 0)
	    goto unix_err_hdlr;
    }

    newch->ref = (char *)ch;
    signal(ERR_ok);

  unix_err_hdlr:
    elist[0] = _unix_erstr(errno);
    signal(ERR_failure);

  def_err_hdlr:
    elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
}


int
_chanOPtstop(void)
{
    struct sigaction temp;
    int pid;

    temp.sa_handler = NULL;
    sigemptyset(&temp.sa_mask);
#if 0
    temp.sa_mask = 0;
#endif
    temp.sa_flags = 0;
    _chanOP_save_tty();
    sigaction(SIGTSTP, &temp, 0);
    pid = getpid();
    kill(pid, SIGTSTP);

    sigset_t eset, oset;
    sigemptyset(&eset);
    sigprocmask(SIG_SETMASK, &eset, &oset);
    sigprocmask(SIG_SETMASK, &oset, NULL);

    _chanOP_restore_tty();
    temp.sa_handler = (void (*)())_chanOPtstop;
    sigfixmask(&temp.sa_mask, SIGNAL_MASK);
#if 0
    temp.sa_mask = SIGNAL_MASK;
#endif
    temp.sa_flags = 0;	/* 02/03/98 */
    sigaction(SIGTSTP, &temp, 0);
    return 0;
}


int
_chanOPtdie(int sig)
{
    struct sigaction temp;
    int pid;

    temp.sa_handler = NULL;
    sigemptyset(&temp.sa_mask);
#if 0
    temp.sa_mask = 0;
#endif
    temp.sa_flags = 0;
    sigaction(sig, &temp, 0);
    pid = getpid();
    kill(pid, sig);
    _chanOP_save_tty();
    return 0;
}


errcode
_chanOPputc(CLUREF chref, CLUREF c, CLUREF image)
{
    int result;
    _chan *ch = (_chan *)chref.ref;

    if (ch->wr.num < 0) {
	elist[0] = cannot_write_to_this__chan_STRING;
	signal(ERR_not_possible);
    }

#ifndef LINUX
    bool lit = (image.tf && ch->typ.num == tty);
    if (lit)
	ioctl(ch->wr.num, TIOCLBIS, LLITOUT);
#else
    CLU_NOREF(image);
#endif

    for (;;) {
	result = write(ch->wr.num, &c.ch, 1);
	if (result == -1 && errno == EINTR)
	    continue;
	if (result == -1) {
	    elist[0] = _unix_erstr(errno);
	    signal(ERR_not_possible);
	}
	if (result != 1) {
	    elist[0] = unknown_error_STRING;
	    signal(ERR_not_possible);
	}
	break;
    }

#ifndef LINUX
    if (lit)
	ioctl(ch->wr.num, TIOCLBIC, LLITOUT);
#endif
    signal(ERR_ok);
}


errcode
_chanOPputi(CLUREF chref, CLUREF i, CLUREF image)
{
    int result;
    _chan *ch = (_chan *)chref.ref;

    if (ch->wr.num < 0) {
	elist[0] = cannot_write_to_this__chan_STRING;
	signal(ERR_not_possible);
    }

#ifndef LINUX
    bool lit = (image.tf && ch->typ.num == tty);
    if (lit)
	ioctl(ch->wr.num, TIOCLBIS, LLITOUT);
#else
    CLU_NOREF(image);
#endif

    for (;;) {
	result = write(ch->wr.num, &i.num, 1);
	if (result == -1 && errno == EINTR)
	    continue;
	if (result < 0) {
	    elist[0] = _unix_erstr(errno);
	    signal(ERR_not_possible);
	}
	if (result != 1) {
	    elist[0] = unknown_error_STRING;
	    signal(ERR_not_possible);
	}
	break;
    }

#ifndef LINUX
    if (lit)
	ioctl(ch->wr.num, TIOCLBIC, LLITOUT);
#endif
    signal(ERR_ok);
}


errcode
_chanOPputs(CLUREF chref, CLUREF s, CLUREF image)
{
    int result;
    _chan *ch = (_chan *)chref.ref;

    if (ch->wr.num < 0) {
	elist[0] = cannot_write_to_this__chan_STRING;
	signal(ERR_not_possible);
    }

#ifndef LINUX
    bool lit = (image.tf && ch->typ.num == tty);
    if (lit)
	ioctl(ch->wr.num, TIOCLBIS, LLITOUT);
#else
    CLU_NOREF(image);
#endif

    for (;;) {
	result = write(ch->wr.num, s.str->data,
		       s.str->size);
	if (result == -1 && errno == EINTR)
	    continue;
	if (result < 0) {
	    elist[0] = _unix_erstr(errno);
	    signal(ERR_not_possible);
	}
	if (result != s.str->size) {
	    elist[0] = unknown_error_STRING;
	    signal(ERR_not_possible);
	}
	break;
    }

#ifndef LINUX
    if (lit)
	ioctl(ch->wr.num, TIOCLBIC, LLITOUT);
#endif
    signal(ERR_ok);
}


errcode
_chanOPputb(CLUREF chref, CLUREF bv, CLUREF low, CLUREF high, CLUREF image)
{
    int result;
    int top;
    int size;
    _chan *ch = (_chan *)chref.ref;

    if (ch->wr.num < 0) {
	elist[0] = cannot_write_to_this__chan_STRING;
	signal(ERR_not_possible);
    }

    if (low.num < 1 || low.num > bv.str->size)
	signal(ERR_bounds);

    top = bv.str->size;
    if (high.num < top)
	top = high.num;

#ifndef LINUX
    bool lit = (image.tf && ch->typ.num == tty);
    if (lit)
	ioctl(ch->wr.num, TIOCLBIS, LLITOUT);
#else
    CLU_NOREF(image);
#endif

    size = top - low.num + 1;
    if (size <= 0)
	signal(ERR_ok);

    for (;;) {
	result = write(ch->wr.num, &bv.str->data[low.num-1], size);
	if (result == -1 && errno == EINTR)
	    continue;
	if (result == -1) {
	    elist[0] = _unix_erstr(errno);
	    signal(ERR_not_possible);
	}
	if (result != size) {
	    elist[0] = unknown_error_STRING;
	    signal(ERR_not_possible);
	}
	break;
    }

#ifndef LINUX
    if (lit)
	ioctl(ch->wr.num, TIOCLBIC, LLITOUT);
#endif
    signal(ERR_ok);
}


errcode
_chanOPputw(CLUREF chref, CLUREF wv, CLUREF low, CLUREF high, CLUREF image)
{
    int result;
    int top;
    int size;
    _chan *ch = (_chan *)chref.ref;

    if (ch->wr.num < 0) {
	elist[0] = cannot_write_to_this__chan_STRING;
	signal(ERR_not_possible);
    }

    if (low.num < 1 || low.num >= wv.vec->size)
	signal(ERR_bounds);

    top = wv.vec->size;
    if (high.num < top)
	top = high.num;

#ifndef LINUX
    bool lit = (image.tf && ch->typ.num == tty);
    if (lit)
	ioctl(ch->wr.num, TIOCLBIS, LLITOUT);
#else
    CLU_NOREF(image);
#endif

    size = top - low.num + 1;
    if (size <= 0)
	signal(ERR_ok);

    for (;;) {
	result = write(ch->wr.num, &wv.vec->data[low.num-1], size);
	if (result == -1 && errno == EINTR)
	    continue;
	if (result == -1) {
	    elist[0] = _unix_erstr(errno);
	    signal(ERR_not_possible);
	}
	if (result != size) {
	    elist[0] = unknown_error_STRING;
	    signal(ERR_not_possible);
	}
	break;
    }

#ifndef LINUX
    if (lit)
	ioctl(ch->wr.num, TIOCLBIC, LLITOUT);
#endif
    signal(ERR_ok);
}


/* callers assume that initial condition is low = 1, high = 0 */
errcode
_chanOPput(CLUREF chref, CLUREF bv, CLUREF low, CLUREF high,
	   CLUREF s, CLUREF image,
	   CLUREF *ans1, CLUREF *ans2)
{
    int bv_space_left, string_chars_left;
    int string_chars_to_newline;
    int bv_offset, string_offset;
    char * newline_addr;
    bool force;
    int bv_low, bv_high;
    int copy_count;
    errcode err;
    _chan *ch = (_chan *)chref.ref;

    /* initial conditions and bounds checking */
    if (ch->wr.num < 0) {
	elist[0] = cannot_write_to_this__chan_STRING;
	signal(ERR_not_possible);
    }

    if (low.num < 1)
	signal(ERR_bounds);
    if (bv.str->size == 0)
	signal(ERR_bounds);
    if (low.num > bv.str->size)
	signal(ERR_bounds);
    if (high.num < low.num - 1)
	signal(ERR_bounds);

    bool lit;
#ifndef LINUX
    lit = (image.tf && ch->typ.num == tty);
#else
    CLU_NOREF(image);
    lit = false;
#endif

    if (s.str->size <= 0) {
	ans1->num = low.num;
	ans2->num = high.num;
	signal(ERR_ok);
    }

    /* initialize invariants */
    bv_space_left = bv.str->size - high.num;	/* ??? +1 */
    if (bv_space_left < 0)
	signal(ERR_bounds);
    string_chars_left = s.str->size;
    bv_low = low.num - 1;
    bv_high = high.num;
    bv_offset = bv_high;
    string_offset = 0;

    /* loop copying chars from s to bv */
    /*    force writes for newlines in s, or when bv gets full */
    while (string_chars_left > 0) {

	/* look for newline char */
	newline_addr = strchr(&s.str->data[string_offset], '\n');
	if (newline_addr == NULL) {
	    force = false;
	    string_chars_to_newline = 0;
	}
	else {
	    force = true;
	    string_chars_to_newline =
		newline_addr - &(s.str->data[string_offset]);
	    string_chars_to_newline += 1;
	}

	/* decide how many chars to copy */
	copy_count = bv_space_left;
	if (string_chars_left < copy_count)
	    copy_count = string_chars_left;
	if (string_chars_to_newline != 0 && string_chars_to_newline < copy_count)
	    copy_count = string_chars_to_newline;

	/* copy the chars */
	bcopy(&s.str->data[string_offset], &bv.str->data[bv_offset],
	      copy_count);

	/* write out bv if necessary */
	if (force || copy_count == bv_space_left) {
	    err = _chanOPOP_put_doit(lit, ch->wr.num, bv, bv_low,
				     bv_high - bv_low + copy_count);
	    if (err != ERR_ok)
		signal(err); /* propagate */
	    bv_offset = 0;
	    bv_high = 0;
	    bv_low = 0;
	}
	else {
	    bv_offset += copy_count;
	    bv_high += copy_count;
	    if (bv_offset > bv.str->size) {
		bv_offset = 0; bv_low = 0; bv_high = 0;
	    }
	}

	/* update loop invariants */
	string_chars_left -= copy_count;
	string_offset += copy_count;
	bv_space_left = bv.str->size - bv_high;
    }

    ans1->num = bv_low + 1;
    ans2->num = bv_high;
    signal(ERR_ok);
}


errcode
_chanOPOP_put_doit(bool lit, int fd, CLUREF bv, int low, int size)
{
    int result;

#ifndef LINUX
    if (lit)
	ioctl(fd, TIOCLBIS, LLITOUT);
#else
    CLU_NOREF(lit);
#endif

    for (;;) {
	result = write(fd, &bv.str->data[low], size);
	if (result == -1 && errno == EINTR) continue;
	if (result == -1) {
	    elist[0] = _unix_erstr(errno);
	    signal(ERR_not_possible);
	}
	if (result != size) {
	    elist[0] = unknown_error_STRING;
	    signal(ERR_not_possible);
	}
	break;
    }

#ifndef LINUX
    if (lit)
	ioctl(fd, TIOCLBIC, LLITOUT);
#endif
    signal(ERR_ok);
}


errcode
_chanOPreset(CLUREF chref)
{
    int s;
    int result;
    _chan *ch = (_chan *)chref.ref;

    if (ch->typ.num > 1) {
	s = -1;
	if (ch->rd.num >= 0)
	    s = ch->rd.num;
	if (ch->wr.num >= 0)
	    s = ch->wr.num;

	if (s != -1) {
	    result = lseek(s, 0, 0);
	    if (result == -1) {
		elist[0] = _unix_erstr(errno);
		signal(ERR_not_possible);
	    }
	}
    }
    signal(ERR_ok);
}


errcode
_chanOPclose(CLUREF chref)
{
    int s;
    int result;
    _chan *ch = (_chan *)chref.ref;

    if (ch->perm.tf == true)
	signal(ERR_permanent);

    s = -1;
    if (ch->rd.num >= 0)
	s = ch->rd.num;
    if (ch->wr.num >= 0)
	s = ch->wr.num;

    if (s != -1) {
	result = close(s);
	if (result != 0) {
	    elist[0] = _unix_erstr(errno);
	    signal(ERR_not_possible);
	}
	ch->rd.num = -1;
	ch->wr.num = -1;
    }
    signal(ERR_ok);
}


errcode
_chanOPabort(CLUREF chref)
{
    int s;
    errcode err;
    int result;
    CLUREF fn;
    _chan *ch = (_chan *)chref.ref;

    if (ch->perm.tf == true)
	signal(ERR_permanent);

    if (ch->rd.num != -1)
	s = ch->rd.num;
    else
	s = ch->wr.num;

    result = close(s);
    if (result != 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    ch->rd.num = -1;
    ch->wr.num = -1;
    if (ch->new.num == 1) {
	err = file_nameOPunparse(ch->fn, &fn);
	if (err != ERR_ok)
	    resignal(err);
	unlink(fn.str->data);
    }
    signal(ERR_ok);
}


errcode
_chanOPis_tty(CLUREF chref, CLUREF *ans)
{
    _chan *ch = (_chan *)chref.ref;

    if (ch->typ.num == 0)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_chanOPpending(CLUREF chref, CLUREF image, CLUREF *ans)
{
    int result;
    int s;
    int obuf;
    _chan *ch = (_chan *)chref.ref;

    CLU_NOREF(image);

    if (ch->rd.num < 0) {
	elist[0] = cannot_read_from_this__chan_STRING;
	signal(ERR_not_possible);
    }

    s = ch->rd.num;
    result = ioctl(s, FIONREAD, &obuf);
    if (result == -1) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    if (obuf > 0)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_chanOPpend_count(CLUREF chref, CLUREF *ans)
{
    int result;
    int s;
    int obuf;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0) {
	elist[0] = cannot_read_from_this__chan_STRING;
	signal(ERR_not_possible);
    }

    s = ch->rd.num;
    result = ioctl(s, FIONREAD, &obuf);
    if (result == -1) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    ans->num = result;
    signal(ERR_ok);
}


errcode
_chanOPbuf_count(CLUREF chref, CLUREF *ans)
{
    int result;
    int s;
    int obuf;
    _chan *ch = (_chan *)chref.ref;

    if (ch->wr.num < 0) {
	elist[0] = cannot_write_to_this__chan_STRING;
	signal(ERR_not_possible);
    }

    s = ch->wr.num;
    result = ioctl(s, TIOCOUTQ, &obuf);
    if (result == -1) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    ans->num = result;
    signal(ERR_ok);
}


errcode
_chanOPgetc(CLUREF chref, CLUREF image, CLUREF *ans)
{
    int result;
    char temp;
    int echo_count;
    char echo_buf[10];
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0) {
	elist[0] = cannot_read_from_this__chan_STRING;
	signal(ERR_not_possible);
    }

    for (;;) {
	result = read(ch->rd.num, &temp, 1);
	if (result == -1 && errno == EINTR)
	    continue;
	if (result >= 0)
	    break;

	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    if (result == 0)
	signal(ERR_end_of_file);

    /* temp &= 0xff; */
    /* check for no echo */
    if (ch->typ.num != 0 || image.tf) {
	/* printf("no echo %d %d %x\n", ch->typ.num, image.tf, temp); */
	ans->ch = temp;
	signal(ERR_ok);
    }

    /* echo */
    /* printf("echoing %x\n", temp);  */
    echo_buf[0] = temp;
    echo_count = 1;
    if (temp >= '\177') { /* meta character */
	if (temp == '\177') {
	    echo_count++;
	    echo_buf[0] = '^';
	    echo_buf[1] = '?';
	}
	else {
	    echo_count++;
	    echo_buf[1] = echo_buf[0] - 0100;
	    echo_buf[0] = '&';
	    if (echo_buf[1] < '\140') {
		echo_buf[0] = '!';
	    }
	    else {
		echo_buf[1] -= 0100;
		if (echo_buf[1] == '\177') {
		    echo_buf[1] = '?';
		    echo_buf[0] = '!';
		}
	    }
	}
    }
    else { /* not a meta character */
	if (temp < ' ') { /* control character */
	    if (temp != '\n' && temp != '\t') {
		echo_count++;
		echo_buf[1] = echo_buf[0];
		echo_buf[0] = '^';
	    }
	}
    }

    result = write(ch->wr.num, echo_buf, echo_count);
    ans->ch = temp;
    signal(ERR_ok);
}


errcode
_chanOPgeti(CLUREF chref, CLUREF image, CLUREF *ans)
{
    int result;
    int temp;
    int echo_count;
    char echo_buf[10];
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0) {
	elist[0] = cannot_read_from_this__chan_STRING;
	signal(ERR_not_possible);
    }

    for (;;) {
	result = read(ch->rd.num, &temp, 1);
	if (result == -1 && errno == EINTR)
	    continue;
	if (result >= 0)
	    break;

	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    if (result == 0)
	signal(ERR_end_of_file);

    temp &= 0xff;
    /* check for no echo */
    if (ch->typ.num != 0 || image.tf) {
	ans->num = temp;
	signal(ERR_ok);
    }

    /* echo */
    echo_buf[0] = temp;
    echo_count = 1;
    if (temp >= '\177') { /* meta character */
	if (temp == '\177') {
	    echo_count++;
	    echo_buf[0] = '^';
	    echo_buf[1] = '?';
	}
	else {
	    echo_count++;
	    echo_buf[1] = echo_buf[0] - 0100;
	    echo_buf[1] = '&';
	    if (echo_buf[1] < '\140') {
		echo_buf[0] = '!';
	    }
	    else {
		echo_buf[1] -= 0100;
		if (echo_buf[1] == '\177') {
		    echo_buf[1] = '?';
		    echo_buf[0] = '!';
		}
	    }
	}
    }
    else { /* not a meta character */
	if (temp < ' ') { /* control character */
	    if (temp != '\n' && temp != '\t') {
		echo_count++;
		echo_buf[1] = echo_buf[0];
		echo_buf[0] = '^';
	    }
	}
    }

    result = write(ch->wr.num, echo_buf, echo_count);
    signal(ERR_ok);
}


errcode
_chanOPgetb(CLUREF chref, CLUREF bv, CLUREF *ans)
{
    int result;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0) {
	elist[0] = cannot_read_from_this__chan_STRING;
	signal(ERR_not_possible);
    }

    if (bv.str->size == 0)
	signal(ERR_bounds);

    for (;;) {
	result = read(ch->rd.num, bv.str->data, bv.str->size);
	if (result == -1 && errno == EINTR)
	    continue;
	if (result >= 0)
	    break;

	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    if (result == 0)
	signal(ERR_end_of_file);

    ans->num = result;
    signal(ERR_ok);
}


errcode
_chanOPgetw(CLUREF chref, CLUREF bv, CLUREF *ans)
{
    int result;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0) {
	elist[0] = cannot_read_from_this__chan_STRING;
	signal(ERR_not_possible);
    }

    if (bv.str->size == 0)
	signal(ERR_bounds);

    for (;;) {
	result = read(ch->rd.num, bv.str->data, bv.str->size);
	if (result == -1 && errno == EINTR)
	    continue;
	if (result >= 0)
	    break;

	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    if (result == 0)
	signal(ERR_end_of_file);

    ans->num = result;
    signal(ERR_ok);
}


errcode
_chanOPgetwv(CLUREF chref, CLUREF bv, CLUREF strt, CLUREF n, CLUREF *ans)
{
    int result, count;
    _chan *ch = (_chan *)chref.ref;

    if (strt.num < 1)
	signal(ERR_bounds);

    count = bv.str->size-strt.num+1;
    if (n.num < count)
	count = n.num;
    if (count < 0)
	signal(ERR_bounds);

    if (ch->rd.num < 0) {
	elist[0] = cannot_read_from_this__chan_STRING;
	signal(ERR_not_possible);
    }

    if (bv.str->size == 0)
	signal(ERR_bounds);

    for (;;) {
	result = read(ch->rd.num, &bv.str->data[strt.num-1], count);
	if (result == -1 && errno == EINTR)
	    continue;
	if (result >= 0)
	    break;

	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    if (result == 0)
	signal(ERR_end_of_file);

    ans->num = result;
    signal(ERR_ok);
}


errcode
_chanOPgetbv(CLUREF chref, CLUREF bv, CLUREF strt, CLUREF n, CLUREF *ans)
{
    int count;
    int result;
    _chan *ch = (_chan *)chref.ref;

    if (strt.num < 1)
	signal(ERR_bounds);

    /* inlined int$min 8/28/90 dcurtis */
    count = bv.str->size-strt.num+1;
    if (n.num < count)
	count = n.num;
    if (count < 0)
	signal(ERR_bounds);

    if (ch->rd.num < 0) {
	elist[0] = cannot_read_from_this__chan_STRING;
	signal(ERR_not_possible);
    }

    for (;;) {
	result = read(ch->rd.num, &bv.str->data[strt.num-1], count);
	if (result == -1 && errno == EINTR)
	    continue;

	if (result >= 0)
	    break;

	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    if (result == 0)
	signal(ERR_end_of_file);

    ans->num = result;
    signal(ERR_ok);
}


errcode
_chanOPget(CLUREF chref, CLUREF bv, CLUREF low, CLUREF high,
	   CLUREF term, CLUREF image,
	   CLUREF *ans, CLUREF *newlow, CLUREF *newhigh)
{
    errcode err;
    bool done;
    CLUREF temp, newchars, beg, len;
    int count;
    int strt;
    int i, j, found;
    char target;
    _chan *ch = (_chan *)chref.ref;

    CLU_NOREF(image);

/* check arguments */
/*	printf("low = %d, high = %d\n", low.num, high.num); */
    if (ch->rd.num < 0) {
	elist[0] = cannot_read_from_this__chan_STRING;
	signal(ERR_not_possible);
    }
    if (low.num < 1) signal(ERR_bounds);
    if (bv.str->size == 0) signal(ERR_bounds);
    if (low.num > (bv.str->size + 1)) signal(ERR_bounds);
    if (high.num > bv.str->size) signal(ERR_bounds);
    count = high.num;
    if (count < 0) signal(ERR_bounds);
    if (term.str->size <= 0) signal(ERR_bounds);    /* new behavior */
    if (term.str->size > bv.str->size) signal(ERR_bounds); /* new behavior */

/*** CONVERT LOW AND HIGH FROM CLU INDEXES (STARTING AT 1) TO C ****/
/*** INDEXES (STARTING AT 0)                                    ****/
    low.num = low.num - 1;
    high.num = high.num - 1;

/* guarantee that there is some data to search through */
/**** MODIFICATION:    V--------------------V 2/13/91 */
    if (count == 0 || high.num < low.num) {

/**** MODIFICATION: ---V   From strt = 1;  *****/
	strt = 0;
	err = _chanOPOPreadit(ch->rd.num, bv, strt, &count);
	if (err == ERR_end_of_file) signal(err);
	if (err != ERR_ok) signal(err); /* propagate */
	low.num = 0;		/* 5/23/90 */
	high.num = count - 1;   /* 5/23/90 */ /* unnecessary */
    }

    temp = CLU_empty_string;

    if (term.str->size == 1) {
/* search for single character terminator string in buffer (bv) */
	target = term.str->data[0];
	while (1) {
	    done = false;

/**** MODIFICATION: ------------V  Deleted + 1          ******/
	    for (i = low.num; i < count; i++) {
		if (bv.str->data[i] != target) continue;
		done = true; break;
	    }

/***** MODIFICATION: Added +1 ------------------V          V-- Deleted +1 */
	    beg.num = low.num + 1;
	    len.num = i - low.num;
	    err = stringOPsubstr(bv, beg, len, &newchars);
	    if (err != ERR_ok) resignal(err);
	    err = stringOPconcat(temp, newchars, &temp);
	    if (err != ERR_ok) resignal(err);
	    if (done) {
		ans->str = temp.str;

/**** MODIFICATION: Changed +1 to +2 --nixed--V            *****/
		newlow->num = i + 1;
		newhigh->num = count;

/**** MODIFICATION: If it ends up with the terminator at the end of the  *****/
/****               buffer, then read in a new buffer full before *****/
/****               returning.  Also return cleanly if EOF. *****/

/* the following case appears impossible */

		if (newlow->num > newhigh->num) {
		    strt = 0;
		    err = _chanOPOPreadit(ch->rd.num, bv, strt,
					  &count);
		    if ((err != ERR_ok)&&(err != ERR_end_of_file))
			signal(err); /* propagate */
		    if (err == ERR_end_of_file) signal(err);
		    newlow->num = 1;
		}
/* the following case is new 5/23/90 */
/* removed 2/13/91 */
/*
  if (newlow->num == newhigh->num) {
  newhigh->num = 0;
  }
*/
		if (newlow->num > bv.str->size) newlow->num = count;
/*			printf("%s\n", temp.str->data); */
/*			printf("newlow = %d, newhigh = %d\n", newlow->num, newhigh->num); */
		signal(ERR_ok);
	    }
	    else {

/**** MODIFICATION: Added --V     strt = 0;    *****/
		strt = 0;
		err = _chanOPOPreadit(ch->rd.num, bv, strt, &count);

/**** MODIFICATION: Added --V     low.num = 0;    *****/
		low.num = 0;

		if (err == ERR_end_of_file) {
		    ans->str = temp.str;
		    newlow->num = 1;
		    newhigh->num = 0;
		    signal(ERR_ok);
		}
		if (err != ERR_ok) signal(err); /* propagate */
	    }
	}
    }

    else {


/***** MODIFICATION: THE REMAINDER OF GET IS ENTIRELY REWRITTEN ****/
/* search for multi character terminator string in bv */
/* substantially reworked 8/12/92 (dwc)  (used by clucc):
   redefine multi-character terminator string: any char in it will terminate the read
   handle eof properly
   leave terminator in buffer
*/
	while (1) {
	    found = false;
	    for (i = low.num; i < count; i++) {
		for (j = 0; j < term.str->size; j++) {
		    if (bv.str->data[i] == term.str->data[j]) {
			found = true; break;}
		}
		if (found == true) {	/*** THEN DONE ***/
		    beg.num = low.num + 1;
		    len.num = i - low.num;
		    err = stringOPsubstr (bv, beg, len, &newchars);
		    if (err != ERR_ok) resignal (err);
		    err = stringOPconcat (temp, newchars, &temp);
		    if (err != ERR_ok) resignal (err);
		    ans->str = temp.str;
		    newlow->num = i + 1;
		    newhigh->num = count;

/**** MODIFICATION: If it ends up with the terminator at the end of the  *****/
/****               buffer, then read in a new buffer full before *****/
/****               returning.  Also return cleanly if EOF. *****/

		    if (newlow->num > newhigh->num) {
			strt = 0;
			err = _chanOPOPreadit(ch->rd.num, bv, strt,
					      &count);
			if ((err != ERR_ok)&&(err != ERR_end_of_file))
			    signal(err); /* propagate */
			if (err == ERR_end_of_file) signal(err);
			newlow->num = 1;
			/** End If **/}

		    if (newlow->num > bv.str->size) newlow->num = count;
		    signal (ERR_ok);
		    /** End If done **/}
		/** End For i **/}

	    beg.num = low.num + 1;
	    len.num = i - low.num;
	    err = stringOPsubstr (bv, beg, len, &newchars);
	    if (err != ERR_ok) resignal (err);
	    err = stringOPconcat (temp, newchars, &temp);
	    if (err != ERR_ok) resignal (err);
	    strt = 0;
	    err = _chanOPOPreadit(ch->rd.num, bv, strt, &count);
	    low.num = 0;
	    if (err == ERR_end_of_file) {
		ans->str = temp.str;
		newlow->num = 1;
		newhigh->num = 0;
		signal(ERR_ok);
	    }
	    if (err != ERR_ok)
		signal (err); /* propagate */
	}
    }
}


errcode
_chanOPOPreadit(int s, CLUREF bv, int start, int *count)
{
    int result;

    /* MODIFICATION: Changed "+ 1" to "+ start" */
    result = read(s, &bv.str->data[start], bv.str->size - start);
    if (result == 0)
	signal(ERR_end_of_file);

    if (result == -1) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    *count = result + start;
    signal(ERR_ok);
}


errcode
_chanOPrecv(CLUREF chref, CLUREF bv, CLUREF flags, CLUREF *ans)
{
    int result;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0) {
	elist[0] = cannot_read_from_this__chan_STRING;
	signal(ERR_not_possible);
    }

    for (;;) {
	result = recv(ch->rd.num, bv.str->data, bv.str->size, flags.num);
	if (result == -1 && errno == EINTR)
	    continue;
	if (result >= 0)
	    break;

	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }
    ans->num = result;
    signal(ERR_ok);
}


errcode
_chanOPrecvfrom(CLUREF chref, CLUREF bv, CLUREF flags, CLUREF addr,
		CLUREF *ans1, CLUREF *ans2)
{
    _chan *ch = (_chan *)chref.ref;
    if (ch->rd.num < 0) {
	elist[0] = cannot_read_from_this__chan_STRING;
	signal(ERR_not_possible);
    }

    for (;;) {
	socklen_t fromlen = addr.str->size;
	ssize_t nread
	    = recvfrom(ch->rd.num, bv.str->data, bv.str->size, flags.num,
		       (struct sockaddr *)addr.str->data, &fromlen);

	if (nread >= 0) {
	    ans1->num = nread;
	    ans2->num = fromlen;
	    signal(ERR_ok);
	}

	if (errno != EINTR) {
	    elist[0] = _unix_erstr(errno);
	    signal(ERR_not_possible);
	}

	/* retry interrupted syscall */
    }
}


errcode
_chanOPsend(CLUREF chref, CLUREF buf, CLUREF len, CLUREF flags)
{
    int result;
    int size;
    _chan *ch = (_chan *)chref.ref;

    if (ch->wr.num < 0) {
	elist[0] = cannot_write_to_this__chan_STRING;
	signal(ERR_not_possible);
    }

    size = buf.vec->size;
    if (len.num <= size)
	size = len.num;
    else
	signal(ERR_bounds);

    for (;;) {
	result = send(ch->wr.num, buf.vec->data, size, flags.num);
	if (result == -1 && errno == EINTR)
	    continue;

	if (result == -1) {
	    elist[0] = _unix_erstr(errno);
	    signal(ERR_not_possible);
	}
	break;
    }
    signal(ERR_ok);
}


errcode
_chanOPsendto(CLUREF chref, CLUREF buf, CLUREF len,
	      CLUREF flags, CLUREF addr, CLUREF alen)
{
    _chan *ch = (_chan *)chref.ref;
    if (ch->wr.num < 0) {
	elist[0] = cannot_write_to_this__chan_STRING;
	signal(ERR_not_possible);
    }

    /* XXX: TODO: ERR_negative_size? */
    if (len.num < 0)
	signal(ERR_bounds);

    size_t size = buf.vec->size;
    if ((size_t)len.num <= size)
	size = len.num;
    else
	signal(ERR_bounds);

    /* XXX: TODO: ERR_negative_size? */
    if (alen.num < 0)
	signal(ERR_bounds);

    size_t asize = addr.vec->size;
    if ((size_t)alen.num <= asize)
	asize = alen.num;
    else
	signal(ERR_bounds);

    for (;;) {
	ssize_t nsent
	    = sendto(ch->wr.num, buf.vec->data, size, flags.num,
		     (struct sockaddr *)addr.vec->data, asize);

	/* XXX: TODO: partial sends? */
	if (nsent >= 0) {
	    signal(ERR_ok);
	}

	if (errno != EINTR) {
	    elist[0] = _unix_erstr(errno);
	    signal(ERR_not_possible);
	}

	/* retry interrupted syscall */
    }
}


errcode
_chanOPread_wait(CLUREF chref, CLUREF millis, CLUREF *ans)
{
    int result;
    struct timeval timeout;
    fd_set readfds, exceptfds;
    _chan *ch = (_chan *)chref.ref;

    FD_ZERO(&readfds);
    FD_ZERO(&exceptfds);

    if (ch->rd.num < 0) {
	elist[0] = cannot_read_from_this__chan_STRING;
	signal(ERR_not_possible);
    }

    FD_SET(ch->rd.num, &readfds);
    FD_SET(ch->rd.num, &exceptfds);

    timeout.tv_sec = millis.num / 1000;
    timeout.tv_usec = (millis.num - (timeout.tv_sec * 1000)) * 1000;

    for (;;) {
	result = select(ch->rd.num + 1, &readfds, 0, &exceptfds, &timeout);
	if (result == -1 && errno == EINTR)
	    continue;

	if (result == -1) {
	    elist[0] = _unix_erstr(errno);
	    signal(ERR_not_possible);
	}
	break;
    }

    if (result == 0)
	ans->num = 0;
    else
	ans->num = 1;
    signal(ERR_ok);
}


errcode
_chanOPwrite_wait(CLUREF chref, CLUREF millis, CLUREF *ans)
{
    int result;
    struct timeval timeout;
    fd_set writefds, exceptfds;
    _chan *ch = (_chan *)chref.ref;

    FD_ZERO(&writefds);
    FD_ZERO(&exceptfds);

    if (ch->wr.num < 0) {
	elist[0] = cannot_write_to_this__chan_STRING;
	signal(ERR_not_possible);
    }

    FD_SET(ch->wr.num, &writefds);
    FD_SET(ch->wr.num, &exceptfds);

    timeout.tv_sec = millis.num / 1000;
    timeout.tv_usec = (millis.num - (timeout.tv_sec * 1000)) * 1000;

    for (;;) {
	result = select(ch->rd.num + 1, 0, &writefds, &exceptfds, &timeout);
	if (result == -1 && errno == EINTR)
	    continue;

	if (result == -1) {
	    elist[0] = _unix_erstr(errno);
	    signal(ERR_not_possible);
	}
	break;
    }

    if (result == 0)
	ans->num = 0;
    else
	ans->num = 1;
    signal(ERR_ok);
}


errcode
_chanOPwait(CLUREF reads, CLUREF writes, CLUREF millis, CLUREF *ans)
{
    int result, i;
    struct timeval timeout;
    fd_set readfds, writefds, exceptfds;
    _chan **rds = (_chan **)reads.vec->data;
    _chan **wrs = (_chan **)writes.vec->data;
    int ith;
    int max = 0;

    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    FD_ZERO(&exceptfds);

    for (i = 0 ; i < reads.vec->size; ++i) {
	ith = rds[i]->rd.num;
	if (ith < 0) {
	    elist[0] = cannot_read_from_this__chan_STRING;
	    signal(ERR_not_possible);
	}

	FD_SET(ith, &readfds);
	FD_SET(ith, &exceptfds);
	if (ith > max)
	    max = ith + 1;
    }

    for (i = 0 ; i < writes.vec->size; ++i) {
	ith = wrs[i]->wr.num;
	if (ith < 0) {
	    elist[0] = cannot_write_to_this__chan_STRING;
	    signal(ERR_not_possible);
	}

	FD_SET(ith, &writefds);
	FD_SET(ith, &exceptfds);
	if (ith > max)
	    max = ith + 1;
    }

    /* 2/26/01 dwc: folded functionality into above loops */
    /* exceptfds.fds_bits[0] = readfds.fds_bits[0] | writefds.fds_bits[0]; */

    timeout.tv_sec = millis.num / 1000;
    timeout.tv_usec = (millis.num - (timeout.tv_sec * 1000)) * 1000;
    for (;;) {
	result = select(max, &readfds,
			&writefds, &exceptfds, &timeout);
	if (result == -1 && errno == EINTR) {
	    ans->num = 0;
	    signal(ERR_ok);
	}

	if (result == -1) {
	    elist[0] = _unix_erstr(errno);
	    signal(ERR_not_possible);
	}
	break;
    }

    ans->num = result;
    signal(ERR_ok);
}


errcode
_chanOPlisten(CLUREF chref, CLUREF backlog)
{
    int fd, uerr;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    uerr = listen(fd, backlog.num);
    if (uerr == 0)
 	signal(ERR_ok);

    elist[0] = _unix_erstr(errno);
    signal(ERR_not_possible);
}


errcode
_chanOPaccept(CLUREF chref, CLUREF addr, CLUREF *ans1, CLUREF *ans2)
{
    errcode err;
    int fd, result, s, z;
    socklen_t len;
    _chan *newch;
    CLUREF temp_str, fn;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    len = addr.vec->size;
    for (;;) {
	result = accept(fd, addr.vec->data, &len);
	if (result == -1 && errno == EINTR)
	    continue;
	if (result == -1) {
	    elist[0] = _unix_erstr(errno);
	    signal(ERR_not_possible);
	}
	break;
    }
    s = result;
    z = len;

    err = stringOPcons("/dev/socket", CLU_1, CLU_11, &temp_str);
    if (err != ERR_ok)
	resignal(err);

    err = file_nameOPparse(temp_str, &fn);
    if (err != ERR_ok)
	resignal(err);

    clu_alloc(sizeof(_chan), &newch);
    newch->fn = fn;
    newch->rd.num = s;
    newch->wr.num = s;
    newch->typ.num = oth;
    newch->new.tf = true;
    newch->perm.tf = false;
    ans1->ref = (char *)newch;
    ans2->num = z;
    signal(ERR_ok);
}


errcode
_chanOPbind(CLUREF chref, CLUREF name, CLUREF len)
{
    int fd, uerr;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    if (len.num > name.vec->size)
	signal(ERR_bounds);

    uerr = bind(fd, name.vec->data, len.num);
    if (uerr == 0)
	signal(ERR_ok);

    elist[0] = _unix_erstr(errno);
    signal(ERR_not_possible);
}


errcode
_chanOPconnect(CLUREF chref, CLUREF name, CLUREF len)
{
    int fd, uerr;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    if (len.num > name.vec->size)
	signal(ERR_bounds);

    uerr = connect(fd, name.vec->data, len.num);
    if (uerr == 0)
	signal(ERR_ok);

    elist[0] = _unix_erstr(errno);
    signal(ERR_not_possible);
}


errcode
_chanOPshutdown(CLUREF chref, CLUREF how)
{
    int fd, uerr;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    uerr = shutdown(fd, how.num);
    if (uerr == 0)
	signal(ERR_ok);

    elist[0] = _unix_erstr(errno);
    signal(ERR_not_possible);
}


errcode
_chanOPpeername(CLUREF chref, CLUREF name, CLUREF *ans)
{
    int fd, uerr;
    socklen_t size;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    size = name.vec->size;
    uerr = getpeername(fd, name.vec->data, &size);
    if (uerr == 0) {
	ans->num = size;
	signal(ERR_ok);
    }

    elist[0] = _unix_erstr(errno);
    signal(ERR_not_possible);
}


errcode
_chanOPsockname(CLUREF chref, CLUREF name, CLUREF *ans)
{
    int fd, uerr;
    socklen_t size;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    size = name.vec->size;
    uerr = getsockname(fd, name.vec->data, &size);
    if (uerr == 0) {
	ans->num = size;
	signal(ERR_ok);
    }

    elist[0] = _unix_erstr(errno);
    signal(ERR_not_possible);
}


errcode
_chanOPgetsockopt(CLUREF chref, CLUREF level, CLUREF option, CLUREF *ans)
{
    int fd, uerr;
    int optval;
    socklen_t optlen;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    optlen = 4;
    uerr = getsockopt(fd, level.num, option.num, &optval, &optlen);
    if (uerr == 0) {
	ans->num = optval;
	signal(ERR_ok);
    }

    elist[0] = _unix_erstr(errno);
    signal(ERR_not_possible);
}


errcode
_chanOPsetsockopt(CLUREF chref, CLUREF level, CLUREF option, CLUREF value)
{
    int fd, uerr;
    int optlen;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    optlen = 4;
    uerr = setsockopt(fd, level.num, option.num, &value, optlen);
    if (uerr == 0) {
	signal(ERR_ok);
    }

    elist[0] = _unix_erstr(errno);
    signal(ERR_not_possible);
}


errcode
_chanOPget_name(CLUREF chref, CLUREF *ans)
{
    _chan *ch = (_chan *)chref.ref;

    ans->vec = ch->fn.vec;
    signal(ERR_ok);
}


errcode
_chanOPget_date(CLUREF chref, CLUREF *ans)
{
    int uerr, fd;
    struct stat stat;
    CLUREF time;
    errcode err;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    uerr = fstat(fd, &stat);
    if (uerr == 0) {
	err = _local_time(CLUREF_make_num((stat.st_mtime >> 16) & 0xffff),
			  CLUREF_make_num(stat.st_mtime & 0xffff), &time);
	if (err != ERR_ok)
	    resignal(err);

	ans->num = time.num;
	signal(ERR_ok);
    }

    elist[0] = _unix_erstr(errno);
    signal(ERR_not_possible);
}


errcode
_chanOPget_speeds(CLUREF chref, CLUREF *ans1, CLUREF *ans2)
{
    int result, fd;
    int insp, outsp;
    struct termios buf;
    _chan *ch = (_chan *)chref.ref;

    if (ch->typ.num != 0) {
	elist[0] = not_a_terminal__chan_STRING;
	signal(ERR_not_possible);
    }

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = speeds_unknown_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    result = tcgetattr(fd, &buf);
    if (result == -1) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    insp = cfgetispeed(&buf);
    outsp = cfgetospeed(&buf);
#if 0
    printf("%d %d\n", insp, outsp);
    printf("%d %d\n", buf.c_ispeed, buf.c_ospeed);
#endif
    ans1->num = insp;
    ans2->num = outsp;
    signal(ERR_ok);
}


errcode
_chanOPget_block_size(CLUREF chref, CLUREF *ans)
{
    int uerr, fd;
    struct stat stat;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    uerr = fstat(fd, &stat);
    if (uerr == 0) {
	ans->num = stat.st_blksize;
	signal(ERR_ok);
    }

    elist[0] = _unix_erstr(errno);
    signal(ERR_not_possible);
}


errcode
_chanOPstat(CLUREF chref, CLUREF buf)
{
    int result, fd;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    if ((size_t)buf.vec->size < sizeof(struct stat))
	signal(ERR_bounds);

    result = fstat(fd, (struct stat *)buf.vec->data);
    if (result == -1) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    signal(ERR_ok);
}


errcode
_chanOPget_access(CLUREF chref, CLUREF *ans)
{
    int result, fd;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    result = lseek(fd, 0, 1);
    if (result == -1) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    ans->num = result;
    signal(ERR_ok);
}


errcode
_chanOPset_access(CLUREF chref, CLUREF pos)
{
    int uerr, fd;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    uerr = lseek(fd, pos.num, 0);
    if (uerr == -1) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    signal(ERR_ok);
}


errcode
_chanOPget_length(CLUREF chref, CLUREF *ans)
{
    int uerr, fd;
    struct stat stat;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }

    fd = ch->rd.num;
    if (fd < 0)
	fd = ch->wr.num;

    uerr = fstat(fd, &stat);
    if (uerr == 0) {
	ans->num = stat.st_size;
	signal(ERR_ok);
    }

    elist[0] = _unix_erstr(errno);
    signal(ERR_not_possible);
}


errcode
_chanOPset_length(CLUREF chref, CLUREF len)
{
    int uerr, fd;
    _chan *ch = (_chan *)chref.ref;

    if (ch->rd.num < 0 && ch->wr.num < 0) {
	elist[0] = _chan_is_closed_STRING;
	signal(ERR_not_possible);
    }
    fd = ch->rd.num;
    if (fd < 0) fd = ch->wr.num;
    uerr = ftruncate(fd, len.num);
    if (uerr == 0) signal(ERR_ok);
    elist[0] = _unix_erstr(errno);
    signal(ERR_not_possible);
}


errcode
_chanOPequal(CLUREF ch1, CLUREF ch2, CLUREF *ans)
{
    if (ch1.ref == ch2.ref)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_chanOPsimilar(CLUREF ch1, CLUREF ch2, CLUREF *ans)
{
    if (ch1.ref == ch2.ref)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_chanOPcopy(CLUREF ch, CLUREF *ans)
{
    ans->ref = ch.ref;
    signal(ERR_ok);
}


errcode
_chanOPget_read_channel(CLUREF chref, CLUREF image, CLUREF *ans)
{
    _chan *ch = (_chan *)chref.ref;
    CLU_NOREF(image);

    if (ch->rd.num >= 0) {
	ans->num = ch->rd.num;
	signal(ERR_ok);
    }
    else {
	elist[0] = cannot_read_from_this__chan_STRING;
	signal(ERR_not_possible);
    }
}


errcode
_chanOPget_write_channel(CLUREF chref, CLUREF image, CLUREF *ans)
{
    _chan *ch = (_chan *)chref.ref;
    CLU_NOREF(image);

    if (ch->wr.num >= 0) {
	ans->num = ch->wr.num;
	signal(ERR_ok);
    }
    else {
	elist[0] = cannot_write_to_this__chan_STRING;
	signal(ERR_not_possible);
    }
}


errcode
_chanOPget_def_mode(CLUREF *ans)
{
    if (_chan_defmode == 0) ans->num = 0666;
    else ans->num = _chan_defmode;
    signal(ERR_ok);
}


errcode
_chanOPset_def_mode(CLUREF mode)
{
    _chan_defmode = mode.num;
    signal(ERR_ok);
}


errcode
_chanOPclose_all(void)
{
    int count, i;

    count = getdtablesize();
    for (i = 3 ; i < count; i++) {
	if (i == rdpipe || i == wrpipe) continue;
	close(i);
    }
    signal(ERR_ok);
}


errcode
_chanOPdebug_print(CLUREF chref, CLUREF pst)
{
    _chan *ch = (_chan *)chref.ref;
    CLUREF temp_str, comma, nm, ans;
    errcode err;

    stringOPcons("[", CLU_1, CLU_1, &temp_str);
    err = pstreamOPstart(pst, temp_str, &ans);
    if (err != ERR_ok) resignal(err);
    if (ans.tf == false) goto done;
    stringOPcons(",", CLU_1, CLU_1, &comma);
    if (err != ERR_ok) resignal(err);

    stringOPcons("fn: ", CLU_1, CLU_4, &nm);
    err = pstreamOPtext(pst, nm, &ans);
    if (err != ERR_ok) resignal(err);
    err = file_nameOPprint(ch->fn, pst);
    if (err != ERR_ok) resignal(err);
    err = pstreamOPpause(pst, comma, &ans);
    if (err != ERR_ok) resignal(err);
    if (ans.tf == false) goto done;

    stringOPcons("rd: ", CLU_1, CLU_4, &nm);
    err = pstreamOPtext(pst, nm, &ans);
    if (err != ERR_ok) resignal(err);
    err = intOPprint(ch->rd, pst);
    if (err != ERR_ok) resignal(err);
    err = pstreamOPpause(pst, comma, &ans);
    if (err != ERR_ok) resignal(err);
    if (ans.tf == false) goto done;

    stringOPcons("wr: ", CLU_1, CLU_4, &nm);
    err = pstreamOPtext(pst, nm, &ans);
    if (err != ERR_ok) resignal(err);
    err = intOPprint(ch->wr, pst);
    if (err != ERR_ok) resignal(err);
    err = pstreamOPpause(pst, comma, &ans);
    if (err != ERR_ok) resignal(err);
    if (ans.tf == false) goto done;

    stringOPcons("typ: ", CLU_1, CLU_5, &nm);
    err = pstreamOPtext(pst, nm, &ans);
    if (err != ERR_ok) resignal(err);
    err = intOPprint(ch->typ, pst);
    if (err != ERR_ok) resignal(err);
    err = pstreamOPpause(pst, comma, &ans);
    if (err != ERR_ok) resignal(err);
    if (ans.tf == false) goto done;

    stringOPcons("new: ", CLU_1, CLU_5, &nm);
    err = pstreamOPtext(pst, nm, &ans);
    if (err != ERR_ok) resignal(err);
    err = boolOPprint(ch->new, pst);
    if (err != ERR_ok) resignal(err);
    err = pstreamOPpause(pst, comma, &ans);
    if (err != ERR_ok) resignal(err);
    if (ans.tf == false) goto done;

    stringOPcons("perm: ", CLU_1, CLU_6, &nm);
    err = pstreamOPtext(pst, nm, &ans);
    if (err != ERR_ok) resignal(err);
    err = boolOPprint(ch->perm, pst);
    if (err != ERR_ok) resignal(err);
    err = pstreamOPpause(pst, comma, &ans);
    if (err != ERR_ok) resignal(err);
    if (ans.tf == false) goto done;

  done:
    err = stringOPcons("}", CLU_1, CLU_1, &temp_str);
    if (err != ERR_ok) resignal(err);
    err = pstreamOPstop(pst, temp_str, &ans);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}



OWN_ptr _chan_own_init = { .init_flag = 1 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &_chan_own_init,		\
    .op_owns = &_chan_own_init,			\
}

static CLU_proc _chan_oe_copy = CLU_proc_INIT(_chanOPcopy);
static CLU_proc _chan_oe_equal = CLU_proc_INIT(_chanOPequal);
static CLU_proc _chan_oe_similar = CLU_proc_INIT(_chanOPsimilar);
static CLU_proc _chan_oe_debug_print = CLU_proc_INIT(_chanOPdebug_print);


/* extends struct OPS */
typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[4];
} _chan_OPS;

static _chan_OPS _chan_ops_actual = {
    4,
    &_chan_own_init,
    &_chan_own_init, {
	{ &_chan_oe_copy, "copy" },
	{ &_chan_oe_equal, "equal" },
	{ &_chan_oe_similar, "similar" },
	{ &_chan_oe_debug_print, "debug_print" },
    }
};

struct OPS *_chan_ops = (struct OPS *)&_chan_ops_actual;
