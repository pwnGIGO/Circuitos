#include <stdio.h>
#include "stack.h"

stack_d init_stack_d(int max){
   stack_d stack;
   stack.max = max;
   stack.top = -1;
   
   return stack;
}

int pop_d(stack_d *stack, int *val){
  int ifpop = -1;
  
  //(*stack).top; --> stack->top;
  
  if (stack->top > -1){
    *val = stack->data[stack->top];
    stack->data[stack->top] = 0;
    stack->top--;
    ifpop = 1;
  }
  else{
    printf("\nError pop: stack empty\n");
  }
  
  return ifpop;
}

int push_d(stack_d *stack, int val){
  int ifpush = -1;
  
  if (stack->top < stack->max-1){
    stack->top++;
    stack->data[stack->top] = val;
    ifpush = 1;
  }
  else{
    printf("\nError push: stack overflow\n");
  }
  
  return ifpush;
}

void print_stack_d(stack_d stack){
  int i = 0;
  
  printf("\n\nStack\n"
         "indice -> valor\n");
  for(i=stack.max-1; i>-1; i--){
    printf("%4d -> %d\n", i, stack.data[i]);
  }
  printf("top/max: %d de %d\n",stack.top,stack.max-1);
}