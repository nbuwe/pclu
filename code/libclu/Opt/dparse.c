
/* This file was automatically generated by pclu. */

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE date_parse ****/

extern errcode arrayOPnew();
extern errcode stringOPfetch();
extern errcode charOPequal();
extern errcode intOPadd();
extern errcode charOPge();
extern errcode charOPle();
extern errcode stringOPappend();
extern errcode boolOPnot();
extern errcode stringOPempty();
extern errcode arrayOPaddh();
extern errcode charOPi2c();
extern errcode charOPc2i();
extern errcode stringOPc2s();
extern errcode intOPlt();
extern errcode arrayOPsize();
extern errcode stringOPequal();
extern errcode arrayOPfetch();
extern errcode now();
extern errcode dateOPget_day();
extern errcode dateOPget_month();
extern errcode dateOPget_year();
extern errcode arrayOPreml();
extern errcode intOPparse();
extern errcode intOPequal();
extern errcode stringOPsubstr();
extern errcode stringOPsize();
extern errcode intOPdiv();
extern errcode stringOPindexs();
extern errcode arrayOPbottom();
extern errcode arrayOPempty();
extern errcode intOPgt();
extern errcode arrayOPlow();
extern errcode arrayOPset_low();
extern errcode dateOPcreate();
static CLUREF STR__072;
static CLUREF STR_jan_040feb_040mar_040apr_040may_040jun_040jul_040aug_040sep_040oct_040nov_040dec_040;
static CLUREF STR__054;
static CLUREF STR__057;
static CLUREF STR__055;
static int date_parse_own_init = 0;

errcode
date_parse(CLUREF s, CLUREF *ret_1)
{
    errcode err;
    CLUREF as;
    CLUREF pos;
    CLUREF c;
    CLUREF acc;
    CLUREF day;
    CLUREF month;
    CLUREF year;
    CLUREF d;
    CLUREF ms;
    CLUREF expect;
    CLUREF next_char;
    CLUREF hr;
    CLUREF min;
    CLUREF sec;
    if (date_parse_own_init == 0) {
        stringOPcons(":", CLU_1, CLUREF_make_num(1), &STR__072);
        stringOPcons("jan feb mar apr may jun jul aug sep oct nov dec ", CLU_1, CLUREF_make_num(48), &STR_jan_040feb_040mar_040apr_040may_040jun_040jul_040aug_040sep_040oct_040nov_040dec_040);
        stringOPcons(",", CLU_1, CLUREF_make_num(1), &STR__054);
        stringOPcons("/", CLU_1, CLUREF_make_num(1), &STR__057);
        stringOPcons("-", CLU_1, CLUREF_make_num(1), &STR__055);
        date_parse_own_init = 1;
    }
    enter_proc(17);

  LINE(22);
    {
    CLUREF T_1_1;
    err = arrayOPnew(&T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    as.num = T_1_1.num;
    }

  LINE(23);
    {
    pos.num = 1;
    }

  LINE(25);
    for (;;) { /* while */
        if (true != true)
            break;

  LINE(27);
        {
        CLUREF T_3_1;
        err = stringOPfetch(s, pos, &T_3_1);
        if (err != ERR_ok)
            goto ex_1;
        c.num = T_3_1.num;
        }

  LINE(28);
        { /* if */
        CLUREF T_3_1;
        CLUREF T_3_2;
        CLUREF T_3_3;
        CLUREF T_3_4;
        CLUREF T_3_5;
        T_3_2.ch = ' ';
        T_3_3.num = (c.ch == T_3_2.ch);
        T_3_1.num = T_3_3.num;
        if (!T_3_3.num) {
            T_3_4.ch = '\t';
            T_3_5.num = (c.ch == T_3_4.ch);
            T_3_1.num = T_3_5.num;
        }
        if (T_3_1.num == true) { /* if */

  LINE(29);
            {
            CLUREF T_4_1;
            T_4_1.num = pos.num + 1;
            if ((T_4_1.num > 0 && pos.num < 0 && 1 < 0) ||
                (T_4_1.num < 0 && pos.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_1;
            }
            pos.num = T_4_1.num;
            }

  LINE(30);
            continue;
        }
        } /* end if */

  LINE(32);
        {
        acc = CLU_empty_string;
        }

  LINE(33);
        for (;;) { /* while */
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            CLUREF T_4_4;
            CLUREF T_4_5;
            T_4_2.ch = '0';
            err = charOPge(c, T_4_2, &T_4_3);
            if (err != ERR_ok)
                goto ex_2;
            T_4_1.num = T_4_3.num;
            if (T_4_3.num) {
                T_4_4.ch = '9';
                err = charOPle(c, T_4_4, &T_4_5);
                if (err != ERR_ok)
                    goto ex_2;
                T_4_1.num = T_4_5.num;
            }
            if (T_4_1.num != true)
                break;

  LINE(34);
            {
            CLUREF T_5_1;
            err = stringOPappend(acc, c, &T_5_1);
            if (err != ERR_ok)
                goto ex_2;
            acc.num = T_5_1.num;
            }

  LINE(35);
            {
            CLUREF T_5_1;
            T_5_1.num = pos.num + 1;
            if ((T_5_1.num > 0 && pos.num < 0 && 1 < 0) ||
                (T_5_1.num < 0 && pos.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_2;
            }
            pos.num = T_5_1.num;
            }

  LINE(36);
            {
            CLUREF T_5_1;
            err = stringOPfetch(s, pos, &T_5_1);
            if (err != ERR_ok)
                goto ex_2;
            c.num = T_5_1.num;
            }
        }
        end_while_2:
        __CLU_END_LABEL;
        goto end_2;
      ex_2: /* except */
        __CLU_EX_HANDLER;
        { /* others */
        }
      end_2:;

  LINE(38);
        { /* if */
        CLUREF T_3_1;
        CLUREF T_3_2;
        err = stringOPempty(acc, &T_3_1);
        if (err != ERR_ok)
            goto ex_1;
        T_3_2.num = !T_3_1.num;
        if (T_3_2.num == true) { /* if */

  LINE(39);
            {
            {
            if ((as.array->int_low + as.array->ext_size + 1) < as.array->int_size) {
                as.array->store->data[as.array->int_low + as.array->ext_size] = acc.num;
                as.array->ext_size++;
                as.array->ext_high++;
            }
            else {
                err = arrayOPaddh(as, acc);
                if (err != ERR_ok)
                    goto ex_1;
            }
            }
            }

  LINE(40);
            continue;
        }
        } /* end if */

  LINE(42);
        for (;;) { /* while */
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            CLUREF T_4_4;
            CLUREF T_4_5;
            CLUREF T_4_6;
            CLUREF T_4_7;
            CLUREF T_4_8;
            CLUREF T_4_9;
            CLUREF T_4_10;
            CLUREF T_4_11;
            T_4_3.ch = 'A';
            err = charOPge(c, T_4_3, &T_4_4);
            if (err != ERR_ok)
                goto ex_3;
            T_4_2.num = T_4_4.num;
            if (T_4_4.num) {
                T_4_5.ch = 'Z';
                err = charOPle(c, T_4_5, &T_4_6);
                if (err != ERR_ok)
                    goto ex_3;
                T_4_2.num = T_4_6.num;
            }
            T_4_1.num = T_4_2.num;
            if (!T_4_2.num) {
                T_4_8.ch = 'a';
                err = charOPge(c, T_4_8, &T_4_9);
                if (err != ERR_ok)
                    goto ex_3;
                T_4_7.num = T_4_9.num;
                if (T_4_9.num) {
                    T_4_10.ch = 'z';
                    err = charOPle(c, T_4_10, &T_4_11);
                    if (err != ERR_ok)
                        goto ex_3;
                    T_4_7.num = T_4_11.num;
                }
                T_4_1.num = T_4_7.num;
            }
            if (T_4_1.num != true)
                break;

  LINE(43);
            { /* if */
            CLUREF T_5_1;
            CLUREF T_5_2;
            T_5_1.ch = 'Z';
            err = charOPle(c, T_5_1, &T_5_2);
            if (err != ERR_ok)
                goto ex_3;
            if (T_5_2.num == true) { /* if */
                {
                CLUREF T_6_1;
                CLUREF T_6_2;
                CLUREF T_6_3;
                T_6_1.num = (long)(c.ch & 0xff);
                T_6_2.num = T_6_1.num + 32;
                if ((T_6_2.num > 0 && T_6_1.num < 0 && 32 < 0) ||
                    (T_6_2.num < 0 && T_6_1.num > 0 && 32 > 0)) {
                    err = ERR_overflow;
                    goto ex_3;
                }
                err = charOPi2c(T_6_2, &T_6_3);
                if (err != ERR_ok)
                    goto ex_3;
                c.num = T_6_3.num;
                }
            }
            } /* end if */

  LINE(44);
            {
            CLUREF T_5_1;
            err = stringOPappend(acc, c, &T_5_1);
            if (err != ERR_ok)
                goto ex_3;
            acc.num = T_5_1.num;
            }

  LINE(45);
            {
            CLUREF T_5_1;
            T_5_1.num = pos.num + 1;
            if ((T_5_1.num > 0 && pos.num < 0 && 1 < 0) ||
                (T_5_1.num < 0 && pos.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_3;
            }
            pos.num = T_5_1.num;
            }

  LINE(46);
            {
            CLUREF T_5_1;
            err = stringOPfetch(s, pos, &T_5_1);
            if (err != ERR_ok)
                goto ex_3;
            c.num = T_5_1.num;
            }
        }
        end_while_3:
        __CLU_END_LABEL;
        goto end_3;
      ex_3: /* except */
        __CLU_EX_HANDLER;
        { /* others */
        }
      end_3:;

  LINE(48);
        { /* if */
        CLUREF T_3_1;
        err = stringOPempty(acc, &T_3_1);
        if (err != ERR_ok)
            goto ex_1;
        if (T_3_1.num == true) { /* if */

  LINE(49);
            {
            CLUREF T_4_1;
            err = stringOPc2s(c, &T_4_1);
            if (err != ERR_ok)
                goto ex_1;
            acc.num = T_4_1.num;
            }

  LINE(50);
            {
            CLUREF T_4_1;
            T_4_1.num = pos.num + 1;
            if ((T_4_1.num > 0 && pos.num < 0 && 1 < 0) ||
                (T_4_1.num < 0 && pos.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_1;
            }
            pos.num = T_4_1.num;
            }
        }
        } /* end if */

  LINE(52);
        {
        {
        if ((as.array->int_low + as.array->ext_size + 1) < as.array->int_size) {
            as.array->store->data[as.array->int_low + as.array->ext_size] = acc.num;
            as.array->ext_size++;
            as.array->ext_high++;
        }
        else {
            err = arrayOPaddh(as, acc);
            if (err != ERR_ok)
                goto ex_1;
        }
        }
        }
    }
    end_while_1:
    __CLU_END_LABEL;
    goto end_1;
  ex_1: /* except */
    __CLU_EX_HANDLER;
    { /* others */
    }
  end_1:;

  LINE(55);
    { /* if */
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = as.array->ext_size;
    T_1_2.num = (T_1_1.num < 2);
    if (T_1_2.num == true) { /* if */
        { /* signal */
            signal(ERR_invalid_format);
        }
    }
    } /* end if */

  LINE(57);
    {
    day.num = 0;
    month.num = 0;
    year.num = 0;
    }

  LINE(58);
    { /* if */
    CLUREF T_2_1;
    CLUREF T_2_2;
    if (2 < as.array->ext_low || 2 > as.array->ext_high) {
        err = ERR_bounds;
        goto ex_4;
    }
    T_2_1.num = as.array->store->data[2 - as.array->ext_low + as.array->int_low];
    T_2_2.num = ((T_2_1.str->size != STR__072.str->size)? false :
        !(memcmp(T_2_1.str->data, STR__072.str->data, T_2_1.str->size)));
    if (T_2_2.num == true) { /* if */

  LINE(60);
        {
        CLUREF T_3_1;
        err = now(&T_3_1);
        if (err != ERR_ok)
            goto ex_4;
        d.num = T_3_1.num;
        }

  LINE(61);
        {
        CLUREF T_3_1;
        err = dateOPget_day(d, &T_3_1);
        if (err != ERR_ok)
            goto ex_4;
        day.num = T_3_1.num;
        }

  LINE(62);
        {
        CLUREF T_3_1;
        err = dateOPget_month(d, &T_3_1);
        if (err != ERR_ok)
            goto ex_4;
        month.num = T_3_1.num;
        }

  LINE(63);
        {
        CLUREF T_3_1;
        err = dateOPget_year(d, &T_3_1);
        if (err != ERR_ok)
            goto ex_4;
        year.num = T_3_1.num;
        }
    }
    else { /* else */

  LINE(66);
        {
        CLUREF T_3_1;
        err = arrayOPreml(as, &T_3_1);
        if (err != ERR_ok)
            goto ex_4;
        ms.num = T_3_1.num;
        }

  LINE(67);
        {
        CLUREF T_4_1;
        err = intOPparse(ms, &T_4_1);
        if (err != ERR_ok)
            goto ex_5;
        day.num = T_4_1.num;
        }
        goto end_5;
      ex_5: /* except */
        __CLU_EX_HANDLER;
        { /* others */
        }
      end_5:;

  LINE(70);
        { /* if */
        CLUREF T_3_1;
        T_3_1.num = (day.num == 0);
        if (T_3_1.num == true) { /* if */

  LINE(72);
            {
            CLUREF T_4_1;
            err = stringOPsubstr(ms, CLU_1, CLU_3, &T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            ms.num = T_4_1.num;
            }

  LINE(73);
            { /* if */
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            err = stringOPsize(ms, &T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            T_4_2.num = (T_4_1.num == 3);
            T_4_3.num = !T_4_2.num;
            if (T_4_3.num == true) { /* if */
                { /* signal */
                    signal(ERR_invalid_format);
                }
            }
            } /* end if */

  LINE(74);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            err = stringOPindexs(ms, STR_jan_040feb_040mar_040apr_040may_040jun_040jul_040aug_040sep_040oct_040nov_040dec_040, &T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            T_4_2.num = T_4_1.num + 3;
            if ((T_4_2.num > 0 && T_4_1.num < 0 && 3 < 0) ||
                (T_4_2.num < 0 && T_4_1.num > 0 && 3 > 0)) {
                err = ERR_overflow;
                goto ex_4;
            }
            err = intOPdiv(T_4_2, CLU_4, &T_4_3);
            if (err != ERR_ok)
                goto ex_4;
            month.num = T_4_3.num;
            }

  LINE(75);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            err = arrayOPreml(as, &T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            err = intOPparse(T_4_1, &T_4_2);
            if (err != ERR_ok)
                goto ex_4;
            day.num = T_4_2.num;
            }

  LINE(76);
            {
            expect = STR__054;
            }
        }
        else {

  LINE(77);
        CLUREF T_3_2;
        CLUREF T_3_3;
        err = arrayOPbottom(as, &T_3_2);
        if (err != ERR_ok)
            goto ex_4;
        T_3_3.num = ((T_3_2.str->size != STR__057.str->size)? false :
            !(memcmp(T_3_2.str->data, STR__057.str->data, T_3_2.str->size)));
        if (T_3_3.num == true) { /* elseif */

  LINE(79);
            {
            month.num = day.num;
            }

  LINE(80);
            {
            CLUREF T_4_1;
            err = arrayOPreml(as, &T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            }

  LINE(81);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            err = arrayOPreml(as, &T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            err = intOPparse(T_4_1, &T_4_2);
            if (err != ERR_ok)
                goto ex_4;
            day.num = T_4_2.num;
            }

  LINE(82);
            {
            expect = STR__057;
            }
        }
        else { /* else */

  LINE(84);
            { /* if */
            CLUREF T_4_1;
            CLUREF T_4_2;
            err = arrayOPbottom(as, &T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            T_4_2.num = ((T_4_1.str->size != STR__055.str->size)? false :
                !(memcmp(T_4_1.str->data, STR__055.str->data, T_4_1.str->size)));
            if (T_4_2.num == true) { /* if */

  LINE(85);
                {
                CLUREF T_5_1;
                err = arrayOPreml(as, &T_5_1);
                if (err != ERR_ok)
                    goto ex_4;
                }

  LINE(86);
                {
                expect = STR__055;
                }
            }
            else { /* else */

  LINE(87);
                {
                expect = STR__054;
                }
            }} /* end if */

  LINE(89);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            err = arrayOPreml(as, &T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            err = stringOPsubstr(T_4_1, CLU_1, CLU_3, &T_4_2);
            if (err != ERR_ok)
                goto ex_4;
            ms.num = T_4_2.num;
            }

  LINE(90);
            { /* if */
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            err = stringOPsize(ms, &T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            T_4_2.num = (T_4_1.num == 3);
            T_4_3.num = !T_4_2.num;
            if (T_4_3.num == true) { /* if */
                { /* signal */
                    signal(ERR_invalid_format);
                }
            }
            } /* end if */

  LINE(91);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            err = stringOPindexs(ms, STR_jan_040feb_040mar_040apr_040may_040jun_040jul_040aug_040sep_040oct_040nov_040dec_040, &T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            T_4_2.num = T_4_1.num + 3;
            if ((T_4_2.num > 0 && T_4_1.num < 0 && 3 < 0) ||
                (T_4_2.num < 0 && T_4_1.num > 0 && 3 > 0)) {
                err = ERR_overflow;
                goto ex_4;
            }
            err = intOPdiv(T_4_2, CLU_4, &T_4_3);
            if (err != ERR_ok)
                goto ex_4;
            month.num = T_4_3.num;
            }
        }}} /* end if */

  LINE(93);
        { /* if */
        CLUREF T_3_1;
        T_3_1.num = (as.array->ext_size == 0);
        if (T_3_1.num == true) { /* if */

  LINE(95);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            err = now(&T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            err = dateOPget_year(T_4_1, &T_4_2);
            if (err != ERR_ok)
                goto ex_4;
            year.num = T_4_2.num;
            }
        }
        else {

  LINE(96);
        CLUREF T_3_2;
        CLUREF T_3_3;
        err = arrayOPbottom(as, &T_3_2);
        if (err != ERR_ok)
            goto ex_4;
        T_3_3.num = ((T_3_2.str->size != expect.str->size)? false :
            !(memcmp(T_3_2.str->data, expect.str->data, T_3_2.str->size)));
        if (T_3_3.num == true) { /* elseif */

  LINE(98);
            {
            CLUREF T_4_1;
            err = arrayOPreml(as, &T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            }

  LINE(99);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            err = arrayOPreml(as, &T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            err = intOPparse(T_4_1, &T_4_2);
            if (err != ERR_ok)
                goto ex_4;
            year.num = T_4_2.num;
            }
        }
        else {

  LINE(100);
        CLUREF T_3_4;
        T_3_4.num = ((expect.str->size != STR__054.str->size)? false :
            !(memcmp(expect.str->data, STR__054.str->data, expect.str->size)));
        if (T_3_4.num == true) { /* elseif */

  LINE(102);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            err = arrayOPbottom(as, &T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            err = intOPparse(T_4_1, &T_4_2);
            if (err != ERR_ok)
                goto ex_4;
            year.num = T_4_2.num;
            }

  LINE(103);
            { /* if */
            CLUREF T_4_1;
            T_4_1.num = (year.num > 23);
            if (T_4_1.num == true) { /* if */

  LINE(105);
                {
                CLUREF T_5_1;
                err = arrayOPreml(as, &T_5_1);
                if (err != ERR_ok)
                    goto ex_4;
                }
            }
            else { /* else */

  LINE(107);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                CLUREF T_5_4;
                T_5_1.num = as.array->ext_low;
                T_5_2.num = T_5_1.num + 1;
                if ((T_5_2.num > 0 && T_5_1.num < 0 && 1 < 0) ||
                    (T_5_2.num < 0 && T_5_1.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_4;
                }
                if (T_5_2.num < as.array->ext_low || T_5_2.num > as.array->ext_high) {
                    err = ERR_bounds;
                    goto ex_4;
                }
                T_5_3.num = as.array->store->data[T_5_2.num - as.array->ext_low + as.array->int_low];
                err = stringOPfetch(T_5_3, CLU_1, &T_5_4);
                if (err != ERR_ok)
                    goto ex_4;
                next_char.num = T_5_4.num;
                }

  LINE(108);
                { /* if */
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                CLUREF T_5_4;
                CLUREF T_5_5;
                T_5_2.ch = '1';
                err = charOPge(next_char, T_5_2, &T_5_3);
                if (err != ERR_ok)
                    goto ex_4;
                T_5_1.num = T_5_3.num;
                if (T_5_3.num) {
                    T_5_4.ch = '9';
                    err = charOPle(next_char, T_5_4, &T_5_5);
                    if (err != ERR_ok)
                        goto ex_4;
                    T_5_1.num = T_5_5.num;
                }
                if (T_5_1.num == true) { /* if */

  LINE(110);
                    {
                    CLUREF T_6_1;
                    err = arrayOPreml(as, &T_6_1);
                    if (err != ERR_ok)
                        goto ex_4;
                    }
                }
                else { /* else */

  LINE(112);
                    {
                    CLUREF T_6_1;
                    CLUREF T_6_2;
                    err = now(&T_6_1);
                    if (err != ERR_ok)
                        goto ex_4;
                    err = dateOPget_year(T_6_1, &T_6_2);
                    if (err != ERR_ok)
                        goto ex_4;
                    year.num = T_6_2.num;
                    }
                }} /* end if */
            }} /* end if */
        }
        else { /* else */

  LINE(115);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            err = now(&T_4_1);
            if (err != ERR_ok)
                goto ex_4;
            err = dateOPget_year(T_4_1, &T_4_2);
            if (err != ERR_ok)
                goto ex_4;
            year.num = T_4_2.num;
            }
        }}}} /* end if */

  LINE(117);
        { /* if */
        CLUREF T_3_1;
        CLUREF T_3_2;
        T_3_1.num = 100;
        T_3_2.num = (year.num < T_3_1.num);
        if (T_3_2.num == true) { /* if */
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            T_4_1.num = 1900;
            T_4_2.num = year.num + T_4_1.num;
            if ((T_4_2.num > 0 && year.num < 0 && T_4_1.num < 0) ||
                (T_4_2.num < 0 && year.num > 0 && T_4_1.num > 0)) {
                err = ERR_overflow;
                goto ex_4;
            }
            year.num = T_4_2.num;
            }
        }
        } /* end if */

  LINE(118);
        {
        err = arrayOPset_low(as, CLU_1);
        if (err != ERR_ok)
            goto ex_4;
        }
    }} /* end if */
    goto end_4;
  ex_4: /* except */
    __CLU_EX_HANDLER;
    { /* others */

  LINE(119);
        { /* signal */
            signal(ERR_invalid_format);
        }
    }
  end_4:;

  LINE(122);
    {
    hr.num = 0;
    min.num = 0;
    sec.num = 0;
    }

  LINE(123);
    { /* if */
    CLUREF T_2_1;
    CLUREF T_2_2;
    T_2_1.num = (as.array->ext_size == 0);
    T_2_2.num = !T_2_1.num;
    if (T_2_2.num == true) { /* if */

  LINE(124);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        err = arrayOPreml(as, &T_3_1);
        if (err != ERR_ok)
            goto ex_6;
        err = intOPparse(T_3_1, &T_3_2);
        if (err != ERR_ok)
            goto ex_6;
        hr.num = T_3_2.num;
        }

  LINE(125);
        { /* if */
        CLUREF T_3_1;
        CLUREF T_3_2;
        CLUREF T_3_3;
        err = arrayOPreml(as, &T_3_1);
        if (err != ERR_ok)
            goto ex_6;
        T_3_2.num = ((T_3_1.str->size != STR__072.str->size)? false :
            !(memcmp(T_3_1.str->data, STR__072.str->data, T_3_1.str->size)));
        T_3_3.num = !T_3_2.num;
        if (T_3_3.num == true) { /* if */
            { /* signal */
                signal(ERR_invalid_format);
            }
        }
        } /* end if */

  LINE(126);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        err = arrayOPreml(as, &T_3_1);
        if (err != ERR_ok)
            goto ex_6;
        err = intOPparse(T_3_1, &T_3_2);
        if (err != ERR_ok)
            goto ex_6;
        min.num = T_3_2.num;
        }

  LINE(127);
        { /* if */
        CLUREF T_3_1;
        CLUREF T_3_2;
        T_3_1.num = (as.array->ext_size == 0);
        T_3_2.num = !T_3_1.num;
        if (T_3_2.num == true) { /* if */

  LINE(128);
            { /* if */
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            err = arrayOPreml(as, &T_4_1);
            if (err != ERR_ok)
                goto ex_6;
            T_4_2.num = ((T_4_1.str->size != STR__072.str->size)? false :
                !(memcmp(T_4_1.str->data, STR__072.str->data, T_4_1.str->size)));
            T_4_3.num = !T_4_2.num;
            if (T_4_3.num == true) { /* if */
                { /* signal */
                    signal(ERR_invalid_format);
                }
            }
            } /* end if */

  LINE(129);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            err = arrayOPreml(as, &T_4_1);
            if (err != ERR_ok)
                goto ex_6;
            err = intOPparse(T_4_1, &T_4_2);
            if (err != ERR_ok)
                goto ex_6;
            sec.num = T_4_2.num;
            }
        }
        } /* end if */
    }
    } /* end if */
    goto end_6;
  ex_6: /* except */
    __CLU_EX_HANDLER;
    { /* others */

  LINE(131);
        { /* signal */
            signal(ERR_invalid_format);
        }
    }
  end_6:;

  LINE(132);
    { /* if */
    CLUREF T_2_1;
    T_2_1.num = (as.array->ext_size == 0);
    if (T_2_1.num == true) { /* if */

  LINE(133);
        { /* return */
        {
        CLUREF T_3_1;
        err = dateOPcreate(day, month, year, hr, min, sec, &T_3_1);
        if (err != ERR_ok)
            goto ex_7;
        ret_1->num = T_3_1.num;
        }
        signal (ERR_ok);
        }
    }
    } /* end if */
    goto end_7;
  ex_7: /* except */
    __CLU_EX_HANDLER;
    { /* others */
    }
  end_7:;

  LINE(136);
    { /* signal */
        signal(ERR_invalid_format);
    }

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

/**** END PROCEDURE date_parse ****/



/**** BEGIN PROCEDURE date_sub ****/

extern errcode dateOPget_all();
extern errcode intOPsub();
extern errcode intOPmod();

errcode
date_sub(CLUREF d, CLUREF days, CLUREF months, CLUREF years, CLUREF *ret_1)
{
    errcode err;
    CLUREF m2d;
    CLUREF lm2d;
    CLUREF adj;
    CLUREF day;
    CLUREF month;
    CLUREF year;
    CLUREF hour;
    CLUREF min;
    CLUREF sec;
    CLUREF dim;
    enter_proc(139);

  LINE(142);
    {
    CLUREF T_1_1;
    err = arrayOPpredict(CLU_1, CLU_12, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_31);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_28);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_31);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_30);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_31);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_30);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_31);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_31);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_30);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_31);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_30);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_31);
    if (err != ERR_ok)
        goto ex_0;
    m2d.num = T_1_1.num;
    }

  LINE(143);
    {
    CLUREF T_1_1;
    err = arrayOPpredict(CLU_1, CLU_12, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_31);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_29);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_31);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_30);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_31);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_30);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_31);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_31);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_30);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_31);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_30);
    if (err != ERR_ok)
        goto ex_0;
    err = arrayOPaddh(T_1_1, CLU_31);
    if (err != ERR_ok)
        goto ex_0;
    lm2d.num = T_1_1.num;
    }

  LINE(144);
    {
    adj.num = m2d.num;
    }

  LINE(146);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    CLUREF T_1_6;
    err = dateOPget_all(d, &T_1_1, &T_1_2, &T_1_3, &T_1_4, &T_1_5, &T_1_6);
    if (err != ERR_ok)
        goto ex_0;
    day.num = T_1_1.num;
    month.num = T_1_2.num;
    year.num = T_1_3.num;
    hour.num = T_1_4.num;
    min.num = T_1_5.num;
    sec.num = T_1_6.num;
    }

  LINE(148);
    {
    CLUREF T_2_1;
    T_2_1.num = day.num - days.num;
    if ((T_2_1.num >= 0 && day.num < 0 && (-days.num) < 0) ||
        (T_2_1.num <= 0 && day.num > 0 && (-days.num) > 0)) {
        err = ERR_overflow;
        goto ex_1;
    }
    day.num = T_2_1.num;
    }
    goto end_1;
  ex_1: /* except */
    __CLU_EX_HANDLER;
    if (err == ERR_overflow) {

  LINE(149);
        { /* signal */
            signal(ERR_overflow);
        }
    }
    else { /* not handled */
        goto ex_0;
    }
  end_1:;

  LINE(150);
    for (;;) { /* while */
        if (true != true)
            break;

  LINE(151);
        { /* if */
        CLUREF T_3_1;
        T_3_1.num = (day.num < 1);
        if (T_3_1.num == true) { /* if */

  LINE(152);
            {
            CLUREF T_4_1;
            T_4_1.num = month.num - 1;
            if ((T_4_1.num >= 0 && month.num < 0 && (-1) < 0) ||
                (T_4_1.num <= 0 && month.num > 0 && (-1) > 0)) {
                err = ERR_overflow;
                goto ex_2;
            }
            month.num = T_4_1.num;
            }

  LINE(153);
            { /* if */
            CLUREF T_4_1;
            T_4_1.num = (month.num == 0);
            if (T_4_1.num == true) { /* if */

  LINE(154);
                {
                month.num = 12;
                }

  LINE(155);
                {
                CLUREF T_5_1;
                T_5_1.num = year.num - 1;
                if ((T_5_1.num >= 0 && year.num < 0 && (-1) < 0) ||
                    (T_5_1.num <= 0 && year.num > 0 && (-1) > 0)) {
                    err = ERR_overflow;
                    goto ex_2;
                }
                year.num = T_5_1.num;
                }
            }
            } /* end if */
        }
        } /* end if */

  LINE(158);
        {
        adj.num = m2d.num;
        }

  LINE(159);
        { /* if */
        CLUREF T_3_1;
        CLUREF T_3_2;
        CLUREF T_3_3;
        CLUREF T_3_4;
        CLUREF T_3_5;
        CLUREF T_3_6;
        CLUREF T_3_7;
        CLUREF T_3_8;
        err = intOPmod(year, CLU_4, &T_3_2);
        if (err != ERR_ok)
            goto ex_2;
        T_3_3.num = (T_3_2.num == 0);
        T_3_4.num = !T_3_3.num;
        T_3_1.num = T_3_4.num;
        if (!T_3_4.num) {
            T_3_5.num = 100;
            err = intOPmod(year, T_3_5, &T_3_6);
            if (err != ERR_ok)
                goto ex_2;
            T_3_7.num = (T_3_6.num == 0);
            T_3_8.num = !T_3_7.num;
            T_3_1.num = T_3_8.num;
        }
        if (T_3_1.num == true) { /* if */
            {
            adj.num = lm2d.num;
            }
        }
        } /* end if */

  LINE(160);
        {
        CLUREF T_3_1;
        if (month.num < adj.array->ext_low || month.num > adj.array->ext_high) {
            err = ERR_bounds;
            goto ex_2;
        }
        T_3_1.num = adj.array->store->data[month.num - adj.array->ext_low + adj.array->int_low];
        dim.num = T_3_1.num;
        }

  LINE(161);
        { /* if */
        CLUREF T_3_1;
        T_3_1.num = (day.num < 1);
        if (T_3_1.num == true) { /* if */

  LINE(162);
            {
            CLUREF T_4_1;
            T_4_1.num = day.num + dim.num;
            if ((T_4_1.num > 0 && day.num < 0 && dim.num < 0) ||
                (T_4_1.num < 0 && day.num > 0 && dim.num > 0)) {
                err = ERR_overflow;
                goto ex_2;
            }
            day.num = T_4_1.num;
            }

  LINE(163);
            { /* if */
            CLUREF T_4_1;
            T_4_1.num = (day.num < 1);
            if (T_4_1.num == true) { /* if */
                continue;
            }
            } /* end if */
        }
        } /* end if */

  LINE(165);
        { /* if */
        CLUREF T_3_1;
        T_3_1.num = (day.num > dim.num);
        if (T_3_1.num == true) { /* if */

  LINE(166);
            {
            CLUREF T_4_1;
            T_4_1.num = day.num - dim.num;
            if ((T_4_1.num >= 0 && day.num < 0 && (-dim.num) < 0) ||
                (T_4_1.num <= 0 && day.num > 0 && (-dim.num) > 0)) {
                err = ERR_overflow;
                goto ex_2;
            }
            day.num = T_4_1.num;
            }

  LINE(167);
            {
            CLUREF T_4_1;
            T_4_1.num = month.num + 1;
            if ((T_4_1.num > 0 && month.num < 0 && 1 < 0) ||
                (T_4_1.num < 0 && month.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_2;
            }
            month.num = T_4_1.num;
            }

  LINE(168);
            { /* if */
            CLUREF T_4_1;
            T_4_1.num = (month.num > 12);
            if (T_4_1.num == true) { /* if */

  LINE(169);
                {
                month.num = 1;
                }

  LINE(170);
                {
                CLUREF T_5_1;
                T_5_1.num = year.num + 1;
                if ((T_5_1.num > 0 && year.num < 0 && 1 < 0) ||
                    (T_5_1.num < 0 && year.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_2;
                }
                year.num = T_5_1.num;
                }
            }
            } /* end if */

  LINE(172);
            continue;
        }
        } /* end if */

  LINE(175);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        T_3_1.num = month.num - 1;
        if ((T_3_1.num >= 0 && month.num < 0 && (-1) < 0) ||
            (T_3_1.num <= 0 && month.num > 0 && (-1) > 0)) {
            err = ERR_overflow;
            goto ex_2;
        }
        T_3_2.num = T_3_1.num - months.num;
        if ((T_3_2.num >= 0 && T_3_1.num < 0 && (-months.num) < 0) ||
            (T_3_2.num <= 0 && T_3_1.num > 0 && (-months.num) > 0)) {
            err = ERR_overflow;
            goto ex_2;
        }
        month.num = T_3_2.num;
        }

  LINE(176);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        CLUREF T_3_3;
        T_3_1.num = year.num - years.num;
        if ((T_3_1.num >= 0 && year.num < 0 && (-years.num) < 0) ||
            (T_3_1.num <= 0 && year.num > 0 && (-years.num) > 0)) {
            err = ERR_overflow;
            goto ex_2;
        }
        err = intOPdiv(month, CLU_12, &T_3_2);
        if (err != ERR_ok)
            goto ex_2;
        T_3_3.num = T_3_1.num + T_3_2.num;
        if ((T_3_3.num > 0 && T_3_1.num < 0 && T_3_2.num < 0) ||
            (T_3_3.num < 0 && T_3_1.num > 0 && T_3_2.num > 0)) {
            err = ERR_overflow;
            goto ex_2;
        }
        year.num = T_3_3.num;
        }

  LINE(177);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        err = intOPmod(month, CLU_12, &T_3_1);
        if (err != ERR_ok)
            goto ex_2;
        T_3_2.num = T_3_1.num + 1;
        if ((T_3_2.num > 0 && T_3_1.num < 0 && 1 < 0) ||
            (T_3_2.num < 0 && T_3_1.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_2;
        }
        month.num = T_3_2.num;
        }

  LINE(178);
        { /* if */
        CLUREF T_3_1;
        T_3_1.num = (months.num == 0);
        if (T_3_1.num == true) { /* if */

  LINE(179);
            { /* return */
            {
            CLUREF T_4_1;
            err = dateOPcreate(day, month, year, hour, min, sec, &T_4_1);
            if (err != ERR_ok)
                goto ex_2;
            ret_1->num = T_4_1.num;
            }
            signal (ERR_ok);
            }
        }
        } /* end if */

  LINE(181);
        {
        months.num = 0;
        }

  LINE(182);
        {
        years.num = 0;
        }
    }
    end_while_1:
    __CLU_END_LABEL;
    goto end_2;
  ex_2: /* except */
    __CLU_EX_HANDLER;
    if (err == ERR_overflow) {

  LINE(183);
        { /* signal */
            signal(ERR_overflow);
        }
    }
    else { /* not handled */
        goto ex_0;
    }
  end_2:;

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

/**** END PROCEDURE date_sub ****/



/**** BEGIN PROCEDURE ago ****/

extern errcode dateOPunparse();
extern errcode date_sub();

errcode
ago(CLUREF days, CLUREF months, CLUREF years, CLUREF *ret_1)
{
    errcode err;
    enter_proc(186);

  LINE(187);
    { /* return */
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    err = now(&T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    err = date_sub(T_1_1, days, months, years, &T_1_2);
    if (err != ERR_ok)
        goto ex_0;
    err = dateOPunparse(T_1_2, &T_1_3);
    if (err != ERR_ok)
        goto ex_0;
    ret_1->num = T_1_3.num;
    }
    signal (ERR_ok);
    }

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

/**** END PROCEDURE ago ****/

