#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "stack.h"

#define LOAD  ((int)'l')
#define PUSH  ((int)'s')
#define POP   ((int)'p')
#define PRINT ((int)'r')

#define MAX_STACK 4


int main(){
  char state;
  int  value, test;
  
  stack_d stack;
  stack = init_stack_d(MAX_STACK);
  printf("stack max %d\n",stack.max);
  
  state = LOAD;
  while(1){
    switch (state) {
      case LOAD:
        system("clear");
        printf("Operacion a realizar con la pila:\n"
               "   s -> push\n"
               "   p -> pop\n"
               "   r -> print\n");
        scanf("%c",&state);
        getchar();
        break;
      case PUSH:
        printf("Push(x)\nIntroduce el valor de x:\n");
        scanf("%d",&value);
        getchar();
        push_d(&stack,value);
        getchar();
        state = LOAD;
        break;
      case POP:
        test = pop_d(&stack,&value);
        if (test>0){
          printf("Pop()\n"
                 "  Valor extraido: %d",value);
          getchar();
        }
        else{
          //printf("Error pila vacia\n");
          getchar();
        }
        state = LOAD;
        break;
      case PRINT:
        system("clear");
        print_stack_d(stack);
        getchar();
        state = LOAD;
        break;
      default:
        state = LOAD;
        break;
    }
  }
}

// cd /home/
//  gcc -g stack.c stack_test_fsm.c -o stack.o