#include <stdio.h>
#include <stdlib.h>
#include "rect.h"

int main()
{
  Rect *r1 = createRect(5.2, 4.8, -2.1, 8);
  Rect *r2 = copyRect(r1);
  Rect *r3 = createRect(1.7, 9.2, 3.6, 4.3);

  char outStr[100];

  move(r1, 2.5, 4.4);
  dilate(r2, 3);
  move(r3, 2, -3);
  dilate(r3, 3);

  printf("R1 : %s\n", toString(r1, outStr));
  printf("R1 Area = %.1f\n", getArea(r1));
  printf("R1 Perimeter = %.1f\n\n", getPerimeter(r1));

  printf("R2 : %s\n", toString(r2, outStr));
  printf("R2 Area = %.1f\n", getArea(r2));
  printf("R2 Perimeter = %.1f\n\n", getPerimeter(r2));

  printf("R3 : %s\n", toString(r3, outStr));
  printf("R3 Width = %.1f\n", getWidth(r3));
  printf("R3 Height = %.1f\n", getHeight(r3));
  printf("R3 Area = %.1f\n", getArea(r3));
  printf("R3 Perimeter = %.1f\n", getPerimeter(r3));

  free(r1);
  free(r2);
  free(r3);
}
