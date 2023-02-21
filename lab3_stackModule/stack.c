#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

#define STACK_SIZE 100

char stack[STACK_SIZE];
int sp = 0;

int push(char c)
{
    if (sp == STACK_SIZE)
    {
        return -1;
    }
    stack[sp++] = c;
    return 0;
}

int pop()
{
    if (sp == 0)
    {
        return -1;
    }
    return stack[--sp];
}

int peek()
{
    if (sp == 0)
    {
        return -1;
    }
    return stack[sp - 1];
}

int isStackEmpty()
{
    return sp == 0 ? 1 : 0;
}

int getStackSize()
{
    return sp;
}

void emptyStack()
{
    sp = 0;
}

void printStack()
{
    int i;
    for (i = 0; i < sp; i++)
    {
        printf("%d: %c\n", i, stack[i]);
    }
}
