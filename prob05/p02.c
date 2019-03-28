#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <string.h>

#define READ 0
#define WRITE 1

int main()
{
    
    int fd[2]; //Pipe files
    pipe(fd);

    int fd1[2];
    pipe(fd1);

    if (fork()) //Pai
    {
        close(fd[READ]);

        int num1, num2;

        scanf("%d %d", &num1, &num2);

        char *string = malloc(20 * sizeof(char));

        sprintf(string, "%d %d", num1, num2);
        
        write(fd[WRITE], string, sizeof(string));

        memset(string, '\0', sizeof(string));
        close(fd[WRITE]);

        close(fd1[WRITE]);
    
        while(read(fd1[READ], string, sizeof(string)) == 0);

        int sum, difference, product, quotient;

        sscanf(string, "%d %d %d %d", &sum, &difference, &product, &quotient);

        printf("Father:\n");
        printf("Sum: %d\nDifference: %d\nProduct: %d\nQuotient: %d\n", sum, difference, product, quotient);

        free(string);
    }
    else //Filho
    {
        char *string = malloc(20 * sizeof(char));

        close(fd[WRITE]);

        while (read(fd[READ], string, sizeof(string)) == 0)
            ;

        int num1, num2;
        sscanf(string, "%d %d", &num1, &num2);

        int sum = num1 + num2;
        int difference = num1 - num2;
        int product = num1 * num2;
        int quotient = num1 / num2;
        
        close(fd[READ]);
        
        memset(string, '\0', sizeof(string));

        close(fd1[READ]);

        sprintf(string, "%d %d %d %d", sum, difference, product, quotient);

        write(fd1[WRITE], string, sizeof(string));
        
        close(fd1[WRITE]);

        free(string);
    }

    return 0;
}