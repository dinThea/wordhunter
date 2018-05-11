#include <stdlib.h>

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