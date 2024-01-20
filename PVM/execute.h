#include "m_types.h"
#include "opcodes.h"

void (*inst[5]) (cpu * c, u32 * code);


void init_inst(){

  inst[0] = ins_hlt;
  inst[1] = ins_mov;
  inst[2] = ins_movr;
  inst[3] = ins_add;
  inst[4] = ins_debug_print;
}

void execute(cpu * c, u32 * code){

  inst[c->ip.part[0]](c , code);

}
