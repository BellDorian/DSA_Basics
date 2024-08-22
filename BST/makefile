Project2: main.o Node.o Tree.o
	g++ Node.o Tree.o main.o -o Project2

main.o: main.cpp Node.h Tree.h
	g++ -c main.cpp

Tree.o: Tree.cpp Node.h Tree.h
	g++ -c Tree.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

run:
	Project2
	./Project2

clean:
	rm -f *.o
	rm Project2

valgrind: Project2
	valgrind --leak-check=full --undef-value-errors=no ./Project2
