all: main


main: main.o quickSort.s
	gcc main.o quickSort.s -o homework


main.o: main.c
	gcc -c main.c


clean:
	rm -f *.o main