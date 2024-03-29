#include "opcodes.h"
#include "stdio.h"


void ins_sub(cpu * c ,  u32 * code){
  c->gpr[c->ip.part[1]] = c->gpr[c->ip.part[2]]
    - c->gpr[c->ip.part[3]];

}


void ins_div(cpu * c ,  u32 * code){
  c->gpr[c->ip.part[1]] = c->gpr[c->ip.part[2]]
    / c->gpr[c->ip.part[3]];

}


void ins_mul(cpu * c ,  u32 * code){
  c->gpr[c->ip.part[1]] = c->gpr[c->ip.part[2]]
    * c->gpr[c->ip.part[3]];

}


void ins_mod(cpu * c ,  u32 * code){
  c->gpr[c->ip.part[1]] = c->gpr[c->ip.part[2]]
    % c->gpr[c->ip.part[3]];

}


void ins_inc(cpu * c ,  u32 * code){
  c->gpr[c->ip.part[1]] = c->gpr[c->ip.part[1]] + 1;

}


void ins_dec(cpu * c ,  u32 * code){
  c->gpr[c->ip.part[1]] = c->gpr[c->ip.part[1]] - 1;
}

