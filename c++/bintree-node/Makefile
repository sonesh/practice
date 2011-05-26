CXX = g++
CXX_FLAGS = -Wall
OBJECTS = main.o
EXECUTABLE = main.exe

main.exe: $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cc
	$(CXX) $(CXX_FLAGS) -c $<

clean:
	rm *~ *.o *.exe