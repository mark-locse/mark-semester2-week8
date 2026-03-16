
#include <stdio.h>
#include "shapes.h"

int main( void ) {

    // complete the structure definition in the header file first
    // code in main to test the structures and functions
    Rectangle r = makeRectangle((Point){2.0,1.5}, 5.0, 7.0);
    printf("Point: (%.1f,%.1f)\nWidth: %.1f\nHeight: %.1f\n",
            r.p.x,r.p.y,r.width,r.height);
    printf("Area: %.2f\n", area(r));
    Point dp;
    dp.x = 3;
    dp.y = -1;
    shiftRectangle(&r, dp);
    printf("Shifted: (%.1f,%.1f)\n", r.p.x,r.p.y);
    scaleRectangle(&r,2.0);
    printf("Scaled Width: %.1f\nScaled Height: %.1f\n", r.width,r.height);

    return 0;
}

Rectangle makeRectangle( Point p, float width, float height ){
    Rectangle r;
    r.p = p;
    r.width = width;
    r.height = height;

    return r;
}

float area( Rectangle r ) {
    float a = r.width*r.height;

    return a;
}

void shiftRectangle( Rectangle *r, Point dp ) {
    r->p.x += dp.x;
    r->p.y += dp.y;
    return;
}

void scaleRectangle( Rectangle *r, float scale ) {
    r->width *= scale;
    r->height *= scale;
    return;
}
