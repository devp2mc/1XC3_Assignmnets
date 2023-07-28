CC = gcc # Complier used
CFLAGS = -Wall -Wextra # Flags used
 
all: main # Excutable file
 
main: main.o functions.o readFile_randWord.o # Dependecies
	$(CC) $(CFLAGS) -o main main.o functions.o readFile_randWord.o 
 
main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c
 
functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

readFile_randWord.o: readFile_randWord.c readFile_randWord.h
	$(CC) $(CFLAGS) -c readFile_randWord.c
 
clean: # Cleans folder 
	rm -f main *.o
