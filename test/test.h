#pragma once

#include <stdio.h>

#define ASSERT(x) \
    if (!x) { \
        fprintf(stderr, "ERROR: Unit test '%s' failed, on line %d of file %s\n", __func__, __LINE__, __FILE__); \
        return 1; \
    }
