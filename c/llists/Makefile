CC = gcc
CFLAGS = -Wall
OBJECTS = main.o node.o list.o

main.exe: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o main.exe

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *~ *.o *.exe

