Sorter: Main.o
	g++ Main.o -o Sorter

Main.o: Main.cpp Main.h quicksort.h heapsort.h
	g++ -c Main.cpp

run:
	Sorter
	./Sorter

clean:
	rm *.o
	rm Sorter

valgrind: Sorter
	valgrind --leak-check=full ./Sorter
