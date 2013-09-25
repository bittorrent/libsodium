
#ifdef _MSC_VER
#include <stdint.h>
typedef int8_t bool;
#else
# include <stdbool.h>
#endif

#include "core.h"
#include "crypto_onetimeauth.h"
#include "randombytes.h"

static bool initialized;

int
sodium_init(void)
{
    if (initialized != 0) {
        return 1;
    }
    if (crypto_onetimeauth_pick_best_implementation() == NULL) {
        return -1;
    }
    randombytes_stir();
    initialized = 1;

    return 0;
}
