FLAG = -std=c++11 -Wall -Wextra
RM = rm -f

all: main

# Multi-step compilation
main: main.o drink.o machine.o
	g++ -o $@ $^

main.o: main.cpp drink.hpp
	g++ $(FLAG) -c -o $@ $<

drink.o: drink.cpp drink.hpp
	g++ $(FLAG) -c -o $@ $<

machine.o: machine.cpp machine.hpp drink.hpp
	g++ $(FLAG) -c -o $@ $<

clean:
	$(RM) a.out *.o *.gch *.dSYM main