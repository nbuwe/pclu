# Makefile for ~CLU/cmpclu

# Generates .c files corresponding to .clu files for the compiler.

# Assumes that the CLUHOME environment variable is set.

# There should be a "make new" to use when changing architectures
# or for a initial installation

PCLU  = ../exe/pclu
RM    = /bin/rm -f
FLUFF = *~ *.old *.bak .*~ .*.old .*.bak

all: regen rebuild

regen:
	$(PCLU) -xf cmp.xfile -opt time -ccopt 0 -co *.clu

rebuild:
	(cd ../code/cmp && make)

lib:
	${RM} ./cmp.lib
	$(PCLU) -xf cmp.xfile -spec *.spc  -spec *.clu -spec *.clu \
		-dump cmp.lib

clean:
	${RM} cmp.lib *.c

veryclean: clean
