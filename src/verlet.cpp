//
//  verlet.cpp
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/27.
//
//

#include "verlet.h"

// v = x - ox
// x = x + (v + a * dt * dt)

void Verlet::integrate(Particle p, float drag) {
    
    Vector pos;
    
    float dtSq = (1.0/60) * (1.0/6.0);
    
    if (!p.fixed) {
                
        p.acc->scale(p.massInv);
        
        p.vel->copy(p.pos->x, p.pos->y);
        p.vel->sub(*p.oldpos.pos);
        

        p.acc->scale(dtSq);
        p.vel->add(*p.acc);
        
        pos.copy(p.pos->x, p.pos->y);
        pos.add(*p.vel);
        
        //cout << pos.x << " " << pos.y << endl;
        
        p.oldpos.pos->copy(p.pos->x, p.pos->y);
        
        p.pos->copy(pos.x, pos.y);
        
        p.acc->clear();
        
    }
    
}