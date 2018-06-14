//  Interface com usuario
#define showSiz 17
#define NUMPAL 99
#define SIZEPA 20

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_BACKCOLOR_BLACK "\x1b[40m"

/*  Objetivo: Calculo do numero de digitos de um numero
    Parametros formais:
    (long int num): inteiro cujo numero de digitos sera calculado
*/
long int calcDig(long int num) {
    
    // Caso o numero seja 0
    if (num == 0) return 0;
    long int dig = 0, cpynum = num;
    // Enquanto o valor for divisivel por 10
    while ((cpynum/10)!=0) {
        dig++;
        cpynum/=10;
    }

    // Retorna o numero de digitos
    return dig+1;
}

/*  Objetivo: Comportamento similar ao fgets so que sem quebra de linha
    Parametros formais:
    (int mode): define se vai ou nao ser impresso em uppercase
    (int echo): define se os caracteres serao impressos ou nao
    (char *string): ponteiro para qual a string linda ira apontar
    (int n): numero maximo de caracteres
*/
char *fgets_(char *string, int n, int mode, int echo) {
    // Char que guarda o caracter atual
    char tmpch;
    int i = n;
    // Precompilacao pra decidir se vai rodar o codigo linux ou windows
    #if __linux__

        char *pont;
        char pnt[10];

        // Guarda o char em maiusculo ou minusculo dependendo do mode
        tmpch = mode == 1? toupper(getch_(0)) : getch_(0) ;
        if (!isspace(tmpch)) {
            // Le o valor do prox chaar 
            *string++ = tmpch; 
            // Printa o valor se echo for igual a 1
            if (echo) printf ("%c", tmpch);
        }
        // Faz a mesma coisa do inicio para o resto dos caracteres
        while ((i-- > 0) && !isspace(tmpch)){
            tmpch = mode == 1?toupper(getch_(0)):getch_(0);
            if (!isspace(tmpch)) {
                *string++ = tmpch;
                if (echo) printf ("%c", tmpch);
            }
        }
        // Fecha a string
        *string++ = '\0';
    #else   
        // Faz a mesma coisa do codigo acima com o acrescimo da biblioteca conio.h
        if (echo) {
            tmpch = mode == 1?toupper(getche()):getche();
            if (!isspace(tmpch)) { *string++ = tmpch; }
            while ((i-- > 0) && !isspace(tmpch)){
                tmpch = mode == 1?toupper(getche()):getche();            
                if (!isspace(tmpch)) {
                    *string++ = tmpch;
                } 
            }
        } else {
            tmpch = mode == 1?toupper(getch()):getch();
            if (!isspace(tmpch)) { *string++ = tmpch; }
            while ((i-- > 0) && !isspace(tmpch)){
                tmpch = mode == 1?toupper(getche()):getch();            
                if (!isspace(tmpch)) {
                    *string++ = tmpch;
                }
            }
        } 
        *string++ = '\0';

    #endif

}

/*  Objetivos: Retorno de inteiro sem pular linhas
*/
int getd(){

    int result = 0;
    char tmpch;
    // Entrada do primeiro char do num
    tmpch = getch_(0);
    // Move o valor para a esquerda e adiciona o digito final
    if (tmpch != '\n') { result = result*10+(tmpch-'0'); printf("%c", tmpch); }
    // Enquanto tmpch for diferente de \n o programa continua
    while (tmpch != '\n'){
        tmpch = getch_(0); 
        if (tmpch != '\n') {
            result = result*10+(tmpch-'0');
            printf("%c",tmpch);
        }
    }
    // Retorna o resultado
    return result;
}

/*  Objetivo: Abre o menu de cli puro
*/
int abrirMenuCli(){
    
    int i, j, k;              // Contadores
    char sel, aux[100], ch, aux2[100];     // Variaveis auxiliares de selecao e entrada
    /* Variaveis estaticas para armazenar os Vectors 
        de palavras e do codice de traducao
    */
    static Codex* flatten = NULL, *palavras = NULL;                                
    /* Armazena estaticamente e dinamicamente o caca
        palavras
    */                                                   
    static Caca* caca = NULL;
    /* Contadores estaticos de pontuacao e de numero
        de palavras e de chamada
    */ 
    static int pontuacao = 0, numpalavras = 0, flag = 0, m, n;
    /* Verifica se caca ja foi preenchido por alguma
        funcao de gerar caca palavras e se existe co-
        dice de traducao, se nao, cria um
    */
    if ((caca != NULL) && (flatten == NULL)) {
        int size[2] = {(*caca).each_size, ((*caca).linhas/(*caca).each_size)};   // Tamanho do caca papavras
        char *matriz[size[0]][size[1]];                                           // Inicializa uma matriz com o tamanho size
        // Varrendo a matriz
        for (i = 0; i < size[0]; i++) {
            for (j = 0; j < (*caca).linhas/size[0] - 1; j++) {
                // Como a matriz esta salva de forma linear em caca, e necessario deslinearizar
                int index = i*(*caca).linhas/size[0] + j;
                // printf ("%c", (*caca).caca.vec[index]);
                matriz[i][j] = &(*caca).caca.vec[index];
            }
        }

        /* Chama a funcao de linearizar a matriz
            de forma a chamar um codice de busca
        */
       printf ("%d %d\n", size[0], size[1]);
        for (i = 0; i < 4; i++){
            for (j = 0; j < 4; j++) printf ("%x ", matriz[i][j]);
            printf ("\n");
        }

        for (i = 0; i < size[0]; i++){
            for (j = 0; j < size[1] - 1; j++) printf ("%c ", *matriz[i][j]);
            printf ("\n");
        }

        size[0] = i;
        size[1] = j;
        flatten = linearizarMatriz(matriz[0][0], size);

    }

    // Testando se e a primeira vez que a funcao e chamada
    if (flag == 0) {
        printf (ANSI_COLOR_BLUE "                                                                               \n" ANSI_COLOR_RESET);                                                                                                                      
        printf (ANSI_BACKCOLOR_BLACK "I8,        8        ,8I  88        88  88        88  888b      88  888888888888\n");
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
    printT ("|      3. Validar caca palavras            | \n"); 
    printT ("|      4. DEBUG                            | \n");                                                                                                           
    printT ("|      5. Sair                             | \n");                                                                                                         
    printT ("+------------------------------------------+ \n");
    tabbing();
    // Lendo a entrada e gerando a arvore de selecao
    sel = getch_(0);
    switch ( sel ) {
        case '1' :
            // Opcoes de visualizacao e abertura de caca palavras
            printf ("+---------------VIZUALIZADOR---------------+\n");
            printT ("|  Selecione a tarefa que deseja executar: |\n");                                                                                                         
            printT ("|      1. Abrir a partir de arquivo        |\n");                                                                                                         
            printT ("|      2. Vizualizar caca palavras         |\n");                                                                                                         
            printT ("|      3. Sair                             |\n");                                                                                                         
            printT ("+------------------------------------------+\n");
            tabbing();
            // Variavel de selecao
            sel = getch_(0);
            switch ( sel ) {
                // Abrindo a partir de arquivo
                case '1' :
                    printf ("+---INSIRA-O-NOME-DO-ARQUIVO-SEM-(.txt)----+\n");
                    printT ("|      N. ");
                    fgets_(aux, 100, 0, 1);
                    // Preence o buffer aux2 de \0
                    memset(aux2, '\0', 99);
                    // Preence o buffer de aux2 de ' '                   
                    memset(aux2, ' ', 33-strlen(aux));
                    // printa aux2
                    printf ("%31s", aux2);
                    printf ("|\n");
                    // Abre o caca palavras
                    free(caca);
                    caca = abrirCp(aux);
                    printT ("+------------------------------------------+\n");
                    tabbing();
                    // puxa o tamanho do caca palavras em x
                    m = (*caca).siz/(*caca).each_size;
                    // puxa o tamanho do caca palavras em y
                    n = (*caca).each_size;
                    // Zera o vetor flatten se existir
                    flatten = NULL;
                    abrirMenuCli();
                break;
                case '2' :
                    if (caca == NULL) {
                        tabbing();
                        printf ("+---NENHUM-CACA-PALAVRAS-INICIALIZADO------+\n");
                        abrirMenuCli();
                    } else {
                        printf ("|                                          |");
                        printf ("\n");
                        printT ("|");

                        for (i = 0; i < showSiz - n/2; i++) printf (" ");
                        
                        for (i = 0; i < m*(n+1)+1; i++) {
                            if (*((*caca).caca.vec[i]) == separator) {
                                if (n/2 <= showSiz)
                                    for (j = 0; j < showSiz - n/2; j++) printf (" "); 
                                else printf (" ");                       
                                printf ("|\n"); 
                                tabbing(); 
                                printf("|");                                 
                                if ((n/2 <= showSiz) && !(i == m*(n+1)))
                                    for (j = 0; j < showSiz - n/2; j++) printf (" ");                        
                            }
                            else {
                                printf ("%c ", *((*caca).caca.vec[i]));
                            }
                        }

                        // for (j = 0; j < 2*showSiz - n + 1; j++) printf (" ");                        

                        printf ("|\n");
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
            printT ("|      2. Gerar palavras                   |\n");
            printT ("|      3. Gerar a partir do teclado        |\n");
            printT ("|      4. Sair                             |\n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
            printT ("+------------------------------------------+\n");
            flatten = NULL;            
            tabbing();
            sel = getch_(0);
            switch ( sel ) {
                case '1' :
                    printf ("+----------GERADOR-DE-PALAVRAS-------------+\n");
                    printT ("|  Entre com a dimensao do caca palavras:  |\n");
                    tabbing();
                    printf ("|  ");
                    fgets_(aux, 100, 0, 1);
                    m = strtol(aux, NULL, 10);
                    printf (" ");
                    fgets_(aux, 100, 0, 1);
                    n = strtol(aux, NULL, 10);
                    memset(aux2, '\0', 99);                    
                    printf ("%s", memset(aux2, ' ', 33-calcDig(n) - calcDig(m) + 6));                    
                    printf ("|\n");
                    tabbing ();
                    char *cp = malloc(m*(n+1)*sizeof(char));
                    for (i = 0; i < m; i++) {
                        printf ("|");
                        for (k = 0; k < 21 - n; k++) printf (" ");                        
                        for (j = 0; j < n; j++) {
                            ch = getRandChar();
                            cp[i*(n+1)+j] = ch;
                            printf ("%c ", ch);
                        }
                        cp[i*(n+1)+j] = '\n';
                        for (k = 0; k < 21 - n; k++) printf (" ");
                        printf ("|\n");
                        tabbing ();
                    }
                    caca = NULL;
                    caca = create_caca(cp, (n+1)*m, n);
                    flatten = NULL;
                    abrirMenuCli();

                break;
                case '2' :

                    printf ("+----------GERADOR-DE-PALAVRAS-------------+\n");
                    printT ("|  Entre com o numero de palavras:         |\n");
                    tabbing();
                    printf ("|     ");
                    fgets_(aux, 100, 0, 1);
                    int numpalavras = strtol(aux, NULL, 10);
                    memset(aux2, '\0', 99);                    
                    printf ("%s", memset(aux2, ' ', 33-calcDig(n) - calcDig(m) + 5));                                        
                    printf ("\n");
                    tabbing();
                    k = 0;
                    i = 0;
                    printf ("| ");                                            
                    while (k < numpalavras) {
                        printf ("%c", (*caca).caca.vec[i]);
                        if ((*caca).caca.vec[i] == '\n') {
                            tabbing();
                            if (k < numpalavras-1)
                                printf ("| ");                        
                            k++;
                        }
                        i++;
                    }

                break;
                case '3' :
                
                    printf ("+----------GERADOR-DE-PALAVRAS-------------+\n");
                    printT ("|  Entre com a dimensao do caca palavras:  |\n");
                    tabbing();
                    printf ("|  ");
                    fgets_(aux, 100, 0, 1);
                    m = strtol(aux, NULL, 10);
                    printf (" ");
                    fgets_(aux, 100, 0, 1);
                    n = strtol(aux, NULL, 10);
                    memset(aux2, '\0', 99);                    
                    printf ("%s", memset(aux2, ' ', 33-calcDig(n) - calcDig(m) + 6));                                        
                    printf ("|\n");
                    tabbing ();
                    char *cacapalavras = malloc(m*(n+1)*sizeof(char));
                    for (i = 0; i < m; i++) {
                        printf ("|");
                        for (k = 0; k < 21 - n; k++) printf (" ");                        
                        for (j = 0; j < n; j++) {
                            ch = toupper(getch_(0));
                            cacapalavras[i*(n+1)+j] = ch;
                            printf ("%c ", ch);
                        }
                        cacapalavras[i*(n+1)+j] = '\n';
                        for (k = 0; k < 21 - n; k++) printf (" ");
                        printf ("|\n");
                        tabbing ();
                    }
                    caca = NULL;
                    caca = create_caca(cacapalavras, (n+1)*m, n);
                    flatten = NULL;
                    abrirMenuCli();


                break;
                case '4' :
                    abrirMenuCli();
                break;
            }
        break;
        case '0' :
            printf ("+------------------PALPITE-----------------+\n");
            printT ("|            Insira um palpite:            |\n");                                                                                                         
            printT ("|      P. ");
            fgets_(aux, 100, 1, 1);
            memset(aux2, '\0', 99);            
            printf ("%s", memset(aux2, ' ', 33-strlen(aux)));                                                    
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
        case '9' :
            printf ("+-------------SUA-PONTUACAO-E--------------+\n");
            printT ("|      P. ");
            printf ("%d", pontuacao);
            for (i = 0; i < 32-calcDig(pontuacao); i++) printf (" ");
            printf ("|\n");
            printT ("+------------------------------------------+\n");
            tabbing();
            abrirMenuCli();            
        break;
        case '4' :
            printf ("+------------------DEBUG-------------------+\n");
            printT ("|      1. Mostrar codice de regex          |\n");            
            printT ("|      2. Sair                             |\n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
            printT ("+------------------------------------------+\n");
            tabbing();
            sel = getch_(0);
            switch ( sel ) {
                case '1' :
                    printf ("| ");
                    //printf ("%c", *(flatten->vec[0]));
                    //fputc ('a', stdout);
                    for (i = 0; i < 100; i++) {

                        if (*((*flatten).vec[i]) != separator) printf ("%c",*(flatten->vec[i]));
                        else { printf ("\n"); printT ("| "); }
                        
                    }
                    *((*flatten).vec[3]) = '3';
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
        case '3' :

            printf ("+----------------VERIFICADOR---------------+\n");
            printT ("|      1. Verificar a partir de arquivo    |\n");
            printT ("|      2. Inserir conjunto de palavras     |\n");                                    
            printT ("|      3. Sair                             |\n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
            printT ("+------------------------------------------+\n");
            tabbing();
            sel = getch_(0);
            switch (sel) {
                case '1' :
                    printf ("+---INSIRA-O-NOME-DO-ARQUIVO-SEM-(.txt)----+\n");
                    printT ("|      N. ");
                    // Caso o sistema seja linux, abre a funcao integrada com a biblioteca terminus
                    #if __linux__
                    fgets_(aux, 100, 0, 1);
                    // Caso o sistema seja windows, abre a funcao integrada com a biblioteca conio
                    #else                    
                    fgets_(aux,100,0,1);
                    #endif
                    /* As funcoes padroes do stdio nao foram usadas por darem echo automaticamente
                        na entrada do teclado
                    */
                    memset(aux2, '\0', 99);
                    printf ("%s", memset(aux2, ' ', 33-strlen(aux)));                    
                    printf ("|\n");
                    tabbing();
                    if (verArquivo((*flatten).vec, aux, strlen(aux)+1)) {
                        printf("|           TUDO CORRETO%-19c|\n", ' ');                     
                        printT ("+------------------------------------------+\n");
                    } else {
                        printf ("+------------------------------------------+\n");                        
                    }
                    tabbing();
                    abrirMenuCli();

                break;
                case '2' :

                    printf ("+--------INSIRA-O-NUMERO-DE-PALAVRAS-------+\n");
                    printT ("|      N. ");
                    int num;
                    num = getd();
                    memset(aux2, '\0', 99);
                    memset(aux2, ' ', 33 - calcDig(num));
                    fputs(aux2, stdout);
                    printf ("|\n");
                    char palavras[num][caca->each_size+1];
                    for (i = 0; i < num; i++) {
                        tabbing ();
                        printf ("|      PALAVRA %d : ", i+1);
                        fgets_(palavras[i], caca->each_size, 1, 1);
                        memset(aux2, '\0', 99);
                        memset(aux2, ' ', 23 - strlen(palavras[i]));
                        printf (" %s|\n", aux2);
                    }
                    printT ("+----------------DIFERENCAS----------------+\n");                    
                    for (i = 0; i < num; i++) {
                        if (strstr((*flatten).vec, palavras[i]) == NULL) {
                            tabbing();
                            memset(aux2, '\0', 99);
                            memset(aux2, ' ', 33 - strlen(palavras[i]));
                            printf ("|      * %s%s |\n", palavras, aux2);
                        }
                    }
                    printT ("+------------------------------------------+\n");
                    tabbing();
                    abrirMenuCli();
                break;
            }
            return 0;
        break;
        case '5' :
            printf ("+------------------SAINDO------------------+\n");
            exit(0);
        break;
    }

    abrirMenuCli();
                                                                                                             
}
/*  Objetivos: Abre o menu de ncurses
*/
int abrirMenuNcurses(){

    #if __linux__
        
    #else
        printf ("\nO ncurses nao esta disponivel para esse sistema operacional");
    #endif
}
/*  Objetivos: Abre o primeiro menu, passando os argumentos de linha
    Parametros formais:
    (int argc): numero de parametros de entrada
    (char *argv[]): vetor de string dos parametros de entrada
*/ 

int abrirMenu(int argc, char argv[argc]){

    if (!strcmp( argv, "cli" )) return abrirMenuCli();              // Caso o argumento seja cli, abre o menu de cli
    else if (!strcmp( argv, "ncurses" )) abrirMenuNcurses();        // Caso o argumento seja curses, abre o menu de curses
    
    return 1;

}
