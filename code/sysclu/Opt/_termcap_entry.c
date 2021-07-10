
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE _termcap_entry ****/

extern errcode _bytevecOPcreate();
extern errcode _chanOPopen();
extern errcode file_nameOPparse();
extern errcode intOPadd();
extern errcode stringOPsize();
extern errcode _cvt();
extern errcode _chanOPgetb();
extern errcode charOPequal();
extern errcode _bytevecOPfetch();
extern errcode _skip_fill();
extern errcode intOPequal();
extern errcode _bytevecOPindexv();
extern errcode _bytevecOPindexc();
extern errcode intOPgt();
extern errcode intOPlt();
extern errcode _chanOPget();
extern errcode intOPle();
extern errcode boolOPnot();
extern errcode stringOPfetch();
extern errcode stringOPindexc();
extern errcode stringOPempty();
extern errcode stringOPconcat();
extern errcode stringOPsubstr();
extern errcode intOPsub();
extern errcode _chanOPclose();
extern errcode stringOPindexs();
static CLUREF STR_read;
static CLUREF STR__012;
static CLUREF STR__072tc_075;
static int _termcap_entry_own_init = 0;

errcode
_termcap_entry(CLUREF fs, CLUREF term, CLUREF *ret_1)
{
    errcode err;
    CLUREF ent;
    CLUREF c;
    CLUREF b;
    CLUREF idx;
    CLUREF bterm;
    CLUREF max;
    CLUREF fin;
    CLUREF first;
    CLUREF i1;
    CLUREF i2;
    CLUREF s;
    CLUREF more;
    CLUREF z;
    CLUREF i;
    if (_termcap_entry_own_init == 0) {
        stringOPcons("read", CLU_1, CLUREF_make_num(4), &STR_read);
        stringOPcons("\n", CLU_1, CLUREF_make_num(1), &STR__012);
        stringOPcons(":tc=", CLU_1, CLUREF_make_num(4), &STR__072tc_075);
        _termcap_entry_own_init = 1;
    }
    enter_proc(3);

  LINE(4);
    {
        {ent = CLU_empty_string;
        }
        }

  LINE(6);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = 128;
        err = _bytevecOPcreate(T_1_1, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        b.num = T_1_2.num;
        }
        }

  LINE(7);
    for (;;) {
        if (true != true) { break; }

  LINE(8);
        {
        CLUREF T_4_1;
        CLUREF T_4_2;
        err = file_nameOPparse(fs, &T_4_1);
        if (err != ERR_ok) goto ex_2;
        err = _chanOPopen(T_4_1, STR_read, CLU_0, &T_4_2);
        if (err != ERR_ok) goto ex_2;
        c.num = T_4_2.num;
        }
            goto end_2;
            ex_2:
                if ((err == ERR_bad_format)
                 || (err == ERR_not_possible)) {

  LINE(9);
                    {
                    {signal (ERR_not_found);}}
                }
                else {
                    goto ex_1;
                }
            end_2:;

  LINE(11);
        {
            {CLUREF T_3_1;
            CLUREF T_3_2;
            err = stringOPsize(term, &T_3_1);
            if (err != ERR_ok) goto ex_1;
            T_3_2.num = T_3_1.num + 1;
             if ((T_3_2.num > 0 && T_3_1.num < 0 && 1 < 0) ||
                 (T_3_2.num < 0 && T_3_1.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            idx.num = T_3_2.num;
            }
            }

  LINE(12);
        {
            {CLUREF T_3_1;
            T_3_1.num = (long)term.num;
            bterm.num = T_3_1.num;
            }
            }

  LINE(13);
        {
            {CLUREF T_3_1;
            err = _chanOPgetb(c, b, &T_3_1);
            if (err != ERR_ok) goto ex_1;
            max.num = T_3_1.num;
            }
            }

  LINE(15);
        for (;;) {
            if (true != true) { break; }

  LINE(17);
            for (;;) {
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                CLUREF T_5_4;
                CLUREF T_5_5;
                CLUREF T_5_6;
                CLUREF T_5_7;
                if (1 < 1 || 1 > b.str->size ) {
                    err = ERR_bounds;
                    goto ex_3;}
                T_5_2.ch = b.str->data[1 - 1];
                T_5_3.ch = '#';
                T_5_4.num = (T_5_2.ch == T_5_3.ch)? true : false;
                T_5_1.num = T_5_4.num;
                if (!T_5_4.num) {
                    if (1 < 1 || 1 > b.str->size ) {
                        err = ERR_bounds;
                        goto ex_3;}
                    T_5_5.ch = b.str->data[1 - 1];
                    T_5_6.ch = '\n';
                    T_5_7.num = (T_5_5.ch == T_5_6.ch)? true : false;
                    T_5_1.num = T_5_7.num;
                }
                if (T_5_1.num != true) { break; }

  LINE(18);
                {
                CLUREF T_6_1;
                CLUREF T_6_2;
                T_6_1.ch = '\n';
                err = _skip_fill(b, max, c, T_6_1, &T_6_2);
                if (err != ERR_ok) goto ex_3;
                max.num = T_6_2.num;
                }
                }
                end_while_3:;

  LINE(21);
            {
                {CLUREF T_5_1;
                T_5_1.ch = '|';
                fin.num = T_5_1.num;
                }
                }

  LINE(22);
            {
                {first.tf = true;
                }
                }

  LINE(23);
            for (;;) {
                if (true != true) { break; }

  LINE(24);
                {
                if (first.num == true) {
                    {
                    first.tf = false;
                    }
                    }
                else {

  LINE(25);
                    {
                    CLUREF T_7_1;
                    err = _skip_fill(b, max, c, fin, &T_7_1);
                    if (err != ERR_ok) goto ex_3;
                    max.num = T_7_1.num;
                    }
                    }}/* end if */

  LINE(26);
                {
                CLUREF T_6_1;
                CLUREF T_6_2;
                CLUREF T_6_3;
                CLUREF T_6_4;
                CLUREF T_6_5;
                CLUREF T_6_6;
                CLUREF T_6_7;
                CLUREF T_6_8;
                CLUREF T_6_9;
                CLUREF T_6_10;
                err = _bytevecOPindexv(bterm, b, CLU_1, &T_6_2);
                if (err != ERR_ok) goto ex_3;
                T_6_3.num = (T_6_2.num == 1)? true : false;
                T_6_1.num = T_6_3.num;
                if (T_6_3.num) {
                    if (idx.num < 1 || idx.num > b.str->size ) {
                        err = ERR_bounds;
                        goto ex_3;}
                    T_6_5.ch = b.str->data[idx.num - 1];
                    T_6_6.ch = '|';
                    T_6_7.num = (T_6_5.ch == T_6_6.ch)? true : false;
                    T_6_4.num = T_6_7.num;
                    if (!T_6_7.num) {
                        if (idx.num < 1 || idx.num > b.str->size ) {
                            err = ERR_bounds;
                            goto ex_3;}
                        T_6_8.ch = b.str->data[idx.num - 1];
                        T_6_9.ch = ':';
                        T_6_10.num = (T_6_8.ch == T_6_9.ch)? true : false;
                        T_6_4.num = T_6_10.num;
                    }
                    T_6_1.num = T_6_4.num;
                }
                if (T_6_1.num == true) {

  LINE(28);
                    {
                        err = ERR_found;
                        goto ex_3;
                        }
                    }
                    }/* end if */

  LINE(29);
                {
                CLUREF T_6_1;
                CLUREF T_6_2;
                T_6_1.ch = ':';
                T_6_2.num = (fin.ch == T_6_1.ch)? true : false;
                if (T_6_2.num == true) {

  LINE(30);
                    goto end_while_4;
                    }
                    }/* end if */

  LINE(31);
                {
                    {CLUREF T_6_1;
                    CLUREF T_6_2;
                    T_6_1.ch = ':';
                    err = _bytevecOPindexc(T_6_1, b, CLU_1, &T_6_2);
                    if (err != ERR_ok) goto ex_3;
                    i1.num = T_6_2.num;
                    }
                    }

  LINE(32);
                {
                CLUREF T_6_1;
                T_6_1.num = (i1.num > 0)? true : false;
                if (T_6_1.num == true) {

  LINE(33);
                    {
                        {CLUREF T_7_1;
                        CLUREF T_7_2;
                        T_7_1.ch = '|';
                        err = _bytevecOPindexc(T_7_1, b, CLU_1, &T_7_2);
                        if (err != ERR_ok) goto ex_3;
                        i2.num = T_7_2.num;
                        }
                        }

  LINE(34);
                    {
                    CLUREF T_7_1;
                    CLUREF T_7_2;
                    CLUREF T_7_3;
                    T_7_2.num = (i2.num == 0)? true : false;
                    T_7_1.num = T_7_2.num;
                    if (!T_7_2.num) {
                        T_7_3.num = (i1.num < i2.num)? true : false;
                        T_7_1.num = T_7_3.num;
                    }
                    if (T_7_1.num == true) {

  LINE(35);
                        {
                        CLUREF T_8_1;
                        T_8_1.ch = ':';
                        fin.num = T_8_1.num;
                        }
                        }
                        }/* end if */
                    }
                    }/* end if */
                }
                end_while_4:;

  LINE(38);
            {
            CLUREF T_5_1;
            CLUREF T_5_2;
            T_5_1.ch = '\n';
            err = _skip_fill(b, max, c, T_5_1, &T_5_2);
            if (err != ERR_ok) goto ex_3;
            max.num = T_5_2.num;
            }
            }
            end_while_2:;
            goto end_3;
            ex_3:
                if ((err == ERR_found)) {
                }
                else {
                    goto ex_1;
                }
            end_3:;

  LINE(41);
        {
            {more.tf = true;
            }
            }

  LINE(42);
        for (;;) {
            if (more.num != true) { break; }

  LINE(43);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            err = _chanOPget(c, b, idx, max, STR__012, CLU_0, &T_4_1, &T_4_2, &T_4_3);
            if (err != ERR_ok) goto ex_1;
            s.num = T_4_1.num;
            idx.num = T_4_2.num;
            max.num = T_4_3.num;
            }

  LINE(44);
            {
            CLUREF T_4_1;
            T_4_1.num = (idx.num <= max.num)? true : false;
            if (T_4_1.num == true) {

  LINE(45);
                {
                CLUREF T_5_1;
                T_5_1.num = idx.num + 1;
                 if ((T_5_1.num > 0 && idx.num < 0 && 1 < 0) ||
                     (T_5_1.num < 0 && idx.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                idx.num = T_5_1.num;
                }
                }
                }/* end if */

  LINE(46);
            {
                {CLUREF T_4_1;
                err = stringOPsize(s, &T_4_1);
                if (err != ERR_ok) goto ex_1;
                z.num = T_4_1.num;
                }
                }

  LINE(47);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            CLUREF T_4_4;
            err = stringOPfetch(s, z, &T_4_1);
            if (err != ERR_ok) goto ex_1;
            T_4_2.ch = '\\';
            T_4_3.num = (T_4_1.ch == T_4_2.ch)? true : false;
            T_4_4.num = T_4_3.num ^ 1;
            if (T_4_4.num == true) {

  LINE(48);
                {
                more.tf = false;
                }

  LINE(49);
                {
                CLUREF T_5_1;
                T_5_1.num = z.num + 1;
                 if ((T_5_1.num > 0 && z.num < 0 && 1 < 0) ||
                     (T_5_1.num < 0 && z.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                z.num = T_5_1.num;
                }
                }
                }/* end if */

  LINE(51);
            {
                {CLUREF T_4_1;
                CLUREF T_4_2;
                T_4_1.ch = ':';
                err = stringOPindexc(T_4_1, s, &T_4_2);
                if (err != ERR_ok) goto ex_1;
                i.num = T_4_2.num;
                }
                }

  LINE(52);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            err = stringOPempty(ent, &T_4_1);
            if (err != ERR_ok) goto ex_1;
            T_4_2.num = T_4_1.num ^ 1;
            if (T_4_2.num == true) {

  LINE(53);
                {
                CLUREF T_5_1;
                T_5_1.num = i.num + 1;
                 if ((T_5_1.num > 0 && i.num < 0 && 1 < 0) ||
                     (T_5_1.num < 0 && i.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                i.num = T_5_1.num;
                }
                }
                }/* end if */

  LINE(54);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            T_4_1.num = z.num - i.num;
             if ((T_4_1.num >= 0 && z.num < 0 && (-i.num) < 0) ||
                 (T_4_1.num <= 0 && z.num > 0 && (-i.num) > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            err = stringOPsubstr(s, i, T_4_1, &T_4_2);
            if (err != ERR_ok) goto ex_1;
            err = stringOPconcat(ent, T_4_2, &T_4_3);
            if (err != ERR_ok) goto ex_1;
            ent.num = T_4_3.num;
            }
            }
            end_while_5:;

  LINE(56);
        {
        err = _chanOPclose(c);
        if (err != ERR_ok) goto ex_1;
        }

  LINE(57);
        {
            {CLUREF T_3_1;
            err = stringOPindexs(STR__072tc_075, ent, &T_3_1);
            if (err != ERR_ok) goto ex_1;
            i.num = T_3_1.num;
            }
            }

  LINE(58);
        {
        CLUREF T_3_1;
        T_3_1.num = (i.num == 0)? true : false;
        if (T_3_1.num == true) {

  LINE(59);
            {
            {
            ret_1->num = ent.num;
            }
            {signal (ERR_ok);}}
            }
            }/* end if */

  LINE(60);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        CLUREF T_3_3;
        CLUREF T_3_4;
        CLUREF T_3_5;
        T_3_1.num = i.num + 4;
         if ((T_3_1.num > 0 && i.num < 0 && 4 < 0) ||
             (T_3_1.num < 0 && i.num > 0 && 4 > 0)) {
            err = ERR_overflow;
            goto ex_1;}
        err = stringOPsize(ent, &T_3_2);
        if (err != ERR_ok) goto ex_1;
        T_3_3.num = T_3_2.num - i.num;
         if ((T_3_3.num >= 0 && T_3_2.num < 0 && (-i.num) < 0) ||
             (T_3_3.num <= 0 && T_3_2.num > 0 && (-i.num) > 0)) {
            err = ERR_overflow;
            goto ex_1;}
        T_3_4.num = T_3_3.num - 4;
         if ((T_3_4.num >= 0 && T_3_3.num < 0 && (-4) < 0) ||
             (T_3_4.num <= 0 && T_3_3.num > 0 && (-4) > 0)) {
            err = ERR_overflow;
            goto ex_1;}
        err = stringOPsubstr(ent, T_3_1, T_3_4, &T_3_5);
        if (err != ERR_ok) goto ex_1;
        term.num = T_3_5.num;
        }

  LINE(61);
        {
        CLUREF T_3_1;
        err = stringOPsubstr(ent, CLU_1, i, &T_3_1);
        if (err != ERR_ok) goto ex_1;
        ent.num = T_3_1.num;
        }
        }
        end_while_1:;
        goto end_1;
        ex_1:
            if ((err == ERR_not_possible)) {
            }
            else if ((err == ERR_bounds)
             || (err == ERR_end_of_file)) {
            }
            else {
                goto ex_0;
            }
        end_1:;

  LINE(66);
    {
    err = _chanOPclose(c);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(67);
    {
    {signal (ERR_not_found);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE _termcap_entry ****/

