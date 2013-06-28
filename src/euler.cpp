//
//  euler.cpp
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/26.
//
//

#include "euler.h"
#include "demo.h"

void Euler::integrate(Particle p, float drag) {
    
    Vector vel;
    
    float dt = 1.0/6.0;
    
    //cout << "Euler::integrate -> " << Demo::NUM_PARTICLES << endl;
    
    if (!p.fixed) {
    
        p.oldpos.pos->copy(p.pos->x, p.pos->y);
        
        p.acc->scale(p.massInv);
        
        vel.copy(p.vel->x, p.vel->y);
        
        p.acc->scale(dt);
        p.vel->add(*p.acc);
        
        vel.scale(dt);
        p.pos->add(vel);
        
        p.acc->clear();
        
        
    }
    
}