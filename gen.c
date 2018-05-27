// Gera o caca palavras dado um tamanho, e opcinalmente um conjunto de palavras
#include "stdio.h"
#include "string.h"
// Gera o caca palavras dado um numero de linhas m e de colunas n
Caca* gerarCp(int m, int n){}
// Abre o caca palavras dado o nome do arquivo
Caca* abrirCp(char *nomeArquivo){
    
    int sz, j=0, i=0, size[] = {0,0};
    char* _line;                                                    // Guarda a linha da matriz 
    char ch = ' ';                                                  // Guarda o char auxiliar
    FILE* fp = fopen(strcat(nomeArquivo, ".txt"), "r");             // Abre o arquivo nomeArquivo.txt
    fseek(fp, 0L, SEEK_END);                                        // Acha o final do arquivo
    sz = 50 + (int)ftell(fp)/2;                                          // Diz o numero de caracteres do arquivo
    rewind(fp);                                                     // Volta o buffer
    
    _line = malloc (sizeof(char)*sz);                               // Aloca espaco pra o buffer do caca palavras
    fseek (fp, 4*sizeof(char), SEEK_SET);
    // Enquanto a posicao do ponteiro nao estiver no final do arquivo
    while (ftell(fp) < sz*2 && ch != EOF) {
        // Zera o char temporario
        ch = ' ';
        // Leitura do caca palavras
        while (ch != '\n' && ch != EOF){
            // Le caracter a caracter
            ch = fgetc(fp);
            // Se o caracter nao for ' '
            if (ch != ' ') {
                // Se ch for uma letra, faz a leitura da matriz em linha
                if (isupper(ch)) _line[i*size[0] + j] = ch;
                else _line[i*size[0] + j] = separator;
                // Senao joga o separador no buffer                
                j++;
            }
            // Guarda o valor do tamanho baseado na iteracao
            if ( i == 0 ) size[0] = j;
        }
        j = 0;
        i++;
    }
    // Guarda o tamanho y
    size[1] = i;
    // Char que vai guardar os caca palavras ao vez do buffer
    char new[size[0]*size[1]+1];
    // Fecha o arquivo
    fclose(fp);
    // Copia o conteudo do _line para o new
    strcpy(new, _line);
    // Cria o struct caca
    Caca* caca = create_caca(new, size[0]*size[1]+1, size[1]);
    return caca;

}
// Gera o caca palavras dado um numero m de linhas, um numero n de colunas e um vetor de palavras
int gerarCpPalavras(int m, int n, char **palavras){}
// Abre o terminal para entrar com a matriz com um numero m de linhas e n de colunas
Caca* lerCp(int m, int n){}
// Dado uma matriz matriz, gera um numero num de palavras dentro da matriz
char** genPalavras(char **matriz){}