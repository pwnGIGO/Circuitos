#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "stack.h"

#define A (0)
#define B (1)

#define MAX_STACK 40

int main(){
    int estado, recorre, parentesis, corchetes, agrega, agregamas;
    char expresion[100];
    
    stack_d stack;
    stack = init_stack_d(MAX_STACK);
    estado = A;
    agrega = 1;
    agregamas = 10;
    
    for(;;){
        switch(estado){
            case A:
                
                parentesis = 0;
                corchetes = 0;
                recorre = 0;
                stack.top = -1;
                printf("Ingresa la expresion algebraica: ");
                scanf("%[^\n]s", expresion);
                getchar();
                estado = B;

            break;
            case B:
                
                if(expresion[recorre] == '('){
                    parentesis = parentesis + push_d(&stack, agrega);
                }
                if(expresion[recorre] == ')'){
                    if(stack.data[stack.top] == 1){
                      pop_d(&stack, &agrega);
                    }
                    parentesis-=1;
                }
                if(expresion[recorre] == '['){
                    corchetes = corchetes + push_d(&stack, agregamas);
                }
                if(expresion[recorre] == ']'){
                    if(stack.data[stack.top] == 10){
                      pop_d(&stack, &agregamas);
                    }
                    corchetes-=1;
                }
                recorre++;
                if(expresion[recorre] == '\0'){
                    if(stack.top == -1 && parentesis == 0 && corchetes == 0){
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
