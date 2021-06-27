/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			version			*/
/*						*/

/*
 * Fallback definition of "version".
 *
 * Returned by _get_version() and expected to be supplied by the
 * #version option of LINK.
 *
 * uwe: As far as I can tell this is not supported by PCLU.
 * E.g. the compiler itself manually supplies "version" in cmpasm.
 */
int version = 0;
