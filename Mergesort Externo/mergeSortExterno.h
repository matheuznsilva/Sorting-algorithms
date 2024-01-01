#include <time.h>
#include "Quicksort/quickSort.h"

#define TAM 30
#define N 100

struct arquivo{
    FILE *f;
    int pos, MAX, *buffer;
};

typedef struct arquivo Arquivo;

void mergeSortExterno(char *nome, int BUFFER);
void salvaArquivo(char *nome, int *V, int tam, int mudaLinhaFinal);
int criaArquivosOrdenados(char *nome, int BUFFER);
void merge(char *nome, int K, int T);
void preencherBuffer(Arquivo* arq, int T);
int procuraMenor(Arquivo* arq, int K, int T, int* menor);