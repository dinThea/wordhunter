//  Interface com usuario

long int calcDig(long int num) {
    
    if (num == 0) return 0;
    long int dig = 0, cpynum = num;
    while (cpynum%10==0) {
        dig++;
        cpynum/=10;
    }

    return dig;
}

/* Comportamento similar ao fgets so que sem quebra de linha
    os parametros sao:
        - mode: define se vai ou nao ser impresso em uppercase
        - echo: define se os caracteres serao impressos ou nao
*/
char *fgets_(char *string, int n, int mode, int echo) {
	char* result;
    char tmpch;
    int i = n;
    result = string;
    #if __linux__
        tmpch = mode == 1?toupper(getch_(echo)):getch_(echo);
        if (!isspace(tmpch)) { *string++ = tmpch; }
        while ((i-- > 0) && !isspace(tmpch)){
            result[i] = tmpch;
            tmpch = mode == 1?toupper(getch_(echo)):getch_(echo);
            if (!isspace(tmpch)) {
                *string++ = tmpch;
            }
        }
        *string++ = '\0';
    #else   

        if (echo) {
            tmpch = mode == 1?toupper(getche()):getche();
            if (!isspace(tmpch)) { *string++ = tmpch; }
            while ((i-- > 0) && !isspace(tmpch)){
                result[i] = tmpch;
                tmpch = mode == 1?toupper(getche()):getche();            
                if (!isspace(tmpch)) {
                    *string++ = tmpch;
                }
            }
        } else {
            tmpch = mode == 1?toupper(getch()):getch();
            if (!isspace(tmpch)) { *string++ = tmpch; }
            while ((i-- > 0) && !isspace(tmpch)){
                result[i] = tmpch;
                tmpch = mode == 1?toupper(getche()):getch();            
                if (!isspace(tmpch)) {
                    *string++ = tmpch;
                }
            }
        } 
        *string++ = '\0';

    #endif

}

// Entrada de inteiros sem pular linhas
int getd(){

    int result = 0;
    char tmpch;
    tmpch = getch_(0);
    if (tmpch != '\n') { result = result*10+(tmpch-'0'); printf("%c", tmpch); }
    while (tmpch != '\n'){
        tmpch = getch_(0); 
        if (tmpch != '\n') {
            result = result*10+(tmpch-'0');
            printf("%c",tmpch);
        }
    }
    return result;
}

// Abre o menu de cli puro
int abrirMenuCli(){
    
    int i, j;               // Contadores
    char sel, aux[100];     // Variaveis auxiliares de selecao e entrada
    /* Variaveis estaticas para armazenar os Vectors 
        de palavras e do codice de traducao
    */
    static Vector* flatten = NULL, *palavras = NULL;                                
    /* Armazena estaticamente e dinamicamente o caca
        palavras
    */                                                   
    static Caca* caca = NULL;
    /* Contadores estaticos de pontuacao e de numero
        de palavras e de chamada
    */ 
    static int pontuacao = 0, numpalavras = 0, flag = 0;
    /* Verifica se caca ja foi preenchido por alguma
        funcao de gerar caca palavras e se existe co-
        dice de traducao, se nao, cria um
    */
    if ((caca != NULL) && (flatten == NULL)) {
        int size[2] = {(*caca).each_size, ((*caca).linhas/(*caca).each_size)};   // Tamanho do caca papavras
        char matriz[size[0]][size[1]];                                           // Inicializa uma matriz com o tamanho size
        // Varrendo a matriz
        for (i = 0; i < size[0]; i++) {
            for (j = 0; j < (*caca).linhas/size[0] - 1; j++) {
                // Como a matriz esta salva de forma linear em caca, e necessario deslinearizar
                int index = i*(*caca).linhas/size[0] + j;
                matriz[i][j] = (*caca).caca.vec[index];
            }
        }

        /* Chama a funcao de linearizar a matriz
            de forma a chamar um codice de busca
        */ 
        flatten = linearizarMatriz(matriz, size);

    }

    // Testando se e a primeira vez que a funcao e chamada
    if (flag == 0) {
        printf ("                                                                               \n");                                                                                                                      
        printf ("I8,        8        ,8I  88        88  88        88  888b      88  888888888888\n");
        printf ("`8b       d8b       d8'  88        88  88        88  8888b     88       88     \n");
        printf ("  8,     ,8'8,     ,8'   88        88  88        88  88 `8b    88       88     \n");
        printf ("  Y8     8P Y8     8P    88aaaaaaaa88  88        88  88  `8b   88       88     \n");
        printf ("  `8b   d8' `8b   d8'    88''''''''88  88        88  88   `8b  88       88     \n");
        printf ("   `8a a8'   `8a a8'     88        88  88        88  88    `8b 88       88     \n");
        printf ("    `8a8'     `8a8'      88        88  Y8a.    .a8P  88     `8888       88     \n");
        printf ("     `8'       `8'       88        88   `'Y8888Y''   88      `888       88     \n");
        printT ("+------------------------------------------+\n");
        flag++;    
    } else                                      printf ("+------------------------------------------+\n");
    printT ("|  Selecione a tarefa que deseja executar: | \n");                                                                                                         
    printT ("|      1. Abrir/Vizualizar caca palavras   | \n");                                                                                                         
    printT ("|      2. Gerar caca palavras              | \n");  
    printT ("|      3. Fazer um palpite                 | \n");
    printT ("|      4. Verificar pontuacao              | \n"); 
    printT ("|      5. DEBUG                            | \n");                                                                                                           
    printT ("|      7. Sair                             | \n");                                                                                                         
    printT ("+------------------------------------------+ \n");
    tabbing();
    // Lendo a entrada e gerando a arvore de selecao
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
                    printT ("|      N. ");
                    // Caso o sistema seja linux, abre a funcao integrada com a biblioteca terminus
                    #if __linux__
                    fgets_(aux, 100, 0, 0);
                    // Caso o sistema seja windows, abre a funcao integrada com a biblioteca conio
                    #else                    
                    aux = cgets(aux);
                    #endif
                    /* As funcoes padroes do stdio nao foram usadas por darem echo automaticamente
                        na entrada do teclado
                    */
                    printf ("%-33s", aux);
                    printf ("|\n");
                    caca = abrirCp(aux);
                    printT ("+------------------------------------------+\n");
                    tabbing();
                    flatten = NULL;
                    abrirMenuCli();
                break;
                case '2' :
                    if (caca == NULL) {
                        printf ("+---NENHUM-CACA-PALAVRAS-INICIALIZADO------+\n");
                        abrirMenuCli();
                    } else {
                        printf ("|                                          |");
                        printf ("\n");
                        printT ("|  ");
                        for (i = 0; i < strlen((*caca).caca.vec)+1; i++) {
                            if ((*caca).caca.vec[i] == separator) { printf ("|\n"); tabbing(); printf("|  "); }
                            else {
                                printf ("%c ", (*caca).caca.vec[i]);
                            }
                        }
                        printf ("                                       |\n");
                        tabbing();
                        abrirMenuCli();

                    }
                break;
                case '3' :
                    abrirMenuCli();
                break;
                default :
                    abrirMenuCli();
                break;
            }
        break;
        case '2' :
            printf ("+------------------GERADOR-----------------+\n");
            printT ("|  Selecione a tarefa que deseja executar: |\n");                                                                                                         
            printT ("|      1. Gerar caca palavras aleatorio    |\n");                                                                                                         
            printT ("|      2. Gerar palavras no ultimo cc      |\n");                                                                                                         
            printT ("|      3. Gerar a partir do teclado        |\n");
            printT ("|      4. Gerar a partir do teclado        |\n");
            printT ("|      5. Sair                             |\n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
            printT ("+------------------------------------------+\n");
            flatten = NULL;            
            tabbing();
            sel = getch_(0);
            switch ( sel ) {
                case '1' :
                break;
                case '2' :
                    printf ("+----------GERADOR-DE-PALAVRAS-------------+\n");
                    printT ("|  Entre com o numero de palavras: ");
                    numpalavras = getd();
                    for (i = 0; i < 5-calcDig(numpalavras); i++) printf(" ");
                    printf (" |\n");
                    for (i = 0; i < numpalavras; i++) {
                        tabbing ();
                        printf ("|       Insira a %d palavra: ", i);
                        for (j = 0; j < 14-calcDig(j); j++) printf(" ");
                        printf ("|\n");
                                                
                    }

                break;
                case '3' :

                break;
                case '5' :
                    abrirMenuCli();
                break;
            }
        break;
        case '3' :
            printf ("+------------------PALPITE-----------------+\n");
            printT ("|            Insira um palpite:            |\n");                                                                                                         
            printT ("|      P. ");
            fgets_(aux, 100, 1, 0);
            printf ("%-33s", aux);
            printf ("|\n");
            //fputs((*flatten).vec, stdout);
            if (strstr((*flatten).vec, aux) != NULL) {
                printT ("+------------------ACHOU-------------------+\n");
                pontuacao++;
            }
            else printT ("+------------------NADA--------------------+\n");
            tabbing();
            abrirMenuCli();
            
        break;
        case '4' :
            printf ("+-------------SUA-PONTUACAO-E--------------+\n");
            printT ("|      P. ");
            printf ("%d", pontuacao);
            for (i = 0; i < 32-calcDig(pontuacao); i++) printf (" ");
            printf ("|\n");
            printT ("+------------------------------------------+\n");
            tabbing();
            abrirMenuCli();            
        break;
        case '5' :
            printf ("+------------------DEBUG-------------------+\n");
            printT ("|      1. Mostrar codice de regex          |\n");            
            printT ("|      2. Sair                             |\n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
            printT ("+------------------------------------------+\n");
            tabbing();
            sel = getch_(0);
            switch ( sel ) {
                case '1' :
                    printf ("| ");
                    for (i = 0; i < (*flatten).length; i++) {

                        if ((*flatten).vec[i] != separator) printf ("%c",(*flatten).vec[i]);
                        else { printf ("\n"); printT ("| "); }
                        
                    }
                    printf ("\n");
                    tabbing();
                    abrirMenuCli();
                break;
                case '2' :
                    abrirMenuCli();
                break;
                default :
                    abrirMenuCli();
                break;
            }
                                                                             
        break;             
        case '6' :
            printf ("+------------------SAINDO------------------+\n");
            return 0;
        break;
    }
                                                                                                             
}
// Abr\n");e o menu de ncurses
int abrirMenuNcurses(){

    #if __linux__
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax); // Pegando os valores maximo do terminal

        // Inicializando o Ncurses
        WINDOW *win = newwin(6, yMax, xMax, 5);
        initscr();
        cbreak();
        noecho();
        wrefresh(win);

        keypad(stdscr, TRUE); // Para poder usar o teclado

        while (1) {
            attron(A_STANDOUT | A_UNDERLINE);
            printw("hello world");
            attron(A_STANDOUT | A_UNDERLINE);    
            refresh();
            addstr("I am highlighted!\n");
            start_color();
            wrefresh(win); 
        }   
        endwin();
    #else
        printf ("\nO ncurses nao esta disponivel para esse sistema operacional");
    #endif
}
// Abre o primeiro menu, passando os argumentos de linha
int abrirMenu(int argc, char argv[argc]){
    

    if (!strcmp( argv, "cli" )) return abrirMenuCli();              // Caso o argumento seja cli, abre o menu de cli
    else if (!strcmp( argv, "ncurses" )) abrirMenuNcurses();        // Caso o argumento seja curses, abre o menu de curses
    
    return 1;

}
