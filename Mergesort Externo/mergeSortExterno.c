#include "mergeSortExterno.h"

void mergeSortExterno(char *nome, int BUFFER){
    char novo[TAM];
    int K = criaArquivosOrdenados(nome, BUFFER);
    int T = BUFFER / (K+1);
    remove(nome);
    merge(nome, K, T);
    for(int i=0; i<K; i++){
        sprintf(novo, "Temp%d.txt", i+1);
        remove(novo);
    }
}

void salvaArquivo(char *nome, int *V, int tam, int mudaLinhaFinal){
    FILE *arq = fopen(nome, "a");
    for(int i=0; i<tam-1; i++){
        fprintf(arq, "%d\n", V[i]);
    }
    if(mudaLinhaFinal == 0){
        fprintf(arq, "%d", V[tam-1]);
    } else{
        fprintf(arq, "%d\n", V[tam-1]);
    } 
    fclose(arq);
}

int criaArquivosOrdenados(char *nome, int BUFFER){
    int *V = (int *) malloc(BUFFER * sizeof(int));
    int K = 0, total = 0;
    char novo[TAM];
    FILE *arq = fopen(nome, "r");
    while(!feof(arq)){
        fscanf(arq, "%d", &V[total]);
        total++;
        if(total == BUFFER){
            K++;
            sprintf(novo, "Temp%d.txt", K);
            quickSort(V, 0, BUFFER-1, 1);
            salvaArquivo(novo, V, total, 0);
            total = 0;
        }
    }
    if(total > 0){
        K++;
        sprintf(novo, "Temp%d.txt", K);
        quickSort(V, 0, total-1, 1);
        salvaArquivo(novo, V, total, 0);
    }
    fclose(arq);
    free(V);
    return K;
}

void merge(char *nome, int K, int T){
    char novo[TAM];
    int menor, qtdSaida = 0, *saida = (int *) malloc(T*sizeof(int));
    Arquivo* arq = (Arquivo *) malloc(K*sizeof(Arquivo));
    for(int i=0; i<K; i++){
        sprintf(novo, "Temp%d.txt", i+1);
        arq[i].f = fopen(novo, "r");
        arq[i].buffer = (int *) malloc(T*sizeof(int));
        preencherBuffer(&arq[i], T);
    }
    while(procuraMenor(arq, K, T, &menor) == 1){
        saida[qtdSaida] = menor;
        qtdSaida++;
        if(qtdSaida == T){
            salvaArquivo(nome, saida, T, 1);
            qtdSaida = 0;
        }
    }
    if(qtdSaida != 0){
        salvaArquivo(nome, saida, qtdSaida, 1);
    }
    for(int i=0; i<K; i++){
        free(arq[i].buffer);
    }
    free(arq);
    free(saida);
}

void preencherBuffer(struct arquivo* arq, int T){
    if(arq->f == NULL){
        return;
    }
    arq->pos = 0;
    arq->MAX = 0;
    for(int i=0; i<T; i++){
        if(!feof(arq->f)){
            fscanf(arq->f, "%d", &arq->buffer[arq->MAX]);
            arq->MAX++;
        } else{
            fclose(arq->f);
            arq->f = NULL;
            break;
        }
    }
}

int procuraMenor(Arquivo* arq, int K, int T, int* menor){
    int idx = -1;
    for(int i=0; i<K; i++){
        if(arq[i].pos < arq[i].MAX){
            if(idx == -1){
                idx = i;
            } else{
                if(arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos]){
                    idx = i;
                }
            }
        }
    }
    if(idx != -1){
        *menor = arq[idx].buffer[arq[idx].pos];
        arq[idx].pos++;
        if(arq[idx].pos == arq[idx].MAX){
            preencherBuffer(&arq[idx], T);
        }
        return 1;
    } else{
        return 0;
    }
}