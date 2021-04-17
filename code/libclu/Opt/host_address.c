
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode _host_address();

/**** BEGIN PROCEDURE host_address ****/

errcode host_address(host, ret_1, ret_2)
CLUREF host;
CLUREF *ret_1;
CLUREF *ret_2;
    {
    errcode err;
    errcode ecode2;
    CLUREF l;
    CLUREF r;
    enter_proc(3);

  LINE(5);
    {
        {CLUREF T_2_1;
        CLUREF T_2_2;
        err = _host_address(host, &T_2_1, &T_2_2);
        if (err != ERR_ok) goto ex_1;
        l.num = T_2_1.num;
        r.num = T_2_2.num;
        }
        }
    goto end_1;
    ex_1:
        if (err == ERR_not_found) {signal(ERR_not_found);}
        else if (err == ERR_bad_address) {signal(ERR_bad_address);}
        else {
            goto ex_0;}
    end_1:;

  LINE(7);
    {
    {
    ret_1->num = l.num;
    }
    {
    ret_2->num = r.num;
    }
    {signal (ERR_ok);}}
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

/**** END PROCEDURE host_address ****/

