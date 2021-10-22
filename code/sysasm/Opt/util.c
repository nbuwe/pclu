/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*		   main				*/
/*    includes several other support routines   */
/*						*/

#include <signal.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#undef  signal
#define signal(x)	break if used
#undef  resignal
#define resignal(x)	break if used


#include <sys/resource.h>
#include <sys/time.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void find_ops_init();
extern void find_selops_init();

errcode _chanOP_save_tty(void);
errcode streamOP_close_all(void);
errcode stringOPconcat(CLUREF s1, CLUREF s2, CLUREF *ans);
errcode stringOPcons(const char *buf, CLUREF start, CLUREF len, CLUREF *ans);

#ifdef CLU_DEBUG_IMPL
/* cf. debug/debug.clu */
#define CLU_DEBUG_GENESIS CLU_4
extern errcode debugOPcli(CLUREF source, CLUREF opt1, CLUREF opt2, CLUREF opt3,
			  CLUREF *ans);
#endif


#ifndef LINUX
extern void expand_hp();
extern struct obj * gc_malloc();
extern void gc_init();
#else
#include <gc/gc.h>
#endif

#if !defined(__arraycount)
#define __arraycount(a) (sizeof(a) / sizeof(a[0]))
#endif

static errcode clu_err_string_init(void);

char **environ;
errlist elist;

CLUREF CUR_PROC_VAR;
struct obj **NewObjPtr;

static int main_2(int _argc, char **_argv, char **_envp);
int argc;
char **argv;
char **envp;

CLUREF empty_string;
CLUREF CLU_empty_string;
bool print_stat = false;
#if 0
extern errcode string_anal(void);
#endif

/* used by the compiler as storage for CUR_PROC_VAR to point to */
CLU_proc generic_CLU_proc;

struct OPS NO_OPS = { .count = 0, .type_owns = NULL, .op_owns = NULL };
struct OPS *NULL_OPS = NULL;

const Vlist0 NO_VALS =  { .hdr = 0, .count = 0 };
const Slist0 NO_PARMS = { .hdr = 0, .count = 0 };


long maxheapsize = 0;
#if 0
extern long STACKTOP;
#endif


int
main(int _argc, char **_argv, char **_envp)
{
    int err;

#if 0
    STACKTOP = get_sp();

    int sz = sizeof(CLUREF);
    int temp1 = INT_MIN;
    int temp2 = LONG_MIN;
    int temp3 = intOPleastint;
    int temp4 = ((long)MIN_ARR_INDEX);
    printf ("size of CLUREF %d\n", sz);
    printf ("INT_MIN %d\n", INT_MIN);
    printf ("LONG_MIN %d\n", LONG_MIN);
    printf ("intOPleastint %d\n", intOPleastint);
    printf ("((long)MIN_ARR_INDEX) %d\n", ((long)MIN_ARR_INDEX));
#endif
    err = main_2(_argc, _argv, _envp);
    return err;
}


/* Routine to get the ball rolling */
static int
main_2(int _argc, char **_argv, char **_envp)
{
    errcode err, pgmerr;
#ifndef LINUX
    struct sigstack ss, oss;
#endif
    OWNPTR save_own_ptr;
    OWNREQ save_own_req;
    void (*save_own_proc)();
    OWNPTR *save1, *save2, *save3, *save4;
    struct rlimit rlimit;
    struct rusage rusage_1;
    struct rusage rusage_2;
    struct timeval tv1, tv2;
    struct timezone tz;

    /* make input information available via globals */
    argc = _argc;
    argv = _argv;
    envp = _envp;
    environ = _envp;
#if 0
    printf("%s\n", _envp[0]);
    printf("%s\n", environ[0]);
#endif

    /* see what the operating system will give us for heap space */
    /* 	and tell it we want the max			     */
    /* note that the heap is in the data area for portable clu,  */
    /*	while the original vax clu has the heap in P1 (usually the stack) */
    err = getrlimit(RLIMIT_DATA, &rlimit);
    if (err != 0) {
	perror("util failed in getrlimit");
	exit(-10);
    }

#if 0
    fprintf(stderr, "soft data limit: %d\n", rlimit.rlim_cur);
    fprintf(stderr, "hard data limit: %d\n", rlimit.rlim_max);
#endif
    rlimit.rlim_cur = rlimit.rlim_max;
    maxheapsize = rlimit.rlim_max;
    err = setrlimit(RLIMIT_DATA, &rlimit);
    if (err != 0) {
	perror("util failed in setrlimit");
	exit(-10);
    }


    /* garbage collector initialization (boehm variant) */
    gc_init();	      /* includes expand_hp of 16 hblks => 64Kbytes */
    expand_hp(112);   /* expands up to 0.5 Megabytes */

#if 0
    printf("%s\n", clu_errlist[0]);
    printf("%s\n", clu_errlist[1]);
    printf("%s\n", clu_errlist[2]);
    printf("%s\n", clu_errlist[23]);
#endif

    /* set up stack for signal handlers */
#ifndef LINUX
    ss.ss_onstack = 1;
    ss.ss_sp = (char *)gc_malloc(100);
    sigstack(&ss, &oss);
#endif

    /* initialize storage for ops manager */
    find_ops_init(&save_own_ptr, &save_own_req, &save_own_proc);
    find_selops_init(&save1, &save2, &save3, &save4);

    /* set up empty string constants */
    err = stringOPcons("", CLU_1, CLU_0, &empty_string);
    if (err != ERR_ok)
	fprintf(stderr, "failure: %s\n", elist[0].str->data);
    CLU_empty_string = empty_string;

    /* set up error string constants */
    clu_err_string_init();

    /* collect statistics on user's program */
    err = gettimeofday(&tv1, &tz);
    if (err != 0) {
	perror("util failed in gettimeofday #1");
	exit(-10);
    }
    err = getrusage(0, &rusage_1);
    if (err != 0) {
	perror("util failed in getruage #1");
	exit(-10);
    }

    /* invoke the user's program */
    {
#ifdef CLU_DEBUG_IMPL
	/*
	 * This bit of code is, more or less the only diff that
	 * pclu-LINUX-RH7 had between Opt and Debugger versions.
	 *
	 * Fold it in here under an ifdef.  It also had this block in
	 * an infinite loop, but I'm not sure about it.  It's nice to
	 * keep the breakpoints and whatever, but since we are in the
	 * same old process, the global state is modified by the
	 * previous run.
	 *
	 * In the more recent pclu-debian this code is not there and
	 * Opt and Debugger versions are practically identicall.
	 */
	CLUREF ignored_result;
	err = debugOPcli(CLU_DEBUG_GENESIS,
			 CLU_0, CLU_empty_string, CLU_empty_string,
			 &ignored_result);
	if (err != ERR_ok) {
	    CLUREF erstr = _pclu_erstr(err);
	    fprintf(stderr, "unhandled exception: %s\n", erstr.str->data);
	}
#endif	/* CLU_DEBUG_IMPL */

	pgmerr = start_up();
	if (pgmerr != ERR_ok) {
	    fflush(stdout);
	    fprintf(stderr, "failure: %s\n", elist[0].str->data);
	}
    }

    /* collect statistics on user's program */
    err = getrusage(0, &rusage_2);
    if (err != 0) {
	perror("util failed in getruage #2");
	exit(-10);
    }
    err = gettimeofday(&tv2, &tz);
    if (err != 0) {
	perror("util failed in gettimeofday #2");
	exit(-10);
    }

    if (print_stat) {
	fprintf(stderr, "wall clock time %lld secs\n", (long long)(tv2.tv_sec - tv1.tv_sec));
	fprintf(stderr, "user time %lld, system time %lld, user+system time %lld secs\n",
			(long long)(rusage_2.ru_utime.tv_sec - rusage_1.ru_utime.tv_sec),
			(long long)(rusage_2.ru_stime.tv_sec - rusage_1.ru_stime.tv_sec),
			(long long)(rusage_2.ru_stime.tv_sec - rusage_1.ru_stime.tv_sec +
				    rusage_2.ru_utime.tv_sec - rusage_1.ru_utime.tv_sec));
	fprintf(stderr, "max resident set sizes (start & end), %ld & %ld Kbytes\n",
			rusage_1.ru_maxrss, rusage_2.ru_maxrss);
	fprintf(stderr, "minor page faults %ld, major page faults %ld\n",
			rusage_2.ru_minflt - rusage_1.ru_minflt,
			rusage_2.ru_majflt - rusage_1.ru_majflt);
	fprintf(stderr, "number of times swapped out %ld\n",
			rusage_2.ru_nswap - rusage_1.ru_nswap);
	fprintf(stderr, "input via file system %ld, output via file system %ld\n",
			rusage_2.ru_inblock - rusage_1.ru_inblock,
			rusage_2.ru_oublock - rusage_1.ru_oublock);
	fprintf(stderr, "IPC input %ld, IPC output %ld\n",
			rusage_2.ru_msgrcv - rusage_1.ru_msgrcv,
			rusage_2.ru_msgsnd - rusage_1.ru_msgsnd);
	fprintf(stderr, "number of signals delivered %ld\n",
			rusage_2.ru_nsignals - rusage_1.ru_nsignals);
	fprintf(stderr, "number of voluntary give ups %ld\n",
			rusage_2.ru_nvcsw - rusage_1.ru_nvcsw);
	fprintf(stderr, "number of involuntary give ups %ld\n",
			rusage_2.ru_nivcsw - rusage_1.ru_nivcsw);
#if 0
	string_anal();
#endif
    }


    /* exit */
    streamOP_close_all(); /* replace by call to _cleanup_ when gprof in */
    _chanOP_save_tty();

    if (pgmerr == ERR_ok)
	return(0);
    else
	return(-1);
}


/*
 * Routine to compare user-defined signals (strings).
 * Internal signals are integers between 0 and MAX_INTERNAL_ERROR.
 */
#undef errcmp
#ifndef LINUX

bool
errcmp(char *s1, char *s2)
{
    if ((long)s1 > 0 && (long)s1 < MAX_INTERNAL_ERROR) return (false);
    if ((long)s2 > 0 && (long)s2 < MAX_INTERNAL_ERROR) return (false);
    return (!strcmp(s1, s2));
}

#else  /* LINUX */

bool
errcmp(char *s1, char *s2)
{
    long longs1 = (long)s1;
    long longs2 = (long)s2;
    if (longs1 < 0 && longs1 > -MAX_INTERNAL_ERROR) {
	longs1 = -longs1;
	s1 = (char *)longs1;
    }
    if (longs2 < 0 && longs2 > -MAX_INTERNAL_ERROR) {
	longs2 = -longs2;
	s2 = (char *)longs2;
    }
    // if ((long)s1 < 0 && (long)s1 > -MAX_INTERNAL_ERROR) (long)s1 = -(long)s1;
    // if ((long)s2 < 0 && (long)s2 > -MAX_INTERNAL_ERROR) (long)s2 = -(long)s2;
    if ((long)s1 > 0 && (long)s1 < MAX_INTERNAL_ERROR) return (false);
    if ((long)s2 > 0 && (long)s2 < MAX_INTERNAL_ERROR) return (false);
    return (!strcmp(s1, s2));
}
#endif	/* LINUX */


/* Routine to produce the unhandled exception string */
void
pclu_unhandled(errcode err)
{
    CLUREF tempstr;
    CLUREF headstr;

    if (err != ERR_failure)
	tempstr = _pclu_erstr(err);
    else
	tempstr = elist[0];

    err = stringOPcons("unhandled exception: ", CLU_1, CLU_21, &headstr);
    if (err != ERR_ok) {
	fprintf(stderr, " death in _pclu_unhandled\n");
	exit(-1);
    }
    err = stringOPconcat(headstr, tempstr, &elist[0]);
    if (err != ERR_ok) {
	fprintf(stderr, " death in _pclu_unhandled\n");
	exit(-1);
    }
}


/* Routine to convert a unix error to a string */
CLUREF
_unix_erstr(int num)
{
    const char * temp;
    CLUREF temp_str, sz;

    temp = strerror(num);
    sz.num = strlen(temp);
    stringOPcons(temp, CLU_1, sz, &temp_str);
    return(temp_str);
}


const char * const clu_errlist[] = {
#define	CLU_errlist_init(_name) [-ERR_ ## _name] = #_name
    CLU_errlist_init(ok),
    CLU_errlist_init(overflow),
    CLU_errlist_init(negative_exponent),
    CLU_errlist_init(zero_divide),
    CLU_errlist_init(break),
    CLU_errlist_init(iterbodyexit),
    CLU_errlist_init(iterbodysignal),
    CLU_errlist_init(iterbodyreturn),
    CLU_errlist_init(bounds),
    CLU_errlist_init(failure),
    CLU_errlist_init(illegal_char),
    CLU_errlist_init(badfmt),
    CLU_errlist_init(negative_size),
    CLU_errlist_init(heap_exhausted),
    CLU_errlist_init(not_possible),
    CLU_errlist_init(toobig),
    CLU_errlist_init(not_found),
    CLU_errlist_init(bad_format),
    CLU_errlist_init(end_of_file),
    CLU_errlist_init(permanent),
    CLU_errlist_init(illegal_stream),
    CLU_errlist_init(no_limit),
    CLU_errlist_init(negative_field_width),
    CLU_errlist_init(wrong_tag),
    CLU_errlist_init(wrong_type),
    CLU_errlist_init(found),
    CLU_errlist_init(illegal_field_width),
    CLU_errlist_init(undefined),
    CLU_errlist_init(insufficient_field_width),
    CLU_errlist_init(script_failed),
    CLU_errlist_init(iterforbodyexit),
    CLU_errlist_init(iterforbodysignal),
    CLU_errlist_init(iterforbodyreturn),
    CLU_errlist_init(none),
    CLU_errlist_init(illegal_size),
    CLU_errlist_init(bad_code),
    /* 36..49 are unallocated */
    CLU_errlist_init(a_cons),
    CLU_errlist_init(abstract),
    CLU_errlist_init(anyize),
    CLU_errlist_init(bad),
    CLU_errlist_init(cont),
    CLU_errlist_init(eof),
    CLU_errlist_init(error),
    CLU_errlist_init(exists),
    CLU_errlist_init(extra),
    CLU_errlist_init(finish),
    CLU_errlist_init(illegal),
    CLU_errlist_init(include_failed),
    CLU_errlist_init(local),
    CLU_errlist_init(no_directive),
    CLU_errlist_init(no_du),
    CLU_errlist_init(open_failed),
    CLU_errlist_init(recons),
    CLU_errlist_init(specs_exist),
    CLU_errlist_init(toohard),
    CLU_errlist_init(underflow),
    CLU_errlist_init(negative_time),
    CLU_errlist_init(negative_multiplier),
    CLU_errlist_init(bad_divisor),
    CLU_errlist_init(bad_size),
    CLU_errlist_init(change),
    CLU_errlist_init(empty),
    CLU_errlist_init(invalid_format),
    CLU_errlist_init(illegal_signal),
    CLU_errlist_init(no_server),
    CLU_errlist_init(timeout),
    CLU_errlist_init(bad_address),
    CLU_errlist_init(complex_result),
    CLU_errlist_init(unterminated_quote),
    CLU_errlist_init(specs_missing),
    CLU_errlist_init(duplicate),
#undef	CLU_errlist_init
};

const char * const clu_uerrlist[] = {
#define	CLU_uerrlist_init(_name) [-ERR_ ## _name - UMINERR] = #_name
    CLU_uerrlist_init(missing),
    CLU_uerrlist_init(already_flattened),
#undef	CLU_uerrlist_init
};


/* Routine to convert a clu signal to a string */
CLUREF
_pclu_erstr(errcode sig)
{
    const char *temp;
    CLUREF temp_str, sz;

    /* small negative integer is a predefined error */
    if (sig <= 0 && sig > -MAX_INTERNAL_ERROR) {
	size_t e = -sig;
	char buf[32];

	temp = NULL;
	if (e < __arraycount(clu_errlist)) {
	    temp = clu_errlist[e];
	}
	else if (e >= UMINERR
		 && (e - UMINERR) < __arraycount(clu_uerrlist))
	{
	    temp = clu_uerrlist[e - UMINERR];
	}

	/* outside the ranges or in an unallocated gap */
	if (temp == NULL) {
	    snprintf(buf, sizeof(buf), "unknown_error_%zu", e);
	    temp = buf;
	}
	sz.num = strlen(temp);
    }
    /* otherwise it's a C string */
    else {
	temp = (const char *)sig;
	size_t len = strlen(temp);

	/* usually "ERR_some_error" */
	const char prefix[4] = "ERR_";
	if (len > sizeof(prefix)
	    && strncmp(temp, prefix, sizeof(prefix)) == 0)
	{
	    temp += sizeof(prefix);
	    len -= sizeof(prefix);
	}
	else if (len == 0) {
	    temp = "<empty>";
	    len = strlen(temp);
	}
	sz.num = len;
    }

    stringOPcons(temp, CLU_1, sz, &temp_str);
    return(temp_str);
}


#define CLU_ERR_STRING 17
const char * const clu_err_string_list[CLU_ERR_STRING] = {
    "illegal access mode",
    "cannot write to this _chan",
    "unknown error",
    "cannot read from this _chan",
    "cannot duplicate _chan",
    "_chan is closed",
    "not a terminal _chan",
    "speeds unknown",
    "array bounds overflow",
    "cannot get connected directory",
    "bad format",
    "huge allocation request",
    "cannot read from input _chan",
    "cannot write to output _chan",
    "cannot write to error _chan",
    "no return values",
    "array bounds exception"
};

CLUREF 	illegal_access_mode_STRING;
CLUREF	cannot_write_to_this__chan_STRING;
CLUREF	unknown_error_STRING;
CLUREF	cannot_read_from_this__chan_STRING;
CLUREF	cannot_duplicate__chan_STRING;
CLUREF	_chan_is_closed_STRING;
CLUREF	not_a_terminal__chan_STRING;
CLUREF	speeds_unknown_STRING;
CLUREF	array_bounds_overflow_STRING;
CLUREF	cannot_get_connected_directory_STRING;
CLUREF	bad_format_STRING;
CLUREF	huge_allocation_request_STRING;
CLUREF	cannot_read_from_input__chan_STRING;
CLUREF	cannot_write_to_output__chan_STRING;
CLUREF	cannot_write_to_error__chan_STRING;
CLUREF	no_return_values_STRING;
CLUREF	array_bounds_exception_STRING;

CLUREF * const clu_glob_err_string_list[CLU_ERR_STRING] = {
    &illegal_access_mode_STRING,
    &cannot_write_to_this__chan_STRING,
    &unknown_error_STRING,
    &cannot_read_from_this__chan_STRING,
    &cannot_duplicate__chan_STRING,
    &_chan_is_closed_STRING,
    &not_a_terminal__chan_STRING,
    &speeds_unknown_STRING,
    &array_bounds_overflow_STRING,
    &cannot_get_connected_directory_STRING,
    &bad_format_STRING,
    &huge_allocation_request_STRING,
    &cannot_read_from_input__chan_STRING,
    &cannot_write_to_output__chan_STRING,
    &cannot_write_to_error__chan_STRING,
    &no_return_values_STRING,
    &array_bounds_exception_STRING
};

static errcode
clu_err_string_init(void)
{
    for (size_t i = 0; i < CLU_ERR_STRING; ++i) {
	CLUREF *dst = clu_glob_err_string_list[i];
	const char *src = clu_err_string_list[i];
	size_t len = strlen(src);

	stringOPcons(src, CLU_1, CLUREF_make_num(len), dst);
    }
    return ERR_ok;
}


char *
mystrcat(const char *s1, const char *s2)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    size_t size = len1 + len2 + 1;

    char *temp = (char *)gc_malloc(size);
    memcpy(&temp[0], s1, len1);
    memcpy(&temp[len1], s2, len2 + 1);

    return temp;
}
