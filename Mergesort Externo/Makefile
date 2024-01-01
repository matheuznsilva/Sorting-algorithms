main: main.o mergeSortExterno.o quickSort.o
	gcc main.o mergeSortExterno.o quickSort.o -o main

main.o: main.c
	gcc -c main.c

mergeSortExterno.o: mergeSortExterno.c mergeSortExterno.h
	gcc -c mergeSortExterno.c -o mergeSortExterno.o

quickSort.o: Quicksort/quickSort.c Quicksort/quickSort.h
	gcc -c Quicksort/quickSort.c -o quickSort.o

clean:
	rm *.o main
