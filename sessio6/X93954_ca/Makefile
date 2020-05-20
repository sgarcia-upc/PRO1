OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Punt.o
	g++ -o program.exe program.o Punt.o
	rm *.o

program.o: program.cpp arbreBin.hpp
	g++ -c program.cpp $(OPCIONS)

Punt.o: Punt.cpp Punt.hpp
	g++ -c Punt.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
