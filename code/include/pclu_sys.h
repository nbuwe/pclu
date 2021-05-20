#ifndef PCLU_SYS
#define PCLU_SYS

/* Copyright Massachusetts Institute of Technology 1990,1991 */

/* $Header: pclu_sys.h,v 1.4 91/05/06 12:21:49 dcurtis Exp $ */
/* $Log:	pclu_sys.h,v $
 * Revision 1.4  91/05/06  12:21:49  dcurtis
 * *** empty log message ***
 * 
 * Revision 1.3  91/05/02  15:17:02  dcurtis
 * replaced a constant with a define for MAX_SIG_VALS
 * 	to ease future changes
 * 
 * Revision 1.2  91/04/02  19:40:46  mtv
 * Removed redundannt code from RecordAlloc and CellAlloc macros.
 * Updated allocation macros to work with (or without) MERGE_SIZES.
 * 
 * Revision 1.1  91/03/23  16:09:37  mtv
 * Initial revision
 * 
 */

/*						  */
/*	sys.h				          */
/*						  */
/*	Defines system constants		  */

#ifdef sparc
#include <sys/param.h>
#endif

#ifndef INT_MIN
#include <limits.h>
#endif

#include <string.h>


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
#define intOPleastint	0X80000000
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
#define resignal(x) \
	{if ((x) == ERR_failure || (x) == ERR_ok) return((long)x);  \
	elist[0] = _pclu_erstr((x)); \
	return(ERR_failure); \
	}

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

#define CLUREF_make_num(n) ((CLUREF){ .num = (n) })


/* Entry point of a CLU program in the C code emitted by the compiler */
errcode start_up(void);

/* dumb stuff for alpha */
extern errcode arrayOPnew();
extern errcode arrayOPaddh();

/* calls to private OPs emitted by the compiler */
extern errcode proctypeOPnew(CLUREF nops, CLUREF *ans);
extern errcode sequenceOPnew2(CLUREF size, CLUREF *ans);
extern errcode stringOPcons(const char *buf, CLUREF start, CLUREF len, CLUREF *ans);


extern CLUREF CUR_PROC_VAR;
extern long CLU_TRACE;
extern errcode debugOPenter_proc();
extern errcode debugOPenter_forbody();
extern errcode debugOPleave_proc();
extern errcode debugOPbegin_line();
extern errcode force();
extern struct OPS NO_OPS;
extern struct obj **NewObjPtr;
#ifndef CLU_sysasm_util_impl
extern CLU_proc generic_CLU_proc;
extern CLUREF CLU_string_size;
extern struct OPS *NULL_OPS;
#endif
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

extern CLUREF	clu_empty_string;
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

struct REQS {
    long count;
    struct REQ_ENTRY entry[VARYING_LENGTH];
} REQS;

struct OP_ENTRY {
    CLUPROC fcn;
    const char *name;
};

struct OPS {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[VARYING_LENGTH];
} OPS;

typedef struct OPS *OPSPTR;

typedef struct {
    long count;
    const char *name[VARYING_LENGTH];
} RLIST;

typedef struct {
    RLIST *param[VARYING_LENGTH];
} PTABLE;

typedef struct {
    char *name;
    errcode (*proc)();
    bool restricted;
    PTABLE *_restrict;
} TG_ENTRY;

typedef struct {
    long pcount;		    /* number of parameters */
    long count;			    /* number of operations */
    TG_ENTRY entry[VARYING_LENGTH]; /* one per operation    */
} TG_OPS;

struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[VARYING_LENGTH];
} TABLE;


errcode add_selector_info(const char *field_name, long index, OPSPTR ops);
errcode find_selector_ops(const char *selname, long nfields, OPSPTR *table);


void add_parm_info_type(long index, struct OPS *ops, const struct REQS *reqs);
void add_parm_info_const(long index, CLUREF value);

errcode find_type_instance(struct OPS *aops,
			   long nparm, OWNREQ ownreqp,
			   struct OPS **result);
errcode find_typeop_instance(struct OPS *aops,
			     errcode (*procaddr)(),
			     long nparm, long ntparm,
			     OWNREQ ownreqp, OWNREQ townreqp,
			     struct OPS **result);
errcode find_prociter_instance(errcode (*procaddr)(),
			       long nparm, OWNREQ ownreqp,
			       struct OPS **result);


typedef struct {
	long hdr;
	long count;
	} Slist0;
extern Slist0 NO_PARMS;

typedef struct {
	long hdr;
	long count;
	char *nm[1];
	} Slist1;

typedef struct {
	long hdr;
	long count;
	char *nm[2];
	} Slist2;

typedef struct {
	long hdr;
	long count;
	char *nm[3];
	} Slist3;

typedef struct {
	long hdr;
	long count;
	char *nm[4];
	} Slist4;

typedef struct {
	long  hdr;
	long  count;
	char *nm;
	struct OPS **ops;
	char *nm_ops;
	} var_desc;

typedef struct {
	long hdr;
	long count;
	} Vlist0;
extern Vlist0 NO_VALS;

typedef struct {
	long hdr;
	long count;
	var_desc vds[1];
	} Vlist1;

typedef struct {
	long hdr;
	long count;
	var_desc vds[2];
	} Vlist2;

typedef struct {
	long hdr;
	long count;
	var_desc vds[3];
	} Vlist3;

typedef struct {
	long hdr;
	long count;
	var_desc vds[4];
	} Vlist4;

typedef struct {
	long hdr;
	long count;
	var_desc vds[5];
	} Vlist5;

typedef struct {
	long hdr;
	long count;
	var_desc vds[6];
	} Vlist6;

typedef struct {
	long hdr;
	long count;
	var_desc vds[7];
	} Vlist7;

typedef struct {
	long hdr;
	long count;
	var_desc vds[8];
	} Vlist8;

typedef struct {
	long hdr;
	long count;
	var_desc vds[9];
	} Vlist9;

typedef struct {
	long hdr;
	long count;
	var_desc vds[10];
	} Vlist10;

typedef struct {
	long hdr;
	long count;
	var_desc vds[11];
	} Vlist11;

typedef struct {
	long hdr;
	long count;
	var_desc vds[12];
	} Vlist12;

typedef struct {
	long hdr;
	long count;
	var_desc vds[13];
	} Vlist13;

typedef struct {
	long hdr;
	long count;
	var_desc vds[14];
	} Vlist14;

typedef struct {
	long hdr;
	long count;
	var_desc vds[15];
	} Vlist15;

typedef struct {
	long hdr;
	long count;
	var_desc vds[16];
	} Vlist16;

typedef struct {
	long hdr;
	long count;
	var_desc vds[17];
	} Vlist17;

typedef struct {
	long hdr;
	long count;
	var_desc vds[18];
	} Vlist18;

typedef struct {
	long hdr;
	long count;
	var_desc vds[19];
	} Vlist19;

typedef struct {
	long hdr;
	long count;
	var_desc vds[20];
	} Vlist20;

typedef struct {
	long hdr;
	long count;
	var_desc vds[21];
	} Vlist21;

typedef struct {
	long hdr;
	long count;
	var_desc vds[22];
	} Vlist22;

typedef struct {
	long hdr;
	long count;
	var_desc vds[23];
	} Vlist23;

typedef struct {
	long hdr;
	long count;
	var_desc vds[24];
	} Vlist24;

typedef struct {
	long hdr;
	long count;
	var_desc vds[25];
	} Vlist25;

typedef struct {
	long hdr;
	long count;
	var_desc vds[26];
	} Vlist26;

typedef struct {
	long hdr;
	long count;
	var_desc vds[27];
	} Vlist27;

typedef struct {
	long hdr;
	long count;
	var_desc vds[28];
	} Vlist28;

typedef struct {
	long hdr;
	long count;
	var_desc vds[29];
	} Vlist29;

typedef struct {
	long hdr;
	long count;
	var_desc vds[30];
	} Vlist30;

typedef struct {
	long hdr;
	long count;
	var_desc vds[31];
	} Vlist31;

typedef struct {
	long hdr;
	long count;
	var_desc vds[32];
	} Vlist32;

typedef struct {
	long hdr;
	long count;
	var_desc vds[33];
	} Vlist33;

typedef struct {
	long hdr;
	long count;
	var_desc vds[34];
	} Vlist34;

typedef struct {
	long hdr;
	long count;
	var_desc vds[35];
	} Vlist35;

typedef struct {
	long hdr;
	long count;
	var_desc vds[36];
	} Vlist36;

typedef struct {
	long hdr;
	long count;
	var_desc vds[37];
	} Vlist37;

typedef struct {
	long hdr;
	long count;
	var_desc vds[38];
	} Vlist38;

typedef struct {
	long hdr;
	long count;
	var_desc vds[39];
	} Vlist39;

typedef struct {
	long hdr;
	long count;
	var_desc vds[40];
	} Vlist40;

typedef struct {
	long hdr;
	long count;
	var_desc vds[41];
	} Vlist41;

typedef struct {
	long hdr;
	long count;
	var_desc vds[42];
	} Vlist42;

typedef struct {
	long hdr;
	long count;
	var_desc vds[43];
	} Vlist43;

typedef struct {
	long hdr;
	long count;
	var_desc vds[44];
	} Vlist44;

typedef struct {
	long hdr;
	long count;
	var_desc vds[45];
	} Vlist45;

typedef struct {
	long hdr;
	long count;
	var_desc vds[46];
	} Vlist46;

typedef struct {
	long hdr;
	long count;
	var_desc vds[47];
	} Vlist47;

typedef struct {
	long hdr;
	long count;
	var_desc vds[48];
	} Vlist48;

typedef struct {
	long hdr;
	long count;
	var_desc vds[49];
	} Vlist49;

typedef struct {
	long hdr;
	long count;
	char *nm;
	Vlist0 vals;
	} sig_desc;

typedef struct {
	long hdr;
	long count;
	char *nm;
	Vlist0 vals;
	} sig_desc0;

typedef struct {
	long hdr;
	long count;
	char *nm;
	Vlist1 vals;
	} sig_desc1;

typedef struct {
	long hdr;
	long count;
	char *nm;
	Vlist2 vals;
	} sig_desc2;

typedef struct {
	long hdr;
	long count;
	char *nm;
	Vlist3 vals;
	} sig_desc3;

typedef struct {
	long hdr;
	long count;
	char *nm;
	Vlist4 vals;
	} sig_desc4;

typedef struct {
	long hdr;
	long count;
	} siglist0;

typedef struct {
	long hdr;
	long count;
	sig_desc *asig[1];
	} siglist1;

typedef struct {
	long hdr;
	long count;
	sig_desc *asig[2];
	} siglist2;

typedef struct {
	long hdr;
	long count;
	sig_desc *asig[3];
	} siglist3;

typedef struct {
	long hdr;
	long count;
	sig_desc *asig[4];
	} siglist4;

typedef struct {
	long hdr;
	long count;
	sig_desc *asig[5];
	} siglist5;

typedef struct {
	long hdr;
	long count;
	sig_desc *asig[6];
	} siglist6;

typedef struct {
        int hdr;
        int count;
        sig_desc *asig[7];
        } siglist7;

typedef struct {
        int hdr;
        int count;
        sig_desc *asig[8];
        } siglist8;

typedef struct {
        int hdr;
        int count;
        sig_desc *asig[9];
        } siglist9;

typedef struct {
        int hdr;
        int count;
        sig_desc *asig[10];
        } siglist10;

#endif	/* !PCLU_SYS */
