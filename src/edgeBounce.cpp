//
//  edgeBounce.cpp
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/26.
//
//

#include "edgeBounce.h"

void EdgeBounce::apply(Particle p, Vector dt, short index) {
    
    if (p.pos->x - p.radius < min->x) {
        p.pos->x = min->x + p.radius;
    
    } else if(p.pos->x + p.radius > max->x) {
        p.pos->x = max->x - p.radius;
    }
    
    if (p.pos->y - p.radius < min->y)
    {
        p.pos->y = min->y + p.radius;
    
    } else if(p.pos->y + p.radius > max->y) {
        p.pos->y = max->y - p.radius;
    
    }
    
}

void EdgeBounce::setMinMax(Vector &_min, Vector &_max) {
    
    min = &_min;
    max = &_max;
    
}