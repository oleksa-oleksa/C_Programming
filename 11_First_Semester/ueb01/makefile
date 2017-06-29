CC = gcc -Wall
Prg = ueb01
Obj = ueb01.o

$(Prg): ueb01.o
	$(CC) -o $@ $^

ueb01.o: ueb01.c
	$(CC) -c $<

run: 
	@./$(Prg)

all: clean $(Prg) run

clean: 
	rm $(Obj) $(Prg) -f


