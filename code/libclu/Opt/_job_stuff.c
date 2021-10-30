
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE _job_stuff ****/

extern errcode file_name_fill();
extern errcode file_nameOPunparse();
extern errcode stringOPempty();
extern errcode file_nameOPget_dir();
extern errcode boolOPnot();
extern errcode _environ();
extern errcode arrayOPnew();
extern errcode intOPadd();
extern errcode _bytevecOPindexc();
extern errcode _cvt();
extern errcode intOPequal();
extern errcode stringOPsize();
extern errcode stringOPsubstr();
extern errcode intOPsub();
extern errcode stringOPequal();
extern errcode stringOPappend();
extern errcode arrayOPaddh();
extern errcode arrayOPelements();
extern errcode stringOPconcat();
extern errcode _file_access();
extern errcode _file_exists();
extern errcode intOPgt();
extern errcode stringOPindexc();
extern errcode _bytevecOPfetch();
extern errcode _bytevecOPstore();
extern errcode _wordvecOPcreate();
extern errcode _wordvecOPstore();
extern errcode charOPequal();
static CLUREF STR_PATH;
static CLUREF STR__072_057bin_072_057usr_057bin;
static CLUREF STR__056;
static CLUREF STR_no_040such_040executable_040file;
static CLUREF STR__040_011_000;
static CLUREF STR__000;
static int _job_stuff_own_init = 0;
CLUREF _job_stuffOPinit;
CLUREF _job_stuffOPdirs;

errcode
_job_stuff(CLUREF fn, CLUREF jcl, CLUREF *ret_1, CLUREF *ret_2, CLUREF *ret_3)
{
    errcode err;
    CLUREF fs;
    CLUREF s;
    CLUREF j;
    CLUREF i;
    CLUREF ws;
    CLUREF b;
    CLUREF chars;
    CLUREF cnt;
    CLUREF v;
    if (_job_stuff_own_init == 0) {
        stringOPcons("PATH", CLU_1, CLUREF_make_num(4), &STR_PATH);
        stringOPcons(":/bin:/usr/bin", CLU_1, CLUREF_make_num(14), &STR__072_057bin_072_057usr_057bin);
        stringOPcons(".", CLU_1, CLUREF_make_num(1), &STR__056);
        stringOPcons("no such executable file", CLU_1, CLUREF_make_num(23), &STR_no_040such_040executable_040file);
        stringOPcons(" \t\000", CLU_1, CLUREF_make_num(3), &STR__040_011_000);
        stringOPcons("\000", CLU_1, CLUREF_make_num(1), &STR__000);
        _job_stuff_own_init = 1;
        {
            {_job_stuffOPinit.tf = false;
            }
            }
    }
    enter_proc(3);

  LINE(9);
    {
    CLUREF T_1_1;
    err = file_name_fill(fn, CLU_empty_string, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    fn.num = T_1_1.num;
    }

  LINE(10);
    {
        {CLUREF T_1_1;
        err = file_nameOPunparse(fn, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        fs.num = T_1_1.num;
        }
        }

  LINE(11);
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    err = file_nameOPget_dir(fn, &T_2_1);
    if (err != ERR_ok) goto ex_1;
    err = stringOPempty(T_2_1, &T_2_2);
    if (err != ERR_ok) goto ex_1;
    if (T_2_2.num == true) {

  LINE(12);
        {
        CLUREF T_3_1;
        T_3_1.num = _job_stuffOPinit.num ^ 1;
        if (T_3_1.num == true) {

  LINE(13);
            {
                {CLUREF T_5_1;
                err = _environ(STR_PATH, &T_5_1);
                if (err != ERR_ok) goto ex_2;
                s.num = T_5_1.num;
                }
                }
                goto end_2;
                ex_2:
                    __CLU_EX_HANDLER;
                    if ((err == ERR_not_found)) {

  LINE(14);
                        {
                        s = STR__072_057bin_072_057usr_057bin;
                        }
                    }
                    else {
                        goto ex_1;
                    }
                end_2:;

  LINE(15);
            {
            CLUREF T_4_1;
            err = arrayOPnew(&T_4_1);
            if (err != ERR_ok) goto ex_1;
            _job_stuffOPdirs.num = T_4_1.num;
            }

  LINE(16);
            {
                {j.num = 0;
                }
                }

  LINE(17);
            for (;;) {
                if (true != true) { break; }

  LINE(18);
                {
                    {CLUREF T_6_1;
                    T_6_1.num = j.num + 1;
                     if ((T_6_1.num > 0 && j.num < 0 && 1 < 0) ||
                         (T_6_1.num < 0 && j.num > 0 && 1 > 0)) {
                        err = ERR_overflow;
                        goto ex_3;}
                    i.num = T_6_1.num;
                    }
                    }

  LINE(19);
                {
                CLUREF T_6_1;
                CLUREF T_6_2;
                CLUREF T_6_3;
                T_6_1.ch = ':';
                T_6_2.num = (long)s.num;
                err = _bytevecOPindexc(T_6_1, T_6_2, i, &T_6_3);
                if (err != ERR_ok) goto ex_3;
                j.num = T_6_3.num;
                }

  LINE(22);
                {
                CLUREF T_6_1;
                T_6_1.num = (j.num == 0)? true : false;
                if (T_6_1.num == true) {

  LINE(23);
                    {
                    CLUREF T_7_1;
                    CLUREF T_7_2;
                    err = stringOPsize(s, &T_7_1);
                    if (err != ERR_ok) goto ex_3;
                    T_7_2.num = T_7_1.num + 1;
                     if ((T_7_2.num > 0 && T_7_1.num < 0 && 1 < 0) ||
                         (T_7_2.num < 0 && T_7_1.num > 0 && 1 > 0)) {
                        err = ERR_overflow;
                        goto ex_3;}
                    j.num = T_7_2.num;
                    }
                    }
                    }/* end if */

  LINE(24);
                {
                    {CLUREF T_6_1;
                    CLUREF T_6_2;
                    T_6_1.num = j.num - i.num;
                     if ((T_6_1.num >= 0 && j.num < 0 && (-i.num) < 0) ||
                         (T_6_1.num <= 0 && j.num > 0 && (-i.num) > 0)) {
                        err = ERR_overflow;
                        goto ex_3;}
                    err = stringOPsubstr(s, i, T_6_1, &T_6_2);
                    if (err != ERR_ok) goto ex_3;
                    ws.num = T_6_2.num;
                    }
                    }

  LINE(25);
                {
                CLUREF T_6_1;
                T_6_1.num = ((ws.str->size != STR__056.str->size)? false :
                    !(memcmp(ws.str->data, STR__056.str->data, ws.str->size)));
                if (T_6_1.num == true) {

  LINE(26);
                    {
                    ws = CLU_empty_string;
                    }
                    }
                else {

  LINE(27);
                    {
                    CLUREF T_7_1;
                    CLUREF T_7_2;
                    T_7_1.ch = '/';
                    err = stringOPappend(ws, T_7_1, &T_7_2);
                    if (err != ERR_ok) goto ex_3;
                    ws.num = T_7_2.num;
                    }
                    }}/* end if */

  LINE(29);
                {
                {
                if ((_job_stuffOPdirs.array->int_low + _job_stuffOPdirs.array->ext_size + 1) < _job_stuffOPdirs.array->int_size) {
                    _job_stuffOPdirs.array->store->data[_job_stuffOPdirs.array->int_low + _job_stuffOPdirs.array->ext_size] = ws.num;
                    _job_stuffOPdirs.array->ext_size++; _job_stuffOPdirs.array->ext_high++;}
                else {
                    err = arrayOPaddh(_job_stuffOPdirs, ws);
                    if (err != ERR_ok) goto ex_3;}
                }
                }
                }
                end_while_1:
                __CLU_END_LABEL;
                goto end_3;
                ex_3:
                    __CLU_EX_HANDLER;
                    if ((err == ERR_bounds)) {
                    }
                    else {
                        goto ex_1;
                    }
                end_3:;

  LINE(31);
            {
            _job_stuffOPinit.tf = true;
            }
            }
            }/* end if */

  LINE(33);
        {
        CLUREF T_4_1;
        CLUREF T_4_2;
        CLUREF T_4_3;
            T_4_2.num = _job_stuffOPdirs.array->ext_high;
            T_4_3 = _job_stuffOPdirs;
            for (T_4_1.num = _job_stuffOPdirs.array->ext_low; T_4_1.num <= T_4_2.num; T_4_1.num++) {
                if (T_4_1.num > T_4_3.array->ext_high || T_4_1.num < T_4_3.array->ext_low) {
                    err = ERR_failure;
                    elist[0] = array_bounds_exception_STRING;
                    goto ex_4;}
                s.num = T_4_3.array->store->data[T_4_1.num - T_4_3.array->ext_low + T_4_3.array->int_low];

  LINE(34);
                {
                CLUREF T_5_1;
                err = stringOPconcat(s, fs, &T_5_1);
                if (err != ERR_ok) goto ex_4;
                s.num = T_5_1.num;
                }

  LINE(35);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                CLUREF T_5_4;
                err = _file_access(s, CLU_1, &T_5_2);
                if (err != ERR_ok) goto ex_4;
                T_5_1.num = T_5_2.num;
                if (T_5_2.num) {
                    err = _file_exists(s, CLU_4, &T_5_3);
                    if (err != ERR_ok) goto ex_4;
                    T_5_4.num = T_5_3.num ^ 1;
                    T_5_1.num = T_5_4.num;
                }
                if (T_5_1.num == true) {

  LINE(36);
                    {
                    fs.num = s.num;
                    }

  LINE(37);
                    {
                        err = ERR_found;
                        goto ex_4;
                        }
                    }
                    }/* end if */
            }
        }
        end_inline_for_1:
        __CLU_END_LABEL;
        goto end_4;
        ex_4:
            __CLU_EX_HANDLER;
            if (err == ERR_not_possible) {signal(ERR_not_possible);}
            else {
                goto ex_1;}
        end_4:;

  LINE(40);
        {
        elist[0] = STR_no_040such_040executable_040file;
        {signal (ERR_not_possible);}}
        }
        }/* end if */
        goto end_1;
        ex_1:
            __CLU_EX_HANDLER;
            if ((err == ERR_found)) {
            }
            else {
                goto ex_0;
            }
        end_1:;

  LINE(42);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.ch = '\000';
    err = stringOPappend(fs, T_1_1, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    fs.num = T_1_2.num;
    }

  LINE(43);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        CLUREF T_1_3;
        CLUREF T_1_4;
        T_1_1.ch = '\000';
        err = stringOPappend(jcl, T_1_1, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        err = stringOPconcat(fs, T_1_2, &T_1_3);
        if (err != ERR_ok) goto ex_0;
        T_1_4.num = (long)T_1_3.str;
        b.num = T_1_4.num;
        }
        }

  LINE(44);
    {
        {chars = STR__040_011_000;
        }
        }

  LINE(45);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_1.ch = '\000';
    err = stringOPindexc(T_1_1, jcl, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    T_1_3.num = (T_1_2.num > 0)? true : false;
    if (T_1_3.num == true) {

  LINE(46);
        {
        chars = STR__000;
        }
        }
        }/* end if */

  LINE(47);
    {
        {cnt.num = 0;
        }
        }

  LINE(48);
    {
        {CLUREF T_1_1;
        err = stringOPsize(fs, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        i.num = T_1_1.num;
        }
        }

  LINE(49);
    for (;;) {
        if (true != true) { break; }

  LINE(50);
        {
        CLUREF T_3_1;
        T_3_1.num = cnt.num + 1;
         if ((T_3_1.num > 0 && cnt.num < 0 && 1 < 0) ||
             (T_3_1.num < 0 && cnt.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_5;}
        cnt.num = T_3_1.num;
        }

  LINE(51);
        for (;;) {
            CLUREF T_3_1;
            CLUREF T_3_2;
            CLUREF T_3_3;
            if (i.num < 1 || i.num > b.str->size ) {
                err = ERR_bounds;
                goto ex_5;}
            T_3_1.ch = b.str->data[i.num - 1];
            err = stringOPindexc(T_3_1, chars, &T_3_2);
            if (err != ERR_ok) goto ex_5;
            T_3_3.num = (T_3_2.num == 0)? true : false;
            if (T_3_3.num != true) { break; }

  LINE(52);
            {
            CLUREF T_4_1;
            T_4_1.num = i.num + 1;
             if ((T_4_1.num > 0 && i.num < 0 && 1 < 0) ||
                 (T_4_1.num < 0 && i.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_5;}
            i.num = T_4_1.num;
            }
            }
            end_while_3:
            __CLU_END_LABEL;

  LINE(54);
        for (;;) {
            CLUREF T_3_1;
            CLUREF T_3_2;
            CLUREF T_3_3;
            if (i.num < 1 || i.num > b.str->size ) {
                err = ERR_bounds;
                goto ex_5;}
            T_3_1.ch = b.str->data[i.num - 1];
            err = stringOPindexc(T_3_1, chars, &T_3_2);
            if (err != ERR_ok) goto ex_5;
            T_3_3.num = (T_3_2.num > 0)? true : false;
            if (T_3_3.num != true) { break; }

  LINE(55);
            {
            CLUREF T_4_1;
            T_4_1.ch = '\000';
            err = _bytevecOPstore(b, i, T_4_1);
            if (err != ERR_ok) goto ex_5;
            }

  LINE(56);
            {
            CLUREF T_4_1;
            T_4_1.num = i.num + 1;
             if ((T_4_1.num > 0 && i.num < 0 && 1 < 0) ||
                 (T_4_1.num < 0 && i.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_5;}
            i.num = T_4_1.num;
            }
            }
            end_while_4:
            __CLU_END_LABEL;
        }
        end_while_2:
        __CLU_END_LABEL;
        goto end_5;
        ex_5:
            __CLU_EX_HANDLER;
            if ((err == ERR_bounds)) {
            }
            else {
                goto ex_0;
            }
        end_5:;

  LINE(59);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = cnt.num + 2;
         if ((T_1_1.num > 0 && cnt.num < 0 && 2 < 0) ||
             (T_1_1.num < 0 && cnt.num > 0 && 2 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = _wordvecOPcreate(T_1_1, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        v.num = T_1_2.num;
        }
        }

  LINE(60);
    {
    err = _wordvecOPstore(v, CLU_1, cnt);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(61);
    {
    cnt.num = 1;
    }

  LINE(62);
    {
    i.num = 1;
    }

  LINE(63);
    for (;;) {
        if (true != true) { break; }

  LINE(64);
        {
        CLUREF T_3_1;
        T_3_1.num = cnt.num + 1;
         if ((T_3_1.num > 0 && cnt.num < 0 && 1 < 0) ||
             (T_3_1.num < 0 && cnt.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_6;}
        cnt.num = T_3_1.num;
        }

  LINE(65);
        {
        err = _wordvecOPstore(v, cnt, i);
        if (err != ERR_ok) goto ex_6;
        }

  LINE(66);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        T_3_1.ch = '\000';
        err = _bytevecOPindexc(T_3_1, b, i, &T_3_2);
        if (err != ERR_ok) goto ex_6;
        i.num = T_3_2.num;
        }

  LINE(67);
        for (;;) {
            CLUREF T_3_1;
            CLUREF T_3_2;
            CLUREF T_3_3;
            if (i.num < 1 || i.num > b.str->size ) {
                err = ERR_bounds;
                goto ex_6;}
            T_3_1.ch = b.str->data[i.num - 1];
            T_3_2.ch = '\000';
            T_3_3.num = (T_3_1.ch == T_3_2.ch)? true : false;
            if (T_3_3.num != true) { break; }

  LINE(68);
            {
            CLUREF T_4_1;
            T_4_1.num = i.num + 1;
             if ((T_4_1.num > 0 && i.num < 0 && 1 < 0) ||
                 (T_4_1.num < 0 && i.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_6;}
            i.num = T_4_1.num;
            }
            }
            end_while_6:
            __CLU_END_LABEL;
        }
        end_while_5:
        __CLU_END_LABEL;
        goto end_6;
        ex_6:
            __CLU_EX_HANDLER;
            if ((err == ERR_bounds)) {
            }
            else {
                goto ex_0;
            }
        end_6:;

  LINE(71);
    {
    {
    ret_1->num = v.num;
    }
    {
    ret_2->num = b.num;
    }
    {
    ret_3->num = fs.num;
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

/**** END PROCEDURE _job_stuff ****/

