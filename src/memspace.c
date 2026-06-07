#include "memspace.h"

#include <stdlib.h>

uint8_t* memspace_init(uint64_t code_size, uint64_t heap_size) {
    uint8_t* memory_space = (uint8_t*) calloc(code_size + heap_size, 1);

    return memory_space;
}
