//
//  vector.cpp
//  myFirstApp
//
//  Created by Rachmad Hidayat on 6/25/13.
//
//

#include "vector.h"

void Vector::add(Vector v){
    x += v.x;
    y += v.y;
}

void Vector::set(float nX, float nY) {
    x = nX;
    y = nY;
}

void Vector::sub(Vector v){
    x -= v.x;
    y -= v.y;
}

// scale the vector
void Vector::scale(float val){
    x *= val;
    y *= val;
}

// dot products between vectors;
float Vector::dot(Vector v) {
    return x * v.x + y * v.y;
}

// Magnitude
float Vector::mag() {
    return sqrt(x * x + y * y);
}

// Squared magniture (length)
float Vector::magSq() {
    return x * x + y + y;
}

Vector Vector::cross(Vector v) {
    return (x * v.y) - (y * v.x);
}

Vector Vector::copy(float nX, float nY){
    x = nX;
    y = nY;
    
    return *this;
}

// normalize
Vector Vector::norm() {
    float m = sqrt(x * x + y * y);
    
    //cout << "Vector::norm ->" << m << endl;
    
    x /= m;
    y /= m;
    
    return *this;
}

Vector Vector::clone() {
    
    Vector *m = new Vector(x, y);
    
    return *m;
    
}

void Vector::clear() {
    x = 0;
    y = 0;
}