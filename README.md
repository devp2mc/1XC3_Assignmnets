Variable Definitions:

CC = gcc: Defines the compiler to be used, in this case, gcc.
CFLAGS = -Wall -Wextra: Defines the compiler flags to be used. -Wall and -Wextra enable additional warning messages, helping to catch potential issues in the code during compilation.
Target Definitions:

all: main: The default target is all, which depends on the target main.
Target: main

Dependencies: main.o functions.o readFile_randWord.o
Action: This target compiles and links the object files (main.o, functions.o, and readFile_randWord.o) to create the final executable main.
Command: $(CC) $(CFLAGS) -o main main.o functions.o readFile_randWord.o
Target: main.o

Dependencies: main.c functions.h
Action: This target compiles the main.c file to create the object file main.o.
Command: $(CC) $(CFLAGS) -c main.c
Target: functions.o

Dependencies: functions.c functions.h
Action: This target compiles the functions.c file to create the object file functions.o.
Command: $(CC) $(CFLAGS) -c functions.c
Target: readFile_randWord.o

Dependencies: readFile_randWord.c readFile_randWord.h
Action: This target compiles the readFile_randWord.c file to create the object file readFile_randWord.o.
Command: $(CC) $(CFLAGS) -c readFile_randWord.c
Target: clean

Action: This target removes the main executable and all object files to clean up the directory.
Command: rm -f main *.o
