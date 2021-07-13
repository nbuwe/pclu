# Makefile for Portable CLU

# To use this Makefile:
#   (a) Set the CLUHOME environment variable to the name of this directory.
#       Using the bash shell: export CLUHOME=`pwd`
#       Using the csh shell:  setenv CLUHOME `pwd`
#   (b) If you are using "make install", edit the definition of INSTALL_DIR.
#   (c) Type "make" 
# If this Makefile does not work on your platform, follow the instructions
# in howto.install, which you can also read if you want to understand how
# this Makefile works.

# The following options have not been tested for this distribution.
#   (a) Using "make configure_G0" to get -G 0 libraries for debugging
#       (for building large programs on the mips or alpha platforms).
#   (b) Adding #define athena to CLUHOME/include/pclu_sys.h (to get
#       smaller executables at the cost of some speed),

PLATFORM = linux

EXEDIR = exe

CONFIGDIRS = cludent code/cmp code/cmpasm code/libasm code/libclu \
             code/sysasm code/sysclu debug driver util

CLEANDIRS  = cludent cmpclu code debug doc driver example lib sys util

# List of directories where you need to change the settings of how the
# CLU code compiled for debugging (to C) is compiled (from C).  The
# name comes from the "-G 0" option to some old C compiler (vs -G 4)
# and was used in configure_G0 target (deleted in 27913b3296f9) to
# switch between the two.  (Preserved for future refence).
G0_DIRS    = code/sysasm code/libasm code/libclu code/sysclu debug

INSTALL_DIR 	= /usr/local/pclu

INSTALL_FILES	 = #

# the programs
INSTALL_FILES	+= ${EXEDIR}/pclu
INSTALL_FILES	+= ${EXEDIR}/plink
INSTALL_FILES	+= ${EXEDIR}/cludent

INSTALL_FILES	+= ./clu.order		# compiler's JCL help

INSTALL_FILES	+= ./lib/*.lib		# dumped type libraries
INSTALL_FILES	+= ./lib/*.spc		# source specs
INSTALL_FILES	+= ./lib/short.help

INSTALL_FILES	+= ./cmp/basic.types	# spec for the built-in types
INSTALL_FILES	+= ./cmp/ccdbg.cmd*	# cc invocation temlate(s)
INSTALL_FILES	+= ./cmp/ccopt.cmd*	# cc invocation temlate(s)

# this is where cc*.cmd templates search for the includes to compile
# the C output from pclu.  it's a symlink to code/include in the
# original distribution ...
INSTALL_FILES	+= ./include
INSTALL_FILES	+= ./code/include		# ... hence this

# compiled C code for sys/clu (code/sysclu, code/sysasm) and lib/clu
# (code/libclu, code/libasm)
INSTALL_FILES	+= ./code/libpclu.a		# symlink to one of ...
INSTALL_FILES	+= ./code/libpclu_opt.a
# INSTALL_FILES	+= ./code/libpclu_debug.a

INSTALL_FILES	+= ./doc/pclu.pdf
INSTALL_FILES	+= ./doc/mini-pclu.pdf

# INSTALL_FILES	+= ./driver
INSTALL_FILES	+= ./elisp
INSTALL_FILES	+= ./example


INSTALL_TAR_FILE = ../pclu-install.tar.Z
INSTALL_TARGZ_FILE = ../pclu-install.tar.gz

LN = /bin/ln -s
MV = /bin/mv -f
RM = /bin/rm -f
CP = /bin/cp

FLUFF = *~ *.old *.bak .*~ .*.old .*.bak

all: clu

# uwe: a temporary workaround, run this once to set things up
# assumes you have installed gc
symlinks:
	# the bootstrapped compiler
	(cd exe && ln -sf ../code/cmp/pclu)
	# to compile the C output
	(cd include && ln -sf ../code/include/pclu_err.h)
	(cd include && ln -sf ../code/include/pclu_sys.h)
	# to link the compiled programs
	(cd code && ln -sf gc/lib/libgc.a)
	# to build the library
	(cd code/include && ln -sf ../gc/include/gc)

clu: libpclu compiler clulibs cludent # PCLU debugger

libpclu:
	echo Creating library of optimized CLU system code for the C linker.
	cd code && ${MAKE} optlib

compiler:
	echo Building and installing the pclu compiler
	echo Assumes that CLUHOME is set properly
	cd code/cmp && ${MAKE}
	mv code/cmp/pclu $(EXEDIR)/pclu

clulibs:
	echo Building CLU runtime libraries
	cd lib && ${MAKE}

debugger:
	echo Creating library of debuggable CLU system code for the C linker.
	cd code && ${MAKE} debuglib

PCLU:
	echo 'Building and installing the PCLU driver (an alternative to pclu/plink)'
	cd driver && ${MAKE} PCLU
	mv driver/PCLU $(EXEDIR)/PCLU

install:
	echo Installing PCLU in ${INSTALL_DIR}
	tar cf - ${INSTALL_FILES} | (cd ${INSTALL_DIR}; tar xf -)

install-tar-z:
	tar cfv - ${INSTALL_FILES} | compress > ${INSTALL_TAR_FILE}

install-tar-gz:
	tar cfv - ${INSTALL_FILES} | gzip -c > ${INSTALL_TARGZ_FILE}

example: fictitious_file
	cd example && ${MAKE}
	cd example/debug && ${MAKE}
	cd example/profile && ${MAKE}

cludent: fictitious_file
	cd cludent && ${MAKE}
	mv cludent/cludent $(EXEDIR)/cludent

newcompiler:
	cd cmpclu && ${MAKE}
	${MAKE} compiler

cdebugger:
	cd code && ${MAKE} cdebuglib

fictitious_file:

clean:
	for i in ${CLEANDIRS}; do (cd $$i && ${MAKE} clean); done
	${RM} ${FLUFF}
	(cd ${EXEDIR} && ${RM} ${FLUFF})

veryclean:
	${RM} ${FLUFF}
	for i in ${CLEANDIRS}; do (cd $$i && ${MAKE} veryclean); done
	(cd ${EXEDIR} && ${RM} pclu cludent liblst PCLU ${FLUFF})
