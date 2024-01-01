#include "shellSort.h"

void shellSortCrescente(int *V, int N){
    int i , j , valor;
    int aux = 1;
    do {
        aux = 3*aux+1;
    }while(aux < N);
    do {
        aux /= 3;
        for(i = aux; i < N; i++) {
            valor = V[i];
            j = i - aux;
            while (j >= 0 && valor < V[j]) {
                V[j + aux] = V[j];
                j -= aux;
            }
            V[j + aux] = valor;
        }
    } while(aux > 1);
}

void shellSortDecrescente(int *V, int N){
    int i , j , valor;
    int aux = 1;
    do {
        aux = 3*aux+1;
    }while(aux < N);
    do {
        aux /= 3;
        for(i = aux; i < N; i++) {
            valor = V[i];
            j = i - aux;
            while (j >= 0 && valor > V[j]) {
                V[j + aux] = V[j];
                j -= aux;
            }
            V[j + aux] = valor;
        }
    } while(aux > 1);
}