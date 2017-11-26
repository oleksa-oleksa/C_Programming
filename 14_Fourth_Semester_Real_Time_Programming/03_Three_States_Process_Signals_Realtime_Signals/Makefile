CFLAGS += -W -Wall
all: queue process tools

queue: queue.o
	$(CC) $(CFLAGS) queue.c -o queue

process: process.o
	$(CC) $(CFLAGS) process.c -o process

tools: tools.o
	$(CC) $(CFLAGS) tools.c -o tools

prsim: process_simulation.c
	$(CC) $(CFLAGS) tools.c process.c queue.c processmodel.c process_simulation.c -o process_simulation

svss: signal_VS_realtime_signal.o
	$(CC) $(CFLAGS) signal_VS_realtime_signal.c -o signal_VS_realtime_signal

clean:
	$(RM) *.o 
