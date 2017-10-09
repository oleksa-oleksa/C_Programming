/*
* Tasks Header
* 
*/

#ifndef TASKS_HEADER_H_
#define TASKS_HEADER_H_
#define TASK_ID1 100
#define TASK_ID2 200
#define TASK_ID3 300
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
void waitTask(int taskId);
void startTask(int taskId);

extern int taskPriority;
extern int highPriorityTask;
extern int currentRunningTask;
extern int taskCounter;

void (Task1) (void);
void (Task2) (void);
void (Task3) (void); 
