objects = main.o DynArray.o

scc : $(objects)
	g++ -o scc $(objects)

main.o : main.cpp DynArray.h
	g++ -c main.cpp

DynArray.o : DynArray.cpp DynArray.h
	g++ -c DynArray.cpp

clean:
	rm scc main.o DynArray.o
