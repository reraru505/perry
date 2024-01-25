#include "m_types.h"
#include "stdlib.h"
#include "stdio.h"

void ins_hlt(cpu * c , u32 * code); //useless func

void ins_mov(cpu * c, u32 * code);

void ins_movr(cpu * c, u32 * code);

void ins_add(cpu * c, u32 * code);

void ins_debug_print(cpu * c , u32 * code);

//added some new instructions

void ins_call(cpu * c , u32 * code);

void ins_ret(cpu * c , u32 * code);

void ins_cmp(cpu * c , u32 * code);

void ins_je(cpu * c ,  u32 * code);

void ins_jg(cpu * c ,  u32 * code);

void ins_jl(cpu * c ,  u32 * code);

void ins_label(cpu * c ,  u32 * code); // another useless func
