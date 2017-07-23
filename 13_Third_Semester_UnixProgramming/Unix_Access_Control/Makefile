CFLAGS += -W -Wall

all: createFiles append reverse fd_copy

createFiles: createFiles.o

append: append.o

reverse: reverse.o

fd_copy: fd_copy.o

cleanObj:
	$(RM) *.o

clean: 
	$(RM) *.o createFiles append reverse fd_copy
