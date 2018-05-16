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
int verArquivo(char *flatten, char* _filename, int sizeName){

    int MAX_SIZE = 100, i, j = 0;
    char namefile[sizeName+4], ch;
    for (i = 0; i < sizeName; i++) {
        namefile[i] = _filename[i];
    }
    FILE* fp = fopen (strcat(namefile, ".txt"), "r");
    char *name = malloc (sizeof(char)*MAX_SIZE);
    ch = fgetc(fp);
    while (ch != EOF) {
        while (!isspace(ch) && ch!=EOF) {
            if (j == MAX_SIZE) name = realloc(name, 2*j);
            name[j] = ch;
            j++;
            ch = fgetc(fp);    
        }
        name[j] = '\0';
        j=0;
        ch = fgetc(fp);
        if (strstr(flatten, name) == NULL) return 0;
    }
    return 1;

}