
#include <stdbool.h>
#include <math.h>

#include "shapes.h"

// complete other functions below
// - start with stubs as above
// - compile regularly to test syntax
// - test functions by calling them from main()

/*
  Structure initialisation functions
*/

Point makePoint( float x, float y ) {
    Point new;
    new.x = x;
    new.y = y;
    return new;
} // create and return a Point structure

Line makeLine( Point p1, Point p2 ) {
    Line line;
    line.p[0] = p1;
    line.p[1] = p2;
    return line;
} // create and return a Line structure

Triangle makeTriangle( Point p1, Point p2, Point p3 ) {
    Triangle triangle;
    triangle.p[0] = p1;
    triangle.p[1] = p2;
    triangle.p[2] = p3;
    return triangle;
} // create and return a Triangle structure

/*
  Structure calculation functions (requires <math.h>)
*/

float lineLength( Line l ) {
    return sqrt(pow(l.p[0].x-l.p[1].x,2)+pow(l.p[0].y-l.p[1].y,2));
} // calculate the length of a Line 

float triangleArea( Triangle t ) {
    return fabs((t.p[0].x * (t.p[1].y - t.p[2].y) +
    t.p[1].x * (t.p[2].y - t.p[0].y) +
    t.p[2].x * (t.p[0].y - t.p[1].y)) * 0.5);
} // calculate the area of a Triangle

/*
  Structure comparison functions (requires <stdbool.h>)

  Note: 
  * to compare 2 points you should not test float values for equality
  * test if they are "close enough"
  * eg. float values are accurate to 8 d.p.
  * abs(lineLength(p1,p2))<1.0e-6 would be sufficient to say p1 and p2 are the same point 
*/

bool samePoint( Point p1, Point p2 ) {
    if (p1.x == p2.x && p1.y == p2.y) {
        return true;
    }
    return false;
} // return true only if the point is the same location

bool pointInLine( Point p, Line l) {
    if (samePoint(p,l.p[0]) || samePoint(p,l.p[1])) {
        return true;
    }
    return false;
} // return true only if the point is one of the line endpoints

bool pointInTriangle( Point p, Triangle t ) {
    if (samePoint(p,t.p[0]) || samePoint(p,t.p[1]) || samePoint(p,t.p[2])) {
        return true;
    }
    return false;
} // return true only if the point is one of the triangle vertices
