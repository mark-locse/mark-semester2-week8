
#include <stdio.h>
#include <stdbool.h>

#include "shapes.h"

int main( void ) {

    Point point1 = makePoint(2,3);
    Point point2 = makePoint(6,7);
    Point point3 = makePoint(-4,4);
    Line line = makeLine(point1,point2);
    Triangle triangle = makeTriangle(point1,point2,point3);
    printf("%f\n",lineLength(line));
    printf("%f\n",triangleArea(triangle));
    printf("%d\n",samePoint(point1,point2));
    printf("%d\n",pointInLine(point3, line));
    printf("%d\n",pointInTriangle(point2, triangle));
    // test your code by calling the functions and printing the output 
    
    return 0;
}