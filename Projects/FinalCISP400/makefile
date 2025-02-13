main: unit.o main.cpp
	g++ -std=c++11 -o main unit.o main.cpp

unit.o: unit.cpp
	g++ -std=c++11 -c unit.cpp

clean:
	rm *.o
	rm -f autograder
	rm -f main

grade:
	./main

run:
	./main
