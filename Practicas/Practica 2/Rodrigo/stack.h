/* PILA DE CARACTERES */

// Constantes
#define STACK_H
#define MAX_LEN 40

// Estructuras
typedef struct stack_d{
  int top;
  int max;
  char data[MAX_LEN];
} stack_d;

// Prototipos
stack_d init_stack_d (int max);
int     push_d       (stack_d *stack, char val);
char     pop_d        (stack_d *stack);
void    print_stack_d(stack_d  *stack);

// Inicializa un prototipo
stack_d init_stack_d(int max){
   stack_d stack;
   stack.max = max;
   stack.top = -1;
   
   return stack;
}

// Saca de la pila
char pop_d(stack_d *stack){
  char elemento = '-';
  if (stack->top > -1){
    elemento = stack->data[stack->top];
    stack->data[stack->top] = 0;
    stack->top--;
  }
  else{
    printf("\nError pop: stack empty\n");
  }
  
  return elemento; // Regresa el primer caracter de la lista
}

// Inserta en la pila
int push_d(stack_d *stack, char val){
  int ifpush = -1;
  if(stack->top < stack->max-1){
    stack->top++;
    stack->data[stack->top] = val;
    ifpush = 1;
  }
  else{
    printf("\nError push: stack overflow\n");
  }
  
  return ifpush; // -1: Error, otro: Insercion con exito
}

// imprime los elementos de la pila
void print_stack_d(stack_d *stack){
  int i;
  if(stack->top == -1){
    printf("No hay elementos en la pila\n");
  }else{
    for(i = 0; i <= stack->top ;i++){
      printf("%c, ", stack->data[i]);
    }
    printf("\n");
  }
}