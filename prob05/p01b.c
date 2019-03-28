#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

#define READ 0
#define WRITE 1

typedef struct{
    int i1;
    int i2;
} numbers;

int main()
{
    int fd[2]; //Pipe files
    pipe(fd);

    if (fork())//Pai
    { 
        close(fd[READ]);
        numbers read_num;

        scanf("%d %d", &read_num.i1, &read_num.i2);
        
        write(fd[WRITE], &read_num, sizeof(numbers));
        
        close(fd[WRITE]);
    }
    else //Filho
    { 
        numbers write_num;

        close(fd[WRITE]);
        
        while(read(fd[READ], &write_num, sizeof(write_num)) == 0);

        int sum = write_num.i1 + write_num.i2;
        int difference = write_num.i1 - write_num.i2;
        int product = write_num.i1 * write_num.i2;
        int quotient = write_num.i1 / write_num.i2;

        printf("Sum: %d\nDifference: %d\nProduct: %d\nQuotient: %d\n", sum, difference, product, quotient);

        close(fd[READ]);
    }

    return 0;
}