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

    if (fork())//Pai
    { 
        close(fd[READ]);
        int read_numbers[2];

        scanf("%d %d", &read_numbers[0], &read_numbers[1]);
        
        write(fd[WRITE], read_numbers, 2*sizeof(int));
        
        close(fd[WRITE]);
    }
    else //Filho
    { 
        int write_numbers[2];

        close(fd[WRITE]);
        
        while(read(fd[READ], write_numbers, 2*sizeof(int)) == 0);

        int sum = write_numbers[0]+write_numbers[1];
        int difference = write_numbers[0]-write_numbers[1];
        int product = write_numbers[0]*write_numbers[1];
        int quotient = write_numbers[0]/write_numbers[1];;

        printf("Sum: %d\nDifference: %d\nProduct: %d\nQuotient: %d\n", sum, difference, product, quotient);

        close(fd[READ]);
    }

    return 0;
}