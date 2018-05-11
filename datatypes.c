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
    int each_size;
    int linhas;
    Vector caca;
} Caca;

Caca* create_caca(char* _matriz, int size, int each_size){
    
    int i;
    Vector* vec = create_vec(size); 
    
    Caca* caca = malloc(sizeof(Caca) + sizeof(vec)*size);
    if (caca != NULL) {
        caca->linhas = size;
        for (i = 0; i < size; i++){
            (*vec).vec[i] = _matriz[i];
        }
        for (i = 0; i < size; i++){
            (*caca).caca.vec[i] = (*vec).vec[i];
        }
    }

    (*caca).each_size = each_size;
    
    return caca;
}


