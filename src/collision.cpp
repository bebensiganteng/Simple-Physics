//
//  collision.cpp
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/26.
//
//

#include "collision.h"
#include "demo.h"

void Collision::setup() {
    
}

void Collision::apply(Particle p, Vector dt, short index) {
    for (short i = 0; i < Demo::NUM_PARTICLES; i++) {
        //cout << "TEST: " << pool[i].p_id << endl;
        
        if (pool[i].p_id != p.p_id) {
            
            delta.copy(pool[i].pos->x, pool[i].pos->y);
            delta.sub(*p.pos);
            
            float distSq = delta.magSq();
            
            float radii = p.radius + pool[i].radius;
            
            if (distSq <= radii * radii) {
                //cout << "overalaped: " << p.p_id << endl;
                
                float dist = delta.mag();
                
                float overlap = (p.radius + pool[i].radius) - dist;
                
                Vector v1 = delta.clone();
                v1.norm();
                v1.scale(overlap * -0.5);
                p.pos->add(v1);
                
                delta.norm();
                delta.scale(overlap * 0.5);
                pool[i].pos->add(delta);
                
                
            }
            
        }
    }
    
   
}

