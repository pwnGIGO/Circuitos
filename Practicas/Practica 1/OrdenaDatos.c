#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//#include<windows.h>

#define estado0 (0)
#define estado1 (1)
#define estado2 (2)

/*void re(int k, int A[]){
        printf("\r Cuantos numeros desea ordenar\n");
        scanf("%d",&k);
        int A[k];
}*/

int main(){
    int state,k,i,m,t,m2;
    k=0;
    int *A;// A es un apuntador
    state =estado0;
    i=0;
    m2=0;
    for(;;){

        switch(state){
            case estado0:
            m=0;
            t=0;

            if(m2==0){
                //printf("\r EL dato %d:   *%d*? ",A[i],k);
                printf("\r Cuantos numeros desea ordenar?\n");
                scanf("%d",&k);
                A = (int*)malloc(k * sizeof(int));//Esta orden manda al apuntador a reservar memoria de k lugares para numeros enteros
                getchar();
                m2 = 1;
            }

            if(i<k){
                A[i]=0;
                i++;
            }else{
                if(k>1){
                    state = estado1;
                    i=0;
                }else{
                    state=estado0;
                }
            }
            break;
            case estado1:
            if(i<k && m==0){
                printf("\r Ingresa el dato %d:   *%d* ",i,k);
                scanf("%d",&A[i]);
                getchar();
                printf("\r EL dato %d:;;;",A[i]);
                i++;
                printf("\r DDD %d DDD   *%d* ",i,k);
            }else{
                printf("\r PPP %d DDD   *%d* ",i,k);
                m=1;
                if(m==1){
                    i=0;
                    m=2;
                }else{
                    if(i<k){
                        if(i==0){
                            printf("\r Tu lista de datos ingresados es \n");
                        }
                        printf("\r %d \t",A[i]);
                        i++;
                    }else{
                        i=0;
                        printf("\r Tu lista de dados ordenados es: ??%d?%d? \n",i,k);
                        state=estado2;
                    }
                }
            }

            break;
            case estado2:
            printf("\r  %d:   ** ",i);
            if(i<k){
                if(A[i]>A[i+1]){
                    t=A[i];
                    A[i]=A[i+1];
                    A[i+1]=t;

                }
                i++;
                printf("\r %d \t",t);
            }else{
                i=0;
                printf("\r  \n");
                state=estado0;
            }
            break;
        }
    }
}
