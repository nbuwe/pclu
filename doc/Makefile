# Makefile for ~CLU/doc

.SILENT:

RM    = /bin/rm -f
FLUFF = *~ *.old *.bak .*~ .*.old .*.bak

all:
	cd driver && ${MAKE}
	pdflatex pclu
	pdflatex pclu
	pdflatex mini-pclu
	pdflatex mini-pclu

clean:
	cd driver && ${MAKE} clean
	${RM} *.aux *.dvi *.log .log ${FLUFF}

veryclean: clean
