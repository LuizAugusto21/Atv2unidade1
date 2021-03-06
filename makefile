all:	function.o main.o
	g++ -o main function.o main.o

function.o:	function.cpp function.hpp
	g++ -c function.cpp

main.o:	main.cpp function.hpp
	g++ -c main.cpp

clean:
	rm -rf *.o

run:
	./main