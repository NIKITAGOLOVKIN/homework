all: main


main: schitalochka.o list.o
	gcc schitalochka.o list.o -o homework


schitalochka.o: schitalochka.c
	gcc -c schitalochka.c


list.o: list.c
	gcc -c list.c


clean:
	rm -f *.o main