
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE array_replace ****/


static const struct /* REQS */ {
    long count;
} array_replace_of_t_reqs_actual = { 0 };

const struct REQS * const array_replace_of_t_reqs
    = (const struct REQS *)&array_replace_of_t_reqs_actual;


typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    } array_replace_of_t_OPS;

extern errcode intOPsub();
extern errcode arrayOPlow();
extern errcode arrayOPsize();
extern errcode intOPlt();
extern errcode _eventOPdefer();
extern errcode _advOPget_vector();
extern errcode _cvt();
extern errcode intOPequal();
extern errcode _eventOPundefer();
extern errcode intOPadd();
extern errcode _advOPget_start();
extern errcode _advOPset_start();
extern errcode intOPgt();
extern errcode _vecOPmove_lr();
extern errcode _advOPset_size();
extern errcode intOPge();
extern errcode _vecOPequal();
extern errcode _vecOPcreate();
extern errcode _vecOPsize();
extern errcode _advOPset_vector();
extern errcode _vecOPmove_rl();
extern const struct REQS * const _adv_of_t_reqs;
extern const OWN_req _adv_ownreqs;
extern struct OPS *_adv_ops;

typedef struct {
    long array_replace_own_init;
    const array_replace_of_t_OPS * const t_ops;
    struct OPS *_adv_of_t_table;
    struct OPS *_adv_of_t_ops;
    OWNPTR _adv_of_t_owns;
} array_replace_OWN_DEFN;
const OWN_req array_replace_ownreqs = { sizeof(array_replace_OWN_DEFN), 1 };


errcode
array_replace(CLUREF a1, CLUREF b1, CLUREF w1, CLUREF a2, CLUREF b2, CLUREF w2)
{
    errcode err;
    array_replace_OWN_DEFN *op_own_ptr;
    CLUREF f1;
    CLUREF r1;
    CLUREF f2;
    CLUREF r2;
    CLUREF v1;
    CLUREF s1;
    CLUREF v2;
    CLUREF w3;
    CLUREF tot;
    CLUREF s2;
    CLUREF s3;
    CLUREF nv;
    CLUREF v3;
    CLUREF df;
    CLUREF s0;
    op_own_ptr = (array_replace_OWN_DEFN *)CUR_PROC_VAR.proc->op_owns;
    if (op_own_ptr->array_replace_own_init == 0) {
        add_parm_info_type(0, (const struct OPS *)op_own_ptr->t_ops, _adv_of_t_reqs);
        find_type_instance(_adv_ops, 1, &_adv_ownreqs, &(op_own_ptr->_adv_of_t_ops));
    }
    if (op_own_ptr->array_replace_own_init == 0) {
        op_own_ptr->array_replace_own_init = 1;
        /* no own vars to init */
    }
    enter_proc(3);

  LINE(8);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = a1.array->ext_low;
        T_1_2.num = b1.num - T_1_1.num;
         if ((T_1_2.num >= 0 && b1.num < 0 && (-T_1_1.num) < 0) ||
             (T_1_2.num <= 0 && b1.num > 0 && (-T_1_1.num) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        f1.num = T_1_2.num;
        }
        }

  LINE(9);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = a1.array->ext_size;
        T_1_2.num = T_1_1.num - f1.num;
         if ((T_1_2.num >= 0 && T_1_1.num < 0 && (-f1.num) < 0) ||
             (T_1_2.num <= 0 && T_1_1.num > 0 && (-f1.num) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        r1.num = T_1_2.num;
        }
        }

  LINE(10);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = a2.array->ext_low;
        T_1_2.num = b2.num - T_1_1.num;
         if ((T_1_2.num >= 0 && b2.num < 0 && (-T_1_1.num) < 0) ||
             (T_1_2.num <= 0 && b2.num > 0 && (-T_1_1.num) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        f2.num = T_1_2.num;
        }
        }

  LINE(11);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = a2.array->ext_size;
        T_1_2.num = T_1_1.num - f2.num;
         if ((T_1_2.num >= 0 && T_1_1.num < 0 && (-f2.num) < 0) ||
             (T_1_2.num <= 0 && T_1_1.num > 0 && (-f2.num) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        r2.num = T_1_2.num;
        }
        }

  LINE(12);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    CLUREF T_1_6;
    CLUREF T_1_7;
    T_1_4.num = (f1.num < 0)? true : false;
    T_1_3.num = T_1_4.num;
    if (!T_1_4.num) {
        T_1_5.num = (r1.num < 0)? true : false;
        T_1_3.num = T_1_5.num;
    }
    T_1_2.num = T_1_3.num;
    if (!T_1_3.num) {
        T_1_6.num = (f2.num < 0)? true : false;
        T_1_2.num = T_1_6.num;
    }
    T_1_1.num = T_1_2.num;
    if (!T_1_2.num) {
        T_1_7.num = (r2.num < 0)? true : false;
        T_1_1.num = T_1_7.num;
    }
    if (T_1_1.num == true) {

  LINE(13);
        {
        {signal (ERR_bounds);}}
        }
        }/* end if */

  LINE(14);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_2.num = (w1.num < 0)? true : false;
    T_1_1.num = T_1_2.num;
    if (!T_1_2.num) {
        T_1_3.num = (w2.num < 0)? true : false;
        T_1_1.num = T_1_3.num;
    }
    if (T_1_1.num == true) {

  LINE(15);
        {
        {signal (ERR_negative_size);}}
        }
        }/* end if */

  LINE(16);
    {
    err = _eventOPdefer();
    if (err != ERR_ok) goto ex_0;
    }

  LINE(17);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = (long)a1.num;
        generic_CLU_proc.type_owns = op_own_ptr->_adv_of_t_ops->type_owns;
        generic_CLU_proc.proc = _advOPget_vector;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = _advOPget_vector(T_1_1, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        v1.num = T_1_2.num;
        }
        }

  LINE(18);
    {
    CLUREF T_1_1;
    T_1_1.num = (r1.num < w1.num)? true : false;
    if (T_1_1.num == true) {

  LINE(19);
        {
        w1.num = r1.num;
        }
        }
        }/* end if */

  LINE(20);
    {
    CLUREF T_1_1;
    T_1_1.num = (r2.num < w2.num)? true : false;
    if (T_1_1.num == true) {

  LINE(21);
        {
        w2.num = r2.num;
        }
        }
        }/* end if */

  LINE(22);
    {
    CLUREF T_1_1;
    T_1_1.num = (w2.num == 0)? true : false;
    if (T_1_1.num == true) {

  LINE(23);
        {
        CLUREF T_2_1;
        T_2_1.num = (w1.num == 0)? true : false;
        if (T_2_1.num == true) {

  LINE(24);
            {
            err = _eventOPundefer();
            if (err != ERR_ok) goto ex_0;
            }

  LINE(25);
            {
            {signal (ERR_ok);}}
            }
            }/* end if */

  LINE(27);
        {
            {CLUREF T_2_1;
            CLUREF T_2_2;
            CLUREF T_2_3;
            T_2_1.num = (long)a1.num;
            generic_CLU_proc.type_owns = op_own_ptr->_adv_of_t_ops->type_owns;
            generic_CLU_proc.proc = _advOPget_start;
            CUR_PROC_VAR.proc = &generic_CLU_proc;
            err = _advOPget_start(T_2_1, &T_2_2);
            if (err != ERR_ok) goto ex_0;
            T_2_3.num = T_2_2.num + f1.num;
             if ((T_2_3.num > 0 && T_2_2.num < 0 && f1.num < 0) ||
                 (T_2_3.num < 0 && T_2_2.num > 0 && f1.num > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            s1.num = T_2_3.num;
            }
            }

  LINE(28);
        {
        CLUREF T_2_1;
        T_2_1.num = (f1.num == 0)? true : false;
        if (T_2_1.num == true) {

  LINE(29);
            {
            CLUREF T_3_1;
            CLUREF T_3_2;
            T_3_1.num = (long)a1.num;
            T_3_2.num = s1.num + w1.num;
             if ((T_3_2.num > 0 && s1.num < 0 && w1.num < 0) ||
                 (T_3_2.num < 0 && s1.num > 0 && w1.num > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            generic_CLU_proc.type_owns = op_own_ptr->_adv_of_t_ops->type_owns;
            generic_CLU_proc.proc = _advOPset_start;
            CUR_PROC_VAR.proc = &generic_CLU_proc;
            err = _advOPset_start(T_3_1, T_3_2);
            if (err != ERR_ok) goto ex_0;
            }
            }
        else {

  LINE(30);
            {
            CLUREF T_3_1;
            T_3_1.num = (r1.num > w1.num)? true : false;
            if (T_3_1.num == true) {

  LINE(31);
                {
                CLUREF T_4_1;
                CLUREF T_4_2;
                T_4_1.num = s1.num + w1.num;
                 if ((T_4_1.num > 0 && s1.num < 0 && w1.num < 0) ||
                     (T_4_1.num < 0 && s1.num > 0 && w1.num > 0)) {
                    err = ERR_overflow;
                    goto ex_0;}
                T_4_2.num = r1.num - w1.num;
                 if ((T_4_2.num >= 0 && r1.num < 0 && (-w1.num) < 0) ||
                     (T_4_2.num <= 0 && r1.num > 0 && (-w1.num) > 0)) {
                    err = ERR_overflow;
                    goto ex_0;}
                err = _vecOPmove_lr(v1, T_4_1, v1, s1, T_4_2);
                if (err != ERR_ok) goto ex_0;
                }
                }
                }/* end if */

  LINE(32);
            {
            CLUREF T_3_1;
            CLUREF T_3_2;
            CLUREF T_3_3;
            T_3_1.num = (long)a1.num;
            T_3_2.num = a1.array->ext_size;
            T_3_3.num = T_3_2.num - w1.num;
             if ((T_3_3.num >= 0 && T_3_2.num < 0 && (-w1.num) < 0) ||
                 (T_3_3.num <= 0 && T_3_2.num > 0 && (-w1.num) > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            generic_CLU_proc.type_owns = op_own_ptr->_adv_of_t_ops->type_owns;
            generic_CLU_proc.proc = _advOPset_size;
            CUR_PROC_VAR.proc = &generic_CLU_proc;
            err = _advOPset_size(T_3_1, T_3_3);
            if (err != ERR_ok) goto ex_0;
            }
            }}/* end if */

  LINE(34);
        {
        err = _eventOPundefer();
        if (err != ERR_ok) goto ex_0;
        }

  LINE(35);
        {
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(37);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = (long)a2.num;
        generic_CLU_proc.type_owns = op_own_ptr->_adv_of_t_ops->type_owns;
        generic_CLU_proc.proc = _advOPget_vector;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = _advOPget_vector(T_1_1, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        v2.num = T_1_2.num;
        }
        }

  LINE(38);
    {
        {CLUREF T_1_1;
        T_1_1.num = r1.num - w1.num;
         if ((T_1_1.num >= 0 && r1.num < 0 && (-w1.num) < 0) ||
             (T_1_1.num <= 0 && r1.num > 0 && (-w1.num) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        w3.num = T_1_1.num;
        }
        }

  LINE(39);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = f1.num + w2.num;
         if ((T_1_1.num > 0 && f1.num < 0 && w2.num < 0) ||
             (T_1_1.num < 0 && f1.num > 0 && w2.num > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        T_1_2.num = T_1_1.num + w3.num;
         if ((T_1_2.num > 0 && T_1_1.num < 0 && w3.num < 0) ||
             (T_1_2.num < 0 && T_1_1.num > 0 && w3.num > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        tot.num = T_1_2.num;
        }
        }

  LINE(40);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = (long)a1.num;
        generic_CLU_proc.type_owns = op_own_ptr->_adv_of_t_ops->type_owns;
        generic_CLU_proc.proc = _advOPget_start;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = _advOPget_start(T_1_1, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        s1.num = T_1_2.num;
        }
        }

  LINE(41);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        CLUREF T_1_3;
        T_1_1.num = (long)a2.num;
        generic_CLU_proc.type_owns = op_own_ptr->_adv_of_t_ops->type_owns;
        generic_CLU_proc.proc = _advOPget_start;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = _advOPget_start(T_1_1, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        T_1_3.num = T_1_2.num + f2.num;
         if ((T_1_3.num > 0 && T_1_2.num < 0 && f2.num < 0) ||
             (T_1_3.num < 0 && T_1_2.num > 0 && f2.num > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        s2.num = T_1_3.num;
        }
        }

  LINE(42);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = s1.num + f1.num;
         if ((T_1_1.num > 0 && s1.num < 0 && f1.num < 0) ||
             (T_1_1.num < 0 && s1.num > 0 && f1.num > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        T_1_2.num = T_1_1.num + w1.num;
         if ((T_1_2.num > 0 && T_1_1.num < 0 && w1.num < 0) ||
             (T_1_2.num < 0 && T_1_1.num > 0 && w1.num > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        s3.num = T_1_2.num;
        }
        }

  LINE(43);
    {
    CLUREF T_1_1;
    T_1_1.num = (w1.num >= w2.num)? true : false;
    if (T_1_1.num == true) {

  LINE(44);
        {
        CLUREF T_2_1;
        err = _vecOPequal(v1, v2, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        if (T_2_1.num == true) {

  LINE(45);
            {
                {CLUREF T_3_1;
                err = _vecOPcreate(w2, &T_3_1);
                if (err != ERR_ok) goto ex_0;
                nv.num = T_3_1.num;
                }
                }

  LINE(46);
            {
            err = _vecOPmove_lr(v2, s2, nv, CLU_1, w2);
            if (err != ERR_ok) goto ex_0;
            }

  LINE(47);
            {
            v2.num = nv.num;
            }

  LINE(48);
            {
            s2.num = 1;
            }
            }
            }/* end if */

  LINE(50);
        {
        CLUREF T_2_1;
        T_2_1.num = s1.num + f1.num;
         if ((T_2_1.num > 0 && s1.num < 0 && f1.num < 0) ||
             (T_2_1.num < 0 && s1.num > 0 && f1.num > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = _vecOPmove_lr(v2, s2, v1, T_2_1, w2);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(51);
        {
        CLUREF T_2_1;
        T_2_1.num = (w1.num > w2.num)? true : false;
        if (T_2_1.num == true) {

  LINE(52);
            {
            CLUREF T_3_1;
            CLUREF T_3_2;
            T_3_1.num = s3.num - w1.num;
             if ((T_3_1.num >= 0 && s3.num < 0 && (-w1.num) < 0) ||
                 (T_3_1.num <= 0 && s3.num > 0 && (-w1.num) > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            T_3_2.num = T_3_1.num + w2.num;
             if ((T_3_2.num > 0 && T_3_1.num < 0 && w2.num < 0) ||
                 (T_3_2.num < 0 && T_3_1.num > 0 && w2.num > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            err = _vecOPmove_lr(v1, s3, v1, T_3_2, w3);
            if (err != ERR_ok) goto ex_0;
            }

  LINE(53);
            {
            CLUREF T_3_1;
            T_3_1.num = (long)a1.num;
            generic_CLU_proc.type_owns = op_own_ptr->_adv_of_t_ops->type_owns;
            generic_CLU_proc.proc = _advOPset_size;
            CUR_PROC_VAR.proc = &generic_CLU_proc;
            err = _advOPset_size(T_3_1, tot);
            if (err != ERR_ok) goto ex_0;
            }
            }
            }/* end if */

  LINE(55);
        {
        err = _eventOPundefer();
        if (err != ERR_ok) goto ex_0;
        }

  LINE(56);
        {
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(58);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    err = _vecOPsize(v1, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    T_1_2.num = (T_1_1.num < tot.num)? true : false;
    if (T_1_2.num == true) {

  LINE(59);
        {
            {CLUREF T_2_1;
            err = _vecOPcreate(tot, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            v3.num = T_2_1.num;
            }
            }

  LINE(60);
        {
        err = _vecOPmove_lr(v1, s1, v3, CLU_1, f1);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(61);
        {
        CLUREF T_2_1;
        T_2_1.num = f1.num + 1;
         if ((T_2_1.num > 0 && f1.num < 0 && 1 < 0) ||
             (T_2_1.num < 0 && f1.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = _vecOPmove_lr(v2, s2, v3, T_2_1, w2);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(62);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = f1.num + w2.num;
         if ((T_2_1.num > 0 && f1.num < 0 && w2.num < 0) ||
             (T_2_1.num < 0 && f1.num > 0 && w2.num > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        T_2_2.num = T_2_1.num + 1;
         if ((T_2_2.num > 0 && T_2_1.num < 0 && 1 < 0) ||
             (T_2_2.num < 0 && T_2_1.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = _vecOPmove_lr(v1, s3, v3, T_2_2, w3);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(63);
        {
        CLUREF T_2_1;
        T_2_1.num = (long)a1.num;
        generic_CLU_proc.type_owns = op_own_ptr->_adv_of_t_ops->type_owns;
        generic_CLU_proc.proc = _advOPset_vector;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = _advOPset_vector(T_2_1, v3);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(64);
        {
        err = _eventOPundefer();
        if (err != ERR_ok) goto ex_0;
        }

  LINE(65);
        {
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(67);
    {
    CLUREF T_1_1;
    err = _vecOPequal(v1, v2, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    if (T_1_1.num == true) {

  LINE(68);
        {
            {CLUREF T_2_1;
            err = _vecOPcreate(w2, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            nv.num = T_2_1.num;
            }
            }

  LINE(69);
        {
        err = _vecOPmove_lr(v2, s2, nv, CLU_1, w2);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(70);
        {
        v2.num = nv.num;
        }

  LINE(71);
        {
        s2.num = 1;
        }
        }
        }/* end if */

  LINE(73);
    {
        {CLUREF T_1_1;
        T_1_1.num = w2.num - w1.num;
         if ((T_1_1.num >= 0 && w2.num < 0 && (-w1.num) < 0) ||
             (T_1_1.num <= 0 && w2.num > 0 && (-w1.num) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        df.num = T_1_1.num;
        }
        }

  LINE(74);
    {
    CLUREF T_1_1;
    T_1_1.num = (s1.num > df.num)? true : false;
    if (T_1_1.num == true) {

  LINE(75);
        {
            {CLUREF T_2_1;
            T_2_1.num = s1.num - df.num;
             if ((T_2_1.num >= 0 && s1.num < 0 && (-df.num) < 0) ||
                 (T_2_1.num <= 0 && s1.num > 0 && (-df.num) > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            s0.num = T_2_1.num;
            }
            }

  LINE(76);
        {
        CLUREF T_2_1;
        T_2_1.num = (long)a1.num;
        generic_CLU_proc.type_owns = op_own_ptr->_adv_of_t_ops->type_owns;
        generic_CLU_proc.proc = _advOPset_start;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = _advOPset_start(T_2_1, s0);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(77);
        {
        err = _vecOPmove_lr(v1, s1, v1, s0, f1);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(78);
        {
        CLUREF T_2_1;
        T_2_1.num = s0.num + f1.num;
         if ((T_2_1.num > 0 && s0.num < 0 && f1.num < 0) ||
             (T_2_1.num < 0 && s0.num > 0 && f1.num > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = _vecOPmove_lr(v2, s2, v1, T_2_1, w2);
        if (err != ERR_ok) goto ex_0;
        }
        }
    else {
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    CLUREF T_1_6;
    CLUREF T_1_7;
    err = _vecOPsize(v1, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    T_1_3.num = T_1_2.num - s1.num;
     if ((T_1_3.num >= 0 && T_1_2.num < 0 && (-s1.num) < 0) ||
         (T_1_3.num <= 0 && T_1_2.num > 0 && (-s1.num) > 0)) {
        err = ERR_overflow;
        goto ex_0;}
    T_1_4.num = a1.array->ext_size;
    T_1_5.num = T_1_3.num - T_1_4.num;
     if ((T_1_5.num >= 0 && T_1_3.num < 0 && (-T_1_4.num) < 0) ||
         (T_1_5.num <= 0 && T_1_3.num > 0 && (-T_1_4.num) > 0)) {
        err = ERR_overflow;
        goto ex_0;}
    T_1_6.num = T_1_5.num + 1;
     if ((T_1_6.num > 0 && T_1_5.num < 0 && 1 < 0) ||
         (T_1_6.num < 0 && T_1_5.num > 0 && 1 > 0)) {
        err = ERR_overflow;
        goto ex_0;}
    T_1_7.num = (T_1_6.num >= df.num)? true : false;
    if (T_1_7.num == true) {

  LINE(80);
        {
        CLUREF T_2_1;
        T_2_1.num = (long)a1.num;
        generic_CLU_proc.type_owns = op_own_ptr->_adv_of_t_ops->type_owns;
        generic_CLU_proc.proc = _advOPset_size;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = _advOPset_size(T_2_1, tot);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(81);
        {
        CLUREF T_2_1;
        T_2_1.num = s3.num + df.num;
         if ((T_2_1.num > 0 && s3.num < 0 && df.num < 0) ||
             (T_2_1.num < 0 && s3.num > 0 && df.num > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = _vecOPmove_rl(v1, s3, v1, T_2_1, w3);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(82);
        {
        CLUREF T_2_1;
        T_2_1.num = s1.num + f1.num;
         if ((T_2_1.num > 0 && s1.num < 0 && f1.num < 0) ||
             (T_2_1.num < 0 && s1.num > 0 && f1.num > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = _vecOPmove_lr(v2, s2, v1, T_2_1, w2);
        if (err != ERR_ok) goto ex_0;
        }
        }
    else {

  LINE(83);
        {
        CLUREF T_2_1;
        T_2_1.num = (long)a1.num;
        generic_CLU_proc.type_owns = op_own_ptr->_adv_of_t_ops->type_owns;
        generic_CLU_proc.proc = _advOPset_vector;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = _advOPset_vector(T_2_1, v1);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(84);
        {
        err = _vecOPmove_lr(v1, s1, v1, CLU_1, f1);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(85);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = f1.num + w2.num;
         if ((T_2_1.num > 0 && f1.num < 0 && w2.num < 0) ||
             (T_2_1.num < 0 && f1.num > 0 && w2.num > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        T_2_2.num = T_2_1.num + 1;
         if ((T_2_2.num > 0 && T_2_1.num < 0 && 1 < 0) ||
             (T_2_2.num < 0 && T_2_1.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = _vecOPmove_rl(v1, s3, v1, T_2_2, w3);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(86);
        {
        CLUREF T_2_1;
        T_2_1.num = f1.num + 1;
         if ((T_2_1.num > 0 && f1.num < 0 && 1 < 0) ||
             (T_2_1.num < 0 && f1.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = _vecOPmove_lr(v2, s2, v1, T_2_1, w2);
        if (err != ERR_ok) goto ex_0;
        }

  LINE(87);
        {
        CLUREF T_2_1;
        T_2_1.num = (long)a1.num;
        generic_CLU_proc.type_owns = op_own_ptr->_adv_of_t_ops->type_owns;
        generic_CLU_proc.proc = _advOPset_size;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = _advOPset_size(T_2_1, tot);
        if (err != ERR_ok) goto ex_0;
        }
        }}}/* end if */

  LINE(89);
    {
    err = _eventOPundefer();
    if (err != ERR_ok) goto ex_0;
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

/**** END PROCEDURE array_replace ****/

