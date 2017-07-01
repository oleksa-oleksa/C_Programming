#include <unistd.h>
#include <stdio.h>
#define PATH 256 // 255 + 1
int main(){
	char *workDir;
	char path[PATH];
	workDir = getcwd(path, PATH);
	puts(workDir);
	return 0;
}
