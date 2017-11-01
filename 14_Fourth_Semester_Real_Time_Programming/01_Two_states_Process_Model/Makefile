CFLAGS += -W -Wall
all: queue process tools qdemo prsim

queue: queue.o
	$(CC) $(CFLAGS) queue.c -o queue

process: process.o
	$(CC) $(CFLAGS) process.c -o process

tools: tools.o
	$(CC) $(CFLAGS) tools.c -o tools

qdemo: queuedemo.o
	$(CC) $(CFLAGS) process.c queue.c tools.c queuedemo.c -o queuedemo

prsim: process_simulation.c
	$(CC) $(CFLAGS) process_simulation.c -o process_simulation

clean: 
	$(RM) *.o 
