// PROGRAMA p7.c
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char prog[20];
    sprintf(prog, "%s.c", argv[1]);
    execlp("gcc", "gcc", prog, "-Wall", "-o", argv[1], NULL);
    printf("Compiling program...");
    exit(0);
}