//
//  collision.h
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/26.
//
//

#ifndef __emptyExample__collision__
#define __emptyExample__collision__

#include <iostream>
#include "vector.h"
#include "behaviour.h"
#include "particle.h"


class Collision:public Behaviour {
    public:
        void apply(Particle p, Vector dt, short index);
    
        Particle *pool;
        Vector delta;
    
        void setup();
    
};

#endif /* defined(__emptyExample__collision__) */
