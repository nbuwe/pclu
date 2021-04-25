
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode _cvt();
extern errcode _bytevecOPindexc();
extern errcode intOPequal();
extern errcode intOPparse();
extern errcode stringOPsubstr();
extern errcode intOPsub();
extern errcode intOPadd();
extern errcode stringOPrest();
extern errcode intOPmod();
extern errcode intOPdiv();
extern errcode intOPmul();

/**** BEGIN PROCEDURE inet_address ****/

errcode
inet_address(CLUREF spec, CLUREF *ret_1, CLUREF *ret_2)
    {
    errcode err;
    errcode ecode2;
    CLUREF bv;
    CLUREF a;
    CLUREF b;
    CLUREF c;
    CLUREF d;
    CLUREF t;
    CLUREF s;
    enter_proc(2);

  LINE(3);
    {

  LINE(4);
        {
            {CLUREF T_3_1;
            T_3_1.num = spec.num;
            bv.num = T_3_1.num;
            }
            }

  LINE(6);
        {
            {CLUREF T_3_1;
            CLUREF T_3_2;
            T_3_1.ch = '.';
            err = _bytevecOPindexc(T_3_1, bv, CLU_1, &T_3_2);
            if (err != ERR_ok) goto ex_1;
            t.num = T_3_2.num;
            }
            }

  LINE(7);
        {
        CLUREF T_3_1;
        T_3_1.num = (t.num == 0)? true : false;
        if (T_3_1.num == true) {

  LINE(8);
            {
                err = ERR_bad_format;
                goto ex_1;
                }
            }
            }/* end if */

  LINE(9);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        CLUREF T_3_3;
        T_3_1.num = t.num - 1;
         if ((T_3_1.num >= 0 && t.num < 0 && (-1) < 0) || 
             (T_3_1.num <= 0 && t.num > 0 && (-1) > 0)) {
            err = ERR_overflow;
            goto ex_1;}
        err = stringOPsubstr(spec, CLU_1, T_3_1, &T_3_2);
        if (err != ERR_ok) goto ex_1;
        err = intOPparse(T_3_2, &T_3_3);
        if (err != ERR_ok) goto ex_1;
        a.num = T_3_3.num;
        }

  LINE(10);
        {
            {CLUREF T_3_1;
            T_3_1.num = t.num + 1;
             if ((T_3_1.num > 0 && t.num < 0 && 1 < 0) || 
                 (T_3_1.num < 0 && t.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            s.num = T_3_1.num;
            }
            }

  LINE(11);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        T_3_1.ch = '.';
        err = _bytevecOPindexc(T_3_1, bv, s, &T_3_2);
        if (err != ERR_ok) goto ex_1;
        t.num = T_3_2.num;
        }

  LINE(12);
        {
        CLUREF T_3_1;
        T_3_1.num = (t.num == 0)? true : false;
        if (T_3_1.num == true) {

  LINE(13);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            err = stringOPrest(spec, s, &T_4_1);
            if (err != ERR_ok) goto ex_1;
            err = intOPparse(T_4_1, &T_4_2);
            if (err != ERR_ok) goto ex_1;
            d.num = T_4_2.num;
            }

  LINE(14);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            CLUREF T_4_4;
            T_4_1.num = 256;
            err = intOPdiv(d, T_4_1, &T_4_2);
            if (err != ERR_ok) goto ex_1;
            T_4_3.num = 256;
            err = intOPmod(T_4_2, T_4_3, &T_4_4);
            if (err != ERR_ok) goto ex_1;
            c.num = T_4_4.num;
            }

  LINE(15);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            CLUREF T_4_4;
            T_4_1.num = 65536;
            err = intOPdiv(d, T_4_1, &T_4_2);
            if (err != ERR_ok) goto ex_1;
            T_4_3.num = 256;
            err = intOPmod(T_4_2, T_4_3, &T_4_4);
            if (err != ERR_ok) goto ex_1;
            b.num = T_4_4.num;
            }

  LINE(16);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            T_4_1.num = 256;
            err = intOPmod(d, T_4_1, &T_4_2);
            if (err != ERR_ok) goto ex_1;
            d.num = T_4_2.num;
            }
            }
        else {

  LINE(17);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            T_4_1.num = t.num - s.num;
             if ((T_4_1.num >= 0 && t.num < 0 && (-s.num) < 0) || 
                 (T_4_1.num <= 0 && t.num > 0 && (-s.num) > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            err = stringOPsubstr(spec, s, T_4_1, &T_4_2);
            if (err != ERR_ok) goto ex_1;
            err = intOPparse(T_4_2, &T_4_3);
            if (err != ERR_ok) goto ex_1;
            b.num = T_4_3.num;
            }

  LINE(18);
            {
            CLUREF T_4_1;
            T_4_1.num = t.num + 1;
             if ((T_4_1.num > 0 && t.num < 0 && 1 < 0) || 
                 (T_4_1.num < 0 && t.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            s.num = T_4_1.num;
            }

  LINE(19);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            T_4_1.ch = '.';
            err = _bytevecOPindexc(T_4_1, bv, s, &T_4_2);
            if (err != ERR_ok) goto ex_1;
            t.num = T_4_2.num;
            }

  LINE(20);
            {
            CLUREF T_4_1;
            T_4_1.num = (t.num == 0)? true : false;
            if (T_4_1.num == true) {

  LINE(21);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                err = stringOPrest(spec, s, &T_5_1);
                if (err != ERR_ok) goto ex_1;
                err = intOPparse(T_5_1, &T_5_2);
                if (err != ERR_ok) goto ex_1;
                d.num = T_5_2.num;
                }

  LINE(22);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                CLUREF T_5_4;
                T_5_1.num = 256;
                err = intOPdiv(d, T_5_1, &T_5_2);
                if (err != ERR_ok) goto ex_1;
                T_5_3.num = 256;
                err = intOPmod(T_5_2, T_5_3, &T_5_4);
                if (err != ERR_ok) goto ex_1;
                c.num = T_5_4.num;
                }

  LINE(23);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                T_5_1.num = 256;
                err = intOPmod(d, T_5_1, &T_5_2);
                if (err != ERR_ok) goto ex_1;
                d.num = T_5_2.num;
                }
                }
            else {

  LINE(24);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                T_5_1.num = t.num - s.num;
                 if ((T_5_1.num >= 0 && t.num < 0 && (-s.num) < 0) || 
                     (T_5_1.num <= 0 && t.num > 0 && (-s.num) > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                err = stringOPsubstr(spec, s, T_5_1, &T_5_2);
                if (err != ERR_ok) goto ex_1;
                err = intOPparse(T_5_2, &T_5_3);
                if (err != ERR_ok) goto ex_1;
                c.num = T_5_3.num;
                }

  LINE(25);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                T_5_1.num = t.num + 1;
                 if ((T_5_1.num > 0 && t.num < 0 && 1 < 0) || 
                     (T_5_1.num < 0 && t.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                err = stringOPrest(spec, T_5_1, &T_5_2);
                if (err != ERR_ok) goto ex_1;
                err = intOPparse(T_5_2, &T_5_3);
                if (err != ERR_ok) goto ex_1;
                d.num = T_5_3.num;
                }
                }}/* end if */
            }}/* end if */

  LINE(28);
        {
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        CLUREF T_3_3;
        T_3_1.num = 256;
        err = intOPmul(d, T_3_1, &T_3_2);
        if (err != ERR_ok) goto ex_1;
        T_3_3.num = c.num + T_3_2.num;
         if ((T_3_3.num > 0 && c.num < 0 && T_3_2.num < 0) || 
             (T_3_3.num < 0 && c.num > 0 && T_3_2.num > 0)) {
            err = ERR_overflow;
            goto ex_1;}
        ret_1->num = T_3_3.num;
        }
        {
        CLUREF T_3_4;
        CLUREF T_3_5;
        CLUREF T_3_6;
        T_3_4.num = 256;
        err = intOPmul(b, T_3_4, &T_3_5);
        if (err != ERR_ok) goto ex_1;
        T_3_6.num = a.num + T_3_5.num;
         if ((T_3_6.num > 0 && a.num < 0 && T_3_5.num < 0) || 
             (T_3_6.num < 0 && a.num > 0 && T_3_5.num > 0)) {
            err = ERR_overflow;
            goto ex_1;}
        ret_2->num = T_3_6.num;
        }
        {signal (ERR_ok);}}
        }
        goto end_1;
        ex_1:
            if ((err == ERR_overflow)
             || (err == ERR_bad_format)) {
            }
            else {
                goto ex_0;
            }
        end_1:;

  LINE(30);
    {
    {signal (ERR_bad_format);}}
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

/**** END PROCEDURE inet_address ****/

