//  Interface com usuario
#include <termios.h>

static struct termios old, new;

// Inicializa as novas definicoes de io do terminal
void initTermios(int echo) {
    tcgetattr(0, &old); // Pega as velhas configuracoes do terminal
    new = old; // Cria novas configucaoes
    new.c_lflag &= ~ICANON; // Desabilita o buffer de io
    if (echo) {
        new.c_lflag |= ECHO; 
    } else {
        new.c_lflag &= ~ECHO;
    }
    tcsetattr(0, TCSANOW, &new);
}

void resetTermios(void) {
    tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) {
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

// Comportamento similar ao fgets, porem sem quebra de linha
char *fgets_(char *string, int n) {
	char* result;
    char tmpch;
    int i = n;
    result = string;
    tmpch = getch_(1);
    while ((i-- > 0) && tmpch != '\n'){
        result[i] = tmpch;
        tmpch = getch_(0); 
        if (tmpch != '\n') {
            *string++ = tmpch;
            printf("%c",tmpch);
        }
    }
    *string++ = '\0';

}

// Seta pra frente
void printT(char text[]){
    printf ("\t\t\t\t\t%s", text);    
}
// Abre o menu de cli puro 
int abrirMenuCli(){
    
    int i;
    char sel, aux[100];
    printf ("                                                                                                                      \n");                                                                                                                      
    printf ("                                                   88 88        88                                                    \n");
    printf ("                                                   88 88        88                          ,d                        \n");
    printf ("                                                   88 88        88                          88                        \n");
    printf ("8b      db      d8  ,adPPYba,  8b,dPPYba,  ,adPPYb,88 88aaaaaaaa88 88       88 8b,dPPYba, MM88MMM ,adPPYba, 8b,dPPYba,\n");
    printf ("`8b    d88b    d8' a8'     '8a 88P'   'Y8 a8'    `Y88 88''''''''88 88       88 88P'   `'8a  88   a8P_____88 88P'   'Y8\n");
    printf (" `8b  d8'`8b  d8'  8b       d8 88         8b       88 88        88 88       88 88       88  88   8PP''''''' 88        \n");
    printf ("  `8bd8'  `8bd8'   '8a,   ,a8' 88         '8a,   ,d88 88        88 '8a,   ,a88 88       88  88,  '8b,   ,aa 88        \n");
    printf ("    YP      YP      `'YbbdP''  88          `'8bbdP'Y8 88        88  `'YbbdP'Y8 88       88  'Y888 `'Ybbd8'' 88        \n");
    printf ("                                                                                                                      \n");
    printf ("                                        +------------------------------------------+                                   \n");
    printf ("                                        |  Selecione a tarefa que deseja executar: |                                   \n");                                                                                                         
    printf ("                                        |      1. Abrir/Vizualizar caca palavras   |                                   \n");                                                                                                         
    printf ("                                        |      2. Gerar caca palavras              |                                   \n");                                                                                                         
    printf ("                                        |      3. Sair                             |                                   \n");                                                                                                         
    printf ("                                        +------------------------------------------+                                   \n");
    printf ("\t\t\t\t\t");
    sel = getch_(0);
    switch ( sel ) {
        case '1' :
            printf ("+---------------VIZUALIZADOR---------------+\n");
            printT ("|  Selecione a tarefa que deseja executar: |\n");                                                                                                         
            printT ("|      1. Abrir a partir de arquivo        |\n");                                                                                                         
            printT ("|      2. Vizualizar caca palavras         |\n");                                                                                                         
            printT ("|      3. Sair                             |\n");                                                                                                         
            printT ("+------------------------------------------+\n");
            printf ("\t\t\t\t\t");
            sel = getch_(0);
            switch ( sel ) {
                case '1' :
                    printf ("+---INSIRA-O-NOME-DO-ARQUIVO-SEM-(.txt)----+\n");
                    printf ("\t\t\t\t\t|      N. ");
                    fgets_(aux, 100);
                    for (i = 0; i < 32-strlen(aux); i++) printf(" ");
                    printf ("|\n\t\t\t\t\t");
                break;
                case '2' :

                break;
                case '3' :

                break;
            }
        break;
        case '2' :
            printf("+------------------GERADOR-----------------+\n");
        break;
        case '3' :
            printf("+------------------SAINDO------------------+\n");
        break;
    }
    //printf ("------------------------------------------+\n");
                                                                                                             
}
// Abr\n");e o menu de ncurses
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
    return 1;

}
// Mostra caca palavras dado a matriz matriz
int mostraCp(char **matriz){}
