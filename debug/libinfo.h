extern struct OPS* int_ops;
extern struct OPS* bool_ops;
extern struct OPS* string_ops;
extern struct OPS* array_ops;
extern struct OPS* _chan_ops;
extern struct OPS* real_ops;
extern struct OPS* sequence_ops;
extern struct OPS* _bytevec_ops;

extern errcode _set_limit();
static const sig_desc1 sig__set_limit_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__set_limit = {0, 1, {(const sig_desc *)&sig__set_limit_1}};
const dbg_info_generic dbg_info__set_limit_data = {0, 14, "_set_limit", "_set_limit", 0, 0, _set_limit, 2, &NO_VALS, (const siglist0 *)&sigs__set_limit,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__set_limit = (const struct dbg_info *)&dbg_info__set_limit_data;

extern errcode _groups();
static const Vlist1 vals__groups = {0, 1, {{0, 3, "", zero_ops, "sequence_of_int_ops"}}};
const dbg_info_generic dbg_info__groups_data = {0, 14, "_groups", "_groups", 0, 0, _groups, 0, (const Vlist0 *)&vals__groups, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__groups = (const struct dbg_info *)&dbg_info__groups_data;

extern errcode _all_dir_entries_();
static const Vlist2 vals__all_dir_entries_ = {0, 2, {{0, 2, "", &int_ops, ""}, {0, 2, "", &_bytevec_ops, ""}}};
const dbg_info_generic dbg_info__all_dir_entries__data = {0, 14, "_all_dir_entries_", "_all_dir_entries_", 1, 0, _all_dir_entries_, 1, (const Vlist0 *)&vals__all_dir_entries_, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__all_dir_entries_ = (const struct dbg_info *)&dbg_info__all_dir_entries__data;

extern errcode _ioctl();
const Slist1 opformals__ioctl = {0, 1, {"t"}};
static const sig_desc1 sig__ioctl_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__ioctl = {0, 1, {(const sig_desc *)&sig__ioctl_1}};
const dbg_info_generic dbg_info__ioctl_data = {0, 14, "_ioctl", "_ioctl", 0, 1, _ioctl, 5, &NO_VALS, (const siglist0 *)&sigs__ioctl,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals__ioctl};
const struct dbg_info * const dbg_info__ioctl = (const struct dbg_info *)&dbg_info__ioctl_data;

extern errcode gc();
static const Vlist1 vals_gc = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_gc_data = {0, 14, "gc", "gc", 0, 0, gc, 0, (const Vlist0 *)&vals_gc, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_gc = (const struct dbg_info *)&dbg_info_gc_data;

extern errcode log();
static const Vlist1 vals_log = {0, 1, {{0, 2, "", &real_ops, ""}}};
static const sig_desc0 sig_log_1 = {0, 2, "undefined", {0,0}};
static const siglist1 sigs_log = {0, 1, {(const sig_desc *)&sig_log_1}};
const dbg_info_generic dbg_info_log_data = {0, 14, "log", "log", 0, 0, log, 1, (const Vlist0 *)&vals_log, (const siglist0 *)&sigs_log,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_log = (const struct dbg_info *)&dbg_info_log_data;

extern errcode _unparse_real();
static const Vlist3 vals__unparse_real = {0, 3, {{0, 2, "", &bool_ops, ""}, {0, 2, "", &_bytevec_ops, ""}, {0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__unparse_real_data = {0, 14, "_unparse_real", "_unparse_real", 0, 0, _unparse_real, 1, (const Vlist0 *)&vals__unparse_real, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__unparse_real = (const struct dbg_info *)&dbg_info__unparse_real_data;

extern errcode delete_file();
static const sig_desc1 sig_delete_file_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs_delete_file = {0, 1, {(const sig_desc *)&sig_delete_file_1}};
const dbg_info_generic dbg_info_delete_file_data = {0, 14, "delete_file", "delete_file", 0, 0, delete_file, 1, &NO_VALS, (const siglist0 *)&sigs_delete_file,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_delete_file = (const struct dbg_info *)&dbg_info_delete_file_data;

extern errcode _change_signal();
static const Vlist1 vals__change_signal = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__change_signal_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__change_signal = {0, 1, {(const sig_desc *)&sig__change_signal_1}};
const dbg_info_generic dbg_info__change_signal_data = {0, 14, "_change_signal", "_change_signal", 0, 0, _change_signal, 2, (const Vlist0 *)&vals__change_signal, (const siglist0 *)&sigs__change_signal,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__change_signal = (const struct dbg_info *)&dbg_info__change_signal_data;

extern errcode _file_owner();
static const Vlist2 vals__file_owner = {0, 2, {{0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__file_owner_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__file_owner = {0, 1, {(const sig_desc *)&sig__file_owner_1}};
const dbg_info_generic dbg_info__file_owner_data = {0, 14, "_file_owner", "_file_owner", 0, 0, _file_owner, 1, (const Vlist0 *)&vals__file_owner, (const siglist0 *)&sigs__file_owner,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__file_owner = (const struct dbg_info *)&dbg_info__file_owner_data;

extern errcode oneofOPmake_1();
const Slist1 opformals_oneofOPmake_1 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_1 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_1_data = {0, 14, "oneof$make_1", "oneof", 0, 1, oneofOPmake_1, 1, (const Vlist0 *)&vals_oneofOPmake_1, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_1};
const struct dbg_info * const dbg_info_oneofOPmake_1 = (const struct dbg_info *)&dbg_info_oneofOPmake_1_data;

extern errcode oneofOPmake_2();
const Slist1 opformals_oneofOPmake_2 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_2 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_2_data = {0, 14, "oneof$make_2", "oneof", 0, 1, oneofOPmake_2, 1, (const Vlist0 *)&vals_oneofOPmake_2, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_2};
const struct dbg_info * const dbg_info_oneofOPmake_2 = (const struct dbg_info *)&dbg_info_oneofOPmake_2_data;

extern errcode oneofOPmake_3();
const Slist1 opformals_oneofOPmake_3 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_3 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_3_data = {0, 14, "oneof$make_3", "oneof", 0, 1, oneofOPmake_3, 1, (const Vlist0 *)&vals_oneofOPmake_3, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_3};
const struct dbg_info * const dbg_info_oneofOPmake_3 = (const struct dbg_info *)&dbg_info_oneofOPmake_3_data;

extern errcode oneofOPmake_4();
const Slist1 opformals_oneofOPmake_4 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_4 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_4_data = {0, 14, "oneof$make_4", "oneof", 0, 1, oneofOPmake_4, 1, (const Vlist0 *)&vals_oneofOPmake_4, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_4};
const struct dbg_info * const dbg_info_oneofOPmake_4 = (const struct dbg_info *)&dbg_info_oneofOPmake_4_data;

extern errcode oneofOPmake_5();
const Slist1 opformals_oneofOPmake_5 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_5 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_5_data = {0, 14, "oneof$make_5", "oneof", 0, 1, oneofOPmake_5, 1, (const Vlist0 *)&vals_oneofOPmake_5, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_5};
const struct dbg_info * const dbg_info_oneofOPmake_5 = (const struct dbg_info *)&dbg_info_oneofOPmake_5_data;

extern errcode oneofOPmake_6();
const Slist1 opformals_oneofOPmake_6 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_6 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_6_data = {0, 14, "oneof$make_6", "oneof", 0, 1, oneofOPmake_6, 1, (const Vlist0 *)&vals_oneofOPmake_6, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_6};
const struct dbg_info * const dbg_info_oneofOPmake_6 = (const struct dbg_info *)&dbg_info_oneofOPmake_6_data;

extern errcode oneofOPmake_7();
const Slist1 opformals_oneofOPmake_7 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_7 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_7_data = {0, 14, "oneof$make_7", "oneof", 0, 1, oneofOPmake_7, 1, (const Vlist0 *)&vals_oneofOPmake_7, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_7};
const struct dbg_info * const dbg_info_oneofOPmake_7 = (const struct dbg_info *)&dbg_info_oneofOPmake_7_data;

extern errcode oneofOPmake_8();
const Slist1 opformals_oneofOPmake_8 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_8 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_8_data = {0, 14, "oneof$make_8", "oneof", 0, 1, oneofOPmake_8, 1, (const Vlist0 *)&vals_oneofOPmake_8, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_8};
const struct dbg_info * const dbg_info_oneofOPmake_8 = (const struct dbg_info *)&dbg_info_oneofOPmake_8_data;

extern errcode oneofOPmake_9();
const Slist1 opformals_oneofOPmake_9 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_9 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_9_data = {0, 14, "oneof$make_9", "oneof", 0, 1, oneofOPmake_9, 1, (const Vlist0 *)&vals_oneofOPmake_9, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_9};
const struct dbg_info * const dbg_info_oneofOPmake_9 = (const struct dbg_info *)&dbg_info_oneofOPmake_9_data;

extern errcode oneofOPmake_10();
const Slist1 opformals_oneofOPmake_10 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_10 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_10_data = {0, 14, "oneof$make_10", "oneof", 0, 1, oneofOPmake_10, 1, (const Vlist0 *)&vals_oneofOPmake_10, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_10};
const struct dbg_info * const dbg_info_oneofOPmake_10 = (const struct dbg_info *)&dbg_info_oneofOPmake_10_data;

extern errcode oneofOPmake_11();
const Slist1 opformals_oneofOPmake_11 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_11 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_11_data = {0, 14, "oneof$make_11", "oneof", 0, 1, oneofOPmake_11, 1, (const Vlist0 *)&vals_oneofOPmake_11, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_11};
const struct dbg_info * const dbg_info_oneofOPmake_11 = (const struct dbg_info *)&dbg_info_oneofOPmake_11_data;

extern errcode oneofOPmake_12();
const Slist1 opformals_oneofOPmake_12 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_12 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_12_data = {0, 14, "oneof$make_12", "oneof", 0, 1, oneofOPmake_12, 1, (const Vlist0 *)&vals_oneofOPmake_12, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_12};
const struct dbg_info * const dbg_info_oneofOPmake_12 = (const struct dbg_info *)&dbg_info_oneofOPmake_12_data;

extern errcode oneofOPmake_13();
const Slist1 opformals_oneofOPmake_13 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_13 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_13_data = {0, 14, "oneof$make_13", "oneof", 0, 1, oneofOPmake_13, 1, (const Vlist0 *)&vals_oneofOPmake_13, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_13};
const struct dbg_info * const dbg_info_oneofOPmake_13 = (const struct dbg_info *)&dbg_info_oneofOPmake_13_data;

extern errcode oneofOPmake_14();
const Slist1 opformals_oneofOPmake_14 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_14 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_14_data = {0, 14, "oneof$make_14", "oneof", 0, 1, oneofOPmake_14, 1, (const Vlist0 *)&vals_oneofOPmake_14, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_14};
const struct dbg_info * const dbg_info_oneofOPmake_14 = (const struct dbg_info *)&dbg_info_oneofOPmake_14_data;

extern errcode oneofOPmake_15();
const Slist1 opformals_oneofOPmake_15 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_15 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_15_data = {0, 14, "oneof$make_15", "oneof", 0, 1, oneofOPmake_15, 1, (const Vlist0 *)&vals_oneofOPmake_15, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_15};
const struct dbg_info * const dbg_info_oneofOPmake_15 = (const struct dbg_info *)&dbg_info_oneofOPmake_15_data;

extern errcode oneofOPmake_16();
const Slist1 opformals_oneofOPmake_16 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_16 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_16_data = {0, 14, "oneof$make_16", "oneof", 0, 1, oneofOPmake_16, 1, (const Vlist0 *)&vals_oneofOPmake_16, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_16};
const struct dbg_info * const dbg_info_oneofOPmake_16 = (const struct dbg_info *)&dbg_info_oneofOPmake_16_data;

extern errcode oneofOPmake_17();
const Slist1 opformals_oneofOPmake_17 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPmake_17 = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPmake_17_data = {0, 14, "oneof$make_17", "oneof", 0, 1, oneofOPmake_17, 1, (const Vlist0 *)&vals_oneofOPmake_17, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPmake_17};
const struct dbg_info * const dbg_info_oneofOPmake_17 = (const struct dbg_info *)&dbg_info_oneofOPmake_17_data;

extern errcode oneofOPis_1();
const Slist1 opformals_oneofOPis_1 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_1 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_1_data = {0, 14, "oneof$is_1", "oneof", 0, 1, oneofOPis_1, 1, (const Vlist0 *)&vals_oneofOPis_1, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_1};
const struct dbg_info * const dbg_info_oneofOPis_1 = (const struct dbg_info *)&dbg_info_oneofOPis_1_data;

extern errcode oneofOPis_2();
const Slist1 opformals_oneofOPis_2 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_2 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_2_data = {0, 14, "oneof$is_2", "oneof", 0, 1, oneofOPis_2, 1, (const Vlist0 *)&vals_oneofOPis_2, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_2};
const struct dbg_info * const dbg_info_oneofOPis_2 = (const struct dbg_info *)&dbg_info_oneofOPis_2_data;

extern errcode oneofOPis_3();
const Slist1 opformals_oneofOPis_3 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_3 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_3_data = {0, 14, "oneof$is_3", "oneof", 0, 1, oneofOPis_3, 1, (const Vlist0 *)&vals_oneofOPis_3, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_3};
const struct dbg_info * const dbg_info_oneofOPis_3 = (const struct dbg_info *)&dbg_info_oneofOPis_3_data;

extern errcode oneofOPis_4();
const Slist1 opformals_oneofOPis_4 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_4 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_4_data = {0, 14, "oneof$is_4", "oneof", 0, 1, oneofOPis_4, 1, (const Vlist0 *)&vals_oneofOPis_4, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_4};
const struct dbg_info * const dbg_info_oneofOPis_4 = (const struct dbg_info *)&dbg_info_oneofOPis_4_data;

extern errcode oneofOPis_5();
const Slist1 opformals_oneofOPis_5 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_5 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_5_data = {0, 14, "oneof$is_5", "oneof", 0, 1, oneofOPis_5, 1, (const Vlist0 *)&vals_oneofOPis_5, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_5};
const struct dbg_info * const dbg_info_oneofOPis_5 = (const struct dbg_info *)&dbg_info_oneofOPis_5_data;

extern errcode oneofOPis_6();
const Slist1 opformals_oneofOPis_6 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_6 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_6_data = {0, 14, "oneof$is_6", "oneof", 0, 1, oneofOPis_6, 1, (const Vlist0 *)&vals_oneofOPis_6, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_6};
const struct dbg_info * const dbg_info_oneofOPis_6 = (const struct dbg_info *)&dbg_info_oneofOPis_6_data;

extern errcode oneofOPis_7();
const Slist1 opformals_oneofOPis_7 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_7 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_7_data = {0, 14, "oneof$is_7", "oneof", 0, 1, oneofOPis_7, 1, (const Vlist0 *)&vals_oneofOPis_7, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_7};
const struct dbg_info * const dbg_info_oneofOPis_7 = (const struct dbg_info *)&dbg_info_oneofOPis_7_data;

extern errcode oneofOPis_8();
const Slist1 opformals_oneofOPis_8 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_8 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_8_data = {0, 14, "oneof$is_8", "oneof", 0, 1, oneofOPis_8, 1, (const Vlist0 *)&vals_oneofOPis_8, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_8};
const struct dbg_info * const dbg_info_oneofOPis_8 = (const struct dbg_info *)&dbg_info_oneofOPis_8_data;

extern errcode oneofOPis_9();
const Slist1 opformals_oneofOPis_9 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_9 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_9_data = {0, 14, "oneof$is_9", "oneof", 0, 1, oneofOPis_9, 1, (const Vlist0 *)&vals_oneofOPis_9, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_9};
const struct dbg_info * const dbg_info_oneofOPis_9 = (const struct dbg_info *)&dbg_info_oneofOPis_9_data;

extern errcode oneofOPis_10();
const Slist1 opformals_oneofOPis_10 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_10 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_10_data = {0, 14, "oneof$is_10", "oneof", 0, 1, oneofOPis_10, 1, (const Vlist0 *)&vals_oneofOPis_10, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_10};
const struct dbg_info * const dbg_info_oneofOPis_10 = (const struct dbg_info *)&dbg_info_oneofOPis_10_data;

extern errcode oneofOPis_11();
const Slist1 opformals_oneofOPis_11 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_11 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_11_data = {0, 14, "oneof$is_11", "oneof", 0, 1, oneofOPis_11, 1, (const Vlist0 *)&vals_oneofOPis_11, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_11};
const struct dbg_info * const dbg_info_oneofOPis_11 = (const struct dbg_info *)&dbg_info_oneofOPis_11_data;

extern errcode oneofOPis_12();
const Slist1 opformals_oneofOPis_12 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_12 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_12_data = {0, 14, "oneof$is_12", "oneof", 0, 1, oneofOPis_12, 1, (const Vlist0 *)&vals_oneofOPis_12, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_12};
const struct dbg_info * const dbg_info_oneofOPis_12 = (const struct dbg_info *)&dbg_info_oneofOPis_12_data;

extern errcode oneofOPis_13();
const Slist1 opformals_oneofOPis_13 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_13 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_13_data = {0, 14, "oneof$is_13", "oneof", 0, 1, oneofOPis_13, 1, (const Vlist0 *)&vals_oneofOPis_13, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_13};
const struct dbg_info * const dbg_info_oneofOPis_13 = (const struct dbg_info *)&dbg_info_oneofOPis_13_data;

extern errcode oneofOPis_14();
const Slist1 opformals_oneofOPis_14 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_14 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_14_data = {0, 14, "oneof$is_14", "oneof", 0, 1, oneofOPis_14, 1, (const Vlist0 *)&vals_oneofOPis_14, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_14};
const struct dbg_info * const dbg_info_oneofOPis_14 = (const struct dbg_info *)&dbg_info_oneofOPis_14_data;

extern errcode oneofOPis_15();
const Slist1 opformals_oneofOPis_15 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_15 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_15_data = {0, 14, "oneof$is_15", "oneof", 0, 1, oneofOPis_15, 1, (const Vlist0 *)&vals_oneofOPis_15, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_15};
const struct dbg_info * const dbg_info_oneofOPis_15 = (const struct dbg_info *)&dbg_info_oneofOPis_15_data;

extern errcode oneofOPis_16();
const Slist1 opformals_oneofOPis_16 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_16 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_16_data = {0, 14, "oneof$is_16", "oneof", 0, 1, oneofOPis_16, 1, (const Vlist0 *)&vals_oneofOPis_16, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_16};
const struct dbg_info * const dbg_info_oneofOPis_16 = (const struct dbg_info *)&dbg_info_oneofOPis_16_data;

extern errcode oneofOPis_17();
const Slist1 opformals_oneofOPis_17 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPis_17 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPis_17_data = {0, 14, "oneof$is_17", "oneof", 0, 1, oneofOPis_17, 1, (const Vlist0 *)&vals_oneofOPis_17, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPis_17};
const struct dbg_info * const dbg_info_oneofOPis_17 = (const struct dbg_info *)&dbg_info_oneofOPis_17_data;

extern errcode oneofOPvalue_1();
const Slist1 opformals_oneofOPvalue_1 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_1 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_1_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_1 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_1_1}};
const dbg_info_generic dbg_info_oneofOPvalue_1_data = {0, 14, "oneof$value_1", "oneof", 0, 1, oneofOPvalue_1, 1, (const Vlist0 *)&vals_oneofOPvalue_1, (const siglist0 *)&sigs_oneofOPvalue_1,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_1};
const struct dbg_info * const dbg_info_oneofOPvalue_1 = (const struct dbg_info *)&dbg_info_oneofOPvalue_1_data;

extern errcode oneofOPvalue_2();
const Slist1 opformals_oneofOPvalue_2 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_2 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_2_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_2 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_2_1}};
const dbg_info_generic dbg_info_oneofOPvalue_2_data = {0, 14, "oneof$value_2", "oneof", 0, 1, oneofOPvalue_2, 1, (const Vlist0 *)&vals_oneofOPvalue_2, (const siglist0 *)&sigs_oneofOPvalue_2,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_2};
const struct dbg_info * const dbg_info_oneofOPvalue_2 = (const struct dbg_info *)&dbg_info_oneofOPvalue_2_data;

extern errcode oneofOPvalue_3();
const Slist1 opformals_oneofOPvalue_3 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_3 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_3_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_3 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_3_1}};
const dbg_info_generic dbg_info_oneofOPvalue_3_data = {0, 14, "oneof$value_3", "oneof", 0, 1, oneofOPvalue_3, 1, (const Vlist0 *)&vals_oneofOPvalue_3, (const siglist0 *)&sigs_oneofOPvalue_3,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_3};
const struct dbg_info * const dbg_info_oneofOPvalue_3 = (const struct dbg_info *)&dbg_info_oneofOPvalue_3_data;

extern errcode oneofOPvalue_4();
const Slist1 opformals_oneofOPvalue_4 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_4 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_4_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_4 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_4_1}};
const dbg_info_generic dbg_info_oneofOPvalue_4_data = {0, 14, "oneof$value_4", "oneof", 0, 1, oneofOPvalue_4, 1, (const Vlist0 *)&vals_oneofOPvalue_4, (const siglist0 *)&sigs_oneofOPvalue_4,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_4};
const struct dbg_info * const dbg_info_oneofOPvalue_4 = (const struct dbg_info *)&dbg_info_oneofOPvalue_4_data;

extern errcode oneofOPvalue_5();
const Slist1 opformals_oneofOPvalue_5 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_5 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_5_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_5 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_5_1}};
const dbg_info_generic dbg_info_oneofOPvalue_5_data = {0, 14, "oneof$value_5", "oneof", 0, 1, oneofOPvalue_5, 1, (const Vlist0 *)&vals_oneofOPvalue_5, (const siglist0 *)&sigs_oneofOPvalue_5,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_5};
const struct dbg_info * const dbg_info_oneofOPvalue_5 = (const struct dbg_info *)&dbg_info_oneofOPvalue_5_data;

extern errcode oneofOPvalue_6();
const Slist1 opformals_oneofOPvalue_6 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_6 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_6_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_6 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_6_1}};
const dbg_info_generic dbg_info_oneofOPvalue_6_data = {0, 14, "oneof$value_6", "oneof", 0, 1, oneofOPvalue_6, 1, (const Vlist0 *)&vals_oneofOPvalue_6, (const siglist0 *)&sigs_oneofOPvalue_6,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_6};
const struct dbg_info * const dbg_info_oneofOPvalue_6 = (const struct dbg_info *)&dbg_info_oneofOPvalue_6_data;

extern errcode oneofOPvalue_7();
const Slist1 opformals_oneofOPvalue_7 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_7 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_7_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_7 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_7_1}};
const dbg_info_generic dbg_info_oneofOPvalue_7_data = {0, 14, "oneof$value_7", "oneof", 0, 1, oneofOPvalue_7, 1, (const Vlist0 *)&vals_oneofOPvalue_7, (const siglist0 *)&sigs_oneofOPvalue_7,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_7};
const struct dbg_info * const dbg_info_oneofOPvalue_7 = (const struct dbg_info *)&dbg_info_oneofOPvalue_7_data;

extern errcode oneofOPvalue_8();
const Slist1 opformals_oneofOPvalue_8 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_8 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_8_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_8 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_8_1}};
const dbg_info_generic dbg_info_oneofOPvalue_8_data = {0, 14, "oneof$value_8", "oneof", 0, 1, oneofOPvalue_8, 1, (const Vlist0 *)&vals_oneofOPvalue_8, (const siglist0 *)&sigs_oneofOPvalue_8,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_8};
const struct dbg_info * const dbg_info_oneofOPvalue_8 = (const struct dbg_info *)&dbg_info_oneofOPvalue_8_data;

extern errcode oneofOPvalue_9();
const Slist1 opformals_oneofOPvalue_9 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_9 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_9_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_9 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_9_1}};
const dbg_info_generic dbg_info_oneofOPvalue_9_data = {0, 14, "oneof$value_9", "oneof", 0, 1, oneofOPvalue_9, 1, (const Vlist0 *)&vals_oneofOPvalue_9, (const siglist0 *)&sigs_oneofOPvalue_9,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_9};
const struct dbg_info * const dbg_info_oneofOPvalue_9 = (const struct dbg_info *)&dbg_info_oneofOPvalue_9_data;

extern errcode oneofOPvalue_10();
const Slist1 opformals_oneofOPvalue_10 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_10 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_10_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_10 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_10_1}};
const dbg_info_generic dbg_info_oneofOPvalue_10_data = {0, 14, "oneof$value_10", "oneof", 0, 1, oneofOPvalue_10, 1, (const Vlist0 *)&vals_oneofOPvalue_10, (const siglist0 *)&sigs_oneofOPvalue_10,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_10};
const struct dbg_info * const dbg_info_oneofOPvalue_10 = (const struct dbg_info *)&dbg_info_oneofOPvalue_10_data;

extern errcode oneofOPvalue_11();
const Slist1 opformals_oneofOPvalue_11 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_11 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_11_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_11 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_11_1}};
const dbg_info_generic dbg_info_oneofOPvalue_11_data = {0, 14, "oneof$value_11", "oneof", 0, 1, oneofOPvalue_11, 1, (const Vlist0 *)&vals_oneofOPvalue_11, (const siglist0 *)&sigs_oneofOPvalue_11,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_11};
const struct dbg_info * const dbg_info_oneofOPvalue_11 = (const struct dbg_info *)&dbg_info_oneofOPvalue_11_data;

extern errcode oneofOPvalue_12();
const Slist1 opformals_oneofOPvalue_12 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_12 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_12_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_12 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_12_1}};
const dbg_info_generic dbg_info_oneofOPvalue_12_data = {0, 14, "oneof$value_12", "oneof", 0, 1, oneofOPvalue_12, 1, (const Vlist0 *)&vals_oneofOPvalue_12, (const siglist0 *)&sigs_oneofOPvalue_12,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_12};
const struct dbg_info * const dbg_info_oneofOPvalue_12 = (const struct dbg_info *)&dbg_info_oneofOPvalue_12_data;

extern errcode oneofOPvalue_13();
const Slist1 opformals_oneofOPvalue_13 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_13 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_13_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_13 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_13_1}};
const dbg_info_generic dbg_info_oneofOPvalue_13_data = {0, 14, "oneof$value_13", "oneof", 0, 1, oneofOPvalue_13, 1, (const Vlist0 *)&vals_oneofOPvalue_13, (const siglist0 *)&sigs_oneofOPvalue_13,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_13};
const struct dbg_info * const dbg_info_oneofOPvalue_13 = (const struct dbg_info *)&dbg_info_oneofOPvalue_13_data;

extern errcode oneofOPvalue_14();
const Slist1 opformals_oneofOPvalue_14 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_14 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_14_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_14 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_14_1}};
const dbg_info_generic dbg_info_oneofOPvalue_14_data = {0, 14, "oneof$value_14", "oneof", 0, 1, oneofOPvalue_14, 1, (const Vlist0 *)&vals_oneofOPvalue_14, (const siglist0 *)&sigs_oneofOPvalue_14,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_14};
const struct dbg_info * const dbg_info_oneofOPvalue_14 = (const struct dbg_info *)&dbg_info_oneofOPvalue_14_data;

extern errcode oneofOPvalue_15();
const Slist1 opformals_oneofOPvalue_15 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_15 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_15_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_15 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_15_1}};
const dbg_info_generic dbg_info_oneofOPvalue_15_data = {0, 14, "oneof$value_15", "oneof", 0, 1, oneofOPvalue_15, 1, (const Vlist0 *)&vals_oneofOPvalue_15, (const siglist0 *)&sigs_oneofOPvalue_15,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_15};
const struct dbg_info * const dbg_info_oneofOPvalue_15 = (const struct dbg_info *)&dbg_info_oneofOPvalue_15_data;

extern errcode oneofOPvalue_16();
const Slist1 opformals_oneofOPvalue_16 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_16 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_16_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_16 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_16_1}};
const dbg_info_generic dbg_info_oneofOPvalue_16_data = {0, 14, "oneof$value_16", "oneof", 0, 1, oneofOPvalue_16, 1, (const Vlist0 *)&vals_oneofOPvalue_16, (const siglist0 *)&sigs_oneofOPvalue_16,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_16};
const struct dbg_info * const dbg_info_oneofOPvalue_16 = (const struct dbg_info *)&dbg_info_oneofOPvalue_16_data;

extern errcode oneofOPvalue_17();
const Slist1 opformals_oneofOPvalue_17 = {0, 1, {"t"}};
static const Vlist1 vals_oneofOPvalue_17 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_oneofOPvalue_17_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_oneofOPvalue_17 = {0, 1, {(const sig_desc *)&sig_oneofOPvalue_17_1}};
const dbg_info_generic dbg_info_oneofOPvalue_17_data = {0, 14, "oneof$value_17", "oneof", 0, 1, oneofOPvalue_17, 1, (const Vlist0 *)&vals_oneofOPvalue_17, (const siglist0 *)&sigs_oneofOPvalue_17,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_oneofOPvalue_17};
const struct dbg_info * const dbg_info_oneofOPvalue_17 = (const struct dbg_info *)&dbg_info_oneofOPvalue_17_data;

extern errcode oneofOPequal();
static const Vlist1 vals_oneofOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPequal_data = {0, 14, "oneof$equal", "oneof", 0, 0, oneofOPequal, 2, (const Vlist0 *)&vals_oneofOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_oneofOPequal = (const struct dbg_info *)&dbg_info_oneofOPequal_data;

extern errcode oneofOPsimilar();
static const Vlist1 vals_oneofOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_oneofOPsimilar_data = {0, 14, "oneof$similar", "oneof", 0, 0, oneofOPsimilar, 2, (const Vlist0 *)&vals_oneofOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_oneofOPsimilar = (const struct dbg_info *)&dbg_info_oneofOPsimilar_data;

extern errcode oneofOPcopy();
static const Vlist1 vals_oneofOPcopy = {0, 1, {{0, 3, "", zero_ops, "ot_ops"}}};
const dbg_info_generic dbg_info_oneofOPcopy_data = {0, 14, "oneof$copy", "oneof", 0, 0, oneofOPcopy, 1, (const Vlist0 *)&vals_oneofOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_oneofOPcopy = (const struct dbg_info *)&dbg_info_oneofOPcopy_data;

extern errcode oneofOPprint();
const dbg_info_generic dbg_info_oneofOPprint_data = {0, 14, "oneof$print", "oneof", 0, 0, oneofOPprint, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_oneofOPprint = (const struct dbg_info *)&dbg_info_oneofOPprint_data;

extern errcode rename_file();
static const sig_desc1 sig_rename_file_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs_rename_file = {0, 1, {(const sig_desc *)&sig_rename_file_1}};
const dbg_info_generic dbg_info_rename_file_data = {0, 14, "rename_file", "rename_file", 0, 0, rename_file, 2, &NO_VALS, (const siglist0 *)&sigs_rename_file,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_rename_file = (const struct dbg_info *)&dbg_info_rename_file_data;

extern errcode _get_runtime();
static const Vlist3 vals__get_runtime = {0, 3, {{0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__get_runtime_data = {0, 14, "_get_runtime", "_get_runtime", 0, 0, _get_runtime, 0, (const Vlist0 *)&vals__get_runtime, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__get_runtime = (const struct dbg_info *)&dbg_info__get_runtime_data;

#if 0
extern errcode _free_space();
static const Vlist1 vals__free_space = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__free_space_data = {0, 14, "_free_space", "_free_space", 0, 0, _free_space, 0, (const Vlist0 *)&vals__free_space, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__free_space = (const struct dbg_info *)&dbg_info__free_space_data;
#endif

extern errcode i_set1();
static const Vlist1 vals_i_set1 = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_i_set1_1 = {0, 2, "bounds", {0,0}};
static const sig_desc0 sig_i_set1_2 = {0, 2, "overflow", {0,0}};
static const siglist2 sigs_i_set1 = {0, 2, {(const sig_desc *)&sig_i_set1_1, (const sig_desc *)&sig_i_set1_2}};
const dbg_info_generic dbg_info_i_set1_data = {0, 14, "i_set1", "i_set1", 0, 0, i_set1, 3, (const Vlist0 *)&vals_i_set1, (const siglist0 *)&sigs_i_set1,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_i_set1 = (const struct dbg_info *)&dbg_info_i_set1_data;

extern errcode hash_obj();
static const Vlist1 vals_hash_obj = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_hash_obj_data = {0, 14, "hash_obj", "hash_obj", 0, 0, hash_obj, 2, (const Vlist0 *)&vals_hash_obj, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_hash_obj = (const struct dbg_info *)&dbg_info_hash_obj_data;

extern errcode _stop();
const dbg_info_generic dbg_info__stop_data = {0, 14, "_stop", "_stop", 0, 0, _stop, 0, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__stop = (const struct dbg_info *)&dbg_info__stop_data;

extern errcode now();
extern struct OPS* date_ops;
static const Vlist1 vals_now = {0, 1, {{0, 2, "", &date_ops, ""}}};
const dbg_info_generic dbg_info_now_data = {0, 14, "now", "now", 0, 0, now, 0, (const Vlist0 *)&vals_now, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_now = (const struct dbg_info *)&dbg_info_now_data;

extern errcode stream2chan();
static const Vlist1 vals_stream2chan = {0, 1, {{0, 2, "", &_chan_ops, ""}}};
static const sig_desc1 sig_stream2chan_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs_stream2chan = {0, 1, {(const sig_desc *)&sig_stream2chan_1}};
const dbg_info_generic dbg_info_stream2chan_data = {0, 14, "stream2chan", "stream2chan", 0, 0, stream2chan, 1, (const Vlist0 *)&vals_stream2chan, (const siglist0 *)&sigs_stream2chan,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stream2chan = (const struct dbg_info *)&dbg_info_stream2chan_data;

const Slist1 tformals_array = {0, 1, {"t"}};
extern errcode arrayOPcreate();
static const Vlist1 vals_arrayOPcreate = {0, 1, {{0, 3, "", zero_ops, "array_of_t_ops"}}};
const dbg_info_generic dbg_info_arrayOPcreate_data = {0, 14, "array$create", "array", 0, 2, arrayOPcreate, 1, (const Vlist0 *)&vals_arrayOPcreate, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPcreate = (const struct dbg_info *)&dbg_info_arrayOPcreate_data;

extern errcode arrayOPnew();
static const Vlist1 vals_arrayOPnew = {0, 1, {{0, 3, "", zero_ops, "array_of_t_ops"}}};
const dbg_info_generic dbg_info_arrayOPnew_data = {0, 14, "array$new", "array", 0, 2, arrayOPnew, 0, (const Vlist0 *)&vals_arrayOPnew, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPnew = (const struct dbg_info *)&dbg_info_arrayOPnew_data;

extern errcode arrayOPpredict();
static const Vlist1 vals_arrayOPpredict = {0, 1, {{0, 3, "", zero_ops, "array_of_t_ops"}}};
const dbg_info_generic dbg_info_arrayOPpredict_data = {0, 14, "array$predict", "array", 0, 2, arrayOPpredict, 2, (const Vlist0 *)&vals_arrayOPpredict, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPpredict = (const struct dbg_info *)&dbg_info_arrayOPpredict_data;

extern errcode arrayOPcons();
static const Vlist1 vals_arrayOPcons = {0, 1, {{0, 3, "", zero_ops, "array_of_t_ops"}}};
const dbg_info_generic dbg_info_arrayOPcons_data = {0, 14, "array$cons", "array", 0, 2, arrayOPcons, 1, (const Vlist0 *)&vals_arrayOPcons, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPcons = (const struct dbg_info *)&dbg_info_arrayOPcons_data;

extern errcode arrayOPcons2();
static const Vlist1 vals_arrayOPcons2 = {0, 1, {{0, 3, "", zero_ops, "array_of_t_ops"}}};
const dbg_info_generic dbg_info_arrayOPcons2_data = {0, 14, "array$cons2", "array", 0, 2, arrayOPcons2, 2, (const Vlist0 *)&vals_arrayOPcons2, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPcons2 = (const struct dbg_info *)&dbg_info_arrayOPcons2_data;

extern errcode arrayOPempty();
static const Vlist1 vals_arrayOPempty = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_arrayOPempty_data = {0, 14, "array$empty", "array", 0, 2, arrayOPempty, 1, (const Vlist0 *)&vals_arrayOPempty, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPempty = (const struct dbg_info *)&dbg_info_arrayOPempty_data;

extern errcode arrayOPlow();
static const Vlist1 vals_arrayOPlow = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_arrayOPlow_data = {0, 14, "array$low", "array", 0, 2, arrayOPlow, 1, (const Vlist0 *)&vals_arrayOPlow, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPlow = (const struct dbg_info *)&dbg_info_arrayOPlow_data;

extern errcode arrayOPhigh();
static const Vlist1 vals_arrayOPhigh = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_arrayOPhigh_data = {0, 14, "array$high", "array", 0, 2, arrayOPhigh, 1, (const Vlist0 *)&vals_arrayOPhigh, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPhigh = (const struct dbg_info *)&dbg_info_arrayOPhigh_data;

extern errcode arrayOPsize();
static const Vlist1 vals_arrayOPsize = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_arrayOPsize_data = {0, 14, "array$size", "array", 0, 2, arrayOPsize, 1, (const Vlist0 *)&vals_arrayOPsize, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPsize = (const struct dbg_info *)&dbg_info_arrayOPsize_data;

extern errcode arrayOPset_low();
const dbg_info_generic dbg_info_arrayOPset_low_data = {0, 14, "array$set_low", "array", 0, 2, arrayOPset_low, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPset_low = (const struct dbg_info *)&dbg_info_arrayOPset_low_data;

extern errcode arrayOPtrim();
static const sig_desc0 sig_arrayOPtrim_1 = {0, 2, "bounds", {0,0}};
static const sig_desc0 sig_arrayOPtrim_2 = {0, 2, "negative_size", {0,0}};
static const siglist2 sigs_arrayOPtrim = {0, 2, {(const sig_desc *)&sig_arrayOPtrim_1, (const sig_desc *)&sig_arrayOPtrim_2}};
const dbg_info_generic dbg_info_arrayOPtrim_data = {0, 14, "array$trim", "array", 0, 2, arrayOPtrim, 3, &NO_VALS, (const siglist0 *)&sigs_arrayOPtrim,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPtrim = (const struct dbg_info *)&dbg_info_arrayOPtrim_data;

extern errcode arrayOPfill();
static const Vlist1 vals_arrayOPfill = {0, 1, {{0, 3, "", zero_ops, "array_of_t_ops"}}};
static const sig_desc0 sig_arrayOPfill_1 = {0, 2, "negative_size", {0,0}};
static const siglist1 sigs_arrayOPfill = {0, 1, {(const sig_desc *)&sig_arrayOPfill_1}};
const dbg_info_generic dbg_info_arrayOPfill_data = {0, 14, "array$fill", "array", 0, 2, arrayOPfill, 3, (const Vlist0 *)&vals_arrayOPfill, (const siglist0 *)&sigs_arrayOPfill,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPfill = (const struct dbg_info *)&dbg_info_arrayOPfill_data;

extern errcode arrayOPfill_copy();
static const Vlist1 vals_arrayOPfill_copy = {0, 1, {{0, 3, "", zero_ops, "array_of_t_ops"}}};
static const sig_desc0 sig_arrayOPfill_copy_1 = {0, 2, "negative_size", {0,0}};
static const siglist1 sigs_arrayOPfill_copy = {0, 1, {(const sig_desc *)&sig_arrayOPfill_copy_1}};
const dbg_info_generic dbg_info_arrayOPfill_copy_data = {0, 14, "array$fill_copy", "array", 0, 2, arrayOPfill_copy, 3, (const Vlist0 *)&vals_arrayOPfill_copy, (const siglist0 *)&sigs_arrayOPfill_copy,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPfill_copy = (const struct dbg_info *)&dbg_info_arrayOPfill_copy_data;

extern errcode arrayOPfetch();
static const Vlist1 vals_arrayOPfetch = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_arrayOPfetch_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_arrayOPfetch = {0, 1, {(const sig_desc *)&sig_arrayOPfetch_1}};
const dbg_info_generic dbg_info_arrayOPfetch_data = {0, 14, "array$fetch", "array", 0, 2, arrayOPfetch, 2, (const Vlist0 *)&vals_arrayOPfetch, (const siglist0 *)&sigs_arrayOPfetch,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPfetch = (const struct dbg_info *)&dbg_info_arrayOPfetch_data;

extern errcode arrayOPbottom();
static const Vlist1 vals_arrayOPbottom = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_arrayOPbottom_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_arrayOPbottom = {0, 1, {(const sig_desc *)&sig_arrayOPbottom_1}};
const dbg_info_generic dbg_info_arrayOPbottom_data = {0, 14, "array$bottom", "array", 0, 2, arrayOPbottom, 1, (const Vlist0 *)&vals_arrayOPbottom, (const siglist0 *)&sigs_arrayOPbottom,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPbottom = (const struct dbg_info *)&dbg_info_arrayOPbottom_data;

extern errcode arrayOPtop();
static const Vlist1 vals_arrayOPtop = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_arrayOPtop_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_arrayOPtop = {0, 1, {(const sig_desc *)&sig_arrayOPtop_1}};
const dbg_info_generic dbg_info_arrayOPtop_data = {0, 14, "array$top", "array", 0, 2, arrayOPtop, 1, (const Vlist0 *)&vals_arrayOPtop, (const siglist0 *)&sigs_arrayOPtop,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPtop = (const struct dbg_info *)&dbg_info_arrayOPtop_data;

extern errcode arrayOPstore();
static const sig_desc0 sig_arrayOPstore_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_arrayOPstore = {0, 1, {(const sig_desc *)&sig_arrayOPstore_1}};
const dbg_info_generic dbg_info_arrayOPstore_data = {0, 14, "array$store", "array", 0, 2, arrayOPstore, 3, &NO_VALS, (const siglist0 *)&sigs_arrayOPstore,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPstore = (const struct dbg_info *)&dbg_info_arrayOPstore_data;

extern errcode arrayOPaddh();
const dbg_info_generic dbg_info_arrayOPaddh_data = {0, 14, "array$addh", "array", 0, 2, arrayOPaddh, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPaddh = (const struct dbg_info *)&dbg_info_arrayOPaddh_data;

extern errcode arrayOPaddl();
const dbg_info_generic dbg_info_arrayOPaddl_data = {0, 14, "array$addl", "array", 0, 2, arrayOPaddl, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPaddl = (const struct dbg_info *)&dbg_info_arrayOPaddl_data;

extern errcode arrayOPremh();
static const Vlist1 vals_arrayOPremh = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_arrayOPremh_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_arrayOPremh = {0, 1, {(const sig_desc *)&sig_arrayOPremh_1}};
const dbg_info_generic dbg_info_arrayOPremh_data = {0, 14, "array$remh", "array", 0, 2, arrayOPremh, 1, (const Vlist0 *)&vals_arrayOPremh, (const siglist0 *)&sigs_arrayOPremh,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPremh = (const struct dbg_info *)&dbg_info_arrayOPremh_data;

extern errcode arrayOPreml();
static const Vlist1 vals_arrayOPreml = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_arrayOPreml_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_arrayOPreml = {0, 1, {(const sig_desc *)&sig_arrayOPreml_1}};
const dbg_info_generic dbg_info_arrayOPreml_data = {0, 14, "array$reml", "array", 0, 2, arrayOPreml, 1, (const Vlist0 *)&vals_arrayOPreml, (const siglist0 *)&sigs_arrayOPreml,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPreml = (const struct dbg_info *)&dbg_info_arrayOPreml_data;

extern errcode arrayOPelements();
static const Vlist1 vals_arrayOPelements = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_arrayOPelements_data = {0, 14, "array$elements", "array", 1, 2, arrayOPelements, 1, (const Vlist0 *)&vals_arrayOPelements, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPelements = (const struct dbg_info *)&dbg_info_arrayOPelements_data;

extern errcode arrayOPindexes();
static const Vlist1 vals_arrayOPindexes = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_arrayOPindexes_data = {0, 14, "array$indexes", "array", 1, 2, arrayOPindexes, 1, (const Vlist0 *)&vals_arrayOPindexes, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPindexes = (const struct dbg_info *)&dbg_info_arrayOPindexes_data;

extern errcode arrayOPequal();
static const Vlist1 vals_arrayOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_arrayOPequal_data = {0, 14, "array$equal", "array", 0, 2, arrayOPequal, 2, (const Vlist0 *)&vals_arrayOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPequal = (const struct dbg_info *)&dbg_info_arrayOPequal_data;

extern errcode arrayOPsimilar();
static const Vlist1 vals_arrayOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_arrayOPsimilar_data = {0, 14, "array$similar", "array", 0, 2, arrayOPsimilar, 2, (const Vlist0 *)&vals_arrayOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPsimilar = (const struct dbg_info *)&dbg_info_arrayOPsimilar_data;

extern errcode arrayOPsimilar1();
static const Vlist1 vals_arrayOPsimilar1 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_arrayOPsimilar1_data = {0, 14, "array$similar1", "array", 0, 2, arrayOPsimilar1, 2, (const Vlist0 *)&vals_arrayOPsimilar1, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPsimilar1 = (const struct dbg_info *)&dbg_info_arrayOPsimilar1_data;

extern errcode arrayOPcopy();
static const Vlist1 vals_arrayOPcopy = {0, 1, {{0, 3, "", zero_ops, "array_of_t_ops"}}};
const dbg_info_generic dbg_info_arrayOPcopy_data = {0, 14, "array$copy", "array", 0, 2, arrayOPcopy, 1, (const Vlist0 *)&vals_arrayOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPcopy = (const struct dbg_info *)&dbg_info_arrayOPcopy_data;

extern errcode arrayOPcopy1();
static const Vlist1 vals_arrayOPcopy1 = {0, 1, {{0, 3, "", zero_ops, "array_of_t_ops"}}};
const dbg_info_generic dbg_info_arrayOPcopy1_data = {0, 14, "array$copy1", "array", 0, 2, arrayOPcopy1, 1, (const Vlist0 *)&vals_arrayOPcopy1, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPcopy1 = (const struct dbg_info *)&dbg_info_arrayOPcopy1_data;

extern errcode arrayOPprint();
const dbg_info_generic dbg_info_arrayOPprint_data = {0, 14, "array$print", "array", 0, 2, arrayOPprint, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_array,&NO_PARMS};
const struct dbg_info * const dbg_info_arrayOPprint = (const struct dbg_info *)&dbg_info_arrayOPprint_data;

const Slist1 tformals_itertype = {0, 1, {"it"}};
extern errcode itertypeOPequal();
static const Vlist1 vals_itertypeOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_itertypeOPequal_data = {0, 14, "itertype$equal", "itertype", 0, 2, itertypeOPequal, 2, (const Vlist0 *)&vals_itertypeOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_itertype,&NO_PARMS};
const struct dbg_info * const dbg_info_itertypeOPequal = (const struct dbg_info *)&dbg_info_itertypeOPequal_data;

extern errcode itertypeOPsimilar();
static const Vlist1 vals_itertypeOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_itertypeOPsimilar_data = {0, 14, "itertype$similar", "itertype", 0, 2, itertypeOPsimilar, 2, (const Vlist0 *)&vals_itertypeOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_itertype,&NO_PARMS};
const struct dbg_info * const dbg_info_itertypeOPsimilar = (const struct dbg_info *)&dbg_info_itertypeOPsimilar_data;

extern errcode itertypeOPcopy();
static const Vlist1 vals_itertypeOPcopy = {0, 1, {{0, 3, "", zero_ops, "it_ops"}}};
const dbg_info_generic dbg_info_itertypeOPcopy_data = {0, 14, "itertype$copy", "itertype", 0, 2, itertypeOPcopy, 1, (const Vlist0 *)&vals_itertypeOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_itertype,&NO_PARMS};
const struct dbg_info * const dbg_info_itertypeOPcopy = (const struct dbg_info *)&dbg_info_itertypeOPcopy_data;

extern errcode _pause();
const dbg_info_generic dbg_info__pause_data = {0, 14, "_pause", "_pause", 0, 0, _pause, 0, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__pause = (const struct dbg_info *)&dbg_info__pause_data;

extern errcode get_jcl();
static const Vlist1 vals_get_jcl = {0, 1, {{0, 2, "", &string_ops, ""}}};
const dbg_info_generic dbg_info_get_jcl_data = {0, 14, "get_jcl", "get_jcl", 0, 0, get_jcl, 0, (const Vlist0 *)&vals_get_jcl, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_get_jcl = (const struct dbg_info *)&dbg_info_get_jcl_data;

extern errcode _cvt();
const Slist2 opformals__cvt = {0, 2, {"from", "to"}};
static const Vlist1 vals__cvt = {0, 1, {{0, 3, "", zero_ops, "to_ops"}}};
const dbg_info_generic dbg_info__cvt_data = {0, 14, "_cvt", "_cvt", 0, 1, _cvt, 1, (const Vlist0 *)&vals__cvt, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals__cvt};
const struct dbg_info * const dbg_info__cvt = (const struct dbg_info *)&dbg_info__cvt_data;

extern errcode recordOPget_1();
const Slist1 opformals_recordOPget_1 = {0, 1, {"t"}};
static const Vlist1 vals_recordOPget_1 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_recordOPget_1_data = {0, 14, "record$get_1", "record", 0, 1, recordOPget_1, 1, (const Vlist0 *)&vals_recordOPget_1, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPget_1};
const struct dbg_info * const dbg_info_recordOPget_1 = (const struct dbg_info *)&dbg_info_recordOPget_1_data;

extern errcode recordOPget_2();
const Slist1 opformals_recordOPget_2 = {0, 1, {"t"}};
static const Vlist1 vals_recordOPget_2 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_recordOPget_2_data = {0, 14, "record$get_2", "record", 0, 1, recordOPget_2, 1, (const Vlist0 *)&vals_recordOPget_2, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPget_2};
const struct dbg_info * const dbg_info_recordOPget_2 = (const struct dbg_info *)&dbg_info_recordOPget_2_data;

extern errcode recordOPget_3();
const Slist1 opformals_recordOPget_3 = {0, 1, {"t"}};
static const Vlist1 vals_recordOPget_3 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_recordOPget_3_data = {0, 14, "record$get_3", "record", 0, 1, recordOPget_3, 1, (const Vlist0 *)&vals_recordOPget_3, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPget_3};
const struct dbg_info * const dbg_info_recordOPget_3 = (const struct dbg_info *)&dbg_info_recordOPget_3_data;

extern errcode recordOPget_4();
const Slist1 opformals_recordOPget_4 = {0, 1, {"t"}};
static const Vlist1 vals_recordOPget_4 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_recordOPget_4_data = {0, 14, "record$get_4", "record", 0, 1, recordOPget_4, 1, (const Vlist0 *)&vals_recordOPget_4, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPget_4};
const struct dbg_info * const dbg_info_recordOPget_4 = (const struct dbg_info *)&dbg_info_recordOPget_4_data;

extern errcode recordOPget_5();
const Slist1 opformals_recordOPget_5 = {0, 1, {"t"}};
static const Vlist1 vals_recordOPget_5 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_recordOPget_5_data = {0, 14, "record$get_5", "record", 0, 1, recordOPget_5, 1, (const Vlist0 *)&vals_recordOPget_5, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPget_5};
const struct dbg_info * const dbg_info_recordOPget_5 = (const struct dbg_info *)&dbg_info_recordOPget_5_data;

extern errcode recordOPget_6();
const Slist1 opformals_recordOPget_6 = {0, 1, {"t"}};
static const Vlist1 vals_recordOPget_6 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_recordOPget_6_data = {0, 14, "record$get_6", "record", 0, 1, recordOPget_6, 1, (const Vlist0 *)&vals_recordOPget_6, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPget_6};
const struct dbg_info * const dbg_info_recordOPget_6 = (const struct dbg_info *)&dbg_info_recordOPget_6_data;

extern errcode recordOPget_7();
const Slist1 opformals_recordOPget_7 = {0, 1, {"t"}};
static const Vlist1 vals_recordOPget_7 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_recordOPget_7_data = {0, 14, "record$get_7", "record", 0, 1, recordOPget_7, 1, (const Vlist0 *)&vals_recordOPget_7, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPget_7};
const struct dbg_info * const dbg_info_recordOPget_7 = (const struct dbg_info *)&dbg_info_recordOPget_7_data;

extern errcode recordOPget_8();
const Slist1 opformals_recordOPget_8 = {0, 1, {"t"}};
static const Vlist1 vals_recordOPget_8 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_recordOPget_8_data = {0, 14, "record$get_8", "record", 0, 1, recordOPget_8, 1, (const Vlist0 *)&vals_recordOPget_8, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPget_8};
const struct dbg_info * const dbg_info_recordOPget_8 = (const struct dbg_info *)&dbg_info_recordOPget_8_data;

extern errcode recordOPget_9();
const Slist1 opformals_recordOPget_9 = {0, 1, {"t"}};
static const Vlist1 vals_recordOPget_9 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_recordOPget_9_data = {0, 14, "record$get_9", "record", 0, 1, recordOPget_9, 1, (const Vlist0 *)&vals_recordOPget_9, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPget_9};
const struct dbg_info * const dbg_info_recordOPget_9 = (const struct dbg_info *)&dbg_info_recordOPget_9_data;

extern errcode recordOPget_10();
const Slist1 opformals_recordOPget_10 = {0, 1, {"t"}};
static const Vlist1 vals_recordOPget_10 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_recordOPget_10_data = {0, 14, "record$get_10", "record", 0, 1, recordOPget_10, 1, (const Vlist0 *)&vals_recordOPget_10, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPget_10};
const struct dbg_info * const dbg_info_recordOPget_10 = (const struct dbg_info *)&dbg_info_recordOPget_10_data;

extern errcode recordOPset_1();
const Slist1 opformals_recordOPset_1 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_recordOPset_1_data = {0, 14, "record$set_1", "record", 0, 1, recordOPset_1, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPset_1};
const struct dbg_info * const dbg_info_recordOPset_1 = (const struct dbg_info *)&dbg_info_recordOPset_1_data;

extern errcode recordOPset_2();
const Slist1 opformals_recordOPset_2 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_recordOPset_2_data = {0, 14, "record$set_2", "record", 0, 1, recordOPset_2, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPset_2};
const struct dbg_info * const dbg_info_recordOPset_2 = (const struct dbg_info *)&dbg_info_recordOPset_2_data;

extern errcode recordOPset_3();
const Slist1 opformals_recordOPset_3 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_recordOPset_3_data = {0, 14, "record$set_3", "record", 0, 1, recordOPset_3, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPset_3};
const struct dbg_info * const dbg_info_recordOPset_3 = (const struct dbg_info *)&dbg_info_recordOPset_3_data;

extern errcode recordOPset_4();
const Slist1 opformals_recordOPset_4 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_recordOPset_4_data = {0, 14, "record$set_4", "record", 0, 1, recordOPset_4, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPset_4};
const struct dbg_info * const dbg_info_recordOPset_4 = (const struct dbg_info *)&dbg_info_recordOPset_4_data;

extern errcode recordOPset_5();
const Slist1 opformals_recordOPset_5 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_recordOPset_5_data = {0, 14, "record$set_5", "record", 0, 1, recordOPset_5, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPset_5};
const struct dbg_info * const dbg_info_recordOPset_5 = (const struct dbg_info *)&dbg_info_recordOPset_5_data;

extern errcode recordOPset_6();
const Slist1 opformals_recordOPset_6 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_recordOPset_6_data = {0, 14, "record$set_6", "record", 0, 1, recordOPset_6, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPset_6};
const struct dbg_info * const dbg_info_recordOPset_6 = (const struct dbg_info *)&dbg_info_recordOPset_6_data;

extern errcode recordOPset_7();
const Slist1 opformals_recordOPset_7 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_recordOPset_7_data = {0, 14, "record$set_7", "record", 0, 1, recordOPset_7, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPset_7};
const struct dbg_info * const dbg_info_recordOPset_7 = (const struct dbg_info *)&dbg_info_recordOPset_7_data;

extern errcode recordOPset_8();
const Slist1 opformals_recordOPset_8 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_recordOPset_8_data = {0, 14, "record$set_8", "record", 0, 1, recordOPset_8, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPset_8};
const struct dbg_info * const dbg_info_recordOPset_8 = (const struct dbg_info *)&dbg_info_recordOPset_8_data;

extern errcode recordOPset_9();
const Slist1 opformals_recordOPset_9 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_recordOPset_9_data = {0, 14, "record$set_9", "record", 0, 1, recordOPset_9, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPset_9};
const struct dbg_info * const dbg_info_recordOPset_9 = (const struct dbg_info *)&dbg_info_recordOPset_9_data;

extern errcode recordOPset_10();
const Slist1 opformals_recordOPset_10 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_recordOPset_10_data = {0, 14, "record$set_10", "record", 0, 1, recordOPset_10, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_recordOPset_10};
const struct dbg_info * const dbg_info_recordOPset_10 = (const struct dbg_info *)&dbg_info_recordOPset_10_data;

extern errcode recordOPr_gets_r();
const dbg_info_generic dbg_info_recordOPr_gets_r_data = {0, 14, "record$r_gets_r", "record", 0, 0, recordOPr_gets_r, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_recordOPr_gets_r = (const struct dbg_info *)&dbg_info_recordOPr_gets_r_data;

extern errcode recordOPequal();
static const Vlist1 vals_recordOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_recordOPequal_data = {0, 14, "record$equal", "record", 0, 0, recordOPequal, 2, (const Vlist0 *)&vals_recordOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_recordOPequal = (const struct dbg_info *)&dbg_info_recordOPequal_data;

extern errcode recordOPsimilar();
static const Vlist1 vals_recordOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_recordOPsimilar_data = {0, 14, "record$similar", "record", 0, 0, recordOPsimilar, 2, (const Vlist0 *)&vals_recordOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_recordOPsimilar = (const struct dbg_info *)&dbg_info_recordOPsimilar_data;

extern errcode recordOPsimilar1();
static const Vlist1 vals_recordOPsimilar1 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_recordOPsimilar1_data = {0, 14, "record$similar1", "record", 0, 0, recordOPsimilar1, 2, (const Vlist0 *)&vals_recordOPsimilar1, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_recordOPsimilar1 = (const struct dbg_info *)&dbg_info_recordOPsimilar1_data;

extern errcode recordOPcopy();
static const Vlist1 vals_recordOPcopy = {0, 1, {{0, 3, "", zero_ops, "rt_ops"}}};
const dbg_info_generic dbg_info_recordOPcopy_data = {0, 14, "record$copy", "record", 0, 0, recordOPcopy, 1, (const Vlist0 *)&vals_recordOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_recordOPcopy = (const struct dbg_info *)&dbg_info_recordOPcopy_data;

extern errcode recordOPcopy1();
static const Vlist1 vals_recordOPcopy1 = {0, 1, {{0, 3, "", zero_ops, "rt_ops"}}};
const dbg_info_generic dbg_info_recordOPcopy1_data = {0, 14, "record$copy1", "record", 0, 0, recordOPcopy1, 1, (const Vlist0 *)&vals_recordOPcopy1, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_recordOPcopy1 = (const struct dbg_info *)&dbg_info_recordOPcopy1_data;

extern errcode recordOPprint();
const dbg_info_generic dbg_info_recordOPprint_data = {0, 14, "record$print", "record", 0, 0, recordOPprint, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_recordOPprint = (const struct dbg_info *)&dbg_info_recordOPprint_data;

extern errcode _gcOPcount();
static const Vlist1 vals__gcOPcount = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__gcOPcount_data = {0, 14, "_gc$count", "_gc", 0, 0, _gcOPcount, 0, (const Vlist0 *)&vals__gcOPcount, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__gcOPcount = (const struct dbg_info *)&dbg_info__gcOPcount_data;

#if 0
extern errcode _gc_control();
static const sig_desc0 sig__gc_control_1 = {0, 2, "illegal", {0,0}};
static const siglist1 sigs__gc_control = {0, 1, {(const sig_desc *)&sig__gc_control_1}};
const dbg_info_generic dbg_info__gc_control_data = {0, 14, "_gc$control", "_gc", 0, 0, _gc_control, 2, &NO_VALS, (const siglist0 *)&sigs__gc_control,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__gc_control = (const struct dbg_info *)&dbg_info__gc_control_data;
#endif

extern errcode _gcOPgc();
const dbg_info_generic dbg_info__gcOPgc_data = {0, 14, "_gc$gc", "_gc", 0, 0, _gcOPgc, 0, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__gcOPgc = (const struct dbg_info *)&dbg_info__gcOPgc_data;

extern errcode _select();
static const Vlist4 vals__select = {0, 4, {{0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__select_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__select = {0, 1, {(const sig_desc *)&sig__select_1}};
const dbg_info_generic dbg_info__select_data = {0, 14, "_select", "_select", 0, 0, _select, 5, (const Vlist0 *)&vals__select, (const siglist0 *)&sigs__select,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__select = (const struct dbg_info *)&dbg_info__select_data;

extern errcode _lstat();
static const sig_desc0 sig__lstat_1 = {0, 2, "bounds", {0,0}};
static const sig_desc1 sig__lstat_2 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist2 sigs__lstat = {0, 2, {(const sig_desc *)&sig__lstat_1, (const sig_desc *)&sig__lstat_2}};
const dbg_info_generic dbg_info__lstat_data = {0, 14, "_lstat", "_lstat", 0, 0, _lstat, 2, &NO_VALS, (const siglist0 *)&sigs__lstat,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__lstat = (const struct dbg_info *)&dbg_info__lstat_data;

extern errcode i_first1();
static const Vlist1 vals_i_first1 = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_i_first1_1 = {0, 2, "none", {0,0}};
static const siglist1 sigs_i_first1 = {0, 1, {(const sig_desc *)&sig_i_first1_1}};
const dbg_info_generic dbg_info_i_first1_data = {0, 14, "i_first1", "i_first1", 0, 0, i_first1, 1, (const Vlist0 *)&vals_i_first1, (const siglist0 *)&sigs_i_first1,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_i_first1 = (const struct dbg_info *)&dbg_info_i_first1_data;

extern errcode _dtable_size();
static const Vlist1 vals__dtable_size = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__dtable_size_data = {0, 14, "_dtable_size", "_dtable_size", 0, 0, _dtable_size, 0, (const Vlist0 *)&vals__dtable_size, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__dtable_size = (const struct dbg_info *)&dbg_info__dtable_size_data;

extern errcode _environ();
static const Vlist1 vals__environ = {0, 1, {{0, 2, "", &string_ops, ""}}};
static const sig_desc0 sig__environ_1 = {0, 2, "not_found", {0,0}};
static const siglist1 sigs__environ = {0, 1, {(const sig_desc *)&sig__environ_1}};
const dbg_info_generic dbg_info__environ_data = {0, 14, "_environ", "_environ", 0, 0, _environ, 1, (const Vlist0 *)&vals__environ, (const siglist0 *)&sigs__environ,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__environ = (const struct dbg_info *)&dbg_info__environ_data;

extern errcode _set_alarm();
static const Vlist1 vals__set_alarm = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info__set_alarm_data = {0, 14, "_set_alarm", "_set_alarm", 0, 0, _set_alarm, 1, (const Vlist0 *)&vals__set_alarm, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__set_alarm = (const struct dbg_info *)&dbg_info__set_alarm_data;

extern errcode _host_address();
static const Vlist2 vals__host_address = {0, 2, {{0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__host_address_data = {0, 14, "_host_address", "_host_address", 0, 0, _host_address, 1, (const Vlist0 *)&vals__host_address, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__host_address = (const struct dbg_info *)&dbg_info__host_address_data;

extern errcode sin();
static const Vlist1 vals_sin = {0, 1, {{0, 2, "", &real_ops, ""}}};
const dbg_info_generic dbg_info_sin_data = {0, 14, "sin", "sin", 0, 0, sin, 1, (const Vlist0 *)&vals_sin, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_sin = (const struct dbg_info *)&dbg_info_sin_data;

extern errcode realOPadd();
static const Vlist1 vals_realOPadd = {0, 1, {{0, 2, "", &real_ops, ""}}};
static const sig_desc0 sig_realOPadd_1 = {0, 2, "overflow", {0,0}};
static const sig_desc0 sig_realOPadd_2 = {0, 2, "underflow", {0,0}};
static const siglist2 sigs_realOPadd = {0, 2, {(const sig_desc *)&sig_realOPadd_1, (const sig_desc *)&sig_realOPadd_2}};
const dbg_info_generic dbg_info_realOPadd_data = {0, 14, "real$add", "real", 0, 0, realOPadd, 2, (const Vlist0 *)&vals_realOPadd, (const siglist0 *)&sigs_realOPadd,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPadd = (const struct dbg_info *)&dbg_info_realOPadd_data;

extern errcode realOPsub();
static const Vlist1 vals_realOPsub = {0, 1, {{0, 2, "", &real_ops, ""}}};
static const sig_desc0 sig_realOPsub_1 = {0, 2, "overflow", {0,0}};
static const sig_desc0 sig_realOPsub_2 = {0, 2, "underflow", {0,0}};
static const siglist2 sigs_realOPsub = {0, 2, {(const sig_desc *)&sig_realOPsub_1, (const sig_desc *)&sig_realOPsub_2}};
const dbg_info_generic dbg_info_realOPsub_data = {0, 14, "real$sub", "real", 0, 0, realOPsub, 2, (const Vlist0 *)&vals_realOPsub, (const siglist0 *)&sigs_realOPsub,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPsub = (const struct dbg_info *)&dbg_info_realOPsub_data;

extern errcode realOPmul();
static const Vlist1 vals_realOPmul = {0, 1, {{0, 2, "", &real_ops, ""}}};
static const sig_desc0 sig_realOPmul_1 = {0, 2, "overflow", {0,0}};
static const sig_desc0 sig_realOPmul_2 = {0, 2, "underflow", {0,0}};
static const siglist2 sigs_realOPmul = {0, 2, {(const sig_desc *)&sig_realOPmul_1, (const sig_desc *)&sig_realOPmul_2}};
const dbg_info_generic dbg_info_realOPmul_data = {0, 14, "real$mul", "real", 0, 0, realOPmul, 2, (const Vlist0 *)&vals_realOPmul, (const siglist0 *)&sigs_realOPmul,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPmul = (const struct dbg_info *)&dbg_info_realOPmul_data;

extern errcode realOPdiv();
static const Vlist1 vals_realOPdiv = {0, 1, {{0, 2, "", &real_ops, ""}}};
static const sig_desc0 sig_realOPdiv_1 = {0, 2, "overflow", {0,0}};
static const sig_desc0 sig_realOPdiv_2 = {0, 2, "underflow", {0,0}};
static const sig_desc0 sig_realOPdiv_3 = {0, 2, "zero_divide", {0,0}};
static const siglist3 sigs_realOPdiv = {0, 3, {(const sig_desc *)&sig_realOPdiv_1, (const sig_desc *)&sig_realOPdiv_2, (const sig_desc *)&sig_realOPdiv_3}};
const dbg_info_generic dbg_info_realOPdiv_data = {0, 14, "real$div", "real", 0, 0, realOPdiv, 2, (const Vlist0 *)&vals_realOPdiv, (const siglist0 *)&sigs_realOPdiv,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPdiv = (const struct dbg_info *)&dbg_info_realOPdiv_data;

extern errcode realOPminus();
static const Vlist1 vals_realOPminus = {0, 1, {{0, 2, "", &real_ops, ""}}};
const dbg_info_generic dbg_info_realOPminus_data = {0, 14, "real$minus", "real", 0, 0, realOPminus, 1, (const Vlist0 *)&vals_realOPminus, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPminus = (const struct dbg_info *)&dbg_info_realOPminus_data;

extern errcode realOPpower();
static const Vlist1 vals_realOPpower = {0, 1, {{0, 2, "", &real_ops, ""}}};
static const sig_desc0 sig_realOPpower_1 = {0, 2, "complex_result", {0,0}};
static const sig_desc0 sig_realOPpower_2 = {0, 2, "overflow", {0,0}};
static const sig_desc0 sig_realOPpower_3 = {0, 2, "underflow", {0,0}};
static const sig_desc0 sig_realOPpower_4 = {0, 2, "zero_divide", {0,0}};
static const siglist4 sigs_realOPpower = {0, 4, {(const sig_desc *)&sig_realOPpower_1, (const sig_desc *)&sig_realOPpower_2, (const sig_desc *)&sig_realOPpower_3, (const sig_desc *)&sig_realOPpower_4}};
const dbg_info_generic dbg_info_realOPpower_data = {0, 14, "real$power", "real", 0, 0, realOPpower, 2, (const Vlist0 *)&vals_realOPpower, (const siglist0 *)&sigs_realOPpower,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPpower = (const struct dbg_info *)&dbg_info_realOPpower_data;

extern errcode realOPabs();
static const Vlist1 vals_realOPabs = {0, 1, {{0, 2, "", &real_ops, ""}}};
const dbg_info_generic dbg_info_realOPabs_data = {0, 14, "real$abs", "real", 0, 0, realOPabs, 1, (const Vlist0 *)&vals_realOPabs, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPabs = (const struct dbg_info *)&dbg_info_realOPabs_data;

extern errcode realOPmin();
static const Vlist1 vals_realOPmin = {0, 1, {{0, 2, "", &real_ops, ""}}};
const dbg_info_generic dbg_info_realOPmin_data = {0, 14, "real$min", "real", 0, 0, realOPmin, 2, (const Vlist0 *)&vals_realOPmin, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPmin = (const struct dbg_info *)&dbg_info_realOPmin_data;

extern errcode realOPmax();
static const Vlist1 vals_realOPmax = {0, 1, {{0, 2, "", &real_ops, ""}}};
const dbg_info_generic dbg_info_realOPmax_data = {0, 14, "real$max", "real", 0, 0, realOPmax, 2, (const Vlist0 *)&vals_realOPmax, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPmax = (const struct dbg_info *)&dbg_info_realOPmax_data;

extern errcode realOPi2r();
static const Vlist1 vals_realOPi2r = {0, 1, {{0, 2, "", &real_ops, ""}}};
static const sig_desc0 sig_realOPi2r_1 = {0, 2, "overflow", {0,0}};
static const siglist1 sigs_realOPi2r = {0, 1, {(const sig_desc *)&sig_realOPi2r_1}};
const dbg_info_generic dbg_info_realOPi2r_data = {0, 14, "real$i2r", "real", 0, 0, realOPi2r, 1, (const Vlist0 *)&vals_realOPi2r, (const siglist0 *)&sigs_realOPi2r,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPi2r = (const struct dbg_info *)&dbg_info_realOPi2r_data;

extern errcode realOPr2i();
static const Vlist1 vals_realOPr2i = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_realOPr2i_1 = {0, 2, "overflow", {0,0}};
static const siglist1 sigs_realOPr2i = {0, 1, {(const sig_desc *)&sig_realOPr2i_1}};
const dbg_info_generic dbg_info_realOPr2i_data = {0, 14, "real$r2i", "real", 0, 0, realOPr2i, 1, (const Vlist0 *)&vals_realOPr2i, (const siglist0 *)&sigs_realOPr2i,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPr2i = (const struct dbg_info *)&dbg_info_realOPr2i_data;

extern errcode realOPtrunc();
static const Vlist1 vals_realOPtrunc = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_realOPtrunc_1 = {0, 2, "overflow", {0,0}};
static const siglist1 sigs_realOPtrunc = {0, 1, {(const sig_desc *)&sig_realOPtrunc_1}};
const dbg_info_generic dbg_info_realOPtrunc_data = {0, 14, "real$trunc", "real", 0, 0, realOPtrunc, 1, (const Vlist0 *)&vals_realOPtrunc, (const siglist0 *)&sigs_realOPtrunc,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPtrunc = (const struct dbg_info *)&dbg_info_realOPtrunc_data;

extern errcode realOPparse();
static const Vlist1 vals_realOPparse = {0, 1, {{0, 2, "", &real_ops, ""}}};
static const sig_desc0 sig_realOPparse_1 = {0, 2, "bad_format", {0,0}};
static const sig_desc0 sig_realOPparse_2 = {0, 2, "overflow", {0,0}};
static const sig_desc0 sig_realOPparse_3 = {0, 2, "underflow", {0,0}};
static const siglist3 sigs_realOPparse = {0, 3, {(const sig_desc *)&sig_realOPparse_1, (const sig_desc *)&sig_realOPparse_2, (const sig_desc *)&sig_realOPparse_3}};
const dbg_info_generic dbg_info_realOPparse_data = {0, 14, "real$parse", "real", 0, 0, realOPparse, 1, (const Vlist0 *)&vals_realOPparse, (const siglist0 *)&sigs_realOPparse,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPparse = (const struct dbg_info *)&dbg_info_realOPparse_data;

extern errcode realOPunparse();
static const Vlist1 vals_realOPunparse = {0, 1, {{0, 2, "", &string_ops, ""}}};
const dbg_info_generic dbg_info_realOPunparse_data = {0, 14, "real$unparse", "real", 0, 0, realOPunparse, 1, (const Vlist0 *)&vals_realOPunparse, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPunparse = (const struct dbg_info *)&dbg_info_realOPunparse_data;

extern errcode realOPexponent();
static const Vlist1 vals_realOPexponent = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_realOPexponent_1 = {0, 2, "undefined", {0,0}};
static const siglist1 sigs_realOPexponent = {0, 1, {(const sig_desc *)&sig_realOPexponent_1}};
const dbg_info_generic dbg_info_realOPexponent_data = {0, 14, "real$exponent", "real", 0, 0, realOPexponent, 1, (const Vlist0 *)&vals_realOPexponent, (const siglist0 *)&sigs_realOPexponent,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPexponent = (const struct dbg_info *)&dbg_info_realOPexponent_data;

extern errcode realOPmantissa();
static const Vlist1 vals_realOPmantissa = {0, 1, {{0, 2, "", &real_ops, ""}}};
const dbg_info_generic dbg_info_realOPmantissa_data = {0, 14, "real$mantissa", "real", 0, 0, realOPmantissa, 1, (const Vlist0 *)&vals_realOPmantissa, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPmantissa = (const struct dbg_info *)&dbg_info_realOPmantissa_data;

extern errcode realOPlt();
static const Vlist1 vals_realOPlt = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_realOPlt_data = {0, 14, "real$lt", "real", 0, 0, realOPlt, 2, (const Vlist0 *)&vals_realOPlt, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPlt = (const struct dbg_info *)&dbg_info_realOPlt_data;

extern errcode realOPle();
static const Vlist1 vals_realOPle = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_realOPle_data = {0, 14, "real$le", "real", 0, 0, realOPle, 2, (const Vlist0 *)&vals_realOPle, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPle = (const struct dbg_info *)&dbg_info_realOPle_data;

extern errcode realOPge();
static const Vlist1 vals_realOPge = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_realOPge_data = {0, 14, "real$ge", "real", 0, 0, realOPge, 2, (const Vlist0 *)&vals_realOPge, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPge = (const struct dbg_info *)&dbg_info_realOPge_data;

extern errcode realOPgt();
static const Vlist1 vals_realOPgt = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_realOPgt_data = {0, 14, "real$gt", "real", 0, 0, realOPgt, 2, (const Vlist0 *)&vals_realOPgt, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPgt = (const struct dbg_info *)&dbg_info_realOPgt_data;

extern errcode realOPequal();
static const Vlist1 vals_realOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_realOPequal_data = {0, 14, "real$equal", "real", 0, 0, realOPequal, 2, (const Vlist0 *)&vals_realOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPequal = (const struct dbg_info *)&dbg_info_realOPequal_data;

extern errcode realOPsimilar();
static const Vlist1 vals_realOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_realOPsimilar_data = {0, 14, "real$similar", "real", 0, 0, realOPsimilar, 2, (const Vlist0 *)&vals_realOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPsimilar = (const struct dbg_info *)&dbg_info_realOPsimilar_data;

extern errcode realOPcopy();
static const Vlist1 vals_realOPcopy = {0, 1, {{0, 2, "", &real_ops, ""}}};
const dbg_info_generic dbg_info_realOPcopy_data = {0, 14, "real$copy", "real", 0, 0, realOPcopy, 1, (const Vlist0 *)&vals_realOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPcopy = (const struct dbg_info *)&dbg_info_realOPcopy_data;

extern errcode realOPprint();
const dbg_info_generic dbg_info_realOPprint_data = {0, 14, "real$print", "real", 0, 0, realOPprint, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_realOPprint = (const struct dbg_info *)&dbg_info_realOPprint_data;

extern errcode i_xor();
static const Vlist1 vals_i_xor = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_i_xor_1 = {0, 2, "overflow", {0,0}};
static const siglist1 sigs_i_xor = {0, 1, {(const sig_desc *)&sig_i_xor_1}};
const dbg_info_generic dbg_info_i_xor_data = {0, 14, "i_xor", "i_xor", 0, 0, i_xor, 2, (const Vlist0 *)&vals_i_xor, (const siglist0 *)&sigs_i_xor,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_i_xor = (const struct dbg_info *)&dbg_info_i_xor_data;

extern errcode get_argv();
static const Vlist1 vals_get_argv = {0, 1, {{0, 3, "", zero_ops, "sequence_of_string_ops"}}};
const dbg_info_generic dbg_info_get_argv_data = {0, 14, "get_argv", "get_argv", 0, 0, get_argv, 0, (const Vlist0 *)&vals_get_argv, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_get_argv = (const struct dbg_info *)&dbg_info_get_argv_data;

extern errcode _get_version();
static const Vlist1 vals__get_version = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__get_version_data = {0, 14, "_get_version", "_get_version", 0, 0, _get_version, 0, (const Vlist0 *)&vals__get_version, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__get_version = (const struct dbg_info *)&dbg_info__get_version_data;

extern errcode sleep();
const dbg_info_generic dbg_info_sleep_data = {0, 14, "sleep", "sleep", 0, 0, sleep, 1, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_sleep = (const struct dbg_info *)&dbg_info_sleep_data;

extern errcode delete_directory();
static const sig_desc1 sig_delete_directory_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs_delete_directory = {0, 1, {(const sig_desc *)&sig_delete_directory_1}};
const dbg_info_generic dbg_info_delete_directory_data = {0, 14, "delete_directory", "delete_directory", 0, 0, delete_directory, 1, &NO_VALS, (const siglist0 *)&sigs_delete_directory,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_delete_directory = (const struct dbg_info *)&dbg_info_delete_directory_data;

extern errcode _file_facts();
static const Vlist2 vals__file_facts = {0, 2, {{0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__file_facts_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__file_facts = {0, 1, {(const sig_desc *)&sig__file_facts_1}};
const dbg_info_generic dbg_info__file_facts_data = {0, 14, "_file_facts", "_file_facts", 0, 0, _file_facts, 1, (const Vlist0 *)&vals__file_facts, (const siglist0 *)&sigs__file_facts,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__file_facts = (const struct dbg_info *)&dbg_info__file_facts_data;

extern errcode file_date();
extern struct OPS* date_ops;
static const Vlist1 vals_file_date = {0, 1, {{0, 2, "", &date_ops, ""}}};
static const sig_desc1 sig_file_date_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs_file_date = {0, 1, {(const sig_desc *)&sig_file_date_1}};
const dbg_info_generic dbg_info_file_date_data = {0, 14, "file_date", "file_date", 0, 0, file_date, 2, (const Vlist0 *)&vals_file_date, (const siglist0 *)&sigs_file_date,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_file_date = (const struct dbg_info *)&dbg_info_file_date_data;

const Slist1 tformals_sequence = {0, 1, {"t"}};
extern errcode sequenceOPnew();
static const Vlist1 vals_sequenceOPnew = {0, 1, {{0, 3, "", zero_ops, "sequence_of_t_ops"}}};
const dbg_info_generic dbg_info_sequenceOPnew_data = {0, 14, "sequence$new", "sequence", 0, 2, sequenceOPnew, 0, (const Vlist0 *)&vals_sequenceOPnew, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPnew = (const struct dbg_info *)&dbg_info_sequenceOPnew_data;

extern errcode sequenceOPcons();
static const Vlist1 vals_sequenceOPcons = {0, 1, {{0, 3, "", zero_ops, "sequence_of_t_ops"}}};
const dbg_info_generic dbg_info_sequenceOPcons_data = {0, 14, "sequence$cons", "sequence", 0, 2, sequenceOPcons, 1, (const Vlist0 *)&vals_sequenceOPcons, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPcons = (const struct dbg_info *)&dbg_info_sequenceOPcons_data;

extern errcode sequenceOPe2s();
static const Vlist1 vals_sequenceOPe2s = {0, 1, {{0, 3, "", zero_ops, "sequence_of_t_ops"}}};
const dbg_info_generic dbg_info_sequenceOPe2s_data = {0, 14, "sequence$e2s", "sequence", 0, 2, sequenceOPe2s, 1, (const Vlist0 *)&vals_sequenceOPe2s, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPe2s = (const struct dbg_info *)&dbg_info_sequenceOPe2s_data;

extern errcode sequenceOPsize();
static const Vlist1 vals_sequenceOPsize = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_sequenceOPsize_data = {0, 14, "sequence$size", "sequence", 0, 2, sequenceOPsize, 1, (const Vlist0 *)&vals_sequenceOPsize, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPsize = (const struct dbg_info *)&dbg_info_sequenceOPsize_data;

extern errcode sequenceOPsubseq();
static const Vlist1 vals_sequenceOPsubseq = {0, 1, {{0, 3, "", zero_ops, "sequence_of_t_ops"}}};
static const sig_desc0 sig_sequenceOPsubseq_1 = {0, 2, "bounds", {0,0}};
static const sig_desc0 sig_sequenceOPsubseq_2 = {0, 2, "negative_size", {0,0}};
static const siglist2 sigs_sequenceOPsubseq = {0, 2, {(const sig_desc *)&sig_sequenceOPsubseq_1, (const sig_desc *)&sig_sequenceOPsubseq_2}};
const dbg_info_generic dbg_info_sequenceOPsubseq_data = {0, 14, "sequence$subseq", "sequence", 0, 2, sequenceOPsubseq, 3, (const Vlist0 *)&vals_sequenceOPsubseq, (const siglist0 *)&sigs_sequenceOPsubseq,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPsubseq = (const struct dbg_info *)&dbg_info_sequenceOPsubseq_data;

extern errcode sequenceOPfill();
static const Vlist1 vals_sequenceOPfill = {0, 1, {{0, 3, "", zero_ops, "sequence_of_t_ops"}}};
static const sig_desc0 sig_sequenceOPfill_1 = {0, 2, "negative_size", {0,0}};
static const siglist1 sigs_sequenceOPfill = {0, 1, {(const sig_desc *)&sig_sequenceOPfill_1}};
const dbg_info_generic dbg_info_sequenceOPfill_data = {0, 14, "sequence$fill", "sequence", 0, 2, sequenceOPfill, 2, (const Vlist0 *)&vals_sequenceOPfill, (const siglist0 *)&sigs_sequenceOPfill,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPfill = (const struct dbg_info *)&dbg_info_sequenceOPfill_data;

extern errcode sequenceOPfill_copy();
static const Vlist1 vals_sequenceOPfill_copy = {0, 1, {{0, 3, "", zero_ops, "sequence_of_t_ops"}}};
static const sig_desc0 sig_sequenceOPfill_copy_1 = {0, 2, "negative_size", {0,0}};
static const siglist1 sigs_sequenceOPfill_copy = {0, 1, {(const sig_desc *)&sig_sequenceOPfill_copy_1}};
const dbg_info_generic dbg_info_sequenceOPfill_copy_data = {0, 14, "sequence$fill_copy", "sequence", 0, 2, sequenceOPfill_copy, 2, (const Vlist0 *)&vals_sequenceOPfill_copy, (const siglist0 *)&sigs_sequenceOPfill_copy,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPfill_copy = (const struct dbg_info *)&dbg_info_sequenceOPfill_copy_data;

extern errcode sequenceOPfetch();
static const Vlist1 vals_sequenceOPfetch = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_sequenceOPfetch_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_sequenceOPfetch = {0, 1, {(const sig_desc *)&sig_sequenceOPfetch_1}};
const dbg_info_generic dbg_info_sequenceOPfetch_data = {0, 14, "sequence$fetch", "sequence", 0, 2, sequenceOPfetch, 2, (const Vlist0 *)&vals_sequenceOPfetch, (const siglist0 *)&sigs_sequenceOPfetch,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPfetch = (const struct dbg_info *)&dbg_info_sequenceOPfetch_data;

extern errcode sequenceOPbottom();
static const Vlist1 vals_sequenceOPbottom = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_sequenceOPbottom_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_sequenceOPbottom = {0, 1, {(const sig_desc *)&sig_sequenceOPbottom_1}};
const dbg_info_generic dbg_info_sequenceOPbottom_data = {0, 14, "sequence$bottom", "sequence", 0, 2, sequenceOPbottom, 1, (const Vlist0 *)&vals_sequenceOPbottom, (const siglist0 *)&sigs_sequenceOPbottom,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPbottom = (const struct dbg_info *)&dbg_info_sequenceOPbottom_data;

extern errcode sequenceOPtop();
static const Vlist1 vals_sequenceOPtop = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_sequenceOPtop_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_sequenceOPtop = {0, 1, {(const sig_desc *)&sig_sequenceOPtop_1}};
const dbg_info_generic dbg_info_sequenceOPtop_data = {0, 14, "sequence$top", "sequence", 0, 2, sequenceOPtop, 1, (const Vlist0 *)&vals_sequenceOPtop, (const siglist0 *)&sigs_sequenceOPtop,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPtop = (const struct dbg_info *)&dbg_info_sequenceOPtop_data;

extern errcode sequenceOPreplace();
static const Vlist1 vals_sequenceOPreplace = {0, 1, {{0, 3, "", zero_ops, "sequence_of_t_ops"}}};
static const sig_desc0 sig_sequenceOPreplace_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_sequenceOPreplace = {0, 1, {(const sig_desc *)&sig_sequenceOPreplace_1}};
const dbg_info_generic dbg_info_sequenceOPreplace_data = {0, 14, "sequence$replace", "sequence", 0, 2, sequenceOPreplace, 3, (const Vlist0 *)&vals_sequenceOPreplace, (const siglist0 *)&sigs_sequenceOPreplace,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPreplace = (const struct dbg_info *)&dbg_info_sequenceOPreplace_data;

extern errcode sequenceOPaddh();
static const Vlist1 vals_sequenceOPaddh = {0, 1, {{0, 3, "", zero_ops, "sequence_of_t_ops"}}};
const dbg_info_generic dbg_info_sequenceOPaddh_data = {0, 14, "sequence$addh", "sequence", 0, 2, sequenceOPaddh, 2, (const Vlist0 *)&vals_sequenceOPaddh, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPaddh = (const struct dbg_info *)&dbg_info_sequenceOPaddh_data;

extern errcode sequenceOPaddl();
static const Vlist1 vals_sequenceOPaddl = {0, 1, {{0, 3, "", zero_ops, "sequence_of_t_ops"}}};
const dbg_info_generic dbg_info_sequenceOPaddl_data = {0, 14, "sequence$addl", "sequence", 0, 2, sequenceOPaddl, 2, (const Vlist0 *)&vals_sequenceOPaddl, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPaddl = (const struct dbg_info *)&dbg_info_sequenceOPaddl_data;

extern errcode sequenceOPremh();
static const Vlist1 vals_sequenceOPremh = {0, 1, {{0, 3, "", zero_ops, "sequence_of_t_ops"}}};
static const sig_desc0 sig_sequenceOPremh_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_sequenceOPremh = {0, 1, {(const sig_desc *)&sig_sequenceOPremh_1}};
const dbg_info_generic dbg_info_sequenceOPremh_data = {0, 14, "sequence$remh", "sequence", 0, 2, sequenceOPremh, 1, (const Vlist0 *)&vals_sequenceOPremh, (const siglist0 *)&sigs_sequenceOPremh,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPremh = (const struct dbg_info *)&dbg_info_sequenceOPremh_data;

extern errcode sequenceOPreml();
static const Vlist1 vals_sequenceOPreml = {0, 1, {{0, 3, "", zero_ops, "sequence_of_t_ops"}}};
static const sig_desc0 sig_sequenceOPreml_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_sequenceOPreml = {0, 1, {(const sig_desc *)&sig_sequenceOPreml_1}};
const dbg_info_generic dbg_info_sequenceOPreml_data = {0, 14, "sequence$reml", "sequence", 0, 2, sequenceOPreml, 1, (const Vlist0 *)&vals_sequenceOPreml, (const siglist0 *)&sigs_sequenceOPreml,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPreml = (const struct dbg_info *)&dbg_info_sequenceOPreml_data;

extern errcode sequenceOPconcat();
static const Vlist1 vals_sequenceOPconcat = {0, 1, {{0, 3, "", zero_ops, "sequence_of_t_ops"}}};
const dbg_info_generic dbg_info_sequenceOPconcat_data = {0, 14, "sequence$concat", "sequence", 0, 2, sequenceOPconcat, 2, (const Vlist0 *)&vals_sequenceOPconcat, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPconcat = (const struct dbg_info *)&dbg_info_sequenceOPconcat_data;

extern errcode sequenceOPa2s();
static const Vlist1 vals_sequenceOPa2s = {0, 1, {{0, 3, "", zero_ops, "sequence_of_t_ops"}}};
const dbg_info_generic dbg_info_sequenceOPa2s_data = {0, 14, "sequence$a2s", "sequence", 0, 2, sequenceOPa2s, 1, (const Vlist0 *)&vals_sequenceOPa2s, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPa2s = (const struct dbg_info *)&dbg_info_sequenceOPa2s_data;

extern errcode sequenceOPs2a();
static const Vlist1 vals_sequenceOPs2a = {0, 1, {{0, 3, "", zero_ops, "array_of_t_ops"}}};
const dbg_info_generic dbg_info_sequenceOPs2a_data = {0, 14, "sequence$s2a", "sequence", 0, 2, sequenceOPs2a, 1, (const Vlist0 *)&vals_sequenceOPs2a, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPs2a = (const struct dbg_info *)&dbg_info_sequenceOPs2a_data;

extern errcode sequenceOPempty();
static const Vlist1 vals_sequenceOPempty = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_sequenceOPempty_data = {0, 14, "sequence$empty", "sequence", 0, 2, sequenceOPempty, 1, (const Vlist0 *)&vals_sequenceOPempty, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPempty = (const struct dbg_info *)&dbg_info_sequenceOPempty_data;

extern errcode sequenceOPelements();
static const Vlist1 vals_sequenceOPelements = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_sequenceOPelements_data = {0, 14, "sequence$elements", "sequence", 1, 2, sequenceOPelements, 1, (const Vlist0 *)&vals_sequenceOPelements, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPelements = (const struct dbg_info *)&dbg_info_sequenceOPelements_data;

extern errcode sequenceOPindexes();
static const Vlist1 vals_sequenceOPindexes = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_sequenceOPindexes_data = {0, 14, "sequence$indexes", "sequence", 1, 2, sequenceOPindexes, 1, (const Vlist0 *)&vals_sequenceOPindexes, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPindexes = (const struct dbg_info *)&dbg_info_sequenceOPindexes_data;

extern errcode sequenceOPequal();
static const Vlist1 vals_sequenceOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_sequenceOPequal_data = {0, 14, "sequence$equal", "sequence", 0, 2, sequenceOPequal, 2, (const Vlist0 *)&vals_sequenceOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPequal = (const struct dbg_info *)&dbg_info_sequenceOPequal_data;

extern errcode sequenceOPsimilar();
static const Vlist1 vals_sequenceOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_sequenceOPsimilar_data = {0, 14, "sequence$similar", "sequence", 0, 2, sequenceOPsimilar, 2, (const Vlist0 *)&vals_sequenceOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPsimilar = (const struct dbg_info *)&dbg_info_sequenceOPsimilar_data;

extern errcode sequenceOPcopy();
static const Vlist1 vals_sequenceOPcopy = {0, 1, {{0, 3, "", zero_ops, "sequence_of_t_ops"}}};
const dbg_info_generic dbg_info_sequenceOPcopy_data = {0, 14, "sequence$copy", "sequence", 0, 2, sequenceOPcopy, 1, (const Vlist0 *)&vals_sequenceOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPcopy = (const struct dbg_info *)&dbg_info_sequenceOPcopy_data;

extern errcode sequenceOPprint();
const dbg_info_generic dbg_info_sequenceOPprint_data = {0, 14, "sequence$print", "sequence", 0, 2, sequenceOPprint, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_sequence,&NO_PARMS};
const struct dbg_info * const dbg_info_sequenceOPprint = (const struct dbg_info *)&dbg_info_sequenceOPprint_data;

extern errcode _environs();
static const Vlist1 vals__environs = {0, 1, {{0, 2, "", &string_ops, ""}}};
const dbg_info_generic dbg_info__environs_data = {0, 14, "_environs", "_environs", 1, 0, _environs, 0, (const Vlist0 *)&vals__environs, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__environs = (const struct dbg_info *)&dbg_info__environs_data;

extern errcode boolOPand();
static const Vlist1 vals_boolOPand = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_boolOPand_data = {0, 14, "bool$and", "bool", 0, 0, boolOPand, 2, (const Vlist0 *)&vals_boolOPand, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_boolOPand = (const struct dbg_info *)&dbg_info_boolOPand_data;

extern errcode boolOPor();
static const Vlist1 vals_boolOPor = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_boolOPor_data = {0, 14, "bool$or", "bool", 0, 0, boolOPor, 2, (const Vlist0 *)&vals_boolOPor, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_boolOPor = (const struct dbg_info *)&dbg_info_boolOPor_data;

extern errcode boolOPnot();
static const Vlist1 vals_boolOPnot = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_boolOPnot_data = {0, 14, "bool$not", "bool", 0, 0, boolOPnot, 1, (const Vlist0 *)&vals_boolOPnot, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_boolOPnot = (const struct dbg_info *)&dbg_info_boolOPnot_data;

extern errcode boolOPequal();
static const Vlist1 vals_boolOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_boolOPequal_data = {0, 14, "bool$equal", "bool", 0, 0, boolOPequal, 2, (const Vlist0 *)&vals_boolOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_boolOPequal = (const struct dbg_info *)&dbg_info_boolOPequal_data;

extern errcode boolOPsimilar();
static const Vlist1 vals_boolOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_boolOPsimilar_data = {0, 14, "bool$similar", "bool", 0, 0, boolOPsimilar, 2, (const Vlist0 *)&vals_boolOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_boolOPsimilar = (const struct dbg_info *)&dbg_info_boolOPsimilar_data;

extern errcode boolOPcopy();
static const Vlist1 vals_boolOPcopy = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_boolOPcopy_data = {0, 14, "bool$copy", "bool", 0, 0, boolOPcopy, 1, (const Vlist0 *)&vals_boolOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_boolOPcopy = (const struct dbg_info *)&dbg_info_boolOPcopy_data;

extern errcode boolOPprint();
const dbg_info_generic dbg_info_boolOPprint_data = {0, 14, "bool$print", "bool", 0, 0, boolOPprint, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_boolOPprint = (const struct dbg_info *)&dbg_info_boolOPprint_data;

extern errcode _file_access();
static const Vlist1 vals__file_access = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info__file_access_data = {0, 14, "_file_access", "_file_access", 0, 0, _file_access, 2, (const Vlist0 *)&vals__file_access, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__file_access = (const struct dbg_info *)&dbg_info__file_access_data;

extern errcode _real_time();
static const Vlist1 vals__real_time = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__real_time_data = {0, 14, "_real_time", "_real_time", 0, 0, _real_time, 0, (const Vlist0 *)&vals__real_time, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__real_time = (const struct dbg_info *)&dbg_info__real_time_data;

extern errcode i_get();
static const Vlist1 vals_i_get = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_i_get_1 = {0, 2, "bounds", {0,0}};
static const sig_desc0 sig_i_get_2 = {0, 2, "illegal_size", {0,0}};
static const sig_desc0 sig_i_get_3 = {0, 2, "overflow", {0,0}};
static const siglist3 sigs_i_get = {0, 3, {(const sig_desc *)&sig_i_get_1, (const sig_desc *)&sig_i_get_2, (const sig_desc *)&sig_i_get_3}};
const dbg_info_generic dbg_info_i_get_data = {0, 14, "i_get", "i_get", 0, 0, i_get, 3, (const Vlist0 *)&vals_i_get, (const siglist0 *)&sigs_i_get,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_i_get = (const struct dbg_info *)&dbg_info_i_get_data;

extern errcode connected_dir();
static const Vlist1 vals_connected_dir = {0, 1, {{0, 2, "", &string_ops, ""}}};
const dbg_info_generic dbg_info_connected_dir_data = {0, 14, "connected_dir", "connected_dir", 0, 0, connected_dir, 0, (const Vlist0 *)&vals_connected_dir, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_connected_dir = (const struct dbg_info *)&dbg_info_connected_dir_data;

extern errcode _signalOPset();
static const sig_desc0 sig__signalOPset_1 = {0, 2, "bad_code", {0,0}};
static const siglist1 sigs__signalOPset = {0, 1, {(const sig_desc *)&sig__signalOPset_1}};
const dbg_info_generic dbg_info__signalOPset_data = {0, 14, "_signal$set", "_signal", 0, 0, _signalOPset, 2, &NO_VALS, (const siglist0 *)&sigs__signalOPset,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__signalOPset = (const struct dbg_info *)&dbg_info__signalOPset_data;

extern errcode _signalOPunset();
static const sig_desc0 sig__signalOPunset_1 = {0, 2, "bad_code", {0,0}};
static const siglist1 sigs__signalOPunset = {0, 1, {(const sig_desc *)&sig__signalOPunset_1}};
const dbg_info_generic dbg_info__signalOPunset_data = {0, 14, "_signal$unset", "_signal", 0, 0, _signalOPunset, 1, &NO_VALS, (const siglist0 *)&sigs__signalOPunset,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__signalOPunset = (const struct dbg_info *)&dbg_info__signalOPunset_data;

extern errcode _signalOPget();
static const Vlist1 vals__signalOPget = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig__signalOPget_1 = {0, 2, "bad_code", {0,0}};
static const siglist1 sigs__signalOPget = {0, 1, {(const sig_desc *)&sig__signalOPget_1}};
const dbg_info_generic dbg_info__signalOPget_data = {0, 14, "_signal$get", "_signal", 0, 0, _signalOPget, 1, (const Vlist0 *)&vals__signalOPget, (const siglist0 *)&sigs__signalOPget,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__signalOPget = (const struct dbg_info *)&dbg_info__signalOPget_data;

extern errcode _signalOPset_message();
static const sig_desc0 sig__signalOPset_message_1 = {0, 2, "bad_code", {0,0}};
static const siglist1 sigs__signalOPset_message = {0, 1, {(const sig_desc *)&sig__signalOPset_message_1}};
const dbg_info_generic dbg_info__signalOPset_message_data = {0, 14, "_signal$set_message", "_signal", 0, 0, _signalOPset_message, 2, &NO_VALS, (const siglist0 *)&sigs__signalOPset_message,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__signalOPset_message = (const struct dbg_info *)&dbg_info__signalOPset_message_data;

extern errcode _signalOPget_message();
static const Vlist1 vals__signalOPget_message = {0, 1, {{0, 2, "", &string_ops, ""}}};
static const sig_desc0 sig__signalOPget_message_1 = {0, 2, "bad_code", {0,0}};
static const siglist1 sigs__signalOPget_message = {0, 1, {(const sig_desc *)&sig__signalOPget_message_1}};
const dbg_info_generic dbg_info__signalOPget_message_data = {0, 14, "_signal$get_message", "_signal", 0, 0, _signalOPget_message, 1, (const Vlist0 *)&vals__signalOPget_message, (const siglist0 *)&sigs__signalOPget_message,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__signalOPget_message = (const struct dbg_info *)&dbg_info__signalOPget_message_data;

extern errcode intOPadd();
static const Vlist1 vals_intOPadd = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_intOPadd_1 = {0, 2, "overflow", {0,0}};
static const siglist1 sigs_intOPadd = {0, 1, {(const sig_desc *)&sig_intOPadd_1}};
const dbg_info_generic dbg_info_intOPadd_data = {0, 14, "int$add", "int", 0, 0, intOPadd, 2, (const Vlist0 *)&vals_intOPadd, (const siglist0 *)&sigs_intOPadd,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPadd = (const struct dbg_info *)&dbg_info_intOPadd_data;

extern errcode intOPsub();
static const Vlist1 vals_intOPsub = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_intOPsub_1 = {0, 2, "overflow", {0,0}};
static const siglist1 sigs_intOPsub = {0, 1, {(const sig_desc *)&sig_intOPsub_1}};
const dbg_info_generic dbg_info_intOPsub_data = {0, 14, "int$sub", "int", 0, 0, intOPsub, 2, (const Vlist0 *)&vals_intOPsub, (const siglist0 *)&sigs_intOPsub,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPsub = (const struct dbg_info *)&dbg_info_intOPsub_data;

extern errcode intOPmul();
static const Vlist1 vals_intOPmul = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_intOPmul_1 = {0, 2, "overflow", {0,0}};
static const siglist1 sigs_intOPmul = {0, 1, {(const sig_desc *)&sig_intOPmul_1}};
const dbg_info_generic dbg_info_intOPmul_data = {0, 14, "int$mul", "int", 0, 0, intOPmul, 2, (const Vlist0 *)&vals_intOPmul, (const siglist0 *)&sigs_intOPmul,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPmul = (const struct dbg_info *)&dbg_info_intOPmul_data;

extern errcode intOPminus();
static const Vlist1 vals_intOPminus = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_intOPminus_1 = {0, 2, "overflow", {0,0}};
static const siglist1 sigs_intOPminus = {0, 1, {(const sig_desc *)&sig_intOPminus_1}};
const dbg_info_generic dbg_info_intOPminus_data = {0, 14, "int$minus", "int", 0, 0, intOPminus, 1, (const Vlist0 *)&vals_intOPminus, (const siglist0 *)&sigs_intOPminus,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPminus = (const struct dbg_info *)&dbg_info_intOPminus_data;

extern errcode intOPdiv();
static const Vlist1 vals_intOPdiv = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_intOPdiv_1 = {0, 2, "overflow", {0,0}};
static const sig_desc0 sig_intOPdiv_2 = {0, 2, "zero_divide", {0,0}};
static const siglist2 sigs_intOPdiv = {0, 2, {(const sig_desc *)&sig_intOPdiv_1, (const sig_desc *)&sig_intOPdiv_2}};
const dbg_info_generic dbg_info_intOPdiv_data = {0, 14, "int$div", "int", 0, 0, intOPdiv, 2, (const Vlist0 *)&vals_intOPdiv, (const siglist0 *)&sigs_intOPdiv,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPdiv = (const struct dbg_info *)&dbg_info_intOPdiv_data;

extern errcode intOPpower();
static const Vlist1 vals_intOPpower = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_intOPpower_1 = {0, 2, "negative_exponent", {0,0}};
static const sig_desc0 sig_intOPpower_2 = {0, 2, "overflow", {0,0}};
static const siglist2 sigs_intOPpower = {0, 2, {(const sig_desc *)&sig_intOPpower_1, (const sig_desc *)&sig_intOPpower_2}};
const dbg_info_generic dbg_info_intOPpower_data = {0, 14, "int$power", "int", 0, 0, intOPpower, 2, (const Vlist0 *)&vals_intOPpower, (const siglist0 *)&sigs_intOPpower,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPpower = (const struct dbg_info *)&dbg_info_intOPpower_data;

extern errcode intOPmod();
static const Vlist1 vals_intOPmod = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_intOPmod_1 = {0, 2, "overflow", {0,0}};
static const sig_desc0 sig_intOPmod_2 = {0, 2, "zero_divide", {0,0}};
static const siglist2 sigs_intOPmod = {0, 2, {(const sig_desc *)&sig_intOPmod_1, (const sig_desc *)&sig_intOPmod_2}};
const dbg_info_generic dbg_info_intOPmod_data = {0, 14, "int$mod", "int", 0, 0, intOPmod, 2, (const Vlist0 *)&vals_intOPmod, (const siglist0 *)&sigs_intOPmod,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPmod = (const struct dbg_info *)&dbg_info_intOPmod_data;

extern errcode intOPabs();
static const Vlist1 vals_intOPabs = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_intOPabs_1 = {0, 2, "overflow", {0,0}};
static const siglist1 sigs_intOPabs = {0, 1, {(const sig_desc *)&sig_intOPabs_1}};
const dbg_info_generic dbg_info_intOPabs_data = {0, 14, "int$abs", "int", 0, 0, intOPabs, 1, (const Vlist0 *)&vals_intOPabs, (const siglist0 *)&sigs_intOPabs,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPabs = (const struct dbg_info *)&dbg_info_intOPabs_data;

extern errcode intOPmin();
static const Vlist1 vals_intOPmin = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_intOPmin_data = {0, 14, "int$min", "int", 0, 0, intOPmin, 2, (const Vlist0 *)&vals_intOPmin, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPmin = (const struct dbg_info *)&dbg_info_intOPmin_data;

extern errcode intOPmax();
static const Vlist1 vals_intOPmax = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_intOPmax_data = {0, 14, "int$max", "int", 0, 0, intOPmax, 2, (const Vlist0 *)&vals_intOPmax, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPmax = (const struct dbg_info *)&dbg_info_intOPmax_data;

extern errcode intOPfrom_to_by();
static const Vlist1 vals_intOPfrom_to_by = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_intOPfrom_to_by_data = {0, 14, "int$from_to_by", "int", 1, 0, intOPfrom_to_by, 3, (const Vlist0 *)&vals_intOPfrom_to_by, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPfrom_to_by = (const struct dbg_info *)&dbg_info_intOPfrom_to_by_data;

extern errcode intOPfrom_to();
static const Vlist1 vals_intOPfrom_to = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_intOPfrom_to_data = {0, 14, "int$from_to", "int", 1, 0, intOPfrom_to, 2, (const Vlist0 *)&vals_intOPfrom_to, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPfrom_to = (const struct dbg_info *)&dbg_info_intOPfrom_to_data;

extern errcode intOPparse();
static const Vlist1 vals_intOPparse = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_intOPparse_1 = {0, 2, "bad_format", {0,0}};
static const sig_desc0 sig_intOPparse_2 = {0, 2, "overflow", {0,0}};
static const siglist2 sigs_intOPparse = {0, 2, {(const sig_desc *)&sig_intOPparse_1, (const sig_desc *)&sig_intOPparse_2}};
const dbg_info_generic dbg_info_intOPparse_data = {0, 14, "int$parse", "int", 0, 0, intOPparse, 1, (const Vlist0 *)&vals_intOPparse, (const siglist0 *)&sigs_intOPparse,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPparse = (const struct dbg_info *)&dbg_info_intOPparse_data;

extern errcode intOPunparse();
static const Vlist1 vals_intOPunparse = {0, 1, {{0, 2, "", &string_ops, ""}}};
const dbg_info_generic dbg_info_intOPunparse_data = {0, 14, "int$unparse", "int", 0, 0, intOPunparse, 1, (const Vlist0 *)&vals_intOPunparse, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPunparse = (const struct dbg_info *)&dbg_info_intOPunparse_data;

extern errcode intOPlt();
static const Vlist1 vals_intOPlt = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_intOPlt_data = {0, 14, "int$lt", "int", 0, 0, intOPlt, 2, (const Vlist0 *)&vals_intOPlt, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPlt = (const struct dbg_info *)&dbg_info_intOPlt_data;

extern errcode intOPle();
static const Vlist1 vals_intOPle = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_intOPle_data = {0, 14, "int$le", "int", 0, 0, intOPle, 2, (const Vlist0 *)&vals_intOPle, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPle = (const struct dbg_info *)&dbg_info_intOPle_data;

extern errcode intOPge();
static const Vlist1 vals_intOPge = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_intOPge_data = {0, 14, "int$ge", "int", 0, 0, intOPge, 2, (const Vlist0 *)&vals_intOPge, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPge = (const struct dbg_info *)&dbg_info_intOPge_data;

extern errcode intOPgt();
static const Vlist1 vals_intOPgt = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_intOPgt_data = {0, 14, "int$gt", "int", 0, 0, intOPgt, 2, (const Vlist0 *)&vals_intOPgt, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPgt = (const struct dbg_info *)&dbg_info_intOPgt_data;

extern errcode intOPequal();
static const Vlist1 vals_intOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_intOPequal_data = {0, 14, "int$equal", "int", 0, 0, intOPequal, 2, (const Vlist0 *)&vals_intOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPequal = (const struct dbg_info *)&dbg_info_intOPequal_data;

extern errcode intOPsimilar();
static const Vlist1 vals_intOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_intOPsimilar_data = {0, 14, "int$similar", "int", 0, 0, intOPsimilar, 2, (const Vlist0 *)&vals_intOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPsimilar = (const struct dbg_info *)&dbg_info_intOPsimilar_data;

extern errcode intOPcopy();
static const Vlist1 vals_intOPcopy = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_intOPcopy_data = {0, 14, "int$copy", "int", 0, 0, intOPcopy, 1, (const Vlist0 *)&vals_intOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPcopy = (const struct dbg_info *)&dbg_info_intOPcopy_data;

extern errcode intOPprint();
const dbg_info_generic dbg_info_intOPprint_data = {0, 14, "int$print", "int", 0, 0, intOPprint, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_intOPprint = (const struct dbg_info *)&dbg_info_intOPprint_data;

extern errcode sqrt();
static const Vlist1 vals_sqrt = {0, 1, {{0, 2, "", &real_ops, ""}}};
static const sig_desc0 sig_sqrt_1 = {0, 2, "complex_result", {0,0}};
static const siglist1 sigs_sqrt = {0, 1, {(const sig_desc *)&sig_sqrt_1}};
const dbg_info_generic dbg_info_sqrt_data = {0, 14, "sqrt", "sqrt", 0, 0, sqrt, 1, (const Vlist0 *)&vals_sqrt, (const siglist0 *)&sigs_sqrt,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_sqrt = (const struct dbg_info *)&dbg_info_sqrt_data;

extern errcode nullOPequal();
static const Vlist1 vals_nullOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_nullOPequal_data = {0, 14, "null$equal", "null", 0, 0, nullOPequal, 2, (const Vlist0 *)&vals_nullOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_nullOPequal = (const struct dbg_info *)&dbg_info_nullOPequal_data;

extern errcode nullOPsimilar();
static const Vlist1 vals_nullOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_nullOPsimilar_data = {0, 14, "null$similar", "null", 0, 0, nullOPsimilar, 2, (const Vlist0 *)&vals_nullOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_nullOPsimilar = (const struct dbg_info *)&dbg_info_nullOPsimilar_data;

extern errcode nullOPcopy();
extern struct OPS* null_ops;
static const Vlist1 vals_nullOPcopy = {0, 1, {{0, 2, "", &null_ops, ""}}};
const dbg_info_generic dbg_info_nullOPcopy_data = {0, 14, "null$copy", "null", 0, 0, nullOPcopy, 1, (const Vlist0 *)&vals_nullOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_nullOPcopy = (const struct dbg_info *)&dbg_info_nullOPcopy_data;

extern errcode nullOPprint();
const dbg_info_generic dbg_info_nullOPprint_data = {0, 14, "null$print", "null", 0, 0, nullOPprint, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_nullOPprint = (const struct dbg_info *)&dbg_info_nullOPprint_data;

extern errcode charOPi2c();
extern struct OPS* char_ops;
static const Vlist1 vals_charOPi2c = {0, 1, {{0, 2, "", &char_ops, ""}}};
static const sig_desc0 sig_charOPi2c_1 = {0, 2, "illegal_char", {0,0}};
static const siglist1 sigs_charOPi2c = {0, 1, {(const sig_desc *)&sig_charOPi2c_1}};
const dbg_info_generic dbg_info_charOPi2c_data = {0, 14, "char$i2c", "char", 0, 0, charOPi2c, 1, (const Vlist0 *)&vals_charOPi2c, (const siglist0 *)&sigs_charOPi2c,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_charOPi2c = (const struct dbg_info *)&dbg_info_charOPi2c_data;

extern errcode charOPc2i();
static const Vlist1 vals_charOPc2i = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_charOPc2i_data = {0, 14, "char$c2i", "char", 0, 0, charOPc2i, 1, (const Vlist0 *)&vals_charOPc2i, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_charOPc2i = (const struct dbg_info *)&dbg_info_charOPc2i_data;

extern errcode charOPlt();
static const Vlist1 vals_charOPlt = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_charOPlt_data = {0, 14, "char$lt", "char", 0, 0, charOPlt, 2, (const Vlist0 *)&vals_charOPlt, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_charOPlt = (const struct dbg_info *)&dbg_info_charOPlt_data;

extern errcode charOPle();
static const Vlist1 vals_charOPle = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_charOPle_data = {0, 14, "char$le", "char", 0, 0, charOPle, 2, (const Vlist0 *)&vals_charOPle, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_charOPle = (const struct dbg_info *)&dbg_info_charOPle_data;

extern errcode charOPge();
static const Vlist1 vals_charOPge = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_charOPge_data = {0, 14, "char$ge", "char", 0, 0, charOPge, 2, (const Vlist0 *)&vals_charOPge, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_charOPge = (const struct dbg_info *)&dbg_info_charOPge_data;

extern errcode charOPgt();
static const Vlist1 vals_charOPgt = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_charOPgt_data = {0, 14, "char$gt", "char", 0, 0, charOPgt, 2, (const Vlist0 *)&vals_charOPgt, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_charOPgt = (const struct dbg_info *)&dbg_info_charOPgt_data;

extern errcode charOPequal();
static const Vlist1 vals_charOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_charOPequal_data = {0, 14, "char$equal", "char", 0, 0, charOPequal, 2, (const Vlist0 *)&vals_charOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_charOPequal = (const struct dbg_info *)&dbg_info_charOPequal_data;

extern errcode charOPsimilar();
static const Vlist1 vals_charOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_charOPsimilar_data = {0, 14, "char$similar", "char", 0, 0, charOPsimilar, 2, (const Vlist0 *)&vals_charOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_charOPsimilar = (const struct dbg_info *)&dbg_info_charOPsimilar_data;

extern errcode charOPcopy();
extern struct OPS* char_ops;
static const Vlist1 vals_charOPcopy = {0, 1, {{0, 2, "", &char_ops, ""}}};
const dbg_info_generic dbg_info_charOPcopy_data = {0, 14, "char$copy", "char", 0, 0, charOPcopy, 1, (const Vlist0 *)&vals_charOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_charOPcopy = (const struct dbg_info *)&dbg_info_charOPcopy_data;

extern errcode charOPprint();
const dbg_info_generic dbg_info_charOPprint_data = {0, 14, "char$print", "char", 0, 0, charOPprint, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_charOPprint = (const struct dbg_info *)&dbg_info_charOPprint_data;

extern errcode i_and();
static const Vlist1 vals_i_and = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_i_and_1 = {0, 2, "overflow", {0,0}};
static const siglist1 sigs_i_and = {0, 1, {(const sig_desc *)&sig_i_and_1}};
const dbg_info_generic dbg_info_i_and_data = {0, 14, "i_and", "i_and", 0, 0, i_and, 2, (const Vlist0 *)&vals_i_and, (const siglist0 *)&sigs_i_and,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_i_and = (const struct dbg_info *)&dbg_info_i_and_data;

extern errcode _get_xjname();
static const Vlist1 vals__get_xjname = {0, 1, {{0, 2, "", &string_ops, ""}}};
const dbg_info_generic dbg_info__get_xjname_data = {0, 14, "_get_xjname", "_get_xjname", 0, 0, _get_xjname, 0, (const Vlist0 *)&vals__get_xjname, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__get_xjname = (const struct dbg_info *)&dbg_info__get_xjname_data;

extern errcode _get_priority();
static const Vlist1 vals__get_priority = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__get_priority_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__get_priority = {0, 1, {(const sig_desc *)&sig__get_priority_1}};
const dbg_info_generic dbg_info__get_priority_data = {0, 14, "_get_priority", "_get_priority", 0, 0, _get_priority, 2, (const Vlist0 *)&vals__get_priority, (const siglist0 *)&sigs__get_priority,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__get_priority = (const struct dbg_info *)&dbg_info__get_priority_data;

extern errcode _file_exists();
static const Vlist1 vals__file_exists = {0, 1, {{0, 2, "", &bool_ops, ""}}};
static const sig_desc1 sig__file_exists_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__file_exists = {0, 1, {(const sig_desc *)&sig__file_exists_1}};
const dbg_info_generic dbg_info__file_exists_data = {0, 14, "_file_exists", "_file_exists", 0, 0, _file_exists, 2, (const Vlist0 *)&vals__file_exists, (const siglist0 *)&sigs__file_exists,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__file_exists = (const struct dbg_info *)&dbg_info__file_exists_data;

extern errcode _local_time();
extern struct OPS* date_ops;
static const Vlist1 vals__local_time = {0, 1, {{0, 2, "", &date_ops, ""}}};
const dbg_info_generic dbg_info__local_time_data = {0, 14, "_local_time", "_local_time", 0, 0, _local_time, 2, (const Vlist0 *)&vals__local_time, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__local_time = (const struct dbg_info *)&dbg_info__local_time_data;

extern errcode i_or();
static const Vlist1 vals_i_or = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_i_or_1 = {0, 2, "overflow", {0,0}};
static const siglist1 sigs_i_or = {0, 1, {(const sig_desc *)&sig_i_or_1}};
const dbg_info_generic dbg_info_i_or_data = {0, 14, "i_or", "i_or", 0, 0, i_or, 2, (const Vlist0 *)&vals_i_or, (const siglist0 *)&sigs_i_or,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_i_or = (const struct dbg_info *)&dbg_info_i_or_data;

extern errcode hash_int();
static const Vlist1 vals_hash_int = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_hash_int_data = {0, 14, "hash_int", "hash_int", 0, 0, hash_int, 2, (const Vlist0 *)&vals_hash_int, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_hash_int = (const struct dbg_info *)&dbg_info_hash_int_data;

extern errcode _change_mode();
static const sig_desc1 sig__change_mode_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__change_mode = {0, 1, {(const sig_desc *)&sig__change_mode_1}};
const dbg_info_generic dbg_info__change_mode_data = {0, 14, "_change_mode", "_change_mode", 0, 0, _change_mode, 2, &NO_VALS, (const siglist0 *)&sigs__change_mode,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__change_mode = (const struct dbg_info *)&dbg_info__change_mode_data;

extern errcode _set_priority();
static const Vlist1 vals__set_priority = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__set_priority_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__set_priority = {0, 1, {(const sig_desc *)&sig__set_priority_1}};
const dbg_info_generic dbg_info__set_priority_data = {0, 14, "_set_priority", "_set_priority", 0, 0, _set_priority, 2, (const Vlist0 *)&vals__set_priority, (const siglist0 *)&sigs__set_priority,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__set_priority = (const struct dbg_info *)&dbg_info__set_priority_data;

extern errcode quit_();
const dbg_info_generic dbg_info_quit__data = {0, 14, "quit_", "quit_", 0, 0, quit_, 0, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_quit_ = (const struct dbg_info *)&dbg_info_quit__data;

extern errcode _umask();
static const Vlist1 vals__umask = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__umask_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__umask = {0, 1, {(const sig_desc *)&sig__umask_1}};
const dbg_info_generic dbg_info__umask_data = {0, 14, "_umask", "_umask", 0, 0, _umask, 1, (const Vlist0 *)&vals__umask, (const siglist0 *)&sigs__umask,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__umask = (const struct dbg_info *)&dbg_info__umask_data;

extern errcode link_file();
static const sig_desc1 sig_link_file_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs_link_file = {0, 1, {(const sig_desc *)&sig_link_file_1}};
const dbg_info_generic dbg_info_link_file_data = {0, 14, "link_file", "link_file", 0, 0, link_file, 2, &NO_VALS, (const siglist0 *)&sigs_link_file,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_link_file = (const struct dbg_info *)&dbg_info_link_file_data;

extern errcode file_exists();
static const Vlist1 vals_file_exists = {0, 1, {{0, 2, "", &bool_ops, ""}}};
static const sig_desc1 sig_file_exists_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs_file_exists = {0, 1, {(const sig_desc *)&sig_file_exists_1}};
const dbg_info_generic dbg_info_file_exists_data = {0, 14, "file_exists", "file_exists", 0, 0, file_exists, 1, (const Vlist0 *)&vals_file_exists, (const siglist0 *)&sigs_file_exists,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_file_exists = (const struct dbg_info *)&dbg_info_file_exists_data;

extern errcode i_get1();
static const Vlist1 vals_i_get1 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
static const sig_desc0 sig_i_get1_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_i_get1 = {0, 1, {(const sig_desc *)&sig_i_get1_1}};
const dbg_info_generic dbg_info_i_get1_data = {0, 14, "i_get1", "i_get1", 0, 0, i_get1, 2, (const Vlist0 *)&vals_i_get1, (const siglist0 *)&sigs_i_get1,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_i_get1 = (const struct dbg_info *)&dbg_info_i_get1_data;

extern errcode _chanOPopen();
static const Vlist1 vals__chanOPopen = {0, 1, {{0, 2, "", &_chan_ops, ""}}};
static const sig_desc1 sig__chanOPopen_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPopen = {0, 1, {(const sig_desc *)&sig__chanOPopen_1}};
const dbg_info_generic dbg_info__chanOPopen_data = {0, 14, "_chan$open", "_chan", 0, 0, _chanOPopen, 3, (const Vlist0 *)&vals__chanOPopen, (const siglist0 *)&sigs__chanOPopen,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPopen = (const struct dbg_info *)&dbg_info__chanOPopen_data;

extern errcode _chanOP_open();
static const Vlist1 vals__chanOP_open = {0, 1, {{0, 2, "", &_chan_ops, ""}}};
static const sig_desc1 sig__chanOP_open_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOP_open = {0, 1, {(const sig_desc *)&sig__chanOP_open_1}};
const dbg_info_generic dbg_info__chanOP_open_data = {0, 14, "_chan$_open", "_chan", 0, 0, _chanOP_open, 3, (const Vlist0 *)&vals__chanOP_open, (const siglist0 *)&sigs__chanOP_open,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOP_open = (const struct dbg_info *)&dbg_info__chanOP_open_data;

extern errcode _chanOPpipe();
static const Vlist2 vals__chanOPpipe = {0, 2, {{0, 2, "", &_chan_ops, ""}, {0, 2, "", &_chan_ops, ""}}};
static const sig_desc1 sig__chanOPpipe_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPpipe = {0, 1, {(const sig_desc *)&sig__chanOPpipe_1}};
const dbg_info_generic dbg_info__chanOPpipe_data = {0, 14, "_chan$pipe", "_chan", 0, 0, _chanOPpipe, 0, (const Vlist0 *)&vals__chanOPpipe, (const siglist0 *)&sigs__chanOPpipe,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPpipe = (const struct dbg_info *)&dbg_info__chanOPpipe_data;

extern errcode _chanOPsocket();
static const Vlist1 vals__chanOPsocket = {0, 1, {{0, 2, "", &_chan_ops, ""}}};
static const sig_desc1 sig__chanOPsocket_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPsocket = {0, 1, {(const sig_desc *)&sig__chanOPsocket_1}};
const dbg_info_generic dbg_info__chanOPsocket_data = {0, 14, "_chan$socket", "_chan", 0, 0, _chanOPsocket, 3, (const Vlist0 *)&vals__chanOPsocket, (const siglist0 *)&sigs__chanOPsocket,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPsocket = (const struct dbg_info *)&dbg_info__chanOPsocket_data;

extern errcode _chanOPsocketpair();
static const Vlist2 vals__chanOPsocketpair = {0, 2, {{0, 2, "", &_chan_ops, ""}, {0, 2, "", &_chan_ops, ""}}};
static const sig_desc1 sig__chanOPsocketpair_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPsocketpair = {0, 1, {(const sig_desc *)&sig__chanOPsocketpair_1}};
const dbg_info_generic dbg_info__chanOPsocketpair_data = {0, 14, "_chan$socketpair", "_chan", 0, 0, _chanOPsocketpair, 3, (const Vlist0 *)&vals__chanOPsocketpair, (const siglist0 *)&sigs__chanOPsocketpair,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPsocketpair = (const struct dbg_info *)&dbg_info__chanOPsocketpair_data;

extern errcode _chanOPprimary_input();
static const Vlist1 vals__chanOPprimary_input = {0, 1, {{0, 2, "", &_chan_ops, ""}}};
const dbg_info_generic dbg_info__chanOPprimary_input_data = {0, 14, "_chan$primary_input", "_chan", 0, 0, _chanOPprimary_input, 0, (const Vlist0 *)&vals__chanOPprimary_input, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPprimary_input = (const struct dbg_info *)&dbg_info__chanOPprimary_input_data;

extern errcode _chanOPprimary_output();
static const Vlist1 vals__chanOPprimary_output = {0, 1, {{0, 2, "", &_chan_ops, ""}}};
const dbg_info_generic dbg_info__chanOPprimary_output_data = {0, 14, "_chan$primary_output", "_chan", 0, 0, _chanOPprimary_output, 0, (const Vlist0 *)&vals__chanOPprimary_output, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPprimary_output = (const struct dbg_info *)&dbg_info__chanOPprimary_output_data;

extern errcode _chanOPerror_output();
static const Vlist1 vals__chanOPerror_output = {0, 1, {{0, 2, "", &_chan_ops, ""}}};
const dbg_info_generic dbg_info__chanOPerror_output_data = {0, 14, "_chan$error_output", "_chan", 0, 0, _chanOPerror_output, 0, (const Vlist0 *)&vals__chanOPerror_output, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPerror_output = (const struct dbg_info *)&dbg_info__chanOPerror_output_data;

extern errcode _chanOPnul();
static const Vlist1 vals__chanOPnul = {0, 1, {{0, 2, "", &_chan_ops, ""}}};
const dbg_info_generic dbg_info__chanOPnul_data = {0, 14, "_chan$nul", "_chan", 0, 0, _chanOPnul, 0, (const Vlist0 *)&vals__chanOPnul, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPnul = (const struct dbg_info *)&dbg_info__chanOPnul_data;

extern errcode _chanOPcontrol();
static const Vlist1 vals__chanOPcontrol = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__chanOPcontrol_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPcontrol = {0, 1, {(const sig_desc *)&sig__chanOPcontrol_1}};
const dbg_info_generic dbg_info__chanOPcontrol_data = {0, 14, "_chan$control", "_chan", 0, 0, _chanOPcontrol, 3, (const Vlist0 *)&vals__chanOPcontrol, (const siglist0 *)&sigs__chanOPcontrol,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPcontrol = (const struct dbg_info *)&dbg_info__chanOPcontrol_data;

extern errcode _chanOPlock();
static const sig_desc1 sig__chanOPlock_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPlock = {0, 1, {(const sig_desc *)&sig__chanOPlock_1}};
const dbg_info_generic dbg_info__chanOPlock_data = {0, 14, "_chan$lock", "_chan", 0, 0, _chanOPlock, 2, &NO_VALS, (const siglist0 *)&sigs__chanOPlock,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPlock = (const struct dbg_info *)&dbg_info__chanOPlock_data;

extern errcode _chanOPsync();
static const sig_desc1 sig__chanOPsync_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPsync = {0, 1, {(const sig_desc *)&sig__chanOPsync_1}};
const dbg_info_generic dbg_info__chanOPsync_data = {0, 14, "_chan$sync", "_chan", 0, 0, _chanOPsync, 1, &NO_VALS, (const siglist0 *)&sigs__chanOPsync,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPsync = (const struct dbg_info *)&dbg_info__chanOPsync_data;

extern errcode _chanOPreset();
static const sig_desc1 sig__chanOPreset_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPreset = {0, 1, {(const sig_desc *)&sig__chanOPreset_1}};
const dbg_info_generic dbg_info__chanOPreset_data = {0, 14, "_chan$reset", "_chan", 0, 0, _chanOPreset, 1, &NO_VALS, (const siglist0 *)&sigs__chanOPreset,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPreset = (const struct dbg_info *)&dbg_info__chanOPreset_data;

extern errcode _chanOPclose();
static const sig_desc1 sig__chanOPclose_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const sig_desc0 sig__chanOPclose_2 = {0, 2, "permanent", {0,0}};
static const siglist2 sigs__chanOPclose = {0, 2, {(const sig_desc *)&sig__chanOPclose_1, (const sig_desc *)&sig__chanOPclose_2}};
const dbg_info_generic dbg_info__chanOPclose_data = {0, 14, "_chan$close", "_chan", 0, 0, _chanOPclose, 1, &NO_VALS, (const siglist0 *)&sigs__chanOPclose,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPclose = (const struct dbg_info *)&dbg_info__chanOPclose_data;

extern errcode _chanOPabort();
static const sig_desc1 sig__chanOPabort_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const sig_desc0 sig__chanOPabort_2 = {0, 2, "permanent", {0,0}};
static const siglist2 sigs__chanOPabort = {0, 2, {(const sig_desc *)&sig__chanOPabort_1, (const sig_desc *)&sig__chanOPabort_2}};
const dbg_info_generic dbg_info__chanOPabort_data = {0, 14, "_chan$abort", "_chan", 0, 0, _chanOPabort, 1, &NO_VALS, (const siglist0 *)&sigs__chanOPabort,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPabort = (const struct dbg_info *)&dbg_info__chanOPabort_data;

extern errcode _chanOPis_tty();
static const Vlist1 vals__chanOPis_tty = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info__chanOPis_tty_data = {0, 14, "_chan$is_tty", "_chan", 0, 0, _chanOPis_tty, 1, (const Vlist0 *)&vals__chanOPis_tty, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPis_tty = (const struct dbg_info *)&dbg_info__chanOPis_tty_data;

extern errcode _chanOPgetc();
extern struct OPS* char_ops;
static const Vlist1 vals__chanOPgetc = {0, 1, {{0, 2, "", &char_ops, ""}}};
static const sig_desc0 sig__chanOPgetc_1 = {0, 2, "end_of_file", {0,0}};
static const sig_desc1 sig__chanOPgetc_2 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist2 sigs__chanOPgetc = {0, 2, {(const sig_desc *)&sig__chanOPgetc_1, (const sig_desc *)&sig__chanOPgetc_2}};
const dbg_info_generic dbg_info__chanOPgetc_data = {0, 14, "_chan$getc", "_chan", 0, 0, _chanOPgetc, 2, (const Vlist0 *)&vals__chanOPgetc, (const siglist0 *)&sigs__chanOPgetc,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPgetc = (const struct dbg_info *)&dbg_info__chanOPgetc_data;

extern errcode _chanOPgeti();
static const Vlist1 vals__chanOPgeti = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig__chanOPgeti_1 = {0, 2, "end_of_file", {0,0}};
static const sig_desc1 sig__chanOPgeti_2 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const sig_desc0 sig__chanOPgeti_3 = {0, 2, "overflow", {0,0}};
static const siglist3 sigs__chanOPgeti = {0, 3, {(const sig_desc *)&sig__chanOPgeti_1, (const sig_desc *)&sig__chanOPgeti_2, (const sig_desc *)&sig__chanOPgeti_3}};
const dbg_info_generic dbg_info__chanOPgeti_data = {0, 14, "_chan$geti", "_chan", 0, 0, _chanOPgeti, 2, (const Vlist0 *)&vals__chanOPgeti, (const siglist0 *)&sigs__chanOPgeti,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPgeti = (const struct dbg_info *)&dbg_info__chanOPgeti_data;

extern errcode _chanOPgetb();
static const Vlist1 vals__chanOPgetb = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig__chanOPgetb_1 = {0, 2, "bounds", {0,0}};
static const sig_desc0 sig__chanOPgetb_2 = {0, 2, "end_of_file", {0,0}};
static const sig_desc1 sig__chanOPgetb_3 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist3 sigs__chanOPgetb = {0, 3, {(const sig_desc *)&sig__chanOPgetb_1, (const sig_desc *)&sig__chanOPgetb_2, (const sig_desc *)&sig__chanOPgetb_3}};
const dbg_info_generic dbg_info__chanOPgetb_data = {0, 14, "_chan$getb", "_chan", 0, 0, _chanOPgetb, 2, (const Vlist0 *)&vals__chanOPgetb, (const siglist0 *)&sigs__chanOPgetb,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPgetb = (const struct dbg_info *)&dbg_info__chanOPgetb_data;

extern errcode _chanOPgetbv();
static const Vlist1 vals__chanOPgetbv = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig__chanOPgetbv_1 = {0, 2, "bounds", {0,0}};
static const sig_desc0 sig__chanOPgetbv_2 = {0, 2, "end_of_file", {0,0}};
static const sig_desc1 sig__chanOPgetbv_3 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist3 sigs__chanOPgetbv = {0, 3, {(const sig_desc *)&sig__chanOPgetbv_1, (const sig_desc *)&sig__chanOPgetbv_2, (const sig_desc *)&sig__chanOPgetbv_3}};
const dbg_info_generic dbg_info__chanOPgetbv_data = {0, 14, "_chan$getbv", "_chan", 0, 0, _chanOPgetbv, 4, (const Vlist0 *)&vals__chanOPgetbv, (const siglist0 *)&sigs__chanOPgetbv,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPgetbv = (const struct dbg_info *)&dbg_info__chanOPgetbv_data;

extern errcode _chanOPgetw();
static const Vlist1 vals__chanOPgetw = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig__chanOPgetw_1 = {0, 2, "bounds", {0,0}};
static const sig_desc0 sig__chanOPgetw_2 = {0, 2, "end_of_file", {0,0}};
static const sig_desc1 sig__chanOPgetw_3 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist3 sigs__chanOPgetw = {0, 3, {(const sig_desc *)&sig__chanOPgetw_1, (const sig_desc *)&sig__chanOPgetw_2, (const sig_desc *)&sig__chanOPgetw_3}};
const dbg_info_generic dbg_info__chanOPgetw_data = {0, 14, "_chan$getw", "_chan", 0, 0, _chanOPgetw, 2, (const Vlist0 *)&vals__chanOPgetw, (const siglist0 *)&sigs__chanOPgetw,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPgetw = (const struct dbg_info *)&dbg_info__chanOPgetw_data;

extern errcode _chanOPgetwv();
static const Vlist1 vals__chanOPgetwv = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig__chanOPgetwv_1 = {0, 2, "bounds", {0,0}};
static const sig_desc0 sig__chanOPgetwv_2 = {0, 2, "end_of_file", {0,0}};
static const sig_desc1 sig__chanOPgetwv_3 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist3 sigs__chanOPgetwv = {0, 3, {(const sig_desc *)&sig__chanOPgetwv_1, (const sig_desc *)&sig__chanOPgetwv_2, (const sig_desc *)&sig__chanOPgetwv_3}};
const dbg_info_generic dbg_info__chanOPgetwv_data = {0, 14, "_chan$getwv", "_chan", 0, 0, _chanOPgetwv, 4, (const Vlist0 *)&vals__chanOPgetwv, (const siglist0 *)&sigs__chanOPgetwv,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPgetwv = (const struct dbg_info *)&dbg_info__chanOPgetwv_data;

extern errcode _chanOPget();
static const Vlist3 vals__chanOPget = {0, 3, {{0, 2, "", &string_ops, ""}, {0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig__chanOPget_1 = {0, 2, "bounds", {0,0}};
static const sig_desc0 sig__chanOPget_2 = {0, 2, "end_of_file", {0,0}};
static const sig_desc1 sig__chanOPget_3 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist3 sigs__chanOPget = {0, 3, {(const sig_desc *)&sig__chanOPget_1, (const sig_desc *)&sig__chanOPget_2, (const sig_desc *)&sig__chanOPget_3}};
const dbg_info_generic dbg_info__chanOPget_data = {0, 14, "_chan$get", "_chan", 0, 0, _chanOPget, 6, (const Vlist0 *)&vals__chanOPget, (const siglist0 *)&sigs__chanOPget,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPget = (const struct dbg_info *)&dbg_info__chanOPget_data;

extern errcode _chanOPrecv();
extern errcode _chanOPpending();
static const Vlist1 vals__chanOPpending = {0, 1, {{0, 2, "", &bool_ops, ""}}};
static const sig_desc1 sig__chanOPpending_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPpending = {0, 1, {(const sig_desc *)&sig__chanOPpending_1}};
const dbg_info_generic dbg_info__chanOPpending_data = {0, 14, "_chan$pending", "_chan", 0, 0, _chanOPpending, 2, (const Vlist0 *)&vals__chanOPpending, (const siglist0 *)&sigs__chanOPpending,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPpending = (const struct dbg_info *)&dbg_info__chanOPpending_data;

extern errcode _chanOPpend_count();
static const Vlist1 vals__chanOPpend_count = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__chanOPpend_count_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPpend_count = {0, 1, {(const sig_desc *)&sig__chanOPpend_count_1}};
const dbg_info_generic dbg_info__chanOPpend_count_data = {0, 14, "_chan$pend_count", "_chan", 0, 0, _chanOPpend_count, 1, (const Vlist0 *)&vals__chanOPpend_count, (const siglist0 *)&sigs__chanOPpend_count,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPpend_count = (const struct dbg_info *)&dbg_info__chanOPpend_count_data;

extern errcode _chanOPbuf_count();
static const Vlist1 vals__chanOPbuf_count = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__chanOPbuf_count_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPbuf_count = {0, 1, {(const sig_desc *)&sig__chanOPbuf_count_1}};
const dbg_info_generic dbg_info__chanOPbuf_count_data = {0, 14, "_chan$buf_count", "_chan", 0, 0, _chanOPbuf_count, 1, (const Vlist0 *)&vals__chanOPbuf_count, (const siglist0 *)&sigs__chanOPbuf_count,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPbuf_count = (const struct dbg_info *)&dbg_info__chanOPbuf_count_data;

extern errcode _chanOPputc();
static const sig_desc1 sig__chanOPputc_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPputc = {0, 1, {(const sig_desc *)&sig__chanOPputc_1}};
const dbg_info_generic dbg_info__chanOPputc_data = {0, 14, "_chan$putc", "_chan", 0, 0, _chanOPputc, 3, &NO_VALS, (const siglist0 *)&sigs__chanOPputc,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPputc = (const struct dbg_info *)&dbg_info__chanOPputc_data;

extern errcode _chanOPputi();
static const sig_desc1 sig__chanOPputi_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPputi = {0, 1, {(const sig_desc *)&sig__chanOPputi_1}};
const dbg_info_generic dbg_info__chanOPputi_data = {0, 14, "_chan$puti", "_chan", 0, 0, _chanOPputi, 3, &NO_VALS, (const siglist0 *)&sigs__chanOPputi,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPputi = (const struct dbg_info *)&dbg_info__chanOPputi_data;

extern errcode _chanOPputs();
static const sig_desc1 sig__chanOPputs_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPputs = {0, 1, {(const sig_desc *)&sig__chanOPputs_1}};
const dbg_info_generic dbg_info__chanOPputs_data = {0, 14, "_chan$puts", "_chan", 0, 0, _chanOPputs, 3, &NO_VALS, (const siglist0 *)&sigs__chanOPputs,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPputs = (const struct dbg_info *)&dbg_info__chanOPputs_data;

extern errcode _chanOPputb();
static const sig_desc0 sig__chanOPputb_1 = {0, 2, "bounds", {0,0}};
static const sig_desc1 sig__chanOPputb_2 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist2 sigs__chanOPputb = {0, 2, {(const sig_desc *)&sig__chanOPputb_1, (const sig_desc *)&sig__chanOPputb_2}};
const dbg_info_generic dbg_info__chanOPputb_data = {0, 14, "_chan$putb", "_chan", 0, 0, _chanOPputb, 5, &NO_VALS, (const siglist0 *)&sigs__chanOPputb,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPputb = (const struct dbg_info *)&dbg_info__chanOPputb_data;

extern errcode _chanOPputw();
static const sig_desc0 sig__chanOPputw_1 = {0, 2, "bounds", {0,0}};
static const sig_desc1 sig__chanOPputw_2 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist2 sigs__chanOPputw = {0, 2, {(const sig_desc *)&sig__chanOPputw_1, (const sig_desc *)&sig__chanOPputw_2}};
const dbg_info_generic dbg_info__chanOPputw_data = {0, 14, "_chan$putw", "_chan", 0, 0, _chanOPputw, 5, &NO_VALS, (const siglist0 *)&sigs__chanOPputw,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPputw = (const struct dbg_info *)&dbg_info__chanOPputw_data;

extern errcode _chanOPput();
static const Vlist2 vals__chanOPput = {0, 2, {{0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig__chanOPput_1 = {0, 2, "bounds", {0,0}};
static const sig_desc1 sig__chanOPput_2 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist2 sigs__chanOPput = {0, 2, {(const sig_desc *)&sig__chanOPput_1, (const sig_desc *)&sig__chanOPput_2}};
const dbg_info_generic dbg_info__chanOPput_data = {0, 14, "_chan$put", "_chan", 0, 0, _chanOPput, 6, (const Vlist0 *)&vals__chanOPput, (const siglist0 *)&sigs__chanOPput,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPput = (const struct dbg_info *)&dbg_info__chanOPput_data;

extern errcode _chanOPsend();
extern errcode _chanOPget_name();
extern struct OPS* file_name_ops;
static const Vlist1 vals__chanOPget_name = {0, 1, {{0, 2, "", &file_name_ops, ""}}};
static const sig_desc1 sig__chanOPget_name_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPget_name = {0, 1, {(const sig_desc *)&sig__chanOPget_name_1}};
const dbg_info_generic dbg_info__chanOPget_name_data = {0, 14, "_chan$get_name", "_chan", 0, 0, _chanOPget_name, 1, (const Vlist0 *)&vals__chanOPget_name, (const siglist0 *)&sigs__chanOPget_name,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPget_name = (const struct dbg_info *)&dbg_info__chanOPget_name_data;

extern errcode _chanOPget_date();
extern struct OPS* date_ops;
static const Vlist1 vals__chanOPget_date = {0, 1, {{0, 2, "", &date_ops, ""}}};
static const sig_desc1 sig__chanOPget_date_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPget_date = {0, 1, {(const sig_desc *)&sig__chanOPget_date_1}};
const dbg_info_generic dbg_info__chanOPget_date_data = {0, 14, "_chan$get_date", "_chan", 0, 0, _chanOPget_date, 1, (const Vlist0 *)&vals__chanOPget_date, (const siglist0 *)&sigs__chanOPget_date,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPget_date = (const struct dbg_info *)&dbg_info__chanOPget_date_data;

extern errcode _chanOPget_speeds();
static const Vlist2 vals__chanOPget_speeds = {0, 2, {{0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__chanOPget_speeds_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPget_speeds = {0, 1, {(const sig_desc *)&sig__chanOPget_speeds_1}};
const dbg_info_generic dbg_info__chanOPget_speeds_data = {0, 14, "_chan$get_speeds", "_chan", 0, 0, _chanOPget_speeds, 1, (const Vlist0 *)&vals__chanOPget_speeds, (const siglist0 *)&sigs__chanOPget_speeds,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPget_speeds = (const struct dbg_info *)&dbg_info__chanOPget_speeds_data;

extern errcode _chanOPget_block_size();
static const Vlist1 vals__chanOPget_block_size = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__chanOPget_block_size_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPget_block_size = {0, 1, {(const sig_desc *)&sig__chanOPget_block_size_1}};
const dbg_info_generic dbg_info__chanOPget_block_size_data = {0, 14, "_chan$get_block_size", "_chan", 0, 0, _chanOPget_block_size, 1, (const Vlist0 *)&vals__chanOPget_block_size, (const siglist0 *)&sigs__chanOPget_block_size,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPget_block_size = (const struct dbg_info *)&dbg_info__chanOPget_block_size_data;

extern errcode _chanOPstat();
static const sig_desc0 sig__chanOPstat_1 = {0, 2, "bounds", {0,0}};
static const sig_desc1 sig__chanOPstat_2 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist2 sigs__chanOPstat = {0, 2, {(const sig_desc *)&sig__chanOPstat_1, (const sig_desc *)&sig__chanOPstat_2}};
const dbg_info_generic dbg_info__chanOPstat_data = {0, 14, "_chan$stat", "_chan", 0, 0, _chanOPstat, 2, &NO_VALS, (const siglist0 *)&sigs__chanOPstat,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPstat = (const struct dbg_info *)&dbg_info__chanOPstat_data;

extern errcode _chanOPget_access();
static const Vlist1 vals__chanOPget_access = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__chanOPget_access_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPget_access = {0, 1, {(const sig_desc *)&sig__chanOPget_access_1}};
const dbg_info_generic dbg_info__chanOPget_access_data = {0, 14, "_chan$get_access", "_chan", 0, 0, _chanOPget_access, 1, (const Vlist0 *)&vals__chanOPget_access, (const siglist0 *)&sigs__chanOPget_access,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPget_access = (const struct dbg_info *)&dbg_info__chanOPget_access_data;

extern errcode _chanOPset_access();
static const sig_desc1 sig__chanOPset_access_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPset_access = {0, 1, {(const sig_desc *)&sig__chanOPset_access_1}};
const dbg_info_generic dbg_info__chanOPset_access_data = {0, 14, "_chan$set_access", "_chan", 0, 0, _chanOPset_access, 2, &NO_VALS, (const siglist0 *)&sigs__chanOPset_access,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPset_access = (const struct dbg_info *)&dbg_info__chanOPset_access_data;

extern errcode _chanOPget_length();
static const Vlist1 vals__chanOPget_length = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__chanOPget_length_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPget_length = {0, 1, {(const sig_desc *)&sig__chanOPget_length_1}};
const dbg_info_generic dbg_info__chanOPget_length_data = {0, 14, "_chan$get_length", "_chan", 0, 0, _chanOPget_length, 1, (const Vlist0 *)&vals__chanOPget_length, (const siglist0 *)&sigs__chanOPget_length,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPget_length = (const struct dbg_info *)&dbg_info__chanOPget_length_data;

extern errcode _chanOPset_length();
static const sig_desc1 sig__chanOPset_length_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPset_length = {0, 1, {(const sig_desc *)&sig__chanOPset_length_1}};
const dbg_info_generic dbg_info__chanOPset_length_data = {0, 14, "_chan$set_length", "_chan", 0, 0, _chanOPset_length, 2, &NO_VALS, (const siglist0 *)&sigs__chanOPset_length,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPset_length = (const struct dbg_info *)&dbg_info__chanOPset_length_data;

extern errcode _chanOPequal();
static const Vlist1 vals__chanOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info__chanOPequal_data = {0, 14, "_chan$equal", "_chan", 0, 0, _chanOPequal, 2, (const Vlist0 *)&vals__chanOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPequal = (const struct dbg_info *)&dbg_info__chanOPequal_data;

extern errcode _chanOPsimilar();
static const Vlist1 vals__chanOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info__chanOPsimilar_data = {0, 14, "_chan$similar", "_chan", 0, 0, _chanOPsimilar, 2, (const Vlist0 *)&vals__chanOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPsimilar = (const struct dbg_info *)&dbg_info__chanOPsimilar_data;

extern errcode _chanOPcopy();
static const Vlist1 vals__chanOPcopy = {0, 1, {{0, 2, "", &_chan_ops, ""}}};
const dbg_info_generic dbg_info__chanOPcopy_data = {0, 14, "_chan$copy", "_chan", 0, 0, _chanOPcopy, 1, (const Vlist0 *)&vals__chanOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPcopy = (const struct dbg_info *)&dbg_info__chanOPcopy_data;

extern errcode _chanOPget_read_channel();
static const Vlist1 vals__chanOPget_read_channel = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__chanOPget_read_channel_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPget_read_channel = {0, 1, {(const sig_desc *)&sig__chanOPget_read_channel_1}};
const dbg_info_generic dbg_info__chanOPget_read_channel_data = {0, 14, "_chan$get_read_channel", "_chan", 0, 0, _chanOPget_read_channel, 2, (const Vlist0 *)&vals__chanOPget_read_channel, (const siglist0 *)&sigs__chanOPget_read_channel,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPget_read_channel = (const struct dbg_info *)&dbg_info__chanOPget_read_channel_data;

extern errcode _chanOPget_write_channel();
static const Vlist1 vals__chanOPget_write_channel = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__chanOPget_write_channel_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__chanOPget_write_channel = {0, 1, {(const sig_desc *)&sig__chanOPget_write_channel_1}};
const dbg_info_generic dbg_info__chanOPget_write_channel_data = {0, 14, "_chan$get_write_channel", "_chan", 0, 0, _chanOPget_write_channel, 2, (const Vlist0 *)&vals__chanOPget_write_channel, (const siglist0 *)&sigs__chanOPget_write_channel,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPget_write_channel = (const struct dbg_info *)&dbg_info__chanOPget_write_channel_data;

extern errcode _chanOPget_def_mode();
static const Vlist1 vals__chanOPget_def_mode = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__chanOPget_def_mode_data = {0, 14, "_chan$get_def_mode", "_chan", 0, 0, _chanOPget_def_mode, 0, (const Vlist0 *)&vals__chanOPget_def_mode, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPget_def_mode = (const struct dbg_info *)&dbg_info__chanOPget_def_mode_data;

extern errcode _chanOPset_def_mode();
const dbg_info_generic dbg_info__chanOPset_def_mode_data = {0, 14, "_chan$set_def_mode", "_chan", 0, 0, _chanOPset_def_mode, 1, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPset_def_mode = (const struct dbg_info *)&dbg_info__chanOPset_def_mode_data;

extern errcode _chanOP_save_tty();
const dbg_info_generic dbg_info__chanOP_save_tty_data = {0, 14, "_chan$_save_tty", "_chan", 0, 0, _chanOP_save_tty, 0, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOP_save_tty = (const struct dbg_info *)&dbg_info__chanOP_save_tty_data;

extern errcode _chanOP_restore_tty();
const dbg_info_generic dbg_info__chanOP_restore_tty_data = {0, 14, "_chan$_restore_tty", "_chan", 0, 0, _chanOP_restore_tty, 0, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOP_restore_tty = (const struct dbg_info *)&dbg_info__chanOP_restore_tty_data;

extern errcode _chanOPclose_all();
const dbg_info_generic dbg_info__chanOPclose_all_data = {0, 14, "_chan$close_all", "_chan", 0, 0, _chanOPclose_all, 0, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__chanOPclose_all = (const struct dbg_info *)&dbg_info__chanOPclose_all_data;

extern errcode _exit();
const dbg_info_generic dbg_info__exit_data = {0, 14, "_exit", "_exit", 0, 0, _exit, 1, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__exit = (const struct dbg_info *)&dbg_info__exit_data;

extern errcode i_not();
static const Vlist1 vals_i_not = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_i_not_1 = {0, 2, "overflow", {0,0}};
static const siglist1 sigs_i_not = {0, 1, {(const sig_desc *)&sig_i_not_1}};
const dbg_info_generic dbg_info_i_not_data = {0, 14, "i_not", "i_not", 0, 0, i_not, 1, (const Vlist0 *)&vals_i_not, (const siglist0 *)&sigs_i_not,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_i_not = (const struct dbg_info *)&dbg_info_i_not_data;

/*
extern errcode _heap_size();
static const Vlist1 vals__heap_size = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__heap_size_data = {0, 14, "_heap_size", "_heap_size", 0, 0, _heap_size, 0, (const Vlist0 *)&vals__heap_size, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__heap_size = (const struct dbg_info *)&dbg_info__heap_size_data;

*/
extern errcode _read_link();
static const Vlist1 vals__read_link = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc1 sig__read_link_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__read_link = {0, 1, {(const sig_desc *)&sig__read_link_1}};
const dbg_info_generic dbg_info__read_link_data = {0, 14, "_read_link", "_read_link", 0, 0, _read_link, 2, (const Vlist0 *)&vals__read_link, (const siglist0 *)&sigs__read_link,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__read_link = (const struct dbg_info *)&dbg_info__read_link_data;

extern errcode stringOPsize();
static const Vlist1 vals_stringOPsize = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_stringOPsize_data = {0, 14, "string$size", "string", 0, 0, stringOPsize, 1, (const Vlist0 *)&vals_stringOPsize, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPsize = (const struct dbg_info *)&dbg_info_stringOPsize_data;

extern errcode stringOPindexs();
static const Vlist1 vals_stringOPindexs = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_stringOPindexs_data = {0, 14, "string$indexs", "string", 0, 0, stringOPindexs, 2, (const Vlist0 *)&vals_stringOPindexs, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPindexs = (const struct dbg_info *)&dbg_info_stringOPindexs_data;

extern errcode stringOPindexc();
static const Vlist1 vals_stringOPindexc = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_stringOPindexc_data = {0, 14, "string$indexc", "string", 0, 0, stringOPindexc, 2, (const Vlist0 *)&vals_stringOPindexc, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPindexc = (const struct dbg_info *)&dbg_info_stringOPindexc_data;

extern errcode stringOPc2s();
static const Vlist1 vals_stringOPc2s = {0, 1, {{0, 2, "", &string_ops, ""}}};
const dbg_info_generic dbg_info_stringOPc2s_data = {0, 14, "string$c2s", "string", 0, 0, stringOPc2s, 1, (const Vlist0 *)&vals_stringOPc2s, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPc2s = (const struct dbg_info *)&dbg_info_stringOPc2s_data;

extern errcode stringOPconcat();
static const Vlist1 vals_stringOPconcat = {0, 1, {{0, 2, "", &string_ops, ""}}};
const dbg_info_generic dbg_info_stringOPconcat_data = {0, 14, "string$concat", "string", 0, 0, stringOPconcat, 2, (const Vlist0 *)&vals_stringOPconcat, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPconcat = (const struct dbg_info *)&dbg_info_stringOPconcat_data;

extern errcode stringOPappend();
static const Vlist1 vals_stringOPappend = {0, 1, {{0, 2, "", &string_ops, ""}}};
const dbg_info_generic dbg_info_stringOPappend_data = {0, 14, "string$append", "string", 0, 0, stringOPappend, 2, (const Vlist0 *)&vals_stringOPappend, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPappend = (const struct dbg_info *)&dbg_info_stringOPappend_data;

extern errcode stringOPfetch();
extern struct OPS* char_ops;
static const Vlist1 vals_stringOPfetch = {0, 1, {{0, 2, "", &char_ops, ""}}};
static const sig_desc0 sig_stringOPfetch_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_stringOPfetch = {0, 1, {(const sig_desc *)&sig_stringOPfetch_1}};
const dbg_info_generic dbg_info_stringOPfetch_data = {0, 14, "string$fetch", "string", 0, 0, stringOPfetch, 2, (const Vlist0 *)&vals_stringOPfetch, (const siglist0 *)&sigs_stringOPfetch,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPfetch = (const struct dbg_info *)&dbg_info_stringOPfetch_data;

extern errcode stringOPempty();
static const Vlist1 vals_stringOPempty = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_stringOPempty_data = {0, 14, "string$empty", "string", 0, 0, stringOPempty, 1, (const Vlist0 *)&vals_stringOPempty, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPempty = (const struct dbg_info *)&dbg_info_stringOPempty_data;

extern errcode stringOPsubstr();
static const Vlist1 vals_stringOPsubstr = {0, 1, {{0, 2, "", &string_ops, ""}}};
static const sig_desc0 sig_stringOPsubstr_1 = {0, 2, "bounds", {0,0}};
static const sig_desc0 sig_stringOPsubstr_2 = {0, 2, "negative_size", {0,0}};
static const siglist2 sigs_stringOPsubstr = {0, 2, {(const sig_desc *)&sig_stringOPsubstr_1, (const sig_desc *)&sig_stringOPsubstr_2}};
const dbg_info_generic dbg_info_stringOPsubstr_data = {0, 14, "string$substr", "string", 0, 0, stringOPsubstr, 3, (const Vlist0 *)&vals_stringOPsubstr, (const siglist0 *)&sigs_stringOPsubstr,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPsubstr = (const struct dbg_info *)&dbg_info_stringOPsubstr_data;

extern errcode stringOPrest();
static const Vlist1 vals_stringOPrest = {0, 1, {{0, 2, "", &string_ops, ""}}};
static const sig_desc0 sig_stringOPrest_1 = {0, 2, "bounds", {0,0}};
static const siglist1 sigs_stringOPrest = {0, 1, {(const sig_desc *)&sig_stringOPrest_1}};
const dbg_info_generic dbg_info_stringOPrest_data = {0, 14, "string$rest", "string", 0, 0, stringOPrest, 2, (const Vlist0 *)&vals_stringOPrest, (const siglist0 *)&sigs_stringOPrest,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPrest = (const struct dbg_info *)&dbg_info_stringOPrest_data;

extern errcode stringOPs2ac();
static const Vlist1 vals_stringOPs2ac = {0, 1, {{0, 3, "", zero_ops, "array_of_char_ops"}}};
const dbg_info_generic dbg_info_stringOPs2ac_data = {0, 14, "string$s2ac", "string", 0, 0, stringOPs2ac, 1, (const Vlist0 *)&vals_stringOPs2ac, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPs2ac = (const struct dbg_info *)&dbg_info_stringOPs2ac_data;

extern errcode stringOPac2s();
static const Vlist1 vals_stringOPac2s = {0, 1, {{0, 2, "", &string_ops, ""}}};
const dbg_info_generic dbg_info_stringOPac2s_data = {0, 14, "string$ac2s", "string", 0, 0, stringOPac2s, 1, (const Vlist0 *)&vals_stringOPac2s, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPac2s = (const struct dbg_info *)&dbg_info_stringOPac2s_data;

extern errcode stringOPs2sc();
static const Vlist1 vals_stringOPs2sc = {0, 1, {{0, 3, "", zero_ops, "sequence_of_char_ops"}}};
const dbg_info_generic dbg_info_stringOPs2sc_data = {0, 14, "string$s2sc", "string", 0, 0, stringOPs2sc, 1, (const Vlist0 *)&vals_stringOPs2sc, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPs2sc = (const struct dbg_info *)&dbg_info_stringOPs2sc_data;

extern errcode stringOPsc2s();
static const Vlist1 vals_stringOPsc2s = {0, 1, {{0, 2, "", &string_ops, ""}}};
const dbg_info_generic dbg_info_stringOPsc2s_data = {0, 14, "string$sc2s", "string", 0, 0, stringOPsc2s, 1, (const Vlist0 *)&vals_stringOPsc2s, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPsc2s = (const struct dbg_info *)&dbg_info_stringOPsc2s_data;

extern errcode stringOPchars();
extern struct OPS* char_ops;
static const Vlist1 vals_stringOPchars = {0, 1, {{0, 2, "", &char_ops, ""}}};
const dbg_info_generic dbg_info_stringOPchars_data = {0, 14, "string$chars", "string", 1, 0, stringOPchars, 1, (const Vlist0 *)&vals_stringOPchars, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPchars = (const struct dbg_info *)&dbg_info_stringOPchars_data;

extern errcode stringOPlt();
static const Vlist1 vals_stringOPlt = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_stringOPlt_data = {0, 14, "string$lt", "string", 0, 0, stringOPlt, 2, (const Vlist0 *)&vals_stringOPlt, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPlt = (const struct dbg_info *)&dbg_info_stringOPlt_data;

extern errcode stringOPle();
static const Vlist1 vals_stringOPle = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_stringOPle_data = {0, 14, "string$le", "string", 0, 0, stringOPle, 2, (const Vlist0 *)&vals_stringOPle, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPle = (const struct dbg_info *)&dbg_info_stringOPle_data;

extern errcode stringOPge();
static const Vlist1 vals_stringOPge = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_stringOPge_data = {0, 14, "string$ge", "string", 0, 0, stringOPge, 2, (const Vlist0 *)&vals_stringOPge, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPge = (const struct dbg_info *)&dbg_info_stringOPge_data;

extern errcode stringOPgt();
static const Vlist1 vals_stringOPgt = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_stringOPgt_data = {0, 14, "string$gt", "string", 0, 0, stringOPgt, 2, (const Vlist0 *)&vals_stringOPgt, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPgt = (const struct dbg_info *)&dbg_info_stringOPgt_data;

extern errcode stringOPequal();
static const Vlist1 vals_stringOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_stringOPequal_data = {0, 14, "string$equal", "string", 0, 0, stringOPequal, 2, (const Vlist0 *)&vals_stringOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPequal = (const struct dbg_info *)&dbg_info_stringOPequal_data;

extern errcode stringOPsimilar();
static const Vlist1 vals_stringOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_stringOPsimilar_data = {0, 14, "string$similar", "string", 0, 0, stringOPsimilar, 2, (const Vlist0 *)&vals_stringOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPsimilar = (const struct dbg_info *)&dbg_info_stringOPsimilar_data;

extern errcode stringOPcopy();
static const Vlist1 vals_stringOPcopy = {0, 1, {{0, 2, "", &string_ops, ""}}};
const dbg_info_generic dbg_info_stringOPcopy_data = {0, 14, "string$copy", "string", 0, 0, stringOPcopy, 1, (const Vlist0 *)&vals_stringOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPcopy = (const struct dbg_info *)&dbg_info_stringOPcopy_data;

extern errcode stringOPprint();
const dbg_info_generic dbg_info_stringOPprint_data = {0, 14, "string$print", "string", 0, 0, stringOPprint, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_stringOPprint = (const struct dbg_info *)&dbg_info_stringOPprint_data;

extern errcode variantOPmake_1();
const Slist1 opformals_variantOPmake_1 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPmake_1 = {0, 1, {{0, 3, "", zero_ops, "vt_ops"}}};
const dbg_info_generic dbg_info_variantOPmake_1_data = {0, 14, "variant$make_1", "variant", 0, 1, variantOPmake_1, 1, (const Vlist0 *)&vals_variantOPmake_1, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPmake_1};
const struct dbg_info * const dbg_info_variantOPmake_1 = (const struct dbg_info *)&dbg_info_variantOPmake_1_data;

extern errcode variantOPmake_2();
const Slist1 opformals_variantOPmake_2 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPmake_2 = {0, 1, {{0, 3, "", zero_ops, "vt_ops"}}};
const dbg_info_generic dbg_info_variantOPmake_2_data = {0, 14, "variant$make_2", "variant", 0, 1, variantOPmake_2, 1, (const Vlist0 *)&vals_variantOPmake_2, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPmake_2};
const struct dbg_info * const dbg_info_variantOPmake_2 = (const struct dbg_info *)&dbg_info_variantOPmake_2_data;

extern errcode variantOPmake_3();
const Slist1 opformals_variantOPmake_3 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPmake_3 = {0, 1, {{0, 3, "", zero_ops, "vt_ops"}}};
const dbg_info_generic dbg_info_variantOPmake_3_data = {0, 14, "variant$make_3", "variant", 0, 1, variantOPmake_3, 1, (const Vlist0 *)&vals_variantOPmake_3, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPmake_3};
const struct dbg_info * const dbg_info_variantOPmake_3 = (const struct dbg_info *)&dbg_info_variantOPmake_3_data;

extern errcode variantOPmake_4();
const Slist1 opformals_variantOPmake_4 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPmake_4 = {0, 1, {{0, 3, "", zero_ops, "vt_ops"}}};
const dbg_info_generic dbg_info_variantOPmake_4_data = {0, 14, "variant$make_4", "variant", 0, 1, variantOPmake_4, 1, (const Vlist0 *)&vals_variantOPmake_4, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPmake_4};
const struct dbg_info * const dbg_info_variantOPmake_4 = (const struct dbg_info *)&dbg_info_variantOPmake_4_data;

extern errcode variantOPmake_5();
const Slist1 opformals_variantOPmake_5 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPmake_5 = {0, 1, {{0, 3, "", zero_ops, "vt_ops"}}};
const dbg_info_generic dbg_info_variantOPmake_5_data = {0, 14, "variant$make_5", "variant", 0, 1, variantOPmake_5, 1, (const Vlist0 *)&vals_variantOPmake_5, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPmake_5};
const struct dbg_info * const dbg_info_variantOPmake_5 = (const struct dbg_info *)&dbg_info_variantOPmake_5_data;

extern errcode variantOPmake_6();
const Slist1 opformals_variantOPmake_6 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPmake_6 = {0, 1, {{0, 3, "", zero_ops, "vt_ops"}}};
const dbg_info_generic dbg_info_variantOPmake_6_data = {0, 14, "variant$make_6", "variant", 0, 1, variantOPmake_6, 1, (const Vlist0 *)&vals_variantOPmake_6, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPmake_6};
const struct dbg_info * const dbg_info_variantOPmake_6 = (const struct dbg_info *)&dbg_info_variantOPmake_6_data;

extern errcode variantOPmake_7();
const Slist1 opformals_variantOPmake_7 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPmake_7 = {0, 1, {{0, 3, "", zero_ops, "vt_ops"}}};
const dbg_info_generic dbg_info_variantOPmake_7_data = {0, 14, "variant$make_7", "variant", 0, 1, variantOPmake_7, 1, (const Vlist0 *)&vals_variantOPmake_7, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPmake_7};
const struct dbg_info * const dbg_info_variantOPmake_7 = (const struct dbg_info *)&dbg_info_variantOPmake_7_data;

extern errcode variantOPmake_8();
const Slist1 opformals_variantOPmake_8 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPmake_8 = {0, 1, {{0, 3, "", zero_ops, "vt_ops"}}};
const dbg_info_generic dbg_info_variantOPmake_8_data = {0, 14, "variant$make_8", "variant", 0, 1, variantOPmake_8, 1, (const Vlist0 *)&vals_variantOPmake_8, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPmake_8};
const struct dbg_info * const dbg_info_variantOPmake_8 = (const struct dbg_info *)&dbg_info_variantOPmake_8_data;

extern errcode variantOPmake_9();
const Slist1 opformals_variantOPmake_9 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPmake_9 = {0, 1, {{0, 3, "", zero_ops, "vt_ops"}}};
const dbg_info_generic dbg_info_variantOPmake_9_data = {0, 14, "variant$make_9", "variant", 0, 1, variantOPmake_9, 1, (const Vlist0 *)&vals_variantOPmake_9, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPmake_9};
const struct dbg_info * const dbg_info_variantOPmake_9 = (const struct dbg_info *)&dbg_info_variantOPmake_9_data;

extern errcode variantOPmake_10();
const Slist1 opformals_variantOPmake_10 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPmake_10 = {0, 1, {{0, 3, "", zero_ops, "vt_ops"}}};
const dbg_info_generic dbg_info_variantOPmake_10_data = {0, 14, "variant$make_10", "variant", 0, 1, variantOPmake_10, 1, (const Vlist0 *)&vals_variantOPmake_10, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPmake_10};
const struct dbg_info * const dbg_info_variantOPmake_10 = (const struct dbg_info *)&dbg_info_variantOPmake_10_data;

extern errcode variantOPchange_1();
const Slist1 opformals_variantOPchange_1 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_variantOPchange_1_data = {0, 14, "variant$change_1", "variant", 0, 1, variantOPchange_1, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPchange_1};
const struct dbg_info * const dbg_info_variantOPchange_1 = (const struct dbg_info *)&dbg_info_variantOPchange_1_data;

extern errcode variantOPchange_2();
const Slist1 opformals_variantOPchange_2 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_variantOPchange_2_data = {0, 14, "variant$change_2", "variant", 0, 1, variantOPchange_2, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPchange_2};
const struct dbg_info * const dbg_info_variantOPchange_2 = (const struct dbg_info *)&dbg_info_variantOPchange_2_data;

extern errcode variantOPchange_3();
const Slist1 opformals_variantOPchange_3 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_variantOPchange_3_data = {0, 14, "variant$change_3", "variant", 0, 1, variantOPchange_3, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPchange_3};
const struct dbg_info * const dbg_info_variantOPchange_3 = (const struct dbg_info *)&dbg_info_variantOPchange_3_data;

extern errcode variantOPchange_4();
const Slist1 opformals_variantOPchange_4 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_variantOPchange_4_data = {0, 14, "variant$change_4", "variant", 0, 1, variantOPchange_4, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPchange_4};
const struct dbg_info * const dbg_info_variantOPchange_4 = (const struct dbg_info *)&dbg_info_variantOPchange_4_data;

extern errcode variantOPchange_5();
const Slist1 opformals_variantOPchange_5 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_variantOPchange_5_data = {0, 14, "variant$change_5", "variant", 0, 1, variantOPchange_5, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPchange_5};
const struct dbg_info * const dbg_info_variantOPchange_5 = (const struct dbg_info *)&dbg_info_variantOPchange_5_data;

extern errcode variantOPchange_6();
const Slist1 opformals_variantOPchange_6 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_variantOPchange_6_data = {0, 14, "variant$change_6", "variant", 0, 1, variantOPchange_6, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPchange_6};
const struct dbg_info * const dbg_info_variantOPchange_6 = (const struct dbg_info *)&dbg_info_variantOPchange_6_data;

extern errcode variantOPchange_7();
const Slist1 opformals_variantOPchange_7 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_variantOPchange_7_data = {0, 14, "variant$change_7", "variant", 0, 1, variantOPchange_7, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPchange_7};
const struct dbg_info * const dbg_info_variantOPchange_7 = (const struct dbg_info *)&dbg_info_variantOPchange_7_data;

extern errcode variantOPchange_8();
const Slist1 opformals_variantOPchange_8 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_variantOPchange_8_data = {0, 14, "variant$change_8", "variant", 0, 1, variantOPchange_8, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPchange_8};
const struct dbg_info * const dbg_info_variantOPchange_8 = (const struct dbg_info *)&dbg_info_variantOPchange_8_data;

extern errcode variantOPchange_9();
const Slist1 opformals_variantOPchange_9 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_variantOPchange_9_data = {0, 14, "variant$change_9", "variant", 0, 1, variantOPchange_9, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPchange_9};
const struct dbg_info * const dbg_info_variantOPchange_9 = (const struct dbg_info *)&dbg_info_variantOPchange_9_data;

extern errcode variantOPchange_10();
const Slist1 opformals_variantOPchange_10 = {0, 1, {"t"}};
const dbg_info_generic dbg_info_variantOPchange_10_data = {0, 14, "variant$change_10", "variant", 0, 1, variantOPchange_10, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPchange_10};
const struct dbg_info * const dbg_info_variantOPchange_10 = (const struct dbg_info *)&dbg_info_variantOPchange_10_data;

extern errcode variantOPis_1();
const Slist1 opformals_variantOPis_1 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPis_1 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_variantOPis_1_data = {0, 14, "variant$is_1", "variant", 0, 1, variantOPis_1, 1, (const Vlist0 *)&vals_variantOPis_1, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPis_1};
const struct dbg_info * const dbg_info_variantOPis_1 = (const struct dbg_info *)&dbg_info_variantOPis_1_data;

extern errcode variantOPis_2();
const Slist1 opformals_variantOPis_2 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPis_2 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_variantOPis_2_data = {0, 14, "variant$is_2", "variant", 0, 1, variantOPis_2, 1, (const Vlist0 *)&vals_variantOPis_2, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPis_2};
const struct dbg_info * const dbg_info_variantOPis_2 = (const struct dbg_info *)&dbg_info_variantOPis_2_data;

extern errcode variantOPis_3();
const Slist1 opformals_variantOPis_3 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPis_3 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_variantOPis_3_data = {0, 14, "variant$is_3", "variant", 0, 1, variantOPis_3, 1, (const Vlist0 *)&vals_variantOPis_3, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPis_3};
const struct dbg_info * const dbg_info_variantOPis_3 = (const struct dbg_info *)&dbg_info_variantOPis_3_data;

extern errcode variantOPis_4();
const Slist1 opformals_variantOPis_4 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPis_4 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_variantOPis_4_data = {0, 14, "variant$is_4", "variant", 0, 1, variantOPis_4, 1, (const Vlist0 *)&vals_variantOPis_4, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPis_4};
const struct dbg_info * const dbg_info_variantOPis_4 = (const struct dbg_info *)&dbg_info_variantOPis_4_data;

extern errcode variantOPis_5();
const Slist1 opformals_variantOPis_5 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPis_5 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_variantOPis_5_data = {0, 14, "variant$is_5", "variant", 0, 1, variantOPis_5, 1, (const Vlist0 *)&vals_variantOPis_5, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPis_5};
const struct dbg_info * const dbg_info_variantOPis_5 = (const struct dbg_info *)&dbg_info_variantOPis_5_data;

extern errcode variantOPis_6();
const Slist1 opformals_variantOPis_6 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPis_6 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_variantOPis_6_data = {0, 14, "variant$is_6", "variant", 0, 1, variantOPis_6, 1, (const Vlist0 *)&vals_variantOPis_6, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPis_6};
const struct dbg_info * const dbg_info_variantOPis_6 = (const struct dbg_info *)&dbg_info_variantOPis_6_data;

extern errcode variantOPis_7();
const Slist1 opformals_variantOPis_7 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPis_7 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_variantOPis_7_data = {0, 14, "variant$is_7", "variant", 0, 1, variantOPis_7, 1, (const Vlist0 *)&vals_variantOPis_7, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPis_7};
const struct dbg_info * const dbg_info_variantOPis_7 = (const struct dbg_info *)&dbg_info_variantOPis_7_data;

extern errcode variantOPis_8();
const Slist1 opformals_variantOPis_8 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPis_8 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_variantOPis_8_data = {0, 14, "variant$is_8", "variant", 0, 1, variantOPis_8, 1, (const Vlist0 *)&vals_variantOPis_8, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPis_8};
const struct dbg_info * const dbg_info_variantOPis_8 = (const struct dbg_info *)&dbg_info_variantOPis_8_data;

extern errcode variantOPis_9();
const Slist1 opformals_variantOPis_9 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPis_9 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_variantOPis_9_data = {0, 14, "variant$is_9", "variant", 0, 1, variantOPis_9, 1, (const Vlist0 *)&vals_variantOPis_9, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPis_9};
const struct dbg_info * const dbg_info_variantOPis_9 = (const struct dbg_info *)&dbg_info_variantOPis_9_data;

extern errcode variantOPis_10();
const Slist1 opformals_variantOPis_10 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPis_10 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_variantOPis_10_data = {0, 14, "variant$is_10", "variant", 0, 1, variantOPis_10, 1, (const Vlist0 *)&vals_variantOPis_10, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPis_10};
const struct dbg_info * const dbg_info_variantOPis_10 = (const struct dbg_info *)&dbg_info_variantOPis_10_data;

extern errcode variantOPvalue_1();
const Slist1 opformals_variantOPvalue_1 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPvalue_1 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_variantOPvalue_1_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_variantOPvalue_1 = {0, 1, {(const sig_desc *)&sig_variantOPvalue_1_1}};
const dbg_info_generic dbg_info_variantOPvalue_1_data = {0, 14, "variant$value_1", "variant", 0, 1, variantOPvalue_1, 1, (const Vlist0 *)&vals_variantOPvalue_1, (const siglist0 *)&sigs_variantOPvalue_1,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPvalue_1};
const struct dbg_info * const dbg_info_variantOPvalue_1 = (const struct dbg_info *)&dbg_info_variantOPvalue_1_data;

extern errcode variantOPvalue_2();
const Slist1 opformals_variantOPvalue_2 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPvalue_2 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_variantOPvalue_2_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_variantOPvalue_2 = {0, 1, {(const sig_desc *)&sig_variantOPvalue_2_1}};
const dbg_info_generic dbg_info_variantOPvalue_2_data = {0, 14, "variant$value_2", "variant", 0, 1, variantOPvalue_2, 1, (const Vlist0 *)&vals_variantOPvalue_2, (const siglist0 *)&sigs_variantOPvalue_2,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPvalue_2};
const struct dbg_info * const dbg_info_variantOPvalue_2 = (const struct dbg_info *)&dbg_info_variantOPvalue_2_data;

extern errcode variantOPvalue_3();
const Slist1 opformals_variantOPvalue_3 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPvalue_3 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_variantOPvalue_3_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_variantOPvalue_3 = {0, 1, {(const sig_desc *)&sig_variantOPvalue_3_1}};
const dbg_info_generic dbg_info_variantOPvalue_3_data = {0, 14, "variant$value_3", "variant", 0, 1, variantOPvalue_3, 1, (const Vlist0 *)&vals_variantOPvalue_3, (const siglist0 *)&sigs_variantOPvalue_3,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPvalue_3};
const struct dbg_info * const dbg_info_variantOPvalue_3 = (const struct dbg_info *)&dbg_info_variantOPvalue_3_data;

extern errcode variantOPvalue_4();
const Slist1 opformals_variantOPvalue_4 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPvalue_4 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_variantOPvalue_4_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_variantOPvalue_4 = {0, 1, {(const sig_desc *)&sig_variantOPvalue_4_1}};
const dbg_info_generic dbg_info_variantOPvalue_4_data = {0, 14, "variant$value_4", "variant", 0, 1, variantOPvalue_4, 1, (const Vlist0 *)&vals_variantOPvalue_4, (const siglist0 *)&sigs_variantOPvalue_4,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPvalue_4};
const struct dbg_info * const dbg_info_variantOPvalue_4 = (const struct dbg_info *)&dbg_info_variantOPvalue_4_data;

extern errcode variantOPvalue_5();
const Slist1 opformals_variantOPvalue_5 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPvalue_5 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_variantOPvalue_5_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_variantOPvalue_5 = {0, 1, {(const sig_desc *)&sig_variantOPvalue_5_1}};
const dbg_info_generic dbg_info_variantOPvalue_5_data = {0, 14, "variant$value_5", "variant", 0, 1, variantOPvalue_5, 1, (const Vlist0 *)&vals_variantOPvalue_5, (const siglist0 *)&sigs_variantOPvalue_5,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPvalue_5};
const struct dbg_info * const dbg_info_variantOPvalue_5 = (const struct dbg_info *)&dbg_info_variantOPvalue_5_data;

extern errcode variantOPvalue_6();
const Slist1 opformals_variantOPvalue_6 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPvalue_6 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_variantOPvalue_6_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_variantOPvalue_6 = {0, 1, {(const sig_desc *)&sig_variantOPvalue_6_1}};
const dbg_info_generic dbg_info_variantOPvalue_6_data = {0, 14, "variant$value_6", "variant", 0, 1, variantOPvalue_6, 1, (const Vlist0 *)&vals_variantOPvalue_6, (const siglist0 *)&sigs_variantOPvalue_6,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPvalue_6};
const struct dbg_info * const dbg_info_variantOPvalue_6 = (const struct dbg_info *)&dbg_info_variantOPvalue_6_data;

extern errcode variantOPvalue_7();
const Slist1 opformals_variantOPvalue_7 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPvalue_7 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_variantOPvalue_7_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_variantOPvalue_7 = {0, 1, {(const sig_desc *)&sig_variantOPvalue_7_1}};
const dbg_info_generic dbg_info_variantOPvalue_7_data = {0, 14, "variant$value_7", "variant", 0, 1, variantOPvalue_7, 1, (const Vlist0 *)&vals_variantOPvalue_7, (const siglist0 *)&sigs_variantOPvalue_7,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPvalue_7};
const struct dbg_info * const dbg_info_variantOPvalue_7 = (const struct dbg_info *)&dbg_info_variantOPvalue_7_data;

extern errcode variantOPvalue_8();
const Slist1 opformals_variantOPvalue_8 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPvalue_8 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_variantOPvalue_8_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_variantOPvalue_8 = {0, 1, {(const sig_desc *)&sig_variantOPvalue_8_1}};
const dbg_info_generic dbg_info_variantOPvalue_8_data = {0, 14, "variant$value_8", "variant", 0, 1, variantOPvalue_8, 1, (const Vlist0 *)&vals_variantOPvalue_8, (const siglist0 *)&sigs_variantOPvalue_8,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPvalue_8};
const struct dbg_info * const dbg_info_variantOPvalue_8 = (const struct dbg_info *)&dbg_info_variantOPvalue_8_data;

extern errcode variantOPvalue_9();
const Slist1 opformals_variantOPvalue_9 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPvalue_9 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_variantOPvalue_9_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_variantOPvalue_9 = {0, 1, {(const sig_desc *)&sig_variantOPvalue_9_1}};
const dbg_info_generic dbg_info_variantOPvalue_9_data = {0, 14, "variant$value_9", "variant", 0, 1, variantOPvalue_9, 1, (const Vlist0 *)&vals_variantOPvalue_9, (const siglist0 *)&sigs_variantOPvalue_9,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPvalue_9};
const struct dbg_info * const dbg_info_variantOPvalue_9 = (const struct dbg_info *)&dbg_info_variantOPvalue_9_data;

extern errcode variantOPvalue_10();
const Slist1 opformals_variantOPvalue_10 = {0, 1, {"t"}};
static const Vlist1 vals_variantOPvalue_10 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
static const sig_desc0 sig_variantOPvalue_10_1 = {0, 2, "wrong_tag", {0,0}};
static const siglist1 sigs_variantOPvalue_10 = {0, 1, {(const sig_desc *)&sig_variantOPvalue_10_1}};
const dbg_info_generic dbg_info_variantOPvalue_10_data = {0, 14, "variant$value_10", "variant", 0, 1, variantOPvalue_10, 1, (const Vlist0 *)&vals_variantOPvalue_10, (const siglist0 *)&sigs_variantOPvalue_10,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_variantOPvalue_10};
const struct dbg_info * const dbg_info_variantOPvalue_10 = (const struct dbg_info *)&dbg_info_variantOPvalue_10_data;

extern errcode variantOPv_gets_v();
const dbg_info_generic dbg_info_variantOPv_gets_v_data = {0, 14, "variant$v_gets_v", "variant", 0, 0, variantOPv_gets_v, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_variantOPv_gets_v = (const struct dbg_info *)&dbg_info_variantOPv_gets_v_data;

extern errcode variantOPequal();
static const Vlist1 vals_variantOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_variantOPequal_data = {0, 14, "variant$equal", "variant", 0, 0, variantOPequal, 2, (const Vlist0 *)&vals_variantOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_variantOPequal = (const struct dbg_info *)&dbg_info_variantOPequal_data;

extern errcode variantOPsimilar();
static const Vlist1 vals_variantOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_variantOPsimilar_data = {0, 14, "variant$similar", "variant", 0, 0, variantOPsimilar, 2, (const Vlist0 *)&vals_variantOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_variantOPsimilar = (const struct dbg_info *)&dbg_info_variantOPsimilar_data;

extern errcode variantOPsimilar1();
static const Vlist1 vals_variantOPsimilar1 = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_variantOPsimilar1_data = {0, 14, "variant$similar1", "variant", 0, 0, variantOPsimilar1, 2, (const Vlist0 *)&vals_variantOPsimilar1, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_variantOPsimilar1 = (const struct dbg_info *)&dbg_info_variantOPsimilar1_data;

extern errcode variantOPcopy();
static const Vlist1 vals_variantOPcopy = {0, 1, {{0, 3, "", zero_ops, "vt_ops"}}};
const dbg_info_generic dbg_info_variantOPcopy_data = {0, 14, "variant$copy", "variant", 0, 0, variantOPcopy, 1, (const Vlist0 *)&vals_variantOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_variantOPcopy = (const struct dbg_info *)&dbg_info_variantOPcopy_data;

extern errcode variantOPcopy1();
static const Vlist1 vals_variantOPcopy1 = {0, 1, {{0, 3, "", zero_ops, "vt_ops"}}};
const dbg_info_generic dbg_info_variantOPcopy1_data = {0, 14, "variant$copy1", "variant", 0, 0, variantOPcopy1, 1, (const Vlist0 *)&vals_variantOPcopy1, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_variantOPcopy1 = (const struct dbg_info *)&dbg_info_variantOPcopy1_data;

extern errcode variantOPprint();
const dbg_info_generic dbg_info_variantOPprint_data = {0, 14, "variant$print", "variant", 0, 0, variantOPprint, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_variantOPprint = (const struct dbg_info *)&dbg_info_variantOPprint_data;

extern errcode _change_owner();
static const sig_desc1 sig__change_owner_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs__change_owner = {0, 1, {(const sig_desc *)&sig__change_owner_1}};
const dbg_info_generic dbg_info__change_owner_data = {0, 14, "_change_owner", "_change_owner", 0, 0, _change_owner, 3, &NO_VALS, (const siglist0 *)&sigs__change_owner,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__change_owner = (const struct dbg_info *)&dbg_info__change_owner_data;

extern errcode i_rotate();
static const Vlist1 vals_i_rotate = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_i_rotate_1 = {0, 2, "overflow", {0,0}};
static const siglist1 sigs_i_rotate = {0, 1, {(const sig_desc *)&sig_i_rotate_1}};
const dbg_info_generic dbg_info_i_rotate_data = {0, 14, "i_rotate", "i_rotate", 0, 0, i_rotate, 2, (const Vlist0 *)&vals_i_rotate, (const siglist0 *)&sigs_i_rotate,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_i_rotate = (const struct dbg_info *)&dbg_info_i_rotate_data;

extern errcode create_directory();
static const sig_desc1 sig_create_directory_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs_create_directory = {0, 1, {(const sig_desc *)&sig_create_directory_1}};
const dbg_info_generic dbg_info_create_directory_data = {0, 14, "create_directory", "create_directory", 0, 0, create_directory, 2, &NO_VALS, (const siglist0 *)&sigs_create_directory,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_create_directory = (const struct dbg_info *)&dbg_info_create_directory_data;

extern errcode structOPcreate();
static const Vlist1 vals_structOPcreate = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPcreate_data = {0, 14, "struct$create", "struct", 0, 0, structOPcreate, 1, (const Vlist0 *)&vals_structOPcreate, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_structOPcreate = (const struct dbg_info *)&dbg_info_structOPcreate_data;

extern errcode structOPget_1();
const Slist1 opformals_structOPget_1 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_1 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_1_data = {0, 14, "struct$get_1", "struct", 0, 1, structOPget_1, 1, (const Vlist0 *)&vals_structOPget_1, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_1};
const struct dbg_info * const dbg_info_structOPget_1 = (const struct dbg_info *)&dbg_info_structOPget_1_data;

extern errcode structOPget_2();
const Slist1 opformals_structOPget_2 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_2 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_2_data = {0, 14, "struct$get_2", "struct", 0, 1, structOPget_2, 1, (const Vlist0 *)&vals_structOPget_2, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_2};
const struct dbg_info * const dbg_info_structOPget_2 = (const struct dbg_info *)&dbg_info_structOPget_2_data;

extern errcode structOPget_3();
const Slist1 opformals_structOPget_3 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_3 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_3_data = {0, 14, "struct$get_3", "struct", 0, 1, structOPget_3, 1, (const Vlist0 *)&vals_structOPget_3, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_3};
const struct dbg_info * const dbg_info_structOPget_3 = (const struct dbg_info *)&dbg_info_structOPget_3_data;

extern errcode structOPget_4();
const Slist1 opformals_structOPget_4 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_4 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_4_data = {0, 14, "struct$get_4", "struct", 0, 1, structOPget_4, 1, (const Vlist0 *)&vals_structOPget_4, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_4};
const struct dbg_info * const dbg_info_structOPget_4 = (const struct dbg_info *)&dbg_info_structOPget_4_data;

extern errcode structOPget_5();
const Slist1 opformals_structOPget_5 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_5 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_5_data = {0, 14, "struct$get_5", "struct", 0, 1, structOPget_5, 1, (const Vlist0 *)&vals_structOPget_5, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_5};
const struct dbg_info * const dbg_info_structOPget_5 = (const struct dbg_info *)&dbg_info_structOPget_5_data;

extern errcode structOPget_6();
const Slist1 opformals_structOPget_6 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_6 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_6_data = {0, 14, "struct$get_6", "struct", 0, 1, structOPget_6, 1, (const Vlist0 *)&vals_structOPget_6, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_6};
const struct dbg_info * const dbg_info_structOPget_6 = (const struct dbg_info *)&dbg_info_structOPget_6_data;

extern errcode structOPget_7();
const Slist1 opformals_structOPget_7 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_7 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_7_data = {0, 14, "struct$get_7", "struct", 0, 1, structOPget_7, 1, (const Vlist0 *)&vals_structOPget_7, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_7};
const struct dbg_info * const dbg_info_structOPget_7 = (const struct dbg_info *)&dbg_info_structOPget_7_data;

extern errcode structOPget_8();
const Slist1 opformals_structOPget_8 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_8 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_8_data = {0, 14, "struct$get_8", "struct", 0, 1, structOPget_8, 1, (const Vlist0 *)&vals_structOPget_8, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_8};
const struct dbg_info * const dbg_info_structOPget_8 = (const struct dbg_info *)&dbg_info_structOPget_8_data;

extern errcode structOPget_9();
const Slist1 opformals_structOPget_9 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_9 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_9_data = {0, 14, "struct$get_9", "struct", 0, 1, structOPget_9, 1, (const Vlist0 *)&vals_structOPget_9, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_9};
const struct dbg_info * const dbg_info_structOPget_9 = (const struct dbg_info *)&dbg_info_structOPget_9_data;

extern errcode structOPget_10();
const Slist1 opformals_structOPget_10 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_10 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_10_data = {0, 14, "struct$get_10", "struct", 0, 1, structOPget_10, 1, (const Vlist0 *)&vals_structOPget_10, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_10};
const struct dbg_info * const dbg_info_structOPget_10 = (const struct dbg_info *)&dbg_info_structOPget_10_data;

extern errcode structOPget_11();
const Slist1 opformals_structOPget_11 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_11 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_11_data = {0, 14, "struct$get_11", "struct", 0, 1, structOPget_11, 1, (const Vlist0 *)&vals_structOPget_11, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_11};
const struct dbg_info * const dbg_info_structOPget_11 = (const struct dbg_info *)&dbg_info_structOPget_11_data;

extern errcode structOPget_12();
const Slist1 opformals_structOPget_12 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_12 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_12_data = {0, 14, "struct$get_12", "struct", 0, 1, structOPget_12, 1, (const Vlist0 *)&vals_structOPget_12, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_12};
const struct dbg_info * const dbg_info_structOPget_12 = (const struct dbg_info *)&dbg_info_structOPget_12_data;

extern errcode structOPget_13();
const Slist1 opformals_structOPget_13 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_13 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_13_data = {0, 14, "struct$get_13", "struct", 0, 1, structOPget_13, 1, (const Vlist0 *)&vals_structOPget_13, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_13};
const struct dbg_info * const dbg_info_structOPget_13 = (const struct dbg_info *)&dbg_info_structOPget_13_data;

extern errcode structOPget_14();
const Slist1 opformals_structOPget_14 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_14 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_14_data = {0, 14, "struct$get_14", "struct", 0, 1, structOPget_14, 1, (const Vlist0 *)&vals_structOPget_14, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_14};
const struct dbg_info * const dbg_info_structOPget_14 = (const struct dbg_info *)&dbg_info_structOPget_14_data;

extern errcode structOPget_15();
const Slist1 opformals_structOPget_15 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_15 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_15_data = {0, 14, "struct$get_15", "struct", 0, 1, structOPget_15, 1, (const Vlist0 *)&vals_structOPget_15, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_15};
const struct dbg_info * const dbg_info_structOPget_15 = (const struct dbg_info *)&dbg_info_structOPget_15_data;

extern errcode structOPget_16();
const Slist1 opformals_structOPget_16 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_16 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_16_data = {0, 14, "struct$get_16", "struct", 0, 1, structOPget_16, 1, (const Vlist0 *)&vals_structOPget_16, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_16};
const struct dbg_info * const dbg_info_structOPget_16 = (const struct dbg_info *)&dbg_info_structOPget_16_data;

extern errcode structOPget_17();
const Slist1 opformals_structOPget_17 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_17 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_17_data = {0, 14, "struct$get_17", "struct", 0, 1, structOPget_17, 1, (const Vlist0 *)&vals_structOPget_17, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_17};
const struct dbg_info * const dbg_info_structOPget_17 = (const struct dbg_info *)&dbg_info_structOPget_17_data;

extern errcode structOPget_18();
const Slist1 opformals_structOPget_18 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_18 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_18_data = {0, 14, "struct$get_18", "struct", 0, 1, structOPget_18, 1, (const Vlist0 *)&vals_structOPget_18, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_18};
const struct dbg_info * const dbg_info_structOPget_18 = (const struct dbg_info *)&dbg_info_structOPget_18_data;

extern errcode structOPget_19();
const Slist1 opformals_structOPget_19 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_19 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_19_data = {0, 14, "struct$get_19", "struct", 0, 1, structOPget_19, 1, (const Vlist0 *)&vals_structOPget_19, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_19};
const struct dbg_info * const dbg_info_structOPget_19 = (const struct dbg_info *)&dbg_info_structOPget_19_data;

extern errcode structOPget_20();
const Slist1 opformals_structOPget_20 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_20 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_20_data = {0, 14, "struct$get_20", "struct", 0, 1, structOPget_20, 1, (const Vlist0 *)&vals_structOPget_20, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_20};
const struct dbg_info * const dbg_info_structOPget_20 = (const struct dbg_info *)&dbg_info_structOPget_20_data;

extern errcode structOPget_21();
const Slist1 opformals_structOPget_21 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_21 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_21_data = {0, 14, "struct$get_21", "struct", 0, 1, structOPget_21, 1, (const Vlist0 *)&vals_structOPget_21, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_21};
const struct dbg_info * const dbg_info_structOPget_21 = (const struct dbg_info *)&dbg_info_structOPget_21_data;

extern errcode structOPget_22();
const Slist1 opformals_structOPget_22 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_22 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_22_data = {0, 14, "struct$get_22", "struct", 0, 1, structOPget_22, 1, (const Vlist0 *)&vals_structOPget_22, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_22};
const struct dbg_info * const dbg_info_structOPget_22 = (const struct dbg_info *)&dbg_info_structOPget_22_data;

extern errcode structOPget_23();
const Slist1 opformals_structOPget_23 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_23 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_23_data = {0, 14, "struct$get_23", "struct", 0, 1, structOPget_23, 1, (const Vlist0 *)&vals_structOPget_23, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_23};
const struct dbg_info * const dbg_info_structOPget_23 = (const struct dbg_info *)&dbg_info_structOPget_23_data;

extern errcode structOPget_24();
const Slist1 opformals_structOPget_24 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_24 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_24_data = {0, 14, "struct$get_24", "struct", 0, 1, structOPget_24, 1, (const Vlist0 *)&vals_structOPget_24, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_24};
const struct dbg_info * const dbg_info_structOPget_24 = (const struct dbg_info *)&dbg_info_structOPget_24_data;

extern errcode structOPget_25();
const Slist1 opformals_structOPget_25 = {0, 1, {"t"}};
static const Vlist1 vals_structOPget_25 = {0, 1, {{0, 3, "", zero_ops, "t_ops"}}};
const dbg_info_generic dbg_info_structOPget_25_data = {0, 14, "struct$get_25", "struct", 0, 1, structOPget_25, 1, (const Vlist0 *)&vals_structOPget_25, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPget_25};
const struct dbg_info * const dbg_info_structOPget_25 = (const struct dbg_info *)&dbg_info_structOPget_25_data;

extern errcode structOPreplace_1();
const Slist1 opformals_structOPreplace_1 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_1 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_1_data = {0, 14, "struct$replace_1", "struct", 0, 1, structOPreplace_1, 2, (const Vlist0 *)&vals_structOPreplace_1, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_1};
const struct dbg_info * const dbg_info_structOPreplace_1 = (const struct dbg_info *)&dbg_info_structOPreplace_1_data;

extern errcode structOPreplace_2();
const Slist1 opformals_structOPreplace_2 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_2 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_2_data = {0, 14, "struct$replace_2", "struct", 0, 1, structOPreplace_2, 2, (const Vlist0 *)&vals_structOPreplace_2, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_2};
const struct dbg_info * const dbg_info_structOPreplace_2 = (const struct dbg_info *)&dbg_info_structOPreplace_2_data;

extern errcode structOPreplace_3();
const Slist1 opformals_structOPreplace_3 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_3 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_3_data = {0, 14, "struct$replace_3", "struct", 0, 1, structOPreplace_3, 2, (const Vlist0 *)&vals_structOPreplace_3, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_3};
const struct dbg_info * const dbg_info_structOPreplace_3 = (const struct dbg_info *)&dbg_info_structOPreplace_3_data;

extern errcode structOPreplace_4();
const Slist1 opformals_structOPreplace_4 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_4 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_4_data = {0, 14, "struct$replace_4", "struct", 0, 1, structOPreplace_4, 2, (const Vlist0 *)&vals_structOPreplace_4, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_4};
const struct dbg_info * const dbg_info_structOPreplace_4 = (const struct dbg_info *)&dbg_info_structOPreplace_4_data;

extern errcode structOPreplace_5();
const Slist1 opformals_structOPreplace_5 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_5 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_5_data = {0, 14, "struct$replace_5", "struct", 0, 1, structOPreplace_5, 2, (const Vlist0 *)&vals_structOPreplace_5, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_5};
const struct dbg_info * const dbg_info_structOPreplace_5 = (const struct dbg_info *)&dbg_info_structOPreplace_5_data;

extern errcode structOPreplace_6();
const Slist1 opformals_structOPreplace_6 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_6 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_6_data = {0, 14, "struct$replace_6", "struct", 0, 1, structOPreplace_6, 2, (const Vlist0 *)&vals_structOPreplace_6, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_6};
const struct dbg_info * const dbg_info_structOPreplace_6 = (const struct dbg_info *)&dbg_info_structOPreplace_6_data;

extern errcode structOPreplace_7();
const Slist1 opformals_structOPreplace_7 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_7 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_7_data = {0, 14, "struct$replace_7", "struct", 0, 1, structOPreplace_7, 2, (const Vlist0 *)&vals_structOPreplace_7, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_7};
const struct dbg_info * const dbg_info_structOPreplace_7 = (const struct dbg_info *)&dbg_info_structOPreplace_7_data;

extern errcode structOPreplace_8();
const Slist1 opformals_structOPreplace_8 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_8 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_8_data = {0, 14, "struct$replace_8", "struct", 0, 1, structOPreplace_8, 2, (const Vlist0 *)&vals_structOPreplace_8, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_8};
const struct dbg_info * const dbg_info_structOPreplace_8 = (const struct dbg_info *)&dbg_info_structOPreplace_8_data;

extern errcode structOPreplace_9();
const Slist1 opformals_structOPreplace_9 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_9 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_9_data = {0, 14, "struct$replace_9", "struct", 0, 1, structOPreplace_9, 2, (const Vlist0 *)&vals_structOPreplace_9, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_9};
const struct dbg_info * const dbg_info_structOPreplace_9 = (const struct dbg_info *)&dbg_info_structOPreplace_9_data;

extern errcode structOPreplace_10();
const Slist1 opformals_structOPreplace_10 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_10 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_10_data = {0, 14, "struct$replace_10", "struct", 0, 1, structOPreplace_10, 2, (const Vlist0 *)&vals_structOPreplace_10, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_10};
const struct dbg_info * const dbg_info_structOPreplace_10 = (const struct dbg_info *)&dbg_info_structOPreplace_10_data;

extern errcode structOPreplace_11();
const Slist1 opformals_structOPreplace_11 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_11 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_11_data = {0, 14, "struct$replace_11", "struct", 0, 1, structOPreplace_11, 2, (const Vlist0 *)&vals_structOPreplace_11, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_11};
const struct dbg_info * const dbg_info_structOPreplace_11 = (const struct dbg_info *)&dbg_info_structOPreplace_11_data;

extern errcode structOPreplace_12();
const Slist1 opformals_structOPreplace_12 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_12 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_12_data = {0, 14, "struct$replace_12", "struct", 0, 1, structOPreplace_12, 2, (const Vlist0 *)&vals_structOPreplace_12, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_12};
const struct dbg_info * const dbg_info_structOPreplace_12 = (const struct dbg_info *)&dbg_info_structOPreplace_12_data;

extern errcode structOPreplace_13();
const Slist1 opformals_structOPreplace_13 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_13 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_13_data = {0, 14, "struct$replace_13", "struct", 0, 1, structOPreplace_13, 2, (const Vlist0 *)&vals_structOPreplace_13, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_13};
const struct dbg_info * const dbg_info_structOPreplace_13 = (const struct dbg_info *)&dbg_info_structOPreplace_13_data;

extern errcode structOPreplace_14();
const Slist1 opformals_structOPreplace_14 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_14 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_14_data = {0, 14, "struct$replace_14", "struct", 0, 1, structOPreplace_14, 2, (const Vlist0 *)&vals_structOPreplace_14, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_14};
const struct dbg_info * const dbg_info_structOPreplace_14 = (const struct dbg_info *)&dbg_info_structOPreplace_14_data;

extern errcode structOPreplace_15();
const Slist1 opformals_structOPreplace_15 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_15 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_15_data = {0, 14, "struct$replace_15", "struct", 0, 1, structOPreplace_15, 2, (const Vlist0 *)&vals_structOPreplace_15, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_15};
const struct dbg_info * const dbg_info_structOPreplace_15 = (const struct dbg_info *)&dbg_info_structOPreplace_15_data;

extern errcode structOPreplace_16();
const Slist1 opformals_structOPreplace_16 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_16 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_16_data = {0, 14, "struct$replace_16", "struct", 0, 1, structOPreplace_16, 2, (const Vlist0 *)&vals_structOPreplace_16, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_16};
const struct dbg_info * const dbg_info_structOPreplace_16 = (const struct dbg_info *)&dbg_info_structOPreplace_16_data;

extern errcode structOPreplace_17();
const Slist1 opformals_structOPreplace_17 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_17 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_17_data = {0, 14, "struct$replace_17", "struct", 0, 1, structOPreplace_17, 2, (const Vlist0 *)&vals_structOPreplace_17, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_17};
const struct dbg_info * const dbg_info_structOPreplace_17 = (const struct dbg_info *)&dbg_info_structOPreplace_17_data;

extern errcode structOPreplace_18();
const Slist1 opformals_structOPreplace_18 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_18 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_18_data = {0, 14, "struct$replace_18", "struct", 0, 1, structOPreplace_18, 2, (const Vlist0 *)&vals_structOPreplace_18, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_18};
const struct dbg_info * const dbg_info_structOPreplace_18 = (const struct dbg_info *)&dbg_info_structOPreplace_18_data;

extern errcode structOPreplace_19();
const Slist1 opformals_structOPreplace_19 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_19 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_19_data = {0, 14, "struct$replace_19", "struct", 0, 1, structOPreplace_19, 2, (const Vlist0 *)&vals_structOPreplace_19, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_19};
const struct dbg_info * const dbg_info_structOPreplace_19 = (const struct dbg_info *)&dbg_info_structOPreplace_19_data;

extern errcode structOPreplace_20();
const Slist1 opformals_structOPreplace_20 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_20 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_20_data = {0, 14, "struct$replace_20", "struct", 0, 1, structOPreplace_20, 2, (const Vlist0 *)&vals_structOPreplace_20, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_20};
const struct dbg_info * const dbg_info_structOPreplace_20 = (const struct dbg_info *)&dbg_info_structOPreplace_20_data;

extern errcode structOPreplace_21();
const Slist1 opformals_structOPreplace_21 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_21 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_21_data = {0, 14, "struct$replace_21", "struct", 0, 1, structOPreplace_21, 2, (const Vlist0 *)&vals_structOPreplace_21, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_21};
const struct dbg_info * const dbg_info_structOPreplace_21 = (const struct dbg_info *)&dbg_info_structOPreplace_21_data;

extern errcode structOPreplace_22();
const Slist1 opformals_structOPreplace_22 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_22 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_22_data = {0, 14, "struct$replace_22", "struct", 0, 1, structOPreplace_22, 2, (const Vlist0 *)&vals_structOPreplace_22, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_22};
const struct dbg_info * const dbg_info_structOPreplace_22 = (const struct dbg_info *)&dbg_info_structOPreplace_22_data;

extern errcode structOPreplace_23();
const Slist1 opformals_structOPreplace_23 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_23 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_23_data = {0, 14, "struct$replace_23", "struct", 0, 1, structOPreplace_23, 2, (const Vlist0 *)&vals_structOPreplace_23, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_23};
const struct dbg_info * const dbg_info_structOPreplace_23 = (const struct dbg_info *)&dbg_info_structOPreplace_23_data;

extern errcode structOPreplace_24();
const Slist1 opformals_structOPreplace_24 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_24 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_24_data = {0, 14, "struct$replace_24", "struct", 0, 1, structOPreplace_24, 2, (const Vlist0 *)&vals_structOPreplace_24, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_24};
const struct dbg_info * const dbg_info_structOPreplace_24 = (const struct dbg_info *)&dbg_info_structOPreplace_24_data;

extern errcode structOPreplace_25();
const Slist1 opformals_structOPreplace_25 = {0, 1, {"t"}};
static const Vlist1 vals_structOPreplace_25 = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPreplace_25_data = {0, 14, "struct$replace_25", "struct", 0, 1, structOPreplace_25, 2, (const Vlist0 *)&vals_structOPreplace_25, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,(Slist0*)&opformals_structOPreplace_25};
const struct dbg_info * const dbg_info_structOPreplace_25 = (const struct dbg_info *)&dbg_info_structOPreplace_25_data;

extern errcode structOPequal();
static const Vlist1 vals_structOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_structOPequal_data = {0, 14, "struct$equal", "struct", 0, 0, structOPequal, 2, (const Vlist0 *)&vals_structOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_structOPequal = (const struct dbg_info *)&dbg_info_structOPequal_data;

extern errcode structOPsimilar();
static const Vlist1 vals_structOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_structOPsimilar_data = {0, 14, "struct$similar", "struct", 0, 0, structOPsimilar, 2, (const Vlist0 *)&vals_structOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_structOPsimilar = (const struct dbg_info *)&dbg_info_structOPsimilar_data;

extern errcode structOPcopy();
static const Vlist1 vals_structOPcopy = {0, 1, {{0, 3, "", zero_ops, "st_ops"}}};
const dbg_info_generic dbg_info_structOPcopy_data = {0, 14, "struct$copy", "struct", 0, 0, structOPcopy, 1, (const Vlist0 *)&vals_structOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_structOPcopy = (const struct dbg_info *)&dbg_info_structOPcopy_data;

extern errcode structOPprint();
const dbg_info_generic dbg_info_structOPprint_data = {0, 14, "struct$print", "struct", 0, 0, structOPprint, 2, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_structOPprint = (const struct dbg_info *)&dbg_info_structOPprint_data;

extern errcode _round_real();
static const Vlist2 vals__round_real = {0, 2, {{0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__round_real_data = {0, 14, "_round_real", "_round_real", 0, 0, _round_real, 2, (const Vlist0 *)&vals__round_real, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__round_real = (const struct dbg_info *)&dbg_info__round_real_data;

extern errcode randomOPreset();
const dbg_info_generic dbg_info_randomOPreset_data = {0, 14, "random$reset", "random", 0, 0, randomOPreset, 0, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_randomOPreset = (const struct dbg_info *)&dbg_info_randomOPreset_data;

extern errcode randomOPseed();
const dbg_info_generic dbg_info_randomOPseed_data = {0, 14, "random$seed", "random", 0, 0, randomOPseed, 1, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_randomOPseed = (const struct dbg_info *)&dbg_info_randomOPseed_data;

extern errcode randomOPnext();
static const Vlist1 vals_randomOPnext = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_randomOPnext_data = {0, 14, "random$next", "random", 0, 0, randomOPnext, 1, (const Vlist0 *)&vals_randomOPnext, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_randomOPnext = (const struct dbg_info *)&dbg_info_randomOPnext_data;

const Slist1 tformals_proctype = {0, 1, {"pt"}};
extern errcode proctypeOPequal();
static const Vlist1 vals_proctypeOPequal = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_proctypeOPequal_data = {0, 14, "proctype$equal", "proctype", 0, 2, proctypeOPequal, 2, (const Vlist0 *)&vals_proctypeOPequal, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_proctype,&NO_PARMS};
const struct dbg_info * const dbg_info_proctypeOPequal = (const struct dbg_info *)&dbg_info_proctypeOPequal_data;

extern errcode proctypeOPsimilar();
static const Vlist1 vals_proctypeOPsimilar = {0, 1, {{0, 2, "", &bool_ops, ""}}};
const dbg_info_generic dbg_info_proctypeOPsimilar_data = {0, 14, "proctype$similar", "proctype", 0, 2, proctypeOPsimilar, 2, (const Vlist0 *)&vals_proctypeOPsimilar, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_proctype,&NO_PARMS};
const struct dbg_info * const dbg_info_proctypeOPsimilar = (const struct dbg_info *)&dbg_info_proctypeOPsimilar_data;

extern errcode proctypeOPcopy();
static const Vlist1 vals_proctypeOPcopy = {0, 1, {{0, 3, "", zero_ops, "pt_ops"}}};
const dbg_info_generic dbg_info_proctypeOPcopy_data = {0, 14, "proctype$copy", "proctype", 0, 2, proctypeOPcopy, 1, (const Vlist0 *)&vals_proctypeOPcopy, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,(Slist0*)&tformals_proctype,&NO_PARMS};
const struct dbg_info * const dbg_info_proctypeOPcopy = (const struct dbg_info *)&dbg_info_proctypeOPcopy_data;

extern errcode _sleep();
const dbg_info_generic dbg_info__sleep_data = {0, 14, "_sleep", "_sleep", 0, 0, _sleep, 1, &NO_VALS, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__sleep = (const struct dbg_info *)&dbg_info__sleep_data;

extern errcode set_connected_dir();
static const sig_desc0 sig_set_connected_dir_1 = {0, 2, "bad_format", {0,0}};
static const sig_desc1 sig_set_connected_dir_2 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist2 sigs_set_connected_dir = {0, 2, {(const sig_desc *)&sig_set_connected_dir_1, (const sig_desc *)&sig_set_connected_dir_2}};
const dbg_info_generic dbg_info_set_connected_dir_data = {0, 14, "set_connected_dir", "set_connected_dir", 0, 0, set_connected_dir, 1, &NO_VALS, (const siglist0 *)&sigs_set_connected_dir,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_set_connected_dir = (const struct dbg_info *)&dbg_info_set_connected_dir_data;

extern errcode i_shift();
static const Vlist1 vals_i_shift = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_i_shift_1 = {0, 2, "overflow", {0,0}};
static const siglist1 sigs_i_shift = {0, 1, {(const sig_desc *)&sig_i_shift_1}};
const dbg_info_generic dbg_info_i_shift_data = {0, 14, "i_shift", "i_shift", 0, 0, i_shift, 2, (const Vlist0 *)&vals_i_shift, (const siglist0 *)&sigs_i_shift,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_i_shift = (const struct dbg_info *)&dbg_info_i_shift_data;

extern errcode _get_gid();
static const Vlist2 vals__get_gid = {0, 2, {{0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__get_gid_data = {0, 14, "_get_gid", "_get_gid", 0, 0, _get_gid, 0, (const Vlist0 *)&vals__get_gid, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__get_gid = (const struct dbg_info *)&dbg_info__get_gid_data;

extern errcode i_last1();
static const Vlist1 vals_i_last1 = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_i_last1_1 = {0, 2, "none", {0,0}};
static const siglist1 sigs_i_last1 = {0, 1, {(const sig_desc *)&sig_i_last1_1}};
const dbg_info_generic dbg_info_i_last1_data = {0, 14, "i_last1", "i_last1", 0, 0, i_last1, 1, (const Vlist0 *)&vals_i_last1, (const siglist0 *)&sigs_i_last1,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_i_last1 = (const struct dbg_info *)&dbg_info_i_last1_data;

extern errcode _stat();
static const sig_desc0 sig__stat_1 = {0, 2, "bounds", {0,0}};
static const sig_desc1 sig__stat_2 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist2 sigs__stat = {0, 2, {(const sig_desc *)&sig__stat_1, (const sig_desc *)&sig__stat_2}};
const dbg_info_generic dbg_info__stat_data = {0, 14, "_stat", "_stat", 0, 0, _stat, 2, &NO_VALS, (const siglist0 *)&sigs__stat,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__stat = (const struct dbg_info *)&dbg_info__stat_data;

extern errcode hash();
static const Vlist1 vals_hash = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info_hash_data = {0, 14, "hash", "hash", 0, 0, hash, 2, (const Vlist0 *)&vals_hash, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_hash = (const struct dbg_info *)&dbg_info_hash_data;

extern errcode _host_id();
static const Vlist2 vals__host_id = {0, 2, {{0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__host_id_data = {0, 14, "_host_id", "_host_id", 0, 0, _host_id, 0, (const Vlist0 *)&vals__host_id, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__host_id = (const struct dbg_info *)&dbg_info__host_id_data;

extern errcode _get_pid();
static const Vlist1 vals__get_pid = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__get_pid_data = {0, 14, "_get_pid", "_get_pid", 0, 0, _get_pid, 0, (const Vlist0 *)&vals__get_pid, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__get_pid = (const struct dbg_info *)&dbg_info__get_pid_data;

extern errcode _host_name();
static const Vlist1 vals__host_name = {0, 1, {{0, 2, "", &string_ops, ""}}};
const dbg_info_generic dbg_info__host_name_data = {0, 14, "_host_name", "_host_name", 0, 0, _host_name, 0, (const Vlist0 *)&vals__host_name, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__host_name = (const struct dbg_info *)&dbg_info__host_name_data;

extern errcode exp();
static const Vlist1 vals_exp = {0, 1, {{0, 2, "", &real_ops, ""}}};
static const sig_desc0 sig_exp_1 = {0, 2, "overflow", {0,0}};
static const sig_desc0 sig_exp_2 = {0, 2, "underflow", {0,0}};
static const siglist2 sigs_exp = {0, 2, {(const sig_desc *)&sig_exp_1, (const sig_desc *)&sig_exp_2}};
const dbg_info_generic dbg_info_exp_data = {0, 14, "exp", "exp", 0, 0, exp, 1, (const Vlist0 *)&vals_exp, (const siglist0 *)&sigs_exp,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_exp = (const struct dbg_info *)&dbg_info_exp_data;

extern errcode _get_pname();
static const Vlist1 vals__get_pname = {0, 1, {{0, 2, "", &string_ops, ""}}};
const dbg_info_generic dbg_info__get_pname_data = {0, 14, "_get_pname", "_get_pname", 0, 0, _get_pname, 0, (const Vlist0 *)&vals__get_pname, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__get_pname = (const struct dbg_info *)&dbg_info__get_pname_data;

extern errcode i_set();
static const Vlist1 vals_i_set = {0, 1, {{0, 2, "", &int_ops, ""}}};
static const sig_desc0 sig_i_set_1 = {0, 2, "bounds", {0,0}};
static const sig_desc0 sig_i_set_2 = {0, 2, "illegal_size", {0,0}};
static const sig_desc0 sig_i_set_3 = {0, 2, "overflow", {0,0}};
static const siglist3 sigs_i_set = {0, 3, {(const sig_desc *)&sig_i_set_1, (const sig_desc *)&sig_i_set_2, (const sig_desc *)&sig_i_set_3}};
const dbg_info_generic dbg_info_i_set_data = {0, 14, "i_set", "i_set", 0, 0, i_set, 4, (const Vlist0 *)&vals_i_set, (const siglist0 *)&sigs_i_set,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_i_set = (const struct dbg_info *)&dbg_info_i_set_data;

extern errcode _get_uid();
static const Vlist2 vals__get_uid = {0, 2, {{0, 2, "", &int_ops, ""}, {0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__get_uid_data = {0, 14, "_get_uid", "_get_uid", 0, 0, _get_uid, 0, (const Vlist0 *)&vals__get_uid, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__get_uid = (const struct dbg_info *)&dbg_info__get_uid_data;

extern errcode _rusage();
static const sig_desc0 sig__rusage_1 = {0, 2, "bounds", {0,0}};
static const sig_desc1 sig__rusage_2 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist2 sigs__rusage = {0, 2, {(const sig_desc *)&sig__rusage_1, (const sig_desc *)&sig__rusage_2}};
const dbg_info_generic dbg_info__rusage_data = {0, 14, "_rusage", "_rusage", 0, 0, _rusage, 2, &NO_VALS, (const siglist0 *)&sigs__rusage,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__rusage = (const struct dbg_info *)&dbg_info__rusage_data;

extern errcode symlink_file();
static const sig_desc1 sig_symlink_file_1 = {0, 2, "not_possible", {0,1, {{0, 3, "", &string_ops, ""}}}};
static const siglist1 sigs_symlink_file = {0, 1, {(const sig_desc *)&sig_symlink_file_1}};
const dbg_info_generic dbg_info_symlink_file_data = {0, 14, "symlink_file", "symlink_file", 0, 0, symlink_file, 2, &NO_VALS, (const siglist0 *)&sigs_symlink_file,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info_symlink_file = (const struct dbg_info *)&dbg_info_symlink_file_data;

extern errcode _page_size();
static const Vlist1 vals__page_size = {0, 1, {{0, 2, "", &int_ops, ""}}};
const dbg_info_generic dbg_info__page_size_data = {0, 14, "_page_size", "_page_size", 0, 0, _page_size, 0, (const Vlist0 *)&vals__page_size, &NO_SIGS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_VALS,&NO_PARMS,&NO_PARMS};
const struct dbg_info * const dbg_info__page_size = (const struct dbg_info *)&dbg_info__page_size_data;

