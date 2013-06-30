//
//  vector.cpp
//  simplePhysics
//
//  Created by Rachmad Hidayat on 6/25/13.
//
//

#include "vector.h"

// Do I need this??
float Vector::mag() {
    return sqrt(x * x + y * y);
}

// Do I need this??
float Vector::magSq() {
    return x * x + y * y;
}

float Vector::cross(Vector v) {
    return (x * v.y) - (y * v.x);
}

Vector Vector::clone() { return *new Vector(); }

void Vector::clear() {
    x = 0;
    y = 0;
}