//
//  attraction.h
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/26.
//
//

#ifndef __emptyExample__attraction__
#define __emptyExample__attraction__

#include <iostream>
#include "vector.h"
#include "particle.h"
#include "behaviour.h"

class Attraction:public Behaviour {
    public:
    
        Vector *target;
        Vector delta;
    
        float radius;
        float radiusSq;
        float strength;
    
        void setup(Vector &_target, float, float);
        void apply(Particle p, Vector dt, short index);
};

#endif /* defined(__emptyExample__attraction__) */
