#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int status;
    pid_t pid;
    pid = fork();
    
    if(pid == -1){
        perror("Fork");
    }
    else if(pid == 0){
        wait(&status);
        write(STDOUT_FILENO, "world!\n", 7);
    }
    else {
        write(STDOUT_FILENO, "Hello ", 6);
    }

    return 0;
}