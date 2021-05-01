# Makefile for ~CLU/cmpclu

# Generates .c files corresponding to .clu files for the compiler.

# Assumes that the CLUHOME environment variable is set.

# There should be a "make new" to use when changing architectures
# or for a initial installation

PCLU  = ../exe/pclu
RM    = /bin/rm -f
FLUFF = *~ *.old *.bak .*~ .*.old .*.bak

EQUS =	bin.equ codgen.equ gen.equ passes.equ syntax.equ

SPECS = _bin_id.spc _restore_state.spc _save_state.spc pjcl.spc

SRCS =	build.clu cconst.clu cdchan.clu cdefn1.clu cdefn2.clu ce.clu	\
	cenv.clu cexpr1.clu cexpr2.clu cmpvar.clu coper.clu		\
	cspecs.clu cstmt1.clu cstmt2.clu dtchan.clu du.clu eval1.clu	\
	eval2.clu gconst.clu gdbg.clu gdefn.clu genv.clu gexpr.clu	\
	giter.clu gopt1.clu gparm.clu gstmt.clu gtbl.clu gtypes.clu	\
	gutil.clu gvars.clu idn.clu init.clu lineedit.clu pconst.clu	\
	pdefn1.clu pdefn2.clu penv.clu pexpr.clu pjcl.clu plist.clu	\
	pstmt1.clu pstmt2.clu pttkn.clu stable.clu syntax.clu		\
	tkntab.clu top1.clu top2.clu vcmp.clu xlib.clu


all: regen rebuild

regen:
	$(PCLU) -xf cmp.xfile -opt time -bindir ../code/cmp -co ${SRCS}

regen-debug:
	$(PCLU) -xf cmp.xfile -opt false -bindir ../code/cmpdbg -co ${SRCS}

rebuild:
	(cd ../code/cmp && make)

lib:
	${RM} ./cmp.lib
	$(PCLU) -xf cmp.xfile -spec ${SPECS} -spec ${SRCS} -spec ${SRCS} \
		-dump cmp.lib

clean:
	${RM} cmp.lib *.c

veryclean: clean
