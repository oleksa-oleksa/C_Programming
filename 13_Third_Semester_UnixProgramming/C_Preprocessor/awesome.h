#pragma once
#include <stdio.h>

#define __awesome_ver 3

static void do_something_awesome(int a){
	printf("awesome: %d\n", a);
}

static void hello_awesome(char *name){
	printf("Hello %s! You are awesome!\n", name);
}
