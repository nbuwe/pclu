# Makefile for ~CLU/code/libclu (Linux version)

# Compilation flags for subdirectories of this directory

CFLAGS         = -I../../include
OPT_FLAGS      = -O2
DEBUG_FLAGS    = -g
DEBUGGER_FLAGS ?= ${OPT_FLAGS}
DEBUGGER_FLAGS += -DCLU_DEBUG=1

LN             = /bin/ln -s
RM             = /bin/rm -f
FLUFF          = *~ *.old *.bak .*~ .*.old .*.bak

OBJS  = _all_file_names_.o _int_range.o _job_stuff.o _longsub.o _qindexc.o \
        _resolve.o _signal_type.o _system_root.o _time_format.o _unquote.o \
        all_file_names.o array_replace.o bigint.o cos.o \
        delete_expunge.o dparse.o gc_copy.o gc_dump.o gc_read.o gcd_tab.o \
        heap.o hex.o host_address.o inet_address.o isqrt.o istream.o \
        lex_scan.o maybe.o octal.o open_append.o open_read.o open_write.o os.o \
        parse_line.o pstream.o quick_sort.o quicksort.o run_time.o scase.o \
        split_line.o strim.o string_lindexs.o string_ops.o table.o tan.o \
        time.o unify_spacing.o xref.o

opt: fictitious_file
	cd Opt && ${MAKE} CC="${CC}" CFLAGS="${CFLAGS} ${OPT_FLAGS}" OBJS="${OBJS}"

debugger: fictitious_file
	#cd Debugger && ${MAKE} CC="${CC}" CFLAGS="${CFLAGS} ${DEBUGGER_FLAGS}" OBJS="${OBJS}" c_files
	cd Debugger && ${MAKE} CC="${CC}" CFLAGS="${CFLAGS} ${DEBUGGER_FLAGS}" OBJS="${OBJS}" all

debug: fictitious_file
	# cd Debug; ${RM} *.c; ${LN} ../Opt/*.c .
	# cd Debug && ${MAKE} CC="${CC}" CFLAGS="${CFLAGS} ${DEBUG_FLAGS}" OBJS="${OBJS}"

fictitious_file:

clean:
	${RM} ${FLUFF}
	cd Opt && ${MAKE} clean
	# cd Debug && ${MAKE} clean
	cd Debugger && ${MAKE} clean

veryclean: clean
