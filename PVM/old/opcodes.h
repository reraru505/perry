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

void ins_jne(cpu * c ,  u32 * code);

void ins_jg(cpu * c ,  u32 * code);

void ins_jl(cpu * c ,  u32 * code);

void ins_label(cpu * c ,  u32 * code); // another useless func


//opcodes 2 , one file was too big to store all operations
//deal with it bitches


void ins_sub(cpu * c ,  u32 * code);

void ins_div(cpu * c ,  u32 * code);

void ins_mul(cpu * c ,  u32 * code);

void ins_mod(cpu * c ,  u32 * code);

void ins_inc(cpu * c ,  u32 * code);

void ins_dec(cpu * c ,  u32 * code);

//newer fucntions to use according to addresssig mode

void addressing_mode_nil();

void addressing_mode_atr();

void addressing_mode_mtr();

void addressing_mode_rtr();

void addressing_mode_mtm();

void addressing_mode_ata();

void addressing_mode_atm();
