/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						  */
/*	sys.h				          */
/*						  */
/*	Defines system constants		  */

#ifndef PCLU_SYS
#define PCLU_SYS

#include <limits.h>
#include <stddef.h>
#include <string.h>

#define __CLU_COMMON  __attribute__((__common__))

#define CLU_NOREF(var) ((void)(var))

#define	CLU_roundup(x, y)	((((x)+((y)-1))/(y))*(y))


#ifdef LINUX
#define gcollect GC_gcollect
#define gc_init GC_init
#define expand_hp GC_expand_hp
#define gc_malloc GC_malloc
#endif
#undef qsort
#define dmd_gc gcollect
#define get_sp get_current_sp
#define _exit _OPexit
#define _environ _OPenviron
#define UNINIT 0xdeadffff
#define MAX_SIG_VALS 	10
#define intOPleastint	(-0x7fffffff-1)
#define intOPmaxint	0X7FFFFFFF
#define intOPsqrtmax	46341
#define intOPmaxdigits   20

#define UNIT (sizeof(long))

#define log OPlog

#ifdef CLU_DEBUG
#define signal(x) if (CLU_TRACE) debugOPleave_proc(x) ; return((long)x)
#else
#define signal(x) return((long)x)
#endif

#ifdef CLU_DEBUG
#define enter_proc(x) locals.DBG_LINE = x; if (CLU_TRACE) debugOPenter_proc(&locals)
#else
#define enter_proc(x)
#endif

#ifdef CLU_DEBUG
#define enter_own_init_proc() if (CLU_TRACE) debugOPenter_proc(-1)
#else
#define enter_own_init_proc()
#endif

#ifdef CLU_DEBUG
#define enter_iter_body_proc(x) locals->DBG_LINE = x; if (CLU_TRACE) debugOPenter_forbody(locals)
#else
#define enter_iter_body_proc(x)
#endif

#ifdef CLU_DEBUG
#define LINE(x) {locals.DBG_LINE = x; \
	        if (CLU_TRACE && MY_TRACE_FLAG) debugOPbegin_line(x);}
#else
#define LINE(x)
#endif

#ifdef CLU_DEBUG
#define FB_LINE(x) {locals->DBG_LINE = x; \
		   if (CLU_TRACE && MY_TRACE_FLAG) debugOPbegin_line(x);}
#else
#define FB_LINE(x)
#endif

#define clu_signal(x) return((long)x)
#define resignal(x) do {				\
	    if ((x) == ERR_ok || (x) == ERR_failure)	\
		return (errcode)(x);			\
	    elist[0] = _pclu_erstr((x));		\
	    return ERR_failure;				\
	} while (0)

#ifndef BOOL
typedef long bool;
#define BOOL
#endif
typedef long gcd_tab;
typedef char * string;

#define true 1
#define false 0

#ifndef NULL
#define NULL ((char *)0)
#endif

#define VARYING_LENGTH 1

/* GCD_REF_SIZE defines the number of bytes that gcd_tab outputs for */
/*	a small base type or a reference */
#define GCD_REF_SIZE (2*CLUREFSZ)

/*					*/
/*	HEADER DEFINITIONS		*/
/*					*/


/* definitions of CLUTYPE val field */
/* (AGG for aggregate covers records, structs, sequences */
/* (VAR for variant or variable covers oneofs, variants, anys */

#define CT_STRING 1
#define CT_ARRAY  2
#define CT_AGG	  3
#define CT_VAR    4
#define CT_PROC   5
#define CT_STORE  6
#define CT_TAG	  7
#define CT_REC	  8

/* may want to adjust string and header definition s.t. only
   32 bits are used for the header and the size field */

typedef struct  {
	char	mark;	/* 4 bits for gc/alloc */
	char	val;    /* type identifier */
	char	refp;   /* immediate vs indirect */
	char	spare;
	} CLUTYPE;

/*
 * The following is spelled in a somewhat roundabout way b/c gcc can
 * optimize it into a single word store, but for some reason can't do
 * that for a direct assignment of a compound literal.
 */
#if 0
#define CLUTYPE_set(_typ, _val) do {		\
	    _typ = (CLUTYPE){ .val = (_val) };	\
	} while (0)
#else
#define CLUTYPE_set(_typ, _val) do {				\
	    const CLUTYPE _clutype_val = { .val = (_val) };	\
	    _typ = _clutype_val;				\
	} while (0)
#endif



/*					*/
/*	STRING DEFINITIONS		*/
/*					*/


typedef char * C_STRING;

/* #define CLUSTR(x) string$cons(x, 1, strlen(x)) */

typedef struct {
	CLUTYPE   typ;
	long	  size;
	char	  data[1];
	} CLU_string;
typedef CLU_string *CLUSTRING;

#define MAX_STR 150000
#define MIN_CAP_CHAR 'A'
#define MAX_CAP_CHAR 'Z'
#define OFF_CHAR 'a' - 'A'

/*					*/
/*	SEQUENCE DEFINITIONS		*/
/*					*/

typedef struct {
	CLUTYPE	typ;
	long	size;
	long	data[1];     /* CLUREF in disguise */
	} CLU_sequence;

#define CLU_sequence_sizew 2


typedef CLU_sequence *CLUSEQ;

#define MAX_SEQ 262144			/* matches VAX CLU */

/*					*/
/*	ONEOF DEFINITIONS		*/
/*					*/

#define nil 0

typedef struct {
	CLUTYPE typ;
	long	tag;
	long	value;
} CLU_cell;
#define CLU_cell_sizew 3	/* size of cell in 32-bit units */
#define cellOPmaxtag 0x3fffffff

typedef CLU_cell *CLUCELL;

/*					*/
/*	OWN PTR DEFINITIONS		*/
/*					*/


typedef struct {
long	init_flag;
long	info[VARYING_LENGTH];	/* CLUREF in disguise */
} OWN_ptr;

typedef  OWN_ptr *OWNPTR;


/*					*/
/*	OWN REQ DEFINITION		*/
/*					*/


typedef struct {
long	size;		/* sizeof own structure needed */
			/*    own structure includes owns, parm values, hints */
long	own_count;	/* number of owns */
} OWN_req;

typedef  OWN_req *OWNREQ;

/*					*/
/*	PROC VAR DEFINITIONS		*/
/*					*/

#define MAX_CONST_PARMS 7

typedef errcode PROC();
typedef struct {
	CLUTYPE typ;
	errcode (*proc)();
	OWNPTR	type_owns;
	OWNPTR  op_owns;
	} CLU_proc;

typedef CLU_proc *CLUPROC;


/*					*/
/*	ARRAY DEFINITIONS		*/
/*					*/

/* arrays are implemented as two objects:		*/
/*		the array descriptor and the store      */
/*		user code sees only the descriptor	*/
/*		and the contents of the store		*/
/*		the implementation uses the store	*/
/*		to hold the user data			*/
/*		the store can be reallocated when	*/
/*		necessary				*/

typedef struct {
	CLUTYPE typ;
	long	size;
	long	data[1];	/* CLUREF in disguise */
	} CLU_store;

typedef CLU_store *CLUSTORE;
#define CLU_store_sizew 3

typedef struct {
	CLUTYPE typ;
	long	ext_low;	/* low index for user */
	long	ext_high;	/* high index for user */
	long	ext_size;	/* size for user */
	long	int_low;	/* index into store equiv to ext_low */
	long	int_size;	/* size of store */
	CLUSTORE store;
	} CLU_array;
#define CLU_array_sizew 7

typedef CLU_array *CLUARRAY;

#define MIN_ARR_INDEX intOPleastint
#define MAX_ARR_INDEX intOPmaxint
#define MAX_ARR_SIZE  (MAX_ARR_INDEX/2)

/*					*/
/*	CLUREF DEFINITIONS		*/
/*					*/


/* These are the types known by the clu runtime system */

/* may have to adjust these declarations for machines where
   a reference to a char is longer than a reference to an long */

/* possibly define CLUREF twice, once with just base types
   so that aggregates can be defined, and then the second
   time including the aggregates */

typedef union {
	char 	*ref;
	long	num;
	float	real;
	char	ch;
	bool	tf;
	unsigned short word;
	CLUSTRING str;
	CLUSEQ  vec;
	CLUCELL cell;
	CLUPROC proc;
	CLUARRAY array;
	CLUSTORE store;
	struct obj * obj;
} CLUREF;

#define CLUREFSZ (sizeof(CLUREF))

#define CLUREF_make_ch(c)	((CLUREF){ .ch = (c) })
#define CLUREF_make_num(n)	((CLUREF){ .num = (n) })
#define CLUREF_make_tf(b)	((CLUREF){ .tf = (b) })

#define CLU_false	CLUREF_make_tf(false)
#define CLU_true	CLUREF_make_tf(true)


/* Entry point of a CLU program in the C code emitted by the compiler */
errcode start_up(void);

/* dumb stuff for alpha */
extern errcode arrayOPnew();
extern errcode arrayOPaddh();

/* calls to private OPs emitted by the compiler */
extern errcode proctypeOPnew(CLUREF nops, CLUREF *ans);
extern errcode sequenceOPnew2(CLUREF size, CLUREF *ans);
extern errcode stringOPcons(const char *buf, CLUREF start, CLUREF len, CLUREF *ans);


#ifdef CLU_DEBUG
extern long CLU_TRACE;
extern errcode debugOPenter_proc();
extern errcode debugOPenter_forbody();
extern errcode debugOPleave_proc();
extern errcode debugOPbegin_line();
#endif

extern errcode force();

extern struct obj **NewObjPtr;

/*
 * Calling convention for parmd applies is to set CUR_PROC_VAR pointer
 * in the caller to supply type and op owns for the callee and the
 * compiler uses generic_CLU_proc as global storage for that.
 */
extern CLU_proc generic_CLU_proc;
extern CLUREF CUR_PROC_VAR; /* usually = { .proc = &generic_CLU_proc } */

extern struct OPS NO_OPS;
extern struct OPS *NULL_OPS;
#define zero_ops (struct OPS**)0
#define m1_ops (struct OPS**)-1

extern void bcopy();
extern void perror();

extern void clu_alloc();
extern void clu_alloc_atomic();

CLUREF _pclu_erstr(errcode sig);
CLUREF _unix_erstr(int num);
void pclu_unhandled(errcode err);

typedef CLUREF errlist[MAX_SIG_VALS];
extern errlist elist;

/*	Storage allocation macros	*/

/*	usage: Alloc(size_in_words, result_name) */

#ifndef LINUX
#ifdef MERGE_SIZES
extern long size_map[];
#define FL_SIZE_MAP(sz) (size_map[sz])
#else
#define FL_SIZE_MAP(sz) (sz)
#endif
#endif

#ifdef LINUX
#define allocobj _allocobj
#endif

#define athena

#define Alloc(Size, Result) \
	     NewObjPtr = &(objfreelist[FL_SIZE_MAP(Size)]); \
	     if(*NewObjPtr == (struct obj *)0) allocobj(Size); \
	     Result.obj = *NewObjPtr; \
	     *NewObjPtr = Result.obj->obj_link; \
	     Result.obj->obj_link = 0;

#ifdef athena
extern errcode oneofOPnew(CLUREF tag, CLUREF val, CLUREF *ans);
extern errcode recordOPnew(CLUREF size, CLUREF *ans);

#define RecordAlloc(Size, Result) \
	    recordOPnew(CLUREF_make_num(Size), &Result)
#define CellAlloc(Tag, Value, Result) \
	    oneofOPnew(CLUREF_make_num(Tag), CLUREF_make_num(Value), &Result)
#else
#define RecordAlloc(Size, Result) \
	     Alloc(Size + CLU_sequence_sizew, Result); \
	     Result.vec->typ.val = CT_REC; \
	     Result.vec->size = Size;

#define CellAlloc(Tag, Value, Result) \
	     Alloc(CLU_cell_sizew, Result); \
	     Result.cell->typ.val = CT_VAR; \
	     Result.cell->tag = Tag; \
	     Result.cell->value = Value;
#endif

/* 	Names for commonly used strings */

extern CLUREF	CLU_empty_string;
extern CLUREF 	illegal_access_mode_STRING;
extern CLUREF	cannot_write_to_this__chan_STRING;
extern CLUREF	unknown_error_STRING;
extern CLUREF	cannot_read_from_this__chan_STRING;
extern CLUREF	_chan_is_closed_STRING;
extern CLUREF	not_a_terminal__chan_STRING;
extern CLUREF	speeds_unknown_STRING;
extern CLUREF	array_bounds_overflow_STRING;
extern CLUREF	cannot_get_connected_directory_STRING;
extern CLUREF	bad_format_STRING;
extern CLUREF	huge_allocation_request_STRING;
extern CLUREF	cannot_read_from_input__chan_STRING;
extern CLUREF	cannot_write_to_output__chan_STRING;
extern CLUREF	cannot_write_to_error__chan_STRING;
extern CLUREF	cannot_duplicate__chan_STRING;
extern CLUREF	no_return_values_STRING;
extern CLUREF	array_bounds_exception_STRING;

/*							*/
/*		externs for common integers		*/
/*							*/

#define CLU_0	CLUREF_make_num(0)
#define CLU_1	CLUREF_make_num(1)
#define CLU_2	CLUREF_make_num(2)
#define CLU_3	CLUREF_make_num(3)
#define CLU_4	CLUREF_make_num(4)
#define CLU_5	CLUREF_make_num(5)
#define CLU_6	CLUREF_make_num(6)
#define CLU_7	CLUREF_make_num(7)
#define CLU_8	CLUREF_make_num(8)
#define CLU_9	CLUREF_make_num(9)
#define CLU_10	CLUREF_make_num(10)
#define CLU_11	CLUREF_make_num(11)
#define CLU_12	CLUREF_make_num(12)
#define CLU_13	CLUREF_make_num(13)
#define CLU_14	CLUREF_make_num(14)
#define CLU_15	CLUREF_make_num(15)
#define CLU_16	CLUREF_make_num(16)
#define CLU_17	CLUREF_make_num(17)
#define CLU_18	CLUREF_make_num(18)
#define CLU_19	CLUREF_make_num(19)
#define CLU_20	CLUREF_make_num(20)
#define CLU_21	CLUREF_make_num(21)
#define CLU_22	CLUREF_make_num(22)
#define CLU_23	CLUREF_make_num(23)
#define CLU_24	CLUREF_make_num(24)
#define CLU_25	CLUREF_make_num(25)
#define CLU_26	CLUREF_make_num(26)
#define CLU_27	CLUREF_make_num(27)
#define CLU_28	CLUREF_make_num(28)
#define CLU_29	CLUREF_make_num(29)
#define CLU_30	CLUREF_make_num(30)
#define CLU_31	CLUREF_make_num(31)
#define CLU_32	CLUREF_make_num(32)
#define CLU_33	CLUREF_make_num(33)
#define CLU_34	CLUREF_make_num(34)
#define CLU_35	CLUREF_make_num(35)
#define CLU_36	CLUREF_make_num(36)
#define CLU_37	CLUREF_make_num(37)
#define CLU_38	CLUREF_make_num(38)
#define CLU_39	CLUREF_make_num(39)
#define CLU_40	CLUREF_make_num(40)
#define CLU_41	CLUREF_make_num(41)
#define CLU_42	CLUREF_make_num(42)
#define CLU_43	CLUREF_make_num(43)
#define CLU_44	CLUREF_make_num(44)
#define CLU_45	CLUREF_make_num(45)
#define CLU_46	CLUREF_make_num(46)
#define CLU_47	CLUREF_make_num(47)
#define CLU_48	CLUREF_make_num(48)
#define CLU_49	CLUREF_make_num(49)
#define CLU_50	CLUREF_make_num(50)


/*							*/
/*		GENERIC PARAMETER DEFINITIONS		*/
/*							*/
struct REQ_ENTRY {
    const char *name;
};

typedef struct REQS {
    long count;
    const struct REQ_ENTRY entry[VARYING_LENGTH];
} REQS;

struct OP_ENTRY {
    CLUPROC fcn;
    const char *name;
};

typedef struct OPS {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[VARYING_LENGTH];
} OPS;

typedef struct OPS *OPSPTR;


errcode add_selector_info(const char *field_name, long index, const struct OPS *ops);
errcode find_selector_ops(const char *selname, long nfields, OPSPTR *table);


void add_parm_info_type(long index, const struct OPS *ops, const struct REQS *reqs);
void add_parm_info_const(long index, CLUREF value);

errcode find_type_instance(const struct OPS *aops,
			   long nparm, const OWN_req *ownreqp,
			   struct OPS **result);
errcode find_typeop_instance(const struct OPS *aops,
			     errcode (*procaddr)(),
			     long nparm, long ntparm,
			     const OWN_req *ownreqp, const OWN_req *townreqp,
			     struct OPS **result);
errcode find_prociter_instance(errcode (*procaddr)(),
			       long nparm, const OWN_req *ownreqp,
			       struct OPS **result);


typedef struct {
    long hdr;
    long count;
} Slist0;

extern const Slist0 NO_PARMS;

#define defslist(N)				\
    typedef struct Slist ## N {			\
        long hdr;				\
        long count;				\
        const char *nm[N];			\
    } Slist ## N

defslist(1);			/* Slist1 */
defslist(2);			/* Slist2 */
defslist(3);			/* Slist3 */
defslist(4);			/* Slist4 */


typedef struct var_desc {
    long hdr;
    long count;
    const char *nm;
    struct OPS **ops;
    const char *nm_ops;
} var_desc;

typedef struct {
    long hdr;
    long count;
} Vlist0;

extern const Vlist0 NO_VALS;

#define defvlist(N)				\
    typedef struct Vlist ## N {			\
	long hdr;				\
	long count;				\
	var_desc vds[N];			\
    } Vlist ## N

defvlist(1);			/* Vlist1 */
defvlist(2);			/* Vlist2 */
defvlist(3);			/* Vlist3 */
defvlist(4);			/* Vlist4 */
defvlist(5);			/* Vlist5 */
defvlist(6);			/* Vlist6 */
defvlist(7);			/* Vlist7 */
defvlist(8);			/* Vlist8 */
defvlist(9);			/* Vlist9 */
defvlist(10);			/* Vlist10 */
defvlist(11);			/* Vlist11 */
defvlist(12);			/* Vlist12 */
defvlist(13);			/* Vlist13 */
defvlist(14);			/* Vlist14 */
defvlist(15);			/* Vlist15 */
defvlist(16);			/* Vlist16 */
defvlist(17);			/* Vlist17 */
defvlist(18);			/* Vlist18 */
defvlist(19);			/* Vlist19 */
defvlist(20);			/* Vlist20 */
defvlist(21);			/* Vlist21 */
defvlist(22);			/* Vlist22 */
defvlist(23);			/* Vlist23 */
defvlist(24);			/* Vlist24 */
defvlist(25);			/* Vlist25 */
defvlist(26);			/* Vlist26 */
defvlist(27);			/* Vlist27 */
defvlist(28);			/* Vlist28 */
defvlist(29);			/* Vlist29 */
defvlist(30);			/* Vlist30 */
defvlist(31);			/* Vlist31 */
defvlist(32);			/* Vlist32 */
defvlist(33);			/* Vlist33 */
defvlist(34);			/* Vlist34 */
defvlist(35);			/* Vlist35 */
defvlist(36);			/* Vlist36 */
defvlist(37);			/* Vlist37 */
defvlist(38);			/* Vlist38 */
defvlist(39);			/* Vlist39 */
defvlist(40);			/* Vlist40 */
defvlist(41);			/* Vlist41 */
defvlist(42);			/* Vlist42 */
defvlist(43);			/* Vlist43 */
defvlist(44);			/* Vlist44 */
defvlist(45);			/* Vlist45 */
defvlist(46);			/* Vlist46 */
defvlist(47);			/* Vlist47 */
defvlist(48);			/* Vlist48 */
defvlist(49);			/* Vlist49 */


typedef struct {
    long hdr;
    long count;
    const char *nm;
    Vlist0 vals;
} sig_desc;

#define defsig_desc(N)				\
    typedef struct sig_desc ## N {		\
	long hdr;				\
	long count;				\
	const char *nm;				\
	Vlist ## N vals;			\
    } sig_desc ## N

defsig_desc(0);			/* sig_desc0 */
defsig_desc(1);			/* sig_desc1 */
defsig_desc(2);			/* sig_desc2 */
defsig_desc(3);			/* sig_desc3 */
defsig_desc(4);			/* sig_desc4 */


typedef struct {
    long hdr;
    long count;
} siglist0;

#define defsiglist(N)				\
    typedef struct siglist ## N {		\
	long hdr;				\
	long count;				\
	const sig_desc *asig[N];		\
    } siglist ## N

defsiglist(1);			/* siglist1 */
defsiglist(2);			/* siglist2 */
defsiglist(3);			/* siglist3 */
defsiglist(4);			/* siglist4 */
defsiglist(5);			/* siglist5 */
defsiglist(6);			/* siglist6 */
defsiglist(7);			/* siglist7 */
defsiglist(8);			/* siglist8 */
defsiglist(9);			/* siglist9 */
defsiglist(10);			/* siglist10 */

#endif	/* !PCLU_SYS */
