#pragma once

#include "stdlib.h"
#include "ctype.h"
#include "string.h"
#include "m_types.h"
#include "tokens.h"

//rewrite

Token * flatten_token_list(Node * n , Length_tracker * lt);

bool isOpcode(char * s);

bool isReg(char * s);

bool isAddress(char * s);

bool isDirective(char * s);

bool isLabel(char * s);

bool isData(char * s);



//old stufff has been canned and now for this part to work the vm
//needs a major rewrite as well
//the project is not even in alpha stage
//after the rewrtie of vm and the assembler the project needs to be in
// version 0 . 0 . 0 
