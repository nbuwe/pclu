
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN CLUSTER xlib ****/

extern errcode xlib_IB_1();
extern errcode tableOPcreate();
extern errcode hash();
extern errcode stringOPequal();
extern errcode xlibOPbind();
extern errcode duOPcreate();
extern errcode tableOPlookup();
extern errcode tableOPbind();
extern errcode arrayOPnew();
extern errcode tableOPelements();
extern errcode duOPget_dump_info();
extern errcode boolOPnot();
extern errcode oneofOPis_4();
extern errcode arrayOPaddh();
extern errcode duOPget_unique();
extern errcode arrayOPempty();
extern errcode gc_dump();
extern errcode file_nameOPcreate();
extern errcode file_nameOPget_dir();
extern errcode file_nameOPget_name();
extern errcode rename_file();
extern errcode file_nameOPget_suffix();
extern errcode delete_file();
extern errcode arrayOPelements();
extern errcode gc_read();
extern errcode recordOPget_1();
extern errcode duOPupdate_specs();
extern errcode recordOPget_3();
extern errcode recordOPget_2();
extern errcode tableOPmbind();
extern errcode duOPforget_specs();
extern struct REQS *table_of_key_reqs;
extern struct OPS *string_ops;
extern struct REQS *table_of_val_reqs;
extern struct OPS *du_ops;
extern OWN_req table_ownreqs;
extern struct OPS *table_ops;
struct OPS *table_of_string_table;
struct OPS *table_of_du_table;
struct OPS *table_of_string_du_ops;
struct OPS *table_of_string_du_ops;
OWNPTR table_of_string_du_owns;
extern struct REQS *sequence_of_t_reqs;
extern struct OPS *idn_ops;
extern OWN_req sequence_ownreqs;
extern struct OPS *sequence_ops;
struct OPS *sequence_of_idn_table;
struct OPS *sequence_of_idn_ops;
struct OPS *sequence_of_idn_ops;
OWNPTR sequence_of_idn_owns;
extern struct OPS *sequence_of_idn_ops;
extern struct OPS *typespec_ops;
struct OPS  *record_parms_type__ops;
extern struct OPS *expr_ops;
struct OPS *sequence_of_expr_table;
struct OPS *sequence_of_expr_ops;
struct OPS *sequence_of_expr_ops;
OWNPTR sequence_of_expr_owns;
extern struct OPS *sequence_of_expr_ops;
struct OPS  *record_name_parms_type__ops;
extern struct OPS *record_name_parms_type__ops;
struct OPS *sequence_of_record_name_parms_type__table;
struct OPS *sequence_of_record_name_parms_type__ops;
struct OPS *sequence_of_record_name_parms_type__ops;
OWNPTR sequence_of_record_name_parms_type__owns;
extern struct OPS *sequence_of_record_name_parms_type__ops;
struct OPS  *record_opers_parm_ops;
extern struct OPS *record_opers_parm_ops;
struct OPS *sequence_of_record_opers_parm_table;
struct OPS *sequence_of_record_opers_parm_ops;
struct OPS *sequence_of_record_opers_parm_ops;
OWNPTR sequence_of_record_opers_parm_owns;
extern struct OPS *record_parms_type__ops;
extern struct OPS *sequence_of_record_opers_parm_ops;
struct OPS  *record_info_name_where__ops;
extern struct OPS *record_info_name_where__ops;
struct OPS *sequence_of_record_info_name_where__table;
struct OPS *sequence_of_record_info_name_where__ops;
struct OPS *sequence_of_record_info_name_where__ops;
OWNPTR sequence_of_record_info_name_where__owns;
extern struct OPS *sequence_of_record_info_name_where__ops;
struct OPS  *record_opers_parms_ops;
extern struct OPS *record_opers_parms_ops;
extern struct OPS *null_ops;
struct OPS  *oneof_apply_atype_cluster__none_select_ops;
extern struct OPS *oneof_apply_atype_cluster__none_select_ops;
struct OPS  *record_name_path_specs_ops;
extern struct REQS *array_of_t_reqs;
extern struct OPS *record_name_path_specs_ops;
extern OWN_req array_ownreqs;
extern struct OPS *array_ops;
struct OPS *array_of_record_name_path_specs_table;
struct OPS *array_of_record_name_path_specs_ops;
struct OPS *array_of_record_name_path_specs_ops;
OWNPTR array_of_record_name_path_specs_owns;
extern struct REQS *gc_dump_of_t_reqs;
extern struct OPS *array_of_record_name_path_specs_ops;
extern OWN_req gc_dump_ownreqs;
struct OPS *gc_dump_of_array_of_record_name_path_specs_table;
struct OPS *gc_dump_of_array_of_record_name_path_specs_ops;
struct OPS *gc_dump_of_array_of_record_name_path_specs_ops;
OWNPTR gc_dump_of_array_of_record_name_path_specs_owns;
extern struct REQS *gc_read_of_t_reqs;
extern OWN_req gc_read_ownreqs;
struct OPS *gc_read_of_array_of_record_name_path_specs_table;
struct OPS *gc_read_of_array_of_record_name_path_specs_ops;
struct OPS *gc_read_of_array_of_record_name_path_specs_ops;
OWNPTR gc_read_of_array_of_record_name_path_specs_owns;
CLUREF STR_null;
CLUREF STR_bool;
CLUREF STR_int;
CLUREF STR_real;
CLUREF STR_char;
CLUREF STR_string;
CLUREF STR_array;
CLUREF STR_record;
CLUREF STR_oneof;
CLUREF STR_sequence;
CLUREF STR_struct;
CLUREF STR_variant;
CLUREF STR_proctype;
CLUREF STR_itertype;
CLUREF STR_type;
CLUREF STR_nothing_040to_040dump;
CLUREF STR__137l_137;
CLUREF STR_;
static int xlib_own_init = 0;
OWN_req xlib_ownreqs = {0,0};
CLUREF xlibOPtab;
errcode xlib_own_init_proc()
{
    errcode err;
    enter_own_init_proc();
        if (xlib_own_init == 0) {
        add_parm_info_type(0, string_ops, table_of_key_reqs);
        add_parm_info_type(1, du_ops, table_of_val_reqs);
        find_type_instance(table_ops, 2, &table_ownreqs, &(table_of_string_du_ops));
        add_parm_info_type(0, idn_ops, sequence_of_t_reqs);
        find_type_instance(sequence_ops, 1, &sequence_ownreqs, &(sequence_of_idn_ops));
        add_selector_info("parms", 0, sequence_of_idn_ops); 
        add_selector_info("type_", 1, typespec_ops); 
        find_selector_ops("record", 2, &(record_parms_type__ops));
        add_parm_info_type(0, expr_ops, sequence_of_t_reqs);
        find_type_instance(sequence_ops, 1, &sequence_ownreqs, &(sequence_of_expr_ops));
        add_selector_info("name", 0, string_ops); 
        add_selector_info("parms", 1, sequence_of_expr_ops); 
        add_selector_info("type_", 2, typespec_ops); 
        find_selector_ops("record", 3, &(record_name_parms_type__ops));
        add_parm_info_type(0, record_name_parms_type__ops, sequence_of_t_reqs);
        find_type_instance(sequence_ops, 1, &sequence_ownreqs, &(sequence_of_record_name_parms_type__ops));
        add_selector_info("opers", 0, sequence_of_record_name_parms_type__ops); 
        add_selector_info("parm", 1, idn_ops); 
        find_selector_ops("record", 2, &(record_opers_parm_ops));
        add_parm_info_type(0, record_opers_parm_ops, sequence_of_t_reqs);
        find_type_instance(sequence_ops, 1, &sequence_ownreqs, &(sequence_of_record_opers_parm_ops));
        add_selector_info("info", 0, record_parms_type__ops); 
        add_selector_info("name", 1, string_ops); 
        add_selector_info("where_", 2, sequence_of_record_opers_parm_ops); 
        find_selector_ops("record", 3, &(record_info_name_where__ops));
        add_parm_info_type(0, record_info_name_where__ops, sequence_of_t_reqs);
        find_type_instance(sequence_ops, 1, &sequence_ownreqs, &(sequence_of_record_info_name_where__ops));
        add_selector_info("opers", 0, sequence_of_record_info_name_where__ops); 
        add_selector_info("parms", 1, sequence_of_idn_ops); 
        find_selector_ops("record", 2, &(record_opers_parms_ops));
        add_selector_info("apply", 0, record_parms_type__ops); 
        add_selector_info("atype", 1, record_opers_parms_ops); 
        add_selector_info("cluster_", 2, record_opers_parms_ops); 
        add_selector_info("none", 3, null_ops); 
        add_selector_info("select", 4, record_opers_parms_ops); 
        find_selector_ops("oneof", 5, &(oneof_apply_atype_cluster__none_select_ops));
        add_selector_info("name", 0, string_ops); 
        add_selector_info("path", 1, string_ops); 
        add_selector_info("specs", 2, oneof_apply_atype_cluster__none_select_ops); 
        find_selector_ops("record", 3, &(record_name_path_specs_ops));
        add_parm_info_type(0, record_name_path_specs_ops, array_of_t_reqs);
        find_type_instance(array_ops, 1, &array_ownreqs, &(array_of_record_name_path_specs_ops));
        add_parm_info_type(0, array_of_record_name_path_specs_ops, gc_dump_of_t_reqs);
        find_prociter_instance(gc_dump, 1, &gc_dump_ownreqs, &(gc_dump_of_array_of_record_name_path_specs_ops));
        add_parm_info_type(0, array_of_record_name_path_specs_ops, gc_read_of_t_reqs);
        find_prociter_instance(gc_read, 1, &gc_read_ownreqs, &(gc_read_of_array_of_record_name_path_specs_ops));
        stringOPcons("null", CLU_1, CLU_4, &STR_null);
        stringOPcons("bool", CLU_1, CLU_4, &STR_bool);
        stringOPcons("int", CLU_1, CLU_3, &STR_int);
        stringOPcons("real", CLU_1, CLU_4, &STR_real);
        stringOPcons("char", CLU_1, CLU_4, &STR_char);
        stringOPcons("string", CLU_1, CLU_6, &STR_string);
        stringOPcons("array", CLU_1, CLU_5, &STR_array);
        stringOPcons("record", CLU_1, CLU_6, &STR_record);
        stringOPcons("oneof", CLU_1, CLU_5, &STR_oneof);
        stringOPcons("sequence", CLU_1, CLU_8, &STR_sequence);
        stringOPcons("struct", CLU_1, CLU_6, &STR_struct);
        stringOPcons("variant", CLU_1, CLU_7, &STR_variant);
        stringOPcons("proctype", CLU_1, CLU_8, &STR_proctype);
        stringOPcons("itertype", CLU_1, CLU_8, &STR_itertype);
        stringOPcons("type", CLU_1, CLU_4, &STR_type);
        stringOPcons("nothing to dump", CLU_1, CLU_15, &STR_nothing_040to_040dump);
        stringOPcons("_l_", CLU_1, CLU_3, &STR__137l_137);
        stringOPcons("", CLU_1, CLU_0, &STR_);
        xlib_own_init = 1;
        {
            {CLUREF T_0_1;
            CLUREF T_0_2;
            CLUREF T_0_3;
            CLUREF T_0_4;
            T_0_1.num = 300;
            err = proctypeOPnew(CLU_0, &T_0_2.proc);
            if (err!= ERR_ok) goto ex_0;
            T_0_2.proc->type_owns = 0;
            T_0_2.proc->op_owns = 0;
            T_0_2.proc->proc = hash;
            err = proctypeOPnew(CLU_0, &T_0_3.proc);
            if (err!= ERR_ok) goto ex_0;
            T_0_3.proc->proc = stringOPequal;
            generic_CLU_proc.type_owns = table_of_string_du_ops->type_owns;
            generic_CLU_proc.proc = tableOPcreate;
            CUR_PROC_VAR.proc = &generic_CLU_proc;
            err = tableOPcreate(T_0_1, T_0_2, T_0_3, &T_0_4);
            if (err != ERR_ok) goto ex_0;
            xlibOPtab.num = T_0_4.num;
            }
            }
        {signal(ERR_ok);}
    ex_0: pclu_unhandled(err); {signal(ERR_failure);}
        }
    }

static int xlibOPinit_own_init = 0;

/**** BEGIN PROCEDURE init ****/

errcode xlibOPinit()
    {
    errcode err;
    errcode ecode2;
        if (xlibOPinit_own_init == 0) {
        if (xlib_own_init == 0) {
            err = xlib_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
        xlibOPinit_own_init = 1;
    }
    enter_proc(24);

  LINE(25);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_null, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_null, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(26);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_bool, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_bool, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(27);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_int, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_int, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(28);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_real, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_real, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(29);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_char, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_char, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(30);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_string, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_string, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(31);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_array, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_array, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(32);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_record, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_record, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(33);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_oneof, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_oneof, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(34);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_sequence, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_sequence, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(35);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_struct, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_struct, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(36);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_variant, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_variant, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(37);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_proctype, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_proctype, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(38);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_itertype, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_itertype, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(39);
    {
    CLUREF T_1_1;
    err = duOPcreate(STR_type, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = xlibOPbind(STR_type, T_1_1);
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

/**** END PROCEDURE init ****/

struct OPS *table_of_string_table;
struct OPS *table_of_du_table;
struct OPS *table_of_string_du_ops;
struct OPS *table_of_string_du_ops;
OWNPTR table_of_string_du_owns;
static int xlibOPlookup_own_init = 0;

/**** BEGIN PROCEDURE lookup ****/

errcode xlibOPlookup(path, ret_1)
CLUREF path;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
        if (xlibOPlookup_own_init == 0) {
        if (xlib_own_init == 0) {
            err = xlib_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
        xlibOPlookup_own_init = 1;
    }
    enter_proc(42);

  LINE(43);
    {
    {
    CLUREF T_2_1;
    generic_CLU_proc.type_owns = table_of_string_du_ops->type_owns;
    generic_CLU_proc.proc = tableOPlookup;
    CUR_PROC_VAR.proc = &generic_CLU_proc;
    err = tableOPlookup(xlibOPtab, path, &T_2_1);
    if (err != ERR_ok) goto ex_1;
    ret_1->num = T_2_1.num;
    }
    {signal (ERR_ok);}}
    goto end_1;
    ex_1:
        if (err == ERR_not_found) {signal(ERR_not_found);}
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
    end_0: elist[0].str = no_return_values_STRING;
        {signal(ERR_failure);}
    }

/**** END PROCEDURE lookup ****/

struct OPS *table_of_string_table;
struct OPS *table_of_du_table;
struct OPS *table_of_string_du_ops;
struct OPS *table_of_string_du_ops;
OWNPTR table_of_string_du_owns;
static int xlibOPbind_own_init = 0;

/**** BEGIN PROCEDURE bind ****/

errcode xlibOPbind(path, d)
CLUREF path;
CLUREF d;
    {
    errcode err;
    errcode ecode2;
        if (xlibOPbind_own_init == 0) {
        if (xlib_own_init == 0) {
            err = xlib_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
        xlibOPbind_own_init = 1;
    }
    enter_proc(47);

  LINE(48);
    {
    generic_CLU_proc.type_owns = table_of_string_du_ops->type_owns;
    generic_CLU_proc.proc = tableOPbind;
    CUR_PROC_VAR.proc = &generic_CLU_proc;
    err = tableOPbind(xlibOPtab, path, d);
    if (err != ERR_ok) goto ex_1;
    }
    goto end_1;
    ex_1:
        if (err == ERR_exists) {signal(ERR_exists);}
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

/**** END PROCEDURE bind ****/

struct OPS *table_of_string_table;
struct OPS *table_of_du_table;
struct OPS *table_of_string_du_ops;
struct OPS *table_of_string_du_ops;
OWNPTR table_of_string_du_owns;
static int xlibOPget_du_own_init = 0;

/**** BEGIN PROCEDURE get_du ****/

errcode xlibOPget_du(n, ret_1)
CLUREF n;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    CLUREF d;
        if (xlibOPget_du_own_init == 0) {
        if (xlib_own_init == 0) {
            err = xlib_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
        xlibOPget_du_own_init = 1;
    }
    enter_proc(52);

  LINE(53);
    {
    {
    CLUREF T_2_1;
    generic_CLU_proc.type_owns = table_of_string_du_ops->type_owns;
    generic_CLU_proc.proc = tableOPlookup;
    CUR_PROC_VAR.proc = &generic_CLU_proc;
    err = tableOPlookup(xlibOPtab, n, &T_2_1);
    if (err != ERR_ok) goto ex_1;
    ret_1->num = T_2_1.num;
    }
    {signal (ERR_ok);}}
        goto end_1;
        ex_1:
            if ((err == ERR_not_found)) {

  LINE(54);
                {
                    {CLUREF T_2_1;
                    err = duOPcreate(n, &T_2_1);
                    if (err != ERR_ok) goto ex_0;
                    d.num = T_2_1.num;
                    }
                    }

  LINE(55);
                {
                generic_CLU_proc.type_owns = table_of_string_du_ops->type_owns;
                generic_CLU_proc.proc = tableOPbind;
                CUR_PROC_VAR.proc = &generic_CLU_proc;
                err = tableOPbind(xlibOPtab, n, d);
                if (err != ERR_ok) goto ex_0;
                }

  LINE(56);
                {
                {
                ret_1->num = d.num;
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
    end_0: elist[0].str = no_return_values_STRING;
        {signal(ERR_failure);}
    }

/**** END PROCEDURE get_du ****/

extern errcode xlibOPdump_IB_1();
struct OPS *table_of_string_table;
struct OPS *table_of_du_table;
struct OPS *table_of_string_du_ops;
struct OPS *table_of_string_du_ops;
OWNPTR table_of_string_du_owns;
struct OPS *sequence_of_idn_table;
struct OPS *sequence_of_idn_ops;
struct OPS *sequence_of_idn_ops;
OWNPTR sequence_of_idn_owns;
struct OPS  *record_parms_type__ops;
struct OPS *sequence_of_expr_table;
struct OPS *sequence_of_expr_ops;
struct OPS *sequence_of_expr_ops;
OWNPTR sequence_of_expr_owns;
struct OPS  *record_name_parms_type__ops;
struct OPS *sequence_of_record_name_parms_type__table;
struct OPS *sequence_of_record_name_parms_type__ops;
struct OPS *sequence_of_record_name_parms_type__ops;
OWNPTR sequence_of_record_name_parms_type__owns;
struct OPS  *record_opers_parm_ops;
struct OPS *sequence_of_record_opers_parm_table;
struct OPS *sequence_of_record_opers_parm_ops;
struct OPS *sequence_of_record_opers_parm_ops;
OWNPTR sequence_of_record_opers_parm_owns;
struct OPS  *record_info_name_where__ops;
struct OPS *sequence_of_record_info_name_where__table;
struct OPS *sequence_of_record_info_name_where__ops;
struct OPS *sequence_of_record_info_name_where__ops;
OWNPTR sequence_of_record_info_name_where__owns;
struct OPS  *record_opers_parms_ops;
struct OPS  *oneof_apply_atype_cluster__none_select_ops;
struct OPS  *record_name_path_specs_ops;
struct OPS *array_of_record_name_path_specs_table;
struct OPS *array_of_record_name_path_specs_ops;
struct OPS *array_of_record_name_path_specs_ops;
OWNPTR array_of_record_name_path_specs_owns;
struct OPS *gc_dump_of_array_of_record_name_path_specs_table;
struct OPS *gc_dump_of_array_of_record_name_path_specs_ops;
struct OPS *gc_dump_of_array_of_record_name_path_specs_ops;
OWNPTR gc_dump_of_array_of_record_name_path_specs_owns;
static int xlibOPdump_own_init = 0;

/**** BEGIN PROCEDURE dump ****/

errcode xlibOPdump(fn, ret_1)
CLUREF fn;
CLUREF *ret_1;
    {
    struct {
        errcode err;
        errcode ecode2;
        CLUREF list;
        CLUREF path;
        CLUREF d;
        CLUREF specs;
        CLUREF ok;
        CLUREF nfn;
        CLUREF why;
        CLUREF fn;
        } locals;
    locals.fn = fn;
        if (xlibOPdump_own_init == 0) {
        if (xlib_own_init == 0) {
            locals.err = xlib_own_init_proc();
            if (locals.err != ERR_ok) goto ex_0;
            }
        xlibOPdump_own_init = 1;
    }
    enter_proc(60);

  LINE(61);
    {
        {CLUREF T_1_1;
        locals.err = arrayOPnew(&T_1_1);
        if (locals.err != ERR_ok) goto ex_0;
        locals.list.num = T_1_1.num;
        }
        }

  LINE(62);
    {
        generic_CLU_proc.type_owns = table_of_string_du_ops->type_owns;
        generic_CLU_proc.proc = tableOPelements;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        locals.err = tableOPelements(xlibOPtab, xlibOPdump_IB_1, &locals, &locals.ecode2);
        if (locals.err == ERR_iterbodyreturn) {
        ret_1->num = elist[0].num;
        signal(ERR_ok);}
        if (locals.err == ERR_iterbodysignal) {signal(locals.ecode2);}
        if (locals.err == ERR_break) locals.err = ERR_ok;
        if (locals.err == ERR_iterbodyexit) locals.err = locals.ecode2;
        if (locals.err != ERR_ok) goto ex_0;
        }

  LINE(70);
    {
    CLUREF T_1_1;
    T_1_1.num = (locals.list.array->ext_size == 0)? true : false;
    if (T_1_1.num == true) {

  LINE(71);
        {
        elist[0] = STR_nothing_040to_040dump;
        {signal (ERR_not_possible);}}
        }
        }/* end if */

  LINE(72);
    {
        {CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        CLUREF T_2_4;
        locals.err = file_nameOPget_dir(locals.fn, &T_2_1);
        if (locals.err != ERR_ok) goto ex_1;
        locals.err = file_nameOPget_name(locals.fn, &T_2_2);
        if (locals.err != ERR_ok) goto ex_1;
        locals.err = file_nameOPcreate(T_2_1, T_2_2, STR__137l_137, STR_, &T_2_3);
        if (locals.err != ERR_ok) goto ex_1;
        generic_CLU_proc.type_owns = 0;
        generic_CLU_proc.op_owns = (long)gc_dump_of_array_of_record_name_path_specs_ops->op_owns;
        generic_CLU_proc.proc = gc_dump;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        locals.err = gc_dump(locals.list, T_2_3, &T_2_4);
        if (locals.err != ERR_ok) goto ex_1;
        locals.nfn.num = T_2_4.num;
        }
        }
    goto end_1;
    ex_1:
        if (locals.err == ERR_not_possible) {signal(ERR_not_possible);}
        else {
            goto ex_0;}
    end_1:;

  LINE(75);
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    CLUREF T_2_3;
    CLUREF T_2_4;
    locals.err = file_nameOPget_dir(locals.nfn, &T_2_1);
    if (locals.err != ERR_ok) goto ex_2;
    locals.err = file_nameOPget_name(locals.nfn, &T_2_2);
    if (locals.err != ERR_ok) goto ex_2;
    locals.err = file_nameOPget_suffix(locals.fn, &T_2_3);
    if (locals.err != ERR_ok) goto ex_2;
    locals.err = file_nameOPcreate(T_2_1, T_2_2, T_2_3, STR_, &T_2_4);
    if (locals.err != ERR_ok) goto ex_2;
    locals.err = rename_file(locals.nfn, T_2_4);
    if (locals.err != ERR_ok) goto ex_2;
    }
        goto end_2;
        ex_2:
            if ((locals.err == ERR_not_possible)) {
            CLUREF why;
            locals.why.num = elist[0].num;

  LINE(77);
                {
                locals.err = delete_file(locals.nfn);
                if (locals.err != ERR_ok) goto ex_3;
                }
                    goto end_3;
                    ex_3:
                        if ((locals.err == ERR_not_possible)) {
                        }
                        else {
                            goto ex_0;
                        }
                    end_3:;

  LINE(79);
                {
                elist[0] = locals.why;
                {signal (ERR_not_possible);}}
            }
            else {
                goto ex_0;
            }
        end_2:;

  LINE(81);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    locals.err = file_nameOPget_dir(locals.nfn, &T_1_1);
    if (locals.err != ERR_ok) goto ex_0;
    locals.err = file_nameOPget_name(locals.nfn, &T_1_2);
    if (locals.err != ERR_ok) goto ex_0;
    locals.err = file_nameOPget_suffix(locals.fn, &T_1_3);
    if (locals.err != ERR_ok) goto ex_0;
    locals.err = file_nameOPcreate(T_1_1, T_1_2, T_1_3, STR_, &T_1_4);
    if (locals.err != ERR_ok) goto ex_0;
    ret_1->num = T_1_4.num;
    }
    {signal (ERR_ok);}}
    goto end_0;
    ex_0:
        {
            if (locals.err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(locals.err);
            {signal(ERR_failure);}
        }
    end_0: elist[0].str = no_return_values_STRING;
        {signal(ERR_failure);}
    }

/**** END PROCEDURE dump ****/


/**** BEGIN ITERATOR BODIES for dump ****/

errcode xlibOPdump_IB_1(iv_1, iv_2, locals, iecode)
errcode *iecode;
CLUREF iv_1;
CLUREF iv_2;
struct {
    errcode err;
    errcode ecode2;
    CLUREF list;
    CLUREF path;
    CLUREF d;
    CLUREF specs;
    CLUREF ok;
    CLUREF nfn;
    CLUREF why;
    CLUREF fn;
    } *locals;
{
    locals->path.num = iv_1.num;
    locals->d.num = iv_2.num;
    enter_iter_body_proc(63);

  FB_LINE(63);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        locals->err = duOPget_dump_info(locals->d, &T_1_1, &T_1_2);
        if (locals->err != ERR_ok) goto ex_0;
        locals->specs.num = T_1_1.num;
        locals->ok.num = T_1_2.num;
        }
        }

  FB_LINE(64);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_1.num = locals->ok.num;
    if (locals->ok.num) {
        if (locals->specs.cell->tag == 4) T_1_2.num = true; else T_1_2.num = false;
        T_1_3.num = T_1_2.num ^ 1;
        T_1_1.num = T_1_3.num;
    }
    if (T_1_1.num == true) {

  FB_LINE(65);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        RecordAlloc(3, T_2_1);
        T_2_1.vec->data[1]  = locals->path.num;
        locals->err = duOPget_unique(locals->d, &T_2_2);
        if (locals->err != ERR_ok) goto ex_0;
        T_2_1.vec->data[0]  = T_2_2.num;
        T_2_1.vec->data[2]  = locals->specs.num;
        {
        if ((locals->list.array->int_low + locals->list.array->ext_size + 1) < locals->list.array->int_size) {
            locals->list.array->store->data[locals->list.array->int_low + locals->list.array->ext_size] = T_2_1.num;
            locals->list.array->ext_size++; locals->list.array->ext_high++;}
        else {
            locals->err = arrayOPaddh(locals->list, T_2_1);
            if (locals->err != ERR_ok) goto ex_0;}
        }
        }
        }
        }/* end if */
    {signal(ERR_ok);}
    ex_0:
        {
            *iecode = locals->err;
            {signal(ERR_iterbodyexit);}}
    end_0: {signal(ERR_ok);}
    }/* end xlibOPdump_IB_1 */

/**** END ITERATOR BODIES for dump ****/

struct OPS *sequence_of_idn_table;
struct OPS *sequence_of_idn_ops;
struct OPS *sequence_of_idn_ops;
OWNPTR sequence_of_idn_owns;
struct OPS  *record_parms_type__ops;
struct OPS *sequence_of_expr_table;
struct OPS *sequence_of_expr_ops;
struct OPS *sequence_of_expr_ops;
OWNPTR sequence_of_expr_owns;
struct OPS  *record_name_parms_type__ops;
struct OPS *sequence_of_record_name_parms_type__table;
struct OPS *sequence_of_record_name_parms_type__ops;
struct OPS *sequence_of_record_name_parms_type__ops;
OWNPTR sequence_of_record_name_parms_type__owns;
struct OPS  *record_opers_parm_ops;
struct OPS *sequence_of_record_opers_parm_table;
struct OPS *sequence_of_record_opers_parm_ops;
struct OPS *sequence_of_record_opers_parm_ops;
OWNPTR sequence_of_record_opers_parm_owns;
struct OPS  *record_info_name_where__ops;
struct OPS *sequence_of_record_info_name_where__table;
struct OPS *sequence_of_record_info_name_where__ops;
struct OPS *sequence_of_record_info_name_where__ops;
OWNPTR sequence_of_record_info_name_where__owns;
struct OPS  *record_opers_parms_ops;
struct OPS  *oneof_apply_atype_cluster__none_select_ops;
struct OPS  *record_name_path_specs_ops;
struct OPS *array_of_record_name_path_specs_table;
struct OPS *array_of_record_name_path_specs_ops;
struct OPS *array_of_record_name_path_specs_ops;
OWNPTR array_of_record_name_path_specs_owns;
struct OPS *gc_read_of_array_of_record_name_path_specs_table;
struct OPS *gc_read_of_array_of_record_name_path_specs_ops;
struct OPS *gc_read_of_array_of_record_name_path_specs_ops;
OWNPTR gc_read_of_array_of_record_name_path_specs_owns;
struct OPS *table_of_string_table;
struct OPS *table_of_du_table;
struct OPS *table_of_string_du_ops;
struct OPS *table_of_string_du_ops;
OWNPTR table_of_string_du_owns;
static int xlibOPmerge_own_init = 0;

/**** BEGIN PROCEDURE merge ****/

errcode xlibOPmerge(fn)
CLUREF fn;
    {
    errcode err;
    errcode ecode2;
    CLUREF form;
    CLUREF d;
        if (xlibOPmerge_own_init == 0) {
        if (xlib_own_init == 0) {
            err = xlib_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
        xlibOPmerge_own_init = 1;
    }
    enter_proc(84);

  LINE(85);
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    CLUREF T_2_3;
    CLUREF T_2_4;
        generic_CLU_proc.type_owns = 0;
        generic_CLU_proc.op_owns = (long)gc_read_of_array_of_record_name_path_specs_ops->op_owns;
        generic_CLU_proc.proc = gc_read;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = gc_read(fn, &T_2_1);
        if (err != ERR_ok) goto ex_1;
        T_2_3.num = T_2_1.array->ext_high; 
        T_2_4 = T_2_1;
        for (T_2_2.num = T_2_1.array->ext_low; T_2_2.num <= T_2_3.num; T_2_2.num++) {
            if (T_2_2.num > T_2_4.array->ext_high || T_2_2.num < T_2_4.array->ext_low) {
                err = ERR_failure;
                elist[0].str = array_bounds_exception_STRING;
                goto ex_1;}
            form.num = T_2_4.array->store->data[T_2_2.num - T_2_4.array->ext_low + T_2_4.array->int_low];

  LINE(86);
            {
                {CLUREF T_4_1;
                CLUREF T_4_2;
                T_4_1.num = form.vec->data[0];
                generic_CLU_proc.type_owns = table_of_string_du_ops->type_owns;
                generic_CLU_proc.proc = tableOPlookup;
                CUR_PROC_VAR.proc = &generic_CLU_proc;
                err = tableOPlookup(xlibOPtab, T_4_1, &T_4_2);
                if (err != ERR_ok) goto ex_2;
                d.num = T_4_2.num;
                }
                }
                goto end_2;
                ex_2:
                    if ((err == ERR_not_found)) {

  LINE(88);
                        {
                        CLUREF T_4_1;
                        CLUREF T_4_2;
                        T_4_1.num = form.vec->data[0];
                        err = duOPcreate(T_4_1, &T_4_2);
                        if (err != ERR_ok) goto ex_1;
                        d.num = T_4_2.num;
                        }

  LINE(89);
                        {
                        CLUREF T_4_1;
                        err = duOPget_unique(d, &T_4_1);
                        if (err != ERR_ok) goto ex_1;
                        generic_CLU_proc.type_owns = table_of_string_du_ops->type_owns;
                        generic_CLU_proc.proc = tableOPbind;
                        CUR_PROC_VAR.proc = &generic_CLU_proc;
                        err = tableOPbind(xlibOPtab, T_4_1, d);
                        if (err != ERR_ok) goto ex_1;
                        }
                    }
                    else {
                        goto ex_1;
                    }
                end_2:;

  LINE(91);
            {
            CLUREF T_3_1;
            T_3_1.num = form.vec->data[2];
            err = duOPupdate_specs(d, T_3_1);
            if (err != ERR_ok) goto ex_1;
            }

  LINE(92);
            {
            CLUREF T_3_1;
            CLUREF T_3_2;
            CLUREF T_3_3;
            CLUREF T_3_4;
            err = duOPget_unique(d, &T_3_1);
            if (err != ERR_ok) goto ex_1;
            T_3_2.num = form.vec->data[1];
            T_3_3.num = ((T_3_1.str->size != T_3_2.str->size)? false :
                !(bcmp(T_3_1.str->data, T_3_2.str->data, T_3_1.str->size)));
            T_3_4.num = T_3_3.num ^ 1;
            if (T_3_4.num == true) {

  LINE(93);
                {
                CLUREF T_4_1;
                CLUREF T_4_2;
                T_4_1.num = form.vec->data[1];
                generic_CLU_proc.type_owns = table_of_string_du_ops->type_owns;
                generic_CLU_proc.proc = tableOPmbind;
                CUR_PROC_VAR.proc = &generic_CLU_proc;
                err = tableOPmbind(xlibOPtab, T_4_1, d, &T_4_2);
                if (err != ERR_ok) goto ex_1;
                }
                }
                }/* end if */
        }
    }
    end_inline_for_1:;
    goto end_1;
    ex_1:
        if (err == ERR_not_possible) {signal(ERR_not_possible);}
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

/**** END PROCEDURE merge ****/

struct OPS *sequence_of_idn_table;
struct OPS *sequence_of_idn_ops;
struct OPS *sequence_of_idn_ops;
OWNPTR sequence_of_idn_owns;
struct OPS  *record_parms_type__ops;
struct OPS *sequence_of_expr_table;
struct OPS *sequence_of_expr_ops;
struct OPS *sequence_of_expr_ops;
OWNPTR sequence_of_expr_owns;
struct OPS  *record_name_parms_type__ops;
struct OPS *sequence_of_record_name_parms_type__table;
struct OPS *sequence_of_record_name_parms_type__ops;
struct OPS *sequence_of_record_name_parms_type__ops;
OWNPTR sequence_of_record_name_parms_type__owns;
struct OPS  *record_opers_parm_ops;
struct OPS *sequence_of_record_opers_parm_table;
struct OPS *sequence_of_record_opers_parm_ops;
struct OPS *sequence_of_record_opers_parm_ops;
OWNPTR sequence_of_record_opers_parm_owns;
struct OPS  *record_info_name_where__ops;
struct OPS *sequence_of_record_info_name_where__table;
struct OPS *sequence_of_record_info_name_where__ops;
struct OPS *sequence_of_record_info_name_where__ops;
OWNPTR sequence_of_record_info_name_where__owns;
struct OPS  *record_opers_parms_ops;
struct OPS  *oneof_apply_atype_cluster__none_select_ops;
struct OPS  *record_name_path_specs_ops;
struct OPS *array_of_record_name_path_specs_table;
struct OPS *array_of_record_name_path_specs_ops;
struct OPS *array_of_record_name_path_specs_ops;
OWNPTR array_of_record_name_path_specs_owns;
struct OPS *gc_read_of_array_of_record_name_path_specs_table;
struct OPS *gc_read_of_array_of_record_name_path_specs_ops;
struct OPS *gc_read_of_array_of_record_name_path_specs_ops;
OWNPTR gc_read_of_array_of_record_name_path_specs_owns;
struct OPS *table_of_string_table;
struct OPS *table_of_du_table;
struct OPS *table_of_string_du_ops;
struct OPS *table_of_string_du_ops;
OWNPTR table_of_string_du_owns;
static int xlibOPunmerge_own_init = 0;

/**** BEGIN PROCEDURE unmerge ****/

errcode xlibOPunmerge(fn)
CLUREF fn;
    {
    errcode err;
    errcode ecode2;
    CLUREF form;
        if (xlibOPunmerge_own_init == 0) {
        if (xlib_own_init == 0) {
            err = xlib_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
        xlibOPunmerge_own_init = 1;
    }
    enter_proc(97);

  LINE(98);
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    CLUREF T_2_3;
    CLUREF T_2_4;
        generic_CLU_proc.type_owns = 0;
        generic_CLU_proc.op_owns = (long)gc_read_of_array_of_record_name_path_specs_ops->op_owns;
        generic_CLU_proc.proc = gc_read;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = gc_read(fn, &T_2_1);
        if (err != ERR_ok) goto ex_1;
        T_2_3.num = T_2_1.array->ext_high; 
        T_2_4 = T_2_1;
        for (T_2_2.num = T_2_1.array->ext_low; T_2_2.num <= T_2_3.num; T_2_2.num++) {
            if (T_2_2.num > T_2_4.array->ext_high || T_2_2.num < T_2_4.array->ext_low) {
                err = ERR_failure;
                elist[0].str = array_bounds_exception_STRING;
                goto ex_1;}
            form.num = T_2_4.array->store->data[T_2_2.num - T_2_4.array->ext_low + T_2_4.array->int_low];

  LINE(99);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            T_4_1.num = form.vec->data[0];
            generic_CLU_proc.type_owns = table_of_string_du_ops->type_owns;
            generic_CLU_proc.proc = tableOPlookup;
            CUR_PROC_VAR.proc = &generic_CLU_proc;
            err = tableOPlookup(xlibOPtab, T_4_1, &T_4_2);
            if (err != ERR_ok) goto ex_2;
            err = duOPforget_specs(T_4_2);
            if (err != ERR_ok) goto ex_2;
            }
                goto end_2;
                ex_2:
                    if ((err == ERR_not_found)) {
                    }
                    else {
                        goto ex_1;
                    }
                end_2:;
        }
    }
    end_inline_for_1:;
    goto end_1;
    ex_1:
        if (err == ERR_not_possible) {signal(ERR_not_possible);}
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

/**** END PROCEDURE unmerge ****/

typedef struct{
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[7];
} xlib_OPS;

CLU_proc xlib_oe_bind = {{0,0,0,0}, xlibOPbind, 0};
CLU_proc xlib_oe_dump = {{0,0,0,0}, xlibOPdump, 0};
CLU_proc xlib_oe_get_du = {{0,0,0,0}, xlibOPget_du, 0};
CLU_proc xlib_oe_init = {{0,0,0,0}, xlibOPinit, 0};
CLU_proc xlib_oe_lookup = {{0,0,0,0}, xlibOPlookup, 0};
CLU_proc xlib_oe_merge = {{0,0,0,0}, xlibOPmerge, 0};
CLU_proc xlib_oe_unmerge = {{0,0,0,0}, xlibOPunmerge, 0};

xlib_OPS xlib_ops_actual = {7, (OWNPTR)&xlib_own_init, (OWNPTR)&xlib_own_init, {
    {&xlib_oe_bind, "bind"},
    {&xlib_oe_dump, "dump"},
    {&xlib_oe_get_du, "get_du"},
    {&xlib_oe_init, "init"},
    {&xlib_oe_lookup, "lookup"},
    {&xlib_oe_merge, "merge"},
    {&xlib_oe_unmerge, "unmerge"}}};

struct OPS *xlib_ops = (struct OPS *)&xlib_ops_actual;

/**** END CLUSTER xlib ****/
