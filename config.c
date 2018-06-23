// Arquivo para definir as diretivas de uso dependendo do OS

char separator = '\n';

#if __linux__
    #include <termios.h>
    enum winsizes { ncols = 10, nlines = 10, xs = 10, ys = 10 };
    static struct termios old, new;

    /*  Objetivo: Inicializa as novas definicoes de io do terminal
        Parametros formais:
        (int echo): decide se vai ou nao mostrar o char
    */
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
#else
    #include <conio.h>

    char getch_(int echo) {
        char ch;
        if (echo)   ch = getche();
        else        ch = getch();
        return ch;
    }
#endif 
