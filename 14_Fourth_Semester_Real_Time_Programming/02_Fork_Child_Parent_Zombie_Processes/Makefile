CFLAGS += -W -Wall
all: tools menu orphan orpan2 zombie my_environ ggfather

orphan: orphan_reaping.o
	$(CC) $(CFLAGS) tools.c orphan_reaping.c -o orphan_reaping

orphan2: orphan_reaping_goodbye.o
	$(CC) $(CFLAGS) tools.c orphan_reaping_goodbye.c -o orphan_reaping_goodbye

zombie: zombie.o
	$(CC) $(CFLAGS) zombie.c -o zombie

my_environ: my_environ.o
	$(CC) $(CFLAGS) tools.c menu.c my_environ.c -o my_environ

ggfather: grandgrantfather.c
	$(CC) $(FLAGS) grandgrantfather.c -o grandgrantfather

# my libs
menu: menu.o
	$(CC) $(CFLAGS) menu.c -o menu

tools: tools.o
	$(CC) tools.c -o tools

clean: 
	$(RM) *.o 
