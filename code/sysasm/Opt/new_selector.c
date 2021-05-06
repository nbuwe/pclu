/* Copyright Massachusetts Institute of Technology 1990,1991 */

/********************************************************/
/*							*/
/*	IMPLEMENTATION of SELECTORS		        */
/*							*/
/*	    routines common to oneof,variant,		*/
/*			       struct,record  		*/
/*							*/
/********************************************************/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* pstream$text = proc (ps: cvt, s: string) returns (bool) */
extern errcode pstreamOPtext(CLUREF ps, CLUREF s, CLUREF *ret_1);

static errcode add_sel_ops(const char *selname, long count, struct OPS *new_ops);
static long find_sel_ops(const char *selname, long count, struct OPS **result);

extern char *mystrcat(const char *s1, const char *s2);
extern errcode missing_print_fcn();

#define MAX_SELECTORS 500
#define MAX_FIELDS    50

static const char *sel_inst_fieldname[MAX_FIELDS];
static long sel_inst_fieldops[MAX_FIELDS];


errcode
add_selector_info(const char *field_name, long index, struct OPS *ops)
{
	sel_inst_fieldname[index] = field_name;
	sel_inst_fieldops[index] = (long)ops;
	signal(ERR_ok);	
}


typedef const char * const *nametable_t;
typedef PROC * const *proctable_t;

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
find_selector_ops(const char *selname, long nfields, struct SELOPS **table)
{
errcode err;
struct SELOPS *temp;
long nentries;
long i, j, jj, k, ans, index, offset;
CLUREF temp_proc;
long *temp_type_owns, *temp_op_owns;
struct OPS *ops;
const char *name, *name1, *field_name;
long *op_own_ptr;
bool found;
static bool init = false;
static CLUREF mpf;

long pf_op_count, parm_op_count, plain_op_count;
nametable_t pf_op_names;
nametable_t parm_op_names;
nametable_t plain_op_names;
nametable_t parm_restrict_name;
proctable_t pf_op_fcns, parm_op_fcns, plain_op_fcns;

/* try to find an existing ops */
	ans = find_sel_ops(selname, nfields, (struct OPS**)table);
	if (ans == true) {
		signal(ERR_ok);
		}

/* initial procedure type object for missing print function */
if (init == false) {
	err = proctypeOPnew(CLU_1, &mpf);
	if (err != ERR_ok) resignal(err);
	mpf.proc->proc = missing_print_fcn;
	init = true;
	}

/* create type owns */
	clu_alloc(UNIT, &temp_type_owns);
	temp_type_owns[0] = 1;

/* gather up some initial context */
        sel_ops_counts(selname, &pf_op_count, &parm_op_count, &plain_op_count);
        sel_ops_names(selname, &pf_op_names, &parm_op_names, &plain_op_names);
        sel_ops_fcns(selname, &pf_op_fcns, &parm_op_fcns, &plain_op_fcns);
	sel_ops_restricts(selname, &parm_restrict_name);

/* create basic ops structure */
	nentries = parm_op_count + plain_op_count + nfields * pf_op_count;
	clu_alloc(sizeof(struct SELOPS) + 
		(nentries-1)*sizeof(struct SELOP_ENTRY), &temp);
	temp->count = nentries;
	temp->type_owns = (OWNPTR)temp_type_owns;
	temp->op_owns = 0;

/* set up storage for parameterized operations */
/* 	--- assumes 4th entry (i == 3) is print & allocates storage for names */
/* 	--- assumes 8th entry (i == 7) is debug_print & allocates storage for names */

	for (i = 0; i < parm_op_count; i++) {
		temp->entry[i].name = parm_op_names[i];
		err = proctypeOPnew(CLU_1, &temp_proc);
		if (err != ERR_ok) resignal(err);
		temp->entry[i].fcn = temp_proc.selproc;

		if (i == 3 || i == 7) {
			clu_alloc(UNIT + nfields*sizeof(CLUPROC) + 
				nfields*sizeof(char*), &temp_op_owns);
			}
		else {
			clu_alloc(UNIT + nfields*sizeof(CLUPROC), 
				&temp_op_owns);
			}

		temp->entry[i].fcn->proc = parm_op_fcns[i];
		temp->entry[i].fcn->type_owns = (OWNPTR)temp_type_owns;
		temp->entry[i].fcn->op_owns = (OWNPTR)temp_op_owns;
		temp_op_owns[0] = 1;
		}

/* set up storage for plain operations */

	for (j = 0; j < plain_op_count; j++, i++) {
		temp->entry[i].name = plain_op_names[j];
		err = proctypeOPnew(CLU_1, &temp_proc);
		if (err != ERR_ok) resignal(err);
		temp->entry[i].fcn = temp_proc.selproc;

		temp->entry[i].fcn->proc = plain_op_fcns[j];
/*		temp->entry[i].fcn->table = NULL; */
		}

/* set up storage for postfixable operations */

	jj = 0;
	for (k = 0; k < nfields; k++) {
	for (j = 0; j < pf_op_count; j++, i++) {
		temp->entry[i].name = pf_op_names[j];
		err = proctypeOPnew(CLU_1, &temp_proc);
		if (err != ERR_ok) resignal(err);
		temp->entry[i].fcn = temp_proc.selproc;

/*		temp->entry[i].fcn->proc = plain_op_fcns[j]; */
		temp->entry[i].fcn->proc = pf_op_fcns[jj]; jj++;
/*		temp->entry[i].fcn->table = NULL; */
		}
		}

     for (index = 0; index < nfields; index++) {
	ops = (struct OPS *)sel_inst_fieldops[index];
	field_name = sel_inst_fieldname[index];
	for (i = 0; i < parm_op_count; i++) {
		name = parm_restrict_name[i];
		for (j = 0; j < ops->count; j++) {
			name1 = ops->entry[j].name;
			if (name1 == 0 || name1[0] != name[0]) continue;
			if (!(strcmp(name1, name))) {
				op_own_ptr = (long *)temp->entry[i].fcn->op_owns;
				op_own_ptr[index+1] =
					 (long)ops->entry[j].fcn;
				break;}
			}
		}
	offset = index*pf_op_count + parm_op_count + plain_op_count;
	for (i = 0; i < pf_op_count; i++) {
		temp->entry[offset+i].name = mystrcat(pf_op_names[i], field_name);
		}
	}

/* set up storage for parameterized operations */
/*	& names for postfixable operations */
/* 	--- assumes 4th entry (i == 3) is print & adds field names */
/* 	--- assumes 8th entry (i == 7) is print & adds field names */

     for (index = 0; index < nfields; index++) {
	ops = (struct OPS *)sel_inst_fieldops[index];
	field_name = sel_inst_fieldname[index];
	for (i = 0; i < parm_op_count; i++) {
		name = parm_restrict_name[i];
		found = false;
		for (j = 0; j < ops->count; j++) {
			name1 = ops->entry[j].name;
			if (name1 == 0 || name1[0] != name[0]) continue;
			if (!(strcmp(name1, name))) {
				op_own_ptr = (long *)temp->entry[i].fcn->op_owns;
				op_own_ptr[index+1] =
					 (long)ops->entry[j].fcn;
				if (i == 3 || i == 7) {
					op_own_ptr[index+1+nfields] =
						 (long)field_name;
					}
				found = true; break;}
			}
		if (found == false && (i == 3 || i == 7)) {
			op_own_ptr = (long *)temp->entry[i].fcn->op_owns;
			op_own_ptr[index+1] = (long)mpf.proc;
			op_own_ptr[index+1+nfields] = (long)field_name;
			}
		}
	offset = index*pf_op_count + parm_op_count + plain_op_count;
	for (i = 0; i < pf_op_count; i++) {
		temp->entry[offset+i].name = mystrcat(pf_op_names[i], field_name);
		}
	}

/* save ops for future users */
	add_sel_ops(selname, nfields, (struct OPS*)temp);

/* return created ops */
	*table = temp;
	signal(ERR_ok);
}


errcode
missing_print_fcn(CLUREF val, CLUREF pst)
{
    static bool init = false;
    static CLUREF msg;

    CLUREF ans;
    errcode err;

    if (init == false) {
	err = stringOPcons("no print function", CLU_1, CLU_17, &msg);
	if (err != ERR_ok) resignal(err);
	init = true;
    }

    err = pstreamOPtext(pst, msg, &ans);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}


/* storage for following routine */

OWNPTR	record_opsptr_arr[MAX_SELECTORS]; /* instantiated ops */
OWNPTR	struct_opsptr_arr[MAX_SELECTORS]; /* instantiated ops */
OWNPTR	variant_opsptr_arr[MAX_SELECTORS]; /* instantiated ops */
OWNPTR	oneof_opsptr_arr[MAX_SELECTORS]; /* instantiated ops */

long 	record_field_count [MAX_SELECTORS];
long 	struct_field_count [MAX_SELECTORS];
long 	variant_field_count [MAX_SELECTORS];
long 	oneof_field_count [MAX_SELECTORS];

long *	record_field_vals [MAX_SELECTORS][MAX_FIELDS];
long *	struct_field_vals [MAX_SELECTORS][MAX_FIELDS];
long *	variant_field_vals [MAX_SELECTORS][MAX_FIELDS];
long *	oneof_field_vals [MAX_SELECTORS][MAX_FIELDS];
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

		record_opsptr_arr[i] = 0;
		struct_opsptr_arr[i] = 0;
		variant_opsptr_arr[i] = 0;
		oneof_opsptr_arr[i] = 0;

		record_field_count[i] = 0;
		struct_field_count[i] = 0;
		variant_field_count[i] = 0;
		oneof_field_count[i] = 0;
		for (size_t j = 0; j < MAX_FIELDS; j++) {
			record_field_vals[i][j]    = (long*) 0;
			struct_field_vals[i][j]    = (long*) 0;
			variant_field_vals[i][j]    = (long*) 0;
			oneof_field_vals[i][j]    = (long*) 0;
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

static long
find_sel_ops(const char *selname, long count, struct OPS **result)
{
long i, j;
bool found = false;
long *pcount;
OWNPTR *table;
long *(*parm_vals)[MAX_FIELDS];
long *parm_count;


	/* if too many fields, then die */

	if (count >= MAX_FIELDS) {
		fprintf(stderr, 
			"find_sel_ops: too many fields: increase MAX_FIELDS\n");
		exit(-10);
		}

	/* first select which table */
	if (selname[0] == 'r') {
		pcount = &record_num_entries;
		table = record_opsptr_arr;
		parm_count = record_field_count;
		parm_vals = record_field_vals;
		}
	if (selname[0] == 's') {
		pcount = &struct_num_entries;
		table = struct_opsptr_arr;
		parm_count = struct_field_count;
		parm_vals = struct_field_vals;
		}
	if (selname[0] == 'v') {
		pcount = &variant_num_entries;
		table = variant_opsptr_arr;
		parm_count = variant_field_count;
		parm_vals = variant_field_vals;
		}
	if (selname[0] == 'o') {
		pcount = &oneof_num_entries;
		table = oneof_opsptr_arr;
		parm_count = oneof_field_count;
		parm_vals = oneof_field_vals;
		}


	found = false;
	for (i = 0 ; i < *pcount; i++) {
		if ((parm_count)[i] != count) continue;
		found = true;
		for (j = 0; j < count; j++) {
			if (sel_inst_fieldops[j] ==
				(long)(parm_vals)[i][j]) continue;
			else {found = false; break;}
			}
		if (found) break;
		}



	if (found) {
	/* entry found: return owns */
		*result = (struct OPS *)table[i];
		return (true);
		}
	else {
		return (false);
		}
	}

static errcode
add_sel_ops(const char *selname, long count, struct OPS *new_ops)
{
long j;
long *pcount;
OWNPTR *table;
long *(*parm_vals)[MAX_FIELDS];
long *parm_count;

	/* first select which table */
	if (selname[0] == 'r') {
		pcount = &record_num_entries;
		table = record_opsptr_arr;
		parm_count = record_field_count;
		parm_vals = record_field_vals;
		}
	if (selname[0] == 's') {
		pcount = &struct_num_entries;
		table = struct_opsptr_arr;
		parm_count = struct_field_count;
		parm_vals = struct_field_vals;
		}
	if (selname[0] == 'v') {
		pcount = &variant_num_entries;
		table = variant_opsptr_arr;
		parm_count = variant_field_count;
		parm_vals = variant_field_vals;
		}
	if (selname[0] == 'o') {
		pcount = &oneof_num_entries;
		table = oneof_opsptr_arr;
		parm_count = oneof_field_count;
		parm_vals = oneof_field_vals;
		}

		table[*pcount] = (OWNPTR) new_ops;
		(parm_count)[*pcount] = count;
		for (j = 0 ; j < count; j++) {
			(parm_vals)[*pcount][j] =
				(long*)sel_inst_fieldops[j]; 
			}
		(*pcount)++;
		if (*pcount == MAX_SELECTORS) {
			fprintf(stderr, 
		"add_sel_ops: too many instantiations: increase MAX_INSTS\n");
			exit(-10);
			}
		signal(ERR_ok);
		}	


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
/*	if (strcmp(name, "oneof") == 0) { */
	if (name[0] == 'o') {
		*pfcount = 3;
		*paramcount = 8;
		*plaincount = 2;
		return; }
/*	if (strcmp(name, "variant") == 0) { */
	if (name[0] == 'v') {
		*pfcount = 4;
		*paramcount = 8;
		*plaincount = 4;
		return; }
/*	if (strcmp(name, "record") == 0) { */
	if (name[0] == 'r') {
		*pfcount = 2;
		*paramcount = 8;
		*plaincount = 4;
		return; }
/*	if (strcmp(name, "struct") == 0) { */
	if (name[0] == 's') {
		*pfcount = 2;
		*paramcount = 8;
		*plaincount = 2;
		return; }
	fprintf(stderr, "sel_ops_counts: bad name %s\n", name);
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
/*	if (strcmp(name, "oneof") == 0) { */
	if (name[0] == 'o') {
		*pfname = oneof_prefix_name_table;
		*paramname = oneof_param_name_table;
		*plainname = oneof_plain_name_table;
		return; }
/*	if (strcmp(name, "variant") == 0) { */
	if (name[0] == 'v') {
		*pfname = variant_prefix_name_table;
		*paramname = variant_param_name_table;
		*plainname = variant_plain_name_table;
		return; }
/*	if (strcmp(name, "record") == 0) { */
	if (name[0] == 'r') {
		*pfname = record_prefix_name_table;
		*paramname = record_param_name_table;
		*plainname = record_plain_name_table;
		return; }
/*	if (strcmp(name, "struct") == 0) { */
	if (name[0] == 's') {
		*pfname = struct_prefix_name_table;
		*paramname = struct_param_name_table;
		*plainname = struct_plain_name_table;
		return; }
	fprintf(stderr, "sel_ops_names: bad name %s\n", name);
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
/*	if (strcmp(name, "oneof") == 0) { */
	if (name[0] == 'o') {
		*pffcn = oneof_prefix_fcn_table;
		*paramfcn = oneof_param_fcn_table;
		*plainfcn = oneof_plain_fcn_table;
		return; }
/*	if (strcmp(name, "variant") == 0) { */
	if (name[0] == 'v') {
		*pffcn = variant_prefix_fcn_table;
		*paramfcn = variant_param_fcn_table;
		*plainfcn = variant_plain_fcn_table;
		return; }
/*	if (strcmp(name, "record") == 0) { */
	if (name[0] == 'r') {
		*pffcn = record_prefix_fcn_table;
		*paramfcn = record_param_fcn_table;
		*plainfcn = record_plain_fcn_table;
		return; }
/*	if (strcmp(name, "struct") == 0) { */
	if (name[0] == 's') {
		*pffcn = struct_prefix_fcn_table;
		*paramfcn = struct_param_fcn_table;
		*plainfcn = struct_plain_fcn_table;
		return; }
	fprintf(stderr, "sel_ops_fcns: bad name %s\n", name);
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
/*	if (strcmp(name, "oneof") == 0) { */
	if (name[0] == 'o') {
		*parm_reqs_names = oneof_reqs_name_table;
		return; }
/*	if (strcmp(name, "variant") == 0) { */
	if (name[0] == 'v') {
		*parm_reqs_names = variant_reqs_name_table;
		return; }
/*	if (strcmp(name, "record") == 0) { */
	if (name[0] == 'r') {
		*parm_reqs_names = record_reqs_name_table;
		return; }
/*	if (strcmp(name, "struct") == 0) { */
	if (name[0] == 's') {
		*parm_reqs_names = struct_reqs_name_table;
		return; }
	fprintf(stderr, "sel_ops_fcns: bad name %s\n", name);
	exit(-1);
	}
