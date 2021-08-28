#include <stdio.h>
#include <unistd.h>

// Se define la estructura/objeto
typedef struct stack_d{
  int top;
  int max;
  int data[MAX_LEN];
} stack_d;

// Se definen los prototipos
stack_d init_stack_d (int max);
int     pop_d        (stack_d *stack, int *val);
int     push_d       (stack_d *stack, int val);
void    print_stack_d(stack_d  stack);

// main (inicia el programa)
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


// Definicion de los metodos para el comportamiento de la pila

// Inicializa una estructura
stack_d init_stack_d(int max){
 stack_d stack;
 stack.max = max;
 stack.top = -1;
 return stack;
}

// Obtiene el primer elemento de la pila
int pop_d(stack_d *stack, int *val){
  int ifpop = -1;  
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

// inserta al principo de la pila
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

// Imprime los elementos de la pila
void print_stack_d(stack_d stack){
  int i = 0;
  
  printf("\n\nStack\n"
   "indice -> valor\n");
  for(i=stack.max-1; i>-1; i--){
    printf("%4d -> %d\n", i, stack.data[i]);
  }
  printf("top/max: %d de %d\n",stack.top,stack.max-1);
}
