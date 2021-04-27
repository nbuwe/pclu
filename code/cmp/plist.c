
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"



typedef struct {
long count;
} p_clist_of_t_REQS;

p_clist_of_t_REQS p_clist_of_t_reqs_actual = {0};

struct REQS * p_clist_of_t_reqs = (struct REQS *)&p_clist_of_t_reqs_actual;


typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    } p_clist_of_t_OPS;

extern errcode sequenceOPnew();
extern errcode intOPfrom_to_by();
extern errcode sequenceOPaddh();
extern errcode p_envOPget_peek1();
extern errcode p_envOPnext_token();
extern errcode stringOPconcat();
extern errcode sequenceOPempty();
extern errcode p_envOPassume();
extern errcode p_envOPerr();
extern errcode sequenceOPs2a();
extern errcode arrayOPaddh();
extern errcode sequenceOPa2s();
CLUREF STR__137list;
CLUREF STR_extra_040comma_040at_040end_040of_040;

typedef struct {
    long p_clist_own_init;
    p_clist_of_t_OPS *t_ops;
    } p_clist_OWN_DEFN;
OWN_req p_clist_ownreqs = {sizeof(p_clist_OWN_DEFN), 1};


/**** BEGIN PROCEDURE p_clist ****/

errcode
p_clist(CLUREF e, CLUREF p_t, CLUREF what, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
    p_clist_OWN_DEFN *op_own_ptr;
    CLUREF list;
    CLUREF i;
    CLUREF buf;
    op_own_ptr = (p_clist_OWN_DEFN*) CUR_PROC_VAR.proc->op_owns;
        if (op_own_ptr->p_clist_own_init == 0) {
        stringOPcons("_list", CLU_1, CLU_5, &STR__137list);
        stringOPcons("extra comma at end of ", CLU_1, CLU_22, &STR_extra_040comma_040at_040end_040of_040);
        }
        if (op_own_ptr->p_clist_own_init == 0) {
        op_own_ptr->p_clist_own_init = 1;
    }
    enter_proc(8);

  LINE(12);
    {
        {CLUREF T_1_1;
        err = sequenceOPnew(&T_1_1);
        if (err != ERR_ok) goto ex_0;
        list.num = T_1_1.num;
        }
        }

  LINE(13);
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    CLUREF T_2_3;
        T_2_2.num = 1;
        T_2_3.num = -1;
        for (T_2_1.num = 100; ((T_2_3.num == 0) || ((T_2_3.num > 0)? (T_2_1.num <= T_2_2.num) : (T_2_1.num >= T_2_2.num))); T_2_1.num += T_2_3.num) {
            i.num = T_2_1.num;

  LINE(14);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CUR_PROC_VAR = p_t;
            err = p_t.proc->proc(e, &T_4_1);
            if (err != ERR_ok) goto ex_2;
            err = sequenceOPaddh(list, T_4_1, &T_4_2);
            if (err != ERR_ok) goto ex_2;
            list.num = T_4_2.num;
            }
                goto end_2;
                ex_2:
                    if ((err == ERR_bad)) {
                    }
                    else {
                        goto ex_1;
                    }
                end_2:;

  LINE(16);
            {
            CLUREF T_3_1;
            err = p_envOPget_peek1(e, &T_3_1);
            if (err != ERR_ok) goto ex_1;
            switch (T_3_1.cell->tag) {
            case 3:
                 {

  LINE(17);
                    {
                    CLUREF T_4_1;
                    err = p_envOPnext_token(e, &T_4_1);
                    if (err != ERR_ok) goto ex_1;
                    }
                    break;
                    }
            default: {

  LINE(18);
                {
                {
                ret_1->num = list.num;
                }
                {signal (ERR_ok);}}
            }
            }
            }
        }
    }
    end_inline_for_1:;
        goto end_1;
        ex_1:
            if ((err == ERR_none)) {

  LINE(22);
                {
                CLUREF T_2_1;
                err = stringOPconcat(what, STR__137list, &T_2_1);
                if (err != ERR_ok) goto ex_0;
                what.num = T_2_1.num;
                }

  LINE(23);
                {
                CLUREF T_2_1;
                err = sequenceOPempty(list, &T_2_1);
                if (err != ERR_ok) goto ex_0;
                if (T_2_1.num == true) {

  LINE(24);
                    {
                    err = p_envOPassume(e, what);
                    if (err != ERR_ok) goto ex_0;
                    }
                    }
                else {

  LINE(25);
                    {
                    CLUREF T_3_1;
                    err = stringOPconcat(STR_extra_040comma_040at_040end_040of_040, what, &T_3_1);
                    if (err != ERR_ok) goto ex_0;
                    err = p_envOPerr(e, T_3_1, CLU_1);
                    if (err != ERR_ok) goto ex_0;
                    }
                    }}/* end if */

  LINE(27);
                {
                {
                ret_1->num = list.num;
                }
                {signal (ERR_ok);}}
            }
            else {
                goto ex_0;
            }
        end_1:;

  LINE(29);
    {
        {CLUREF T_1_1;
        err = sequenceOPs2a(list, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        buf.num = T_1_1.num;
        }
        }

  LINE(30);
    for (;;) {
        if (true != true) { break; }

  LINE(31);
        {
        CLUREF T_4_1;
        CUR_PROC_VAR = p_t;
        err = p_t.proc->proc(e, &T_4_1);
        if (err != ERR_ok) goto ex_4;
        {
        if ((buf.array->int_low + buf.array->ext_size + 1) < buf.array->int_size) {
            buf.array->store->data[buf.array->int_low + buf.array->ext_size] = T_4_1.num;
            buf.array->ext_size++; buf.array->ext_high++;}
        else {
            err = arrayOPaddh(buf, T_4_1);
            if (err != ERR_ok) goto ex_4;}
        }
        }
            goto end_4;
            ex_4:
                if ((err == ERR_bad)) {
                }
                else {
                    goto ex_3;
                }
            end_4:;

  LINE(33);
        {
        CLUREF T_3_1;
        err = p_envOPget_peek1(e, &T_3_1);
        if (err != ERR_ok) goto ex_3;
        switch (T_3_1.cell->tag) {
        case 3:
             {

  LINE(34);
                {
                CLUREF T_4_1;
                err = p_envOPnext_token(e, &T_4_1);
                if (err != ERR_ok) goto ex_3;
                }
                break;
                }
        default: {

  LINE(35);
            {
            {
            CLUREF T_4_1;
            err = sequenceOPa2s(buf, &T_4_1);
            if (err != ERR_ok) goto ex_3;
            ret_1->num = T_4_1.num;
            }
            {signal (ERR_ok);}}
        }
        }
        }
        }
        end_while_1:;
        goto end_3;
        ex_3:
            if ((err == ERR_none)) {
            }
            else {
                goto ex_0;
            }
        end_3:;

  LINE(39);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    err = stringOPconcat(STR_extra_040comma_040at_040end_040of_040, what, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = stringOPconcat(T_1_1, STR__137list, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    err = p_envOPerr(e, T_1_2, CLU_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(40);
    {
    {
    CLUREF T_1_1;
    err = sequenceOPa2s(buf, &T_1_1);
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
    end_0: elist[0] = no_return_values_STRING;
        {signal(ERR_failure);}
    }

/**** END PROCEDURE p_clist ****/



typedef struct {
long count;
} p_slist_of_t_REQS;

p_slist_of_t_REQS p_slist_of_t_reqs_actual = {0};

struct REQS * p_slist_of_t_reqs = (struct REQS *)&p_slist_of_t_reqs_actual;


typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    } p_slist_of_t_OPS;

extern errcode p_semi();

typedef struct {
    long p_slist_own_init;
    p_slist_of_t_OPS *t_ops;
    } p_slist_OWN_DEFN;
OWN_req p_slist_ownreqs = {sizeof(p_slist_OWN_DEFN), 1};


/**** BEGIN PROCEDURE p_slist ****/

errcode
p_slist(CLUREF e, CLUREF p_t, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
    p_slist_OWN_DEFN *op_own_ptr;
    CLUREF list;
    op_own_ptr = (p_slist_OWN_DEFN*) CUR_PROC_VAR.proc->op_owns;
        if (op_own_ptr->p_slist_own_init == 0) {
        op_own_ptr->p_slist_own_init = 1;
    }
    enter_proc(45);

  LINE(48);
    {
        {CLUREF T_1_1;
        err = sequenceOPnew(&T_1_1);
        if (err != ERR_ok) goto ex_0;
        list.num = T_1_1.num;
        }
        }

  LINE(49);
    for (;;) {
        if (true != true) { break; }

  LINE(50);
        {
        CLUREF T_4_1;
        CLUREF T_4_2;
        CUR_PROC_VAR = p_t;
        err = p_t.proc->proc(e, &T_4_1);
        if (err != ERR_ok) goto ex_2;
        err = sequenceOPaddh(list, T_4_1, &T_4_2);
        if (err != ERR_ok) goto ex_2;
        list.num = T_4_2.num;
        }
            goto end_2;
            ex_2:
                if ((err == ERR_bad)) {
                }
                else {
                    goto ex_1;
                }
            end_2:;

  LINE(52);
        {
        err = p_semi(e);
        if (err != ERR_ok) goto ex_1;
        }
        }
        end_while_1:;
        goto end_1;
        ex_1:
            if ((err == ERR_none)) {

  LINE(54);
                {
                {
                ret_1->num = list.num;
                }
                {signal (ERR_ok);}}
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
    end_0: elist[0] = no_return_values_STRING;
        {signal(ERR_failure);}
    }

/**** END PROCEDURE p_slist ****/



typedef struct {
long count;
} p_list_of_t_REQS;

p_list_of_t_REQS p_list_of_t_reqs_actual = {0};

struct REQS * p_list_of_t_reqs = (struct REQS *)&p_list_of_t_reqs_actual;


typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    } p_list_of_t_OPS;

extern errcode boolOPnot();

typedef struct {
    long p_list_own_init;
    p_list_of_t_OPS *t_ops;
    } p_list_OWN_DEFN;
OWN_req p_list_ownreqs = {sizeof(p_list_OWN_DEFN), 1};


/**** BEGIN PROCEDURE p_list ****/

errcode
p_list(CLUREF e, CLUREF p_t, CLUREF emptyok, CLUREF what, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
    p_list_OWN_DEFN *op_own_ptr;
    CLUREF list;
    op_own_ptr = (p_list_OWN_DEFN*) CUR_PROC_VAR.proc->op_owns;
        if (op_own_ptr->p_list_own_init == 0) {
        stringOPcons("_list", CLU_1, CLU_5, &STR__137list);
        }
        if (op_own_ptr->p_list_own_init == 0) {
        op_own_ptr->p_list_own_init = 1;
    }
    enter_proc(60);

  LINE(64);
    {
        {CLUREF T_1_1;
        err = sequenceOPnew(&T_1_1);
        if (err != ERR_ok) goto ex_0;
        list.num = T_1_1.num;
        }
        }

  LINE(65);
    for (;;) {
        if (true != true) { break; }

  LINE(66);
        {
        CLUREF T_4_1;
        CLUREF T_4_2;
        CUR_PROC_VAR = p_t;
        err = p_t.proc->proc(e, &T_4_1);
        if (err != ERR_ok) goto ex_2;
        err = sequenceOPaddh(list, T_4_1, &T_4_2);
        if (err != ERR_ok) goto ex_2;
        list.num = T_4_2.num;
        }
            goto end_2;
            ex_2:
                if ((err == ERR_bad)) {
                }
                else {
                    goto ex_1;
                }
            end_2:;
        }
        end_while_1:;
        goto end_1;
        ex_1:
            if ((err == ERR_none)) {
            }
            else {
                goto ex_0;
            }
        end_1:;

  LINE(70);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_2.num = emptyok.num ^ 1;
    T_1_1.num = T_1_2.num;
    if (T_1_2.num) {
        err = sequenceOPempty(list, &T_1_3);
        if (err != ERR_ok) goto ex_0;
        T_1_1.num = T_1_3.num;
    }
    if (T_1_1.num == true) {

  LINE(71);
        {
        CLUREF T_2_1;
        err = stringOPconcat(what, STR__137list, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        err = p_envOPassume(e, T_2_1);
        if (err != ERR_ok) goto ex_0;
        }
        }
        }/* end if */

  LINE(72);
    {
    {
    ret_1->num = list.num;
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

/**** END PROCEDURE p_list ****/



typedef struct {
long count;
} p_blist_of_t_REQS;

p_blist_of_t_REQS p_blist_of_t_reqs_actual = {0};

struct REQS * p_blist_of_t_reqs = (struct REQS *)&p_blist_of_t_reqs_actual;


typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    } p_blist_of_t_OPS;

extern errcode p_clist();
extern struct REQS *p_clist_of_t_reqs;
extern OWN_req p_clist_ownreqs;
CLUREF STR__133;
CLUREF STR__137list_135;
CLUREF STR__135_040in_040_133;

typedef struct {
    long p_blist_own_init;
    p_blist_of_t_OPS *t_ops;
    struct OPS *p_clist_of_t_table;
    struct OPS *p_clist_of_t_ops;
    OWNPTR p_clist_of_t_owns;
    } p_blist_OWN_DEFN;
OWN_req p_blist_ownreqs = {sizeof(p_blist_OWN_DEFN), 1};


/**** BEGIN PROCEDURE p_blist ****/

errcode
p_blist(CLUREF e, CLUREF p_t, CLUREF noneok, CLUREF what, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
    p_blist_OWN_DEFN *op_own_ptr;
    CLUREF list;
    op_own_ptr = (p_blist_OWN_DEFN*) CUR_PROC_VAR.proc->op_owns;
        if (op_own_ptr->p_blist_own_init == 0) {
        add_parm_info_type(0, op_own_ptr->t_ops, p_clist_of_t_reqs);
        find_prociter_instance(p_clist, 1, &p_clist_ownreqs, &(op_own_ptr->p_clist_of_t_ops));
        stringOPcons("[", CLU_1, CLU_1, &STR__133);
        stringOPcons("_list]", CLU_1, CLU_6, &STR__137list_135);
        stringOPcons("] in [", CLU_1, CLU_6, &STR__135_040in_040_133);
        }
        if (op_own_ptr->p_blist_own_init == 0) {
        op_own_ptr->p_blist_own_init = 1;
    }
    enter_proc(78);

  LINE(82);
    {
    CLUREF T_1_1;
    err = p_envOPget_peek1(e, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    switch (T_1_1.cell->tag) {
    case 19:
         {

  LINE(83);
            {
            CLUREF T_2_1;
            err = p_envOPnext_token(e, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            }
            break;
            }
    default: {

  LINE(84);
        {
        CLUREF T_2_1;
        T_2_1.num = noneok.num ^ 1;
        if (T_2_1.num == true) {

  LINE(85);
            {
            CLUREF T_3_1;
            CLUREF T_3_2;
            err = stringOPconcat(STR__133, what, &T_3_1);
            if (err != ERR_ok) goto ex_0;
            err = stringOPconcat(T_3_1, STR__137list_135, &T_3_2);
            if (err != ERR_ok) goto ex_0;
            err = p_envOPassume(e, T_3_2);
            if (err != ERR_ok) goto ex_0;
            }
            }
            }/* end if */

  LINE(86);
        {
        {
        CLUREF T_2_1;
        err = sequenceOPnew(&T_2_1);
        if (err != ERR_ok) goto ex_0;
        ret_1->num = T_2_1.num;
        }
        {signal (ERR_ok);}}
    }
    }
    }

  LINE(88);
    {
        {CLUREF T_1_1;
        generic_CLU_proc.type_owns = 0;
        generic_CLU_proc.op_owns = (long)op_own_ptr->p_clist_of_t_ops->op_owns;
        generic_CLU_proc.proc = p_clist;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = p_clist(e, p_t, what, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        list.num = T_1_1.num;
        }
        }

  LINE(89);
    {
    CLUREF T_1_1;
    err = p_envOPget_peek1(e, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    switch (T_1_1.cell->tag) {
    case 26:
         {

  LINE(90);
            {
            CLUREF T_2_1;
            err = p_envOPnext_token(e, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            }
            break;
            }
    default: {

  LINE(91);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        err = stringOPconcat(STR__135_040in_040_133, what, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        err = stringOPconcat(T_2_1, STR__137list_135, &T_2_2);
        if (err != ERR_ok) goto ex_0;
        err = p_envOPassume(e, T_2_2);
        if (err != ERR_ok) goto ex_0;
        }
    }
    }
    }

  LINE(93);
    {
    {
    ret_1->num = list.num;
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

/**** END PROCEDURE p_blist ****/



typedef struct {
long count;
} p_plist_of_t_REQS;

p_plist_of_t_REQS p_plist_of_t_reqs_actual = {0};

struct REQS * p_plist_of_t_reqs = (struct REQS *)&p_plist_of_t_reqs_actual;


typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    } p_plist_of_t_OPS;

CLUREF STR__050;
CLUREF STR__137list_051;
CLUREF STR__051_040in_040_050;

typedef struct {
    long p_plist_own_init;
    p_plist_of_t_OPS *t_ops;
    struct OPS *p_clist_of_t_table;
    struct OPS *p_clist_of_t_ops;
    OWNPTR p_clist_of_t_owns;
    } p_plist_OWN_DEFN;
OWN_req p_plist_ownreqs = {sizeof(p_plist_OWN_DEFN), 1};


/**** BEGIN PROCEDURE p_plist ****/

errcode
p_plist(CLUREF e, CLUREF p_t, CLUREF noneok, CLUREF emptyok, CLUREF what, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
    p_plist_OWN_DEFN *op_own_ptr;
    CLUREF list;
    op_own_ptr = (p_plist_OWN_DEFN*) CUR_PROC_VAR.proc->op_owns;
        if (op_own_ptr->p_plist_own_init == 0) {
        add_parm_info_type(0, op_own_ptr->t_ops, p_clist_of_t_reqs);
        find_prociter_instance(p_clist, 1, &p_clist_ownreqs, &(op_own_ptr->p_clist_of_t_ops));
        stringOPcons("(", CLU_1, CLU_1, &STR__050);
        stringOPcons("_list)", CLU_1, CLU_6, &STR__137list_051);
        stringOPcons(") in (", CLU_1, CLU_6, &STR__051_040in_040_050);
        }
        if (op_own_ptr->p_plist_own_init == 0) {
        op_own_ptr->p_plist_own_init = 1;
    }
    enter_proc(100);

  LINE(104);
    {
    CLUREF T_1_1;
    err = p_envOPget_peek1(e, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    switch (T_1_1.cell->tag) {
    case 21:
         {

  LINE(105);
            {
            CLUREF T_2_1;
            err = p_envOPnext_token(e, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            }
            break;
            }
    default: {

  LINE(106);
        {
        CLUREF T_2_1;
        T_2_1.num = noneok.num ^ 1;
        if (T_2_1.num == true) {

  LINE(107);
            {
            CLUREF T_3_1;
            CLUREF T_3_2;
            err = stringOPconcat(STR__050, what, &T_3_1);
            if (err != ERR_ok) goto ex_0;
            err = stringOPconcat(T_3_1, STR__137list_051, &T_3_2);
            if (err != ERR_ok) goto ex_0;
            err = p_envOPassume(e, T_3_2);
            if (err != ERR_ok) goto ex_0;
            }
            }
            }/* end if */

  LINE(108);
        {
        {
        CLUREF T_2_1;
        err = sequenceOPnew(&T_2_1);
        if (err != ERR_ok) goto ex_0;
        ret_1->num = T_2_1.num;
        }
        {signal (ERR_ok);}}
    }
    }
    }

  LINE(110);
    {
    if (emptyok.num == true) {

  LINE(111);
        {
        CLUREF T_2_1;
        err = p_envOPget_peek1(e, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        switch (T_2_1.cell->tag) {
        case 28:
             {

  LINE(112);
                {
                CLUREF T_3_1;
                err = p_envOPnext_token(e, &T_3_1);
                if (err != ERR_ok) goto ex_0;
                }

  LINE(113);
                {
                {
                CLUREF T_3_1;
                err = sequenceOPnew(&T_3_1);
                if (err != ERR_ok) goto ex_0;
                ret_1->num = T_3_1.num;
                }
                {signal (ERR_ok);}}
                break;
                }
        default: {
        }
        }
        }
        }
        }/* end if */

  LINE(117);
    {
        {CLUREF T_1_1;
        generic_CLU_proc.type_owns = 0;
        generic_CLU_proc.op_owns = (long)op_own_ptr->p_clist_of_t_ops->op_owns;
        generic_CLU_proc.proc = p_clist;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = p_clist(e, p_t, what, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        list.num = T_1_1.num;
        }
        }

  LINE(118);
    {
    CLUREF T_1_1;
    err = p_envOPget_peek1(e, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    switch (T_1_1.cell->tag) {
    case 28:
         {

  LINE(119);
            {
            CLUREF T_2_1;
            err = p_envOPnext_token(e, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            }
            break;
            }
    default: {

  LINE(120);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        err = stringOPconcat(STR__051_040in_040_050, what, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        err = stringOPconcat(T_2_1, STR__137list_051, &T_2_2);
        if (err != ERR_ok) goto ex_0;
        err = p_envOPassume(e, T_2_2);
        if (err != ERR_ok) goto ex_0;
        }
    }
    }
    }

  LINE(122);
    {
    {
    ret_1->num = list.num;
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

/**** END PROCEDURE p_plist ****/

