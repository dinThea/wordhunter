#include "config.c"
#include "datatypes.c"
#include "utils.c"
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "gen.c"
#include "ver.c"
// Macro para apenas tentar carregar o curses se estiver num ambiente linux
#if __linux__
    #include <ncurses.h>
#endif
#include "ui.c"
#define DEFAULT_MENU abrirMenuCli(0)

/*  Objetivo: Isso e o main, ele e primeira funcao que o gcc vai chamar quando o programa foi chamado no bash
    Parametros formais:
    (int argc): numero de parametros de entrada
    (char *argv[]): vetor de string dos parametros de entrada
*/
int main (int argc, char *argv[]) {

    if (argc == 1) DEFAULT_MENU;                         // Caso nao tenha nenhum argumento, ou seja, abre o menu default
    else abrirMenu( strlen(argv[1])+1, argv[1] );        // Caso tenha algum argumento, passa para a funcao generica os argumentos
    
    return 0;
}


