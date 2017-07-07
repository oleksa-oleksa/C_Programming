CFLAGS += -W -Wall

all: main macros ermacros kinda_project awesome multi_platform

main: main.o bye.o hello.o

macros: macros.o

ermacros: ermacros.o

kinda_project: kinda_project.o

awesome: awesome.h kinda_project.o

multi_platform: multi_platform.o

cleanObj: 
	$(RM) *.o

clean:
	$(RM) *.o main macros ermacros kinda_project awesome multi_platform
