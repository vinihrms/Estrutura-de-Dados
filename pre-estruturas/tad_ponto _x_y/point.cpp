#include <stdlib.h>
#include <math.h>
#include "point.h"

struct point{
    float x;
    float y;
};

Point *create_point(float x, float y){
    Point *p = (Point *) malloc(sizeof(Point));

    if(p != NULL){
        p->x = x;
        p->y = y;
    }

    return p;
};

void free_point(Point *p){
    free(p);
}

int access_point(Point *p, float x, float y){
    if (p != NULL){
        if ((p-> x == x) && (p->y == y)){
        return 1;   
        } 
    } 
    return 0;
}

int assign_point(Point *p, float x, float y){
    if(p != NULL){
        p -> x = x;
        p -> y = y;
        return 1;
    } else {
        return 0;
    }
}

float point_distance(Point *p1, Point *p2){
    float x_distance = p1->x - p2->x;
    float y_distance = p1->y - p2->y;

    return sqrt(pow(x_distance, 2) + pow(y_distance, 2));
}