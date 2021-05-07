/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*	 	    PROCTYPE			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"


errcode
proctypeOPnew(CLUREF nops, CLUREF *ans)
{
    size_t size = sizeof(CLU_proc);
#if 0
    if (nops.num > 1)
	size += (nops.num - 1) * sizeof(struct OPS *);
#else
    (void) nops;
#endif

    CLUREF temp;
    clu_alloc(size, &temp);
    temp.proc->typ.val = CT_PROC;
    temp.proc->typ.mark = 0;
    temp.proc->typ.refp = 0;

    ans->proc = temp.proc;
    signal(ERR_ok);
}


/* totally wrong */
errcode
proctypeOPequal(CLUREF x1, CLUREF x2, CLUREF *ans)
{
    if (x1.proc->proc == x2.proc->proc)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


/* totally wrong */
errcode
proctypeOPsimilar(CLUREF x1, CLUREF x2, CLUREF *ans)
{
    if (x1.proc == x2.proc)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
proctypeOPcopy(CLUREF x1, CLUREF *ans)
{
    *ans = x1;
    signal(ERR_ok);
}


errcode
proctypeOPdebug_print(CLUREF x1, CLUREF ps)
{
    errcode err;
    CLUREF ans, str;

    stringOPcons("proctype", CLU_1, CLU_8, &str);
    err = pstreamOPtextc(ps, str, &ans);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}



OWN_ptr proctype_own_init = { .init_flag = 1 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &proctype_own_init,		\
    .op_owns = &proctype_own_init,		\
}

CLU_proc proctype_oe_copy = CLU_proc_INIT(proctypeOPcopy);
CLU_proc proctype_oe_equal = CLU_proc_INIT(proctypeOPequal);
CLU_proc proctype_oe_similar = CLU_proc_INIT(proctypeOPsimilar);
CLU_proc proctype_oe_debug_print = CLU_proc_INIT(proctypeOPdebug_print);

/* extends struct OPS */
typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[4];
} proctype_OPS;

proctype_OPS proctype_ops_actual = {
    4,
    &proctype_own_init,
    &proctype_own_init,
    {
	{&proctype_oe_copy, "copy"},
	{&proctype_oe_equal, "equal"},
	{&proctype_oe_similar, "similar"},
	{&proctype_oe_debug_print, "debug_print"},
    }
};

OPSPTR proctype_ops = (OPSPTR)&proctype_ops_actual;
