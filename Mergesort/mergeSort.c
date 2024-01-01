#include "mergeSort.h"

void mergeCrescente(int *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(V[p1] < V[p2]){
                    temp[i]=V[p1++];
                } else{
                       temp[i]=V[p2++];
                }
                if(p1>meio){ 
                    fim1=1;
                }
                if(p2>fim){ 
                    fim2=1;
                }         
            } else{
                    if(!fim1){
                    temp[i]=V[p1++];
                }
                else{
                    temp[i]=V[p2++];
                }
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++){
            V[k]=temp[j];
        }
    }
    free(temp);
}

void mergeDecrescente(int *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(V[p1] > V[p2]){
                    temp[i]=V[p1++];
                } else{
                       temp[i]=V[p2++];
                }
                if(p1>meio){ 
                    fim1=1;
                }
                if(p2>fim){ 
                    fim2=1;
                }         
            } else{
                    if(!fim1){
                    temp[i]=V[p1++];
                }
                else{
                    temp[i]=V[p2++];
                }
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++){
            V[k]=temp[j];
        }
    }
    free(temp);
}

void mergeSort(int *V, int inicio, int fim, int tipo){
    int meio;
    if(inicio < fim){
        if(tipo == 1){
            meio = floor((inicio+fim)/2);
            mergeSort(V,inicio,meio, tipo);
            mergeSort(V,meio+1,fim, tipo);
            mergeCrescente(V,inicio,meio,fim);
        } else{
            meio = floor((inicio+fim)/2);
            mergeSort(V,inicio,meio, tipo);
            mergeSort(V,meio+1,fim, tipo);
            mergeDecrescente(V,inicio,meio,fim);
        }
    }
}
