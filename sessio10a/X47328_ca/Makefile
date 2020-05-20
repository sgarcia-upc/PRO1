OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o cua_encuar_preferencia.o cua.o
	g++ -o program.exe program.o cua_encuar_preferencia.o cua.o
	rm *.o

program.o: program.cpp cua.hpp
	g++ -c program.cpp $(OPCIONS)

cua_encuar_preferencia.o: cua_encuar_preferencia.cpp cua.hpp
	g++ -c cua_encuar_preferencia.cpp $(OPCIONS)
	
cua.o: cua.cpp cua.hpp
	g++ -c cua.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
