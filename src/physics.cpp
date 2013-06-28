//
//  physics.cpp
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/26.
//
//

#include "physics.h"
#include "demo.h"

Physics::Physics () {
    viscosity = 0.005;
}


void Physics::step(short pLength) {
    
    short i,j;
    float drag = 1.0 - viscosity;
    
    for (i = 0; i < pLength; i++) {
        
        for (j = 0; j < vBehaviour.size(); j++) {
            
            vBehaviour[j]->apply(particles[i], *new Vector(), i);
        
        };
        
        integrator->integrate(particles[i], drag);
    }
    

    for (i = 0; i < vSpring.size(); i++) {
        vSpring[i].apply();
    }
    
}