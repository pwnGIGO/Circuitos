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
    int estado, recorre, pon, contador;
    char expresion[100];
    
    stack_d stack;
    stack = init_stack_d(MAX_STACK);
    estado = A;
    pon = 1;
    
    for(;;){
        switch(estado){
            case A:
                
                contador = 0;
                recorre = 0;
                stack.top = -1;
                printf("Ingresa la expresion algebraica: ");
                scanf("%[^\n]s", expresion);
                getchar();
                estado = B;

            break;
            case B:
                
                if(expresion[recorre] == '('){
                    push_d(&stack, pon);
                    contador++;
                }
                if(expresion[recorre] == ')'){
                    pop_d(&stack, &pon);
                    contador--;
                }
                recorre++;
                if(expresion[recorre] == '\0'){
                    if(stack.top == -1 && contador == 0){
                        printf("\nTu expresion algebraica es correcta\n\n");
                    }else{
                        printf("\nTu expresion es incorrecta\n\n");
                    }
                    estado = A;
                }
 
            break;
        }
    }
    return 0;
}
