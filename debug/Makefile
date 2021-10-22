# Makefile for ~CLU/debug

# Generates .o files for debugging.

OPT_FLAGS ?= -O2
CFLAGS = -I${CLUHOME}/code/include ${OPT_FLAGS}

RM    = /bin/rm -f
FLUFF = *~ *.old *.bak .*~ .*.old .*.bak

PCLU = ../exe/pclu

CLU_SOURCES = debug.clu debug2.clu parse.clu


# debugger Clu code
CFILES  = $(CLU_SOURCES:.clu=.c)
FLUFF  += $(CLU_SOURCES:.clu=.c)

# debugger native code
CFILES += debug_c.c call_clu.c

# debug info for the "builtin" stuff
CFILES += libinfo.c


OBJECTS  = $(CFILES:.c=.o)
FLUFF   += $(CFILES:.c=.o)

# in the original these were symlinks to ../cmp
OBJECTS += lineedit.o stable.o


.SUFFIXES:
.SUFFIXES: .o .c .clu

.clu.c:
	$(PCLU) -xf debug.xfile -spec *.clu -opt time -cfiles -ccopt 0 -co $*.clu

it: $(OBJECTS) libinfo.h $(CFILES)

all:
	$(PCLU) -xf debug.xfile -spec *.clu -opt time -co *.clu -dump debug

clean:
	${RM} ${FLUFF}

veryclean: clean
	${RM} debug.lib

libinfo.o: libinfo.h libinfo.c
new_selector.o: selector.h new_selector.c
debug.o: debug.clu
debug2.o: debug2.clu
parse.o: parse.clu
