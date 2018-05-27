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
* config.c
* gen.c
* ver.c
* ui.c