#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

int main(){
	int num_students = 0;
	if(write(STDOUT_FILENO, "Number of Students: ", 21) < 0){
		perror("write");
		exit(1);
	}

	if(read(STDIN_FILENO, &num_students, 3) < 0){
		perror("read");
		exit(1);
	}

	char* line = (char*)malloc(256*sizeof(char));

	int fd1 = open("file.txt", O_WRONLY | O_CREAT, 0777);
	if(fd1 < 0){
		perror("open");
		exit(1);
	}
	int read_return;

	while(num_students > 0){
		memset(line, 256, '\0');

		while((read_return = read(STDIN_FILENO, line, 256)) <= 0){
			if(read_return < 0){
				perror("read");
				exit(1);
			}
		}
		
		if(write(fd1, line, strlen(line))<0){
			perror("write");
			exit(1);
		}

		num_students--;
	}
	close(fd1);
	free(line);
}