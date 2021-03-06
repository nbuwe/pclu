/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*
 * IMPLEMENTATION of Parameterized Type utilities
 *
 * For something like:
 *
 *   foos = sequence[foo]
 *
 * the compiler generates C code like:
 *
 *   // built-in (sequence.c)
 *   extern struct OPS *sequence_ops;        // the template (abstract ops)
 *   extern struct REQS *sequence_of_t_reqs; // what it needs of T
 *   extern const OWN_req sequence_ownreqs;  // how to instantiate owns
 *
 *   // comes from elsewhere
 *   extern struct OPS *foo_ops;             // parameter's ops
 *
 *   // the ops for "foos"
 *   struct OPS *sequence_of_foo_ops;        // the instance
 *
 *   // pass parameters on an internal argument stack
 *   add_parm_info_type(0, foo_ops, sequence_of_t_reqs);
 *
 *   // build ops
 *   find_type_instance(sequence_ops, 1, &sequence_ownreqs,
 *       &sequence_of_foo_ops);
 *
 * Similarly standalone parmd procedure or iterator are instantiated
 * with find_prociter_instance() and parmd operations of a type are
 * instantiated with find_typeop_instance().
 */

#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdio.h>
#include <stdlib.h>

static void add_ops(const struct OPS *aops, errcode (*procaddr)(), long nparm,
		    struct OPS *instance, long tdefs, long odefs);
static bool find_ops(const struct OPS *aops, errcode (*procaddr)(), long nparm,
		     struct OPS **instance);

static errcode build_type_ops(const struct OPS *aops, long nparm, OWNPTR owns,
			      struct OPS **instance);
static errcode build_parm_table2(const struct REQS *reqs, const struct OPS *ops,
				 struct OPS **table, long *defs);
static errcode update_parm_table2(const struct REQS *reqs, const struct OPS *ops,
				  struct OPS **table, long *defs);
static void update_type_ops(long nparm, const OWN_req *ownreqp,
			    struct OPS **instance);
static void update_op_ops(long nparm, long ntparm, const OWN_req *ownreqp,
			  struct OPS **instance);
static void update_ops(void);

#define MAX_INSTS 500
#define MAX_PARMS 20

static long inst_parm_value[MAX_PARMS];
static const struct REQS *inst_parm_reqs[MAX_PARMS]; /* NULL for consts */
static long current_tdefs;
static long current_odefs;

static long fti_tdefs;


/*
 * Save information about the index'th parameter, a type, for use in
 * instance finding routines.
 */
void
add_parm_info_type(long index, const struct OPS *ops, const struct REQS *reqs)
{
    inst_parm_value[index] = (long)ops;
    inst_parm_reqs[index] = reqs;
}


/*
 * Save information about the index'th parameter, a constant, for use
 * in instance finding routines
 */
void
add_parm_info_const(long index, CLUREF value)
{
    inst_parm_value[index] = value.num;
    inst_parm_reqs[index] = NULL;
}


/*
 * OWNREQ tells how to allocate and init the OWNPTR data for an
 * instance.  The compiler defines the parmd code's view of its ownptr
 * as a foo_OWN_DEFN structure where OWN_ptr::info[] elements are
 * separate, named fields that contain space for own variables and for
 * the parameter ops/constants.
 */
static OWNPTR
owns_alloc(const OWN_req *ownreqp)
{
    size_t owns_size = ownreqp->size;
    if (owns_size == 0)
	owns_size = offsetof(OWN_ptr, info); /* just the flag */

    OWNPTR owns;
    clu_alloc(owns_size, &owns);
    // owns->init_flag = 0; // allocated memory is already zeroed out
    return owns;
}


/*
 * Create (or find existing) instance of type ops template "aops"
 * (abstract ops) parameterized with "nparm" inst_parm_*[] parameters.
 */
errcode
find_type_instance(const struct OPS *aops,
		   long nparm, const OWN_req *ownreqp,
		   struct OPS **result)
{
    /* see if the instance already exists */
    bool already = find_ops(aops, 0, nparm, result);
    if (already) {
	if (current_tdefs != 0)
	    update_type_ops(nparm, ownreqp, result);
	signal(ERR_ok);
    }

    OWNPTR owns = owns_alloc(ownreqp);

    /* allocate and build aops instance */
    struct OPS *ops;
    build_type_ops(aops, nparm, owns, &ops);

    /*
     * Put parm values into the own structure:
     *   put const value for const parameters
     *   build parm table per reqs for type parameters
     */
    long tdefs = 0;
    for (long i = 0; i < nparm; ++i) {
	/* Pointer to a field in the instance's _OWN_DEFN structure */
	long *fieldp = owns->info + (ownreqp->own_count - 1) + i;

	if (inst_parm_reqs[i] == NULL) {
	    /* a constant parameter */
	    *fieldp = inst_parm_value[i];
	}
	else {
	    /* a type parameter */
	    const struct OPS *parm_ops
		= (const struct OPS *)inst_parm_value[i];

	    /* extract from parm_ops what's required of them */
	    build_parm_table2(inst_parm_reqs[i], parm_ops,
			      (struct OPS **)fieldp,
			      &tdefs);
	}
    }

    /* save the result for the future */
    add_ops(aops, NULL, nparm, ops, tdefs, 0);

    /* "return" tdefs if called by find_typeop_instance */
    fti_tdefs = tdefs;

    *result = ops;
    signal(ERR_ok);
}


/*
 * Create (or find existing) instance of own data for a parmd op of a
 * type.  The type may be parmd or unparmd.  The result is OPS, but a
 * degenerate one, with only the type and op ownptrs and no entries.
 *
 * inst_parm_*[] parameters contains "nparm" parameters of which the
 * first "ntparm" are the parameters for the type (may be 0).
 */
errcode
find_typeop_instance(const struct OPS *aops,
		     errcode (*procaddr)(),
		     long nparm, long ntparm,
		     const OWN_req *ownreqp, const OWN_req *townreqp,
		     struct OPS **result)
{
    /* look up type/op instance and return it if it exists */
    bool already = find_ops(aops, procaddr, nparm, result);
    if (already) {
	if (current_tdefs != 0)
	    update_type_ops(ntparm, townreqp, result);
	if (current_odefs != 0)
	    update_op_ops(nparm, ntparm, ownreqp, result);
	signal(ERR_ok);
    }

    OWNPTR owns = owns_alloc(ownreqp);

    /* find/build type instance */
    struct OPS *type_ops;
    find_type_instance(aops, ntparm, townreqp, &type_ops);
    long tdefs = fti_tdefs;

    /*
     * Create dummy ops structure that is used only as a container for
     * the op's ownptr.
     */
    struct OPS *ops;
    clu_alloc(sizeof(struct OPS), &ops);
    ops->type_owns = type_ops->type_owns;
    ops->op_owns = owns;

    /*
     * Put parm values into the own structure:
     *   put const value for const parameters
     *   build parm table per reqs for type parameters
     */
    long odefs = 0;
    for (long i = 0; i < nparm - ntparm; ++i) {
	/* Pointer to a field in the instance's _OWN_DEFN structure */
	long *fieldp = owns->info + (ownreqp->own_count - 1) + i;

	if (inst_parm_reqs[ntparm + i] == NULL) {
	    /* a constant parameter */
	    *fieldp = inst_parm_value[ntparm + i];
	}
	else {
	    /* a type parameter */
	    const struct OPS *parm_ops
		= (const struct OPS *)inst_parm_value[ntparm + i];

	    build_parm_table2(inst_parm_reqs[ntparm + i], parm_ops,
			      (struct OPS **)fieldp,
			      &odefs);
	}
    }

    /* save result for the future */
    add_ops(aops, procaddr, nparm, ops, tdefs, odefs);

    *result = ops;
    signal(ERR_ok);
}


/*
 * Create (or find existing) instance of own data for a parmd
 * procedure or iterator.  The result is OPS, but a degenerate one,
 * with only the op ownptr and no entries.
 */
errcode
find_prociter_instance(errcode (*procaddr)(),
		       long nparm, const OWN_req *ownreqp,
		       struct OPS **result)
{
    /* look up type/op instance and return it if it exists */
    bool already = find_ops(NULL, procaddr, nparm, result);
    if (already) {
	if (current_odefs != 0)
	    update_op_ops(nparm, 0, ownreqp, result);
	signal(ERR_ok);
    }

    OWNPTR owns = owns_alloc(ownreqp);

    /*
     * Create dummy ops structure that is used only as a container for
     * the op's ownptr.
     */
    struct OPS *ops;
    clu_alloc(sizeof(struct OPS), &ops);
    ops->type_owns = NULL;	/* doesn't belong to a type */
    ops->op_owns = owns;

    /*
     * Put parm values into the own structure:
     *   put const value for const parameters
     *   build parm table per reqs for type parameters
     */
    long odefs = 0;
    for (long i = 0; i < nparm; ++i) {
	/* Pointer to a field in the instance's _OWN_DEFN structure */
	long *fieldp = owns->info + (ownreqp->own_count - 1) + i;

	if (inst_parm_reqs[i] == NULL) {
	    /* a constant parameter */
	    *fieldp = inst_parm_value[i];
	}
	else {
	    /* a type parameter */
	    const struct OPS *parm_ops
		= (const struct OPS *)inst_parm_value[i];

	    build_parm_table2(inst_parm_reqs[i], parm_ops,
			      (struct OPS **)fieldp,
			      &odefs);
	}
    }

    /* save result for the future */
    add_ops(NULL, procaddr, nparm, ops, 0, odefs);

    *result = ops;
    signal(ERR_ok);
}


/*
 * Instantiate type ops: create a copy of the abstract ops template
 * and fill it with instantiated type owns.
 *
 * "nparm" is only used as input to proctype$new, to be obsoleted.
 */
static errcode
build_type_ops(const struct OPS *aops, long nparm, OWNPTR owns,
	       struct OPS **instance)
{
    errcode err;

    size_t size = offsetof(struct OPS, entry)		/* header */
	+ aops->count * sizeof(struct OP_ENTRY);	/* entries */

    struct OPS *ops;
    clu_alloc(size, &ops);
    ops->count = aops->count;
    ops->type_owns = owns;

    for (long i = 0; i < aops->count; ++i) {
	CLUREF proc;
	err = proctypeOPnew(CLUREF_make_num(nparm), &proc);
	if (err != ERR_ok)
	    resignal(err);

	proc.proc->proc = aops->entry[i].fcn->proc;
	proc.proc->type_owns = owns;
	proc.proc->op_owns = owns;

	ops->entry[i].fcn = proc.proc;
	ops->entry[i].name = aops->entry[i].name;
    }

    *instance = ops;
    signal(ERR_ok);
}


/*
 * Instantiate "cluster C [..., T: type, ...] ... where T has ..."
 * template, building the part for the specific parm type T.  Here
 * specific T used for this instance is represented by its "ops", and
 * the "where" clause of the template is described by "reqs".
 *
 * The output ops is the C's "view" of T (<c>_of_<t>_OPS) and is
 * stored in the <c>_OWN_DEFN::<t>_ops, pointed to by "table".
 *
 * XXX: The "defs" and the incremental updates it's used for is
 * probably no longer relevant, but I'm not entirely sure yet.
 */
static errcode
build_parm_table2(const struct REQS *reqs, const struct OPS *ops,
		  struct OPS **table, long *defs)
{
    long i,j;
    const char *name, *name1;

    struct OPS *temp;
    clu_alloc(sizeof(struct OPS) +
	      sizeof(struct OP_ENTRY) * reqs->count, &temp);

    /* increment to cover print function for debugger 11/12/91*/
    temp->count = reqs->count + 1;
    /* defs calculated number of fcns missing vs reqs */
    *defs += temp->count;

    /* checked ops before use 11/12/91 */
    if (ops == NULL) {
	temp->type_owns = NULL;
	temp->op_owns = NULL;
	*table = temp;
	signal(ERR_ok);
    }

    temp->type_owns = ops->type_owns;
    temp->op_owns = ops->op_owns;

    for (i = 0; i < reqs->count; ++i) {
	name = reqs->entry[i].name;
	for (j = 0; j < ops->count; ++j) {
	    name1 = ops->entry[j].name;
	    if (name1 == NULL || name1[0] != name[0])
		continue;
	    if (strcmp(name1, name) == 0) {
		temp->entry[i].name = name1;
		temp->entry[i].fcn = ops->entry[j].fcn;
		--*defs;
		break;
	    }
	}
    }

    /* add in debug_print function for debugger 11/12/91 */
    for (j = 0; j < ops->count; ++j) {
	name1 = ops->entry[j].name;
	if (name1 == NULL)
	    continue;
	if (strcmp(name1, "debug_print") == 0) {
	    temp->entry[i].name = name1;
	    temp->entry[i].fcn = ops->entry[j].fcn;
	    --*defs;
	    break;
	}
    }

    *table = temp;
    signal(ERR_ok);
}



/*
 * Suppose an instantiation without any where clauses has occurred.
 * Suppose the same instantiation is desired but now there are where
 * clauses.  Let's fill them in.
 */
static void
update_type_ops(long nparm, const OWN_req *ownreqp, struct OPS **instance)
{
    long *owns = (long *)(*instance)->type_owns;

    long tdefs = current_tdefs;
    for (long i = 0; i < nparm; ++i) {
	if (inst_parm_reqs[i] == NULL) /* a constant parameter */
	    continue;

	const struct OPS *parm_ops
	    = (const struct OPS *)inst_parm_value[i];

	update_parm_table2(inst_parm_reqs[i], parm_ops,
			   (struct OPS **)&owns[ownreqp->own_count + i],
			   &tdefs);
    }
    current_tdefs = tdefs;
    update_ops();
}


static void
update_op_ops(long nparm, long ntparm, const OWN_req *ownreqp,
	      struct OPS **instance)
{
    long *owns = (long *)(*instance)->op_owns;

    long odefs = current_odefs;
    for (long i = 0; i < nparm - ntparm; ++i) {
	if (inst_parm_reqs[ntparm + i] == NULL) /* a constant parameter */
	    continue;

	const struct OPS *parm_ops
	    = (const struct OPS *)inst_parm_value[ntparm + i];

	update_parm_table2(inst_parm_reqs[ntparm + i], parm_ops,
			   (struct OPS **)&owns[ownreqp->own_count + i],
			   &odefs);
    }
    current_odefs = odefs;
}


static errcode
update_parm_table2(const struct REQS *reqs, const struct OPS *ops,
		   struct OPS **table, long *defs)
{
    struct OPS *temp;
    long i,j;
    const char *name, *name1;

    temp = *table;
    /* increment to cover print function for debugger 11/12/91*/
    temp->count = reqs->count + 1;     /* count sb ok already */
    /* checked ops before use 11/12/91 */
    if (ops == NULL) {
	*table = temp;
	signal(ERR_ok);
    }

    temp->type_owns = ops->type_owns;  /* type owns sb ok already */
    temp->op_owns = ops->op_owns;      /* op owns sb ok already */
    for (i = 0; i < reqs->count; ++i) {
	if (temp->entry[i].fcn != NULL)
	    continue; /* entry already ok */

	name = reqs->entry[i].name;
	for (j = 0; j < ops->count; ++j) {
	    name1 = ops->entry[j].name;
	    if (name1 == NULL || name1[0] != name[0])
		continue;
	    if (strcmp(name1, name) == 0) {
		temp->entry[i].name = name1;
		temp->entry[i].fcn = ops->entry[j].fcn;
		--*defs;
		break;
	    }
	}
    }

    /* add in debug_print function for debugger 11/12/91 */
    for (j = 0; j < ops->count; ++j) {
	name1 = ops->entry[j].name;
	if (name1 == NULL)
	    continue;
	if (strcmp(name1, "debug_print") == 0) {
	    temp->entry[i].name = name1;
	    temp->entry[i].fcn = ops->entry[j].fcn;
	    --*defs;
	    break;
	}
    }
    *table = temp;
    signal(ERR_ok);
}



/* storage for following routine */

static const struct OPS *ops_arr[MAX_INSTS]; /* abstract ops */
static errcode (*ops_proc[MAX_INSTS])();     /* abstract proc */
static OPSPTR opsptr_arr[MAX_INSTS];	     /* instantiated ops */

static long parm_vals[MAX_INSTS][MAX_PARMS];
static const struct REQS *parm_reqs[MAX_INSTS][MAX_PARMS]; /* NULL => const */

static long parm_types_defs[MAX_INSTS]; /* count of missing fcns on type */
static long parm_ops_defs[MAX_INSTS];   /* count of missing fcns per op/proc */
static long num_entries = 0;

/* routine to initialize structures used by find_ops */
void
find_ops_init(OWNPTR *ans1, OWNREQ *ans2, void **ans3)
{
#if 0 /* removed 1/28/91 to speed up start_up dwc */
    for (size_t i = 0; i < MAX_INSTS; ++i) {
	opsptr_arr[i] = 0;
	ops_arr[i] = 0;
	ops_proc[i] = 0;
	for (size_t j = 0; j < MAX_PARMS; ++j) {
	    parm_vals[i][j] = 0;
	    parm_reqs[i][j] = NULL;
	}
    }
#endif
    *ans1 = (OWNPTR)opsptr_arr;
    *ans2 = (OWNREQ)ops_arr;
    *ans3 = (void *)ops_proc;	/* errcode (**ans3)() */
}


/* routine to find ops given type and instance information */

static bool
find_ops(const struct OPS *aops, errcode (*procaddr)(), long nparm,
	 struct OPS **instance)
{
    long i, j;

    /* if too many parms, then die */
    if (nparm >= MAX_PARMS) {
	fprintf(stderr,
		"find_ops: too many parameters: increase MAX_PARMS\n");
	exit(-10);
    }

    bool found = false;
    for (i = 0; i < num_entries; ++i) {

	/* same type/op template? */
	if (aops != ops_arr[i] || procaddr != ops_proc[i])
	    continue;		/* next template */

	/* type/op match: see if parameters line up */
	found = true;	/* tentatively */
	for (j = 0; j < nparm; ++j) {
	    if (parm_reqs[i][j] == NULL) {
		/* make sure instance parm is a constant */
		/* and check constant value equality */
		if (inst_parm_reqs[j] == NULL
		    && inst_parm_value[j] == parm_vals[i][j])
		    continue;	/* next parm */
		else {
		    found = false;
		    break;
		}
	    }
	    else {
		/* make sure isntance parm is a type */
		/* and check type match via type_owns */
		if (inst_parm_reqs[j] != NULL) {
		    const struct OPS *ops1 = (const struct OPS *)inst_parm_value[j];
		    const struct OPS *ops2 = (const struct OPS *)parm_vals[i][j];
		    if (ops1->type_owns == ops2->type_owns)
			continue; /* next parm */
		    else {
			found = false;
			break;
		    }
		}
		else {
		    found = false;
		    break;
		}
	    }
	}

	if (found)
	    break;
    }

    if (found) {
	/* entry found: return owns */
	*instance = opsptr_arr[i];
	current_tdefs = parm_types_defs[i];
	current_odefs = parm_ops_defs[i];
	return true;
    }
    else {
	return false;
    }
}


static void
add_ops(const struct OPS *aops, errcode (*procaddr)(), long nparm,
	struct OPS *instance, long tdefs, long odefs)
{
    long slot = num_entries++;
    if (num_entries == MAX_INSTS) { /* XXX: sic */
	fprintf(stderr,
		"add_ops: too many instantiations: increase MAX_INSTS\n");
	exit(-10);
    }

    ops_arr[slot] = aops;
    ops_proc[slot] = procaddr;
    opsptr_arr[slot] = instance;
    parm_types_defs[slot] = tdefs;
    parm_ops_defs[slot] = odefs;
    for (long j = 0; j < nparm; ++j) {
	parm_vals[slot][j] = inst_parm_value[j];
	parm_reqs[slot][j] = inst_parm_reqs[j];
    }
}


static void
update_ops(void)
{
    /* XXX: this is kinda suspect */
    parm_types_defs[num_entries] = current_tdefs;
    parm_ops_defs[num_entries] = current_odefs;
}



#ifdef CLU_DEBUG_IMPL
/*
 * Give the debugger access to this from Clu code.
 *
 * Note that we should not use signal() macro here as with CLU_DEBUG
 * it includes the debugger hooks and we don't want them.
 */


errcode
clu_add_parm_info_type(CLUREF nth_entry, CLUREF ptr_to_ops, CLUREF ptr_to_reqs)
{
    long index = nth_entry.num;
    const struct OPS *ops = (const struct OPS *)ptr_to_ops.num;
    const struct REQS *reqs = (const struct REQS *)ptr_to_reqs.num;

    add_parm_info_type(index, ops, reqs);
    return ERR_ok;
}


errcode
clu_add_parm_info_const(CLUREF nth_entry, CLUREF value)
{
    long index = nth_entry.num;

    add_parm_info_const(index, value);
    return ERR_ok;
}


errcode
clu_find_type_instance(CLUREF aops_, CLUREF nparm_, CLUREF ownreqp_,
		       CLUREF *ansops)
{
    const struct OPS *aops = (const struct OPS *)aops_.num;
    long nparm = nparm_.num;
    const OWN_req *ownreqp = (const OWN_req *)ownreqp_.num;

    struct OPS *ops;
    find_type_instance(aops, nparm, ownreqp, &ops);

    ansops->num = (long)ops;
    return ERR_ok;
}


errcode
clu_find_typeop_instance(CLUREF aops_, CLUREF procaddr_,
			 CLUREF nparm_, CLUREF ntparm_,
			 CLUREF ownreqp_, CLUREF townreqp_,
			 CLUREF *ansops)
{
    const struct OPS *aops = (const struct OPS *)aops_.num;
    PROC *procaddr = (PROC *)procaddr_.num;
    long nparm = nparm_.num;
    long ntparm = ntparm_.num;
    const OWN_req *ownreqp = (const OWN_req *)ownreqp_.num;
    const OWN_req *townreqp = (const OWN_req *)townreqp_.num;

    struct OPS *ops;
    find_typeop_instance(aops, procaddr, nparm, ntparm,
			 ownreqp, townreqp, &ops);

    ansops->num = (long)ops;
    return ERR_ok;
}


errcode
clu_find_prociter_instance(CLUREF procaddr_, CLUREF nparm_, CLUREF ownreqp_,
			   CLUREF *ansops)
{
    PROC *procaddr = (PROC *)procaddr_.num;
    long nparm = nparm_.num;
    const OWN_req *ownreqp = (const OWN_req *)ownreqp_.num;

    struct OPS *ops;
    find_prociter_instance(procaddr, nparm, ownreqp, &ops);

    ansops->num = (long)ops;
    return ERR_ok;
}


/*
 * Given the address of an instantiated type, return abstract ops for
 * that type, the number of parameters, and the index of the
 * instantiation.
 */
errcode
find_tgen(CLUREF tops,
	  CLUREF *ansaops, CLUREF *ansnparm, CLUREF *ansindex)
{
    const struct OPS *ops = (const struct OPS *)tops.num;

    for (long i = 0; i < num_entries; ++i) {
	if (opsptr_arr[i] == ops) {
	    ansaops->num = (long)ops_arr[i];
	    ansindex->num = i;

	    /*
	     * XXX: uwe: this seems wrong in the presence of constant
	     * parameters.
	     */
	    for (long j = 0; j < MAX_PARMS; ++j) {
		if (parm_reqs[i][j] == NULL) {
		    ansnparm->num = j;
		    break;
		}
	    }
	    return ERR_ok;
	}
    }

    return ERR_not_found;
}


/*
 * Given the index of an instantiation and the index of the parameter
 * for that instantiation return ops for that parameter.
 */
errcode
find_tgen_parm(CLUREF index, CLUREF ith, CLUREF *ansops)
{
    ansops->num = (long)parm_vals[index.num][ith.num];
    return ERR_ok;
}
#endif	/* CLU_DEBUG_IMPL */
