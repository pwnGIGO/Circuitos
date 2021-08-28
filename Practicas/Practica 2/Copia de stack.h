#ifndef STACK_H
#define STACK_H

#define MAX_LEN 40

typedef struct stack_d{
  int top;
  int max;
  int data[MAX_LEN];
} stack_d;

stack_d init_stack_d (int max);
int     pop_d        (stack_d *stack, int *val);
int     push_d       (stack_d *stack, int val);
void    print_stack_d(stack_d  stack);

#endif