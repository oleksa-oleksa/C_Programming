#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pwd.h>
#include "hello.h"
#include "bye.h"

int main (){

	uid_t userID;
        struct passwd *userName;
        userID = geteuid();
        userName = getpwuid(userID);

        sayHi(userName->pw_name);
	sayBye(userName->pw_name);
        
	return 0;

}
