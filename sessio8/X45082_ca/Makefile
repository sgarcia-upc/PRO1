OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o llista_elem_central.o listIOint.o
	g++ -o program.exe program.o llista_elem_central.o listIOint.o
	rm *.o

program.o: program.cpp llista_elem_central.hpp listIOint.hpp
	g++ -c program.cpp $(OPCIONS)

llista_elem_central.o: llista_elem_central.cpp llista_elem_central.hpp
	g++ -c llista_elem_central.cpp $(OPCIONS)

listIOint.o: listIOint.cpp listIOint.hpp
	g++ -c listIOint.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
