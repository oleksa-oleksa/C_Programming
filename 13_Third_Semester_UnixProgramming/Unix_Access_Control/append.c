#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_LEN 4096

int main(int args, char *argv[]) {

    char *buff[BUF_LEN];
    int len;
    if (args != 3) {
        printf("append <src-file> <dst-file>\n");
        return EXIT_FAILURE;
    }

    // open source and destination files
    int fdS = open(argv[1], O_RDONLY);
    if (fdS < 0) {
        printf("Error opening source file.\n");
        return EXIT_FAILURE;
    }

    int fdD = open(argv[2], O_WRONLY | O_APPEND);
    if (fdD < 0) {
        printf("Error opening destination file.\n");
        return EXIT_FAILURE;
    }

    // read and write
    // while not the end of the file - read
    while((len = read(fdS, buff, BUF_LEN)) > 0) {
        write(fdD, buff, len);
    }
    close(fdS);
    close(fdD);
    return 0;
}
