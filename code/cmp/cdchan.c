
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN CLUSTER code_chan ****/

extern errcode stringOPequal();
extern errcode file_nameOPget_dir();
extern errcode file_nameOPget_name();
extern errcode _chanOPnul();
extern errcode _chanOPopen();
extern errcode _wordvecOPcreate();
extern errcode _chanOPget_name();
extern errcode recordOPget_3();
extern errcode recordOPset_3();
extern errcode intOPadd();
extern errcode intOPmul();
extern errcode intOPdiv();
extern errcode arrayOPsize();
extern errcode intOPequal();
extern errcode recordOPget_5();
extern errcode boolOPnot();
extern errcode recordOPget_4();
extern errcode _chanOPputw();
extern errcode recordOPget_1();
extern errcode recordOPget_6();
extern errcode recordOPset_4();
extern errcode recordOPset_7();
extern errcode recordOPset_5();
extern errcode _wordvecOPstore();
extern errcode code_chanOPboutput();
extern errcode code_chanOPoutput();
extern errcode _eventOPdefer();
extern errcode _advOPget_vector();
extern errcode _cvt();
extern errcode _advOPget_start();
extern errcode intOPgt();
extern errcode intOPmin();
extern errcode intOPsub();
extern errcode _bytevecOPmove_v();
extern errcode _eventOPundefer();
extern errcode intOPmod();
extern errcode _wordvecOPbstore();
extern errcode arrayOPempty();
extern errcode arrayOPlow();
extern errcode arrayOPhigh();
extern errcode intOPfrom_to_by();
extern errcode _wordvecOPstore2();
extern errcode arrayOPfetch();
extern errcode arrayOPtop();
extern errcode recordOPget_2();
extern errcode _chanOPabort();
extern errcode _chanOPclose();
extern errcode recordOPget_7();
extern errcode recordOPset_2();
extern struct REQS *_adv_of_t_reqs;
extern struct OPS *char_ops;
extern OWN_req _adv_ownreqs;
extern struct OPS *_adv_ops;
struct OPS *_adv_of_char_table;
struct OPS *_adv_of_char_ops;
struct OPS *_adv_of_char_ops;
OWNPTR _adv_of_char_owns;
CLUREF STR__057dev;
CLUREF STR_null;
CLUREF STR_random;
CLUREF STR_;
CLUREF STR_channel_040is_040closed;
static int code_chan_own_init = 0;
OWN_req code_chan_ownreqs = {0,0};
CLUREF code_chanOPisfree;
CLUREF code_chanOPfree;
errcode code_chan_own_init_proc()
{
    errcode err;
    enter_own_init_proc();
        if (code_chan_own_init == 0) {
        add_parm_info_type(0, char_ops, _adv_of_t_reqs);
        find_type_instance(_adv_ops, 1, &_adv_ownreqs, &(_adv_of_char_ops));
        stringOPcons("/dev", CLU_1, CLU_4, &STR__057dev);
        stringOPcons("null", CLU_1, CLU_4, &STR_null);
        stringOPcons("random", CLU_1, CLU_6, &STR_random);
        stringOPcons("", CLU_1, CLU_0, &STR_);
        stringOPcons("channel is closed", CLU_1, CLU_17, &STR_channel_040is_040closed);
        code_chan_own_init = 1;
        {
            {code_chanOPisfree.tf = false;
            }
            }
        {signal(ERR_ok);}
    ex_0: pclu_unhandled(err); {signal(ERR_failure);}
        }
    }

static int code_chanOPopen_own_init = 0;

/**** BEGIN PROCEDURE open ****/

errcode
code_chanOPopen(CLUREF fn, CLUREF *ret_1, CLUREF *ret_2)
    {
    errcode err;
    errcode ecode2;
    CLUREF c;
    CLUREF page;
        if (code_chanOPopen_own_init == 0) {
        if (code_chan_own_init == 0) {
            err = code_chan_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
        code_chanOPopen_own_init = 1;
    }
    enter_proc(26);

  LINE(28);
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    CLUREF T_2_3;
    CLUREF T_2_4;
    CLUREF T_2_5;
    err = file_nameOPget_dir(fn, &T_2_2);
    if (err != ERR_ok) goto ex_1;
    T_2_3.num = ((T_2_2.str->size != STR__057dev.str->size)? false :
        !(bcmp(T_2_2.str->data, STR__057dev.str->data, T_2_2.str->size)));
    T_2_1.num = T_2_3.num;
    if (T_2_3.num) {
        err = file_nameOPget_name(fn, &T_2_4);
        if (err != ERR_ok) goto ex_1;
        T_2_5.num = ((T_2_4.str->size != STR_null.str->size)? false :
            !(bcmp(T_2_4.str->data, STR_null.str->data, T_2_4.str->size)));
        T_2_1.num = T_2_5.num;
    }
    if (T_2_1.num == true) {

  LINE(29);
        {
        CLUREF T_3_1;
        err = _chanOPnul(&T_3_1);
        if (err != ERR_ok) goto ex_1;
        c.num = T_3_1.num;
        }
        }
    else {

  LINE(30);
        {
        CLUREF T_3_1;
        err = _chanOPopen(fn, STR_random, CLU_0, &T_3_1);
        if (err != ERR_ok) goto ex_1;
        c.num = T_3_1.num;
        }
        }}/* end if */
    goto end_1;
    ex_1:
        if (err == ERR_not_possible) {signal(ERR_not_possible);}
        else {
            goto ex_0;}
    end_1:;

  LINE(33);
    {
    if (code_chanOPisfree.num == true) {

  LINE(34);
        {
        page.num = code_chanOPfree.num;
        }

  LINE(35);
        {
        code_chanOPisfree.tf = false;
        }
        }
    else {

  LINE(36);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = 2048;
        err = _wordvecOPcreate(T_2_1, &T_2_2);
        if (err != ERR_ok) goto ex_0;
        page.num = T_2_2.num;
        }
        }}/* end if */

  LINE(38);
    {
    {
    CLUREF T_1_1;
    err = _chanOPget_name(c, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_1.num;
    }
    {
    CLUREF T_1_2;
    RecordAlloc(7, T_1_2);
    T_1_2.vec->data[0]  = c.num;
    T_1_2.vec->data[2]  = 0;
    T_1_2.vec->data[5]  = page.num;
    T_1_2.vec->data[4]  = 0;
    T_1_2.vec->data[1]  = false;
    T_1_2.vec->data[3]  = false;
    T_1_2.vec->data[6]  = STR_.num;
    ret_2->num = T_1_2.num;
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

/**** END PROCEDURE open ****/


/**** BEGIN PROCEDURE write ****/

errcode
code_chanOPwrite(CLUREF cc, CLUREF base, CLUREF code, CLUREF eblock, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
    CLUREF count;
    CLUREF why;
        if (code_chan_own_init == 0) {
            err = code_chan_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(48);

  LINE(49);
    {
        {CLUREF T_1_1;
        T_1_1.num = cc.vec->data[2];
        count.num = T_1_1.num;
        }
        }

  LINE(50);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    CLUREF T_1_6;
    CLUREF T_1_7;
    CLUREF T_1_8;
    CLUREF T_1_9;
    T_1_1.num = code.array->ext_size;
    T_1_2.num = T_1_1.num + 7;
     if ((T_1_2.num > 0 && T_1_1.num < 0 && 7 < 0) || 
         (T_1_2.num < 0 && T_1_1.num > 0 && 7 > 0)) {
        err = ERR_overflow;
        goto ex_0;}
    err = intOPdiv(T_1_2, CLU_4, &T_1_3);
    if (err != ERR_ok) goto ex_0;
    T_1_4.num = eblock.array->ext_size;
    T_1_5.num = T_1_4.num + 1;
     if ((T_1_5.num > 0 && T_1_4.num < 0 && 1 < 0) || 
         (T_1_5.num < 0 && T_1_4.num > 0 && 1 > 0)) {
        err = ERR_overflow;
        goto ex_0;}
    err = intOPdiv(T_1_5, CLU_2, &T_1_6);
    if (err != ERR_ok) goto ex_0;
    T_1_7.num = T_1_3.num + T_1_6.num;
     if ((T_1_7.num > 0 && T_1_3.num < 0 && T_1_6.num < 0) || 
         (T_1_7.num < 0 && T_1_3.num > 0 && T_1_6.num > 0)) {
        err = ERR_overflow;
        goto ex_0;}
    err = intOPmul(T_1_7, CLU_4, &T_1_8);
    if (err != ERR_ok) goto ex_0;
    T_1_9.num = count.num + T_1_8.num;
     if ((T_1_9.num > 0 && count.num < 0 && T_1_8.num < 0) || 
         (T_1_9.num < 0 && count.num > 0 && T_1_8.num > 0)) {
        err = ERR_overflow;
        goto ex_0;}
    cc.vec->data[2]  = T_1_9.num;
    }

  LINE(52);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_1.num = cc.vec->data[4];
    T_1_2.num = 2048;
    T_1_3.num = (T_1_1.num == T_1_2.num)? true : false;
    if (T_1_3.num == true) {

  LINE(53);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = cc.vec->data[3];
        T_2_2.num = T_2_1.num ^ 1;
        if (T_2_2.num == true) {

  LINE(54);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            T_4_1.num = cc.vec->data[0];
            T_4_2.num = cc.vec->data[5];
            T_4_3.num = 8192;
            err = _chanOPputw(T_4_1, T_4_2, CLU_1, T_4_3, CLU_0);
            if (err != ERR_ok) goto ex_1;
            }
                goto end_1;
                ex_1:
                    if ((err == ERR_not_possible)) {
                    CLUREF why;
                    why.num = elist[0].num;

  LINE(56);
                        {
                        cc.vec->data[3]  = true;
                        }

  LINE(57);
                        {
                        cc.vec->data[6]  = why.num;
                        }
                    }
                    else {
                        goto ex_0;
                    }
                end_1:;
            }
            }/* end if */

  LINE(60);
        {
        cc.vec->data[4]  = 0;
        }
        }
        }/* end if */

  LINE(62);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = cc.vec->data[4];
    T_1_2.num = T_1_1.num + 1;
     if ((T_1_2.num > 0 && T_1_1.num < 0 && 1 < 0) || 
         (T_1_2.num < 0 && T_1_1.num > 0 && 1 > 0)) {
        err = ERR_overflow;
        goto ex_0;}
    cc.vec->data[4]  = T_1_2.num;
    }

  LINE(63);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = cc.vec->data[5];
    T_1_2.num = cc.vec->data[4];
    err = _wordvecOPstore(T_1_1, T_1_2, base);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(64);
    {
    err = code_chanOPboutput(cc, code);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(65);
    {
    err = code_chanOPoutput(cc, eblock);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(66);
    {
    {
    ret_1->num = count.num;
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

/**** END PROCEDURE write ****/

struct OPS *_adv_of_char_table;
struct OPS *_adv_of_char_ops;
struct OPS *_adv_of_char_ops;
OWNPTR _adv_of_char_owns;
static int code_chanOPboutput_own_init = 0;

/**** BEGIN PROCEDURE boutput ****/

errcode
code_chanOPboutput(CLUREF cc, CLUREF block)
    {
    errcode err;
    errcode ecode2;
    CLUREF v;
    CLUREF i;
    CLUREF z;
    CLUREF p;
    CLUREF index;
    CLUREF why;
    CLUREF len;
        if (code_chanOPboutput_own_init == 0) {
        if (code_chan_own_init == 0) {
            err = code_chan_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
        code_chanOPboutput_own_init = 1;
    }
    enter_proc(69);

  LINE(70);
    {
    err = _eventOPdefer();
    if (err != ERR_ok) goto ex_0;
    }

  LINE(71);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = block.num;
        generic_CLU_proc.type_owns = _adv_of_char_ops->type_owns;
        generic_CLU_proc.proc = _advOPget_vector;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = _advOPget_vector(T_1_1, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        v.num = T_1_2.num;
        }
        }

  LINE(72);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = block.num;
        generic_CLU_proc.type_owns = _adv_of_char_ops->type_owns;
        generic_CLU_proc.proc = _advOPget_start;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = _advOPget_start(T_1_1, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        i.num = T_1_2.num;
        }
        }

  LINE(73);
    {
        {CLUREF T_1_1;
        T_1_1.num = block.array->ext_size;
        z.num = T_1_1.num;
        }
        }

  LINE(74);
    {
        {CLUREF T_1_1;
        T_1_1.num = cc.vec->data[5];
        p.num = T_1_1.num;
        }
        }

  LINE(75);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = cc.vec->data[4];
        err = intOPmul(T_1_1, CLU_4, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        index.num = T_1_2.num;
        }
        }

  LINE(76);
    for (;;) {
        CLUREF T_1_1;
        T_1_1.num = (z.num > 0)? true : false;
        if (T_1_1.num != true) { break; }

  LINE(77);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = 8192;
        T_2_2.num = (index.num == T_2_1.num)? true : false;
        if (T_2_2.num == true) {

  LINE(78);
            {
            CLUREF T_3_1;
            CLUREF T_3_2;
            T_3_1.num = cc.vec->data[3];
            T_3_2.num = T_3_1.num ^ 1;
            if (T_3_2.num == true) {

  LINE(79);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                T_5_1.num = cc.vec->data[0];
                T_5_2.num = 8192;
                err = _chanOPputw(T_5_1, p, CLU_1, T_5_2, CLU_0);
                if (err != ERR_ok) goto ex_1;
                }
                    goto end_1;
                    ex_1:
                        if ((err == ERR_not_possible)) {
                        CLUREF why;
                        why.num = elist[0].num;

  LINE(81);
                            {
                            cc.vec->data[3]  = true;
                            }

  LINE(82);
                            {
                            cc.vec->data[6]  = why.num;
                            }
                        }
                        else {
                            goto ex_0;
                        }
                    end_1:;
                }
                }/* end if */

  LINE(85);
            {
            index.num = 0;
            }
            }
            }/* end if */

  LINE(87);
        {
            {CLUREF T_2_1;
            CLUREF T_2_2;
            CLUREF T_2_3;
            T_2_1.num = 8192;
            T_2_2.num = T_2_1.num - index.num;
             if ((T_2_2.num >= 0 && T_2_1.num < 0 && (-index.num) < 0) || 
                 (T_2_2.num <= 0 && T_2_1.num > 0 && (-index.num) > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            err = intOPmin(z, T_2_2, &T_2_3);
            if (err != ERR_ok) goto ex_0;
            len.num = T_2_3.num;
            }
            }

  LINE(88);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = p.num;
        T_2_2.num = index.num + 1;
         if ((T_2_2.num > 0 && index.num < 0 && 1 < 0) || 
             (T_2_2.num < 0 && index.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = _bytevecOPmove_v(v, i, T_2_1, T_2_2, len);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(91);
        {
        CLUREF T_2_1;
        T_2_1.num = z.num - len.num;
         if ((T_2_1.num >= 0 && z.num < 0 && (-len.num) < 0) || 
             (T_2_1.num <= 0 && z.num > 0 && (-len.num) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        z.num = T_2_1.num;
        }

  LINE(92);
        {
        CLUREF T_2_1;
        T_2_1.num = index.num + len.num;
         if ((T_2_1.num > 0 && index.num < 0 && len.num < 0) || 
             (T_2_1.num < 0 && index.num > 0 && len.num > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        index.num = T_2_1.num;
        }

  LINE(93);
        {
        CLUREF T_2_1;
        T_2_1.num = i.num + len.num;
         if ((T_2_1.num > 0 && i.num < 0 && len.num < 0) || 
             (T_2_1.num < 0 && i.num > 0 && len.num > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        i.num = T_2_1.num;
        }
        }
        end_while_1:;

  LINE(95);
    {
    err = _eventOPundefer();
    if (err != ERR_ok) goto ex_0;
    }

  LINE(96);
    for (;;) {
        CLUREF T_1_1;
        CLUREF T_1_2;
        CLUREF T_1_3;
        err = intOPmod(index, CLU_4, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        T_1_2.num = (T_1_1.num == 0)? true : false;
        T_1_3.num = T_1_2.num ^ 1;
        if (T_1_3.num != true) { break; }

  LINE(97);
        {
        CLUREF T_2_1;
        T_2_1.num = index.num + 1;
         if ((T_2_1.num > 0 && index.num < 0 && 1 < 0) || 
             (T_2_1.num < 0 && index.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        index.num = T_2_1.num;
        }

  LINE(98);
        {
        err = _wordvecOPbstore(p, index, CLU_0);
        if (err != ERR_ok) goto ex_0;
        }
        }
        end_while_2:;

  LINE(100);
    {
    CLUREF T_1_1;
    err = intOPdiv(index, CLU_4, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    cc.vec->data[4]  = T_1_1.num;
    }
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
    }

/**** END PROCEDURE boutput ****/


/**** BEGIN PROCEDURE output ****/

errcode
code_chanOPoutput(CLUREF cc, CLUREF block)
    {
    errcode err;
    errcode ecode2;
    CLUREF p;
    CLUREF index;
    CLUREF low;
    CLUREF max;
    CLUREF why;
        if (code_chan_own_init == 0) {
            err = code_chan_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(103);

  LINE(104);
    {
    CLUREF T_1_1;
    T_1_1.num = (block.array->ext_size == 0)? true : false;
    if (T_1_1.num == true) {

  LINE(105);
        {
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(106);
    {
        {CLUREF T_1_1;
        T_1_1.num = cc.vec->data[5];
        p.num = T_1_1.num;
        }
        }

  LINE(107);
    {
        {CLUREF T_1_1;
        T_1_1.num = cc.vec->data[4];
        index.num = T_1_1.num;
        }
        }

  LINE(108);
    {
        {CLUREF T_1_1;
        T_1_1.num = block.array->ext_low;
        low.num = T_1_1.num;
        }
        }

  LINE(109);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = block.array->ext_high;
        T_1_2.num = T_1_1.num - 1;
         if ((T_1_2.num >= 0 && T_1_1.num < 0 && (-1) < 0) || 
             (T_1_2.num <= 0 && T_1_1.num > 0 && (-1) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        max.num = T_1_2.num;
        }
        }

  LINE(110);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
        T_1_2.num = max.num;
        T_1_3.num = 2;
        for (T_1_1.num = low.num; ((T_1_3.num == 0) || ((T_1_3.num > 0)? (T_1_1.num <= T_1_2.num) : (T_1_1.num >= T_1_2.num))); T_1_1.num += T_1_3.num) {
            low.num = T_1_1.num;

  LINE(111);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            T_2_1.num = 2048;
            T_2_2.num = (index.num == T_2_1.num)? true : false;
            if (T_2_2.num == true) {

  LINE(112);
                {
                CLUREF T_3_1;
                CLUREF T_3_2;
                T_3_1.num = cc.vec->data[3];
                T_3_2.num = T_3_1.num ^ 1;
                if (T_3_2.num == true) {

  LINE(113);
                    {
                    CLUREF T_5_1;
                    CLUREF T_5_2;
                    T_5_1.num = cc.vec->data[0];
                    T_5_2.num = 8192;
                    err = _chanOPputw(T_5_1, p, CLU_1, T_5_2, CLU_0);
                    if (err != ERR_ok) goto ex_1;
                    }
                        goto end_1;
                        ex_1:
                            if ((err == ERR_not_possible)) {
                            CLUREF why;
                            why.num = elist[0].num;

  LINE(115);
                                {
                                cc.vec->data[3]  = true;
                                }

  LINE(116);
                                {
                                cc.vec->data[6]  = why.num;
                                }
                            }
                            else {
                                goto ex_0;
                            }
                        end_1:;
                    }
                    }/* end if */

  LINE(119);
                {
                index.num = 0;
                }
                }
                }/* end if */

  LINE(121);
            {
            CLUREF T_2_1;
            T_2_1.num = index.num + 1;
             if ((T_2_1.num > 0 && index.num < 0 && 1 < 0) || 
                 (T_2_1.num < 0 && index.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            index.num = T_2_1.num;
            }

  LINE(122);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            CLUREF T_2_3;
            T_2_1.num = low.num + 1;
             if ((T_2_1.num > 0 && low.num < 0 && 1 < 0) || 
                 (T_2_1.num < 0 && low.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            if (T_2_1.num < block.array->ext_low || T_2_1.num > block.array->ext_high ) {
                err = ERR_bounds;
                goto ex_0;}
            T_2_2.num = block.array->store->data[T_2_1.num - block.array->ext_low + block.array->int_low];
            if (low.num < block.array->ext_low || low.num > block.array->ext_high ) {
                err = ERR_bounds;
                goto ex_0;}
            T_2_3.num = block.array->store->data[low.num - block.array->ext_low + block.array->int_low];
            err = _wordvecOPstore2(p, index, T_2_2, T_2_3);
            if (err != ERR_ok) goto ex_0;
            }
        }
    }
    end_inline_for_1:;

  LINE(124);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = (low.num == max.num)? true : false;
    T_1_2.num = T_1_1.num ^ 1;
    if (T_1_2.num == true) {

  LINE(125);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = 2048;
        T_2_2.num = (index.num == T_2_1.num)? true : false;
        if (T_2_2.num == true) {

  LINE(126);
            {
            CLUREF T_3_1;
            CLUREF T_3_2;
            T_3_1.num = cc.vec->data[3];
            T_3_2.num = T_3_1.num ^ 1;
            if (T_3_2.num == true) {

  LINE(127);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                T_5_1.num = cc.vec->data[0];
                T_5_2.num = 8192;
                err = _chanOPputw(T_5_1, p, CLU_1, T_5_2, CLU_0);
                if (err != ERR_ok) goto ex_2;
                }
                    goto end_2;
                    ex_2:
                        if ((err == ERR_not_possible)) {
                        CLUREF why;
                        why.num = elist[0].num;

  LINE(129);
                            {
                            cc.vec->data[3]  = true;
                            }

  LINE(130);
                            {
                            cc.vec->data[6]  = why.num;
                            }
                        }
                        else {
                            goto ex_0;
                        }
                    end_2:;
                }
                }/* end if */

  LINE(133);
            {
            index.num = 0;
            }
            }
            }/* end if */

  LINE(135);
        {
        CLUREF T_2_1;
        T_2_1.num = index.num + 1;
         if ((T_2_1.num > 0 && index.num < 0 && 1 < 0) || 
             (T_2_1.num < 0 && index.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        index.num = T_2_1.num;
        }

  LINE(136);
        {
        CLUREF T_2_1;
        err = arrayOPtop(block, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        err = _wordvecOPstore2(p, index, CLU_0, T_2_1);
        if (err != ERR_ok) goto ex_0;
        }
        }
        }/* end if */

  LINE(138);
    {
    cc.vec->data[4]  = index.num;
    }
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
    }

/**** END PROCEDURE output ****/


/**** BEGIN PROCEDURE get_chan ****/

errcode
code_chanOPget_chan(CLUREF cc, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
    CLUREF why;
        if (code_chan_own_init == 0) {
            err = code_chan_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(141);

  LINE(142);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = cc.vec->data[4];
    T_1_2.num = (T_1_1.num > 0)? true : false;
    if (T_1_2.num == true) {

  LINE(143);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = cc.vec->data[3];
        T_2_2.num = T_2_1.num ^ 1;
        if (T_2_2.num == true) {

  LINE(144);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            CLUREF T_4_4;
            T_4_1.num = cc.vec->data[0];
            T_4_2.num = cc.vec->data[5];
            T_4_3.num = cc.vec->data[4];
            err = intOPmul(CLU_4, T_4_3, &T_4_4);
            if (err != ERR_ok) goto ex_1;
            err = _chanOPputw(T_4_1, T_4_2, CLU_1, T_4_4, CLU_0);
            if (err != ERR_ok) goto ex_1;
            }
                goto end_1;
                ex_1:
                    if ((err == ERR_not_possible)) {
                    CLUREF why;
                    why.num = elist[0].num;

  LINE(146);
                        {
                        cc.vec->data[3]  = true;
                        }

  LINE(147);
                        {
                        cc.vec->data[6]  = why.num;
                        }
                    }
                    else {
                        goto ex_0;
                    }
                end_1:;
            }
            }/* end if */

  LINE(150);
        {
        cc.vec->data[4]  = 0;
        }
        }
        }/* end if */

  LINE(152);
    {
    {
    CLUREF T_1_1;
    T_1_1.num = cc.vec->data[0];
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
    end_0: elist[0] = no_return_values_STRING;
        {signal(ERR_failure);}
    }

/**** END PROCEDURE get_chan ****/


/**** BEGIN PROCEDURE size ****/

errcode
code_chanOPsize(CLUREF cc, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (code_chan_own_init == 0) {
            err = code_chan_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(155);

  LINE(156);
    {
    {
    CLUREF T_1_1;
    T_1_1.num = cc.vec->data[2];
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
    end_0: elist[0] = no_return_values_STRING;
        {signal(ERR_failure);}
    }

/**** END PROCEDURE size ****/

static int code_chanOPclose_own_init = 0;

/**** BEGIN PROCEDURE close ****/

errcode
code_chanOPclose(CLUREF cc)
    {
    errcode err;
    errcode ecode2;
    CLUREF why;
        if (code_chanOPclose_own_init == 0) {
        if (code_chan_own_init == 0) {
            err = code_chan_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
        code_chanOPclose_own_init = 1;
    }
    enter_proc(159);

  LINE(160);
    {
    CLUREF T_1_1;
    T_1_1.num = cc.vec->data[1];
    if (T_1_1.num == true) {

  LINE(161);
        {
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(162);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    T_1_2.num = cc.vec->data[4];
    T_1_3.num = (T_1_2.num > 0)? true : false;
    T_1_1.num = T_1_3.num;
    if (T_1_3.num) {
        T_1_4.num = cc.vec->data[3];
        T_1_5.num = T_1_4.num ^ 1;
        T_1_1.num = T_1_5.num;
    }
    if (T_1_1.num == true) {

  LINE(163);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        CLUREF T_3_3;
        CLUREF T_3_4;
        T_3_1.num = cc.vec->data[0];
        T_3_2.num = cc.vec->data[5];
        T_3_3.num = cc.vec->data[4];
        err = intOPmul(CLU_4, T_3_3, &T_3_4);
        if (err != ERR_ok) goto ex_1;
        err = _chanOPputw(T_3_1, T_3_2, CLU_1, T_3_4, CLU_0);
        if (err != ERR_ok) goto ex_1;
        }
            goto end_1;
            ex_1:
                if ((err == ERR_not_possible)) {
                CLUREF why;
                why.num = elist[0].num;

  LINE(165);
                    {
                    cc.vec->data[3]  = true;
                    }

  LINE(166);
                    {
                    cc.vec->data[6]  = why.num;
                    }
                }
                else {
                    goto ex_0;
                }
            end_1:;
        }
        }/* end if */

  LINE(169);
    {
    CLUREF T_2_1;
    T_2_1.num = cc.vec->data[3];
    if (T_2_1.num == true) {

  LINE(170);
        {
        CLUREF T_3_1;
        T_3_1.num = cc.vec->data[0];
        err = _chanOPabort(T_3_1);
        if (err != ERR_ok) goto ex_2;
        }
        }
    else {

  LINE(171);
        {
        CLUREF T_3_1;
        T_3_1.num = cc.vec->data[0];
        err = _chanOPclose(T_3_1);
        if (err != ERR_ok) goto ex_2;
        }
        }}/* end if */
        goto end_2;
        ex_2:
            if ((err == ERR_not_possible)) {
            CLUREF why;
            why.num = elist[0].num;

  LINE(173);
                {
                CLUREF T_2_1;
                CLUREF T_2_2;
                T_2_1.num = cc.vec->data[3];
                T_2_2.num = T_2_1.num ^ 1;
                if (T_2_2.num == true) {

  LINE(174);
                    {
                    cc.vec->data[3]  = true;
                    }

  LINE(175);
                    {
                    cc.vec->data[6]  = why.num;
                    }
                    }
                    }/* end if */
            }
            else if ((err == ERR_permanent)) {
            }
            else {
                goto ex_0;
            }
        end_2:;

  LINE(179);
    {
        {CLUREF T_1_1;
        T_1_1.num = cc.vec->data[6];
        why.num = T_1_1.num;
        }
        }

  LINE(180);
    {
    cc.vec->data[6]  = STR_channel_040is_040closed.num;
    }

  LINE(181);
    {
    cc.vec->data[1]  = true;
    }

  LINE(182);
    {
    CLUREF T_1_1;
    T_1_1.num = cc.vec->data[5];
    code_chanOPfree.num = T_1_1.num;
    }

  LINE(183);
    {
    code_chanOPisfree.tf = true;
    }

  LINE(184);
    {
    CLUREF T_1_1;
    T_1_1.num = cc.vec->data[3];
    if (T_1_1.num == true) {

  LINE(185);
        {
        elist[0] = why;
        {signal (ERR_not_possible);}}
        }
    else {

  LINE(186);
        {
        cc.vec->data[3]  = true;
        }
        }}/* end if */
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
    }

/**** END PROCEDURE close ****/

typedef struct{
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[5];
} code_chan_OPS;

CLU_proc code_chan_oe_close = {{0,0,0,0}, code_chanOPclose, 0};
CLU_proc code_chan_oe_get_chan = {{0,0,0,0}, code_chanOPget_chan, 0};
CLU_proc code_chan_oe_open = {{0,0,0,0}, code_chanOPopen, 0};
CLU_proc code_chan_oe_size = {{0,0,0,0}, code_chanOPsize, 0};
CLU_proc code_chan_oe_write = {{0,0,0,0}, code_chanOPwrite, 0};

code_chan_OPS code_chan_ops_actual = {5, (OWNPTR)&code_chan_own_init, (OWNPTR)&code_chan_own_init, {
    {&code_chan_oe_close, "close"},
    {&code_chan_oe_get_chan, "get_chan"},
    {&code_chan_oe_open, "open"},
    {&code_chan_oe_size, "size"},
    {&code_chan_oe_write, "write"}}};

struct OPS *code_chan_ops = (struct OPS *)&code_chan_ops_actual;

/**** END CLUSTER code_chan ****/
