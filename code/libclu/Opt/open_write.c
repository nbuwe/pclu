
/* This file was automatically generated by pclu. */

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE open_write ****/

extern errcode streamOPopen();
extern errcode file_nameOPparse();
static CLUREF STR_write;
static int open_write_own_init = 0;

errcode
open_write(CLUREF name, CLUREF *ret_1)
{
    errcode err;
    if (open_write_own_init == 0) {
        stringOPcons("write", CLU_1, CLUREF_make_num(5), &STR_write);
        open_write_own_init = 1;
    }
    enter_proc(3);

  LINE(5);
    { /* return */
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    err = file_nameOPparse(name, &T_2_1);
    if (err != ERR_ok)
        goto ex_1;
    err = streamOPopen(T_2_1, STR_write, &T_2_2);
    if (err != ERR_ok)
        goto ex_1;
    ret_1->num = T_2_2.num;
    }
    signal (ERR_ok);
    }
    goto end_1;
  ex_1: /* resignal */
    __CLU_EX_HANDLER;
    if (err == ERR_bad_format)
        signal(err);
    else if (err == ERR_not_possible)
        signal(err);
    else
        goto ex_0;
  end_1:;

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

/**** END PROCEDURE open_write ****/

