//
//  spring.h
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/27.
//
//

#ifndef __emptyExample__spring__
#define __emptyExample__spring__

#include <iostream>
#include "vector.h"
#include "particle.h"

class Spring {
    public:
        float stiffness;
        float restlength;
    
        Particle p1;
        Particle p2;
        Vector delta;
    
        void setup(Particle _p1, Particle _p2, float, float);
        void apply();
        
};

#endif /* defined(__emptyExample__spring__) */
