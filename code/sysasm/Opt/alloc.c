#include <string.h>
#include <gc/gc.h>


/* Allocate lb bytes of atomic (pointer-free) data. */
void
clu_alloc_atomic(size_t lb, char **ans)
{
    void *p = GC_malloc_atomic(lb);
    if (p != NULL)
	memset(p, '\0', lb);
    *ans = p;
}


/* Allocate lb bytes of composite (pointerful) data */
void
clu_alloc(size_t lb, char **ans)
{
    void *p = GC_malloc(lb);
    if (p != NULL)
	memset(p, '\0', lb);
    *ans = p;
}
