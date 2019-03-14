// PROGRAMA p8.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char *argv[], char *envp[])
{
    pid_t pid;
    if (argc != 2)
    {
        printf("usage: %s dirname\n", argv[0]);
        exit(1);
    }
    pid = fork();
    if (pid > 0){
        printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]);
        int status;
        wait(&status);
    }
    else if (pid == 0)
    {
        //execlp("ls", "ls", "-laR", argv[1], NULL);
        //execl("/bin/ls", "ls", "-laR", argv[1], NULL);
        char *args[4] = {"ls", "-laR", argv[1], NULL};
        //execvp("ls", args);
        //execv("/bin/ls", args);
        execve("/bin/ls", args, envp);
        printf("Command not executed !\n");
        exit(1);
    }
    exit(0);
}