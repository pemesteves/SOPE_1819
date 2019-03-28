#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

#define READ 0
#define WRITE 1

int main()
{
    
    int fd[2]; //Pipe files
    pipe(fd);

    if (fork()) //Pai
    {
        close(fd[READ]);

        int num1, num2;

        scanf("%d %d", &num1, &num2);

        char *string = malloc(20 * sizeof(char));

        sprintf(string, "%d %d", num1, num2);
        
        write(fd[WRITE], string, sizeof(string));

        free(string);
        close(fd[WRITE]);
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

        printf("Sum: %d\nDifference: %d\nProduct: %d\nQuotient: %d\n", sum, difference, product, quotient);

        free(string);
        close(fd[READ]);
    }

    return 0;
}