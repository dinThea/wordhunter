// Verificacao de presenca de palavras na matriz
#include "stdio.h"

// Verifica se as palavras palavras estao no vetor de identificacao, retorna 0 se nao estiverem
int verPalavras(void* _palavras, char *identificacao, int maiorPalavra, int numPalavras){

    int i;
    char (*palavras)[maiorPalavra] = _palavras;
    //  Sera verficado todas as palavras da lista
    for (i = 0; i < numPalavras; i++) {

        //Caso o valor da palavra, q esta sendo verificado seja nulo, sera retornado a zero
        if (strstr(identificacao, palavras[i]) == NULL) return 0;
    }
    return 1;

}

// Verifica se as palavras no arquivo correspondem as palavras do caca palavras
int verArquivo(char *flatten, char* _filename, int sizeName){

    int MAX_SIZE = 100, i, j = 0;
    char namefile[sizeName+4], ch;
    // Ocorre uma transformação para array
    for (i = 0; i < sizeName; i++) {
        namefile[i] = _filename[i];
    }

    // Aberura do arquivo 
    FILE* fp = fopen (strcat(namefile, ".txt"), "r");
    char *name = malloc (sizeof(char)*MAX_SIZE);                           // Alocacao dinamica para definir o espaco do ponteiro
    ch = fgetc(fp);

    // Leitura do arquivo
    while (ch != EOF) {

        // Enquanto o ch nao for espaco ou o final do arquivo
        while (!isspace(ch) && ch!=EOF) {

            // Define a quantidade de termos em cada linha
            if (j == MAX_SIZE) name = realloc(name, 2*j);
            name[j] = ch;
            j++;
            ch = fgetc(fp);    
        }
        name[j] = '\0';                                                  // E
        j=0;
        ch = fgetc(fp);

        // Caso o valor do termo do arquivo for nulo, a funcao retornara a zero
        if (strstr(flatten, name) == NULL) return 0;
    }
    return 1;

}