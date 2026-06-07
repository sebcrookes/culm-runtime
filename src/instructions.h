#pragma once

enum instructions_e {
    NOOP,
    PUSH,
    POP,
    SYS,
    MV_IMM_REG,
    MV_REG_REG,
    MV_REG_ADDR_IMM,
    MV_REG_ADD_REG
};
