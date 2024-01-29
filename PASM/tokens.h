#pragma once

typedef enum Token_type {

  DATA,
  ADDRESS,
  OPCODE,
  REGISTER
  
} Token_type;

typedef struct Token {

  Token_type type;
  char * name;
  
} Token;

typedef struct Node{

  struct Node * next;
  Token token;
  
} Node;

