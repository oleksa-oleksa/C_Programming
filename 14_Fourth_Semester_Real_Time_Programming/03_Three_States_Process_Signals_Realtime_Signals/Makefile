CFLAGS += -W -Wall
all: queue process prsim svss sset menu tools

queue: queue.o
	$(CC) $(CFLAGS) queue.c -o queue

process: process.o
	$(CC) $(CFLAGS) process.c -o process

prsim: process_simulation.c
	$(CC) $(CFLAGS) tools.c process.c queue.c processmodel.c process_simulation.c -o process_simulation

svss: signal_VS_realtime_signal.o
	$(CC) $(CFLAGS) signal_VS_realtime_signal.c -o signal_VS_realtime_signal

sset: signalset_implementation.o
	$(CC) $(CFLAGS) tools.c menu.c signalset_implementation.c -o signalset_implementation

# my libs
menu: menu.o
	$(CC) $(CFLAGS) menu.c -o menu

tools: tools.o
	$(CC) tools.c -o tools

clean:
	$(RM) *.o 
