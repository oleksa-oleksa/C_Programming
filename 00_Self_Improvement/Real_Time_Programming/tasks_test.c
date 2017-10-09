#include <stdio.h>
#include <stdlib.h>
#include "tasks_header.h"
#include <unistd.h>

int main(int n, char **v)
{
	printf("Creating tasks:\n");
	createTask(Task1, 5, 7003);
	createTask(Task2, 20, 8023);
	createTask(Task3, 20, 1299);

	startOS();

	return 0;
}

void Task1()
{
	while(1)
	{
		printf("I am a task 1 with the highest priority!\n");
		sleep(3);
		waitTask();
	}
}

void Task2()
{
	while(1)
	{
	
		printf("I am a task 2 with normal priority\n");
		printf("What is going on here?");
		sleep(3);
		waitTask();
	}
}

void Task3()
{
	while(1)
	{
	
		printf("I am a task 3 with normal priority\n");
		printf("Today is a Sunday!\n");
		sleep(3);
		waitTask();
	}
}
