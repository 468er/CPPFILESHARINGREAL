main: StackType.o balanced.cpp
	g++ -std=c++11 -o main StackType.o balanced.cpp

StackType.o: StackType.cpp
	g++ -std=c++11 -c StackType.cpp

clean:
	rm *.o
	rm -f main

run:
	./main

test:
	./main < test.txt
