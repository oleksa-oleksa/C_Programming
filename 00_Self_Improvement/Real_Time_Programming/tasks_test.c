#include <stdio.h>
#include <stdlib.h>
#include "tasks_header.h"
#include <unistd.h>

int main()
{
	printf("Creating tasks:\n");
	createTask(Task1, 5, TASK_ID1);
	createTask(Task2, 20, TASK_ID2);
	createTask(Task3, 20, TASK_ID3);
	printf("Done...\n");
	startOS();

	return 0;
}

void Task1()
{
	while(1)
	{
		printf("I am a task 1 with the highest priority!\n");
		sleep(2);
		waitTask(TASK_ID1);
		sleep(2);
		startTask(TASK_ID1);
	}
}

void Task2()
{
	while(1)
	{
	
		printf("I am a task 2 with normal priority\n");
		printf("What is going on here?\n");
		sleep(5);
		waitTask(TASK_ID2);
		sleep(5);
		startTask(TASK_ID2);
	}
}

void Task3()
{
	while(1)
	{
	
		printf("I am a task 3 with normal priority\n");
		printf("Today is a Sunday!\n");
		sleep(3);
		waitTask(TASK_ID3);
		sleep(3);
		startTask(TASK_ID3);
	}
}
