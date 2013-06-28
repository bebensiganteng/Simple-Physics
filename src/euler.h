//
//  euler.h
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/26.
//
//

#ifndef __emptyExample__euler__
#define __emptyExample__euler__

#include <iostream>
#include "particle.h"
#include "vector.h"
#include "integrator.h"

class Euler:public Integrator {
    public:
        void integrate(Particle p, float drag);
};

#endif /* defined(__emptyExample__euler__) */
