/*****************************************

  Stack.h and Stack.c implement a stack of characters.

  A client program accesses the stack via the interface defined below.

*********************************************/

/************************
 * Pushes character c onto the stack.
 * Returns 0 if successful.
 * Returns -1 if an error occurs because the stack is full.
 */
int push(char c);

/************************
 * Pops next character off the stack.
 * Returns the char if successful.
 * Returns -1 if an error occurs.  (Stack empty).
 */
int pop();

/************************
 * Returns the next character off the stack, if it exists.
 * Does not remove (pop) the character from the stack
 * Returns the char if successful.
 * Returns -1 if an error occurs.  (Stack empty).
 */
int peek();

/************************
 * isStackEmpty
 *
 * If the stack is empty, returns 1 (true).
 * Otherwise, returns 0 (false).
 */
int isStackEmpty();

/************************
 * Returns the current size of the stack.
 */
int getStackSize();

/************************
 * Empties the stack entirely.
 * After this call, getStackSize() should equal 0.
 */
void emptyStack();

/************************
 * For debugging purposes.
 * Prints out the indexes and contents of the stack,
 * from the top of the stack to the bottom. For example:
 * 3:   c
 * 2:   d
 * 1:   f
 * 0:   q
 */
void printStack();
