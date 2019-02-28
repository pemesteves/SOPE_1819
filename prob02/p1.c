#include <unistd.h>
#include <termios.h>
#include <stdio.h>

int main()
{
    write(STDOUT_FILENO, "Password: ", 10);

    struct termios term;

    while (tcgetattr(STDOUT_FILENO, &term) == -1);

    tcflag_t t = term.c_lflag;

    term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);

    while (tcsetattr(STDOUT_FILENO, TCSANOW, &term) == -1);

    const int max_length = 20;

    char string[max_length];

    int i = 0;
    char c;
    while (i < max_length && read(STDIN_FILENO, &c, 1) && c != '\n')
    {
        string[i] = c;
        c = '*';
        i++;
        write(STDOUT_FILENO, &c, 1);
    }
    term.c_lflag = t;
    while (tcsetattr(STDOUT_FILENO, TCSANOW, &term) == -1);


    write(STDOUT_FILENO, "\nPassword: ", 11);
    for(i = 0; i < max_length; i++){
        if (string[i] == '\0')
            break;
        write(STDOUT_FILENO, &string[i], 1);
    }
    write(STDOUT_FILENO, "\n", 1);
    return 0;
}