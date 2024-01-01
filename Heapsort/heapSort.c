#include "heapSort.h"

void criaHeapCrescente(int *vet, int i, int f){
    int aux = vet[i];
    int j = i * 2 + 1;
    while (j <= f){
        if(j < f){
            if(vet[j] < vet[j + 1]){
                j = j + 1;
            }
        }
        if(aux < vet[j]){
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }else{
            j = f + 1;
        }
    }
    vet[i] = aux;
}

void criaHeapDecrescente(int *vet, int i, int f){
    int aux = vet[i];
    int j = i * 2 + 1;
    while (j <= f){
        if(j < f){
            if(vet[j] > vet[j + 1]){
                j = j + 1;
            }
        }
        if(aux > vet[j]){
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        } else {
            j = f + 1;
        }
    }
    vet[i] = aux;
}

void heapSort(int *vet, int N, int tipo){
    int i, aux;
    if(tipo == 1){
        for(i=(N - 1)/2; i >= 0; i--){
            criaHeapCrescente(vet, i, N-1);
        }  
        for (i = N-1; i >= 1; i--){
            aux = vet[0];
            vet [0] = vet [i];
            vet [i] = aux;
            criaHeapCrescente(vet, 0, i - 1);
        }   
    } else{
        for(i=(N - 1)/2; i >= 0; i--){
            criaHeapDecrescente(vet, i, N-1);
        }  
        for (i = N-1; i >= 1; i--){
            aux = vet[0];
            vet [0] = vet [i];
            vet [i] = aux;
            criaHeapDecrescente(vet, 0, i - 1);
        }
    }
}