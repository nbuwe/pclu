
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


extern errcode _bytevecOPindexc();
extern errcode _cvt();
extern errcode intOPadd();
extern errcode intOPequal();
extern errcode stringOPsize();
extern errcode stringOPconcat();
extern errcode stringOPsubstr();
extern errcode intOPsub();
extern errcode stringOPrest();

/**** BEGIN PROCEDURE _unquote ****/

errcode _unquote(s, ret_1)
CLUREF s;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    CLUREF i;
    enter_proc(3);

  LINE(4);
    {
        {i.num = 0;
        }
        }

  LINE(5);
    for (;;) {
        if (true != true) { break; }

  LINE(6);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        CLUREF T_2_4;
        T_2_1.ch = '\\';
        T_2_2.num = s.num;
        T_2_3.num = i.num + 1;
         if ((T_2_3.num > 0 && i.num < 0 && 1 < 0) || 
             (T_2_3.num < 0 && i.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = _bytevecOPindexc(T_2_1, T_2_2, T_2_3, &T_2_4);
        if (err != ERR_ok) goto ex_0;
        i.num = T_2_4.num;
        }

  LINE(7);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        CLUREF T_2_4;
        T_2_2.num = (i.num == 0)? true : false;
        T_2_1.num = T_2_2.num;
        if (!T_2_2.num) {
            err = stringOPsize(s, &T_2_3);
            if (err != ERR_ok) goto ex_0;
            T_2_4.num = (i.num == T_2_3.num)? true : false;
            T_2_1.num = T_2_4.num;
        }
        if (T_2_1.num == true) {

  LINE(8);
            {
            {
            ret_1->num = s.num;
            }
            {signal (ERR_ok);}}
            }
            }/* end if */

  LINE(9);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        CLUREF T_2_4;
        CLUREF T_2_5;
        T_2_1.num = i.num - 1;
         if ((T_2_1.num >= 0 && i.num < 0 && (-1) < 0) || 
             (T_2_1.num <= 0 && i.num > 0 && (-1) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = stringOPsubstr(s, CLU_1, T_2_1, &T_2_2);
        if (err != ERR_ok) goto ex_0;
        T_2_3.num = i.num + 1;
         if ((T_2_3.num > 0 && i.num < 0 && 1 < 0) || 
             (T_2_3.num < 0 && i.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = stringOPrest(s, T_2_3, &T_2_4);
        if (err != ERR_ok) goto ex_0;
        err = stringOPconcat(T_2_2, T_2_4, &T_2_5);
        if (err != ERR_ok) goto ex_0;
        s.num = T_2_5.num;
        }
        }
        end_while_1:;
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

/**** END PROCEDURE _unquote ****/

