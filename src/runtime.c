#include "runtime.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "instructions.h"

runtime_state_t* runtime_init(uint8_t* mem, uint64_t code_size, uint64_t stack_size, uint64_t heap_size) {
    runtime_state_t* runtime = (runtime_state_t*) malloc(sizeof(runtime_state_t));

    runtime->mem = mem;
    runtime->code_size = code_size;
    runtime->stack_size = stack_size;
    runtime->mem_size = code_size + heap_size;

    return runtime;
}

uint8_t get_register_size(uint8_t size) {
    switch (size) {
        case 0: return 1;
        case 1: return 2;
        case 2: return 4;
        case 3: return 8;
        default: {
            fprintf(stderr, "Error: Invalid register size\n");
            exit(1);
        } break;
    }
}

bool is_valid_register(uint8_t reg) {
    return reg < 32;
}

void runtime_step(runtime_state_t* state) {
    // Decoding the instruction
    uint8_t b1 = state->mem[state->ip];

    // If the first bit isn't set, this is a 1-byte opcode
    if (!(b1 & 0b10000000)) {
        state->ip++;

        switch (b1 & 0b01111111) {
            case NOOP: break;
            case SYS: {
                printf("SYSCALL: %d\n", state->regs[0]);
            } break;

            case MV_IMM_REG: {
                /*
                 * Moves an immediate value into a register.
                 *
                 * byte 1 - register to store value into
                 * byte 2-9 - value to be stored into register
                 * 
                 * The subsequent number of bytes depends on the
                 * size of the register the value is being moved
                 * into.
                 */

                uint8_t reg_op = state->mem[state->ip];
                uint8_t reg = reg_op & 0b00111111;

                if (!is_valid_register(reg)) {
                    fprintf(stderr, "Error: Invalid register\n");
                    exit(0);
                }

                state->ip++;

                uint8_t imm_op_size = get_register_size(reg_op >> 6);

                // Writing the operand into the register
                for (int i = 0; i < imm_op_size; i++) {
                    ((uint8_t*) &state->regs[reg])[i] = state->mem[state->ip];

                    state->ip++;
                }
            } break;

            default: {
                fprintf(stderr, "Error: Invalid opcode %d\n", b1 & 0b01111111);
                exit(1);
            }
        }
    } else {
        // Otherwise, this is a 2-byte opcode

    }
}
