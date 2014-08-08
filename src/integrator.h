//
//  integrator.h
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/27.
//
//

#ifndef __emptyExample__integrator__
#define __emptyExample__integrator__

#include <iostream>
#include "particle.h"

class Integrator {
    public:
        virtual void integrate(Particle p, float drag) override;
};

#endif /* defined(__emptyExample__integrator__) */
