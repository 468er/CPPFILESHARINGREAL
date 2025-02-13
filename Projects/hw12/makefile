autograder: genericArray.o autograder.o
	g++ -std=c++11 -o autograder genericArray.o autograder.o

autograder.o: autograder.cpp
	g++ -std=c++11 -c autograder.cpp

genericArray.o: genericArray.cpp
	g++ -std=c++11 -c genericArray.cpp


main: genericArray.o main.cpp
	g++ -std=c++11 -o main genericArray.o main.cpp

clean:
	rm -f autograder
	rm genericArray.o
	rm autograder.o
	rm main.o
	rm -f main

grade:
	./autograder

run:
	./main
