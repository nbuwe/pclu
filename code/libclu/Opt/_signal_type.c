
/* This file was automatically generated by pclu. */

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE _signal_type ****/

extern errcode sequenceOPfetch();
static CLUREF STR_hangup;
static CLUREF STR_interrupt;
static CLUREF STR_quit;
static CLUREF STR_illegal_040instruction;
static CLUREF STR_trace_040trap_057BPT;
static CLUREF STR_IOT_040instruction;
static CLUREF STR_EMT_040instruction;
static CLUREF STR_floating_040point_040exception;
static CLUREF STR_killed;
static CLUREF STR_bus_040error;
static CLUREF STR_segmentation_040violation;
static CLUREF STR_bad_040argument_040to_040system_040call;
static CLUREF STR_broken_040pipe;
static CLUREF STR_alarm_040clock;
static CLUREF STR_software_040termination;
static CLUREF STR_urgent_040condition;
static CLUREF STR_stop;
static CLUREF STR_stop_040_050tty_051;
static CLUREF STR_continue;
static CLUREF STR_child_040termination;
static CLUREF STR_stop_040_050tty_040input_051;
static CLUREF STR_stop_040_050tty_040output_051;
static CLUREF STR_i_057o_040possible;
static CLUREF STR_cpu_040time_040limit;
static CLUREF STR_file_040size_040limit;
static CLUREF STR_virtual_040time_040alarm;
static CLUREF STR_profiling_040timer_040alarm;
static CLUREF STR_signal_04028;
static CLUREF STR_signal_04029;
static CLUREF STR_signal_04030;
static CLUREF STR_signal_04031;
static CLUREF STR_signal_04032;
static int _signal_type_own_init = 0;

errcode
_signal_type(CLUREF sig, CLUREF *ret_1)
{
    errcode err;
    if (_signal_type_own_init == 0) {
        stringOPcons("hangup", CLU_1, CLUREF_make_num(6), &STR_hangup);
        stringOPcons("interrupt", CLU_1, CLUREF_make_num(9), &STR_interrupt);
        stringOPcons("quit", CLU_1, CLUREF_make_num(4), &STR_quit);
        stringOPcons("illegal instruction", CLU_1, CLUREF_make_num(19), &STR_illegal_040instruction);
        stringOPcons("trace trap/BPT", CLU_1, CLUREF_make_num(14), &STR_trace_040trap_057BPT);
        stringOPcons("IOT instruction", CLU_1, CLUREF_make_num(15), &STR_IOT_040instruction);
        stringOPcons("EMT instruction", CLU_1, CLUREF_make_num(15), &STR_EMT_040instruction);
        stringOPcons("floating point exception", CLU_1, CLUREF_make_num(24), &STR_floating_040point_040exception);
        stringOPcons("killed", CLU_1, CLUREF_make_num(6), &STR_killed);
        stringOPcons("bus error", CLU_1, CLUREF_make_num(9), &STR_bus_040error);
        stringOPcons("segmentation violation", CLU_1, CLUREF_make_num(22), &STR_segmentation_040violation);
        stringOPcons("bad argument to system call", CLU_1, CLUREF_make_num(27), &STR_bad_040argument_040to_040system_040call);
        stringOPcons("broken pipe", CLU_1, CLUREF_make_num(11), &STR_broken_040pipe);
        stringOPcons("alarm clock", CLU_1, CLUREF_make_num(11), &STR_alarm_040clock);
        stringOPcons("software termination", CLU_1, CLUREF_make_num(20), &STR_software_040termination);
        stringOPcons("urgent condition", CLU_1, CLUREF_make_num(16), &STR_urgent_040condition);
        stringOPcons("stop", CLU_1, CLUREF_make_num(4), &STR_stop);
        stringOPcons("stop (tty)", CLU_1, CLUREF_make_num(10), &STR_stop_040_050tty_051);
        stringOPcons("continue", CLU_1, CLUREF_make_num(8), &STR_continue);
        stringOPcons("child termination", CLU_1, CLUREF_make_num(17), &STR_child_040termination);
        stringOPcons("stop (tty input)", CLU_1, CLUREF_make_num(16), &STR_stop_040_050tty_040input_051);
        stringOPcons("stop (tty output)", CLU_1, CLUREF_make_num(17), &STR_stop_040_050tty_040output_051);
        stringOPcons("i/o possible", CLU_1, CLUREF_make_num(12), &STR_i_057o_040possible);
        stringOPcons("cpu time limit", CLU_1, CLUREF_make_num(14), &STR_cpu_040time_040limit);
        stringOPcons("file size limit", CLU_1, CLUREF_make_num(15), &STR_file_040size_040limit);
        stringOPcons("virtual time alarm", CLU_1, CLUREF_make_num(18), &STR_virtual_040time_040alarm);
        stringOPcons("profiling timer alarm", CLU_1, CLUREF_make_num(21), &STR_profiling_040timer_040alarm);
        stringOPcons("signal 28", CLU_1, CLUREF_make_num(9), &STR_signal_04028);
        stringOPcons("signal 29", CLU_1, CLUREF_make_num(9), &STR_signal_04029);
        stringOPcons("signal 30", CLU_1, CLUREF_make_num(9), &STR_signal_04030);
        stringOPcons("signal 31", CLU_1, CLUREF_make_num(9), &STR_signal_04031);
        stringOPcons("signal 32", CLU_1, CLUREF_make_num(9), &STR_signal_04032);
        _signal_type_own_init = 1;
    }
    enter_proc(36);

  LINE(37);
    { /* return */
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    sequenceOPnew2(CLU_32, &T_2_1);
    T_2_1.vec->data[0] = STR_hangup.num;
    T_2_1.vec->data[1] = STR_interrupt.num;
    T_2_1.vec->data[2] = STR_quit.num;
    T_2_1.vec->data[3] = STR_illegal_040instruction.num;
    T_2_1.vec->data[4] = STR_trace_040trap_057BPT.num;
    T_2_1.vec->data[5] = STR_IOT_040instruction.num;
    T_2_1.vec->data[6] = STR_EMT_040instruction.num;
    T_2_1.vec->data[7] = STR_floating_040point_040exception.num;
    T_2_1.vec->data[8] = STR_killed.num;
    T_2_1.vec->data[9] = STR_bus_040error.num;
    T_2_1.vec->data[10] = STR_segmentation_040violation.num;
    T_2_1.vec->data[11] = STR_bad_040argument_040to_040system_040call.num;
    T_2_1.vec->data[12] = STR_broken_040pipe.num;
    T_2_1.vec->data[13] = STR_alarm_040clock.num;
    T_2_1.vec->data[14] = STR_software_040termination.num;
    T_2_1.vec->data[15] = STR_urgent_040condition.num;
    T_2_1.vec->data[16] = STR_stop.num;
    T_2_1.vec->data[17] = STR_stop_040_050tty_051.num;
    T_2_1.vec->data[18] = STR_continue.num;
    T_2_1.vec->data[19] = STR_child_040termination.num;
    T_2_1.vec->data[20] = STR_stop_040_050tty_040input_051.num;
    T_2_1.vec->data[21] = STR_stop_040_050tty_040output_051.num;
    T_2_1.vec->data[22] = STR_i_057o_040possible.num;
    T_2_1.vec->data[23] = STR_cpu_040time_040limit.num;
    T_2_1.vec->data[24] = STR_file_040size_040limit.num;
    T_2_1.vec->data[25] = STR_virtual_040time_040alarm.num;
    T_2_1.vec->data[26] = STR_profiling_040timer_040alarm.num;
    T_2_1.vec->data[27] = STR_signal_04028.num;
    T_2_1.vec->data[28] = STR_signal_04029.num;
    T_2_1.vec->data[29] = STR_signal_04030.num;
    T_2_1.vec->data[30] = STR_signal_04031.num;
    T_2_1.vec->data[31] = STR_signal_04032.num;
    if (sig.num < 1 || sig.num > T_2_1.vec->size) {
        err = ERR_bounds;
        goto ex_1;
    }
    T_2_2.num = T_2_1.vec->data[sig.num - 1];
    ret_1->num = T_2_2.num;
    }
    signal (ERR_ok);
    }
    goto end_1;
  ex_1: /* except */
    __CLU_EX_HANDLER;
    if (err == ERR_bounds) {
    }
    else { /* not handled */
        goto ex_0;
    }
  end_1:;

  LINE(39);
    { /* signal */
        signal(ERR_illegal_signal);
    }

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

/**** END PROCEDURE _signal_type ****/

