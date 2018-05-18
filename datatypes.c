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
    int siz;
    Vector caca;
} Caca;

Caca* create_caca(char* _vetor, int size, int each_size){
    
    int i;
    Vector* vec = create_vec(size); 
    
    Caca* caca = malloc(sizeof(Caca) + sizeof(vec)*size);
    caca->siz = size;
    if (caca != NULL) {
        caca->linhas = size;
        for (i = 0; i < size; i++){
            (*vec).vec[i] = _vetor[i];
        }
        for (i = 0; i < size; i++){
            (*caca).caca.vec[i] = (*vec).vec[i];
        }
    }

    (*caca).each_size = each_size;
    
    return caca;
}

typedef union String_set {

    char identifier[2];
    char ch;
    int pos[2];
    int color[2];

} Nstring;

typedef struct Rectangles {
    
    char identifier[2];
    int color;
    int pos[4]; // x0 y0 x1 y1

} Rec_t;

typedef struct Rectangle_set {

    int lenght; 
    Rec_t rectangles[];

} Curses_t;

Curses_t* addRectangle (Curses_t* preview, int color, int pos[4], char identifier[2]) {

    int i, j;
    Curses_t* cur;
    cur = malloc (sizeof(*preview) + sizeof(Rec_t) + sizeof(char)*2 + sizeof(int));
    if (cur != NULL) {
        for (i = 0; i < (*preview).lenght; i++)
            for (j = 0; j < 4; j++) {
                cur->rectangles[i].color = (*preview).rectangles[i].color;
                cur->rectangles[i].pos[j] = (*preview).rectangles[i].pos[j];
                cur->rectangles[i].identifier[0] = (*preview).rectangles[i].identifier[0];
                cur->rectangles[i].identifier[1] = (*preview).rectangles[i].identifier[1];                                                
            }
        cur->rectangles[i].color = color;
        for (j = 0; j < 4; j++) cur->rectangles[i].pos[j] = pos[j];
        for (j = 0; j < 2; j++) cur->rectangles[i].identifier[j] = identifier[j];
        cur->lenght = preview->lenght+1;
    }

    return cur;

}

// Procura por um retangulo em preview, e o deleta procurando pelo identificador, se nao achar retorna o preview
Curses_t* deleteRectangle (Curses_t* preview, char identifier[2]) {
    
    int i, j, k=0;
    Curses_t* cur;
    cur = malloc(sizeof(*preview));
    for (i = 0; i < (*preview).lenght+k; i++) {
        if ((*preview).rectangles[i].identifier[0]==identifier[0] && (*preview).rectangles[i].identifier[1]==identifier[1]) {
            k=1;
            (*cur).lenght = (*preview).lenght--;
        }
        for (j = 0; j < 4; j++) {
            cur->rectangles[i].color = (*preview).rectangles[i+k].color;
            cur->rectangles[i].pos[j] = (*preview).rectangles[i+k].pos[j];
            cur->rectangles[i].identifier[0] = (*preview).rectangles[i+k].identifier[0];
            cur->rectangles[i].identifier[1] = (*preview).rectangles[i+k].identifier[1];                                                
        }
    }

    //cur = realloc(cur, sizeof(cur) - sizeof(Rec_t));

    return cur;
}