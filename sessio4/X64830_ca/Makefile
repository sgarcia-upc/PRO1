OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o list_punt_separa.o listIOpunt.o Punt.o
	g++ -o program.exe program.o list_punt_separa.o listIOpunt.o Punt.o
	rm *.o

program.o: program.cpp list_punt_separa.hpp listIOpunt.hpp Punt.hpp
	g++ -c program.cpp $(OPCIONS)

list_punt_separa.o: list_punt_separa.cpp list_punt_separa.hpp Punt.hpp
	g++ -c list_punt_separa.cpp $(OPCIONS)

listIOpunt.o: listIOpunt.cpp listIOpunt.hpp Punt.hpp
	g++ -c listIOpunt.cpp $(OPCIONS)

Punt.o: Punt.cpp Punt.hpp
	g++ -c Punt.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
