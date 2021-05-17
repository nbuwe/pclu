ifdef(`MAXFIELDS', `',
`errprint(``MAXFIELDS' is not defined
')
m4exit(1)
')dnl
dnl
define(`EMIT',
`ifdef(`$1', `EMIT_FROM_TO(`$1', 1, incr(MAXFIELDS))',
`errprint(``$1' is not defined
')
m4exit(1)'
)')dnl
dnl
define(`EMIT_FROM_TO',
`ifelse($2, $3, `dnl',
`$1($2)
EMIT_FROM_TO(`$1', incr($2),  $3)')')dnl
