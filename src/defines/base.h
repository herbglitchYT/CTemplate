#ifndef BASE_DEFINES_H_
#define BASE_DEFINES_H_

#include <stdint.h>

/**
 * @brief Main error type. subtypes can be defined by .type, and the error itself is stored in .errno
*/
typedef struct Error {
    uint8_t type;
    uint32_t errno;
} Error;

#endif