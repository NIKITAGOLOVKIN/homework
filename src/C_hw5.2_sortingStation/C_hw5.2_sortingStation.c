#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int priority(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int convertToPostfix(char* infix, char* postfix)
{
    Node* top = newStack();
    int tracker = 0;
    int len = strlen(infix);

    for (int i = 0; i < len; ++i) {
        switch (infix[i]) {
        case '+':
        case '/':
        case '-':
        case '*':
            char current_op = infix[i];
            while (top != NULL && peek(top) != '(') {
                char stack_op = peek(top);
                if (priority(stack_op) < priority(current_op))
                    break;

                postfix[tracker] = stack_op;
                tracker++;
                top = pop(top);
            }
            top = push(top, current_op);
            break;

        case '(':
            top = push(top, infix[i]);
            break;

        case ')': // идем по стеку до '(' и все операторы отправляем в массив
            while (top != NULL && peek(top) != '(') {
                postfix[tracker] = peek(top);
                tracker++;
                top = pop(top);
            }
            if (top != NULL && peek(top) == '(') {
                top = pop(top); // Удаляем '(' из стека
            }
            break;

        case ' ': // пробелы просто пропускаем
            break;

        default: // если элемент цифра, отправляем в массив
            postfix[tracker] = infix[i];
            tracker++;
            break;
        }
    }

    while (top != NULL) { // если в стеке еще остались операторы, отправляем их в массив
        postfix[tracker] = peek(top);
        ++tracker;
        top = pop(top);
    }
}

int main(void)
{
    char* infix = "(1 + 2) * 3";
    printf("Инфиксная запись: %s\n\n", infix);
    char* postfix = malloc(strlen(infix) * 2);
    convertToPostfix(infix, postfix);
    printf("Постфиксная запись: %s\n", postfix);
    free(postfix);
    return 0;
}