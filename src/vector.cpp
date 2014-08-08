//
//  vector.cpp
//  simplePhysics
//
//  Created by Rachmad Hidayat on 6/25/13.
//
//

#include "vector.h"


float Vector::cross(Vector v) {
    return (x * v.y) - (y * v.x);
}

Vector Vector::clone() {
    Vector v;
    v.set(x,y);
    
    return v;
}

void Vector::clear() {
    x = 0;
    y = 0;
}