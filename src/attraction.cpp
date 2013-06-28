//
//  attraction.cpp
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/26.
//
//

#include "attraction.h"

void Attraction::setup(Vector &_target, float _radius = 1000, float _strength = 100) {
    target = &_target;
    
    radius = _radius;
    radiusSq = radius * radius;
    
    strength = _strength;
    delta = new Vector();
}

void Attraction::apply(Particle p, Vector dt, short index) {
    
    delta->copy(target->x, target->y);
    delta->sub(*p.pos);
    
    int distSq = delta->magSq();
    
    if (distSq < radiusSq && distSq > 0.000001) {
        delta->norm();
        delta->scale(1.0 - distSq / radiusSq);
        
        p.acc->add(*delta);
        
        
    }
    
    
    
}