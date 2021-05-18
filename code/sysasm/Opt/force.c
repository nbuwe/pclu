/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		force				*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

extern OWN_ptr _anyize_own_init;


errcode
force(CLUREF x, CLUREF *ans)
{
    OWNPTR type_owns = CUR_PROC_VAR.proc->type_owns;

    /* if t == any, then return object without change */
    if (type_owns == &_anyize_own_init) {
	ans->cell = x.cell;
	signal(ERR_ok);
    }
    /* if tag != type_owns, then signal wrong_type */
    if (x.cell->tag != (long)type_owns) {
	signal(ERR_wrong_type);
    }

    /* else return value */
    ans->num = x.cell->value;
    signal(ERR_ok);
}
