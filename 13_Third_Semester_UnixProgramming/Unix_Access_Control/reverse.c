#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_LEN 4096

int main(int args, char *argv[]) {

    char *buff[BUF_LEN];
    int len;
    if (args != 2) {
        printf("reverse <src-file>\n");
        return EXIT_FAILURE;
    }

    // open source file
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        printf("Error opening source file.\n");
        return EXIT_FAILURE;
    }

    // while not the end of the file - read
    len = read(fd, buff, BUF_LEN);
    close(fd);
    char tmpLast[] = buff;
    char copyItem[];
    write(1, *buff, len);		
    while (*tmpLast){
	tmpLast++;
    }	
    tmpLast--;
    
    while(buff < tmpLast){
	copyItem = *buff;
	*buff = *tmpLast;
	*buff = copyItem;
	buff++;
	tmpLast--;
    }
    write(1, *buff, len); 
    return 0;
}
