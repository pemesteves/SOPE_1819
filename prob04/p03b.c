// PROGRAMA p03a.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int v = 0;

void sigusr_handler(int signo)
{
    if (signo == SIGUSR1)
        v++;
    else
        v--;
}


int main(void)
{
    struct sigaction action;
    action.sa_handler = sigusr_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    if (sigaction(SIGUSR1, &action, NULL) < 0)
    {
        fprintf(stderr, "Unable to install SIGUSR1 handler\n");
        exit(1);
    }

    if (sigaction(SIGUSR2, &action, NULL) < 0)
    {
        fprintf(stderr, "Unable to install SIGUSR2 handler\n");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }
    else if (pid > 0)
    {
        time_t t;
        srand((unsigned)time(&t));

        for (int i = 0; i < 50; i++)
        {
            if (rand() % 2 == 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);

            sleep(1);
        }
    }
    else
    {
        for (int i = 0; i < 50; i++)
        {
            printf("v: %d\n", v);
            sleep(1);
        }
    }

    return 0;
}