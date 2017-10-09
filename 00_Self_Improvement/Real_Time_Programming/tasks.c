#include "tasks_header.h"
taskTable arrTasksTable[3];
int taskCounter;
int taskPriority;
int highPriorityTask;
int currentRunningTask; 

void startOS () 
{
	startTask(7003);
	startTask(8023);
	startTask(1299);
	scheduler();
}

void scheduler() 
{	
	highPriorityTask = 10;
	
	for (int i = 0; i < taskCounter; i++)
	{
		// if it the task with a highest priority and it is ready to execute
		if ((arrTasksTable[i].priority <= highPriorityTask) && (arrTasksTable[i].ready == 1))			
		{
			//call the task with the high priority
			(*arrTasksTable[i].pTaskAddr)();
		}
		// if the task with highest priority is not ready
		// the lower priority task may start
		if ((arrTasksTable[i].priority > highPriorityTask) && (arrTasksTable[i].ready == 1))
		{
			(*arrTasksTable[i].pTaskAddr)();
		}
	}	
}

void createTask(void (*pTaskAddr) (void), int taskPriority, int taskId)
{
	//Save Task's attributes
	arrTasksTable[taskCounter].pTaskAddr = pTaskAddr;
	arrTasksTable[taskCounter].priority = taskPriority; 
	arrTasksTable[taskCounter].taskId = taskId;
	// set the ready status
	arrTasksTable[taskCounter].ready = 1;

	taskCounter++;
}

void waitTask(int taskId)
{
		for (int i = 0; i < taskCounter; i++)
	{
		if (taskId == arrTasksTable[i].taskId)
		{
			arrTasksTable[i].ready = 0;
		}
	}
	scheduler();
}

void startTask(int taskId)
{
	for (int i = 0; i < taskCounter; i++)
	{
		if (taskId == arrTasksTable[i].taskId)
		{
			arrTasksTable[i].ready = 1;
		}
	}
	scheduler();
}
