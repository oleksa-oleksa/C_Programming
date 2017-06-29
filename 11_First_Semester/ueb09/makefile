CC = gcc -Wall
SOURCE = ueb09

run: link
	@./$(SOURCE)

link: compile
	$(CC) -o $(SOURCE) $(SOURCE).o tools.o matrix.o -lm
	@echo File compiled

compile:
	$(CC) -c $(SOURCE).c tools.c matrix.c

clean:
	rm -f $(SOURCE).o $(SOURCE)
	@echo Files deleted

all: clean run
