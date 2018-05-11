#include "datatypes.c"
#include "utils.c"
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "gen.c"
#include "ver.c"
#include "ui.c"

int main (int argc, char *argv[]) {

    abrirMenu( strlen(argv[1])+1, argv[1] );
    /*char matrizTeste[][2] = {{'a','b'}, {'d','e'}, {'g','h'}};
    int size[2] = {3, 2};
    Vector* flatten = linearizarMatriz(matrizTeste, size, 1000);
    char ch[10];
    while (strcmp(ch,"0\n")) {
        fgets(ch, 10, stdin);
        printf ("\n%d\n", verPalavras(ch, flatten->vec, 10, 1));
    }*/
    return 0;
}
