# WordHunter
Caça palavras para o trabalho prático 1 de CAP
## Instruções de compilação
1. Certifique-se que os arquivos do caça-palavras estão na mesma pasta dos arquivos de código
2. Certifique-se de usar o sistema linux de preferência com gcc C99
3. Compile os arquivos da seguinte maneira: (com todas as flags)

```
    gcc main.c -o main -lm
```
4. Para executar use:

```
    ./main
```
## Descrição dos arquivos

* main.c
    - Tem a função principal main, que dado os parâmetros de entrada seleciona o menu
* utils.c
    - Tem as funções de uso geral do código, como por exemplo:
        * Impressão tabulada printT(char *)
        * Impressão de tabulação tabbing()
        * Máximo maior(int, int)
        * Mínimo menor(int, int)
        * Diferença entre o maior e o menor difMm(int, int)
        * Impressão de matriz printMatriz(void*, size*)
        * Inversão de vetor inverterVetor(int, char*, char*)
        * Linearização de vetor para geração de códice linearizarMatriz(void*, size*)
        * Geração de caracter aleatório getRandChar ()
* datatypes.c
    - Tem os seguintes tipos de dados:
        * Guarda um vetor de tamnaho variável Struct Vector_t
        * Vetor bidimensional siz_t
        *Guarda um caça-palavras individual Struct cacaPalavras_t
    - Ademais, há as seguintes funções
        * Inicializa um vetor de tamanho indeterminado Create_vec (int)
        * Deleta o vetor criado anteriormente delete_vec ()
        * Inicialização do Struct Caca (char, int, int)
* config.c
    - Inicializa novas defições de io do terminal 
        ```#include <termios.h>```
        para Linux e usa a função getc_()
        ```#include <conio.h>```
        para Windows e usa a função getche() 
* gen.c
    - Apresenta as seguintes funções:
        * Gera uma matriz para o caça-palvras gerarCp(int, int)
        * Abre a matriz caça-palavras, dado um certo nome abrirCp(char) 
        * Gera uma matriz e um vetor de palavras para o caça-palavras gerarCpPalavras(int, int, char)
        * Mostra o terminal para q se coloque a quantidade de linhas e colunas LerCp(int, int)
        *Gera um numero de palvras apartir de uma certa matriz genPalavras(char)
* ver.c
    - Apresenta as seguintes funções:
        * Verifica se as palavras fazem parte do vetor de indetificação verPalvras(void, char, int, int)   
        * Verifica se as no aruvio correponde com as do caça-palavras verArquivo (char, char, int)
* ui.c
    - Apresenta as seguintes funções:
        * Cálculo do número de digitos calcDig (long int)
        * Escrita dos caracteres do caça-palavras, em uppercase *fgets (char, int, int, int)
        * Entrada dos inteiros sem pular linhas getd()