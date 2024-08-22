System: Node.o Network.o main.o
	g++ Node.o Network.o main.o -o System

main.o: Node.h Network.h main.cpp
	g++ -c main.cpp

Network.o: Node.h Network.h Network.cpp
	g++ -c Network.cpp

Node.o: Node.h Node.cpp
	g++ -c Node.cpp

clean:
	rm -f *.o
	rm System

run: 	System
	./System

valgrind: System
	valgrind --leak-check=full --undef-value-errors=no ./System
