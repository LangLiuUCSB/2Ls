#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stdlib.h>

size_t bytes_alloc_max(void)
{
    size_t size = 1;
    uint8_t *largeArray = (uint8_t *)malloc(size);
    if (!largeArray)
        return 0;
    for (; largeArray; largeArray = (uint8_t *)malloc(size *= 2))
        free(largeArray);
    for (size_t extra = (size /= 2); extra;)
    {
        if ((largeArray = (uint8_t *)malloc(size += (extra >>= 1))))
            free(largeArray);
        else
            size -= extra;
    }
    return size;
};

#endif
