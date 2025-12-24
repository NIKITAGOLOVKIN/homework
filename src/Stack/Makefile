all: main


main: C_hw5.1_bracketBalance.o stack.o
	gcc C_hw5.1_bracketBalance.o stack.c -o homework


C_hw5.1_bracketBalance.o: C_hw5.1_bracketBalance.c
	gcc -c C_hw5.1_bracketBalance.c


stack.o: stack.c
	gcc -c stack.c


clean:
	rm -f *.o main