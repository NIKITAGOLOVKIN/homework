#include <stdlib.h>



typedef struct StackBlock {       //структура блока стека
    char value;
    struct StackBlock *next;
} Block;




Block* newStack(void);     //создать стек

Block* push(Block *top, char value);     //отправить значение в стек


Block* pop(Block *top);    //удалить элемент стека


char peek(Block *top);     //вернуть значение из стека


void show(Block *top);     //вывести весь стек


void deleteStack(Block *top);   //удалить стек