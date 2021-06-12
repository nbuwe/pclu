/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		_anyize				*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#ifdef LINUX
#include <gc/gc_mark.h>
#else
extern char *heapstart, *heaplim;
#endif

extern OWN_ptr _anyize_own_init;


errcode
_anyize(CLUREF x, CLUREF *ans)
{
    CLUREF temp = CLU_0;  /* XXX: -Wmaybe-uninitialized is confused */
    errcode err;

    /* if already an any, do nothing */
    OWNPTR type_owns = CUR_PROC_VAR.proc->type_owns;
    if (type_owns == &_anyize_own_init) {
	ans->cell = x.cell;
	signal(ERR_ok);
    }

    /* test not correct for versions of gc using the stack */
#ifdef LINUX
    const char * const heapstart = GC_least_plausible_heap_addr;
    const char * const heaplim = GC_greatest_plausible_heap_addr;
#endif
    if (x.ref > heapstart && x.ref < heaplim
	&& x.cell->typ.val == CT_VAR
	&& x.cell->tag > 100)
    {
	ans->num = temp.num;
	signal(ERR_ok);
    }

    /*
     * wrap into an oneof with the object's type info as the tag and
     * the object as the value
     */
    CLUREF tag = { .ref = (char *)type_owns };
    err = oneofOPnew(tag, x, &temp);
    if (err != ERR_ok)
	resignal(err);

    ans->num = temp.num;
    signal(ERR_ok);
}



OWN_ptr _anyize_own_init = { .init_flag = 0 };

/* aliases struct OPS */
typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
//  struct OP_ENTRY entry[0];
} _anyize_OPS;

_anyize_OPS _anyize_ops_actual = {
    0,
    &_anyize_own_init,
    &_anyize_own_init
};

_anyize_OPS *_anyize_ops = &_anyize_ops_actual;
_anyize_OPS *any_ops = &_anyize_ops_actual;



const OWN_req _anyize_ownreqs = { 2 * UNIT, 1 };

typedef struct {
    long count;
    struct REQ_ENTRY entry[7];
} _anyize_of_t_REQS;

_anyize_of_t_REQS _anyize_of_t_reqs_actual = { 0 };
_anyize_of_t_REQS *_anyize_of_t_reqs = &_anyize_of_t_reqs_actual;
