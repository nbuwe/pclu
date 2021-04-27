
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode arrayOPnew();
extern errcode intOPequal();
extern errcode stringOPindexc();
extern errcode file_name_fill();
extern errcode file_nameOPparse();
extern errcode _restar();
extern errcode file_exists();
extern errcode stringOPequal();
extern errcode file_nameOPunparse();
extern errcode _fixup_file_name();
extern errcode _last_indexc();
extern errcode stringOPrest();
extern errcode intOPadd();
extern errcode intOPgt();
extern errcode charOPequal();
extern errcode stringOPfetch();
extern errcode intOPsub();
extern errcode stringOPsubstr();
extern errcode _split_name_part();
extern errcode _environ();
extern errcode _home_dir();
extern errcode _all_file_names_();
extern errcode file_nameOPcreate();
extern errcode arrayOPtrim();
extern errcode _all_dir_entries_();
extern errcode _match_name_spec();
extern errcode _cvt();
extern errcode arrayOPindexes();
extern errcode stringOPlt();
extern errcode arrayOPfetch();
extern errcode arrayOPstore();
extern errcode arrayOPaddh();
extern errcode arrayOPelements();
extern errcode boolOPnot();
extern errcode _all_file_names__IB_1();
extern errcode _all_file_names__IB_2();
CLUREF STR_;
CLUREF STR_HOME;
static int _all_file_names__own_init = 0;
CLUREF _all_file_names_OPinuse;
CLUREF _all_file_names_OPtemp;

/**** BEGIN ITERATOR _all_file_names_ ****/

errcode
_all_file_names_(CLUREF fs, errcode (*proc)(), char **user_locals, errcode *iecode)
    {
    errcode ecode;
    struct {
        char **user_locals;
        errcode (*proc)();
        errcode err;
        errcode ecode2;
        bool body_ctrl_req;
        CLUREF fn;
        CLUREF dr;
        CLUREF z;
        CLUREF nm;
        CLUREF sf;
        CLUREF ot;
        CLUREF ok;
        CLUREF list;
        CLUREF used;
        CLUREF off;
        CLUREF buf;
        CLUREF fs;
        } locals;
    locals.fs = fs;
    locals.proc = proc;
    locals.user_locals = user_locals;
    locals.user_locals = user_locals;
    locals.proc = proc;
        if (_all_file_names__own_init == 0) {
        stringOPcons("", CLU_1, CLU_0, &STR_);
        stringOPcons("HOME", CLU_1, CLU_4, &STR_HOME);
        _all_file_names__own_init = 1;
        {
            {_all_file_names_OPinuse.tf = false;
            }
            }
        {
            {CLUREF T_0_1;
            locals.err = arrayOPnew(&T_0_1);
            if (locals.err != ERR_ok) goto ex_0;
            _all_file_names_OPtemp.num = T_0_1.num;
            }
            }
    }
    enter_proc(6);

  LINE(13);
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    CLUREF T_2_3;
    T_2_1.ch = '*';
    locals.err = stringOPindexc(T_2_1, locals.fs, &T_2_2);
    if (locals.err != ERR_ok) goto ex_1;
    T_2_3.num = (T_2_2.num == 0)? true : false;
    if (T_2_3.num == true) {

  LINE(14);
        {
            {CLUREF T_3_1;
            CLUREF T_3_2;
            CLUREF T_3_3;
            locals.err = _restar(locals.fs, &T_3_1);
            if (locals.err != ERR_ok) goto ex_1;
            locals.err = file_nameOPparse(T_3_1, &T_3_2);
            if (locals.err != ERR_ok) goto ex_1;
            locals.err = file_name_fill(T_3_2, STR_, &T_3_3);
            if (locals.err != ERR_ok) goto ex_1;
            locals.fn.num = T_3_3.num;
            }
            }

  LINE(17);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        CLUREF T_3_3;
        CLUREF T_3_4;
        locals.err = file_exists(locals.fn, &T_3_2);
        if (locals.err != ERR_ok) goto ex_1;
        T_3_1.num = T_3_2.num;
        if (!T_3_2.num) {
            locals.err = file_nameOPunparse(locals.fn, &T_3_3);
            if (locals.err != ERR_ok) goto ex_1;
            T_3_4.num = ((T_3_3.str->size != STR_.str->size)? false :
                !(bcmp(T_3_3.str->data, STR_.str->data, T_3_3.str->size)));
            T_3_1.num = T_3_4.num;
        }
        if (T_3_1.num == true) {

  LINE(18);
            {
            CLUREF T_4_1;
            locals.err = _fixup_file_name(locals.fn, CLU_0, &T_4_1);
            if (locals.err != ERR_ok) goto ex_1;
            locals.err = locals.proc(T_4_1, locals.user_locals, iecode);
            if (locals.err != ERR_ok) {
            if (locals.err == ERR_break) {signal(ERR_break);}
            if (locals.err == ERR_iterbodyreturn) {signal(ERR_iterbodyreturn);}
            if (locals.err == ERR_iterbodyexit) {signal(ERR_iterbodyexit);}
            if (locals.err == ERR_iterbodysignal) {signal(ERR_iterbodysignal);}
            {signal(locals.err);
                }}
            }
            }
            }/* end if */

  LINE(19);
        {
        {signal (ERR_ok);}}
        }
        }/* end if */
    goto end_1;
    ex_1:
        if (locals.err == ERR_bad_format) {signal(ERR_bad_format);}
        else if (locals.err == ERR_not_possible) {signal(ERR_not_possible);}
        else {
            goto ex_0;}
    end_1:;

  LINE(21);
    {
        {locals.dr.num = locals.fs.num;
        }
        }

  LINE(22);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.ch = '/';
        locals.err = _last_indexc(T_1_1, locals.fs, &T_1_2);
        if (locals.err != ERR_ok) goto ex_0;
        locals.z.num = T_1_2.num;
        }
        }

  LINE(23);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = locals.z.num + 1;
     if ((T_1_1.num > 0 && locals.z.num < 0 && 1 < 0) ||
         (T_1_1.num < 0 && locals.z.num > 0 && 1 > 0)) {
        locals.err = ERR_overflow;
        goto ex_0;}
    locals.err = stringOPrest(locals.fs, T_1_1, &T_1_2);
    if (locals.err != ERR_ok) goto ex_0;
    locals.fs.num = T_1_2.num;
    }

  LINE(24);
    for (;;) {
        CLUREF T_1_1;
        CLUREF T_1_2;
        CLUREF T_1_3;
        CLUREF T_1_4;
        CLUREF T_1_5;
        T_1_2.num = (locals.z.num > 1)? true : false;
        T_1_1.num = T_1_2.num;
        if (T_1_2.num) {
            locals.err = stringOPfetch(locals.dr, locals.z, &T_1_3);
            if (locals.err != ERR_ok) goto ex_0;
            T_1_4.ch = '/';
            T_1_5.num = (T_1_3.ch == T_1_4.ch)? true : false;
            T_1_1.num = T_1_5.num;
        }
        if (T_1_1.num != true) { break; }

  LINE(25);
        {
        CLUREF T_2_1;
        T_2_1.num = locals.z.num - 1;
         if ((T_2_1.num >= 0 && locals.z.num < 0 && (-1) < 0) ||
             (T_2_1.num <= 0 && locals.z.num > 0 && (-1) > 0)) {
            locals.err = ERR_overflow;
            goto ex_0;}
        locals.z.num = T_2_1.num;
        }
        }
        end_while_1:;

  LINE(27);
    {
    CLUREF T_1_1;
    locals.err = stringOPsubstr(locals.dr, CLU_1, locals.z, &T_1_1);
    if (locals.err != ERR_ok) goto ex_0;
    locals.dr.num = T_1_1.num;
    }

  LINE(30);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_1.ch = '*';
    locals.err = stringOPindexc(T_1_1, locals.fs, &T_1_2);
    if (locals.err != ERR_ok) goto ex_0;
    T_1_3.num = (T_1_2.num == 0)? true : false;
    if (T_1_3.num == true) {

  LINE(31);
        {
        locals.ok.tf = true;
        }

  LINE(32);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        CLUREF T_2_4;
        locals.err = _restar(locals.fs, &T_2_1);
        if (locals.err != ERR_ok) goto ex_0;
        locals.err = _split_name_part(T_2_1, &T_2_2, &T_2_3, &T_2_4);
        if (locals.err != ERR_ok) goto ex_0;
        locals.nm.num = T_2_2.num;
        locals.sf.num = T_2_3.num;
        locals.ot.num = T_2_4.num;
        }
        }
    else {

  LINE(33);
        {
        locals.ok.tf = false;
        }
        }}/* end if */

  LINE(35);
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    CLUREF T_2_3;
    CLUREF T_2_4;
    CLUREF T_2_5;
    CLUREF T_2_6;
    CLUREF T_2_7;
    locals.err = stringOPfetch(locals.dr, CLU_1, &T_2_2);
    if (locals.err != ERR_ok) goto ex_2;
    T_2_3.ch = '~';
    T_2_4.num = (T_2_2.ch == T_2_3.ch)? true : false;
    T_2_1.num = T_2_4.num;
    if (T_2_4.num) {
        T_2_5.ch = '/';
        locals.err = stringOPindexc(T_2_5, locals.dr, &T_2_6);
        if (locals.err != ERR_ok) goto ex_2;
        T_2_7.num = (T_2_6.num == 0)? true : false;
        T_2_1.num = T_2_7.num;
    }
    if (T_2_1.num == true) {

  LINE(36);
        {
        CLUREF T_3_1;
        T_3_1.num = (locals.z.num == 1)? true : false;
        if (T_3_1.num == true) {

  LINE(37);
            {
            CLUREF T_4_1;
            locals.err = _environ(STR_HOME, &T_4_1);
            if (locals.err != ERR_ok) goto ex_2;
            locals.dr.num = T_4_1.num;
            }
            }
        else {

  LINE(38);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            locals.err = stringOPrest(locals.dr, CLU_2, &T_4_1);
            if (locals.err != ERR_ok) goto ex_2;
            locals.err = _home_dir(T_4_1, &T_4_2);
            if (locals.err != ERR_ok) goto ex_2;
            locals.dr.num = T_4_2.num;
            }
            }}/* end if */
        }
        }/* end if */
        goto end_2;
        ex_2:
            if ((locals.err == ERR_bounds)
             || (locals.err == ERR_not_found)) {
            }
            else {
                goto ex_0;
            }
        end_2:;

  LINE(41);
    {
        locals.body_ctrl_req = false;
        locals.err = _all_file_names_(locals.dr, _all_file_names__IB_1, &locals, &locals.ecode2);
        if (locals.err == ERR_iterbodyreturn) {signal(ERR_iterbodyreturn);}
        if (locals.err == ERR_iterbodysignal) {
            *iecode = locals.ecode2; signal(ERR_iterbodysignal);}
        if (locals.err == ERR_iterbodyexit) {
            *iecode = locals.ecode2; signal(ERR_iterbodyexit);}
        if (locals.body_ctrl_req == true) {
            locals.body_ctrl_req = false;
            if (locals.err == ERR_iteriterbodyreturn) {signal(ERR_ok);}
            if (locals.err == ERR_iteriterbodysignal) {signal(locals.ecode2);}
            if (locals.err == ERR_break) locals.err = ERR_ok;
            if (locals.err == ERR_iteriterbodyexit) locals.err = locals.ecode2;
            }
        else {
            if (locals.err == ERR_iteriterbodyreturn) {signal(ERR_iteriterbodyreturn);}
            if (locals.err == ERR_break) {signal(ERR_break);}
            if (locals.err == ERR_iteriterbodysignal) {
                  *iecode = locals.ecode2; signal(ERR_iteriterbodysignal);}
            if (locals.err == ERR_iteriterbodyexit) {
                  *iecode = locals.ecode2; signal(ERR_iteriterbodyexit);}}
        if (locals.err != ERR_ok) goto ex_3;
        }
    goto end_3;
    ex_3:
        if (locals.err == ERR_not_possible) {signal(ERR_not_possible);}
        else if (locals.err == ERR_bad_format) {signal(ERR_bad_format);}
        else {
            goto ex_0;}
    end_3:;
    goto end_0;
    ex_0:
        {
            if (locals.err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(locals.err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
    }

/**** END ITERATOR _all_file_names_ ****/


/**** BEGIN ITERATOR BODIES for _all_file_names_ ****/

errcode _all_file_names__IB_1(iv_1, locals, iecode)
errcode *iecode;
CLUREF iv_1;
struct {
    char **user_locals;
    errcode (*proc)();
    errcode err;
    errcode ecode2;
    bool body_ctrl_req;
    CLUREF fn;
    CLUREF dr;
    CLUREF z;
    CLUREF nm;
    CLUREF sf;
    CLUREF ot;
    CLUREF ok;
    CLUREF list;
    CLUREF used;
    CLUREF off;
    CLUREF buf;
    CLUREF fs;
    } *locals;
{
    locals->fn.num = iv_1.num;
    enter_iter_body_proc(42);

  FB_LINE(42);
    {
    CLUREF T_1_1;
    locals->err = file_nameOPunparse(locals->fn, &T_1_1);
    if (locals->err != ERR_ok) goto ex_0;
    locals->dr.num = T_1_1.num;
    }

  FB_LINE(43);
    {
    if (locals->ok.num == true) {

  FB_LINE(44);
        {
        CLUREF T_2_1;
        locals->err = file_nameOPcreate(locals->dr, locals->nm, locals->sf, locals->ot, &T_2_1);
        if (locals->err != ERR_ok) goto ex_0;
        locals->fn.num = T_2_1.num;
        }

  FB_LINE(45);
        {
        CLUREF T_3_1;
        locals->err = file_exists(locals->fn, &T_3_1);
        if (locals->err != ERR_ok) goto ex_1;
        if (T_3_1.num == true) {

  FB_LINE(46);
            {
            CLUREF T_4_1;
            locals->err = _fixup_file_name(locals->fn, CLU_1, &T_4_1);
            if (locals->err != ERR_ok) goto ex_1;
            locals->err = locals->proc(T_4_1, locals->user_locals, iecode);
            if ((locals->body_ctrl_req == true) && (locals->err == ERR_iteriterbodyexit)) {
                locals->err = *iecode;
                goto ex_1;}
            if (locals->err != ERR_ok) {
            signal(locals->err);
            }
            }
            }
            }/* end if */
            goto end_1;
            ex_1:
                if ((locals->err == ERR_not_possible)) {
                }
                else {
                    goto ex_0;
                }
            end_1:;

  FB_LINE(48);
        {signal(ERR_ok);}
        }
        }/* end if */

  FB_LINE(51);
    {
        {locals->used.num = _all_file_names_OPinuse.num;
        }
        }

  FB_LINE(52);
    {
    if (locals->used.num == true) {

  FB_LINE(53);
        {
        CLUREF T_2_1;
        locals->err = arrayOPnew(&T_2_1);
        if (locals->err != ERR_ok) goto ex_0;
        locals->list.num = T_2_1.num;
        }
        }
    else {

  FB_LINE(54);
        {
        locals->list.num = _all_file_names_OPtemp.num;
        }

  FB_LINE(55);
        {
        locals->err = arrayOPtrim(locals->list, CLU_1, CLU_0);
        if (locals->err != ERR_ok) goto ex_0;
        }

  FB_LINE(56);
        {
        _all_file_names_OPinuse.tf = true;
        }
        }}/* end if */

  FB_LINE(58);
    {
        locals->body_ctrl_req = false;
        locals->err = _all_dir_entries_(locals->dr, _all_file_names__IB_2, locals, iecode);
        if (locals->err != ERR_ok) {
        if (locals->err == ERR_iterbodyreturn) {signal(ERR_iterbodyreturn);}
        if (locals->err == ERR_iterbodysignal) {signal(ERR_iterbodysignal);}
        if (locals->err == ERR_iterbodyexit) {signal(ERR_iterbodyexit);}
        if (locals->err == ERR_iteriterbodyreturn) {signal(ERR_iteriterbodyreturn);}
        if (locals->err == ERR_iteriterbodysignal) {signal(ERR_iteriterbodysignal);}
        if (locals->err == ERR_break && !locals->body_ctrl_req) {signal(ERR_break);}
        if (locals->err == ERR_iteriterbodyexit && !locals->body_ctrl_req) {signal(ERR_iteriterbodyexit);}
        if (locals->err == ERR_break) locals->err = ERR_ok;
        if (locals->err == ERR_iteriterbodyexit) 
        locals->err = *iecode;
        if (locals->err != ERR_ok) 
        goto ex_0;
        }
        }

  FB_LINE(75);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
        T_1_2.num = locals->list.array->ext_high;
        T_1_3 = locals->list;
        for (T_1_1.num = locals->list.array->ext_low; T_1_1.num <= T_1_2.num; T_1_1.num++) {
            if (T_1_1.num > T_1_3.array->ext_high || T_1_1.num < T_1_3.array->ext_low) {
                locals->err = ERR_failure;
                elist[0] = array_bounds_exception_STRING;
                goto ex_0;}
            locals->nm.num = T_1_3.array->store->data[T_1_1.num - T_1_3.array->ext_low + T_1_3.array->int_low];

  FB_LINE(76);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            CLUREF T_2_3;
            locals->err = _split_name_part(locals->nm, &T_2_1, &T_2_2, &T_2_3);
            if (locals->err != ERR_ok) goto ex_0;
            locals->nm.num = T_2_1.num;
            locals->sf.num = T_2_2.num;
            locals->ot.num = T_2_3.num;
            }

  FB_LINE(77);
            {
            CLUREF T_2_1;
            locals->err = file_nameOPcreate(locals->dr, locals->nm, locals->sf, locals->ot, &T_2_1);
            if (locals->err != ERR_ok) goto ex_0;
            locals->err = locals->proc(T_2_1, locals->user_locals, iecode);
            if ((locals->body_ctrl_req == true) && (locals->err == ERR_iteriterbodyexit)) {
                locals->err = *iecode;
                goto ex_0;}
            if (locals->err != ERR_ok) {
            signal(locals->err);
            }
            }
        }
    }
    end_inline_for_1:;

  FB_LINE(79);
    {
    _all_file_names_OPinuse.num = locals->used.num;
    }

  FB_LINE(80);
    {
    CLUREF T_1_1;
    T_1_1.num = _all_file_names_OPinuse.num ^ 1;
    if (T_1_1.num == true) {

  FB_LINE(81);
        {
        locals->err = arrayOPtrim(locals->list, CLU_1, CLU_0);
        if (locals->err != ERR_ok) goto ex_0;
        }
        }
        }/* end if */
    {signal(ERR_ok);}
    ex_0:
        {
            *iecode = locals->err;
            locals->body_ctrl_req = true;
            {signal(ERR_iteriterbodyexit);}}
    end_0: {signal(ERR_ok);}
    }/* end _all_file_names__IB_1 */
errcode _all_file_names__IB_2(iv_1, iv_2, locals, iecode)
errcode *iecode;
CLUREF iv_1;
CLUREF iv_2;
struct {
    char **user_locals;
    errcode (*proc)();
    errcode err;
    errcode ecode2;
    bool body_ctrl_req;
    CLUREF fn;
    CLUREF dr;
    CLUREF z;
    CLUREF nm;
    CLUREF sf;
    CLUREF ot;
    CLUREF ok;
    CLUREF list;
    CLUREF used;
    CLUREF off;
    CLUREF buf;
    CLUREF fs;
    } *locals;
{
    locals->off.num = iv_1.num;
    locals->buf.num = iv_2.num;
    enter_iter_body_proc(59);

  FB_LINE(59);
    {
    CLUREF T_1_1;
    locals->err = _match_name_spec(locals->off, locals->buf, locals->fs, &T_1_1);
    if (locals->err != ERR_ok) goto ex_0;
    locals->z.num = T_1_1.num;
    }

  FB_LINE(60);
    {
    CLUREF T_1_1;
    T_1_1.num = (locals->z.num == 0)? true : false;
    if (T_1_1.num == true) {

  FB_LINE(61);
        {signal(ERR_ok);}
        }
        }/* end if */

  FB_LINE(62);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = locals->buf.num;
    locals->err = stringOPsubstr(T_1_1, locals->off, locals->z, &T_1_2);
    if (locals->err != ERR_ok) goto ex_0;
    locals->nm.num = T_1_2.num;
    }

  FB_LINE(63);
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
        T_2_2.num = locals->list.array->ext_high;
        for (T_2_1.num = locals->list.array->ext_low; T_2_1.num <= T_2_2.num; T_2_1.num++) {
            locals->z.num = T_2_1.num;

  FB_LINE(64);
            {
            CLUREF T_3_1;
            CLUREF T_3_2;
            if (locals->z.num < locals->list.array->ext_low || locals->z.num > locals->list.array->ext_high ) {
                locals->err = ERR_bounds;
                goto ex_1;}
            T_3_1.num = locals->list.array->store->data[locals->z.num - locals->list.array->ext_low + locals->list.array->int_low];
            locals->err = stringOPlt(T_3_1, locals->nm, &T_3_2);
            if (locals->err != ERR_ok) goto ex_1;
            if (T_3_2.num == true) {

  FB_LINE(65);
                continue;
                }
                }/* end if */

  FB_LINE(66);
            for (;;) {
                if (true != true) { break; }

  FB_LINE(67);
                {
                CLUREF T_4_1;
                if (locals->z.num < locals->list.array->ext_low || locals->z.num > locals->list.array->ext_high ) {
                    locals->err = ERR_bounds;
                    goto ex_1;}
                T_4_1.num = locals->list.array->store->data[locals->z.num - locals->list.array->ext_low + locals->list.array->int_low];
                locals->ot.num = T_4_1.num;
                }

  FB_LINE(68);
                {
                {
                if (locals->z.num < locals->list.array->ext_low || locals->z.num > locals->list.array->ext_high) {
                    locals->err = ERR_bounds;
                    goto ex_1;}
                locals->list.array->store->data[locals->z.num + locals->list.array->int_low - locals->list.array->ext_low] = locals->nm.num;
                }
                }

  FB_LINE(69);
                {
                locals->nm.num = locals->ot.num;
                }

  FB_LINE(70);
                {
                CLUREF T_4_1;
                T_4_1.num = locals->z.num + 1;
                 if ((T_4_1.num > 0 && locals->z.num < 0 && 1 < 0) ||
                     (T_4_1.num < 0 && locals->z.num > 0 && 1 > 0)) {
                    locals->err = ERR_overflow;
                    goto ex_1;}
                locals->z.num = T_4_1.num;
                }
                }
                end_while_2:;
        }
    }
    end_inline_for_2:;
        goto end_1;
        ex_1:
            if ((locals->err == ERR_bounds)) {
            }
            else {
                goto ex_0;
            }
        end_1:;

  FB_LINE(73);
    {
    {
    if ((locals->list.array->int_low + locals->list.array->ext_size + 1) < locals->list.array->int_size) {
        locals->list.array->store->data[locals->list.array->int_low + locals->list.array->ext_size] = locals->nm.num;
        locals->list.array->ext_size++; locals->list.array->ext_high++;}
    else {
        locals->err = arrayOPaddh(locals->list, locals->nm);
        if (locals->err != ERR_ok) goto ex_0;}
    }
    }
    {signal(ERR_ok);}
    ex_0:
        {
            *iecode = locals->err;
            locals->body_ctrl_req = true;
            {signal(ERR_iteriterbodyexit);}}
    end_0: {signal(ERR_ok);}
    }/* end _all_file_names__IB_2 */

/**** END ITERATOR BODIES for _all_file_names_ ****/


extern errcode stringOPconcat();
extern errcode stringOPappend();

/**** BEGIN PROCEDURE _restar ****/

errcode
_restar(CLUREF s, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
    CLUREF i;
    enter_proc(85);

  LINE(86);
    for (;;) {
        if (true != true) { break; }

  LINE(87);
        {
            {CLUREF T_2_1;
            CLUREF T_2_2;
            T_2_1.ch = '\000';
            err = stringOPindexc(T_2_1, s, &T_2_2);
            if (err != ERR_ok) goto ex_0;
            i.num = T_2_2.num;
            }
            }

  LINE(88);
        {
        CLUREF T_2_1;
        T_2_1.num = (i.num == 0)? true : false;
        if (T_2_1.num == true) {

  LINE(89);
            {
            {
            ret_1->num = s.num;
            }
            {signal (ERR_ok);}}
            }
            }/* end if */

  LINE(90);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        CLUREF T_2_4;
        CLUREF T_2_5;
        CLUREF T_2_6;
        CLUREF T_2_7;
        T_2_1.num = i.num - 1;
         if ((T_2_1.num >= 0 && i.num < 0 && (-1) < 0) ||
             (T_2_1.num <= 0 && i.num > 0 && (-1) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = stringOPsubstr(s, CLU_1, T_2_1, &T_2_2);
        if (err != ERR_ok) goto ex_0;
        T_2_3.ch = '*';
        err = stringOPappend(T_2_2, T_2_3, &T_2_4);
        if (err != ERR_ok) goto ex_0;
        T_2_5.num = i.num + 1;
         if ((T_2_5.num > 0 && i.num < 0 && 1 < 0) ||
             (T_2_5.num < 0 && i.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = stringOPrest(s, T_2_5, &T_2_6);
        if (err != ERR_ok) goto ex_0;
        err = stringOPconcat(T_2_4, T_2_6, &T_2_7);
        if (err != ERR_ok) goto ex_0;
        s.num = T_2_7.num;
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
    end_0: elist[0] = no_return_values_STRING;
        {signal(ERR_failure);}
    }

/**** END PROCEDURE _restar ****/


extern errcode stringOPsize();
extern errcode _bytevecOPfetch();
extern errcode _bytevecOPindexc();
extern errcode intOPle();

/**** BEGIN PROCEDURE _match_name_spec ****/

errcode
_match_name_spec(CLUREF off, CLUREF buf, CLUREF nm, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
    CLUREF l;
    CLUREF i;
    CLUREF h;
    CLUREF c;
    CLUREF j;
    CLUREF m;
    CLUREF c2;
    CLUREF c1;
    enter_proc(95);

  LINE(96);
    {
        {l.num = off.num;
        }
        }

  LINE(97);
    {
        {i.num = 1;
        }
        }

  LINE(98);
    {
        {CLUREF T_1_1;
        err = stringOPsize(nm, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        h.num = T_1_1.num;
        }
        }

  LINE(99);
    for (;;) {
        if (true != true) { break; }

  LINE(100);
        {
            {CLUREF T_2_1;
            err = stringOPfetch(nm, i, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            c.num = T_2_1.num;
            }
            }

  LINE(101);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.ch = '*';
        T_2_2.num = (c.ch == T_2_1.ch)? true : false;
        if (T_2_2.num == true) {

  LINE(102);
            goto end_while_1;
            }
        else {
        CLUREF T_2_3;
        CLUREF T_2_4;
        T_2_3.ch = '\000';
        T_2_4.num = (c.ch == T_2_3.ch)? true : false;
        if (T_2_4.num == true) {

  LINE(104);
            {
            CLUREF T_3_1;
            T_3_1.ch = '*';
            c.num = T_3_1.num;
            }
            }
            }}/* end if */

  LINE(105);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        if (l.num < 1 || l.num > buf.str->size ) {
            err = ERR_bounds;
            goto ex_0;}
        T_2_1.ch = buf.str->data[l.num - 1];
        T_2_2.num = (c.ch == T_2_1.ch)? true : false;
        T_2_3.num = T_2_2.num ^ 1;
        if (T_2_3.num == true) {

  LINE(106);
            {
            {
            ret_1->num = 0;
            }
            {signal (ERR_ok);}}
            }
            }/* end if */

  LINE(107);
        {
        CLUREF T_2_1;
        T_2_1.num = l.num + 1;
         if ((T_2_1.num > 0 && l.num < 0 && 1 < 0) ||
             (T_2_1.num < 0 && l.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        l.num = T_2_1.num;
        }

  LINE(108);
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
        end_while_1:;

  LINE(110);
    for (;;) {
        if (true != true) { break; }

  LINE(111);
        {
        CLUREF T_3_1;
        T_3_1.num = i.num + 1;
         if ((T_3_1.num > 0 && i.num < 0 && 1 < 0) ||
             (T_3_1.num < 0 && i.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_1;}
        i.num = T_3_1.num;
        }

  LINE(112);
        {
            {j.num = i.num;
            }
            }

  LINE(113);
        for (;;) {
            CLUREF T_3_1;
            CLUREF T_3_2;
            CLUREF T_3_3;
            CLUREF T_3_4;
            err = stringOPfetch(nm, j, &T_3_1);
            if (err != ERR_ok) goto ex_1;
            T_3_2.ch = '*';
            T_3_3.num = (T_3_1.ch == T_3_2.ch)? true : false;
            T_3_4.num = T_3_3.num ^ 1;
            if (T_3_4.num != true) { break; }

  LINE(114);
            {
            CLUREF T_4_1;
            T_4_1.num = j.num + 1;
             if ((T_4_1.num > 0 && j.num < 0 && 1 < 0) ||
                 (T_4_1.num < 0 && j.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            j.num = T_4_1.num;
            }
            }
            end_while_3:;

  LINE(116);
        {
        j.num = i.num;
        }

  LINE(117);
        for (;;) {
            if (true != true) { break; }

  LINE(118);
            {
                {m.num = l.num;
                }
                }

  LINE(119);
            for (;;) {
                if (true != true) { break; }

  LINE(120);
                {
                    {CLUREF T_6_1;
                    err = stringOPfetch(nm, i, &T_6_1);
                    if (err != ERR_ok) goto ex_2;
                    c2.num = T_6_1.num;
                    }
                    }

  LINE(121);
                {
                CLUREF T_6_1;
                CLUREF T_6_2;
                T_6_1.ch = '*';
                T_6_2.num = (c2.ch == T_6_1.ch)? true : false;
                if (T_6_2.num == true) {

  LINE(122);
                    {
                        err = ERR_found;
                        goto ex_2;
                        }
                    }
                else {
                CLUREF T_6_3;
                CLUREF T_6_4;
                T_6_3.ch = '\000';
                T_6_4.num = (c2.ch == T_6_3.ch)? true : false;
                if (T_6_4.num == true) {

  LINE(124);
                    {
                    CLUREF T_7_1;
                    T_7_1.ch = '*';
                    c2.num = T_7_1.num;
                    }
                    }
                    }}/* end if */

  LINE(125);
                {
                    {CLUREF T_6_1;
                    if (l.num < 1 || l.num > buf.str->size ) {
                        err = ERR_bounds;
                        goto ex_2;}
                    T_6_1.ch = buf.str->data[l.num - 1];
                    c1.num = T_6_1.num;
                    }
                    }

  LINE(126);
                {
                CLUREF T_6_1;
                CLUREF T_6_2;
                T_6_1.ch = '\000';
                T_6_2.num = (c1.ch == T_6_1.ch)? true : false;
                if (T_6_2.num == true) {

  LINE(127);
                    {
                    {
                    ret_1->num = 0;
                    }
                    {signal (ERR_ok);}}
                    }
                else {
                CLUREF T_6_3;
                CLUREF T_6_4;
                T_6_3.num = (c1.ch == c2.ch)? true : false;
                T_6_4.num = T_6_3.num ^ 1;
                if (T_6_4.num == true) {

  LINE(129);
                    goto end_while_5;
                    }
                    }}/* end if */

  LINE(130);
                {
                CLUREF T_6_1;
                T_6_1.num = l.num + 1;
                 if ((T_6_1.num > 0 && l.num < 0 && 1 < 0) ||
                     (T_6_1.num < 0 && l.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_2;}
                l.num = T_6_1.num;
                }

  LINE(131);
                {
                CLUREF T_6_1;
                T_6_1.num = i.num + 1;
                 if ((T_6_1.num > 0 && i.num < 0 && 1 < 0) ||
                     (T_6_1.num < 0 && i.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_2;}
                i.num = T_6_1.num;
                }
                }
                end_while_5:;

  LINE(133);
            {
            CLUREF T_5_1;
            T_5_1.num = m.num + 1;
             if ((T_5_1.num > 0 && m.num < 0 && 1 < 0) ||
                 (T_5_1.num < 0 && m.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_2;}
            l.num = T_5_1.num;
            }

  LINE(134);
            {
            i.num = j.num;
            }
            }
            end_while_4:;
            goto end_2;
            ex_2:
                if ((err == ERR_found)) {
                }
                else {
                    goto ex_1;
                }
            end_2:;
        }
        end_while_2:;
        goto end_1;
        ex_1:
            if ((err == ERR_bounds)) {
            }
            else {
                goto ex_0;
            }
        end_1:;

  LINE(137);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        CLUREF T_1_3;
        CLUREF T_1_4;
        CLUREF T_1_5;
        T_1_1.ch = '\000';
        err = _bytevecOPindexc(T_1_1, buf, l, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        T_1_3.num = h.num - i.num;
         if ((T_1_3.num >= 0 && h.num < 0 && (-i.num) < 0) ||
             (T_1_3.num <= 0 && h.num > 0 && (-i.num) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        T_1_4.num = T_1_3.num + 1;
         if ((T_1_4.num > 0 && T_1_3.num < 0 && 1 < 0) ||
             (T_1_4.num < 0 && T_1_3.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        T_1_5.num = T_1_2.num - T_1_4.num;
         if ((T_1_5.num >= 0 && T_1_2.num < 0 && (-T_1_4.num) < 0) ||
             (T_1_5.num <= 0 && T_1_2.num > 0 && (-T_1_4.num) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        m.num = T_1_5.num;
        }
        }

  LINE(138);
    {
    CLUREF T_1_1;
    T_1_1.num = (l.num > m.num)? true : false;
    if (T_1_1.num == true) {

  LINE(139);
        {
        {
        ret_1->num = 0;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(140);
    for (;;) {
        CLUREF T_1_1;
        T_1_1.num = (i.num <= h.num)? true : false;
        if (T_1_1.num != true) { break; }

  LINE(141);
        {
            {CLUREF T_2_1;
            err = stringOPfetch(nm, i, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            c.num = T_2_1.num;
            }
            }

  LINE(142);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.ch = '\000';
        T_2_2.num = (c.ch == T_2_1.ch)? true : false;
        if (T_2_2.num == true) {

  LINE(143);
            {
            CLUREF T_3_1;
            T_3_1.ch = '*';
            c.num = T_3_1.num;
            }
            }
            }/* end if */

  LINE(144);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        if (m.num < 1 || m.num > buf.str->size ) {
            err = ERR_bounds;
            goto ex_0;}
        T_2_1.ch = buf.str->data[m.num - 1];
        T_2_2.num = (c.ch == T_2_1.ch)? true : false;
        T_2_3.num = T_2_2.num ^ 1;
        if (T_2_3.num == true) {

  LINE(145);
            {
            {
            ret_1->num = 0;
            }
            {signal (ERR_ok);}}
            }
            }/* end if */

  LINE(146);
        {
        CLUREF T_2_1;
        T_2_1.num = m.num + 1;
         if ((T_2_1.num > 0 && m.num < 0 && 1 < 0) ||
             (T_2_1.num < 0 && m.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        m.num = T_2_1.num;
        }

  LINE(147);
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
        end_while_6:;

  LINE(149);
    {
    {
    CLUREF T_1_1;
    T_1_1.num = m.num - off.num;
     if ((T_1_1.num >= 0 && m.num < 0 && (-off.num) < 0) ||
         (T_1_1.num <= 0 && m.num > 0 && (-off.num) > 0)) {
        err = ERR_overflow;
        goto ex_0;}
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

/**** END PROCEDURE _match_name_spec ****/

