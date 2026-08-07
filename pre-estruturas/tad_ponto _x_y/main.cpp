#include <iostream>
#include "point.h"
using namespace std;

int main(){

    // pick the coordinates
    float x1, y1, x2, y2;
    cout << "Insert an x value for point 1: ";
    cin >> x1;
    cout << "Insert an y value for point 1: ";
    cin >> y1;

    cout << "Insert an x value for point 2: ";
    cin >> x2;
    cout << "Insert an y value for point 2: ";
    cin >> y2;

    // creating a point
    Point *p1, *p2;
    p1 = create_point(x1, y1);
    p2 = create_point(x2, y2);

    float distance = point_distance(p1, p2);

    cout << "Distance between p1 and p2: " << distance << ".\n";

    free_point(p1);
    free_point(p2);
    
    return 0;
}