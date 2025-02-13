autograder: playTools.o play.o autograder.o
	g++ -std=c++11 -o autograder playTools.o play.o autograder.o

play.o: play.cpp
	g++ -std=c++11 -c play.cpp

playTools.o: playTools.cpp
	g++ -std=c++11 -c playTools.cpp

main: playTools.o play.o main.cpp
	g++ -std=c++11 -o main playTools.o play.o main.cpp

clean:
	rm -f autograder
	rm play.o
	rm playTools.o
	rm main.o
	rm -f main

grade:
	./autograder

run:
	./main
