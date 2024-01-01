#include "selectionSort.h"

void selectionSortCrescente(int *V, int N){
    int i, j, menor, troca;
    for(i = 0; i < N-1; i++){
        menor = i;
        for(j = i+1; j < N; j++){
            if(V[j] < V[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }            
    }
}

void selectionSortDecrescente(int *V, int N){
    int i, j, maior, troca;
    for(i = 0; i < N-1; i++){
        maior = i;
        for(j = i+1; j < N; j++){
            if(V[j] > V[maior]){
                maior = j;
            }
        }
        if(i != maior){
            troca = V[i];
            V[i] = V[maior];
            V[maior] = troca;
        }            
    }
}