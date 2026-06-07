#pragma once

#include <stdint.h>

uint8_t* memspace_init(uint64_t code_size, uint64_t stack_size, uint64_t heap_size);
