objects = main.o DynArray.o Lex.o TkWord.o

scc : $(objects)
	g++ -o scc $(objects)

main.o : main.cpp DynArray.h
	g++ -c main.cpp

DynArray.o : DynArray.cpp DynArray.h
	g++ -c DynArray.cpp

Lex.o : Lex.cpp Lex.h TkWord.h
	g++ -c Lex.cpp

Tkword.o : Tkword.cpp TkWord.h DynArray.h
	g++ -c Tkword.cpp

clean:
	rm scc main.o DynArray.o
