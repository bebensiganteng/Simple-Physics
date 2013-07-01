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

void Verlet::integrate(Particle p, float dt, float drag) {
    
    Vector pos;
    
    float dtSq = dt * dt;
    
    if (!p.fixed) {
        
        // Scale force to mass
        p.acc->operator*=(p.massInv);
        
        // Derive velocity
        p.vel->set(p.pos->x, p.pos->y);
        p.vel->operator-=(*p.oldpos.pos);
        
        //if(drag)
        
        // apply forces to new pos
        p.acc->operator*=(dtSq);
        p.vel->operator+=(*p.acc);

        pos.set(p.pos->x, p.pos->y);
        pos.operator+=(*p.vel);

        p.oldpos.pos->set(p.pos->x, p.pos->y);

        p.pos->set(pos.x, pos.y);
        
        p.acc->clear();
        
    }

    
}