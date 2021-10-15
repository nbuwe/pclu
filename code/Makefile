# Makfile for ~CLU/code

# Creates libraries of PCLU system code for the C linker

# To create a pclu library for debugging, you need to compile stream with
# compiler debugging on and cc debugging off.  Without compiler debugging on,
# dbg_info stuff will be lost and you can't eval system operations.  With cc
# debugging on, system operations enter the debugger on signals, etc., and
# confuse the debugger no end.

CLIBDIRS = sysasm libasm sysclu libclu

CLEANDIRS = ${CLIBDIRS} cmp

RM     = /bin/rm -f
FLUFF  = *~ *.old *.bak .*~ .*.old .*.bak


# Opt: Clu optimized, C optimized
optlib: optfiles libpclu_opt.a

OPT = libclu/Opt/*.o sysclu/Opt/*.o libasm/Opt/*.o sysasm/Opt/*.o

optfiles:
	for i in ${CLIBDIRS}; do (cd $$i && ${MAKE} opt); done

libpclu_opt.a:
	${RM} libpclu_opt.a
	ar cruv libpclu_opt.a ${OPT}
	ranlib libpclu_opt.a


# Debugger: Clu debug/ger, C optimized
# The debugger is in ~CLU/debug along with some library overrides
debuglib: debugfiles libpclu_debug.a

DEBUG1 = libclu/Debugger/*.o sysclu/Debugger/*.o libasm/Debugger/*.o \
         sysasm/Debugger/*.o
DEBUG2 = ../debug/*.o

debugfiles:
	for i in ${CLIBDIRS}; do (cd $$i && ${MAKE} debugger); done
	cd ../debug && ${MAKE}

#libpclu_debug.a: ${DEBUG1} ${DEBUG2}
libpclu_debug.a:
	${RM} libpclu_debug.a
	ar cruv libpclu_debug.a ${DEBUG1}
	# drop stuff that the debugger provides overrides for
	ar d libpclu_debug.a util.o _signal.o new_parm_util.o new_selector.o
	# add the debugger and its overrides
	ar q libpclu_debug.a ${DEBUG2}
	ranlib libpclu_debug.a


# Debug: Clu optimized, C with debug
# (uwe: doesn't currently work as the Debug symlinks are not in place)
cdebuglib: cdebugfiles libpclu_g.a

G = libclu/Debug/*.o sysclu/Debug/*.o libasm/Debug/*.o sysasm/Debug/*.o

cdebugfiles:
	for i in ${CLIBDIRS}; do (cd $$i && ${MAKE} debug); done

libpclu_g.a: ${G}
	${RM} libpclu_g.a
	ar cruv libpclu_g.a ${G}
	ranlib libpclu_g.a


clean:
	for i in ${CLEANDIRS}; do (cd $$i && ${MAKE} clean); done
	${RM} ${FLUFF}

veryclean: clean
	for i in ${CLEANDIRS} cmp; do (cd $$i && ${MAKE} veryclean); done
	${RM} libpclu_opt.a libpclu_debug.a libpclu_g.a ${FLUFF}
