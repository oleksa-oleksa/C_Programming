/*
* Tasks Header
* 
*/

#ifndef TASKS_HEADER_H_
#define TASKS_HEADER_H_
#endif

typedef struct {
	void (*pTaskAddr) (void);
	int priority;
	int ready;
	int taskId;
} taskTable;	

void startOS();
void scheduler();
void createTask(void (*pTaskAddr) (void), int taskPriority, int taskId);
void waitTask();
void startTask(int taskId);

extern int taskPriority;
extern int highPriorityTask;
extern int currentRunningTask;
extern int taskCounter;

void (Task1) (void);
void (Task2) (void);
void (Task3) (void); 
