
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN CLUSTER heap ****/


typedef struct {
long count;
} heap_of_t_REQS;

heap_of_t_REQS heap_of_t_reqs_actual = {0};

struct REQS * heap_of_t_reqs = (struct REQS *)&heap_of_t_reqs_actual;


typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    } heap_of_t_OPS;

extern errcode arrayOPcreate();
extern errcode arrayOPbottom();
extern errcode recordOPget_1();
extern errcode arrayOPsize();
extern errcode intOPequal();
extern errcode recordOPget_2();
extern errcode arrayOPaddh();
extern errcode arrayOPhigh();
extern errcode intOPdiv();
extern errcode intOPgt();
extern errcode arrayOPfetch();
extern errcode arrayOPstore();
extern errcode arrayOPremh();
extern errcode intOPle();
extern errcode intOPmul();
extern errcode intOPlt();
extern errcode intOPadd();
extern errcode recordOPcopy1();
extern errcode recordOPset_1();
extern errcode arrayOPcopy1();

OWN_ptr heap_own_init; /* dummy */
typedef struct {
    long heap_own_init;
    long create_own_init;
    long top_own_init;
    long size_own_init;
    long empty_own_init;
    long insert_own_init;
    long remove_own_init;
    long copy_own_init;
    heap_of_t_OPS *t_ops;
} heap_OWN_DEFN;

OWN_req heap_ownreqs = {sizeof(heap_OWN_DEFN), 8};

errcode heap_own_init_proc()
{
errcode err;
heap_OWN_DEFN *type_own_ptr = (heap_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;

enter_own_init_proc();
    if (type_own_ptr->heap_own_init == 0) {
    type_own_ptr->heap_own_init = 1;
    {signal(ERR_ok);}
    ex_0: pclu_unhandled(err); {signal(ERR_failure);}
}
}


/**** BEGIN PROCEDURE create ****/

errcode heapOPcreate(p, ret_1)
CLUREF p;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    heap_OWN_DEFN *type_own_ptr;
    type_own_ptr = (heap_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->create_own_init == 0) {
        type_own_ptr->create_own_init = 1;
    }
    enter_proc(45);

  LINE(46);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    RecordAlloc(2, T_1_1);
    err = arrayOPcreate(CLU_1, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    T_1_1.vec->data[0]  = T_1_2.num;
    T_1_1.vec->data[1]  = p.num;
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

/**** END PROCEDURE create ****/


/**** BEGIN PROCEDURE top ****/

errcode heapOPtop(x, ret_1)
CLUREF x;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    heap_OWN_DEFN *type_own_ptr;
    type_own_ptr = (heap_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->top_own_init == 0) {
        type_own_ptr->top_own_init = 1;
    }
    enter_proc(49);

  LINE(50);
    {
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    T_2_1.num = x.vec->data[0];
    err = arrayOPbottom(T_2_1, &T_2_2);
    if (err != ERR_ok) goto ex_1;
    ret_1->num = T_2_2.num;
    }
    {signal (ERR_ok);}}
        goto end_1;
        ex_1:
            if ((err == ERR_bounds)) {

  LINE(51);
                {
                {signal (ERR_empty);}}
            }
            else {
                goto ex_0;
            }
        end_1:;
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

/**** END PROCEDURE top ****/


/**** BEGIN PROCEDURE size ****/

errcode heapOPsize(x, ret_1)
CLUREF x;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    heap_OWN_DEFN *type_own_ptr;
    type_own_ptr = (heap_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->size_own_init == 0) {
        type_own_ptr->size_own_init = 1;
    }
    enter_proc(54);

  LINE(55);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = x.vec->data[0];
    T_1_2.num = T_1_1.array->ext_size;
    ret_1->num = T_1_2.num;
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

/**** END PROCEDURE size ****/


/**** BEGIN PROCEDURE empty ****/

errcode heapOPempty(x, ret_1)
CLUREF x;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    heap_OWN_DEFN *type_own_ptr;
    type_own_ptr = (heap_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->empty_own_init == 0) {
        type_own_ptr->empty_own_init = 1;
    }
    enter_proc(58);

  LINE(59);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_1.num = x.vec->data[0];
    T_1_2.num = T_1_1.array->ext_size;
    T_1_3.num = (T_1_2.num == 0)? true : false;
    ret_1->num = T_1_3.num;
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

/**** END PROCEDURE empty ****/


/**** BEGIN PROCEDURE insert ****/

errcode heapOPinsert(x, v)
CLUREF x;
CLUREF v;
    {
    errcode err;
    errcode ecode2;
    heap_OWN_DEFN *type_own_ptr;
    CLUREF a;
    CLUREF p;
    CLUREF son;
    CLUREF dad;
    type_own_ptr = (heap_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->insert_own_init == 0) {
        type_own_ptr->insert_own_init = 1;
    }
    enter_proc(62);

  LINE(63);
    {
        {CLUREF T_1_1;
        T_1_1.num = x.vec->data[0];
        a.num = T_1_1.num;
        }
        }

  LINE(64);
    {
        {CLUREF T_1_1;
        T_1_1.num = x.vec->data[1];
        p.num = T_1_1.num;
        }
        }

  LINE(65);
    {
    {
    if ((a.array->int_low + a.array->ext_size + 1) < a.array->int_size) {
        a.array->store->data[a.array->int_low + a.array->ext_size] = v.num;
        a.array->ext_size++; a.array->ext_high++;}
    else {
        err = arrayOPaddh(a, v);
        if (err != ERR_ok) goto ex_0;}
    }
    }

  LINE(66);
    {
        {CLUREF T_1_1;
        T_1_1.num = a.array->ext_high;
        son.num = T_1_1.num;
        }
        }

  LINE(67);
    {
        {CLUREF T_1_1;
        err = intOPdiv(son, CLU_2, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        dad.num = T_1_1.num;
        }
        }

  LINE(68);
    for (;;) {
        CLUREF T_1_1;
        CLUREF T_1_2;
        CLUREF T_1_3;
        CLUREF T_1_4;
        T_1_2.num = (dad.num > 0)? true : false;
        T_1_1.num = T_1_2.num;
        if (T_1_2.num) {
            if (dad.num < a.array->ext_low || dad.num > a.array->ext_high ) {
                err = ERR_bounds;
                goto ex_0;}
            T_1_3.num = a.array->store->data[dad.num - a.array->ext_low + a.array->int_low];
            CUR_PROC_VAR = p;
            err = p.proc->proc(v, T_1_3, &T_1_4);
            if (err != ERR_ok) goto ex_0;
            T_1_1.num = T_1_4.num;
        }
        if (T_1_1.num != true) { break; }

  LINE(69);
        {
        CLUREF T_2_1;
        if (dad.num < a.array->ext_low || dad.num > a.array->ext_high ) {
            err = ERR_bounds;
            goto ex_0;}
        T_2_1.num = a.array->store->data[dad.num - a.array->ext_low + a.array->int_low];
        {
        if (son.num < a.array->ext_low || son.num > a.array->ext_high) {
            err = ERR_bounds;
            goto ex_0;}
        a.array->store->data[son.num + a.array->int_low - a.array->ext_low] = T_2_1.num;
        }
        }

  LINE(70);
        {
        CLUREF T_2_1;
        err = intOPdiv(dad, CLU_2, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        son.num = dad.num;
        dad.num = T_2_1.num;
        }
        }
        end_while_1:;

  LINE(72);
    {
    {
    if (son.num < a.array->ext_low || son.num > a.array->ext_high) {
        err = ERR_bounds;
        goto ex_0;}
    a.array->store->data[son.num + a.array->int_low - a.array->ext_low] = v.num;
    }
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

/**** END PROCEDURE insert ****/


/**** BEGIN PROCEDURE remove ****/

errcode heapOPremove(x, ret_1)
CLUREF x;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    heap_OWN_DEFN *type_own_ptr;
    CLUREF a;
    CLUREF p;
    CLUREF r;
    CLUREF v;
    CLUREF max_son;
    CLUREF max_dad;
    CLUREF dad;
    CLUREF son;
    CLUREF s;
    CLUREF ns;
    type_own_ptr = (heap_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->remove_own_init == 0) {
        type_own_ptr->remove_own_init = 1;
    }
    enter_proc(75);

  LINE(76);
    {
        {CLUREF T_1_1;
        T_1_1.num = x.vec->data[0];
        a.num = T_1_1.num;
        }
        }

  LINE(77);
    {
        {CLUREF T_1_1;
        T_1_1.num = x.vec->data[1];
        p.num = T_1_1.num;
        }
        }

  LINE(78);
    {
        {CLUREF T_2_1;
        err = arrayOPbottom(a, &T_2_1);
        if (err != ERR_ok) goto ex_1;
        r.num = T_2_1.num;
        }
        }
        goto end_1;
        ex_1:
            if ((err == ERR_bounds)) {

  LINE(79);
                {
                {signal (ERR_empty);}}
            }
            else {
                goto ex_0;
            }
        end_1:;

  LINE(80);
    {
        {CLUREF T_1_1;
        err = arrayOPremh(a, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        v.num = T_1_1.num;
        }
        }

  LINE(81);
    {
        {CLUREF T_1_1;
        T_1_1.num = a.array->ext_size;
        max_son.num = T_1_1.num;
        }
        }

  LINE(82);
    {
    CLUREF T_1_1;
    T_1_1.num = (max_son.num == 0)? true : false;
    if (T_1_1.num == true) {
        {
        {
        ret_1->num = r.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(83);
    {
        {CLUREF T_1_1;
        err = intOPdiv(max_son, CLU_2, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        max_dad.num = T_1_1.num;
        }
        }

  LINE(84);
    {
        {dad.num = 1;
        }
        }

  LINE(85);
    for (;;) {
        CLUREF T_1_1;
        T_1_1.num = (dad.num <= max_dad.num)? true : false;
        if (T_1_1.num != true) { break; }

  LINE(86);
        {
            {CLUREF T_2_1;
            err = intOPmul(dad, CLU_2, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            son.num = T_2_1.num;
            }
            }

  LINE(87);
        {
            {CLUREF T_2_1;
            if (son.num < a.array->ext_low || son.num > a.array->ext_high ) {
                err = ERR_bounds;
                goto ex_0;}
            T_2_1.num = a.array->store->data[son.num - a.array->ext_low + a.array->int_low];
            s.num = T_2_1.num;
            }
            }

  LINE(88);
        {
        CLUREF T_2_1;
        T_2_1.num = (son.num < max_son.num)? true : false;
        if (T_2_1.num == true) {

  LINE(90);
            {
                {CLUREF T_3_1;
                CLUREF T_3_2;
                T_3_1.num = son.num + 1;
                 if ((T_3_1.num > 0 && son.num < 0 && 1 < 0) || 
                     (T_3_1.num < 0 && son.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_0;}
                if (T_3_1.num < a.array->ext_low || T_3_1.num > a.array->ext_high ) {
                    err = ERR_bounds;
                    goto ex_0;}
                T_3_2.num = a.array->store->data[T_3_1.num - a.array->ext_low + a.array->int_low];
                ns.num = T_3_2.num;
                }
                }

  LINE(91);
            {
            CLUREF T_3_1;
            CUR_PROC_VAR = p;
            err = p.proc->proc(ns, s, &T_3_1);
            if (err != ERR_ok) goto ex_0;
            if (T_3_1.num == true) {
                {
                CLUREF T_4_1;
                T_4_1.num = son.num + 1;
                 if ((T_4_1.num > 0 && son.num < 0 && 1 < 0) || 
                     (T_4_1.num < 0 && son.num > 0 && 1 > 0)) {
                    err = ERR_overflow;
                    goto ex_0;}
                son.num = T_4_1.num;
                s.num = ns.num;
                }
                }
                }/* end if */
            }
            }/* end if */

  LINE(93);
        {
        CLUREF T_2_1;
        CUR_PROC_VAR = p;
        err = p.proc->proc(v, s, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        if (T_2_1.num == true) {
            goto end_while_1;
            }
            }/* end if */

  LINE(94);
        {
        {
        if (dad.num < a.array->ext_low || dad.num > a.array->ext_high) {
            err = ERR_bounds;
            goto ex_0;}
        a.array->store->data[dad.num + a.array->int_low - a.array->ext_low] = s.num;
        }
        }

  LINE(95);
        {
        dad.num = son.num;
        }
        }
        end_while_1:;

  LINE(97);
    {
    {
    if (dad.num < a.array->ext_low || dad.num > a.array->ext_high) {
        err = ERR_bounds;
        goto ex_0;}
    a.array->store->data[dad.num + a.array->int_low - a.array->ext_low] = v.num;
    }
    }

  LINE(98);
    {
    {
    ret_1->num = r.num;
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

/**** END PROCEDURE remove ****/


/**** BEGIN PROCEDURE copy ****/

errcode heapOPcopy(x, ret_1)
CLUREF x;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    heap_OWN_DEFN *type_own_ptr;
    type_own_ptr = (heap_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->copy_own_init == 0) {
        type_own_ptr->copy_own_init = 1;
    }
    enter_proc(101);

  LINE(102);
    {
    CLUREF T_1_1;
    generic_CLU_proc.type_owns = 0;
    generic_CLU_proc.proc = recordOPcopy1;
    CUR_PROC_VAR.proc = &generic_CLU_proc;
    err = recordOPcopy1(x, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    x.num = T_1_1.num;
    }

  LINE(103);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = x.vec->data[0];
    err = arrayOPcopy1(T_1_1, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    x.vec->data[0]  = T_1_2.num;
    }

  LINE(104);
    {
    {
    ret_1->num = x.num;
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

/**** END PROCEDURE copy ****/

typedef struct{
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[7];
} heap_OPS;

CLU_proc heap_oe_copy = {{0,0,0,0}, heapOPcopy, 0};
CLU_proc heap_oe_create = {{0,0,0,0}, heapOPcreate, 0};
CLU_proc heap_oe_empty = {{0,0,0,0}, heapOPempty, 0};
CLU_proc heap_oe_insert = {{0,0,0,0}, heapOPinsert, 0};
CLU_proc heap_oe_remove = {{0,0,0,0}, heapOPremove, 0};
CLU_proc heap_oe_size = {{0,0,0,0}, heapOPsize, 0};
CLU_proc heap_oe_top = {{0,0,0,0}, heapOPtop, 0};

heap_OPS heap_ops_actual = {7, (OWNPTR)&heap_own_init, (OWNPTR)&heap_own_init, {
    {&heap_oe_copy, "copy"},
    {&heap_oe_create, "create"},
    {&heap_oe_empty, "empty"},
    {&heap_oe_insert, "insert"},
    {&heap_oe_remove, "remove"},
    {&heap_oe_size, "size"},
    {&heap_oe_top, "top"}}};

struct OPS *heap_ops = (struct OPS *)&heap_ops_actual;

/**** END CLUSTER heap ****/
