// Verificacao de presenca de palavras na matriz
#include "stdio.h"

// Verifica se as palavras palavras estao no vetor de identificacao, retorna 0 se nao estiverem
int verPalavras(void* _palavras, char *identificacao, int maiorPalavra, int numPalavras){

    int i;
    char (*palavras)[maiorPalavra] = _palavras;
    for (i = 0; i < numPalavras; i++) {
        if (strstr(identificacao, palavras[i]) == NULL) return 0;
    }
    return 1;

}