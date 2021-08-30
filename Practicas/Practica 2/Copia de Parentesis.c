#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "stack.h"

#define A (0)
#define B (1)
#define C (2)
#define D (3)

#define MAX_STACK 40

int main(){
    int estado, recorre, pon;
    char expresion[100];
    
    stack_d stack;
    stack = init_stack_d(MAX_STACK);
    estado = A;
    pon = 1;
    
    for(;;){
        switch(estado){
            case A: // Leer del teclado
                recorre = 0;
                printf("Ingresa la expresion algebraica: ");
                scanf("%[^\n]s", expresion);
                getchar();
                estado = B;
                break;
            case B:
                recorre++;
                if(expresion[recorre] == '\0'){
                    printf("%d culero\n", stack.top);
                    if(stack.top == -1){ // Pila vacia
                        printf("\nTu expresion algebraica es correcta\n\n");
                    }else{
                        printf("\nTu expresion es incorrecta\n\n");
                    }
                    estado = A;
                }else{
                    if(expresion[recorre] == '('){
                        estado = C;
                    }
                    if(expresion[recorre] == ')'){
                        estado = D;
                    }

                }
                break;
            case C:
                push_d(&stack, pon);
                printf("%d puto\n", stack.top);
                estado = B;
                break;
            case D:
                pop_d(&stack, &pon);
                printf("%d mamon\n", stack.top);
                estado =B;
                break;
        }
    }
    return 0;
}
