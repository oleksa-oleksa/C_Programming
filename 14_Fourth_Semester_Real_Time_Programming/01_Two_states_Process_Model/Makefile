CFLAGS += -W -Wall
all: queue process tools qdemo prsim

queue: queue.o
	$(CC) queue.c -o queue

process: process.o
	$(CC)  process.c -o process

tools: tools.o
	$(CC) tools.c -o tools

qdemo: queuedemo.o
	$(CC) process.c queue.c tools.c queuedemo.c -o queuedemo

prsim: process_simulation.c
	$(CC) process_simulation.c -o process_simulation

clean: 
	$(RM) *.o 
