OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o pila_concatena.o stackIOint.o
	g++ -o program.exe program.o pila_concatena.o stackIOint.o
	rm *.o

program.o: program.cpp pila_concatena.hpp stackIOint.hpp
	g++ -c program.cpp $(OPCIONS)

pila_concatena.o: pila_concatena.cpp pila_concatena.hpp
	g++ -c pila_concatena.cpp $(OPCIONS)
	
stackIOint.o: stackIOint.cpp stackIOint.hpp
	g++ -c stackIOint.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
