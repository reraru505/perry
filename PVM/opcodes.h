#include "m_types.h"
#include "stdlib.h"
#include "stdio.h"

void ins_hlt(cpu * c , u32 * code);

void ins_mov(cpu * c, u32 * code);

void ins_movr(cpu * c, u32 * code);

void ins_add(cpu * c, u32 * code);

void ins_debug_print(cpu * c , u32 * code);
