#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode debugOPcli(CLUREF source, CLUREF opt1, CLUREF opt2, CLUREF opt3, CLUREF *_int);
extern errcode missing_print_fcn(CLUREF val, CLUREF pst);
extern errcode opown2typeown(CLUREF nm, CLUREF *_string);
extern errcode print_uninit(CLUREF po, CLUREF v);
extern errcode symOPget_address(CLUREF s, CLUREF *_int);

extern char *mystrcat(const char *s1, const char *s2);


/* values for return from debugOPcli */
#define CONT 0
#define STEP 1

/* values for input to debugOPcli */
#define ENTER_PROC 0
#define LEAVE_PROC 1
#define BEGIN_LINE 2
#define GENESIS 4
#define ENTER_FORBODY 5
#define LEAVE_FORBODY 6
#define ENTER_PROC_FAULT 7


typedef struct {
    long hdr;
    long count;
    char  *name;
    char  *fname;
    bool is_iter;
    long is_parmd;
    long addr;
    long nargs;
    Vlist1 *vals;
    siglist1 *sigs;
    Vlist1 *locals;
    Vlist1 *owns;
    Vlist1 *ptowns;
    Vlist1 *popowns;
    Slist1 *type_formals;
    Slist1 *op_formals;
} frame, *framep;

errlist saved_elist[1000];

long CLU_TRACE = 1;

long *stack[1000];	      /* pointers to locals data structures */
CLUREF nmstack[1000];	      /* names of procs on stack */
bool forbodystack[1000]; /* is the corresponding entry the body of a for stmt */
long sp = 0;

/*
	ISSUES: starting afresh
			zero out bss? ?sufficient
			what about the stack? heap?
	        ?force return/signal with values
		signals??? (catch control-c? (probably))
			try to catch segv's?
		onset/(pclu/cc)compiling options/linking options
			getting to debugOPsay_hi at the right time
				allows setting of argv!?
			can -g be detected at compile time? (probably not)

	COMMANDS: help  (top-level/category/command-names/per command)
		  (un)set/show breakpoint at function entry
		  	breakpoint at line
				breakpoint could stop or just log
		  look at stack
		  continue
		  single step
				(n turns on single stepping, c turns off ss)
		  run (see above/issues)
		  move up/down stack
				(set current frame for var printing, listing)
		  list relevant source code
		  print/set variable
			print all own variables for this routine
		  cause routine to execute
			parse name & use get_addr & call_clu
			parse arguments (??)
			optionally save result for future use ( :=/= )
		  trace signals
		  ?use compiler technology for expression parsing?
			for variable setting/expr eval
		  ?force return/signal with values
		  variables
		  quit

	FLUFF: 	command_line editting
		command synonyms ala CLU
		use <dir> command, encode filename (w/o dir) in debug info
		func command: specify current func for listing, line breaks
		single character input (see command line editting)
		base 10 vs base 16 vs base 8
		set command line arguments
		tags support
	       	when in proc_P print var_V
	       	trace var_V in proc_P
		log input to a file
		log output to a file
	       	take input from a file
		aliases
		looking at raw memory
		output windowing
*/


void
save_elist(long ind)
{
    for (long i = 0; i < MAX_SIG_VALS; ++i)
	saved_elist[ind][i] = elist[i];
}


void
restore_elist(long ind)
{
    for (long i = 0; i < MAX_SIG_VALS; ++i)
	elist[i] = saved_elist[ind][i];
}


errcode
debugOPenter_proc(long *localsp)
{
    CLUREF mode;
    framep fp;
    CLUREF nm, code, spref, size;
    long i;
    CLUREF argnm;

    if (localsp == (long *)-1) {
	/* printf("enter: nm = UNKNOWN sp = %X\n", sp); */
	stack[sp] = localsp;
	nmstack[sp] = CLU_empty_string;
	forbodystack[sp] = false;
	++sp;
	return ERR_ok;
    }

    fp = (framep) localsp[0];
    /* printf("enter: nm = %s sp = %X\n", fp->name, sp); */
    stack[sp] = localsp;
    size.num = strlen(fp->name);
    stringOPcons(fp->name, CLU_1, size, &nm);
    nmstack[sp] = nm;
    forbodystack[sp] = false;
    ++sp;
    spref.num = sp;

    /* check for uninitialized arguments */
    for (i = fp->locals->count - fp->nargs; i < fp->locals->count; ++i) {
	if (localsp[i+2] == UNINIT) {
            /* printf(" uninitialized argument %s to proc %s\n",
                    fp->locals->vds[i].nm,
                    fp->name);
            */
	    size.num = strlen(fp->locals->vds[i].nm);
	    stringOPcons(fp->locals->vds[i].nm, CLU_1, size, &argnm);
	    code.num = ENTER_PROC_FAULT;
	    debugOPcli(code, spref, nm, argnm, &mode);
	    return ERR_ok;
	}
    }

    code.num = ENTER_PROC;
    debugOPcli(code, spref, nm, CLU_empty_string, &mode);
    return ERR_ok;
}


errcode
debugOPenter_forbody(long *localsp)
{
    CLUREF mode;
    framep fp;
    CLUREF nm, code, spref, size;

    fp = (framep) localsp[0];
    /* printf("enter: nm = %s sp = %X\n", fp->name, sp); */
    stack[sp] = localsp;
    size.num = strlen(fp->name);
    stringOPcons(fp->name, CLU_1, size, &nm);
    nmstack[sp] = nm;
    forbodystack[sp] = true;
    ++sp;
    spref.num = sp;

    code.num = ENTER_FORBODY;
    debugOPcli(code, spref, nm, CLU_empty_string, &mode);
    return ERR_ok;
}


errcode
debugOPleave_proc(errcode sig)
{
    CLUREF mode;
    CLUREF nm, code, sigref;

    nm = nmstack[sp - 1];
    if (nm.str != CLU_empty_string.str) {
	if (forbodystack[sp - 1]) {
	    code.num = LEAVE_FORBODY;
	    sigref.num = sig;
	    save_elist(sp - 1);
	    debugOPcli(code, sigref, nmstack[sp-1], CLU_empty_string, &mode);
	    restore_elist(sp - 1);
	}
	else {
	    code.num = LEAVE_PROC;
	    sigref.num = sig;
	    save_elist(sp - 1);
	    debugOPcli(code, sigref, nmstack[sp - 1], elist[0], &mode);
	    restore_elist(sp - 1);
	}
    }
    stack[sp] = 0;
    --sp;
    return ERR_ok;
}


errcode
debugOPbegin_line(long n)
{
    CLUREF mode, code, nref;

    /* printf("line: nm = %s, line = %d\n", nmstack[sp-1], n); */
    code.num = BEGIN_LINE;
    nref.num = n;
    debugOPcli(code, nref, nmstack[sp - 1], CLU_empty_string, &mode);
    return ERR_ok;
}


errcode
debugopline_stop(CLUREF mod, CLUREF n)
{
    signal(ERR_ok);
}


errcode
debugopclear_line_stop(CLUREF mod, CLUREF n)
{
    signal(ERR_ok);
}


errcode
debugopfunc_stop(CLUREF nm)
{
    signal(ERR_ok);
}


errcode
debugopclear_func_stop(CLUREF nm)
{
    signal(ERR_ok);
}


errcode
debugopassign(CLUREF addr, CLUREF val)
{
    long *a = (long *)addr.num;
    *a = val.num;
    signal(ERR_ok);
}


CLUPROC
find_print(struct OPS **opsp)
{
    long i;
    struct OPS *ops;

    if (opsp == NULL)
	return NULL;

    if (*(long*)opsp < 1000)
	ops = (struct OPS *)opsp;
    else
	ops = *opsp;

    if (ops == NULL)
	return NULL;

    for (i = 0 ; i < ops->count; ++i) {
	if (ops->entry[i].name == NULL)
	    continue;

	if (strcmp("debug_print", ops->entry[i].name) == 0)
	    return ops->entry[i].fcn;
    }

    return NULL;
}


long
find_op_own_ptr(framep fp, long i)
{
    for (long k = 0; k < fp->locals->count; ++k) {
	if (strcmp("op_own_ptr", fp->locals->vds[k].nm) == 0)
	    return stack[i][k + 2];
    }

    return 0;
}


long
find_type_own_ptr(framep fp, long i)
{
    for (long k = 0; k < fp->locals->count; ++k) {
	if (strcmp("type_own_ptr", fp->locals->vds[k].nm) == 0)
	    return stack[i][k + 2];
    }

    return 0;
}


struct OPS **
alt_find_ops(framep fp, long i, char *opnm)
{
    long k;
    CLUREF op_own_ptr, type_own_ptr;

#if 0
    printf("checking op info\n");
#endif
    op_own_ptr.num = find_op_own_ptr(fp, i);
    for (k = 0; k < fp->popowns->count; ++k) {
#if 0
	printf("%s\n", fp->popowns->vds[k].nm);
#endif
	if (strcmp(opnm, fp->popowns->vds[k].nm) == 0) {
	    return (struct OPS **)op_own_ptr.num + k;
	}
    }

#if 0
    printf("checking type info\n");
#endif
    type_own_ptr.num = find_type_own_ptr(fp, i);
    for (k = 0; k < fp->ptowns->count; ++k) {
#if 0
	printf("%s\n", fp->ptowns->vds[k].nm);
#endif
	if (strcmp(opnm, fp->ptowns->vds[k].nm) == 0)
	    return (struct OPS **)type_own_ptr.num + k;
    }

#if 0
    printf("not found\n");
#endif
    return (0);
}


struct OPS **
alt_find_ops2(char *opnm, framep info,
	      OWNPTR type_own_ptr, OWNPTR op_own_ptr)
{
    long k;

#if 0
    printf("checking op info\n");
#endif
    if (op_own_ptr != NULL) {
	for (k = 0; k < info->popowns->count; ++k) {
#if 0
	    printf("%s\n", info->popowns->vds[k].nm);
#endif
	    if (strcmp(opnm, info->popowns->vds[k].nm) == 0) {
		return (struct OPS **)op_own_ptr + k;
	    }
	}
    }

#if 0
    printf("checking type info\n");
#endif
    if (type_own_ptr != NULL) {
	for (k = 0; k < info->ptowns->count; ++k) {
#if 0
	    printf("%s\n", info->ptowns->vds[k].nm);
#endif
	    if (strcmp(opnm, info->ptowns->vds[k].nm) == 0)
		return (struct OPS **)type_own_ptr + k;
	}
    }

#if 0
    printf("not found\n");
#endif
    return 0;
}


errcode
debugopprint_val2(CLUREF po, CLUREF val, CLUREF ops)
{
    long i, j, len;
    struct OPS **opsp = (struct OPS **)ops.num;
    CLUPROC cluprc;
    errcode err;

    if (val.num == UNINIT) {
	err = print_uninit(po, val);
	resignal(err);
    }

    CUR_PROC_VAR.proc = find_print(opsp);
    if (CUR_PROC_VAR.proc == NULL) {
	signal(ERR_not_possible);
    }

    err = (*CUR_PROC_VAR.proc->proc)(val, po);
    resignal(err);
}


/* 1/19/93: started searching in locals at index 1, rather than 0, to
	avoid matchine err */
errcode
debugopprint_val(CLUREF po, CLUREF ind, CLUREF mod, CLUREF nm)
{
    long i, j, k, len;
    CLUREF value;
    framep fp;
    struct OPS **ops;
    CLUPROC cluprc;
    errcode err;
    long *addr;
    char *fullnm, *opnm;
    CLUREF clu_fullnm, op_own_ptr, type_own_ptr, size;

    i = ind.num - 1;
    if (i < 0 || i >  (sp - 1))
	signal(ERR_not_found);
    fp = (framep)stack[i][0];


    /*
     * SEARCH LOCALS
     */
#if 0
    printf("LOCALS %d %s\n", fp->locals->count, nm.str->data);
#endif
    for (j = 1; j < fp->locals->count; ++j) {
#if 0
	printf("%s\n", fp->locals->vds[j].nm);
#endif
	if (strcmp(nm.str->data, fp->locals->vds[j].nm) == 0) {
	    value.num = stack[i][j + 2];
	    if (value.num == UNINIT) {
		err = print_uninit(po, value);
		resignal(err);
	    }

	    ops = fp->locals->vds[j].ops;
	    if (ops == (struct OPS **)-1) {
		err = missing_print_fcn(value, po);
		resignal(err);
	    }

	    if (ops == NULL) {
#if 0
		printf("finding %s\n", fp->locals->vds[j].nm_ops);
#endif
		opnm = fp->locals->vds[j].nm_ops;
		ops = alt_find_ops(fp, i, opnm);
	    }

	    CUR_PROC_VAR.proc = find_print(ops);
	    if (CUR_PROC_VAR.proc == NULL) {
		signal(ERR_not_possible);
	    }
	    err = (*CUR_PROC_VAR.proc->proc)(value, po);
	    resignal(err);
	}
    }


    /*
     * SEARCH STATIC OWNS
     */
#if 0
    printf("STATIC OWNS %d %s\n", fp->owns->count, nm.str->data);
#endif
    for (j = 0; j < fp->owns->count ; ++j) {
#if 0
	printf("%s\n", fp->owns->vds[j].nm);
#endif
	if (strcmp(nm.str->data, fp->owns->vds[j].nm) == 0) {
	    fullnm = mystrcat(mod.str->data, "OP");
	    fullnm = mystrcat(fullnm, nm.str->data);
	    size.num = strlen(fullnm);
	    err = stringOPcons(fullnm, CLU_1, size, &clu_fullnm);

	    CLUREF aref;
	    err = symOPget_address(clu_fullnm, &aref);
	    if (err != ERR_ok) {
		/* check cluster owns */
		err = opown2typeown(clu_fullnm, &clu_fullnm);
		if (err != ERR_ok)
		    continue;
		err = symOPget_address(clu_fullnm, &aref);
		if (err != ERR_ok)
		    continue;
	    }

	    addr = (long *)aref.ref;
	    value.num = *addr;
	    if (value.num == UNINIT) {
		err = print_uninit(po, value);
		resignal(err);
	    }

	    ops = fp->owns->vds[j].ops;
	    if (ops == (struct OPS **)-1) {
		err = missing_print_fcn(value, po);
		resignal(err);
	    }

	    if (ops == NULL) {
		opnm = fp->locals->vds[j].nm_ops;
		ops = alt_find_ops(fp, i, opnm);
	    }

	    CUR_PROC_VAR.proc = find_print(ops);
	    if (CUR_PROC_VAR.proc == NULL) {
		signal(ERR_not_possible);
	    }
	    err = (*CUR_PROC_VAR.proc->proc)(value, po);
	    resignal(err);
	}
    }

    /* 9/29/93 dwc: changed order of search: do popowns before type owns */
    /*
     * SEARCH PARAMETERIZED OPERATION OWNS
     */
    for (j = 0; j < fp->popowns->count; ++j) {
	if (strcmp(nm.str->data, fp->popowns->vds[j].nm) == 0) {
	    /* have index (j) of var within owns */
	    /* now find op_own_ptr in locals */
	    op_own_ptr.num = find_op_own_ptr(fp, i);
	    addr = ((long*)(op_own_ptr.num)) + (j);

	    value.num = *addr;
	    if (value.num == UNINIT) {
		err = print_uninit(po, value);
		resignal(err);
	    }

	    ops = fp->popowns->vds[j].ops;
	    if (ops == (struct OPS **)-1) {
		err = missing_print_fcn(value, po);
		resignal(err);
	    }

	    if (ops == NULL) {
		opnm = fp->locals->vds[j].nm_ops;
		ops = alt_find_ops(fp, i, opnm);
	    }

	    CUR_PROC_VAR.proc = find_print(ops);
	    if (CUR_PROC_VAR.proc == NULL) {
		signal(ERR_not_possible);
	    }
	    err = (*CUR_PROC_VAR.proc->proc)(value, po);
	    resignal(err);
	}
    }


    /*
     * SEARCH PARAMETERIZED TYPE OWNS
     */
#if 0
    printf("PARAMD TYPE OWNS %d %s\n", fp->ptowns->count, nm.str->data);
#endif
    for (j = 0; j < fp->ptowns->count; ++j) {
#if 0
	printf("%s\n", fp->ptowns->vds[j].nm);
#endif
	if (strcmp(nm.str->data, fp->ptowns->vds[j].nm) == 0) {
	    type_own_ptr.num = find_type_own_ptr(fp, i);
	    addr = ((long*)(type_own_ptr.num)) + (j);

	    value.num = *addr;
	    if (value.num == UNINIT) {
		err = print_uninit(po, value);
		resignal(err);
	    }

	    ops = fp->ptowns->vds[j].ops;
	    if (ops == (struct OPS **)-1) {
		err = missing_print_fcn(value, po);
		resignal(err);
	    }

	    if (ops == NULL) {
		opnm = fp->locals->vds[j].nm_ops;
		ops = alt_find_ops(fp, i, opnm);
	    }

	    CUR_PROC_VAR.proc = find_print(ops);
	    if (CUR_PROC_VAR.proc == NULL) {
		signal(ERR_not_possible);
	    }
	    err = (*CUR_PROC_VAR.proc->proc)(value, po);
	    resignal(err);
	}
    }

    signal(ERR_not_found);
}


errcode
debugopnm2val_ops(CLUREF ind, CLUREF mod, CLUREF nm,
		  CLUREF *ansval, CLUREF *ansops)
{
    long i, j, k, len;
    CLUREF value;
    framep fp;
    struct OPS **ops;
    CLUPROC cluprc;
    errcode err;
    long *addr;
    char *fullnm, *opnm;
    CLUREF clu_fullnm, op_own_ptr, type_own_ptr, size;

    i = ind.num - 1;
    if (i < 0 || i >  (sp - 1))
	signal(ERR_not_found);
    fp = (framep)stack[i][0];


    /*
     * SEARCH LOCALS
     */
    for (j = 1; j < fp->locals->count; ++j) {
	if (strcmp(nm.str->data, fp->locals->vds[j].nm) == 0) {
	    value.num = stack[i][j + 2];
	    if (value.num == UNINIT)
		signal(ERR_undefined);

	    ops = fp->locals->vds[j].ops;
	    if (ops == (struct OPS **)-1)
		signal(ERR_bad_code);

	    if (ops == NULL) {
		opnm = fp->locals->vds[j].nm_ops;
		ops = alt_find_ops(fp, i, opnm);
	    }

	    ansval->num = value.num;
	    ansops->num = *((long *)ops);
	    signal(ERR_ok);
	}
    }


    /*
     * SEARCH STATIC OWNS
     */
    for (j = 0; j < fp->owns->count; ++j) {
	if (strcmp(nm.str->data, fp->owns->vds[j].nm) == 0) {
	    fullnm = mystrcat(mod.str->data, "OP");
	    fullnm = mystrcat(fullnm, nm.str->data);
	    size.num = strlen(fullnm);
	    err = stringOPcons(fullnm, CLU_1, size, &clu_fullnm);

	    CLUREF aref;
	    err = symOPget_address(clu_fullnm, &aref);
	    if (err != ERR_ok) {
		/* check cluster owns */
		err = opown2typeown(clu_fullnm, &clu_fullnm);
		if (err != ERR_ok)
		    continue;
		err = symOPget_address(clu_fullnm, &aref);
		if (err != ERR_ok)
		    continue;
	    }

	    addr = (long *)aref.ref;
	    value.num = *addr;
	    if (value.num == UNINIT)
		signal(ERR_undefined);

	    ops = fp->owns->vds[j].ops;
	    if (ops == (struct OPS **)-1)
		signal(ERR_bad_code);

	    if (ops == NULL) {
		opnm = fp->locals->vds[j].nm_ops;
		ops = alt_find_ops(fp, i, opnm);
	    }

	    ansval->num = value.num;
	    ansops->num = *((long *)ops);
	    signal(ERR_ok);
	}
    }


    /* 9/29/93 dwc: changed order of search: do popowns before type owns */
    /*
     * SEARCH PARAMETERIZED OPERATION OWNS
     */
    for (j = 0; j < fp->popowns->count ; j++) {
	if (strcmp(nm.str->data, fp->popowns->vds[j].nm) == 0) {
	    /* have index (j) of var within owns */
	    /* now find op_own_ptr in locals */
	    op_own_ptr.num = find_op_own_ptr(fp, i);
	    addr = ((long *)(op_own_ptr.num)) + (j);

	    value.num = *addr;
	    if (value.num == UNINIT)
		signal(ERR_undefined);

	    ops = fp->popowns->vds[j].ops;
	    if (ops == (struct OPS **)-1)
		signal(ERR_bad_code);

	    if (ops == NULL) {
		opnm = fp->locals->vds[j].nm_ops;
		ops = alt_find_ops(fp, i, opnm);
	    }

	    ansval->num = value.num;
	    ansops->num = *((long*)ops);
	    signal(ERR_ok);
	}
    }


    /*
     * SEARCH PARAMETERIZED TYPE OWNS
     */
    for (j = 0; j < fp->ptowns->count; ++j) {
#if 0
	printf("%s\n", fp->ptowns->vds[j].nm);
#endif
	if (strcmp(nm.str->data, fp->ptowns->vds[j].nm) == 0) {
	    type_own_ptr.num = find_type_own_ptr(fp, i);
	    addr = ((long*)(type_own_ptr.num)) + (j);

	    value.num = *addr;
	    if (value.num == UNINIT)
		signal(ERR_undefined);

	    ops = fp->ptowns->vds[j].ops;
	    if (ops == (struct OPS **)-1)
		signal(ERR_bad_code);

	    if (ops == NULL) {
		opnm = fp->locals->vds[j].nm_ops;
		ops = alt_find_ops(fp, i, opnm);
	    }

	    ansval->num = value.num;
	    ansops->num = *((long *)ops);
	    signal(ERR_ok);
	}
    }

    signal(ERR_not_found);
}


errcode
debugopget_val(CLUREF ind, CLUREF mod, CLUREF nm, CLUREF *val)
{
    long i, j, k, len;
    framep fp;
    struct OPS **ops;
    CLUPROC cluprc;
    errcode err;
    char *fullnm;
    CLUREF clu_fullnm, op_own_ptr, type_own_ptr, size;
    long *addr;

    /* 3/10/94: dwc: don't search the stack!!! */
    /*	for (i = sp - 1; i > -1; --i) ... */
    i = ind.num - 1;
    if (i < 0 || i >  (sp - 1))
	signal(ERR_not_found);
    fp = (framep)stack[i][0];

    if (strcmp(mod.str->data, fp->name) == 0) {
	for (j = 1; j < fp->locals->count; ++j) {
	    if (strcmp(nm.str->data, fp->locals->vds[j].nm) == 0) {
		val->num = stack[i][j+2];
		signal(ERR_ok);
	    }
	}

	for (j = 0; j < fp->owns->count; ++j) {
	    if (strcmp(nm.str->data, fp->owns->vds[j].nm) == 0) {
		fullnm = mystrcat(mod.str->data, "OP");
		fullnm = mystrcat(fullnm, nm.str->data);
		size.num = strlen(fullnm);
		err = stringOPcons(fullnm, CLU_1, size, &clu_fullnm);

		CLUREF aref;
		err = symOPget_address(clu_fullnm, &aref);
		if (err != ERR_ok) {
		    /* check cluster owns */
		    err = opown2typeown(clu_fullnm, &clu_fullnm);
		    if (err != ERR_ok)
			continue;
		    err = symOPget_address(clu_fullnm, &aref);
		    if (err != ERR_ok)
			continue;
		}

		addr = (long *)aref.ref;
		val->num = *addr;
		signal(ERR_ok);
	    }
	}

	/* 9/29/93 dwc: changed order of search: do popowns before type owns */
	for (j = 0; j < fp->popowns->count; ++j) {
	    if (strcmp(nm.str->data, fp->popowns->vds[j].nm) == 0) {
		/* have index (j) of var within owns */
		/* now find op_own_ptr in locals */
		op_own_ptr.num = find_op_own_ptr(fp, i);
		addr = ((long *)(op_own_ptr.num)) + (j);

		val->num = *addr;
		signal(ERR_ok);
	    }
	}

	for (j = 0; j < fp->ptowns->count; ++j) {
	    if (strcmp(nm.str->data, fp->ptowns->vds[j].nm) == 0) {
		type_own_ptr.num = find_type_own_ptr(fp, i);
		addr = ((long *)(type_own_ptr.num)) + (j);

		val->num = *addr;
		signal(ERR_ok);
	    }
	}
    }

    signal(ERR_not_found);
}


errcode
debugopset_val(CLUREF ind, CLUREF mod, CLUREF nm, CLUREF val)
{
    long i, j, k, len;
    framep fp;
    struct OPS **ops;
    CLUPROC cluprc;
    errcode err;
    char *fullnm;
    CLUREF clu_fullnm, op_own_ptr, type_own_ptr, size;
    long *addr;

    /* 3/10/94: dwc: don't search the stack!!! */
    /* for (i = sp - 1 ; i > -1; --i) ... */
    i = ind.num - 1;
    if (i < 0 || i >  (sp - 1))
	signal(ERR_not_found);
    fp = (framep)stack[i][0];

    if (strcmp(mod.str->data, fp->name) == 0) {
	for (j = 1; j < fp->locals->count; ++j) {
	    if (!strcmp(nm.str->data, fp->locals->vds[j].nm)) {
		stack[i][j + 2] = val.num;
		signal(ERR_ok);
	    }
	}

	for (j = 0; j < fp->owns->count; ++j) {
	    if (strcmp(nm.str->data, fp->owns->vds[j].nm) == 0) {
		fullnm = mystrcat(mod.str->data, "OP");
		fullnm = mystrcat(fullnm, nm.str->data);
		size.num = strlen(fullnm);
		err = stringOPcons(fullnm, CLU_1, size, &clu_fullnm);

		CLUREF aref;
		err = symOPget_address(clu_fullnm, &aref);
		if (err != ERR_ok)
		    continue;

		addr = (long *)aref.ref;
		*addr = val.num;
		signal(ERR_ok);
	    }
	}

	/* 9/29/93 dwc: changed order of search: do popowns before type owns */
	for (j = 0; j < fp->popowns->count; ++j) {
	    if (strcmp(nm.str->data, fp->popowns->vds[j].nm) == 0) {
		/* have index (j) of var within owns */
		/* now find op_own_ptr in locals */
		op_own_ptr.num = find_op_own_ptr(fp, i);
		addr = ((long *)(op_own_ptr.num)) + (j);

		*addr = val.num;
		signal(ERR_ok);
	    }
	}

	for (j = 0; j < fp->ptowns->count; ++j) {
	    if (strcmp(nm.str->data, fp->ptowns->vds[j].nm) == 0) {
		type_own_ptr.num = find_type_own_ptr(fp, i);
		addr = ((long *)(type_own_ptr.num)) + (j);

		*addr = val.num;
		signal(ERR_ok);
	    }
	}
    }

    signal(ERR_not_found);
}


errcode
debugopframe_count(CLUREF *ans)
{
    ans->num = sp;
    signal(ERR_ok);
}


errcode
debugopframe_info(CLUREF nth, CLUREF *info, CLUREF *line)
{
    char *cnm;
    CLUREF newnm;
    framep fp, *fpp;

    fpp = (framep *)stack[nth.num - 1];
    if (fpp == (framep *)-1)	/* own_init_proc */
	signal(ERR_none);

    fp = (framep)stack[nth.num - 1][0];
    info->num = (long)fp;
    line->num = stack[nth.num - 1][1];
    signal(ERR_ok);
}


errcode
debugopget_name(CLUREF riref, CLUREF *ans)
{
    CLUREF temp, size;
    framep ri = (framep)riref.ref;
    errcode err;

    size.num = strlen(ri->name);
    err = stringOPcons(ri->name, CLU_1, size, &temp);
    ans->str = temp.str;
    signal(ERR_ok);
}


errcode
debugopget_fname(CLUREF riref, CLUREF *ans)
{
    CLUREF temp, size;
    framep ri = (framep)riref.ref;
    errcode err;

    size.num = strlen(ri->fname);
    err = stringOPcons(ri->fname, CLU_1, size, &temp);
    ans->str = temp.str;
    signal(ERR_ok);
}


errcode
debugopget_count_formals(CLUREF ref, CLUREF *ans)
{
    Slist1 *sl = (Slist1 *)ref.ref;
    ans->num = sl->count;
    signal(ERR_ok);
}


errcode
debugopget_nth_formal(CLUREF ref, CLUREF n, CLUREF *ans)
{
    CLUREF temp, size;
    Slist1 *sl  = (Slist1 *)ref.ref;
    errcode err;
    char *nm;

    nm = sl->nm[n.num - 1];
    size.num = strlen(nm);
    err = stringOPcons(nm, CLU_1, size, &temp);
    ans->str = temp.str;
    signal(ERR_ok);
}


errcode
debugopget_nth_type_formal(CLUREF riref, CLUREF n, CLUREF *ans)
{
    CLUREF temp, size;
    framep ri  = (framep)riref.ref;
    errcode err;
    char *nm;

    nm = ri->type_formals->nm[n.num - 1];
    size.num = strlen(nm);
    err = stringOPcons(nm, CLU_1, size, &temp);
    ans->str = temp.str;
    signal(ERR_ok);
}


errcode
debugopget_nth_op_formal(CLUREF riref, CLUREF n, CLUREF *ans)
{
    CLUREF temp, size;
    framep ri = (framep)riref.ref;
    errcode err;
    char *nm;

    nm = ri->op_formals->nm[n.num - 1];
    size.num = strlen(nm);
    err = stringOPcons(nm, CLU_1, size, &temp);
    ans->str = temp.str;
    signal(ERR_ok);
}


errcode
debugopget_nth_op(CLUREF vals, CLUREF n, CLUREF info_ref,
		  CLUREF type_ops_ref, CLUREF op_ops_ref,
		  CLUREF *ans)
{
    Vlist1 *temp = (Vlist1 *)vals.num;
    struct OPS**ptr;
    char *opnm;
    CLUREF opname, sz;
    struct OPS *type_ops = (struct OPS *)type_ops_ref.ref;
    struct OPS *op_ops = (struct OPS *)op_ops_ref.ref;
    framep info = (framep)info_ref.ref;
    OWNPTR type_own_ptr = NULL;
    OWNPTR op_own_ptr = NULL;

    ptr = (struct OPS **)temp->vds[n.num - 1].ops;
    if (ptr != (zero_ops)) {
	ans->num = (long)temp->vds[n.num - 1].ops;
	signal(ERR_ok);
    }
    else {
	opnm = temp->vds[n.num - 1].nm_ops;
	if (type_ops != NULL)
	    type_own_ptr = type_ops->type_owns;
	if (op_ops != NULL)
	    op_own_ptr = op_ops->op_owns;

	ptr = alt_find_ops2(opnm, info, type_own_ptr, op_own_ptr);
	if (ptr == (struct OPS**)0) {
	    sz.num = strlen(opnm);
	    stringOPcons(opnm, CLU_1, sz, &opname);
	    elist[0] = opname;
	    signal(ERR_not_found);
	}

	ans->num = (long)ptr;
	signal(ERR_ok);
#if 0
	nm = temp->vds[n.num-1].nm_ops;
	sz.num = strlen(nm);
	stringOPcons(nm, CLU_1, sz, &opname);
	elist[0] = opname;
	signal(ERR_not_found);
#endif
    }
}


errcode
debugopget_nth_sigval(CLUREF i, CLUREF *ans)
{
    ans->ref = saved_elist[sp - 1][i.num - 1].ref;
    signal(ERR_ok);
}


errcode
debugopcmp_sig(CLUREF s1, char *s2, CLUREF *ans)
{
    long size = strlen(s2);

    if (size != s1.str->size) {
	ans->tf = false;
	signal(ERR_ok);
    }
    ans->tf = !bcmp(s1.str->data, s2, size);
    signal(ERR_ok);
}


/* convert a raw signal to a CLUREF string */
errcode
debugopcvt_sig(CLUREF sig, CLUREF *ans)
{
    CLUREF temp = _pclu_erstr(sig.num);
    ans->num = temp.num;
    signal(ERR_ok);
}


errcode
debugopget_sigvalcount(CLUREF sd, CLUREF *ans)
{
    sig_desc *temp = (sig_desc *)sd.num;

    ans->num = temp->vals.count;
    signal(ERR_ok);
}


errcode
debugopget_nth_sigvalops(CLUREF sd, CLUREF n, CLUREF info_ref,
			 CLUREF type_ops_ref, CLUREF op_ops_ref,
			 CLUREF *ans)
{
    sig_desc1 *temp = (sig_desc1 *)sd.num;
    char *opnm;
    struct OPS **ops;
    struct OPS *type_ops = (struct OPS *)type_ops_ref.ref;
    struct OPS *op_ops = (struct OPS *)op_ops_ref.ref;
    framep info = (framep)info_ref.ref;
    OWNPTR type_own_ptr = NULL;
    OWNPTR op_own_ptr = NULL;

    ops = temp->vals.vds[n.num - 1].ops;
    if (ops == NULL) {
	opnm = temp->vals.vds[n.num - 1].nm_ops;
	if (type_ops == (struct OPS *)-1) {
	    type_own_ptr = (OWNPTR)find_type_own_ptr((framep)stack[sp - 1][0], sp - 1);
	    op_own_ptr = (OWNPTR)find_op_own_ptr((framep)stack[sp - 1][0], sp - 1);
	}
	else {
	    if (type_ops != NULL)
		type_own_ptr = type_ops->type_owns;
	    if (op_ops != NULL)
		op_own_ptr = op_ops->op_owns;
	}
	ops = alt_find_ops2(opnm, info, type_own_ptr, op_own_ptr);
    }

    ans->ref = (char *)ops;
    signal(ERR_ok);
}


errcode
add_selector_info2(CLUREF nm, CLUREF n, CLUREF ops)
{
    char *nmc = nm.str->data;
    add_selector_info(nmc, n.num, (struct OPS *)ops.ref);
    signal(ERR_ok);
}


errcode
find_selector_ops2(CLUREF typ, CLUREF nfields, CLUREF *ans)
{
    struct OPS *ops;

    char *typc = typ.str->data;
    find_selector_ops(typc, nfields.num, &ops);
    ans->ref = (char *)ops;
    signal(ERR_ok);
}


/*
static char *uninit_var1 = "Uninitialized variable ";
static char *uninit_var2 = " in entry point ";

			size.num = strlen(uninit_var1);
			stringOPcons(uninit_var1, CLU_1, size, &str1);
*/
/*
			size.num = strlen(uninit_var2);
			stringOPcons(uninit_var2, CLU_1, size, &str3);
			size.num = strlen(fp->name);
			stringOPcons(fp->name, CLU_1, size, &str4);
			stringOPconcat(str1, str2, &str);
			stringOPconcat(str, str3, &str);
			stringOPconcat(str, str4, &str);
			elist[0] = str;
			signal(ERR_failure);
*/
