#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

bool areBracketsMatch(char open, char close)
{
    return (open == '{' && close == '}') ||
           (open == '[' && close == ']') ||
           (open == '(' && close == ')');
}

bool isBalanced(char *s)
{
    Node *top = newStack();
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            case '{': case '[': case '(':
                top = push(top, s[i]);
                break;
            case '}': case ']': case ')':
                char buff = peek(top);
                if (buff == 0) {
                    deleteStack(top);
                    return false;
                }
                if (areBracketsMatch(buff, s[i])) {
                    top = pop(top);
                } else {
                    deleteStack(top);
                    return false;
                }
        }
    }

    bool balanced = (peek(top) == 0);
    deleteStack(top);
    return balanced;
}

int main(void)
{
    char test[] = "{    [1234576(1111   fwgqgqfd)]qjfbkhbfkh12878e f+4d 92+}";
    if (isBalanced(&test))
        printf("Баланс выполнен\n");
    else
        printf("Баланс не выполнен\n");
    return 0;
}