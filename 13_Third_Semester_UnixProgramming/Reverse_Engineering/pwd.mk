CC = gcc
CFLAGS = -W -Wall -Werror

OBJ = pwd
TARGET = $(OBJ).c

all: $(OBJ)

$(OBJ): $(OBJ).o
	$(CC) $(CFLAGS) -o $(OBJ) $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ).o
