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
    
    float dt   = 1.0/60;
    float dtSq = dt * dt;
    
    if (!p.fixed) {
                
        p.acc->scale(p.massInv);
        
        p.vel->set(p.pos->x, p.pos->y);
        p.vel->operator-=(*p.oldpos.pos);

        p.acc->scale(dtSq);
        p.vel->operator+=(*p.acc);
        
        pos.set(p.pos->x, p.pos->y);
        pos.operator+=(*p.vel);
        
        //cout << pos.x << " " << pos.y << endl;
        
        p.oldpos.pos->set(p.pos->x, p.pos->y);
        
        p.pos->set(pos.x, pos.y);
        
        p.acc->clear();
        
    }
    
}