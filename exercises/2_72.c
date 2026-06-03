/*
 * Copy integer into buffer if space is available
 */

#include <string.h>
int copy_int(int value, void *buffer, int maxbytes) {
    if (maxbytes >= (int)sizeof(value)) {
        memcpy(buffer, &value, sizeof(value));
        return sizeof(value);
    }
    return 0;
}
