
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode intOPle();
extern errcode intOPge();
extern errcode intOPdiv();
extern errcode boolOPnot();
extern errcode intOPequal();
extern errcode intOPsub();
extern errcode intOPadd();
extern errcode intOPmul();

/**** BEGIN PROCEDURE isqrt ****/

errcode isqrt(i, ret_1)
CLUREF i;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    CLUREF a;
    CLUREF b;
    enter_proc(2);

  LINE(3);
    {
    CLUREF T_1_1;
    T_1_1.num = (i.num <= 1)? true : false;
    if (T_1_1.num == true) {

  LINE(4);
        {
        CLUREF T_2_1;
        T_2_1.num = (i.num >= 0)? true : false;
        if (T_2_1.num == true) {

  LINE(5);
            {
            {
            ret_1->num = i.num;
            }
            {signal (ERR_ok);}}
            }
            }/* end if */

  LINE(6);
        {
        {signal (ERR_complex_result);}}
        }
        }/* end if */

  LINE(8);
    {
        {a.num = 1;
        }
        }

  LINE(9);
    {
        {CLUREF T_1_1;
        err = intOPdiv(i, CLU_2, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        b.num = T_1_1.num;
        }
        }

  LINE(10);
    for (;;) {
        CLUREF T_1_1;
        CLUREF T_1_2;
        CLUREF T_1_3;
        CLUREF T_1_4;
        CLUREF T_1_5;
        CLUREF T_1_6;
        T_1_2.num = (a.num == b.num)? true : false;
        T_1_3.num = T_1_2.num ^ 1;
        T_1_1.num = T_1_3.num;
        if (T_1_3.num) {
            T_1_4.num = b.num - a.num;
             if ((T_1_4.num >= 0 && b.num < 0 && (-a.num) < 0) || 
                 (T_1_4.num <= 0 && b.num > 0 && (-a.num) > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            T_1_5.num = (T_1_4.num == 1)? true : false;
            T_1_6.num = T_1_5.num ^ 1;
            T_1_1.num = T_1_6.num;
        }
        if (T_1_1.num != true) { break; }

  LINE(11);
        {
        a.num = b.num;
        }

  LINE(12);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        err = intOPdiv(i, a, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        T_2_2.num = a.num + T_2_1.num;
         if ((T_2_2.num > 0 && a.num < 0 && T_2_1.num < 0) || 
             (T_2_2.num < 0 && a.num > 0 && T_2_1.num > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = intOPdiv(T_2_2, CLU_2, &T_2_3);
        if (err != ERR_ok) goto ex_0;
        b.num = T_2_3.num;
        }
        }
        end_while_1:;

  LINE(14);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    T_1_2.num = (a.num == b.num)? true : false;
    T_1_3.num = T_1_2.num ^ 1;
    T_1_1.num = T_1_3.num;
    if (T_1_3.num) {
        err = intOPmul(b, b, &T_1_4);
        if (err != ERR_ok) goto ex_0;
        T_1_5.num = (T_1_4.num <= i.num)? true : false;
        T_1_1.num = T_1_5.num;
    }
    if (T_1_1.num == true) {

  LINE(15);
        {
        a.num = b.num;
        }
        }
        }/* end if */

  LINE(16);
    {
    {
    ret_1->num = a.num;
    }
    {signal (ERR_ok);}}
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: elist[0] = no_return_values_STRING;
        {signal(ERR_failure);}
    }

/**** END PROCEDURE isqrt ****/

