/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*	 	    ITERTYPE			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

errcode pstreamOPtextc(CLUREF ps, CLUREF c, CLUREF *ret_1);


errcode
itertypeOPnew(CLUREF nops, CLUREF *ans)
{
    CLUREF temp;

    size_t size = sizeof(CLU_proc);
    if (nops.num > 1)		/* XXX? */
	size += (nops.num - 1) * sizeof(struct OPS *);

    clu_alloc(size, &temp);
    temp.proc->typ.val = CT_PROC;
    temp.proc->typ.mark = 0;
    temp.proc->typ.refp = 0;

    ans->proc = temp.proc;
    signal(ERR_ok);
}


errcode
itertypeOPequal(CLUREF x1, CLUREF x2, CLUREF *ans)
{
    if (x1.proc == x2.proc)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
itertypeOPsimilar(CLUREF x1, CLUREF x2, CLUREF *ans)
{
    if (x1.proc == x2.proc)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
itertypeOPcopy(CLUREF x1, CLUREF *ans)
{
    ans->proc = x1.proc;
    signal(ERR_ok);
}


errcode
itertypeOPdebug_print(CLUREF x1, CLUREF ps)
{
    CLUREF str, ans;
    errcode err;

    CLU_NOREF(x1);

    stringOPcons("itertype", CLU_1, CLU_8, &str);
    err = pstreamOPtextc(ps, str, &ans);
    if (err != ERR_ok) resignal(err);
    signal(ERR_ok);
}



OWN_ptr itertype_own_init = { .init_flag = 1 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &itertype_own_init,		\
    .op_owns = &itertype_own_init,		\
}

CLU_proc itertype_oe_copy = CLU_proc_INIT(itertypeOPcopy);
CLU_proc itertype_oe_equal = CLU_proc_INIT(itertypeOPequal);
CLU_proc itertype_oe_similar = CLU_proc_INIT(itertypeOPsimilar);
CLU_proc itertype_oe_debug_print = CLU_proc_INIT(itertypeOPdebug_print);

/* extends struct OPS */
typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[4];
} itertype_OPS;

itertype_OPS itertype_ops_actual = {
    4,
    &itertype_own_init,
    &itertype_own_init,
    {
	{ &itertype_oe_copy, "copy" },
	{ &itertype_oe_equal, "equal" },
	{ &itertype_oe_similar, "similar" },
	{ &itertype_oe_debug_print, "debug_print" },
    }
};

itertype_OPS *itertype_ops = &itertype_ops_actual;
