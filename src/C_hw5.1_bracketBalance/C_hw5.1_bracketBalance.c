#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


int main(void)
{
    char s[] = "{    [1234576(1111   fwgqgqfd)]qjfbkhbfkh12878e f+4d 92+}";
    int len = strlen(s);
    char buff;
    Node *top = newStack();
    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            case '{': case '[': case '(':
                top = push(top, s[i]);
                break;


            case '}': case ']': case ')':
                buff = peek(top);
                if (buff == 0) {
                    printf("Стек пуст, а скобки еще есть\n");
                    printf("Баланс не выполнен\n");
                    deleteStack(top);
                    return 0;
                }

                if ((buff == '{' && s[i] == '}') || (buff == '[' && s[i] == ']') || (buff == '(' && s[i] == ')')) {
                    top = pop(top);
                    break;
                }
                else {
                    printf("Баланс не выполнен\n");
                    deleteStack(top);
                    return 0;
                }
        }
    }
    if (peek(top) == 0) {
        printf("Баланс выполнен\n");
        deleteStack(top);
    }

    else
        printf("Баланс не выполнен\n");
        deleteStack(top);
    return 0;
}