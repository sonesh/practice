CC = gcc
CFLAGS = -Wall
OBJECTS = main.o stack.o node.o

main.exe: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o main.exe

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *~ *.o *.exe

