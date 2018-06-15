#include <stdlib.h>

// Wrap para retornar um vetor numa funcao
typedef struct Vector_t {
    int length; 
    char vec[];
} Vector;

// Wrap para salvar o codice
typedef struct Vector_codex {
    int length;
    char *vec[];
} Codex;

/*  Objetivos: Cria e retorna um vec de tamanho length
    Parametros formais:
    (int length): define o tamanho do vec para alocar
*/
Codex* create_codex(int length) {

    // Aloca o espaco para guardar o codice
    Codex* cod = malloc(sizeof(Codex) + length*sizeof(char*));
    // Caso nao tenha alocado
    if (cod != NULL) { 
        cod -> length = length;
    }

    return cod;
}

/*  Objetivos: Cria e retorna um vec de tamanho length
    Parametros formais: 
    (int length): define o tamanho do vec para alocar
*/
Vector* create_vec(int length) {

    // Aloca o espaco necessario para guardar o vec
    Vector* vec = malloc(sizeof(Vector) + length*sizeof(char));
    // Se nao tiver dado nada errado
    if (vec != NULL) {
        // atribui o valor para length
        vec->length = length;
    }
    
    // Retorna o vetor alocado
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
    Codex caca;
} Caca;
 

/*  Objetivo: Inicializa e retorna o struct caca
    Parametros formais:
    (char* _vetor): entrada do vetor a ser colocado no struct
    (int size): tamanho do vetor
    (int each_line): tamanho de cada linha do vetor
*/
Caca* create_caca(char* _vetor, int size, int each_size){
    
    int i;
    // Cria o vetor
    Vector* vec = create_vec(size); 
    // Cria o caca
    Caca* caca = malloc(sizeof(Caca) + sizeof(vec)*size);
    // Atribui o valor para siz
    caca->siz = size;
    // Se a atribuicao tiver dado certo, ou seja, se o ponteiro nao for nulo
    if (caca != NULL) {
        // Salva o numero de linhas
        caca->linhas = size;
        // Coloca o conteudo de _vetor para vec->vec
        for (i = 0; i < size; i++){
            (*vec).vec[i] = _vetor[i];
        }
        // Coloca o conteudo de vec->vec para a estrutura de caca palavras
        for (i = 0; i < size; i++){
            (*caca).caca.vec[i] = (*vec).vec[i];
        }
    }

    // Atribui o valor de each_size 
    (*caca).each_size = each_size;
    
    // Retorna o caca palavras criado
    return caca;
}

typedef union String_set {

    char identifier[2];
    char ch;
    int pos[2];
    int color[2];

} Nstring;
