CFLAGS += -W -Wall

all: tasks tasks_test

tasks: tasks.o 

tasks_test: # tasks_header.h tasks tasks_test
	$(CC) tasks.c tasks_test.c -o tasks_test
clean:
	$(RM) *.o tasks tasks_test
