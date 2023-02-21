#include <stdio.h>
#include <math.h>
#include "stack.h"

int main()
{
  int i;
  int result;

  /************************************************
  /* Check the initial state of the stack:
   */

  if (getStackSize() == 0)
    printf("Passed 1\n");
  else
    printf("**FAILED** 1\n");

  /* Check if an empty stack returns a non-zero (true) value. */

  if (isStackEmpty())
    printf("Passed 2\n");
  else
    printf("**FAILED** 2\n");

  /* Make sure a pop or peek of an empty stack returns -1*/
  result = pop();
  if (result == -1)
    printf("Passed 3\n");
  else
    printf("**FAILED** 3\n");

  result = peek();
  if (result == -1)
    printf("Passed 4\n");
  else
    printf("**FAILED** 4\n");

  /************************************************
  /* Push 15 values on the stack --
     Check results, isStackEmpty, and getStackSize */
  result = 0;

  for (i = 0; i < 15; i++)
    result += push(i);

  if (result == 0)
    printf("Passed 5\n");
  else
    printf("**FAILED** 5\n");

  if (getStackSize() == 15)
    printf("Passed 6\n");
  else
    printf("**FAILED** 6\n");

  if (!isStackEmpty())
    printf("Passed 7\n");
  else
    printf("**FAILED** 7\n");

  /************************************************
  /* Check two peeks and pops */
  /* Then make sure stack size is now 13.
   */

  if (peek() == 14)
    printf("Passed 8\n");
  else
    printf("**FAILED** 8\n");

  if (pop() == 14)
    printf("Passed 9\n");
  else
    printf("**FAILED** 9\n");

  if (pop() == 13)
    printf("Passed 10\n");
  else
    printf("**FAILED** 10\n");

  if (peek() == 12)
    printf("Passed 11\n");
  else
    printf("**FAILED** 11\n");

  if (getStackSize() == 13)
    printf("Passed 12\n");
  else
    printf("**FAILED** 12\n");

  /************************************************
  /* Empty the stack, and run the same tests as the beginning:
   */

  emptyStack();

  if (getStackSize() == 0)
    printf("Passed 13\n");
  else
    printf("**FAILED** 13\n");

  if (isStackEmpty())
    printf("Passed 14\n");
  else
    printf("**FAILED** 14\n");

  result = pop();
  if (result == -1)
    printf("Passed 15\n");
  else
    printf("**FAILED** 15\n");

  result = peek();
  if (result == -1)
    printf("Passed 16\n");
  else
    printf("**FAILED** 16\n");

  /************************************************
   * Stress test: Push 100 values on the stack --
   * All should have a result of 0.
   * Then push a 101th value and make sure the result is -1.
   */

  for (i = 0; i < 100; i++)
  {
    result = push(i);
    if (result != 0)
    {
      printf("**FAILED** 17 on push(%d)\n", i);
      break;
    }
  }
  if (result == 0)
  {
    printf("Passed 17\n");
  }
  result = push(101);
  if (result == -1)
    printf("Passed 18\n");
  else
    printf("**FAILED** 18\n");
}
