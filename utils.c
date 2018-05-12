// Utilidades em geral
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define separator 'e'

// MARSHAALLLLLL aqui voce vai fazer a sua funcao de gerar um char aleatorio entre A e Z 
// Retorna o maior inteiro
int maior(int a, int b) { return a>=b?a:b; }

// Retorna o menor inteiro
int menor(int a, int b) { return a<=b?a:b; }

// Retorna a diferenca entre o maior e o menor
int difMm(int a, int b) { return (maior(a,b) - menor(a,b)); }

// Imprime uma matriz dada
int printMatriz(void* _matriz, int size[2]){
    int i, j;
    printf ("%d %d\n", size[0], size[1]);
    // Casting de tipo
    char (*matriz)[size[1]] = _matriz;

    // Varrendo a matriz para buscar os valores
    for (i = 0; i < size[0]; i++) {
        for (j = 0; j < size[1]; j++)
            printf("%c' '", matriz[i][j]);
        putc('\n', stdout);
    }

    return 0;
}
// Inverte um vetor
int inverterVetor(int size, char vetor[size], char *newVec) {

    int i = 0;
    char ch = vetor[i];
    for (; i < size; i++) { newVec[size-i-1] = (vetor[i] > 'Z' || vetor[i] < 'A')? separator:vetor[i]; }
    newVec[i] = '\0';

    return 0;
}
/*  
    Dado uma matriz de strings de tamanho mn, retorna um vetor com os valores 
    em serie nas verticais, horizontais, diagonais e invertidas
*/
Vector* linearizarMatriz(void* _matriz, int size[2]) {

    int i, j, k, l, cnt, count = 0, siz;
    // Casting de tipo
    char (*matriz)[size[1]] = _matriz;
    // Definindo o tamanho do vetor linear
    int linearSize = (size[0] + 1)*(size[1] + 1)*4+(int)pow(menor(size[1] + 1, size[0] + 1), 2)+(int)(abs(size[0] - size[1]))+1;
    // Define o array que vai guardar todo os valores
    char linearVetor[linearSize];
    // Atribuindo ponteiros para poder fazer tudo no mesmo grupo iterador
    int *it1 = &j, *it2 = &k;
    int *sz1 = &size[0], *sz2 = &size[1];
    // Varrendo    
    for (i = 0; i < 2; i++){
        // Se estiver na segunda iteracao ele comeca a ler as verticais ao inves das horizontais
        if (i == 1) {
            it1 = &k;           it2 = &j;
            sz1 = &size[1];     sz2 = &size[0];
        }
        // Varrendo de fato
        for (*it1 = 0; *it1 < (*sz1)-2; (*it1)++){
            for (*it2 = 0; *it2 < (*sz2)+1; (*it2)++){
                linearVetor[count] = matriz[j][k];
                // printf ("%c", matriz[j][k]);
                count++;
            }
            linearVetor[count] = separator;
            // printf ("\n");
        }   
    }
    char aux[size[1]*size[0]];  cnt = count;
    // Varrendo as diagonais
    for (i = 0; i < 2*menor(size[1] + 1, size[0] + 1) + (int)abs( size[0] - size[1] ); i++){
        // Define uma rotina diferente caso o valor seja abaixo da diagonal principal
        if (i < size[0]) { j = size[0] - i; k = 0; }
        else { k = abs(size[0] - i); j = 0; }
        while ( j < size[0] && k < size[1]-1) {
            linearVetor[count] = matriz[j][k];
            aux[count - cnt] = matriz[size[0] - j - 1][size[1] - k - 1];
            // printf("%c ", matriz[j][k], j);
            j++;    k++;    count++;
        }
        // printf ("\n");
        linearVetor[count] = separator;
        aux[count - cnt] = separator;
        count++;    
    }
    // printf("end?\n");
    for (i = 0; i < (count - cnt); i++) { linearVetor[count] = (aux[i] > 'Z' || aux[i] < 'A') ? separator:aux[i]; count++; }
    linearVetor[count] = '\0';
    siz = (int)(sizeof(linearVetor)/sizeof(linearVetor[0]));
    char newVec[siz];
    inverterVetor(siz, linearVetor, newVec);    
    strcat(linearVetor, newVec); 
    Vector* finalVec = create_vec(siz);    
    for (i = 0; i < siz; i++) { finalVec->vec[i]=linearVetor[i]; }
    
    return finalVec;
}  
// Verifica se a primeira string esta contida na segunda, retorna 0 se nao
int simpleRegex( char *str1, char *str2 ) {

    int i, j;
    char tempCh = ' ';
    if (sizeof(str1) > sizeof(str2)) {
        return 0;
    } else
        for (i = 0; i < (strlen(str2) - strlen(str1)); i++)
            if (str1[0] == str2[i]) {
                j = 1;
                tempCh = str1[j];
                do {
                    if ( j == (strlen(str1)-2) && tempCh == str2[ i + j ]) return 1;
                    j++;
                    tempCh = str1[j];                    
                } while (tempCh == str2[ i + j ]);
            }

    return 0;
        
}
