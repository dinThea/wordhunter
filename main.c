#include "datatypes.c"
#include "utils.c"
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "gen.c"
#include "ver.c"
#include <curses.h>
#include "ui.c"

// Isso e o main, ele e primeira funcao que o gcc vai chamar quando o programa foi chamado no bash
int main (int argc, char *argv[]) {

    abrirMenu( strlen(argv[1])+1, argv[1] );

    return 0;
}

