# Makefile for ~CLU/code/sysasm (Linux version)

# Compilation flags for subdirectories of this directory

CFLAGS         = -I../../include -DLINUX
OPT_FLAGS      = -O2
DEBUG_FLAGS    = -g
DEBUGGER_FLAGS ?= ${OPT_FLAGS}

# NB: Don't compile this with CLU_DEBUG.  Native code uses signal() in
#   an (IMHO) misguided attempt to look more like Clu, but
#   debug$leave_proc that signal() calls with CLU_DEBUG doesn't have
#   the matching debug$enter* call at the beginning, wreaking havoc.
DEBUGGER_FLAGS += -DCLU_DEBUG_IMPL=1

LN             = /bin/ln -s
RM             = /bin/rm -f
FLUFF          = *~ *.old *.bak .*~ .*.old .*.bak

OBJS  = _adv.o _anyize.o _bytevec.o _chan.o _cvt.o _environ.o _environs.o \
	_event.o _get_pid.o _gprof.o _local_time.o _round_real.o _tagcell.o \
	_unparse_real.o _vec.o alloc.o array.o bool.o char.o connected_dir.o \
	delete_file.o force.o gprof.o int.o itertype.o log.o new_parm_util.o \
	new_selector.o now.o null.o oneof.o oneof_pfx.o proctype.o real.o \
	record.o record_pfx.o rename_file.o sequence.o string.o \
	struct.o struct_pfx.o type.o type_of.o unimp.o unix_cmd.o util.o \
	variant.o variant_pfx.o

opt: fictitious_file
	cd Opt && ${MAKE} CC="${CC}" CFLAGS="${CFLAGS} ${OPT_FLAGS}" OBJS="${OBJS}"

debugger: fictitious_file
	cd Debugger; ${RM} *.c *.h; ${LN} ../Opt/*.c . ; ${LN} ../Opt/*.h .
	cd Debugger && ${MAKE} CC="${CC}" CFLAGS="${CFLAGS} ${DEBUGGER_FLAGS}" OBJS="${OBJS}"

fdebugger: fictitious_file
	cd Debugger && ${MAKE} CC="${CC}" CFLAGS="${CFLAGS} ${DEBUGGER_FLAGS}" OBJS="${OBJS}"

debug: fictitious_file
	cd Debug; ${RM} *.c *.h; ${LN} ../Opt/*.c . ; ${LN} ../Opt/*.h .
	cd Debug && ${MAKE} CC="${CC}" CFLAGS="${CFLAGS} ${DEBUG_FLAGS}" OBJS="${OBJS}"

fictitious_file:

clean:
	${RM} ${FLUFF}
	cd Debug && ${MAKE} clean
	cd Debugger && ${MAKE} clean
	cd Opt && ${MAKE} clean

veryclean: clean
