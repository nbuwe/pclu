
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


extern errcode streamOPopen();
extern errcode file_nameOPparse();
CLUREF STR_append;
static int open_append_own_init = 0;

/**** BEGIN PROCEDURE open_append ****/

errcode open_append(name, ret_1)
CLUREF name;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
        if (open_append_own_init == 0) {
        stringOPcons("append", CLU_1, CLU_6, &STR_append);
        open_append_own_init = 1;
    }
    enter_proc(3);

  LINE(5);
    {
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    err = file_nameOPparse(name, &T_2_1);
    if (err != ERR_ok) goto ex_1;
    err = streamOPopen(T_2_1, STR_append, &T_2_2);
    if (err != ERR_ok) goto ex_1;
    ret_1->num = T_2_2.num;
    }
    {signal (ERR_ok);}}
    goto end_1;
    ex_1:
        if (err == ERR_bad_format) {signal(ERR_bad_format);}
        else if (err == ERR_not_possible) {signal(ERR_not_possible);}
        else {
            goto ex_0;}
    end_1:;
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: elist[0].str = no_return_values_STRING;
        {signal(ERR_failure);}
    }

/**** END PROCEDURE open_append ****/

