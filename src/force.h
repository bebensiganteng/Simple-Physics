//
//  force.h
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/27.
//
//

#ifndef __emptyExample__force__
#define __emptyExample__force__

#include "behaviour.h"
#include "vector.h"
#include "particle.h"

class Force:public Behaviour {
    public:
        void apply(Particle p, Vector dt, short index);
        
        Vector g;
    
};

#endif /* defined(__emptyExample__force__) */
