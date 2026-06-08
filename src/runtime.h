#pragma once

#include <stdint.h>

typedef struct {
    uint8_t* mem;
    uint64_t code_size;
    uint64_t stack_size;
    uint64_t mem_size;

    // 'CPU' state
    uint64_t regs[32];

    uint64_t ip;
    uint64_t sb;
    uint64_t sp;
} runtime_state_t;

runtime_state_t* runtime_init(uint8_t* mem, uint64_t code_size, uint64_t stack_size, uint64_t heap_size);

void runtime_step(runtime_state_t* state);

uint64_t runtime_get_reg(runtime_state_t* state, uint8_t reg);
void runtime_set_reg(runtime_state_t* state, uint8_t reg, uint64_t val);
