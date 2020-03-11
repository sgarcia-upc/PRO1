OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o stackIOpunt.o queueIOpunt.o Punt.o
	g++ -o program.exe program.o stackIOpunt.o queueIOpunt.o Punt.o
	rm *.o

program.o: program.cpp stackIOpunt.hpp queueIOpunt.hpp Punt.hpp
	g++ -c program.cpp $(OPCIONS)

stackIOpunt.o: stackIOpunt.cpp stackIOpunt.hpp Punt.hpp
	g++ -c stackIOpunt.cpp $(OPCIONS)

queueIOpunt.o: queueIOpunt.cpp queueIOpunt.hpp Punt.hpp
	g++ -c queueIOpunt.cpp $(OPCIONS)

Punt.o: Punt.cpp Punt.hpp
	g++ -c Punt.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
