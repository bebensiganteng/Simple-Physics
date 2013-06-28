//
//  vector.h
//  myFirstApp
//
//  Created by Rachmad Hidayat on 6/25/13.
//
//

#ifndef __myFirstApp__vector__
#define __myFirstApp__vector__

#include <iostream>
#include <math.h>
#include "ofMain.h"

class Vector {
    public:
        float x;
        float y;
    
        Vector(float nX = 0, float nY = 0) { set(nX, nY); }
    
        void add(Vector v);
        void sub(Vector v);
        void set(float nX, float nY);
        void clear();
    
        void scale(float val);
        float dot(Vector v);
    
        float mag();
        float magSq();
    
        Vector cross(Vector v);
        Vector copy(float nX, float nY);
    
        Vector norm();
        Vector clone();
};

#endif /* defined(__myFirstApp__vector__) */
