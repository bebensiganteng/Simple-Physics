//
//  euler.cpp
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/26.
//
//

#include "euler.h"
#include "demo.h"

void Euler::integrate(Particle p, float dt, float drag) {
    
    Vector vel;
    
    cout << "Euler::integrate -> " << dt << endl;
    
    if (!p.fixed) {
    
        p.oldpos.pos->set(p.pos->x, p.pos->y);
        
        p.acc->operator*=(p.massInv);
        
        vel.set(p.vel->x, p.vel->y);
        
        p.acc->operator*=(dt);
        p.vel->operator+=(*p.acc);
        
        vel.operator*=(dt);
        p.pos->operator+=(vel);
        
        //cout << vel.x << " " << vel.y << endl;
        
        p.acc->clear();
        
        
    }
    
}