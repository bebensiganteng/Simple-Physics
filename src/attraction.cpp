//
//  attraction.cpp
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/26.
//
//

#include "attraction.h"

void Attraction::setup(Vector &_target, float _radius = 1000, float _strength = 100) {
    
    target   = &_target;
    radius   = _radius;
    radiusSq = radius * radius;
    strength = _strength;
}

void Attraction::apply(Particle p, Vector dt, short index) {
    
    delta.set(target->x, target->y);
    delta.operator-=(*p.pos);
    
//    int distSq = delta.magSq();
//    
//    if (distSq < radiusSq && distSq > 0.000001) {
//        delta.normalize();
//        
//        delta.scale(1.0 - distSq / radiusSq);
//        
//        delta.scale(strength);
//        p.acc->operator+=(delta);
//    }
//    
//    
//    
}