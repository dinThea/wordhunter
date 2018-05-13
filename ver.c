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

// Verifica se as palavras no arquivo correspondem as palavras do caca palavras
int verArquivo(char *flatten, void* _filename, int sizeName){

    int MAX_SIZE = 100, i, j = 0, sz;
    char (*filename)[sizeName+4] = _filename;
    FILE* fp = fopen (strcat(*filename, ".txt"), "r");
    char ch = fgetc(fp);    
    char *name = malloc (sizeof(char)*MAX_SIZE);
    fseek(fp, 0L, SEEK_END);
    sz = (int)ftell(fp)/2;
    rewind(fp);
    for (i = 0; i < sz; i++) {
        while (!isspace(ch)) {
            if (j == MAX_SIZE) name = realloc(name, 2*j);
            name[j] = ch;
            j++;
            ch = fgetc(fp);    
        }
        name[j] = '\0';
        j=0;
        if (strstr(flatten, name) == NULL) return 0;
    }
    return 1;

}