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
    
    Vector vel = *new Vector();
    
    //cout << "Euler::integrate -> " << Demo::NUM_PARTICLES << endl;
    
    if (!p.fixed) {
        
        //p.acc->scale(1);
        
        p.pos->add(*p.acc);
        
        //p.acc->clear();
        //cout << p.acc->x << " " << p.acc->y << endl;
    }
    
}