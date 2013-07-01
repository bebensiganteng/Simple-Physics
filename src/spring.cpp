//
//  spring.cpp
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/27.
//
//

#include "spring.h"

void Spring::setup(Particle _p1, Particle _p2, float _r = 100, float _s = 1.0) {
    
    p1          = _p1;
    p2          = _p2;
    
    stiffness   = _s;
    restlength  = _r;
    
}

// F= -kx

void Spring::apply() {
     
    delta.set(p2.pos->x, p2.pos->y);
    delta.operator-=(*p1.pos);

    float dist = delta.length() + 0.000001;
    
//    if (p1.p_id > 1 && p1.p_id < 10) {
//        cout << "Spring::apply-> " << endl;
//        cout << p1.p_id << " " << p1.pos->x << " " << p1.pos->y << endl;
//        cout << delta.x << " " << delta.y << endl;
//        
//        delta.operator-=(*p1.pos);
//        double length = sqrt(delta.x * delta.x + delta.y * delta.y);
//        double dist = 10 + 0.000001;
//        
//        cout << "delta: " << dist << endl;
//
//    }
    
    
    float force = (dist - restlength) / (dist * (p1.massInv + p2.massInv)) * stiffness;

    
    if (!p1.fixed) {
        
        Vector d1 = delta.clone();
        d1.operator*=(force * p1.massInv);
        
        p1.pos->operator+=(d1);
    }
    
    if (!p2.fixed) {
        
        delta.operator*=(-force * p2.massInv);
        
        p2.pos->operator+=(delta);
    }
}