#include "m_types.h"

void (*addressing_mode_selet[7]) (cpu * c, u32 * code);

void init_addressing_mode_selection(){

  addressing_mode_selet[NIL] = addressing_mode_nil;
  			                       
  addressing_mode_selet[ATR] = addressing_mode_atr;
  			                       
  addressing_mode_selet[MTR] = addressing_mode_mtr;
  			                       
  addressing_mode_selet[RTR] = addressing_mode_rtr;
  			                       
  addressing_mode_selet[MTM] = addressing_mode_mtm;
  			                       
  addressing_mode_selet[ATA] = addressing_mode_ata;
  			                       
  addressing_mode_selet[ATM] = addressing_mode_atm;
    
}
