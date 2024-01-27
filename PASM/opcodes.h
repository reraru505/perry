#include "m_types.h"
#include "string.h"
#include "stdlib.h"

u8 give_reg(char * name);

r32 is_mov(char ** tokens ,
	   int * current_index,
	   int * data_next_signal);

r32 is_data(char ** tokens ,
	    int * current_index,
	    int * data_next_signal);

r32 is_add(char ** tokens ,
	   int * current_index,
	   int * data_next_signal);

r32 is_hlt(char ** tokens ,
	   int * current_index,
	   int * data_next_signal);

r32 is_print(char ** tokens ,
	   int * current_index,
	     int * data_next_signal);

r32 is_label(char ** tokens ,
	     int * current_index,
	     int * data_next_signal,
	     label_table * labels,
	     u32 buffindex);

r32 is_call(char ** tokens ,
	    int * current_index,
	    int * address_next_signal);

u32 give_address(label_table * lt , char * label);

r32 is_address(char ** tokens ,
	       int * current_index,
	       label_table * lt,
	       int * address_next_signal);

r32 is_ret(char ** tokens ,
	   int * current_index,
	   int * data_next_signal);

r32 is_cmp(char ** tokens ,
	   int * current_index,
	   int * data_next_signal);

r32 is_je(char ** tokens ,
	  int * current_index,
	  int * address_next_signal);

r32 is_jg(char ** tokens ,
	  int * current_index,
	  int * address_next_signal);

r32 is_jl(char ** tokens ,
	   int * current_index,
	  int * address_next_signal);


r32 is_movr(char ** tokens ,
	   int * current_index,
	    int * data_next_signal);
