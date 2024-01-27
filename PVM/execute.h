#include "m_types.h"
#include "opcodes.h"

void (*inst[19]) (cpu * c, u32 * code);


void init_inst(){

  inst[0] = ins_hlt;
  inst[1] = ins_mov;
  inst[2] = ins_movr;
  inst[3] = ins_add;
  inst[4] = ins_debug_print;
  
  inst[5]  = ins_call; 
  inst[6]  = ins_ret;
  inst[7]  = ins_cmp;
  inst[8]  = ins_je;   //jump if equal
  inst[9]  = ins_jg;   //jump if greater
  inst[10] = ins_jl;   //jump if lesser
  inst[11] = ins_label; //is a label don't do shit here just like hlt

  //ah shit here we go again
  inst[12] = ins_sub;	            
  inst[13] = ins_div;	            
  inst[14] = ins_mul;	            
  inst[15] = ins_mod;	            
  inst[16] = ins_inc;
  inst[17] = ins_dec;
  inst[18] = ins_jne;
  

  
}

void execute(cpu * c, u32 * code){

  inst[c->ip.part[0]](c , code);

}
