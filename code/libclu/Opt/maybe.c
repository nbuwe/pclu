
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"

/**** BEGIN CLUSTER maybe ****/


typedef struct {
long count;
    char *equal_name;
    char *similar_name;
    char *copy_name;
    char *_gcd_name;
} maybe_of_t_REQS;

maybe_of_t_REQS maybe_of_t_reqs_actual = {4,
    "equal", "similar", "copy", "_gcd"};

struct REQS * maybe_of_t_reqs = (struct REQS *)&maybe_of_t_reqs_actual;

typedef struct {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY equal;
    struct OP_ENTRY similar;
    struct OP_ENTRY copy;
    struct OP_ENTRY _gcd;
} maybe_of_t_OPS;
extern errcode intOPequal();
extern errcode _cvt();
extern errcode boolOPnot();
extern errcode intOP_gcd();
CLUREF STR_Bad_040value_040for_040maybe_044make_056;

OWN_ptr maybe_own_init; /* dummy */
typedef struct {
    long maybe_own_init;
    long none_own_init;
    long make_own_init;
    long exists_own_init;
    long value_own_init;
    long equal_own_init;
    long similar_own_init;
    long copy_own_init;
    long _gcd_own_init;
    maybe_of_t_OPS *t_ops;
} maybe_OWN_DEFN;

OWN_req maybe_ownreqs = {sizeof(maybe_OWN_DEFN), 9};

errcode maybe_own_init_proc()
{
errcode err;
maybe_OWN_DEFN *type_own_ptr = (maybe_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;

enter_own_init_proc();
    if (type_own_ptr->maybe_own_init == 0) {
    stringOPcons("Bad value for maybe$make.", CLU_1, CLU_25, &STR_Bad_040value_040for_040maybe_044make_056);
    }
    if (type_own_ptr->maybe_own_init == 0) {
    type_own_ptr->maybe_own_init = 1;
    {signal(ERR_ok);}
    ex_0: pclu_unhandled(err); {signal(ERR_failure);}
}
}


/**** BEGIN PROCEDURE none ****/

errcode maybeOPnone(ret_1)
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    maybe_OWN_DEFN *type_own_ptr;
    type_own_ptr = (maybe_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->none_own_init == 0) {
        type_own_ptr->none_own_init = 1;
    }
    enter_proc(20);

  LINE(23);
    {
    {
    ret_1->num = -2147483648;
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

/**** END PROCEDURE none ****/


/**** BEGIN PROCEDURE make ****/

errcode maybeOPmake(x, ret_1)
CLUREF x;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    maybe_OWN_DEFN *type_own_ptr;
    type_own_ptr = (maybe_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->make_own_init == 0) {
        stringOPcons("Bad value for maybe$make.", CLU_1, CLU_25, &STR_Bad_040value_040for_040maybe_044make_056);
        }
        if (type_own_ptr->make_own_init == 0) {
        type_own_ptr->make_own_init = 1;
    }
    enter_proc(26);

  LINE(29);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_1.num = x.num;
    T_1_2.num = -2147483648;
    T_1_3.num = (T_1_1.num == T_1_2.num)? true : false;
    if (T_1_3.num == true) {

  LINE(30);
        {
        elist[0] = STR_Bad_040value_040for_040maybe_044make_056;
        {signal (ERR_failure);}}
        }
        }/* end if */

  LINE(32);
    {
    {
    CLUREF T_1_1;
    T_1_1.num = x.num;
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

/**** END PROCEDURE make ****/


/**** BEGIN PROCEDURE exists ****/

errcode maybeOPexists(m, ret_1)
CLUREF m;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    maybe_OWN_DEFN *type_own_ptr;
    type_own_ptr = (maybe_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->exists_own_init == 0) {
        type_own_ptr->exists_own_init = 1;
    }
    enter_proc(35);

  LINE(37);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_1.num = -2147483648;
    T_1_2.num = (m.num == T_1_1.num)? true : false;
    T_1_3.num = T_1_2.num ^ 1;
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

/**** END PROCEDURE exists ****/


/**** BEGIN PROCEDURE value ****/

errcode maybeOPvalue(m, ret_1)
CLUREF m;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    maybe_OWN_DEFN *type_own_ptr;
    type_own_ptr = (maybe_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->value_own_init == 0) {
        type_own_ptr->value_own_init = 1;
    }
    enter_proc(40);

  LINE(43);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = -2147483648;
    T_1_2.num = (m.num == T_1_1.num)? true : false;
    if (T_1_2.num == true) {

  LINE(44);
        {
        {signal (ERR_wrong_tag);}}
        }
        }/* end if */

  LINE(46);
    {
    {
    CLUREF T_1_1;
    T_1_1.num = m.num;
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

/**** END PROCEDURE value ****/


/**** BEGIN PROCEDURE equal ****/

errcode maybeOPequal(m1, m2, ret_1)
CLUREF m1;
CLUREF m2;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    maybe_OWN_DEFN *type_own_ptr;
    type_own_ptr = (maybe_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->equal_own_init == 0) {
        type_own_ptr->equal_own_init = 1;
    }
    enter_proc(49);

  LINE(54);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = -2147483648;
    T_1_2.num = (m1.num == T_1_1.num)? true : false;
    if (T_1_2.num == true) {

  LINE(55);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = -2147483648;
        T_2_2.num = (m2.num == T_2_1.num)? true : false;
        if (T_2_2.num == true) {
            {
            {
            ret_1->tf = true;
            }
            {signal (ERR_ok);}}
            }
        else {
            {
            {
            ret_1->tf = false;
            }
            {signal (ERR_ok);}}
            }}/* end if */
        }
        }/* end if */

  LINE(57);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = -2147483648;
    T_1_2.num = (m2.num == T_1_1.num)? true : false;
    if (T_1_2.num == true) {
        {
        {
        ret_1->tf = false;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(58);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = m1.num;
    T_1_2.num = m2.num;
    T_1_4.proc = type_own_ptr->t_ops->equal.fcn;
    CUR_PROC_VAR = T_1_4;
    err = T_1_4.proc->proc(T_1_1, T_1_2, &T_1_3);
    if (err != ERR_ok) goto ex_0;
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

/**** END PROCEDURE equal ****/


/**** BEGIN PROCEDURE similar ****/

errcode maybeOPsimilar(m1, m2, ret_1)
CLUREF m1;
CLUREF m2;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    maybe_OWN_DEFN *type_own_ptr;
    type_own_ptr = (maybe_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->similar_own_init == 0) {
        type_own_ptr->similar_own_init = 1;
    }
    enter_proc(61);

  LINE(66);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = -2147483648;
    T_1_2.num = (m1.num == T_1_1.num)? true : false;
    if (T_1_2.num == true) {

  LINE(67);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = -2147483648;
        T_2_2.num = (m2.num == T_2_1.num)? true : false;
        if (T_2_2.num == true) {
            {
            {
            ret_1->tf = true;
            }
            {signal (ERR_ok);}}
            }
        else {
            {
            {
            ret_1->tf = false;
            }
            {signal (ERR_ok);}}
            }}/* end if */
        }
        }/* end if */

  LINE(69);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = -2147483648;
    T_1_2.num = (m2.num == T_1_1.num)? true : false;
    if (T_1_2.num == true) {
        {
        {
        ret_1->tf = false;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(70);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = m1.num;
    T_1_2.num = m2.num;
    T_1_4.proc = type_own_ptr->t_ops->similar.fcn;
    CUR_PROC_VAR = T_1_4;
    err = T_1_4.proc->proc(T_1_1, T_1_2, &T_1_3);
    if (err != ERR_ok) goto ex_0;
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

/**** END PROCEDURE similar ****/


/**** BEGIN PROCEDURE copy ****/

errcode maybeOPcopy(m, ret_1)
CLUREF m;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    maybe_OWN_DEFN *type_own_ptr;
    type_own_ptr = (maybe_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->copy_own_init == 0) {
        type_own_ptr->copy_own_init = 1;
    }
    enter_proc(73);

  LINE(78);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = -2147483648;
    T_1_2.num = (m.num == T_1_1.num)? true : false;
    if (T_1_2.num == true) {
        {
        {
        ret_1->num = m.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(79);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = m.num;
    T_1_3.proc = type_own_ptr->t_ops->copy.fcn;
    CUR_PROC_VAR = T_1_3;
    err = T_1_3.proc->proc(T_1_1, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    T_1_4.num = T_1_2.num;
    ret_1->num = T_1_4.num;
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


/**** BEGIN PROCEDURE _gcd ****/

errcode maybeOP_gcd(m, tab, ret_1)
CLUREF m;
CLUREF tab;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    maybe_OWN_DEFN *type_own_ptr;
    type_own_ptr = (maybe_OWN_DEFN *) CUR_PROC_VAR.proc->type_owns;
        if (type_own_ptr->_gcd_own_init == 0) {
        type_own_ptr->_gcd_own_init = 1;
    }
    enter_proc(82);

  LINE(85);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = -2147483648;
    T_1_2.num = (m.num == T_1_1.num)? true : false;
    if (T_1_2.num == true) {
        {
        {
        CLUREF T_2_1;
        err = intOP_gcd(m, tab, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        ret_1->num = T_2_1.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(86);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_1.num = m.num;
    T_1_3.proc = type_own_ptr->t_ops->_gcd.fcn;
    CUR_PROC_VAR = T_1_3;
    err = T_1_3.proc->proc(T_1_1, tab, &T_1_2);
    if (err != ERR_ok) goto ex_0;
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

/**** END PROCEDURE _gcd ****/

typedef struct{
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[8];
} maybe_OPS;

CLU_proc maybe_oe__gcd = {{0,0,0,0}, maybeOP_gcd, 0};
CLU_proc maybe_oe_copy = {{0,0,0,0}, maybeOPcopy, 0};
CLU_proc maybe_oe_equal = {{0,0,0,0}, maybeOPequal, 0};
CLU_proc maybe_oe_exists = {{0,0,0,0}, maybeOPexists, 0};
CLU_proc maybe_oe_make = {{0,0,0,0}, maybeOPmake, 0};
CLU_proc maybe_oe_none = {{0,0,0,0}, maybeOPnone, 0};
CLU_proc maybe_oe_similar = {{0,0,0,0}, maybeOPsimilar, 0};
CLU_proc maybe_oe_value = {{0,0,0,0}, maybeOPvalue, 0};

maybe_OPS maybe_ops_actual = {8, (OWNPTR)&maybe_own_init, (OWNPTR)&maybe_own_init, {
    {&maybe_oe__gcd, "_gcd"},
    {&maybe_oe_copy, "copy"},
    {&maybe_oe_equal, "equal"},
    {&maybe_oe_exists, "exists"},
    {&maybe_oe_make, "make"},
    {&maybe_oe_none, "none"},
    {&maybe_oe_similar, "similar"},
    {&maybe_oe_value, "value"}}};

struct OPS *maybe_ops = (struct OPS *)&maybe_ops_actual;

/**** END CLUSTER maybe ****/
