#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[], char* envp[])
{
    unsigned i = 0;
    char* user = "USER";
    char* env_var = (char*) malloc(4*sizeof(char));


    while(envp[i] != NULL){
        strcpy(env_var, envp[i]);

        if(strcmp(user, env_var) == 0)
            break;

        i++;
    }

    printf("Hello %s!\n", env_var);

    free(user);
    free(env_var);

    return 0;
} 
