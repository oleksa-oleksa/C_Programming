#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pwd.h>

int main(){
	uid_t userID;
	struct passwd *userName;
	userID = geteuid();
	userName = getpwuid(userID);
	
	puts(userName->pw_name);
	return 0;
}
