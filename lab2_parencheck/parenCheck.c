#define STACK_SIZE 100
#include <stdio.h>
#include <stdbool.h>

char stack[STACK_SIZE];
int sp = 0;

/*
 * Pushes character c onto the stack.
 * Returns 0 if successful.
 * Returns -1 if an error occurs.  (Stack full).
 */
int push(char c)
{
  if (sp == STACK_SIZE)
  {
    return -1;
  }
  stack[sp++] = c;
  return 0;
}

/*
 * Pops next character off the stack.
 * Returns the char if successful.
 * Returns -1 if an error occurs.  (Stack empty).
 */
int pop()
{
  if (sp == 0)
  {
    return -1;
  }
  return stack[--sp];
}

/*
 * Returns the current size of the stack.
 */
int stackSize()
{
  return sp;
}

/*
 * Prints the stack positions and contents:
 * For example, if 'X', 'Y', and 'Z' were pushed onto the stack
 * printStack should print:
 *
 * 0: X
 * 1: Y
 * 2: Z
 *
 * An empty stack should print nothing.
 */
void printStack()
{
  int i;
  for (i = 0; i < sp; i++)
  {
    printf("%d: %c\n", i, stack[i]);
  }
}

int main()
{
  char c;
  int character = 0;
  int line = 1;
  bool inQuotes;
  while ((c = getchar()) != EOF)
  {
    character++;
    if (c == '"')
    {
      inQuotes = !inQuotes;
    }
    if (inQuotes)
    {
      continue;
    }
    if (c == '\n')
    {
      line++;
      character = 0;
    }
    if (c == '(' || c == '[' || c == '{')
    {
      if (push(c) == -1)
      {
        printf("Error: Stack Full!\n");
        return -1;
      }
    }
    else if (c == ')' || c == ']' || c == '}')
    {
      if (stackSize() == 0)
      {
        printf("Error: Line %d, Char %d: Found %c. No matching character.\n", line, character, c);
        return -1;
      }
      else
      {
        int error = 0;
        char top = pop();
        if (c == ')' && top != '(')
        {
          error = 1;
        }
        else if (c == ']' && top != '[')
        {
          error = 1;
        }
        else if (c == '}' && top != '{')
        {
          error = 1;
        }
        if (error == 1)
        {
          char expected = top == '(' ? ')' : top == '[' ? ']'
                                                        : '}';
          printf("Line %d, Char %d: Found %c, expected %c\n", line, character, c, expected);
          return 0;
        }
      }
    }
  }
  if (stackSize() != 0)
  {
    char top = pop();
    char expected = top == '(' ? ')' : top == '[' ? ']'
                                                  : '}';
    printf("Error: expecting %c, found end of input.\n", expected);
    return -1;
  }
  printf("Well formatted input.\n");
  return 0;
}
