/* Copyright Massachusetts Institute of Technology 1990,1991 */
/* Copyright Massachusetts Institute of Technology 1985, 1989 */

#include "pclu_err.h"
#include "pclu_sys.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>


errcode
_host_address(CLUREF host, CLUREF *ans1, CLUREF *ans2)
{
    struct hostent *hp;
    int l, r;
    int *np;

    hp = gethostbyname(host.str->data);
    if (hp == NULL)
	signal(ERR_not_found);

    if (hp->h_addrtype != AF_INET)
	signal(ERR_bad_address);

#if 0
    printf("%x\n", *hp->h_addr);
#endif
    np = (int *)hp->h_addr;
    l = (*np >> 16) & 0xffff;
    r = *np & 0xffff;
    ans1->num = l;
    ans2->num = r;
    signal(ERR_ok);
}
