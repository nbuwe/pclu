# Makefile for ~CLU/code/sysasm/Opt

RM    = /bin/rm -f
FLUFF = *~ *.old *.bak .*~ .*.old .*.bak

all: ${OBJS}

oneof_pfx.c: oneof_pfx.m4 pfx.m4
	m4 $< > $@

record_pfx.c: record_pfx.m4 pfx.m4
	m4 $< > $@

struct_pfx.c: struct_pfx.m4 pfx.m4
	m4 $< > $@

variant_pfx.c: variant_pfx.m4 pfx.m4
	m4 $< > $@

clean:
	${RM} *.o ${FLUFF}

verclean: clean
