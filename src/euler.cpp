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
    
        p.oldpos.pos->set(p.pos->x, p.pos->y);
        
        p.acc->scale(p.massInv);
        
        vel.set(p.vel->x, p.vel->y);
        
        p.acc->scale(dt);
        p.vel->operator+=(*p.acc);
        
        vel.scale(dt);
        p.pos->operator+=(vel);
        
        p.acc->clear();
        
        
    }
    
}