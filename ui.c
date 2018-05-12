//  Interface com usuario
#include <termios.h>
#define tab "\t\t\t\t\t"
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
    tmpch = getch_(0);
    if (tmpch != '\n') { *string++ = tmpch; printf("%c", tmpch); }
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
// Tabear
void tabbing(){
    printf (tab);
}
// Abre o menu de cli puro 
int abrirMenuCli(int flag, Caca* c, Vector* vec){
    int i, j, k=0;
    char sel, aux[100];
    Vector* flatten = vec;
    Caca* caca = c;
    if ((c != NULL) && (flatten == NULL)) {
        int size[2] = {(*caca).each_size, ((*caca).linhas/(*caca).each_size)};
        char matriz[(*caca).each_size][((*caca).linhas/(*caca).each_size)];
        for (i = 0; i < (*caca).each_size; i++) {
            for (j = 0; j < (*caca).linhas/(*caca).each_size - 1; j++) {
                int index = i*(*caca).linhas/(*caca).each_size + k + j;
                matriz[i][j] = (*caca).caca.vec[index];
            }
            k=0;
        }
        flatten = linearizarMatriz(matriz, size);
        //for (i = 0; i < (*flatten).length; i++)
        //    printf ("%c", (*flatten).vec[i] != separator?(*flatten).vec[i]:'\n');
        //fputs ((*flatten).vec, stdout);

    }
    if (flag == 0) {
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
    } else                                      printf ("+------------------------------------------+                                   \n");
    printT ("|  Selecione a tarefa que deseja executar: | \n");                                                                                                         
    printT ("|      1. Abrir/Vizualizar caca palavras   | \n");                                                                                                         
    printT ("|      2. Gerar caca palavras              | \n");  
    printT ("|      3. Fazer um palpite                 | \n");
    printT ("|      4. Verificar pontuacao              | \n");                                                                                                       
    printT ("|      5. Sair                             | \n");                                                                                                         
    printT ("+------------------------------------------+ \n");
    tabbing();
    sel = getch_(0);
    switch ( sel ) {
        case '1' :
            printf ("+---------------VIZUALIZADOR---------------+\n");
            printT ("|  Selecione a tarefa que deseja executar: |\n");                                                                                                         
            printT ("|      1. Abrir a partir de arquivo        |\n");                                                                                                         
            printT ("|      2. Vizualizar caca palavras         |\n");                                                                                                         
            printT ("|      3. Sair                             |\n");                                                                                                         
            printT ("+------------------------------------------+\n");
            tabbing();
            sel = getch_(0);
            switch ( sel ) {
                case '1' :
                    printf ("+---INSIRA-O-NOME-DO-ARQUIVO-SEM-(.txt)----+\n");
                    printf ("\t\t\t\t\t|      N. ");
                    fgets_(aux, 100);
                    for (i = 0; i < 33-strlen(aux); i++) printf(" ");
                    printf ("|\n");
                    caca = abrirCp(aux);
                    printT ("+------------------------------------------+\n");
                    tabbing();
                    flatten = NULL;
                    abrirMenuCli(1, caca, flatten);
                break;
                case '2' :
                    if (caca == NULL) {
                        printf ("+---NENHUM-CACA-PALAVRAS-INICIALIZADO------+\n");
                        abrirMenuCli(1, caca, flatten);
                    } else {
                        printf ("|                                          |");
                        printf ("\n\t\t\t\t\t|  ");
                        for (i = 0; i < strlen((*caca).caca.vec)+1; i++) {
                            if ((*caca).caca.vec[i] == 'e') { printf ("|\n\t\t\t\t\t|  "); }
                            else {
                                printf ("%c ", (*caca).caca.vec[i]);
                            }
                        }
                        printf ("                                       |\n");
                        tabbing();
                        abrirMenuCli(1, caca, flatten);

                    }
                break;
                case '3' :
                    abrirMenuCli(1, caca, flatten);
                break;
            }
        break;
        case '2' :
            printf ("+------------------GERADOR-----------------+\n");
            printT ("|  Selecione a tarefa que deseja executar: |\n");                                                                                                         
            printT ("|      1. Gerar caca palavras aleatorio    |\n");                                                                                                         
            printT ("|      2. Gerar palavras no ultimo cc      |\n");                                                                                                         
            printT ("|      3. Gerar a partir do teclado        |\n");
            printT ("|      3. Gerar a partir do teclado        |\n");
            printT ("|      4. Sair                             |\n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
            printT ("+------------------------------------------+\n");
            flatten = NULL;            
            tabbing();
            sel = getch_(0);
            switch ( sel ) {
                case '1' :
                break;
                case '2' :

                break;
                case '3' :

                break;
                case '4' :
                    abrirMenuCli(1, caca, flatten);
                break;
            }
        break;
        case '3' :
            printf ("+------------------PALPITE-----------------+\n");
            printT ("|            Insira um palpite:            |\n");                                                                                                         
            printT ("|      P. ");
            fgets_(aux, 100);
            for (i = 0; i < 33-strlen(aux); i++) printf(" ");
            printf ("|\n");
            //fputs((*flatten).vec, stdout);
            if (simpleRegex(aux, (*flatten).vec)) printT ("+------------------ACHOU-------------------+\n");
            else ("+------------------NADA--------------------+\n");

        case '5' :
            printf ("+------------------SAINDO------------------+\n");
            return 0;
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
        if (!strcmp( argv, "cli" )) return abrirMenuCli(0, NULL, NULL);
        else if (!strcmp( argv, "ncurses" )) abrirMenuNcurses();
    }
    else if ( argc == 0 ) {
        printf("Faltam argumentos.\n");
    }
    return 1;

}
// Mostra caca palavras dado a matriz matriz
int mostraCp(char **matriz){}
