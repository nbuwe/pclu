
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE _int_range ****/


errcode
_int_range(CLUREF *ret_1, CLUREF *ret_2)
{
    errcode err;
    enter_proc(2);

  LINE(5);
    {
    {
    ret_1->num = -1073741824;
    }
    {
    ret_2->num = 1073741823;
    }
    {signal (ERR_ok);}}

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

/**** END PROCEDURE _int_range ****/

