#include <stdio.h>

void llenaLista(int* lista, int tam){
	for (int i = 0; i < tam; ++i){
		lista[i] = i*2;
	}
}

void muestraLista(int* lista, int tam){
	for (int i = 0; i < tam; ++i){
		printf("%d ", lista[i]);
	}
	printf("\n");
}

int main(){

	printf("\tCREACION DE ARREGLO DE TAMANIO ESTATICO\n");
	int tam;
	printf("INGRESA EL TAMANIO DEL ARREGLO\n");
	//scanf("%d", &tam);
	tam = 5;
	printf("EL TAMANIO DEL ARREGLO SERA DE %d CASILLAS\n", tam);
	int arreglo[tam];
	llenaLista(arreglo, tam);
	muestraLista(arreglo, tam);
	return 0;
}

