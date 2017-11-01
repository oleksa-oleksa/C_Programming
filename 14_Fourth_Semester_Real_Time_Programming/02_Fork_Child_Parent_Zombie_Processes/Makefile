CFLAGS += -W -Wall
all: orphan tools

orphan: orphan_reaping.o
	$(CC) $(CFLAGS) tools.c orphan_reaping.c -o orphan_reaping

tools: tools.o
	$(CC) tools.c -o tools

clean: 
	$(RM) *.o 
