#include <stdio.h>
#include <errno.h> 
#include <unistd.h>
#include <stdlib.h>

int main () {
printf("Magic that I do not see\n");
perror("Another magic");
_exit(0);
}
