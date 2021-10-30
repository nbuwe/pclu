
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE _fixup_file_name ****/

extern errcode file_nameOPget_dir();
extern errcode _dir_ent_size();
extern errcode boolOPnot();
extern errcode stringOPempty();
extern errcode charOPequal();
extern errcode stringOPfetch();
extern errcode stringOPconcat();
extern errcode connected_dir();
extern errcode _bytevecOPindexc();
extern errcode _cvt();
extern errcode intOPadd();
extern errcode intOPequal();
extern errcode intOPmin();
extern errcode stringOPsize();
extern errcode intOPgt();
extern errcode intOPsub();
extern errcode stringOPsubstr();
extern errcode stringOPrest();
extern errcode intOPle();
extern errcode file_nameOPget_name();
extern errcode stringOPequal();
extern errcode file_nameOPparse();
extern errcode intOPmax();
extern errcode _last_indexc();
extern errcode file_nameOPget_suffix();
extern errcode file_nameOPget_other();
extern errcode stringOPappend();
extern errcode file_nameOPcreate();
static CLUREF STR__057;
static CLUREF STR__056;
static CLUREF STR__056_056;
static int _fixup_file_name_own_init = 0;

errcode
_fixup_file_name(CLUREF fn, CLUREF dirok, CLUREF *ret_1)
{
    errcode err;
    CLUREF d;
    CLUREF dez;
    CLUREF i;
    CLUREF j;
    CLUREF c;
    CLUREF n;
    CLUREF s;
    CLUREF o;
    if (_fixup_file_name_own_init == 0) {
        stringOPcons("/", CLU_1, CLUREF_make_num(1), &STR__057);
        stringOPcons(".", CLU_1, CLUREF_make_num(1), &STR__056);
        stringOPcons("..", CLU_1, CLUREF_make_num(2), &STR__056_056);
        _fixup_file_name_own_init = 1;
    }
    enter_proc(3);

  LINE(4);
    {
        {CLUREF T_1_1;
        err = file_nameOPget_dir(fn, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        d.num = T_1_1.num;
        }
        }

  LINE(5);
    {
        {CLUREF T_1_1;
        err = _dir_ent_size(&T_1_1);
        if (err != ERR_ok) goto ex_0;
        dez.num = T_1_1.num;
        }
        }

  LINE(7);
    {
    CLUREF T_1_1;
    T_1_1.num = dirok.num ^ 1;
    if (T_1_1.num == true) {

  LINE(8);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        CLUREF T_2_4;
        CLUREF T_2_5;
        CLUREF T_2_6;
        err = stringOPempty(d, &T_2_2);
        if (err != ERR_ok) goto ex_0;
        T_2_1.num = T_2_2.num;
        if (!T_2_2.num) {
            err = stringOPfetch(d, CLU_1, &T_2_3);
            if (err != ERR_ok) goto ex_0;
            T_2_4.ch = '/';
            T_2_5.num = (T_2_3.ch == T_2_4.ch)? true : false;
            T_2_6.num = T_2_5.num ^ 1;
            T_2_1.num = T_2_6.num;
        }
        if (T_2_1.num == true) {

  LINE(9);
            {
            CLUREF T_3_1;
            CLUREF T_3_2;
            err = connected_dir(&T_3_1);
            if (err != ERR_ok) goto ex_0;
            err = stringOPconcat(T_3_1, d, &T_3_2);
            if (err != ERR_ok) goto ex_0;
            d.num = T_3_2.num;
            }
            }
            }/* end if */

  LINE(10);
        {
        i.num = 0;
        }

  LINE(11);
        for (;;) {
            if (true != true) { break; }

  LINE(12);
            {
                {CLUREF T_4_1;
                CLUREF T_4_2;
                CLUREF T_4_3;
                CLUREF T_4_4;
                T_4_1.ch = '/';
                T_4_2.num = (long)d.num;
                T_4_3.num = i.num + 1;
                 if ((T_4_3.num > 0 && i.num < 0 && 1 < 0) ||
                     (T_4_3.num < 0 && i.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                err = _bytevecOPindexc(T_4_1, T_4_2, T_4_3, &T_4_4);
                if (err != ERR_ok) goto ex_1;
                j.num = T_4_4.num;
                }
                }

  LINE(15);
            {
            CLUREF T_4_1;
            T_4_1.num = (j.num == 0)? true : false;
            if (T_4_1.num == true) {

  LINE(16);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                CLUREF T_5_4;
                CLUREF T_5_5;
                err = stringOPsize(d, &T_5_1);
                if (err != ERR_ok) goto ex_1;
                T_5_2.num = T_5_1.num + 1;
                 if ((T_5_2.num > 0 && T_5_1.num < 0 && 1 < 0) ||
                     (T_5_2.num < 0 && T_5_1.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                T_5_3.num = i.num + dez.num;
                 if ((T_5_3.num > 0 && i.num < 0 && dez.num < 0) ||
                     (T_5_3.num < 0 && i.num > 0 && dez.num > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                T_5_4.num = T_5_3.num + 1;
                 if ((T_5_4.num > 0 && T_5_3.num < 0 && 1 < 0) ||
                     (T_5_4.num < 0 && T_5_3.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                err = intOPmin(T_5_2, T_5_4, &T_5_5);
                if (err != ERR_ok) goto ex_1;
                i.num = T_5_5.num;
                }

  LINE(17);
                goto end_while_1;
                }
            else {
            CLUREF T_4_2;
            CLUREF T_4_3;
            CLUREF T_4_4;
            T_4_2.num = j.num - i.num;
             if ((T_4_2.num >= 0 && j.num < 0 && (-i.num) < 0) ||
                 (T_4_2.num <= 0 && j.num > 0 && (-i.num) > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            T_4_3.num = dez.num + 1;
             if ((T_4_3.num > 0 && dez.num < 0 && 1 < 0) ||
                 (T_4_3.num < 0 && dez.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            T_4_4.num = (T_4_2.num > T_4_3.num)? true : false;
            if (T_4_4.num == true) {

  LINE(19);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                CLUREF T_5_4;
                T_5_1.num = i.num + dez.num;
                 if ((T_5_1.num > 0 && i.num < 0 && dez.num < 0) ||
                     (T_5_1.num < 0 && i.num > 0 && dez.num > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                err = stringOPsubstr(d, CLU_1, T_5_1, &T_5_2);
                if (err != ERR_ok) goto ex_1;
                err = stringOPrest(d, j, &T_5_3);
                if (err != ERR_ok) goto ex_1;
                err = stringOPconcat(T_5_2, T_5_3, &T_5_4);
                if (err != ERR_ok) goto ex_1;
                d.num = T_5_4.num;
                }

  LINE(21);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                T_5_1.num = i.num + dez.num;
                 if ((T_5_1.num > 0 && i.num < 0 && dez.num < 0) ||
                     (T_5_1.num < 0 && i.num > 0 && dez.num > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                T_5_2.num = T_5_1.num + 1;
                 if ((T_5_2.num > 0 && T_5_1.num < 0 && 1 < 0) ||
                     (T_5_2.num < 0 && T_5_1.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                j.num = T_5_2.num;
                }
                }
                }}/* end if */

  LINE(23);
            {
            i.num = j.num;
            }

  LINE(24);
            for (;;) {
                if (true != true) { break; }

  LINE(25);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                CLUREF T_5_4;
                CLUREF T_5_5;
                T_5_1.num = i.num + 1;
                 if ((T_5_1.num > 0 && i.num < 0 && 1 < 0) ||
                     (T_5_1.num < 0 && i.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                err = stringOPfetch(d, T_5_1, &T_5_2);
                if (err != ERR_ok) goto ex_1;
                T_5_3.ch = '.';
                T_5_4.num = (T_5_2.ch == T_5_3.ch)? true : false;
                T_5_5.num = T_5_4.num ^ 1;
                if (T_5_5.num == true) {

  LINE(26);
                    goto end_while_2;
                    }
                    }/* end if */

  LINE(27);
                {
                    {CLUREF T_5_1;
                    CLUREF T_5_2;
                    T_5_1.num = i.num + 2;
                     if ((T_5_1.num > 0 && i.num < 0 && 2 < 0) ||
                         (T_5_1.num < 0 && i.num > 0 && 2 > 0)) {
                        err = ERR_overflow;
                        goto ex_1;}
                    err = stringOPfetch(d, T_5_1, &T_5_2);
                    if (err != ERR_ok) goto ex_1;
                    c.num = T_5_2.num;
                    }
                    }

  LINE(28);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                T_5_1.ch = '/';
                T_5_2.num = (c.ch == T_5_1.ch)? true : false;
                if (T_5_2.num == true) {

  LINE(29);
                    {
                    CLUREF T_6_1;
                    CLUREF T_6_2;
                    CLUREF T_6_3;
                    CLUREF T_6_4;
                    err = stringOPsubstr(d, CLU_1, i, &T_6_1);
                    if (err != ERR_ok) goto ex_1;
                    T_6_2.num = i.num + 3;
                     if ((T_6_2.num > 0 && i.num < 0 && 3 < 0) ||
                         (T_6_2.num < 0 && i.num > 0 && 3 > 0)) {
                        err = ERR_overflow;
                        goto ex_1;}
                    err = stringOPrest(d, T_6_2, &T_6_3);
                    if (err != ERR_ok) goto ex_1;
                    err = stringOPconcat(T_6_1, T_6_3, &T_6_4);
                    if (err != ERR_ok) goto ex_1;
                    d.num = T_6_4.num;
                    }

  LINE(31);
                    continue;
                    }
                    }/* end if */

  LINE(33);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                T_5_1.ch = '.';
                T_5_2.num = (c.ch == T_5_1.ch)? true : false;
                T_5_3.num = T_5_2.num ^ 1;
                if (T_5_3.num == true) {

  LINE(34);
                    goto end_while_2;
                    }
                    }/* end if */

  LINE(35);
                {
                CLUREF T_5_1;
                T_5_1.num = i.num + 3;
                 if ((T_5_1.num > 0 && i.num < 0 && 3 < 0) ||
                     (T_5_1.num < 0 && i.num > 0 && 3 > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                j.num = T_5_1.num;
                }

  LINE(36);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                err = stringOPsize(d, &T_5_1);
                if (err != ERR_ok) goto ex_1;
                T_5_2.num = (j.num <= T_5_1.num)? true : false;
                if (T_5_2.num == true) {

  LINE(37);
                    {
                    CLUREF T_6_1;
                    CLUREF T_6_2;
                    CLUREF T_6_3;
                    CLUREF T_6_4;
                    err = stringOPfetch(d, j, &T_6_1);
                    if (err != ERR_ok) goto ex_1;
                    T_6_2.ch = '/';
                    T_6_3.num = (T_6_1.ch == T_6_2.ch)? true : false;
                    T_6_4.num = T_6_3.num ^ 1;
                    if (T_6_4.num == true) {

  LINE(38);
                        goto end_while_2;
                        }
                        }/* end if */

  LINE(39);
                    {
                    CLUREF T_6_1;
                    T_6_1.num = j.num + 1;
                     if ((T_6_1.num > 0 && j.num < 0 && 1 < 0) ||
                         (T_6_1.num < 0 && j.num > 0 && 1 > 0)) {
                        err = ERR_overflow;
                        goto ex_1;}
                    j.num = T_6_1.num;
                    }
                    }
                    }/* end if */

  LINE(41);
                {
                CLUREF T_5_1;
                T_5_1.num = (i.num == 1)? true : false;
                if (T_5_1.num == true) {

  LINE(42);
                    {
                    CLUREF T_6_1;
                    CLUREF T_6_2;
                    err = stringOPrest(d, j, &T_6_1);
                    if (err != ERR_ok) goto ex_1;
                    err = stringOPconcat(STR__057, T_6_1, &T_6_2);
                    if (err != ERR_ok) goto ex_1;
                    d.num = T_6_2.num;
                    }

  LINE(43);
                    continue;
                    }
                    }/* end if */

  LINE(45);
                for (;;) {
                    if (true != true) { break; }

  LINE(46);
                    {
                    CLUREF T_7_1;
                    T_7_1.num = i.num - 1;
                     if ((T_7_1.num >= 0 && i.num < 0 && (-1) < 0) ||
                         (T_7_1.num <= 0 && i.num > 0 && (-1) > 0)) {
                        err = ERR_overflow;
                        goto ex_2;}
                    i.num = T_7_1.num;
                    }

  LINE(47);
                    {
                    CLUREF T_7_1;
                    CLUREF T_7_2;
                    CLUREF T_7_3;
                    err = stringOPfetch(d, i, &T_7_1);
                    if (err != ERR_ok) goto ex_2;
                    T_7_2.ch = '/';
                    T_7_3.num = (T_7_1.ch == T_7_2.ch)? true : false;
                    if (T_7_3.num == true) {

  LINE(48);
                        goto end_while_3;
                        }
                        }/* end if */
                    }
                    end_while_3:
                    __CLU_END_LABEL;
                    goto end_2;
                    ex_2:
                        __CLU_EX_HANDLER;
                        if ((err == ERR_bounds)) {

  LINE(50);
                            {
                            CLUREF T_6_1;
                            err = stringOPrest(d, j, &T_6_1);
                            if (err != ERR_ok) goto ex_1;
                            d.num = T_6_1.num;
                            }

  LINE(51);
                            goto end_while_2;
                        }
                        else {
                            goto ex_1;
                        }
                    end_2:;

  LINE(53);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                err = stringOPsubstr(d, CLU_1, i, &T_5_1);
                if (err != ERR_ok) goto ex_1;
                err = stringOPrest(d, j, &T_5_2);
                if (err != ERR_ok) goto ex_1;
                err = stringOPconcat(T_5_1, T_5_2, &T_5_3);
                if (err != ERR_ok) goto ex_1;
                d.num = T_5_3.num;
                }
                }
                end_while_2:
                __CLU_END_LABEL;
            }
            end_while_1:
            __CLU_END_LABEL;
            goto end_1;
            ex_1:
                __CLU_EX_HANDLER;
                if ((err == ERR_bounds)) {
                }
                else {
                    goto ex_0;
                }
            end_1:;

  LINE(57);
        {
        CLUREF T_2_1;
        T_2_1.num = (i.num == 1)? true : false;
        if (T_2_1.num == true) {

  LINE(58);
            {
            d = STR__057;
            }
            }
        else {
        CLUREF T_2_2;
        T_2_2.num = (i.num > 1)? true : false;
        if (T_2_2.num == true) {

  LINE(60);
            {
            CLUREF T_3_1;
            CLUREF T_3_2;
            T_3_1.num = i.num - 1;
             if ((T_3_1.num >= 0 && i.num < 0 && (-1) < 0) ||
                 (T_3_1.num <= 0 && i.num > 0 && (-1) > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            err = stringOPsubstr(d, CLU_1, T_3_1, &T_3_2);
            if (err != ERR_ok) goto ex_0;
            d.num = T_3_2.num;
            }
            }
            }}/* end if */
        }
        }/* end if */

  LINE(62);
    {
        {CLUREF T_1_1;
        err = file_nameOPget_name(fn, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        n.num = T_1_1.num;
        }
        }

  LINE(63);
    {
    CLUREF T_1_1;
    T_1_1.num = ((n.str->size != STR__056.str->size)? false :
        !(memcmp(n.str->data, STR__056.str->data, n.str->size)));
    if (T_1_1.num == true) {

  LINE(64);
        {
        {
        CLUREF T_2_1;
        err = file_nameOPparse(d, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        ret_1->num = T_2_1.num;
        }
        {signal (ERR_ok);}}
        }
    else {
    CLUREF T_1_2;
    T_1_2.num = ((n.str->size != STR__056_056.str->size)? false :
        !(memcmp(n.str->data, STR__056_056.str->data, n.str->size)));
    if (T_1_2.num == true) {

  LINE(66);
        {
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        CLUREF T_2_4;
        CLUREF T_2_5;
        CLUREF T_2_6;
        T_2_1.ch = '/';
        err = _last_indexc(T_2_1, d, &T_2_2);
        if (err != ERR_ok) goto ex_0;
        T_2_3.num = T_2_2.num - 1;
         if ((T_2_3.num >= 0 && T_2_2.num < 0 && (-1) < 0) ||
             (T_2_3.num <= 0 && T_2_2.num > 0 && (-1) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = intOPmax(T_2_3, CLU_1, &T_2_4);
        if (err != ERR_ok) goto ex_0;
        err = stringOPsubstr(d, CLU_1, T_2_4, &T_2_5);
        if (err != ERR_ok) goto ex_0;
        err = file_nameOPparse(T_2_5, &T_2_6);
        if (err != ERR_ok) goto ex_0;
        ret_1->num = T_2_6.num;
        }
        {signal (ERR_ok);}}
        }
        }}/* end if */

  LINE(72);
    {
        {CLUREF T_1_1;
        err = file_nameOPget_suffix(fn, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        s.num = T_1_1.num;
        }
        }

  LINE(73);
    {
        {CLUREF T_1_1;
        err = file_nameOPget_other(fn, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        o.num = T_1_1.num;
        }
        }

  LINE(74);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    err = stringOPsize(n, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = stringOPsize(s, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    T_1_3.num = T_1_1.num + T_1_2.num;
     if ((T_1_3.num > 0 && T_1_1.num < 0 && T_1_2.num < 0) ||
         (T_1_3.num < 0 && T_1_1.num > 0 && T_1_2.num > 0)) {
        err = ERR_overflow;
        goto ex_0;}
    err = stringOPsize(o, &T_1_4);
    if (err != ERR_ok) goto ex_0;
    T_1_5.num = T_1_3.num + T_1_4.num;
     if ((T_1_5.num > 0 && T_1_3.num < 0 && T_1_4.num < 0) ||
         (T_1_5.num < 0 && T_1_3.num > 0 && T_1_4.num > 0)) {
        err = ERR_overflow;
        goto ex_0;}
    i.num = T_1_5.num;
    }

  LINE(75);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    err = stringOPempty(o, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    T_1_2.num = T_1_1.num ^ 1;
    if (T_1_2.num == true) {

  LINE(76);
        {
        CLUREF T_2_1;
        T_2_1.num = i.num + 2;
         if ((T_2_1.num > 0 && i.num < 0 && 2 < 0) ||
             (T_2_1.num < 0 && i.num > 0 && 2 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        i.num = T_2_1.num;
        }
        }
    else {
    CLUREF T_1_3;
    CLUREF T_1_4;
    err = stringOPempty(s, &T_1_3);
    if (err != ERR_ok) goto ex_0;
    T_1_4.num = T_1_3.num ^ 1;
    if (T_1_4.num == true) {

  LINE(78);
        {
        CLUREF T_2_1;
        T_2_1.num = i.num + 1;
         if ((T_2_1.num > 0 && i.num < 0 && 1 < 0) ||
             (T_2_1.num < 0 && i.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        i.num = T_2_1.num;
        }
        }
        }}/* end if */

  LINE(80);
    {
    CLUREF T_1_1;
    T_1_1.num = (i.num > dez.num)? true : false;
    if (T_1_1.num == true) {

  LINE(81);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        CLUREF T_2_4;
        CLUREF T_2_5;
        err = stringOPempty(s, &T_2_2);
        if (err != ERR_ok) goto ex_0;
        T_2_3.num = T_2_2.num ^ 1;
        T_2_1.num = T_2_3.num;
        if (!T_2_3.num) {
            err = stringOPempty(o, &T_2_4);
            if (err != ERR_ok) goto ex_0;
            T_2_5.num = T_2_4.num ^ 1;
            T_2_1.num = T_2_5.num;
        }
        if (T_2_1.num == true) {

  LINE(82);
            {
            CLUREF T_3_1;
            CLUREF T_3_2;
            CLUREF T_3_3;
            T_3_1.ch = '.';
            err = stringOPappend(n, T_3_1, &T_3_2);
            if (err != ERR_ok) goto ex_0;
            err = stringOPconcat(T_3_2, s, &T_3_3);
            if (err != ERR_ok) goto ex_0;
            n.num = T_3_3.num;
            }
            }
            }/* end if */

  LINE(83);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        err = stringOPempty(o, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        T_2_2.num = T_2_1.num ^ 1;
        if (T_2_2.num == true) {

  LINE(84);
            {
            CLUREF T_3_1;
            CLUREF T_3_2;
            CLUREF T_3_3;
            T_3_1.ch = '.';
            err = stringOPappend(n, T_3_1, &T_3_2);
            if (err != ERR_ok) goto ex_0;
            err = stringOPconcat(T_3_2, o, &T_3_3);
            if (err != ERR_ok) goto ex_0;
            n.num = T_3_3.num;
            }
            }
            }/* end if */

  LINE(85);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        CLUREF T_2_4;
        CLUREF T_2_5;
        T_2_1.ch = '/';
        err = stringOPappend(d, T_2_1, &T_2_2);
        if (err != ERR_ok) goto ex_0;
        err = stringOPsubstr(n, CLU_1, dez, &T_2_3);
        if (err != ERR_ok) goto ex_0;
        err = stringOPconcat(T_2_2, T_2_3, &T_2_4);
        if (err != ERR_ok) goto ex_0;
        err = file_nameOPparse(T_2_4, &T_2_5);
        if (err != ERR_ok) goto ex_0;
        fn.num = T_2_5.num;
        }
        }
    else {
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    err = file_nameOPget_dir(fn, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    T_1_3.num = ((d.str->size != T_1_2.str->size)? false :
        !(memcmp(d.str->data, T_1_2.str->data, d.str->size)));
    T_1_4.num = T_1_3.num ^ 1;
    if (T_1_4.num == true) {

  LINE(88);
        {
        CLUREF T_2_1;
        err = file_nameOPcreate(d, n, s, o, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        fn.num = T_2_1.num;
        }
        }
        }}/* end if */

  LINE(89);
    {
    {
    ret_1->num = fn.num;
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

/**** END PROCEDURE _fixup_file_name ****/

