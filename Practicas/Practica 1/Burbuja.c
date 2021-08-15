#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define A (0)
#define B (1)
#define C (2)
#define D (3)
#define E (4)

int main(){
    
    int contador, vueltas, recorre, k, estado, apoyo, r, *arreglo;
    
    estado = A;
    
    for(;;){
        switch(estado){
            case A:
                contador = 0;
                vueltas = 0;
                recorre = 0;
                apoyo = 0;
                k = 0;
                r = 0;
                
                printf("Dame el valor de k: ");//Se solicita al usuario el numero k
                scanf("%d", &k);
                getchar();
                
                arreglo = (int*)malloc(k * sizeof(int));
                
                if(k <= 0){
                    printf("El numero que ingresaste es invalido, ingresa un numero positivo\n\n");
                    estado = A;
                }else{
                    estado = B;
                }
                
             break;
            case B:
                
                  printf("\nIngresa el dato %d: ", contador+1);
                  scanf("%d",&arreglo[contador]);
                  getchar();
                  contador++;
                if(contador == k){
                  estado = C;
                }

             break;
            case C:
                
                if(r < k){
                  printf("%d\t", arreglo[r]);
                  r++;
                }
                if(r == k){
                    if(recorre == k-(vueltas+1)){
                        recorre = 0;
                        vueltas++;
                    }
                  printf("\n");
                  estado = D;
                }
                if(vueltas == k-1){
                  estado = A;
                }
               // sleep(1);
             break;
                
            case D:
                
                if(arreglo[recorre] > arreglo[recorre+1]){
                    apoyo = arreglo[recorre];
                    arreglo[recorre] = arreglo[recorre+1];
                    arreglo[recorre+1] = apoyo;
                }
                if(recorre < k-(vueltas+1)){
                  recorre++;
                  r = 0;
                  estado = C;
                }
                
             break;
                
        }

    }
    return 0;
}

