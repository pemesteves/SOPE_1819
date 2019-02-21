#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    for(int i = 0; i < atoi(argv[2]); i++){
        printf("Hello %s!\n", (char*) argv[1]);
    }

    return 0;
} 
