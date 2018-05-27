// Utilidades em geral
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define separator '\n'
#define tab "\t\t"

/*  Objetivo: Seta pra frente
    Parametros formais:
    (char text[]): entrada, sera impresso
*/
void printT(char text[]){
    printf (tab);
    printf ("%s", text);    
}
//  Objetivo: Tabear
void tabbing(){
    printf (tab);
}

/*  Objetivo: Retorna o maior inteiro
    Parametros formais:
    (int a, int b): valores de entrada a serem comparados
*/
int maior(int a, int b) { return a>=b?a:b; }

/*  Objetivo: Retorna o menor inteiro
    Parametros formais:
    (int a, int b): valores de entrada a serem comparados
*/
int menor(int a, int b) { return a<=b?a:b; }

/*  Objetivo: Retorna a diferenca entre o maior e o menor
    Parametros formais:
    (int a, int b): valores de entrada a serem comparados
*/
int difMm(int a, int b) { return (maior(a,b) - menor(a,b)); }

/*  Objetivo: Imprime uma matriz dada
    Parametros formais:
    (void* _matriz): ponteiro de ponteiro para a matriz de entrada
    (int size[2]): vetor de tamanho
*/
int printMatriz(void* _matriz, int size[2]){
    int i, j;
    // printf ("%d %d\n", size[0], size[1]);
    // Casting de tipo
    char (*matriz)[size[1]] = _matriz;

    // Varrendo a matriz para buscar os valores
    for (i = 0; i < size[0]; i++) {
        for (j = 0; j < size[1]; j++)
            printf("%c", matriz[i][j]);
        putc('\n', stdout);
    }

    return 0;
}

/*  Objetivo: Inverte um vetor
    Parametros formais:
    (int size): tamanho do vetor de entrada
    (char vetor[size]): Vetor de entrar a ser invertido
    (char *newVec): ponteiro para o vetor de saida
*/  
int inverterVetor(int size, char vetor[size], char *newVec) {

    int i = 0;
    newVec[size+1] = '\n';
    for (; i < (size+1); i++) { 
        newVec[size+i] = (vetor[size-i] > 'Z' || vetor[size-i] < 'A')? separator:vetor[size-i]; 
    }
    for (i=0; i < 2*(size+1); i++) {
        if ((newVec[i]<'A' || newVec[i]>'Z') && newVec[i]!='\n') newVec[i]='\n';
    }
    newVec[i] = '\0';
    
    return i;
}
/*  
    Objetivo: Dado uma matriz de strings de tamanho mn, retorna um vetor com os valores 
    em serie nas verticais, horizontais, diagonais e invertidas
    Parametros formais:
    (void *_matriz): ponteiro para ponteiro, parametro de entrada para passar a matriz
    (int size[2]): vetor do tamanho da matriz
*/
Vector* linearizarMatriz(void* _matriz, int size[2]) {

    int i, j, k, l, cnt, count = 0, siz, siz1 = size[1]-1;
    // Casting de tipo
    char (*matriz)[size[1]] = _matriz;
    // Definindo o tamanho do vetor linear
    int linearSize = 2*(size[0] + 1)*(size[1] + 1)*4+(int)pow(menor(size[1] + 1, size[0] + 1), 2)+(int)(abs(size[0] - size[1]))+1;
    // Define o array que vai guardar todo os valores
    char linearVetor[linearSize*sizeof(char)];
    // Atribuindo ponteiros para poder fazer tudo no mesmo grupo iterador
    int *it1 = &j, *it2 = &k;
    int *sz1 = &size[0], *sz2 = &siz1;
    // Varrendo    
    for (i = 0; i < 2; i++){
        // Se estiver na segunda iteracao ele comeca a ler as verticais ao inves das horizontais
        if (i == 1) {
            it1 = &k;           it2 = &j;
            sz1 = &siz1;         sz2 = &size[0];
        }
        // Varrendo de fato
        for (*it1 = 0; *it1 < (*sz1); (*it1)++){
            for (*it2 = 0; *it2 < (*sz2); (*it2)++){
                linearVetor[count] = matriz[j][k];
                count++;
            }
            linearVetor[count] = separator;
            count++;
            // printf ("\n");
        }   
    }

    char aux[(size[1]+1)*(size[0]+1)];  cnt = count;
    // Varrendo as diagonais
    for (i = 0; i < 2*menor(size[1] + 1, size[0] + 1) + (int)abs( size[0] - size[1] ); i++){
        // Define uma rotina diferente caso o valor seja abaixo da diagonal principal
        if (i < size[0]) { j = size[0] - i - 1; k = 0; }
        else { k = abs(size[0] - i); j = 0; }
        while ( j < size[0] && k < size[1]-1) {
            linearVetor[count] = matriz[j][k];
            // Le valor a valor da diagonal e atribui tanto para pra linearVetor tanto para aux que guarda as diagonais inversas
            aux[count - cnt] = matriz[size[0] - j - 1][size[1] - k - 2];
            j++;    k++;    count++;
            
        }
        // Se pular linha guarda o valor do separador
        linearVetor[count] = separator;
        aux[count - cnt] = separator;
        count++;    
    }


    int val = count - cnt;
    // Inverte a matriz
    for (i = 0; i < val; i++) { 
        if (i!=(count-cnt-2)) {
            if (aux[i] >= 'A' && aux[i] <= 'Z') {
                // Se nao for letra maiuscula, joga o separador na matriz
                linearVetor[count] = (aux[i] > 'Z' || aux[i] < 'A') ? separator:aux[i]; 
                count++; 
            }
            else {
                if (aux[i+1] < 'A' || aux[i+1] > 'Z'){}
                else {
                    linearVetor[count] = separator;
                    count++;
                }
            } 
        }
    }

    linearVetor[count] = '\n';
    linearVetor[count++] = '\n';

    // Concatena o vetor de saida com ele mesmo invertido
    siz = inverterVetor(count, linearVetor, linearVetor);    

    Vector* finalVec = create_vec(siz);    

    // Para cada termo do vetor e atribuido no struct finalvec 
    for (i = 0; i < siz; i++) { finalVec->vec[i]=linearVetor[i]; }
    
    return finalVec;
} 

/*  Objetivo: Gera um caracter aleatorio
*/
char getRandChar () {

    // Coloca uma seed aaleatoria 
    srand(rand());
    int num = rand();
    srand(rand());
    // PEga o intervalo randomico em intervalo de caracteres
    return (char) ('A' + (int) (((double) ('Z'-'A'))/ (RAND_MAX) * num));

}
