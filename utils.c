// Utilidades em geral
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define separator '\n'
#define tab "\t\t"

// Seta pra frente
void printT(char text[]){
    printf (tab);
    printf ("%s", text);    
}
// Tabear
void tabbing(){
    printf (tab);
}

// Retorna o maior inteiro
int maior(int a, int b) { return a>=b?a:b; }

// Retorna o menor inteiro
int menor(int a, int b) { return a<=b?a:b; }

// Retorna a diferenca entre o maior e o menor
int difMm(int a, int b) { return (maior(a,b) - menor(a,b)); }

// Imprime uma matriz dada
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

// Inverte um vetor
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
    Dado uma matriz de strings de tamanho mn, retorna um vetor com os valores 
    em serie nas verticais, horizontais, diagonais e invertidas
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
            aux[count - cnt] = matriz[size[0] - j - 1][size[1] - k - 2];
            j++;    k++;    count++;
            
        }
        linearVetor[count] = separator;
        aux[count - cnt] = separator;
        count++;    
    }


    int val = count - cnt;

    for (i = 0; i < val; i++) { 
        if (i!=(count-cnt-2)) {
            if (aux[i] >= 'A' && aux[i] <= 'Z') {
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
    /*printf ("\n");
    tabbing();
    for (i = 0; i < count - 1; i++) {
        printf ("%c ", linearVetor[i] != separator?linearVetor[i]:'\n');
        if (linearVetor[i] == separator) tabbing();
        
    }*/
    linearVetor[count] = '\n';
    linearVetor[count++] = '\n';
    siz = inverterVetor(count, linearVetor, linearVetor);    
    /*for (i = 0; i < 2*count - 1; i++) {
        printf ("%c ", linearVetor[i] != separator?linearVetor[i]:'\n');
        if (linearVetor[i] == separator) tabbing();
        
    }*/
    Vector* finalVec = create_vec(siz);    
    for (i = 0; i < siz; i++) { finalVec->vec[i]=linearVetor[i]; }
    
    return finalVec;
}  
