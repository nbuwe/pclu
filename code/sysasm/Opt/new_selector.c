/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*
 * IMPLEMENTATION of SELECTORS
 *   - routines common to oneof/variant, struct/record.
 *
 * For something like:
 *
 *   foos = sequence[foo]
 *   spec = record[name: string, foos: foos]
 *
 * the compiler generates C code like:
 *
 *   extern struct OPS *string_ops;
 *   struct OPS *sequence_of_foo_ops;
 *   struct OPS *record_foos_name_ops;
 *
 *   // pass parameters for fields/tags on an internal argument stack
 *   add_selector_info("foos", 0, sequence_of_foo_ops); // built previously
 *   add_selector_info("name", 1, string_ops); // built-in (string.c)
 *
 *   // build selector ops for "spec"
 *   find_selector_ops("record", 2, &record_foos_name_ops);
 */

#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#ifndef __arraycount
#define __arraycount(__x) (sizeof(__x) / sizeof(__x[0]))
#endif

/* pstream$text = proc (ps: cvt, s: string) returns (bool) */
extern errcode pstreamOPtext(CLUREF ps, CLUREF s, CLUREF *ret_1);

extern char *mystrcat(const char *s1, const char *s2);
extern errcode missing_print_fcn();

#define MAX_SELECTORS 1000
#define MAX_FIELDS    50

static const char *sel_inst_fieldname[MAX_FIELDS];
static const struct OPS *sel_inst_fieldops[MAX_FIELDS];


errcode
add_selector_info(const char *field_name, long index, const struct OPS *ops)
{
    sel_inst_fieldname[index] = field_name;
    sel_inst_fieldops[index] = ops;
    signal(ERR_ok);
}


typedef const char * const *nametable_t;
typedef PROC * const *proctable_t;

static errcode add_sel_ops(const char *selname, long count, struct OPS *new_ops);
static bool find_sel_ops(const char *selname, long count, struct OPS **result);

static void sel_ops_counts(const char *name,
			   long *pfcount, long *paramcount, long *plaincount);
static void sel_ops_names(const char *name,
			  nametable_t *pfname,
			  nametable_t *paramname,
			  nametable_t *plainname);
static void sel_ops_fcns(const char *name,
			 proctable_t *pffcn,
			 proctable_t *paramfcn,
			 proctable_t *plainfcn);
static void sel_ops_restricts(const char *name,
			      nametable_t *parm_reqs_names);

/********************************************************/
/*							*/
/*	Find_Selector_Ops				*/
/*							*/
/*	allocate storage for table that contains all	*/
/*	the operations that can be performed on a 	*/
/*	selector					*/
/*							*/
/********************************************************/

errcode
find_selector_ops(const char *selname, long nfields, struct OPS **table)
{
    static CLUREF mpf = { .proc = NULL };

    CLUREF temp_proc;
    errcode err;

    /* try to find an existing ops */
    bool already = find_sel_ops(selname, nfields, table);
    if (already) {
	signal(ERR_ok);
    }

    /* initial procedure type object for missing print function */
    if (mpf.proc == NULL) {
	err = proctypeOPnew(CLU_1, &mpf);
	if (err != ERR_ok) resignal(err);

	mpf.proc->proc = missing_print_fcn;
    }

    /* get the building blocks */
    long pf_op_count, parm_op_count, plain_op_count;
    nametable_t pf_op_names, parm_op_names, plain_op_names;
    proctable_t pf_op_fcns, parm_op_fcns, plain_op_fcns;
    nametable_t parm_restrict_name;

    sel_ops_counts(selname, &pf_op_count, &parm_op_count, &plain_op_count);
    sel_ops_names(selname, &pf_op_names, &parm_op_names, &plain_op_names);
    sel_ops_fcns(selname, &pf_op_fcns, &parm_op_fcns, &plain_op_fcns);
    sel_ops_restricts(selname, &parm_restrict_name);


    /*
     * Create basic ops structure.
     */
    struct OPS *ops;
    size_t nentries
	= parm_op_count	     /* ops parametrized by field ops (equal, &c) */
	+ plain_op_count     /* container level ops don't depend on fields */
	+ nfields * pf_op_count; /* accessors for each field */
    size_t ops_size = sizeof(struct OPS)
	+ (nentries - (VARYING_LENGTH + 0)) * sizeof(struct OP_ENTRY);

    clu_alloc(ops_size, &ops);
    ops->count = nentries;

    /* Create trivial type owns (OWN_ptr with empty info[]) */
    OWNPTR type_owns;
    clu_alloc(UNIT, &type_owns);
    ops->type_owns = type_owns;
    type_owns->init_flag = 1;


    size_t slot = 0;		/* index into ops->entry[] */

    /*
     * Set up storage for parameterized operations (equal &c).
     */
    for (long i = 0; i < parm_op_count; ++i, ++slot) {
	struct OP_ENTRY *entry = &ops->entry[slot];
	entry->name = parm_op_names[i];

	err = proctypeOPnew(CLU_1, &temp_proc);
	if (err != ERR_ok) resignal(err);
	entry->fcn = temp_proc.proc;
	entry->fcn->proc = parm_op_fcns[i];

	/* op's own storage */
	OWNPTR op_owns;
	size_t owns_size = UNIT + nfields * sizeof(CLUPROC);
	if (i == 3 || i == 7)	/* assume: print and debug_print */
	    owns_size += nfields * sizeof(const char *);
	clu_alloc(owns_size, &op_owns);
	op_owns->init_flag = 1; /* a promise, will complete it below */

	entry->fcn->type_owns = ops->type_owns;
	entry->fcn->op_owns = op_owns;
    }


    /*
     * Set up storage for plain (container level) operations.
     */
    for (long i = 0; i < plain_op_count; ++i, ++slot) {
	struct OP_ENTRY *entry = &ops->entry[slot];
	entry->name = plain_op_names[i];

	err = proctypeOPnew(CLU_1, &temp_proc);
	if (err != ERR_ok) resignal(err);
	entry->fcn = temp_proc.proc;
	entry->fcn->proc = plain_op_fcns[i];
    }


    /*
     * Set up storage for postfixable operations (i.e. field accessors &c).
     * pf_op_fcns[] is a Cartesian product of field x prefix.
     */
    for (long k = 0; k < nfields; ++k) {
	const char *field_name = sel_inst_fieldname[k];

	for (long i = 0; i < pf_op_count; ++i, ++slot) {
	    struct OP_ENTRY *entry = &ops->entry[slot];
	    entry->name = mystrcat(pf_op_names[i], field_name);

	    err = proctypeOPnew(CLU_1, &temp_proc);
	    if (err != ERR_ok) resignal(err);
	    entry->fcn = temp_proc.proc;
	    entry->fcn->proc
		= pf_op_fcns[k * pf_op_count + i]; /* [k][i] */
	}
    }


    /*
     * Finish initialization of op owns for the parameterized ops of
     * this new selector type (cf. the first loop above).
     *
     * Each parameterized operation ("equal" &c) of this new selector
     * type needs to know the corresponding operation for each field.
     * Additionally "print" and "debug_print" need to know the field
     * names.
     */
    for (long index = 0; index < nfields; ++index) {
	const struct OPS *field_ops = sel_inst_fieldops[index];
	const char *field_name = sel_inst_fieldname[index];

	for (long i = 0; i < parm_op_count; ++i) {
	    const char *reqname = parm_restrict_name[i];
	    struct OP_ENTRY *entry = &ops->entry[i];
	    OWNPTR owns = entry->fcn->op_owns;

	    for (long j = 0; j < field_ops->count; ++j) {
		const char *name = field_ops->entry[j].name;
		if (name == NULL
		    || name[0] != reqname[0]
		    || strcmp(name, reqname) != 0)
		    continue;

		/* save the corresponding field's op */
		owns->info[index] = (long)field_ops->entry[j].fcn;

		/* for print and debug_print save the field name too */
		if (i == 3 || i == 7) {
		    owns->info[nfields + index] = (long)field_name;
		}
		break;
	    }

	    /* stub for a missing debug/print function */
	    if (owns->info[index] == 0 && (i == 3 || i == 7)) {
		owns->info[index] = (long)mpf.proc;
		owns->info[nfields + index] = (long)field_name;
	    }
	}
    }

    /* save ops for future users */
    add_sel_ops(selname, nfields, ops);

    /* return created ops */
    *table = ops;
    signal(ERR_ok);
}


errcode
missing_print_fcn(CLUREF val, CLUREF pst)
{
    errcode err;

    CLU_NOREF(val);		/* no idea how to print it */

    static CLUREF msg = { .str = NULL };
    if (msg.str == NULL) {
	err = stringOPcons("no print function", CLU_1, CLU_17, &msg);
	if (err != ERR_ok) resignal(err);
    }

    CLUREF ans;
    err = pstreamOPtext(pst, msg, &ans);
    if (err != ERR_ok) resignal(err);

    signal(ERR_ok);
}


/* storage for following routine */

OPSPTR	record_opsptr_arr[MAX_SELECTORS]; /* instantiated ops */
OPSPTR	struct_opsptr_arr[MAX_SELECTORS]; /* instantiated ops */
OPSPTR	variant_opsptr_arr[MAX_SELECTORS]; /* instantiated ops */
OPSPTR	oneof_opsptr_arr[MAX_SELECTORS]; /* instantiated ops */

long 	record_field_count [MAX_SELECTORS];
long 	struct_field_count [MAX_SELECTORS];
long 	variant_field_count [MAX_SELECTORS];
long 	oneof_field_count [MAX_SELECTORS];

const struct OPS *record_field_vals[MAX_SELECTORS][MAX_FIELDS];
const struct OPS *struct_field_vals[MAX_SELECTORS][MAX_FIELDS];
const struct OPS *variant_field_vals[MAX_SELECTORS][MAX_FIELDS];
const struct OPS *oneof_field_vals[MAX_SELECTORS][MAX_FIELDS];

const char *record_field_names[MAX_SELECTORS][MAX_FIELDS];
const char *struct_field_names[MAX_SELECTORS][MAX_FIELDS];
const char *variant_field_names[MAX_SELECTORS][MAX_FIELDS];
const char *oneof_field_names[MAX_SELECTORS][MAX_FIELDS];

static long record_num_entries = 0;
static long struct_num_entries = 0;
static long variant_num_entries = 0;
static long oneof_num_entries = 0;

/* routine to initialize structures used by find_owns */
void
find_selops_init(OWNPTR *ans1, OWNPTR *ans2, OWNPTR *ans3, OWNPTR *ans4)
{
#if 0 /* removed 1/28/91 to speed up start_up dwc */
    for (size_t i = 0; i < MAX_SELECTORS; i++) {
	record_opsptr_arr[i] = NULL;
	struct_opsptr_arr[i] = NULL;
	variant_opsptr_arr[i] = NULL;
	oneof_opsptr_arr[i] = NULL;

	record_field_count[i] = 0;
	struct_field_count[i] = 0;
	variant_field_count[i] = 0;
	oneof_field_count[i] = 0;

	for (size_t j = 0; j < MAX_FIELDS; ++j) {
	    record_field_vals[i][j] = NULL;
	    struct_field_vals[i][j] = NULL;
	    variant_field_vals[i][j] = NULL;
	    oneof_field_vals[i][j] = NULL;
	}
    }
#endif
    *ans1 = (OWNPTR)record_opsptr_arr;
    *ans2 = (OWNPTR)struct_opsptr_arr;
    *ans3 = (OWNPTR)variant_opsptr_arr;
    *ans4 = (OWNPTR)oneof_opsptr_arr;
}


/* routine to find selector ops given selector name, # of fields */
/*	type info for fields is in sel_inst_info arrays */

static bool
find_sel_ops(const char *selname, long count, struct OPS **result)
{
    bool found = false;
    long *pcount;
    OPSPTR *table;
    const struct OPS *(*parm_vals)[MAX_FIELDS];
    const char *(*parm_names)[MAX_FIELDS];
    long *parm_count;


    /* if too many fields, then die */
    if (count >= MAX_FIELDS) {
	fprintf(stderr,
		"%s: too many fields: increase MAX_FIELDS\n", __func__);
	exit(-10);
    }

    /* first select which table */
    if (selname[0] == 'r') {	/* record */
	pcount = &record_num_entries;
	table = record_opsptr_arr;
	parm_count = record_field_count;
	parm_vals = record_field_vals;
	parm_names = record_field_names;
    }
    else if (selname[0] == 's') { /* struct */
	pcount = &struct_num_entries;
	table = struct_opsptr_arr;
	parm_count = struct_field_count;
	parm_vals = struct_field_vals;
	parm_names = struct_field_names;
    }
    else if (selname[0] == 'v') { /* variant */
	pcount = &variant_num_entries;
	table = variant_opsptr_arr;
	parm_count = variant_field_count;
	parm_vals = variant_field_vals;
	parm_names = variant_field_names;
    }
    else if (selname[0] == 'o') { /* oneof */
	pcount = &oneof_num_entries;
	table = oneof_opsptr_arr;
	parm_count = oneof_field_count;
	parm_vals = oneof_field_vals;
	parm_names = oneof_field_names;
    }
    else {
	fprintf(stderr, "%s: bad name %s\n", __func__, selname);
	exit(-1);
    }


    long slot;
    found = false;
    for (slot = 0 ; slot < *pcount; ++slot) {
	if (parm_count[slot] != count)
	    continue;

	found = true;
	for (long i = 0; i < count; ++i) {
	    if (parm_vals[slot][i] == sel_inst_fieldops[i]
		&& strcmp(parm_names[slot][i], sel_inst_fieldname[i]) == 0)
		continue;

	    found = false;
	    break;
	}
	if (found)
	    break;
    }

    if (found) {
	/* entry found: return ops */
	*result = table[slot];
	return true;
    }
    else {
	return false;
    }
}


static errcode
add_sel_ops(const char *selname, long count, struct OPS *new_ops)
{
    long *pcount;
    OPSPTR *table;
    const struct OPS *(*parm_vals)[MAX_FIELDS];
    const char *(*parm_names)[MAX_FIELDS];
    long *parm_count;

    /* first select which table */
    if (selname[0] == 'r') {	/* record */
	pcount = &record_num_entries;
	table = record_opsptr_arr;
	parm_count = record_field_count;
	parm_vals = record_field_vals;
	parm_names = record_field_names;
    }
    else if (selname[0] == 's') { /* struct */
	pcount = &struct_num_entries;
	table = struct_opsptr_arr;
	parm_count = struct_field_count;
	parm_vals = struct_field_vals;
	parm_names = struct_field_names;
    }
    else if (selname[0] == 'v') { /* variant */
	pcount = &variant_num_entries;
	table = variant_opsptr_arr;
	parm_count = variant_field_count;
	parm_vals = variant_field_vals;
	parm_names = variant_field_names;
    }
    else if (selname[0] == 'o') { /* oneof */
	pcount = &oneof_num_entries;
	table = oneof_opsptr_arr;
	parm_count = oneof_field_count;
	parm_vals = oneof_field_vals;
	parm_names = oneof_field_names;
    }
    else {
	fprintf(stderr, "%s: bad name %s\n", __func__, selname);
	exit(-1);
    }


    long slot = *pcount;
    if (slot == MAX_SELECTORS) {
	fprintf(stderr,
		"%s: too many %s instantiations: increase MAX_SELECTORS\n",
		__func__, selname);
	exit(-10);
    }

    table[slot] = new_ops;
    parm_count[slot] = count;
    for (long i = 0 ; i < count; ++i) {
	parm_vals[slot][i] = sel_inst_fieldops[i];
	parm_names[slot][i] = sel_inst_fieldname[i];
    }

    *pcount = slot + 1;
    signal(ERR_ok);
}


#ifdef CLU_DEBUG
errcode find_valops(CLUREF selname, CLUREF opname, CLUREF ops,
		    CLUREF *ans1, CLUREF *ans2, CLUREF *ans3);


/********************************************************/
/*							*/
/*	given the ops corresponding to a selector       */
/*		and an op on that type                  */
/*							*/
/*	find name of selector                           */
/*	find the number of values for that operation    */
/*	find ops for the result of that operation       */
/*							*/
/*	these ops may be NULL_OPS, (e.g. print)		*/
/*                       bool_ops, (e.g. equal)		*/
/*                       input ops, (e.g. copy)		*/
/*	                 per field ops, (e.g. get_)	*/
/*                    or equivalent ops (e.g. o2v)	*/
/*							*/
/********************************************************/
errcode
rep_find_valops(CLUREF opname, CLUREF opsptr,
		CLUREF *anstyp,
		CLUREF *ansnum, CLUREF *ansops, CLUREF *ansnfield)
{
    errcode err;

    static CLUREF rec, str, one, var;
    static bool init = false;
    if (!init) {
	stringOPcons("record",  CLU_1, CLU_6, &rec);
	stringOPcons("struct",  CLU_1, CLU_6, &str);
	stringOPcons("oneof",   CLU_1, CLU_5, &one);
	stringOPcons("variant", CLU_1, CLU_7, &var);
	init = true;
    }

    CLUREF ops;
    /* ops.num = *((long*)(opsptr.ref)); */
    ops.num = opsptr.num;

    err = find_valops(rec, opname, ops,
		      ansnum, ansops, ansnfield);
    if (err == ERR_ok) {
	anstyp->str = rec.str;
	signal(ERR_ok);
    }

    err = find_valops(str, opname, ops,
		      ansnum, ansops, ansnfield);
    if (err == ERR_ok) {
	anstyp->str = str.str;
	signal(ERR_ok);
    }

    err = find_valops(one, opname, ops,
		      ansnum, ansops, ansnfield);
    if (err == ERR_ok) {
	anstyp->str = one.str;
	signal(ERR_ok);
    }

    err = find_valops(var, opname, ops,
		      ansnum, ansops, ansnfield);
    if (err == ERR_ok) {
	anstyp->str = var.str;
	signal(ERR_ok);
    }

    signal(ERR_not_found);
}


/********************************************************/
/*							*/
/*	given the ops corresponding to a selector       */
/*		and an op on that selector type         */
/*							*/
/*	find # of results for that operation            */
/*	find ops for the result of that operation       */
/*	find ordinal of field if relevant		*/
/*							*/
/*	these ops may be NULL_OPS, (e.g. print)		*/
/*                       bool_ops, (e.g. equal)		*/
/*                       input ops, (e.g. copy)		*/
/*	                 per field ops, (e.g. get_)	*/
/*                    or equivalent ops (e.g. o2v)	*/
/*							*/
/*	signals are ignored for the time being		*/
/*	equivalent ops are also ignored 		*/
/*		(input ops are used)                    */
/********************************************************/

extern struct OPS *int_ops;
extern struct OPS *bool_ops;


errcode
find_valops(CLUREF selname, CLUREF opname, CLUREF ops,
	    CLUREF *ans1, CLUREF *ans2, CLUREF *ans3)
{
    long i, j;
    bool found;
    long *pcount;
    OPSPTR *table;
    const struct OPS *(*parm_vals)[MAX_FIELDS];
    const char *(*parm_names)[MAX_FIELDS];
    long *parm_count;
    char *field;
    long oplen;
    bool pfo = false;
    bool pfo_known_ops = false;
    bool ans_known = false;
    char *nm = opname.str->data;
    char *selnm = selname.str->data;


    /*
     * Look at operation and decide how to find valops.
     * Dispense with easy albeit unlikely operations first.
     */

    if (nm[0] == '_') {				/* _gcd */
	ans1->num = 1;
	ans2->num = (long)int_ops;
	ans3->num = 0;
	ans_known = true;
    }

    if ((nm[0] == 'i')				/* is_ */
	|| (nm[0] == 'e' && nm[1] == 'q')	/* equal */
	|| (nm[0] == 's' && nm[1] == 'i'))	/* similar, similar1 */
    {
	ans1->num = 1;
	ans2->num = (long)bool_ops;
	if (nm[0] == 'i') {
	    pfo_known_ops = true;
	}
	else {
	    ans3->num = 0;
	    ans_known = true;
	}
    }

    if ((nm[0] == 's' && nm[1] == '2')		/* s2r */
	|| (nm[0] == 'o' && nm[1] == '2'))	/* o2v */
    {
	/* actually equivalent ops: should do instantiation */
	ans1->num = 1;
	ans2->num = (long)ops.num;
	ans3->num = 0;
	ans_known = true;
    }

    if ((nm[0] == 'g')				/* get_ */
	|| (nm[0] == 'v' && nm[1] == 'a'))	/* value_ */
    {
	pfo = true;
    }

    if ((nm[0] == 'd')				/* decode */
	|| (nm[1] == '2')			/* v2o, r2s */
	|| (nm[0] == 'c' && nm[1] == 'o'))	/* copy, copy1 */
    {
	ans1->num = 1;
	ans2->num = (long)ops.num;
	ans3->num = 0;
	ans_known = true;
    }

    if ((nm[0] == 'm')				/* make_ */
	|| (nm[0] == 'r' && nm[1] == 'e'))	/* replace_ */
    {
	ans1->num = 1;
	ans2->num = (long)ops.num;
	pfo_known_ops = true;
    }

    if (!pfo && !pfo_known_ops && !ans_known) {
	ans1->num = 0;
	ans2->num = (long)NULL_OPS;
	if ((nm[0] == 'c') || (nm[0] == 's')) {
	    pfo_known_ops = true;
	}
	else {
	    ans3->num = 0;
	    ans_known = true;
	}
    }


    /*
     * We have a postfixable operation and need to look up valops in
     * table.  Get the field name from the postfix.
     */
    field = index(nm, '_') + 1;

    /* decide what type we have and get corresponding tables */
    if (selnm[0] == 'r') {
	pcount = &record_num_entries;
	table = record_opsptr_arr;
	parm_count = record_field_count;
	parm_vals = record_field_vals;
	parm_names = record_field_names;
    }
    if (selnm[0] == 's') {
	pcount = &struct_num_entries;
	table = struct_opsptr_arr;
	parm_count = struct_field_count;
	parm_vals = struct_field_vals;
	parm_names = struct_field_names;
    }
    if (selnm[0] == 'v') {
	pcount = &variant_num_entries;
	table = variant_opsptr_arr;
	parm_count = variant_field_count;
	parm_vals = variant_field_vals;
	parm_names = variant_field_names;
    }
    if (selnm[0] == 'o') {
	pcount = &oneof_num_entries;
	table = oneof_opsptr_arr;
	parm_count = oneof_field_count;
	parm_vals = oneof_field_vals;
	parm_names = oneof_field_names;
    }

    /* get number of such instantiations and list */
    found = false;
    for (i = 0 ; i < *pcount ; ++i) {
	if ((OPSPTR)ops.num == table[i]) {
	    found = true;
	    break;
	}
    }
    if (!found)
	signal(ERR_not_found);

    if (ans_known)
	signal(ERR_ok);

    found = false;
    for (j = 0; j < parm_count[i]; ++j) {
	if (!strcmp(field,parm_names[i][j])) {
	    found = true;
	    break;
	}
    }
    if (found == false)
	signal(ERR_not_found);

    if (pfo) {
	ans1->num = 1;
	ans2->num = (long)parm_vals[i][j];
    }
    ans3->num = j+1;
    signal(ERR_ok);
}
#endif	/* CLU_DEBUG */


/********************************************************/
/*							*/
/*	selectors have three types of operations	*/
/*							*/
/*	1. postfixable: e.g. get_, is_			*/
/*	2. parameterized: e.g. record$copy requires 	*/
/*				t$copy for each field 	*/
/*	3. plain: e.g. record$copy1 (not postfixable, 	*/
/*				not parameterized)	*/
/*							*/
/********************************************************/
#include "selector.h"


/********************************************************/
/*							*/
/*	Sel_Ops_Counts					*/
/*		returns the numbers of 			*/
/*			each type of operation		*/
/*		based on the name of the selector	*/
/*							*/
/********************************************************/

static void
sel_ops_counts(const char *name,
	       long *pfcount, long *paramcount, long *plaincount)
{
    if (name[0] == 'o') {
	*pfcount    = __arraycount(oneof_prefix_name_table);
	*paramcount = __arraycount(oneof_param_name_table);
	*plaincount = __arraycount(oneof_plain_name_table);
	return;
    }
    if (name[0] == 'v') {
	*pfcount    = __arraycount(variant_prefix_name_table);
	*paramcount = __arraycount(variant_param_name_table);
	*plaincount = __arraycount(variant_plain_name_table);
	return;
    }
    if (name[0] == 'r') {
	*pfcount    = __arraycount(record_prefix_name_table);
	*paramcount = __arraycount(record_param_name_table);
	*plaincount = __arraycount(record_plain_name_table);
	return;
    }
    if (name[0] == 's') {
	*pfcount    = __arraycount(struct_prefix_name_table);
	*paramcount = __arraycount(struct_param_name_table);
	*plaincount = __arraycount(struct_plain_name_table);
	return;
    }

    fprintf(stderr, "%s: bad name %s\n", __func__, name);
    exit(-1);
}


/********************************************************/
/*							*/
/*	Sel_Ops_Names					*/
/*		returns the list of the names for	*/
/*			each type of operation		*/
/*		based on the name of the selector	*/
/*							*/
/********************************************************/

static void
sel_ops_names(const char *name,
	      nametable_t *pfname,
	      nametable_t *paramname,
	      nametable_t *plainname)
{
    if (name[0] == 'o') {
	*pfname    = oneof_prefix_name_table;
	*paramname = oneof_param_name_table;
	*plainname = oneof_plain_name_table;
	return;
    }
    if (name[0] == 'v') {
	*pfname    = variant_prefix_name_table;
	*paramname = variant_param_name_table;
	*plainname = variant_plain_name_table;
	return;
    }
    if (name[0] == 'r') {
	*pfname    = record_prefix_name_table;
	*paramname = record_param_name_table;
	*plainname = record_plain_name_table;
	return;
    }
    if (name[0] == 's') {
	*pfname    = struct_prefix_name_table;
	*paramname = struct_param_name_table;
	*plainname = struct_plain_name_table;
	return;
    }

    fprintf(stderr, "%s: bad name %s\n", __func__, name);
    exit(-1);
}


/********************************************************/
/*							*/
/*	Sel_Ops_Fcns					*/
/*		returns the list of the functions for	*/
/*			each type of operation		*/
/*		based on the name of the selector	*/
/*							*/
/********************************************************/

static void
sel_ops_fcns(const char *name,
	     proctable_t *pffcn, proctable_t *paramfcn, proctable_t *plainfcn)
{
    if (name[0] == 'o') {
	*pffcn    = oneof_prefix_fcn_table;
	*paramfcn = oneof_param_fcn_table;
	*plainfcn = oneof_plain_fcn_table;
	return;
    }
    if (name[0] == 'v') {
	*pffcn    = variant_prefix_fcn_table;
	*paramfcn = variant_param_fcn_table;
	*plainfcn = variant_plain_fcn_table;
	return;
    }

    if (name[0] == 'r') {
	*pffcn    = record_prefix_fcn_table;
	*paramfcn = record_param_fcn_table;
	*plainfcn = record_plain_fcn_table;
	return;
    }
    if (name[0] == 's') {
	*pffcn    = struct_prefix_fcn_table;
	*paramfcn = struct_param_fcn_table;
	*plainfcn = struct_plain_fcn_table;
	return;
    }

    fprintf(stderr, "%s: bad name %s\n", __func__, name);
    exit(-1);
}


/********************************************************/
/*							*/
/*	Sel_Ops_Restricts				*/
/*		returns the list of required functions  */
/*			one for each parameterized op	*/
/*							*/
/********************************************************/

static void
sel_ops_restricts(const char *name,
		  nametable_t *parm_reqs_names)
{
    if (name[0] == 'o') {
	*parm_reqs_names = oneof_reqs_name_table;
	return;
    }
    if (name[0] == 'v') {
	*parm_reqs_names = variant_reqs_name_table;
	return;
    }
    if (name[0] == 'r') {
	*parm_reqs_names = record_reqs_name_table;
	return;
    }
    if (name[0] == 's') {
	*parm_reqs_names = struct_reqs_name_table;
	return;
    }

    fprintf(stderr, "%s: bad name %s\n", __func__, name);
    exit(-1);
}
