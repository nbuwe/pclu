
/* This file was automatically generated by pclu. */

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE _dir_ent_size ****/


errcode
_dir_ent_size(CLUREF *ret_1)
{
    errcode err;
    enter_proc(3);

  LINE(4);
    { /* return */
    {
    ret_1->num = 255;
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

/**** END PROCEDURE _dir_ent_size ****/

