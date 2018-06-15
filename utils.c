// Utilidades em geral
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
char separator = '\n';

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
int inverterVetor(int size, char *vetor, char *newVec) {

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
Codex* linearizarMatriz(void* _matriz, int size[2]) {

    int i, j, k, l, cnt, count = 0, siz = 0, siz1 = size[1]-1;
    char valueSaver[size[0]][size[1]];    
    //printf ("\n%d\n", &(*_matriz));
    //char (*matriz)[size[0]][size[1]] = _matriz;
    char *ptr = _matriz;
    char *matriz[size[0]][size[1]];
    for (i = 0; i < size[0]; i++){
        for (j = 0; j < size[1]; j++) {
            matriz[i][j] = ptr;
            valueSaver[i][j] = *matriz[i][j];
            ptr+=sizeof(char*);
        }
        ptr+=sizeof(char*);
    }
        
    // Casting de tipo
    //char (**matriz)[size[1]] = _matriz;
    int linearSize = 2*(size[0] + 1)*(size[1] + 1)*4+(int)pow(menor(size[1] + 1, size[0] + 1), 2)+(int)(abs(size[0] - size[1]))+1;
    // Define o array que vai guardar todo os valores
    char **linearVetor = malloc(linearSize*sizeof(char*));
    // Atribuindo ponteiros para poder fazer tudo no mesmo grupo iterador
    int *it1 = &j, *it2 = &k;
    int *sz1 = &size[0], *sz2 = &size[1];
    // Varrendo    
    for (i = 0; i < 2; i++){
        // Se estiver na segunda iteracao ele comeca a ler as verticais ao inves das horizontais
        if (i == 1) {
            it1 = &k;           it2 = &j;
            sz1 = &siz1;         sz2 = &size[0];
            siz = 1;
        }
        // Varrendo de fato
        for (*it1 = 0; *it1 < (*sz1) + siz; (*it1)++){
            for (*it2 = 0; *it2 < (*sz2); (*it2)++){
                linearVetor[count] = matriz[j][k];
                // printf ("%c ", *linearVetor[count]);
                count++;
            }
            linearVetor[count] = &separator;
            count++;
            // printf ("\n");
        }   
    }

    char **aux = malloc(sizeof(char*)*(size[1]+1)*(size[0]+1));
    cnt = count;
    // Varrendo as diagonais
    for (i = 0; i < 2*menor(size[1] + 1, size[0] + 1) + (int)abs( size[0] - size[1] ); i++){
        // Define uma rotina diferente caso o valor seja abaixo da diagonal principal
        if (i < size[0]) { j = size[0] - i - 1; k = 0; }
        else { k = abs(size[0] - i); j = 0; }
        while ( j < size[0] && k < size[1]) {
            char temp = *matriz[j][k];
            char *ptr;
            ptr = matriz[j][k];
            linearVetor[count] = ptr;
            // Le valor a valor da diagonal e atribui tanto para pra linearVetor tanto para aux que guarda as diagonais inversas
            aux[count - cnt] = matriz[size[0] - j - 1][size[1] - k - 1];
            // printf ("%c ", *aux[count - cnt]);
            j++;    k++;    count++;
            
        }        
        // printf ("\n");
        // Se pular linha guarda o valor do separador
        linearVetor[count] = &separator;
        aux[count - cnt] = &separator;
        count++;    
    }
    for (i = 0; i < size[0]; i++) {
        for (j = 0; j < size[1]; j++) *matriz[i][j] = valueSaver[i][j];
    }

    int val = count - cnt;
    // Inverte a matriz
    for (i = 0; i < val - 1; i++) { 
        linearVetor[count] = aux[i];
        // printf ("%c ", *aux[i]);
        count++;
    }
    // for (i = 0; i < count; i++) printf ("%c ", *linearVetor[i]);            

    linearVetor[count] = &separator;
    linearVetor[count++] = &separator;

    // for (i = 0; i < count; i++) { printf ("%c ", *linearVetor[i]); }
    // for (i = 0; i < count; i++) printf ("%c", linearVetor[count]);
    // Concatena o vetor de saida com ele mesmo invertido
    // siz = inverterVetor(count, linearVetor, linearVetor);    

    Codex* finalVec = create_codex(count+1);    
    finalVec->length = count+1;
    // Para cada termo do vetor e atribuido no struct finalvec 
    for (i = 0; i < count; i++) { 
        finalVec->vec[i]=linearVetor[i]; 
        // printf ("%c ", *(finalVec->vec[i]));
    }
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
