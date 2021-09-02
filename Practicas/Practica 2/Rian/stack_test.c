#include <stdio.h>
#include <unistd.h>
#include "stack.h"

int main(){
  int value = -20;
  stack_d stack;
  stack = init_stack_d(4);
  
  printf("Hola mundo\n");
  push_d(&stack,120);
  print_stack_d(stack);
  
  push_d(&stack,12);
  print_stack_d(stack);

  push_d(&stack,-120);
  print_stack_d(stack);

  push_d(&stack,8);
  print_stack_d(stack);

  push_d(&stack,512);
  print_stack_d(stack);
  
  pop_d(&stack,&value);
  print_stack_d(stack);
  
  pop_d(&stack,&value);
  print_stack_d(stack);
}

