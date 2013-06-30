//
//  vector.h
//  simplePhysics
//
//  Created by Rachmad Hidayat on 6/25/13.
//
//

#ifndef __myFirstApp__vector__
#define __myFirstApp__vector__

#include <iostream>
#include <math.h>
#include "ofMain.h"

class Vector:public ofVec2f {
    public:

        float mag();
        float magSq();
        float cross(Vector v);
    
        Vector clone();
    
        void clear();

};

#endif /* defined(__myFirstApp__vector__) */
