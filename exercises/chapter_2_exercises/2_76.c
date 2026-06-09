/**
 * The calloc function allocates memory for an array of nmemb elements
 * of size bytes each. The memory is set to zero. If nmemb or size is zero,
 * then calloc returns a NULL.
 *
 * Question: Write an implementation of calloc that performs the allocation
 * by a call to `malloc` and sets the memory to zero via `memset`.
 */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
void *calloc(size_t nmemb, size_t size) {
    // Safety check 1: Avoid division by zero and unnecessary allocation
    if (nmemb == 0 || size == 0) {
        return NULL;
    }

    size_t total_size = nmemb * size;

    // Safety check 2: Use division to detect overflow
    if (total_size / size != nmemb) {
        return NULL;
    }

    // Safety check 3: Guard the library calls
    void *p = malloc(total_size);
    if (p != NULL) {
        memset(p, 0, total_size);
    }

    return p;
}
