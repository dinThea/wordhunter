// Gera o caca palavras dado um tamanho, e opcinalmente um conjunto de palavras
#include "stdio.h"
#include "string.h"
// Gera o caca palavras dado um numero de linhas m e de colunas n
int gerarCp(int m, int n){}
// Abre o caca palavras dado o nome do arquivo
vecsize* abrirCp(char *nomeArquivo){
    
    vecsize* vec;
    char ch;
    FILE* fp = fopen(strcat(nomeArquivo, ".txt"), "r");
    ch = fgetc(fp);
    while (ch != EOF) {
        while (ch != '\n'){
            ch = fgetc(fp);
            if 
        }
    }
    return vec;

}
// Gera o caca palavras dado um numero m de linhas, um numero n de colunas e um vetor de palavras
int gerarCpPalavras(int m, int n, char **palavras){}
// Abre o terminal para entrar com a matriz com um numero m de linhas e n de colunas
char** lerCp(int m, int n){} 
// Dado uma matriz matriz, gera um numero num de palavras dentro da matriz
char** genPalavras(char **matriz){}