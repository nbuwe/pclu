
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode stringOPindexs();
extern errcode intOPequal();
extern errcode intOPadd();
extern errcode intOPgt();
extern errcode stringOPfetch();
extern errcode charOPlt();
extern errcode charOPgt();
extern errcode boolOPnot();
extern errcode charOPequal();
extern errcode intOPsub();
extern errcode intOPmul();
extern errcode charOPc2i();
extern errcode intOPmax();
extern errcode intOPdiv();
extern errcode _termcap_decode();
extern errcode stringOPac2s();
extern errcode arrayOPfill();
extern errcode stringOPappend();
extern errcode stringOPconcat();
CLUREF STR_;
CLUREF STR__072pc_075;
static int _termcap_own_init = 0;

/**** BEGIN PROCEDURE _termcap ****/

errcode _termcap(term, cap, repeat, baud, ret_1)
CLUREF term;
CLUREF cap;
CLUREF repeat;
CLUREF baud;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    CLUREF i;
    CLUREF c;
    CLUREF pad;
    CLUREF cnt;
    CLUREF scale;
    CLUREF s;
        if (_termcap_own_init == 0) {
        stringOPcons("", CLU_1, CLU_0, &STR_);
        stringOPcons(":pc=", CLU_1, CLU_4, &STR__072pc_075);
        _termcap_own_init = 1;
    }
    enter_proc(6);

  LINE(8);
    {
        {CLUREF T_1_1;
        err = stringOPindexs(cap, term, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        i.num = T_1_1.num;
        }
        }

  LINE(9);
    {
    CLUREF T_1_1;
    T_1_1.num = (i.num == 0)? true : false;
    if (T_1_1.num == true) {

  LINE(10);
        {
        {signal (ERR_not_found);}}
        }
        }/* end if */

  LINE(11);
    {
    CLUREF T_1_1;
    T_1_1.num = i.num + 4;
     if ((T_1_1.num > 0 && i.num < 0 && 4 < 0) || 
         (T_1_1.num < 0 && i.num > 0 && 4 > 0)) {
        err = ERR_overflow;
        goto ex_0;}
    i.num = T_1_1.num;
    }

  LINE(13);
    {
        {pad = STR_;
        }
        }

  LINE(14);
    {
    CLUREF T_2_1;
    T_2_1.num = (repeat.num > 0)? true : false;
    if (T_2_1.num == true) {

  LINE(15);
        {
        CLUREF T_3_1;
        err = stringOPfetch(term, i, &T_3_1);
        if (err != ERR_ok) goto ex_1;
        c.num = T_3_1.num;
        }

  LINE(16);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        CLUREF T_3_3;
        CLUREF T_3_4;
        CLUREF T_3_5;
        T_3_2.ch = '0';
        err = charOPlt(c, T_3_2, &T_3_3);
        if (err != ERR_ok) goto ex_1;
        T_3_1.num = T_3_3.num;
        if (!T_3_3.num) {
            T_3_4.ch = '9';
            err = charOPgt(c, T_3_4, &T_3_5);
            if (err != ERR_ok) goto ex_1;
            T_3_1.num = T_3_5.num;
        }
        if (T_3_1.num == true) {

  LINE(17);
            {
                err = ERR_bounds;
                goto ex_1;
                }
            }
            }/* end if */

  LINE(18);
        {
            {cnt.num = 0;
            }
            }

  LINE(19);
        {
            {scale.num = 0;
            }
            }

  LINE(20);
        for (;;) {
            if (true != true) { break; }

  LINE(21);
            {
            CLUREF T_4_1;
            T_4_1.num = i.num + 1;
             if ((T_4_1.num > 0 && i.num < 0 && 1 < 0) || 
                 (T_4_1.num < 0 && i.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            i.num = T_4_1.num;
            }

  LINE(22);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            CLUREF T_4_4;
            CLUREF T_4_5;
            T_4_2.ch = '0';
            err = charOPlt(c, T_4_2, &T_4_3);
            if (err != ERR_ok) goto ex_1;
            T_4_1.num = T_4_3.num;
            if (!T_4_3.num) {
                T_4_4.ch = '9';
                err = charOPgt(c, T_4_4, &T_4_5);
                if (err != ERR_ok) goto ex_1;
                T_4_1.num = T_4_5.num;
            }
            if (T_4_1.num == true) {

  LINE(23);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                T_5_1.ch = '.';
                T_5_2.num = (c.ch == T_5_1.ch)? true : false;
                T_5_3.num = T_5_2.num ^ 1;
                if (T_5_3.num == true) {

  LINE(24);
                    goto end_while_1;
                    }
                    }/* end if */

  LINE(25);
                {
                scale.num = 1;
                }
                }
                }/* end if */

  LINE(27);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            CLUREF T_4_4;
            err = intOPmul(cnt, CLU_10, &T_4_1);
            if (err != ERR_ok) goto ex_1;
            T_4_2.num = (long)(c.ch & 0xff);
            T_4_3.num = T_4_1.num + T_4_2.num;
             if ((T_4_3.num > 0 && T_4_1.num < 0 && T_4_2.num < 0) || 
                 (T_4_3.num < 0 && T_4_1.num > 0 && T_4_2.num > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            T_4_4.num = T_4_3.num - 48;
             if ((T_4_4.num >= 0 && T_4_3.num < 0 && (-48) < 0) || 
                 (T_4_4.num <= 0 && T_4_3.num > 0 && (-48) > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            cnt.num = T_4_4.num;
            }

  LINE(28);
            {
            CLUREF T_4_1;
            T_4_1.num = (scale.num > 0)? true : false;
            if (T_4_1.num == true) {

  LINE(29);
                {
                CLUREF T_5_1;
                err = intOPmul(scale, CLU_10, &T_5_1);
                if (err != ERR_ok) goto ex_1;
                scale.num = T_5_1.num;
                }
                }
                }/* end if */

  LINE(30);
            {
            CLUREF T_4_1;
            err = stringOPfetch(term, i, &T_4_1);
            if (err != ERR_ok) goto ex_1;
            c.num = T_4_1.num;
            }
            }
            end_while_1:;

  LINE(32);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        T_3_1.ch = '*';
        T_3_2.num = (c.ch == T_3_1.ch)? true : false;
        if (T_3_2.num == true) {

  LINE(33);
            {
            CLUREF T_4_1;
            err = intOPmul(cnt, repeat, &T_4_1);
            if (err != ERR_ok) goto ex_1;
            cnt.num = T_4_1.num;
            }
            }
        else {

  LINE(34);
            {
            CLUREF T_4_1;
            T_4_1.num = i.num - 1;
             if ((T_4_1.num >= 0 && i.num < 0 && (-1) < 0) || 
                 (T_4_1.num <= 0 && i.num > 0 && (-1) > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            i.num = T_4_1.num;
            }
            }}/* end if */

  LINE(36);
        {
        CLUREF T_3_1;
        T_3_1.num = (baud.num > 0)? true : false;
        if (T_3_1.num == true) {

  LINE(37);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            T_4_1.num = 9600;
            err = intOPmax(scale, CLU_1, &T_4_2);
            if (err != ERR_ok) goto ex_1;
            err = intOPmul(T_4_1, T_4_2, &T_4_3);
            if (err != ERR_ok) goto ex_1;
            scale.num = T_4_3.num;
            }

  LINE(38);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            CLUREF T_4_4;
            err = intOPmul(cnt, baud, &T_4_1);
            if (err != ERR_ok) goto ex_1;
            err = intOPdiv(scale, CLU_2, &T_4_2);
            if (err != ERR_ok) goto ex_1;
            T_4_3.num = T_4_1.num + T_4_2.num;
             if ((T_4_3.num > 0 && T_4_1.num < 0 && T_4_2.num < 0) || 
                 (T_4_3.num < 0 && T_4_1.num > 0 && T_4_2.num > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            err = intOPdiv(T_4_3, scale, &T_4_4);
            if (err != ERR_ok) goto ex_1;
            scale.num = T_4_4.num;
            }

  LINE(39);
            {
            CLUREF T_4_1;
            T_4_1.num = (scale.num > 0)? true : false;
            if (T_4_1.num == true) {

  LINE(40);
                {
                CLUREF T_5_1;
                T_5_1.ch = '\000';
                c.num = T_5_1.num;
                }

  LINE(41);
                {
                CLUREF T_5_1;
                err = stringOPindexs(STR__072pc_075, term, &T_5_1);
                if (err != ERR_ok) goto ex_1;
                cnt.num = T_5_1.num;
                }

  LINE(42);
                {
                CLUREF T_5_1;
                T_5_1.num = (cnt.num > 0)? true : false;
                if (T_5_1.num == true) {

  LINE(43);
                    {
                    CLUREF T_6_1;
                    CLUREF T_6_2;
                    CLUREF T_6_3;
                    T_6_1.num = cnt.num + 4;
                     if ((T_6_1.num > 0 && cnt.num < 0 && 4 < 0) || 
                         (T_6_1.num < 0 && cnt.num > 0 && 4 > 0)) {
                        err = ERR_overflow;
                        goto ex_1;}
                    err = _termcap_decode(term, T_6_1, &T_6_2, &T_6_3);
                    if (err != ERR_ok) goto ex_1;
                    cnt.num = T_6_2.num;
                    c.num = T_6_3.num;
                    }
                    }
                    }/* end if */

  LINE(46);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                err = arrayOPfill(CLU_1, scale, c, &T_5_1);
                if (err != ERR_ok) goto ex_1;
                err = stringOPac2s(T_5_1, &T_5_2);
                if (err != ERR_ok) goto ex_1;
                pad.num = T_5_2.num;
                }
                }
                }/* end if */
            }
            }/* end if */
        }
        }/* end if */
        goto end_1;
        ex_1:
            if ((err == ERR_bounds)) {
            }
            else {
                goto ex_0;
            }
        end_1:;

  LINE(51);
    {
        {s = STR_;
        }
        }

  LINE(52);
    for (;;) {
        if (true != true) { break; }

  LINE(53);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        err = _termcap_decode(term, i, &T_3_1, &T_3_2);
        if (err != ERR_ok) goto ex_2;
        i.num = T_3_1.num;
        c.num = T_3_2.num;
        }

  LINE(54);
        {
        CLUREF T_3_1;
        err = stringOPappend(s, c, &T_3_1);
        if (err != ERR_ok) goto ex_2;
        s.num = T_3_1.num;
        }
        }
        end_while_2:;
        goto end_2;
        ex_2:
            if ((err == ERR_bounds)) {
            }
            else {
                goto ex_0;
            }
        end_2:;

  LINE(56);
    {
    {
    CLUREF T_1_1;
    err = stringOPconcat(s, pad, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_1.num;
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

/**** END PROCEDURE _termcap ****/


extern errcode charOPge();
extern errcode charOPle();
extern errcode charOPi2c();
extern errcode intOPmod();
extern errcode stringOPindexc();
CLUREF STR_Enrtbf;
CLUREF STR__033_012_015_011_010_013;
static int _termcap_decode_own_init = 0;

/**** BEGIN PROCEDURE _termcap_decode ****/

errcode _termcap_decode(term, i, ret_1, ret_2)
CLUREF term;
CLUREF i;
CLUREF *ret_1;
CLUREF *ret_2;
    {
    errcode err;
    errcode ecode2;
    CLUREF c;
    CLUREF j;
        if (_termcap_decode_own_init == 0) {
        stringOPcons("Enrtbf", CLU_1, CLU_6, &STR_Enrtbf);
        stringOPcons("\033\n\r\t\b\v", CLU_1, CLU_6, &STR__033_012_015_011_010_013);
        _termcap_decode_own_init = 1;
    }
    enter_proc(59);

  LINE(61);
    {
        {CLUREF T_2_1;
        err = stringOPfetch(term, i, &T_2_1);
        if (err != ERR_ok) goto ex_1;
        c.num = T_2_1.num;
        }
        }
    goto end_1;
    ex_1:
        if (err == ERR_bounds) {signal(ERR_bounds);}
        else {
            goto ex_0;}
    end_1:;

  LINE(63);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.ch = ':';
    T_1_2.num = (c.ch == T_1_1.ch)? true : false;
    if (T_1_2.num == true) {

  LINE(64);
        {
        {signal (ERR_bounds);}}
        }
        }/* end if */

  LINE(65);
    {
    CLUREF T_1_1;
    T_1_1.num = i.num + 1;
     if ((T_1_1.num > 0 && i.num < 0 && 1 < 0) || 
         (T_1_1.num < 0 && i.num > 0 && 1 > 0)) {
        err = ERR_overflow;
        goto ex_0;}
    i.num = T_1_1.num;
    }

  LINE(66);
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    T_2_1.ch = '\\';
    T_2_2.num = (c.ch == T_2_1.ch)? true : false;
    if (T_2_2.num == true) {

  LINE(67);
        {
        CLUREF T_3_1;
        err = stringOPfetch(term, i, &T_3_1);
        if (err != ERR_ok) goto ex_2;
        c.num = T_3_1.num;
        }

  LINE(68);
        {
        CLUREF T_3_1;
        T_3_1.num = i.num + 1;
         if ((T_3_1.num > 0 && i.num < 0 && 1 < 0) || 
             (T_3_1.num < 0 && i.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_2;}
        i.num = T_3_1.num;
        }

  LINE(69);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        CLUREF T_3_3;
        CLUREF T_3_4;
        CLUREF T_3_5;
        T_3_2.ch = '0';
        err = charOPge(c, T_3_2, &T_3_3);
        if (err != ERR_ok) goto ex_2;
        T_3_1.num = T_3_3.num;
        if (T_3_3.num) {
            T_3_4.ch = '7';
            err = charOPle(c, T_3_4, &T_3_5);
            if (err != ERR_ok) goto ex_2;
            T_3_1.num = T_3_5.num;
        }
        if (T_3_1.num == true) {

  LINE(70);
            {
            CLUREF T_5_1;
            CLUREF T_5_2;
            CLUREF T_5_3;
            CLUREF T_5_4;
            CLUREF T_5_5;
            CLUREF T_5_6;
            CLUREF T_5_7;
            CLUREF T_5_8;
            CLUREF T_5_9;
            CLUREF T_5_10;
            CLUREF T_5_11;
            CLUREF T_5_12;
            CLUREF T_5_13;
            CLUREF T_5_14;
            CLUREF T_5_15;
            CLUREF T_5_16;
            T_5_1.num = (long)(c.ch & 0xff);
            T_5_2.num = T_5_1.num - 48;
             if ((T_5_2.num >= 0 && T_5_1.num < 0 && (-48) < 0) || 
                 (T_5_2.num <= 0 && T_5_1.num > 0 && (-48) > 0)) {
                err = ERR_overflow;
                goto ex_3;}
            err = intOPmod(T_5_2, CLU_4, &T_5_3);
            if (err != ERR_ok) goto ex_3;
            T_5_4.num = 64;
            err = intOPmul(T_5_3, T_5_4, &T_5_5);
            if (err != ERR_ok) goto ex_3;
            err = stringOPfetch(term, i, &T_5_6);
            if (err != ERR_ok) goto ex_3;
            T_5_7.num = (long)(T_5_6.ch & 0xff);
            T_5_8.num = T_5_7.num - 48;
             if ((T_5_8.num >= 0 && T_5_7.num < 0 && (-48) < 0) || 
                 (T_5_8.num <= 0 && T_5_7.num > 0 && (-48) > 0)) {
                err = ERR_overflow;
                goto ex_3;}
            err = intOPmul(T_5_8, CLU_8, &T_5_9);
            if (err != ERR_ok) goto ex_3;
            T_5_10.num = T_5_5.num + T_5_9.num;
             if ((T_5_10.num > 0 && T_5_5.num < 0 && T_5_9.num < 0) || 
                 (T_5_10.num < 0 && T_5_5.num > 0 && T_5_9.num > 0)) {
                err = ERR_overflow;
                goto ex_3;}
            T_5_11.num = i.num + 1;
             if ((T_5_11.num > 0 && i.num < 0 && 1 < 0) || 
                 (T_5_11.num < 0 && i.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_3;}
            err = stringOPfetch(term, T_5_11, &T_5_12);
            if (err != ERR_ok) goto ex_3;
            T_5_13.num = (long)(T_5_12.ch & 0xff);
            T_5_14.num = T_5_10.num + T_5_13.num;
             if ((T_5_14.num > 0 && T_5_10.num < 0 && T_5_13.num < 0) || 
                 (T_5_14.num < 0 && T_5_10.num > 0 && T_5_13.num > 0)) {
                err = ERR_overflow;
                goto ex_3;}
            T_5_15.num = T_5_14.num - 48;
             if ((T_5_15.num >= 0 && T_5_14.num < 0 && (-48) < 0) || 
                 (T_5_15.num <= 0 && T_5_14.num > 0 && (-48) > 0)) {
                err = ERR_overflow;
                goto ex_3;}
            err = charOPi2c(T_5_15, &T_5_16);
            if (err != ERR_ok) goto ex_3;
            c.num = T_5_16.num;
            }
                goto end_3;
                ex_3:
                    if ((err == ERR_illegal_char)) {
                    }
                    else {
                        goto ex_2;
                    }
                end_3:;

  LINE(74);
            {
            CLUREF T_4_1;
            T_4_1.num = i.num + 2;
             if ((T_4_1.num > 0 && i.num < 0 && 2 < 0) || 
                 (T_4_1.num < 0 && i.num > 0 && 2 > 0)) {
                err = ERR_overflow;
                goto ex_2;}
            i.num = T_4_1.num;
            }
            }
        else {

  LINE(75);
            {
                {CLUREF T_4_1;
                err = stringOPindexc(c, STR_Enrtbf, &T_4_1);
                if (err != ERR_ok) goto ex_2;
                j.num = T_4_1.num;
                }
                }

  LINE(76);
            {
            CLUREF T_4_1;
            T_4_1.num = (j.num > 0)? true : false;
            if (T_4_1.num == true) {

  LINE(77);
                {
                CLUREF T_5_1;
                err = stringOPfetch(STR__033_012_015_011_010_013, j, &T_5_1);
                if (err != ERR_ok) goto ex_2;
                c.num = T_5_1.num;
                }
                }
                }/* end if */
            }}/* end if */
        }
    else {
    CLUREF T_2_3;
    CLUREF T_2_4;
    T_2_3.ch = '^';
    T_2_4.num = (c.ch == T_2_3.ch)? true : false;
    if (T_2_4.num == true) {

  LINE(80);
        {
        CLUREF T_3_1;
        err = stringOPfetch(term, i, &T_3_1);
        if (err != ERR_ok) goto ex_2;
        c.num = T_3_1.num;
        }

  LINE(81);
        {
        CLUREF T_3_1;
        T_3_1.num = i.num + 1;
         if ((T_3_1.num > 0 && i.num < 0 && 1 < 0) || 
             (T_3_1.num < 0 && i.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_2;}
        i.num = T_3_1.num;
        }

  LINE(82);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        CLUREF T_3_3;
        CLUREF T_3_4;
        CLUREF T_3_5;
        T_3_2.ch = '@';
        err = charOPge(c, T_3_2, &T_3_3);
        if (err != ERR_ok) goto ex_2;
        T_3_1.num = T_3_3.num;
        if (T_3_3.num) {
            T_3_4.ch = '_';
            err = charOPle(c, T_3_4, &T_3_5);
            if (err != ERR_ok) goto ex_2;
            T_3_1.num = T_3_5.num;
        }
        if (T_3_1.num == true) {

  LINE(83);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            CLUREF T_4_4;
            T_4_1.num = (long)(c.ch & 0xff);
            T_4_2.num = 64;
            T_4_3.num = T_4_1.num - T_4_2.num;
             if ((T_4_3.num >= 0 && T_4_1.num < 0 && (-T_4_2.num) < 0) || 
                 (T_4_3.num <= 0 && T_4_1.num > 0 && (-T_4_2.num) > 0)) {
                err = ERR_overflow;
                goto ex_2;}
            err = charOPi2c(T_4_3, &T_4_4);
            if (err != ERR_ok) goto ex_2;
            c.num = T_4_4.num;
            }
            }
        else {
        CLUREF T_3_6;
        CLUREF T_3_7;
        CLUREF T_3_8;
        CLUREF T_3_9;
        CLUREF T_3_10;
        T_3_7.ch = 'a';
        err = charOPge(c, T_3_7, &T_3_8);
        if (err != ERR_ok) goto ex_2;
        T_3_6.num = T_3_8.num;
        if (T_3_8.num) {
            T_3_9.ch = 'z';
            err = charOPle(c, T_3_9, &T_3_10);
            if (err != ERR_ok) goto ex_2;
            T_3_6.num = T_3_10.num;
        }
        if (T_3_6.num == true) {

  LINE(85);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            CLUREF T_4_4;
            T_4_1.num = (long)(c.ch & 0xff);
            T_4_2.num = 96;
            T_4_3.num = T_4_1.num - T_4_2.num;
             if ((T_4_3.num >= 0 && T_4_1.num < 0 && (-T_4_2.num) < 0) || 
                 (T_4_3.num <= 0 && T_4_1.num > 0 && (-T_4_2.num) > 0)) {
                err = ERR_overflow;
                goto ex_2;}
            err = charOPi2c(T_4_3, &T_4_4);
            if (err != ERR_ok) goto ex_2;
            c.num = T_4_4.num;
            }
            }
        else {
        CLUREF T_3_11;
        CLUREF T_3_12;
        T_3_11.ch = '?';
        T_3_12.num = (c.ch == T_3_11.ch)? true : false;
        if (T_3_12.num == true) {

  LINE(87);
            {
            CLUREF T_4_1;
            T_4_1.ch = '\177';
            c.num = T_4_1.num;
            }
            }
            }}}/* end if */
        }
        }}/* end if */
    goto end_2;
    ex_2:
        if (err == ERR_bounds) {signal(ERR_bounds);}
        else {
            goto ex_0;}
    end_2:;

  LINE(89);
    {
    {
    ret_1->num = i.num;
    }
    {
    ret_2->num = c.num;
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

/**** END PROCEDURE _termcap_decode ****/

