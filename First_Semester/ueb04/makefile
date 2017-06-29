CC = gcc -Wall
SOURCE = ueb04

run: link
	@./$(SOURCE)

link: compile
	$(CC) -o $(SOURCE) $(SOURCE).o -lm
	@echo File compiled

compile:
	$(CC) -c $(SOURCE).c

clean:
	rm -f $(SOURCE).o $(SOURCE)
	@echo Files deleted

all: clean run
