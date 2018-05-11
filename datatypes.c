#include <stdlib.h>

// Wrap para retornar um vetor numa funcao
typedef struct Vector_t {
    int length; 
    char vec[];
} Vector;

Vector* create_vec(int length) {
    Vector* vec = malloc(sizeof(Vector) + length*sizeof(char));
    if (vec != NULL) {
        vec->length = length;
    }
    
    return vec;
}

void delete_vec(Vector* vec) {
    
    free( vec );

}

// Wrap para retornar facilmente um vetor bidimensional numa funcao
typedef struct siz_t {
    int size[2];
} vecsize;

// Struct para guardar um caca palavras individual
typedef struct cacaPalavra_t {
    int linhas;
    Vector finder;
    Vector vec[];
} Caca;

// Struct para guardar um grupo de caca palavras
typedef struct cacaPalavras_t {
    int numcacas;
    Caca cacas[];
} Cacas;

Caca* create_caca(void ) 

