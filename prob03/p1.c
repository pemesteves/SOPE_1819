// PROGRAMA p1.c
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int global = 1;
int main(void)
{
    int local = 2;
    if (fork() > 0) //Processo-filho
    {
        printf("PID = %d; PPID = %d\n", getpid(), getppid());
        global++;
        local--;
    }
    else //Processo-pai
    {
        printf("PID = %d; PPID = %d\n", getpid(), getppid());
        global--;
        local++;
    }
    printf("PID = %d - global = %d ; local = %d\n", getpid(), global, local);
    return 0;
}