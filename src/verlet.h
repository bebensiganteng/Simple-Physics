//
//  verlet.h
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/27.
//
//

#ifndef __emptyExample__verlet__
#define __emptyExample__verlet__

#include <iostream>
#include "particle.h"
#include "integrator.h"

class Verlet:public Integrator {
    public:
        void integrate(Particle p, float drag);
};

#endif /* defined(__emptyExample__verlet__) */
