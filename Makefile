objects = main.o DynArray.o Lex.o TkWord.o

scc : $(objects)
	g++ -o scc $(objects)

main.o : main.cpp main.h DynArray.h
	g++ -c -g main.cpp

DynArray.o : DynArray.cpp DynArray.h TkWord.h
	g++ -c -g DynArray.cpp

Lex.o : Lex.cpp Lex.h TkWord.h
	g++ -c -g Lex.cpp

Tkword.o : Tkword.cpp TkWord.h DynArray.h
	g++ -c -g Tkword.cpp


clean:
	rm scc main.o DynArray.o
