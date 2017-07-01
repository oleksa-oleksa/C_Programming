/* Writing the program /bin/sync by using strace*/

#include <unistd.h>

int main(){

	sync();
	return 0;
}

