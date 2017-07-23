#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

int getFileMode(char *par) {
    int rights =0;
    while(*par) {
        rights = rights << 3;
        rights = rights | (*par -'0');
        par++;
    }
    return rights;
}

int main(int args, char *argv[]) {

    if(args != 3) {
        printf("createFiles filename rights");
        return EXIT_FAILURE;
    }

    int rights = getFileMode(argv[2]);

    int fd = open(argv[1], O_CREAT | O_EXCL, rights);
    if (fd < 0) {
        perror(argv[1]);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
