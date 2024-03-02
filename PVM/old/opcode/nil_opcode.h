#include "m_types.h"

void ins_hlt_nil(cpu * c , u32 * code){
  
}

void ins_ret_nil(cpu * c , u32 * code){

  if(c->was_called == 1){
    c->pc = c->ret;
    c->was_called = 0;
  }
 
}
