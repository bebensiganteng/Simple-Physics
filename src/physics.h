//
//  physics.h
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/26.
//
//

#ifndef __emptyExample__physics__
#define __emptyExample__physics__

#include <iostream>
#include <vector>

#include "ofMain.h"
#include "vector.h"
#include "particle.h"

#include "behaviour.h"
#include "attraction.h"
#include "edgeBounce.h"
#include "integrator.h"
#include "spring.h"

class Physics {
    public:
    
        Physics();
    
        //TODO
        // add rule of 5?!?!
        // http://stackoverflow.com/questions/4782757/rule-of-three-becomes-rule-of-five-with-c11
        Physics(const Physics&);
        Physics& operator=(const Physics&);
        ~Physics() {
            delete particles;
        };
    
        vector<Behaviour*> vBehaviour;
        vector<Spring> vSpring;
    
        float viscosity;
        float timeStep;
    
        Particle *particles;
        Integrator *integrator;
            
        friend class Particle;
    
        void step(short);
};

#endif /* defined(__emptyExample__physics__) */
