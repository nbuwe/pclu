# Makefile for ~CLU/sys/clu

RM    = /bin/rm -f
FLUFF = *~ *.old *.bak .*~ .*.old .*.bak

all:

clean:
	${RM} ${FLUFF}

veryclean: clean

SYS_SOURCES  =
SYS_SOURCES += _cause_bounds.clu
SYS_SOURCES += _cause_illegal_char.clu
SYS_SOURCES += _cause_overflow.clu
SYS_SOURCES += _cause_wrong_tag.clu
SYS_SOURCES += _cause_wrong_type.clu
SYS_SOURCES += _cleanup_.clu
SYS_SOURCES += _dir_ent_size.clu
SYS_SOURCES += _erstr.clu
SYS_SOURCES += _fixup_dir_part.clu
SYS_SOURCES += _fixup_file_name.clu
SYS_SOURCES += _get_termcap.clu
SYS_SOURCES += _home_dir.clu
SYS_SOURCES += _last_indexc.clu
SYS_SOURCES += _skip_fill.clu
SYS_SOURCES += _split_name_part.clu
SYS_SOURCES += _termcap.clu
SYS_SOURCES += _termcap_entry.clu
SYS_SOURCES += _working_dir.clu
SYS_SOURCES += date.clu
SYS_SOURCES += e_form.clu
SYS_SOURCES += f_form.clu
SYS_SOURCES += file_name.clu
SYS_SOURCES += file_name_fill.clu
SYS_SOURCES += file_spec.clu
SYS_SOURCES += g_form.clu
SYS_SOURCES += set_working_dir.clu
SYS_SOURCES += stream.clu
SYS_SOURCES += user_name.clu
SYS_SOURCES += working_dir.clu

CLU       = $(CLUHOME)/exe/pclu

regen-sysclu:
	for file in ${SYS_SOURCES}; do \
	    echo '===>' $${file}; \
	    $(CLU) \#opt \
		\#cfiles TRUE \#ccopt 0 \
		\#merge ../../lib/lowlev.lib \
		\#merge ../../lib/misc.lib \
		\#merge ../../lib/useful.lib \
		\#spec ../../lib/_gprof.spc \
		\#bindir ${CLUHOME}/code/sysclu/Opt \
		\#clu $${file} \
	    || echo FAILED: $${file}; \
	done
