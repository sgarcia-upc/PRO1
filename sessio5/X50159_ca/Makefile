OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o listIOint.o
	g++ -o program.exe program.o listIOint.o
	rm *.o

program.o: program.cpp listIOint.hpp arbreBin.hpp
	g++ -c program.cpp $(OPCIONS)

listIOint.o: listIOint.cpp listIOint.hpp
	g++ -c listIOint.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
