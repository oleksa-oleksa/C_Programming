CFLAGS += -W -Wall
all: orphan orpan2 tools

orphan: orphan_reaping.o
	$(CC) $(CFLAGS) tools.c orphan_reaping.c -o orphan_reaping

orphan2: orphan_reaping_goodbye.o
	$(CC) $(CFLAGS) tools.c orphan_reaping_goodbye.c -o orphan_reaping_goodbye

zombie: zombie.o
	$(CC) $(CFLAGS) zombie.c -o zombie

tools: tools.o
	$(CC) tools.c -o tools

clean: 
	$(RM) *.o 
