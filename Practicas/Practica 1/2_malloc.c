#include <stdio.h>
#include <stdlib.h>

// Este metodo llena la lista
void llenaLista(int* lista, int tam){
	for (int i = 0; i < tam; ++i){
		lista[i] = i*2;
	}
}

// Este metodo imprime la lista
void muestraLista(int* lista, int tam){
	for (int i = 0; i < tam; ++i){
		printf("%d ", lista[i]);
	}
	printf("\n");
}

int main(){
	int tam;
	int *arreglo;

	printf("\tCREACION DE ARREGLO DE TAMANIO DINAMICO\n\n\n");
    
    printf("HDSPTM Jimbo\n");

	printf("INGRESA EL TAMANIO DEL ARREGLO\n");
	//scanf("%d", &tam);
	tam = 5;
	printf("EL TAMANIO DEL ARREGLO SERA DE %d CASILLAS\n", tam);
	arreglo = (int*)malloc(tam * sizeof(int));
	llenaLista(arreglo, tam);
	muestraLista(arreglo, tam);

	free(arreglo); // Libera la memora asignada

	printf("\n\nAHORA INGRESA EL TAMANIO DEL ARREGLO NUEVAMENTE\n");
	//scanf("%d", &tam);
	tam = 13;
	printf("AHORA EL TAMANIO DEL ARREGLO SERA DE %d CASILLAS\n", tam);
	arreglo = (int*)malloc(tam * sizeof(int));
	llenaLista(arreglo, tam);
	muestraLista(arreglo, tam);


	return 0;
}

