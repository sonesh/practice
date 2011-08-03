CC = gcc
CFLAGS = -Wall
OBJECTS = bit-next-prev.o bit-manip-utils.o
EXECUTABLE = bit-next-prev.exe

bit-next-prev.exe: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *~ $(OBJECTS) $(EXECUTABLE)