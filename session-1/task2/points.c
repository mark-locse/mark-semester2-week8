
#include <stdio.h>
#include <math.h>
#include "points.h"

int main( void ) {
    // complete the structure definition in the header file first
    // implement code for the following
    // include necessary libraries
    /*
    Point p1 = { .x=1, .y=2 };
    Point p2 = { .x=-2, .y=4 };
    
    printf(" Distance between (%.1f,%.1f) and (%.1f,%.1f) is %f\n", 
             p1.x,p1.y,p2.x,p2.y,distance(p1,p2));
    */
    struct _point;
    Point p1;
    Point p2;
    p1.x = 1;
    p1.y = 2;
    p2.x = -2;
    p2.y = 4;

    printf("Distance between (%.1f,%.1f) and (%.1f,%.1f) is %.2f\n", 
             p1.x,p1.y,p2.x,p2.y,distance(p1,p2));

    Point Rp1 = reflect(p1);
    Point Rp2 = reflect(p2);
    Point p3 = shift(p1, p2);
    printf("The reflections of (%.1f,%.1f) and (%.1f,%.1f) are (%.1f,%.1f) and (%.1f,%.1f)\n", 
             p1.x,p1.y,p2.x,p2.y,Rp1.x,Rp1.y,Rp2.x,Rp2.y);
    printf("The shifting of (%.1f,%.1f) by (%.1f,%.1f) leads to a point at (%.1f,%.1f)\n",
             p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
    return 0;
}

float distance( Point p, Point q ) {
    // implement distance here
    return sqrt(pow(p.x-q.x,2)+pow(p.y-q.y,2));
}

Point reflect( Point p) {
    Point R;
    R.x = p.x;
    R.y = -p.y;

    return R;
}

Point shift( Point q, Point dq) {
    Point S;
    S.x = q.x+dq.x;
    S.y = q.y+dq.y;

    return S;
}