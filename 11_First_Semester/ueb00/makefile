CC = gcc -Wall
Prg = ueb00
Obj = ueb00.o

$(Prg): ueb00.o
	$(CC) -o $@ $^

ueb00.o: ueb00.c
	$(CC) -c $<

run: 
	@./$(Prg)

all: clean $(Prg) run

clean: 
	rm $(Obj) $(Prg) -f

