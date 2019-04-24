LFLAG= -Wall
CFLAGS= -Wall -std=c++14 -g -O0 -pedantic-errors


main: main.cpp quickSort.o selectionSort.o mergeSort.o heapSort.o randomizedQuickSort.o
	g++ $(LFLAG) -o main main.cpp  quickSort.o selectionSort.o mergeSort.o heapSort.o randomizedQuickSort.o -g
 
run: main.cpp quickSort.o selectionSort.o mergeSort.o heapSort.o randomizedQuickSort.o
	g++ -std=c++14 -g -o run main.cpp  quickSort.o selectionSort.o mergeSort.o heapSort.o randomizedQuickSort.o -g

quickSort.o: quickSort.cpp quickSort.h
	g++ $(CFLAGS) -c quickSort.cpp

selectionSort.o: selectionSort.cpp selectionSort.h
	g++ $(CFLAGS) -c selectionSort.cpp
 
mergeSort.o: mergeSort.cpp mergeSort.h
	g++ $(CFLAGS) -c mergeSort.cpp
 
heapSort.o: heapSort.cpp heapSort.h
	g++ $(CFLAGS) -c heapSort.cpp
 
randomizedQuickSort.o: randomizedQuickSort.cpp randomizedQuickSort.h
	g++ $(CFLAGS) -c randomizedQuickSort.cpp
clean:
	rm *.o mai