#include <stdio.h>
#include <string.h>
#include "stack.h"


void priority(char op1, char op2, int *n1, int *n2)   //функция для определения приоритетов операторов, где оп1 это оператор из стека, а оп2 оператор из строки
{
    if ((op1 == '*') || (op1 == '/')) {
	*n1 = 2;
    }
    else {
	*n1 = 1;
    }
    if ((op2 == '*') || (op2 == '/')) {
	*n2 = 2;
    }
    else {
	*n2 = 1;
    }
}



int main(void)
{
    char infix[] = "(1 + 1) * 2 + (3 + 3) * 4";
    printf("Инфиксная запись: %s\n\n", infix);
    int len = strlen(infix);
    int size = 0;
    for (int i = 0; i < len; ++i) {                                //считаем сколько в строке операторов и цифр
	if (infix[i] != '(' && infix[i] != ')' && infix[i] != ' ')
	    ++size;
    }
    char postfix[size];                                          //создаем массив размером сколько посчитали в цикле
    Block *top = newStack();
    int tracker = 0;           //индекс свободной ячейки выходного массива
    char buff;

    for (int i = 0; i < len; ++i) {                //пробегаем по строке
	switch (infix[i]) {
	    case '+': case '/': case '-': case '*':
		if (top == NULL) {                     //если стек пуст просто кидаем туда оператор
		    top = push(top, infix[i]);
		    break;
		}

		buff = peek(top);
		if (buff == '(') {                     //если в стеке скобка тоже просто кидаем оператор
		    top = push(top, infix[i]);
		    break;
		}

		int n1 = 0;
		int n2 = 0;
		priority(buff, infix[i], &n1, &n2);    //пока у оператора из стека приоритет >= приоритета оператора из строки
		while (n1 >= n2) {                     //операторы из стека отправляем в массив
		    postfix[tracker] = buff;
		    ++tracker;
		    top = pop(top);
		    if (top == NULL) {
			break;
		    }
		    buff = peek(top);
		}
		top = push(top, infix[i]);             //оператор из строки кидаем в стек
		break;



	    case '(':
		top = push(top, infix[i]);
		break;



	    case ')':              //идем по стеку до '(' и все операторы отправляем в массив
		buff = peek(top);
		while (buff != '(') {
		    postfix[tracker] = buff;
		    ++tracker;
		    top = pop(top);
		    buff = peek(top);
		}
		top = pop(top);
		break;



	    case ' ':   //пробелы просто пропускаем
		break;



	    default:           //если элемент цифра, отправляем в массив
		postfix[tracker] = infix[i];
		++tracker;
		break;
	}
    }


    while (top != NULL) {            //если в стеке еще остались операторы, отправляем их в массив
	postfix[tracker] = peek(top);
	++tracker;
	top = pop(top);
    }

    printf("Постфиксная запись: ");
    for (int i = 0; i < size; ++i) {
	printf("%c ", postfix[i]);                //печатаем массив
    }
    printf("\n");
    printf("\n");


    deleteStack(top);
    return 0;
}