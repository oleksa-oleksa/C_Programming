CC = gcc -Wall
SOURCE = ueb11

run: link
	@./$(SOURCE)

link: compile
	$(CC) -o $(SOURCE) $(SOURCE).o tools.o text.o -lm
	@echo File compiled

compile:
	$(CC) -c $(SOURCE).c tools.c text.c

clean:
	rm -f $(SOURCE).o $(SOURCE)
	@echo Files deleted

all: clean run
