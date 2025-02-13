autograder: ships.o autograder.o
	g++ -std=c++11 -o autograder ships.o autograder.o

autograder.o: autograder.cpp
	g++ -std=c++11 -c autograder.cpp

ships.o: ships.cpp
	g++ -std=c++11 -c ships.cpp


main: ships.o main.cpp
	g++ -std=c++11 -o main ships.o main.cpp

clean:
	rm -f autograder
	rm ships.o
	rm main.o
	rm -f main

grade:
	./autograder

run:
	./main
