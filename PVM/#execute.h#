#include "m_types.h"
#include "opcodes.h"

void (*inst[11]) (cpu * c, u32 * code);


void init_inst(){

  inst[0] = ins_hlt;
  inst[1] = ins_mov;
  inst[2] = ins_movr;
  inst[3] = ins_add;
  inst[4] = ins_debug_print;
  
  inst[5]  = ins_call; 
  inst[6]  = ins_ret;
  inst[7]  = ins_cmp;
  inst[8]  = ins_je; //jump if equal
  inst[9]  = ins_jg; //jump if greater
  inst[10] = ins_jl; //jump if lesser
  inst[11] = ins_label;
  
  
}

void execute(cpu * c, u32 * code){

  inst[c->ip.part[0]](c , code);

}
