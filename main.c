#include "utils.c"
#include <stdio.h>
#include <math.h>
#include "gen.c"
#include "ui.c"

int main () {

    char matrizTeste[][2] = {{'a','b'}, {'d','e'}, {'g','h'}};
    int size[2] = {3, 2};
    char testeFlatten[100];
    linearizarMatriz(matrizTeste, size, testeFlatten);

    return 0;
}
