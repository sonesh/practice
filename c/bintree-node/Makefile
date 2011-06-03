CC = gcc
CFLAGS = -Wall
OBJECTS = main.o binarytreenodeutils.o binarytreenode.o
EXECUTABLE = main.exe

main.exe: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *~ $(OBJECTS) $(EXECUTABLE)