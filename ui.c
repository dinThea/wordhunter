//  Interface com usuario

// Abre o menu de cli puro 
int abrirMenuCli(){
    
}
// Abre o menu de ncurses
int abrirMenuNcurses(){
    printf ("\nNCURSES DOES NOT EXIST\n");
}
// Abre o primeiro menu
int abrirMenu(int argc, char argv[argc]){
    
    if ( argc > 0 ) {
        if (!strcmp( argv, "cli" )) abrirMenuCli();
        else if (!strcmp( argv, "ncurses" )) abrirMenuNcurses();
    }
    else if ( argc == 0 ) {
        printf("Faltam argumentos.\n");
    }

}
// Mostra caca palavras dado a matriz matriz
int mostraCp(char **matriz){}
