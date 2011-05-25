CXX = g++
CXX_FLAGS =
OBJECTS = main.o Bag.o

main.exe: $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) -o main.exe

%.o: &.cc
	$(CXX) $(CXX_FLAGS) -c $<

clean:
	rm *~ *.o *.exe

