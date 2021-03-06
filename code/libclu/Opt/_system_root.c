
/* This file was automatically generated by pclu. */

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE _system_root ****/

extern errcode _home_dir();
static CLUREF STR_CLU;
static int _system_root_own_init = 0;

errcode
_system_root(CLUREF *ret_1)
{
    errcode err;
    if (_system_root_own_init == 0) {
        stringOPcons("CLU", CLU_1, CLUREF_make_num(3), &STR_CLU);
        _system_root_own_init = 1;
    }
    enter_proc(2);

  LINE(3);
    { /* return */
    {
    CLUREF T_1_1;
    err = _home_dir(STR_CLU, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    ret_1->num = T_1_1.num;
    }
    signal (ERR_ok);
    }

    goto end_0;
  ex_0:
    __CLU_EX_HANDLER;
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE _system_root ****/

