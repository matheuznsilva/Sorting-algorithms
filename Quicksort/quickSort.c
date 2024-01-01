#include "quickSort.h"

int particionaCrescente(int *V, int inicio, int final){
	int aux;
	int esq = inicio+1;
	int dir = final;
	int pivo = V[inicio];
	while(esq <= dir){
		while(V[esq] <= pivo && V[esq] <= pivo){
			esq++;
		}
		while(V[dir] > pivo){
			dir--;
		}
		if(esq < dir){
			aux = V[esq];
			V[esq] = V[dir];
			V[dir] = aux;
		}
	}
	V[inicio] = V[dir];
	V[dir] = pivo;
	return dir;
}

int particionaDecrescente(int *V, int inicio, int final){
	int aux;
	int esq = inicio+1;
	int dir = final;
	int pivo = V[inicio];
	while(esq <= dir){
		while(V[esq] >= pivo && esq <= final){
			esq++;
		}
		while(V[dir] < pivo){
			dir--;
		}
		if(esq < dir){
			aux = V[esq];
			V[esq] = V[dir];
			V[dir] = aux;
		}
	}
	V[inicio] = V[dir];
	V[dir] = pivo;
	return dir;
}

void quickSort(int *V, int inicio, int fim, int tipo){
	int pivo;
	if(fim > inicio){
		if(tipo == 1){
			pivo = particionaCrescente(V, inicio, fim);
			quickSort(V, inicio, pivo-1, tipo);
			quickSort(V, pivo+1, fim, tipo);
		} else{
			pivo = particionaDecrescente(V, inicio, fim);
			quickSort(V, inicio, pivo-1, tipo);
			quickSort(V, pivo+1, fim, tipo);
		}
	}
}
