#include <stdio.h>

struct stack
{
   int arraySize;
   double *stack;
   int sp;
};

struct point
{
   double x;
   double y;
};

typedef struct point Point;

// Look, we can define a struct AND typedef it conveniently
// in one statement, instead of two.
typedef struct rect
{
   // NOTE - these are NOT pointers.
   Point pt1;
   Point pt2;
} Rect;

Rect *createRect(double x1, double y1, double x2, double y2);
/* Creates a new "Rectangle" object, defined by the coordinates x1,y1 and x2,y2.
   It is the responsibility of the calling code to free the Rectangle when done.
   */

Rect *copyRect(Rect *r);
/* Creates a new "Rectangle" object that is a deep copy of the passed rectangle "r".
   It is the responsibility of the calling code to free the Rectangle when done.
   */

void move(Rect *r, double dx, double dy);
/* Translates rectangle "r" by dx and dy. */

void dilate(Rect *r, double factor);
/* Dilates rectangle "r" by "factor" about the origin. */

double getWidth(Rect *r);
/* Returns the absolute width of the rectangle "r", as defined
   by the difference of the "x" coordinate values. */

double getHeight(Rect *r);
/* Returns the absolute height of the rectangle "r", as defined
   by the difference of the "y" coordinate values. */

double getArea(Rect *r);
/* Returns the area of the rectangle. */

double getPerimeter(Rect *r);
/* Returns the perimeter of the rectangle. */

char *toString(Rect *r, char out[]);
/* Writes a string representation of Rectangle r to "out".
   "out" must be large enough for the string, 50 characters is plenty.
   The function returns a reference to out to make printing easier.
   */
