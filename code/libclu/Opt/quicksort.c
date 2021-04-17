
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


typedef struct {
long count;
} quicksort_of_t_REQS;

quicksort_of_t_REQS quicksort_of_t_reqs_actual = {0};

struct REQS * quicksort_of_t_reqs = (struct REQS *)&quicksort_of_t_reqs_actual;


typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    } quicksort_of_t_OPS;

extern errcode intOPsub();
extern errcode intOPgt();
extern errcode intOPlt();
extern errcode sisort();
extern errcode lqsort();
extern struct REQS *sisort_of_t_reqs;
extern OWN_req sisort_ownreqs;
extern struct REQS *lqsort_of_t_reqs;
extern OWN_req lqsort_ownreqs;

typedef struct {
    long quicksort_own_init;
    quicksort_of_t_OPS *t_ops;
    struct OPS *sisort_of_t_table;
    struct OPS *sisort_of_t_ops;
    OWNPTR sisort_of_t_owns;
    struct OPS *lqsort_of_t_table;
    struct OPS *lqsort_of_t_ops;
    OWNPTR lqsort_of_t_owns;
    } quicksort_OWN_DEFN;
OWN_req quicksort_ownreqs = {sizeof(quicksort_OWN_DEFN), 1};


/**** BEGIN PROCEDURE quicksort ****/

errcode quicksort(items, low, high, less)
CLUREF items;
CLUREF low;
CLUREF high;
CLUREF less;
    {
    errcode err;
    errcode ecode2;
    quicksort_OWN_DEFN *op_own_ptr;
    CLUREF size;
    op_own_ptr = (quicksort_OWN_DEFN*) CUR_PROC_VAR.proc->op_owns;
        if (op_own_ptr->quicksort_own_init == 0) {
        add_parm_info_type(0, op_own_ptr->t_ops, sisort_of_t_reqs);
        find_prociter_instance(sisort, 1, &sisort_ownreqs, &(op_own_ptr->sisort_of_t_ops));
        add_parm_info_type(0, op_own_ptr->t_ops, lqsort_of_t_reqs);
        find_prociter_instance(lqsort, 1, &lqsort_ownreqs, &(op_own_ptr->lqsort_of_t_ops));
        }
        if (op_own_ptr->quicksort_own_init == 0) {
        op_own_ptr->quicksort_own_init = 1;
    }
    enter_proc(18);

  LINE(23);
    {
        {CLUREF T_1_1;
        T_1_1.num = high.num - low.num;
         if ((T_1_1.num >= 0 && high.num < 0 && (-low.num) < 0) || 
             (T_1_1.num <= 0 && high.num > 0 && (-low.num) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        size.num = T_1_1.num;
        }
        }

  LINE(25);
    {
    CLUREF T_1_1;
    T_1_1.num = (size.num > 0)? true : false;
    if (T_1_1.num == true) {

  LINE(26);
        {
        CLUREF T_3_1;
        T_3_1.num = (size.num < 10)? true : false;
        if (T_3_1.num == true) {

  LINE(27);
            {
            generic_CLU_proc.type_owns = 0;
            generic_CLU_proc.op_owns = (long)op_own_ptr->sisort_of_t_ops->op_owns;
            generic_CLU_proc.proc = sisort;
            CUR_PROC_VAR.proc = &generic_CLU_proc;
            err = sisort(items, low, high, less);
            if (err != ERR_ok) goto ex_1;
            }
            }
        else {

  LINE(28);
            {
            generic_CLU_proc.type_owns = 0;
            generic_CLU_proc.op_owns = (long)op_own_ptr->lqsort_of_t_ops->op_owns;
            generic_CLU_proc.proc = lqsort;
            CUR_PROC_VAR.proc = &generic_CLU_proc;
            err = lqsort(items, low, high, size, less);
            if (err != ERR_ok) goto ex_1;
            }
            }}/* end if */
        goto end_1;
        ex_1:
            if (err == ERR_bounds) {signal(ERR_bounds);}
            else {
                goto ex_0;}
        end_1:;
        }
    else {
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_2.num = -1;
    T_1_3.num = (size.num < T_1_2.num)? true : false;
    if (T_1_3.num == true) {

  LINE(32);
        {
        {signal (ERR_bounds);}}
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

/**** END PROCEDURE quicksort ****/



typedef struct {
long count;
} lqsort_of_t_REQS;

lqsort_of_t_REQS lqsort_of_t_reqs_actual = {0};

struct REQS * lqsort_of_t_reqs = (struct REQS *)&lqsort_of_t_reqs_actual;


typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    } lqsort_of_t_OPS;

extern errcode intOPdiv();
extern errcode intOPadd();
extern errcode arrayOPfetch();
extern errcode boolOPnot();
extern errcode arrayOPstore();
extern errcode intOPequal();

typedef struct {
    long lqsort_own_init;
    lqsort_of_t_OPS *t_ops;
    struct OPS *sisort_of_t_table;
    struct OPS *sisort_of_t_ops;
    OWNPTR sisort_of_t_owns;
    struct OPS *lqsort_of_t_table;
    struct OPS *lqsort_of_t_ops;
    OWNPTR lqsort_of_t_owns;
    } lqsort_OWN_DEFN;
OWN_req lqsort_ownreqs = {sizeof(lqsort_OWN_DEFN), 1};


/**** BEGIN PROCEDURE lqsort ****/

errcode lqsort(items, low, high, size, less)
CLUREF items;
CLUREF low;
CLUREF high;
CLUREF size;
CLUREF less;
    {
    errcode err;
    errcode ecode2;
    lqsort_OWN_DEFN *op_own_ptr;
    CLUREF temp;
    CLUREF median;
    CLUREF miditem;
    CLUREF left;
    CLUREF right;
    CLUREF smlsize;
    op_own_ptr = (lqsort_OWN_DEFN*) CUR_PROC_VAR.proc->op_owns;
        if (op_own_ptr->lqsort_own_init == 0) {
        add_parm_info_type(0, op_own_ptr->t_ops, sisort_of_t_reqs);
        find_prociter_instance(sisort, 1, &sisort_ownreqs, &(op_own_ptr->sisort_of_t_ops));
        add_parm_info_type(0, op_own_ptr->t_ops, lqsort_of_t_reqs);
        find_prociter_instance(lqsort, 1, &lqsort_ownreqs, &(op_own_ptr->lqsort_of_t_ops));
        }
        if (op_own_ptr->lqsort_own_init == 0) {
        op_own_ptr->lqsort_own_init = 1;
    }
    enter_proc(39);

  LINE(44);
    {

  LINE(45);
        for (;;) {
            CLUREF T_3_1;
            T_3_1.num = (10 < size.num)? true : false;
            if (T_3_1.num != true) { break; }

  LINE(47);
            {
                {CLUREF T_4_1;
                CLUREF T_4_2;
                T_4_1.num = low.num + high.num;
                 if ((T_4_1.num > 0 && low.num < 0 && high.num < 0) || 
                     (T_4_1.num < 0 && low.num > 0 && high.num > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                err = intOPdiv(T_4_1, CLU_2, &T_4_2);
                if (err != ERR_ok) goto ex_1;
                median.num = T_4_2.num;
                }
                }

  LINE(50);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            if (low.num < items.array->ext_low || low.num > items.array->ext_high ) {
                err = ERR_bounds;
                goto ex_1;}
            T_4_1.num = items.array->store->data[low.num - items.array->ext_low + items.array->int_low];
            if (median.num < items.array->ext_low || median.num > items.array->ext_high ) {
                err = ERR_bounds;
                goto ex_1;}
            T_4_2.num = items.array->store->data[median.num - items.array->ext_low + items.array->int_low];
            CUR_PROC_VAR = less;
            err = less.proc->proc(T_4_1, T_4_2, &T_4_3);
            if (err != ERR_ok) goto ex_1;
            if (T_4_3.num == true) {

  LINE(51);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                CLUREF T_5_4;
                if (median.num < items.array->ext_low || median.num > items.array->ext_high ) {
                    err = ERR_bounds;
                    goto ex_1;}
                T_5_1.num = items.array->store->data[median.num - items.array->ext_low + items.array->int_low];
                if (high.num < items.array->ext_low || high.num > items.array->ext_high ) {
                    err = ERR_bounds;
                    goto ex_1;}
                T_5_2.num = items.array->store->data[high.num - items.array->ext_low + items.array->int_low];
                CUR_PROC_VAR = less;
                err = less.proc->proc(T_5_1, T_5_2, &T_5_3);
                if (err != ERR_ok) goto ex_1;
                T_5_4.num = T_5_3.num ^ 1;
                if (T_5_4.num == true) {

  LINE(53);
                    {
                    CLUREF T_6_1;
                    if (median.num < items.array->ext_low || median.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_6_1.num = items.array->store->data[median.num - items.array->ext_low + items.array->int_low];
                    temp.num = T_6_1.num;
                    }

  LINE(54);
                    {
                    CLUREF T_6_1;
                    if (high.num < items.array->ext_low || high.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_6_1.num = items.array->store->data[high.num - items.array->ext_low + items.array->int_low];
                    {
                    if (median.num < items.array->ext_low || median.num > items.array->ext_high) {
                        err = ERR_bounds;
                        goto ex_1;}
                    items.array->store->data[median.num + items.array->int_low - items.array->ext_low] = T_6_1.num;
                    }
                    }

  LINE(55);
                    {
                    {
                    if (high.num < items.array->ext_low || high.num > items.array->ext_high) {
                        err = ERR_bounds;
                        goto ex_1;}
                    items.array->store->data[high.num + items.array->int_low - items.array->ext_low] = temp.num;
                    }
                    }

  LINE(56);
                    {
                    CLUREF T_6_1;
                    CLUREF T_6_2;
                    CLUREF T_6_3;
                    CLUREF T_6_4;
                    if (low.num < items.array->ext_low || low.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_6_1.num = items.array->store->data[low.num - items.array->ext_low + items.array->int_low];
                    if (median.num < items.array->ext_low || median.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_6_2.num = items.array->store->data[median.num - items.array->ext_low + items.array->int_low];
                    CUR_PROC_VAR = less;
                    err = less.proc->proc(T_6_1, T_6_2, &T_6_3);
                    if (err != ERR_ok) goto ex_1;
                    T_6_4.num = T_6_3.num ^ 1;
                    if (T_6_4.num == true) {

  LINE(58);
                        {
                        CLUREF T_7_1;
                        if (low.num < items.array->ext_low || low.num > items.array->ext_high ) {
                            err = ERR_bounds;
                            goto ex_1;}
                        T_7_1.num = items.array->store->data[low.num - items.array->ext_low + items.array->int_low];
                        temp.num = T_7_1.num;
                        }

  LINE(59);
                        {
                        CLUREF T_7_1;
                        if (median.num < items.array->ext_low || median.num > items.array->ext_high ) {
                            err = ERR_bounds;
                            goto ex_1;}
                        T_7_1.num = items.array->store->data[median.num - items.array->ext_low + items.array->int_low];
                        {
                        if (low.num < items.array->ext_low || low.num > items.array->ext_high) {
                            err = ERR_bounds;
                            goto ex_1;}
                        items.array->store->data[low.num + items.array->int_low - items.array->ext_low] = T_7_1.num;
                        }
                        }

  LINE(60);
                        {
                        {
                        if (median.num < items.array->ext_low || median.num > items.array->ext_high) {
                            err = ERR_bounds;
                            goto ex_1;}
                        items.array->store->data[median.num + items.array->int_low - items.array->ext_low] = temp.num;
                        }
                        }
                        }
                        }/* end if */
                    }
                    }/* end if */
                }
            else {

  LINE(63);
                {
                CLUREF T_5_1;
                CLUREF T_5_2;
                CLUREF T_5_3;
                if (median.num < items.array->ext_low || median.num > items.array->ext_high ) {
                    err = ERR_bounds;
                    goto ex_1;}
                T_5_1.num = items.array->store->data[median.num - items.array->ext_low + items.array->int_low];
                if (high.num < items.array->ext_low || high.num > items.array->ext_high ) {
                    err = ERR_bounds;
                    goto ex_1;}
                T_5_2.num = items.array->store->data[high.num - items.array->ext_low + items.array->int_low];
                CUR_PROC_VAR = less;
                err = less.proc->proc(T_5_1, T_5_2, &T_5_3);
                if (err != ERR_ok) goto ex_1;
                if (T_5_3.num == true) {

  LINE(65);
                    {
                    CLUREF T_6_1;
                    if (low.num < items.array->ext_low || low.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_6_1.num = items.array->store->data[low.num - items.array->ext_low + items.array->int_low];
                    temp.num = T_6_1.num;
                    }

  LINE(66);
                    {
                    CLUREF T_6_1;
                    if (median.num < items.array->ext_low || median.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_6_1.num = items.array->store->data[median.num - items.array->ext_low + items.array->int_low];
                    {
                    if (low.num < items.array->ext_low || low.num > items.array->ext_high) {
                        err = ERR_bounds;
                        goto ex_1;}
                    items.array->store->data[low.num + items.array->int_low - items.array->ext_low] = T_6_1.num;
                    }
                    }

  LINE(67);
                    {
                    {
                    if (median.num < items.array->ext_low || median.num > items.array->ext_high) {
                        err = ERR_bounds;
                        goto ex_1;}
                    items.array->store->data[median.num + items.array->int_low - items.array->ext_low] = temp.num;
                    }
                    }

  LINE(68);
                    {
                    CLUREF T_6_1;
                    CLUREF T_6_2;
                    CLUREF T_6_3;
                    CLUREF T_6_4;
                    if (median.num < items.array->ext_low || median.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_6_1.num = items.array->store->data[median.num - items.array->ext_low + items.array->int_low];
                    if (high.num < items.array->ext_low || high.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_6_2.num = items.array->store->data[high.num - items.array->ext_low + items.array->int_low];
                    CUR_PROC_VAR = less;
                    err = less.proc->proc(T_6_1, T_6_2, &T_6_3);
                    if (err != ERR_ok) goto ex_1;
                    T_6_4.num = T_6_3.num ^ 1;
                    if (T_6_4.num == true) {

  LINE(70);
                        {
                        CLUREF T_7_1;
                        if (median.num < items.array->ext_low || median.num > items.array->ext_high ) {
                            err = ERR_bounds;
                            goto ex_1;}
                        T_7_1.num = items.array->store->data[median.num - items.array->ext_low + items.array->int_low];
                        temp.num = T_7_1.num;
                        }

  LINE(71);
                        {
                        CLUREF T_7_1;
                        if (high.num < items.array->ext_low || high.num > items.array->ext_high ) {
                            err = ERR_bounds;
                            goto ex_1;}
                        T_7_1.num = items.array->store->data[high.num - items.array->ext_low + items.array->int_low];
                        {
                        if (median.num < items.array->ext_low || median.num > items.array->ext_high) {
                            err = ERR_bounds;
                            goto ex_1;}
                        items.array->store->data[median.num + items.array->int_low - items.array->ext_low] = T_7_1.num;
                        }
                        }

  LINE(72);
                        {
                        {
                        if (high.num < items.array->ext_low || high.num > items.array->ext_high) {
                            err = ERR_bounds;
                            goto ex_1;}
                        items.array->store->data[high.num + items.array->int_low - items.array->ext_low] = temp.num;
                        }
                        }
                        }
                        }/* end if */
                    }
                else {

  LINE(75);
                    {
                    CLUREF T_6_1;
                    if (low.num < items.array->ext_low || low.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_6_1.num = items.array->store->data[low.num - items.array->ext_low + items.array->int_low];
                    temp.num = T_6_1.num;
                    }

  LINE(76);
                    {
                    CLUREF T_6_1;
                    if (high.num < items.array->ext_low || high.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_6_1.num = items.array->store->data[high.num - items.array->ext_low + items.array->int_low];
                    {
                    if (low.num < items.array->ext_low || low.num > items.array->ext_high) {
                        err = ERR_bounds;
                        goto ex_1;}
                    items.array->store->data[low.num + items.array->int_low - items.array->ext_low] = T_6_1.num;
                    }
                    }

  LINE(77);
                    {
                    {
                    if (high.num < items.array->ext_low || high.num > items.array->ext_high) {
                        err = ERR_bounds;
                        goto ex_1;}
                    items.array->store->data[high.num + items.array->int_low - items.array->ext_low] = temp.num;
                    }
                    }
                    }}/* end if */
                }}/* end if */

  LINE(82);
            {
                {CLUREF T_4_1;
                if (median.num < items.array->ext_low || median.num > items.array->ext_high ) {
                    err = ERR_bounds;
                    goto ex_1;}
                T_4_1.num = items.array->store->data[median.num - items.array->ext_low + items.array->int_low];
                miditem.num = T_4_1.num;
                }
                }

  LINE(84);
            {
                {left.num = low.num;
                }
                }

  LINE(85);
            {
                {right.num = high.num;
                }
                }

  LINE(87);
            for (;;) {
                CLUREF T_4_1;
                T_4_1.num = (left.num < right.num)? true : false;
                if (T_4_1.num != true) { break; }

  LINE(89);
                {
                CLUREF T_5_1;
                T_5_1.num = left.num + 1;
                 if ((T_5_1.num > 0 && left.num < 0 && 1 < 0) || 
                     (T_5_1.num < 0 && left.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                left.num = T_5_1.num;
                }

  LINE(90);
                for (;;) {
                    CLUREF T_5_1;
                    CLUREF T_5_2;
                    if (left.num < items.array->ext_low || left.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_5_1.num = items.array->store->data[left.num - items.array->ext_low + items.array->int_low];
                    CUR_PROC_VAR = less;
                    err = less.proc->proc(T_5_1, miditem, &T_5_2);
                    if (err != ERR_ok) goto ex_1;
                    if (T_5_2.num != true) { break; }
                    {
                    CLUREF T_6_1;
                    T_6_1.num = left.num + 1;
                     if ((T_6_1.num > 0 && left.num < 0 && 1 < 0) || 
                         (T_6_1.num < 0 && left.num > 0 && 1 > 0)) {
                        err = ERR_overflow;
                        goto ex_1;}
                    left.num = T_6_1.num;
                    }
                    }
                    end_while_3:;

  LINE(92);
                {
                CLUREF T_5_1;
                T_5_1.num = right.num - 1;
                 if ((T_5_1.num >= 0 && right.num < 0 && (-1) < 0) || 
                     (T_5_1.num <= 0 && right.num > 0 && (-1) > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                right.num = T_5_1.num;
                }

  LINE(93);
                for (;;) {
                    CLUREF T_5_1;
                    CLUREF T_5_2;
                    if (right.num < items.array->ext_low || right.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_5_1.num = items.array->store->data[right.num - items.array->ext_low + items.array->int_low];
                    CUR_PROC_VAR = less;
                    err = less.proc->proc(miditem, T_5_1, &T_5_2);
                    if (err != ERR_ok) goto ex_1;
                    if (T_5_2.num != true) { break; }
                    {
                    CLUREF T_6_1;
                    T_6_1.num = right.num - 1;
                     if ((T_6_1.num >= 0 && right.num < 0 && (-1) < 0) || 
                         (T_6_1.num <= 0 && right.num > 0 && (-1) > 0)) {
                        err = ERR_overflow;
                        goto ex_1;}
                    right.num = T_6_1.num;
                    }
                    }
                    end_while_4:;

  LINE(95);
                {
                CLUREF T_5_1;
                T_5_1.num = (left.num < right.num)? true : false;
                if (T_5_1.num == true) {

  LINE(96);
                    {
                    CLUREF T_6_1;
                    if (left.num < items.array->ext_low || left.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_6_1.num = items.array->store->data[left.num - items.array->ext_low + items.array->int_low];
                    temp.num = T_6_1.num;
                    }

  LINE(97);
                    {
                    CLUREF T_6_1;
                    if (right.num < items.array->ext_low || right.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_6_1.num = items.array->store->data[right.num - items.array->ext_low + items.array->int_low];
                    {
                    if (left.num < items.array->ext_low || left.num > items.array->ext_high) {
                        err = ERR_bounds;
                        goto ex_1;}
                    items.array->store->data[left.num + items.array->int_low - items.array->ext_low] = T_6_1.num;
                    }
                    }

  LINE(98);
                    {
                    {
                    if (right.num < items.array->ext_low || right.num > items.array->ext_high) {
                        err = ERR_bounds;
                        goto ex_1;}
                    items.array->store->data[right.num + items.array->int_low - items.array->ext_low] = temp.num;
                    }
                    }
                    }
                    }/* end if */
                }
                end_while_2:;

  LINE(103);
            {
            CLUREF T_4_1;
            T_4_1.num = right.num + 1;
             if ((T_4_1.num > 0 && right.num < 0 && 1 < 0) || 
                 (T_4_1.num < 0 && right.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            left.num = T_4_1.num;
            }

  LINE(106);
            {
            CLUREF T_4_1;
            T_4_1.num = high.num - left.num;
             if ((T_4_1.num >= 0 && high.num < 0 && (-left.num) < 0) || 
                 (T_4_1.num <= 0 && high.num > 0 && (-left.num) > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            size.num = T_4_1.num;
            }

  LINE(107);
            {
                {CLUREF T_4_1;
                T_4_1.num = right.num - low.num;
                 if ((T_4_1.num >= 0 && right.num < 0 && (-low.num) < 0) || 
                     (T_4_1.num <= 0 && right.num > 0 && (-low.num) > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                smlsize.num = T_4_1.num;
                }
                }

  LINE(109);
            {
            CLUREF T_4_1;
            T_4_1.num = (smlsize.num < size.num)? true : false;
            if (T_4_1.num == true) {

  LINE(110);
                {
                CLUREF T_5_1;
                T_5_1 = low;
                low.num = left.num;
                left.num = T_5_1.num;
                }
                }
            else {

  LINE(111);
                {
                CLUREF T_5_1;
                T_5_1 = right;
                right.num = high.num;
                high.num = T_5_1.num;
                }

  LINE(112);
                {
                CLUREF T_5_1;
                T_5_1 = size;
                size.num = smlsize.num;
                smlsize.num = T_5_1.num;
                }
                }}/* end if */

  LINE(118);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            T_4_1.num = (smlsize.num == 0)? true : false;
            T_4_2.num = T_4_1.num ^ 1;
            if (T_4_2.num == true) {

  LINE(119);
                {
                CLUREF T_5_1;
                T_5_1.num = (smlsize.num < 10)? true : false;
                if (T_5_1.num == true) {

  LINE(120);
                    {
                    generic_CLU_proc.type_owns = 0;
                    generic_CLU_proc.op_owns = (long)op_own_ptr->sisort_of_t_ops->op_owns;
                    generic_CLU_proc.proc = sisort;
                    CUR_PROC_VAR.proc = &generic_CLU_proc;
                    err = sisort(items, left, right, less);
                    if (err != ERR_ok) goto ex_1;
                    }
                    }
                else {

  LINE(121);
                    {
                    generic_CLU_proc.type_owns = 0;
                    generic_CLU_proc.op_owns = (long)op_own_ptr->lqsort_of_t_ops->op_owns;
                    generic_CLU_proc.proc = lqsort;
                    CUR_PROC_VAR.proc = &generic_CLU_proc;
                    err = lqsort(items, left, right, smlsize, less);
                    if (err != ERR_ok) goto ex_1;
                    }
                    }}/* end if */
                }
                }/* end if */
            }
            end_while_1:;

  LINE(127);
        {
        generic_CLU_proc.type_owns = 0;
        generic_CLU_proc.op_owns = (long)op_own_ptr->sisort_of_t_ops->op_owns;
        generic_CLU_proc.proc = sisort;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = sisort(items, low, high, less);
        if (err != ERR_ok) goto ex_1;
        }
        }
    goto end_1;
    ex_1:
        if (err == ERR_bounds) {signal(ERR_bounds);}
        else {
            goto ex_0;}
    end_1:;
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
    }

/**** END PROCEDURE lqsort ****/



typedef struct {
long count;
} sisort_of_t_REQS;

sisort_of_t_REQS sisort_of_t_reqs_actual = {0};

struct REQS * sisort_of_t_reqs = (struct REQS *)&sisort_of_t_reqs_actual;


typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    } sisort_of_t_OPS;

extern errcode intOPfrom_to();
extern errcode intOPle();

typedef struct {
    long sisort_own_init;
    sisort_of_t_OPS *t_ops;
    } sisort_OWN_DEFN;
OWN_req sisort_ownreqs = {sizeof(sisort_OWN_DEFN), 1};


/**** BEGIN PROCEDURE sisort ****/

errcode sisort(items, low, high, less)
CLUREF items;
CLUREF low;
CLUREF high;
CLUREF less;
    {
    errcode err;
    errcode ecode2;
    sisort_OWN_DEFN *op_own_ptr;
    CLUREF top;
    CLUREF item;
    CLUREF hole;
    CLUREF trial;
    op_own_ptr = (sisort_OWN_DEFN*) CUR_PROC_VAR.proc->op_owns;
        if (op_own_ptr->sisort_own_init == 0) {
        op_own_ptr->sisort_own_init = 1;
    }
    enter_proc(136);

  LINE(141);
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    CLUREF T_2_3;
        T_2_1.num = low.num + 1;
         if ((T_2_1.num > 0 && low.num < 0 && 1 < 0) || 
             (T_2_1.num < 0 && low.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_1;}
        T_2_3.num = high.num;
        for (T_2_2.num = T_2_1.num; T_2_2.num <= T_2_3.num; T_2_2.num++) {
            top.num = T_2_2.num;

  LINE(143);
            {
                {CLUREF T_3_1;
                if (top.num < items.array->ext_low || top.num > items.array->ext_high ) {
                    err = ERR_bounds;
                    goto ex_1;}
                T_3_1.num = items.array->store->data[top.num - items.array->ext_low + items.array->int_low];
                item.num = T_3_1.num;
                }
                }

  LINE(145);
            {
                {hole.num = top.num;
                }
                }

  LINE(146);
            {
                {CLUREF T_3_1;
                T_3_1.num = top.num - 1;
                 if ((T_3_1.num >= 0 && top.num < 0 && (-1) < 0) || 
                     (T_3_1.num <= 0 && top.num > 0 && (-1) > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                trial.num = T_3_1.num;
                }
                }

  LINE(148);
            for (;;) {
                CLUREF T_3_1;
                CLUREF T_3_2;
                CLUREF T_3_3;
                CLUREF T_3_4;
                T_3_2.num = (low.num <= trial.num)? true : false;
                T_3_1.num = T_3_2.num;
                if (T_3_2.num) {
                    if (trial.num < items.array->ext_low || trial.num > items.array->ext_high ) {
                        err = ERR_bounds;
                        goto ex_1;}
                    T_3_3.num = items.array->store->data[trial.num - items.array->ext_low + items.array->int_low];
                    CUR_PROC_VAR = less;
                    err = less.proc->proc(item, T_3_3, &T_3_4);
                    if (err != ERR_ok) goto ex_1;
                    T_3_1.num = T_3_4.num;
                }
                if (T_3_1.num != true) { break; }

  LINE(152);
                {
                CLUREF T_4_1;
                if (trial.num < items.array->ext_low || trial.num > items.array->ext_high ) {
                    err = ERR_bounds;
                    goto ex_1;}
                T_4_1.num = items.array->store->data[trial.num - items.array->ext_low + items.array->int_low];
                {
                if (hole.num < items.array->ext_low || hole.num > items.array->ext_high) {
                    err = ERR_bounds;
                    goto ex_1;}
                items.array->store->data[hole.num + items.array->int_low - items.array->ext_low] = T_4_1.num;
                }
                }

  LINE(153);
                {
                hole.num = trial.num;
                }

  LINE(154);
                {
                CLUREF T_4_1;
                T_4_1.num = trial.num - 1;
                 if ((T_4_1.num >= 0 && trial.num < 0 && (-1) < 0) || 
                     (T_4_1.num <= 0 && trial.num > 0 && (-1) > 0)) {
                    err = ERR_overflow;
                    goto ex_1;}
                trial.num = T_4_1.num;
                }
                }
                end_while_1:;

  LINE(158);
            {
            {
            if (hole.num < items.array->ext_low || hole.num > items.array->ext_high) {
                err = ERR_bounds;
                goto ex_1;}
            items.array->store->data[hole.num + items.array->int_low - items.array->ext_low] = item.num;
            }
            }
        }
    }
    end_inline_for_1:;
    goto end_1;
    ex_1:
        if (err == ERR_bounds) {signal(ERR_bounds);}
        else {
            goto ex_0;}
    end_1:;
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
    }

/**** END PROCEDURE sisort ****/

