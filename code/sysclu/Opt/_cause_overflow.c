
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE _cause_overflow ****/


errcode
_cause_overflow()
{
    errcode err;
    enter_proc(3);

  LINE(4);
    {
    {signal (ERR_overflow);}}
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
}

/**** END PROCEDURE _cause_overflow ****/

