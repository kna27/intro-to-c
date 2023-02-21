#define STACK_SIZE 100
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

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
      if (getStackSize() == 0)
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
  if (getStackSize() != 0)
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
