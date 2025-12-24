all: main


main: C_hw5.2_sortingStation.o stack.o
	gcc C_hw5.2_sortingStation.o stack.o -o homework


C_hw5.2_sortingStation.o: C_hw5.2_sortingStation.c
	gcc -c C_hw5.2_sortingStation.c


stack.o: stack.c
	gcc -c stack.c


clean:
	rm -f *.o main