/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			version			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"


/*
 * _get_version = proc () returns (int)
 *     % return program version number (set by #version option of LINK)
 *     end _get_version
 *
 * uwe: #version is not supported by PCLU's PLINK, so the compiler
 * supplies the "version" variable manually.
 */
int version = 7;
