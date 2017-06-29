CC = gcc -Wall
SOURCE = ueb10

run: link
	@./$(SOURCE)

link: compile
	$(CC) -o $(SOURCE) $(SOURCE).o tools.o -lm
	@echo File compiled

compile:
	$(CC) -c $(SOURCE).c tools.c

clean:
	rm -f $(SOURCE).o $(SOURCE)
	@echo Files deleted

all: clean run
