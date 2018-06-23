// Verificacao de presenca de palavras na matriz
#include "stdio.h"

#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_BACKCOLOR_BLACK "\x1b[47m"

/*  Objetivo: Verifica se as palavras estao no vetor de identificacao, retorna 0 se nao estiverem
    Parametros formais:
    (void* _palavras): Lista de palavras
    (char *identificacao): Palavra a ser identificacao
    (int maiorPalavra): tamanho da maior palavra
    (int numPalavras): numero de palavras 
*/
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

/*  Objetivo: Verifica se as palavras no arquivo correspondem com as palavras do caca palavras
    Parametros formais:
    (char *flatten): Vetor que vai recever a matriz linearizada
    (char *_filename): Nome do arquivo
    (int sizeName): tamanho do nome
*/
int verArquivo(Codex *flatten, char* _filename, int sizeName, int sizeFlatten, Codex *palavras, int *numpalavras){

    int MAX_SIZE = 100, i, j = 0, k, count, countPalavras = 0;
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
        name[j] = '\0';
        j=0;
        ch = fgetc(fp);
        count = 0;
        // Caso o valor do termo do arquivo for nulo, a funcao retornara a zero
        for (j = 0; j < sizeFlatten - strlen(name); j++) {
            if (count == strlen(name)) break;                                    
            for (i = 0; i < strlen(name); i++) {
                if (count == strlen(name)) break;                                        
                if (*(flatten->vec[j+i]) == name[i]){
                    count++;
                    if (count == strlen(name)) {
                        for (k = 0; k < strlen(name); k++) {
                            palavras->vec[countPalavras] = flatten->vec[j+i-k];
                            countPalavras++;
                            //printf ("%c\n", *(palavras->vec[countPalavras]));         
                        }
                        break;
                    }
                } else {
                    count=0;                   
                    break;
                }
            }
        }
        if (count != strlen(name)) {
            for (j = sizeFlatten - 2; j >= 0; j--) {
                if (count == strlen(name)) break;                                    
                for (i = 0; i < strlen(name); i++) {
                    if (count == strlen(name)) break;                                        
                    if (*(flatten->vec[j-i]) == name[i]){
                        count++;                        
                        if (count == strlen(name)) {
                            for (k = 0; k < strlen(name); k++) {
                                palavras->vec[countPalavras] = flatten->vec[j-i+k];
                                // printf ("%c\n", *(palavras->vec[countPalavras]));                                     
                                countPalavras++;
                            }
                            break;
                        }
                    } else {
                        count=0;                   
                        break;
                    }
                }
            }
    
        }
        *numpalavras+=1;
        // for (i = 0; i < countPalavras-1; i++) printf ("%c", *(palavras->vec[i]));
        palavras->length = countPalavras;
        if (count != strlen(name)) return 0;
        j = 0;

    }
    return 1;

}
