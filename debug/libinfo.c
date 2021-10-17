/*	debugging information so that system functions */
/*		can be invoked			       */

#include "pclu_err.h"
#include "pclu_sys.h"

/*
 * XXX: debug_c.c defines this as "frame" but slightly differently.
 */
typedef struct {
    long hdr;
    long count;
    const char *name;
    const char *fname;
    bool is_iter;
    long is_parmd;
    errcode (*addr)();
    long nargs;
    const Vlist0 *vals;
    const siglist0 *sigs;
    const Vlist0 *locals;
    const Vlist0 *owns;
    const Vlist0 *ptowns;
    const Vlist0 *popowns;
    const Slist0 *type_formals;
    const Slist0 *op_formals;
} dbg_info_generic;

#include "libinfo.h"
