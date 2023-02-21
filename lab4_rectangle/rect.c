#include <stdlib.h>
#include "rect.h"

Rect *createRect(double x1, double y1, double x2, double y2)
{
    Rect *r = malloc(sizeof(Rect));
    r->pt1.x = x1;
    r->pt1.y = y1;
    r->pt2.x = x2;
    r->pt2.y = y2;
    return r;
}

Rect *copyRect(Rect *r)
{
    Rect *r2 = malloc(sizeof(Rect));
    r2->pt1.x = r->pt1.x;
    r2->pt1.y = r->pt1.y;
    r2->pt2.x = r->pt2.x;
    r2->pt2.y = r->pt2.y;
    return r2;
}

void move(Rect *r, double dx, double dy)
{
    r->pt1.x += dx;
    r->pt1.y += dy;
    r->pt2.x += dx;
    r->pt2.y += dy;
}

void dilate(Rect *r, double factor)
{
    r->pt1.x *= factor;
    r->pt1.y *= factor;
    r->pt2.x *= factor;
    r->pt2.y *= factor;
}

double getWidth(Rect *r)
{
    double width = r->pt2.x - r->pt1.x;
    if (width < 0)
    {
        width *= -1;
    }
    return width;
}

double getHeight(Rect *r)
{
    double height = r->pt2.y - r->pt1.y;
    if (height < 0)
    {
        height *= -1;
    }
    return height;
}
double getArea(Rect *r)
{
    return getWidth(r) * getHeight(r);
}

double getPerimeter(Rect *r)
{
    return 2 * (getWidth(r) + getHeight(r));
}

char *toString(Rect *r, char out[])
{
    sprintf(out, "Rectangle: (%.1f,%.1f); (%.1f,%.1f)", r->pt1.x, r->pt1.y, r->pt2.x, r->pt2.y);
    return out;
}
