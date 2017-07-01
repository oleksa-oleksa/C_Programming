#include <unistd.h>
#include <stdio.h>

int main(){
	char *tty;
	tty = ttyname(0);
	puts(tty);
	return 0;
}

