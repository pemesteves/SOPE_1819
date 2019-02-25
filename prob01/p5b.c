#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    unsigned i = 0;

    while (envp[i] != NULL)
    {
        if (strncmp("USER=", envp[i], 5) == 0)
            break;

        i++;
    }

    printf("Hello %s!\n", envp[i]+5);

    return 0;
}
