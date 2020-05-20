OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o pila_duplica.o pila.o
	g++ -o program.exe program.o pila_duplica.o pila.o
	rm *.o

program.o: program.cpp pila.hpp
	g++ -c program.cpp $(OPCIONS)

pila_duplica.o: pila_duplica.cpp pila.hpp
	g++ -c pila_duplica.cpp $(OPCIONS)
	
pila.o: pila.cpp pila.hpp
	g++ -c pila.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
