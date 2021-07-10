
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE _cleanup_ ****/

extern errcode streamOP_close_all();
extern errcode _gprofOPcontrol();
extern errcode _gprofOPdump();
static CLUREF STR_gmon_056out;
static int _cleanup__own_init = 0;

errcode
_cleanup_()
{
    errcode err;
    if (_cleanup__own_init == 0) {
        stringOPcons("gmon.out", CLU_1, CLUREF_make_num(8), &STR_gmon_056out);
        _cleanup__own_init = 1;
    }
    enter_proc(3);

  LINE(4);
    {
    err = streamOP_close_all();
    if (err != ERR_ok) goto ex_0;
    }

  LINE(5);
    {
    err = _gprofOPcontrol(CLU_0);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(6);
    {
    err = _gprofOPdump(STR_gmon_056out);
    if (err != ERR_ok) goto ex_0;
    }

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    signal(ERR_ok);
}

/**** END PROCEDURE _cleanup_ ****/

