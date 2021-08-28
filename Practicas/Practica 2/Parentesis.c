#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define A (0)
#define B (1)
#define C (2)
#define D (3)

int main(){
    int estado, caracter;
    char expresion[100];
    
    estado = A;
    caracter = 0;
    printf("Ingresa la expresion algebraica\n");
    
    for(;;){
        switch(estado){
            case A:
                //gets(expresion);
                scanf("%[^\n]s", &expresion[0]);
                getchar();
                //caracter++;
                //if(expresion[caracter] == '\n'){
                    estado = B;
                //}
            break;
            case B:
                printf("Pasamos al estado B\n %s\n", expresion);
                sleep(1);
            break;
            case C:
            break;
            case D:
            break;
        }
    }
    return 0;
}
