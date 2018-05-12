// Gera o caca palavras dado um tamanho, e opcinalmente um conjunto de palavras
#include "stdio.h"
#include "string.h"
// Gera o caca palavras dado um numero de linhas m e de colunas n
Caca* gerarCp(int m, int n){
    // 1. Funcao de gerar caracter aleatorio
    // 2. Definir uma matriz mxn
    // 3. Preencher com valores aleatorios
    // 4. So isso
    char matriz[m][n];
    return create_caca(matriz, 5, 2);
}
// Abre o caca palavras dado o nome do arquivo
Caca* abrirCp(char *nomeArquivo){
    
    int sz, j=0, i=0, size[] = {0,0};
    char* _line;
    char* _newline = NULL;
    char ch;
    FILE* fp = fopen(strcat(nomeArquivo, ".txt"), "r");
    fseek(fp, 0L, SEEK_END);
    sz = (int)ftell(fp)/2;
    rewind(fp);
    _line = malloc (sizeof(char)*sz);
    while (ftell(fp) < sz*2) {
        ch = ' ';
        while (ch != '\n' && ch != EOF){
            ch = fgetc(fp);
            if (ch != ' ') {
                if (ch>='A' && ch<='Z') _line[i*size[0] + j] = ch;
                else _line[i*size[0] + j] = separator;
                j++;    
            }
            if ( i == 0 ) size[0] = j;
        }
        j = 0;
        i++;
    }
    size[1] = i;
    char new[size[0]*size[1]+1];
    strcpy(new, _line);
    Caca* caca = create_caca(new, size[0]*size[1], size[1]);
    return caca;

}
// Gera o caca palavras dado um numero m de linhas, um numero n de colunas e um vetor de palavras
int gerarCpPalavras(int m, int n, char **palavras){}
// Abre o terminal para entrar com a matriz com um numero m de linhas e n de colunas
Caca* lerCp(int m, int n){
    int a;
    int a;
    int a;
    int a;
    int a;
    int a;
    int a;
    int a;
    int a;
    int a;
    int a;
    
    char matriz[m][n];
    // Mesma coisa do primeiro, so que ao inves de gerar aleatoriamente vc da entrada com o getch_
    return create_caca(matriz, 5, 2);
} 
// Dado uma matriz matriz, gera um numero num de palavras dentro da matriz
char** genPalavras(char **matriz){}