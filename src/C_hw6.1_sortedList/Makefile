all: main


main: sortedList.o list.o
	gcc sortedList.o list.o -o homework


sortedList.o: sortedList.c
	gcc -c sortedList.c


list.o: list.c
	gcc -c list.c


clean:
	rm -f *.o main