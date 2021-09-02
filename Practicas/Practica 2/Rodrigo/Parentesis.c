#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "stack.h"
#include <time.h>

#define A (0)
#define B (1)
#define C (2)
#define D (3)

#define MAX_STACK 40

int main(){
    int estado, recorre, pon;
    char expresion[100];
    int contParentesis = 0;
    
    stack_d stack;
    stack = init_stack_d(MAX_STACK);
    estado = A;
    pon = 1;
    /*push_d(&stack, '1');
    push_d(&stack, '2');
    push_d(&stack, '3');
    print_stack_d(&stack);
    printf("Saque: %c\n", pop_d(&stack));
    push_d(&stack, '4');
    push_d(&stack, '5');
    print_stack_d(&stack);
    printf("Saque: %c\n", pop_d(&stack));
    printf("Saque: %c\n", pop_d(&stack));
    printf("Saque: %c\n", pop_d(&stack));
    printf("Saque: %c\n", pop_d(&stack));
    print_stack_d(&stack);*/

    for(;;){
        //printf("\n\n");
        //sleep(1);
        switch(estado){
            case A: // Leer del teclado
                recorre = 0;
                printf("\nIngresa la expresion algebraica: ");
                scanf("%[^\n]s", expresion);
                getchar();
                estado = B;
                break;
            case B:
                //printf("Estado B: Actual %c\n", expresion[recorre]);
                if(expresion[recorre] == '\0'){
                    if(stack.top == -1 && contParentesis == 0){ // Pila vacia
                        printf("\nTu expresion algebraica es correcta\n");
                    }else{
                        printf("\nTu expresion es incorrecta\n");
                    }
                    stack.top=-1;
                    estado = A;
                }else{
                    if(expresion[recorre] == '('){
                        estado = C;
                    } else if(expresion[recorre] == ')'){
                        estado = D;
                    }else{ // Es digito u operador aritmetico
                        recorre++;
                    }
                }
                break;
            case C:
                //printf("Estado C: Inserta %c \n", expresion[recorre]);
                push_d(&stack, expresion[recorre]);
                recorre++;
                contParentesis++;
                estado = B;
                break;
            case D:
                //printf("Estado D: Saca %c\n", pop_d(&stack));
                pop_d(&stack);
                recorre++;
                contParentesis--;
                estado = B;
                break;
        }
    }
    return 0;
}
