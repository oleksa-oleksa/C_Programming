#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_LEN 4096

int main(int args, char *argv[]){
	char *buff[BUF_LEN];
	if (args != 2){
		printf("fd_copy <filename>\n");
		return EXIT_FAILURE;
	}
	int fd1 = open(argv[1], O_RDONLY);
	printf("fd1 = %d\n", fd1);
	int fd2 = dup(fd1);
	printf("fd2 = %d\n", fd2);
	int fd3 = open(argv[1], O_RDONLY);
	printf("fd3 = %d\n", fd3);
	int fd4 = dup(fd3);
	printf("fd4 = %d\n", fd4);
	int fd1_off = read(fd1, buff, 5);
	int fd2_off = lseek(fd2, 0, SEEK_CUR);
	int fd3_off = read(fd3, buff, 17);
        int fd4_off = lseek(fd4, 0, SEEK_CUR);
	printf("offset fd1 = %d; offset fd2 = %d\n", fd1_off, fd2_off);
        printf("offset fd3 = %d; offset fd4 = %d\n", fd3_off, fd4_off);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return 0;	
}

