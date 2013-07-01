//
//  collision.cpp
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/26.
//
//

#include "collision.h"
#include "demo.h"

void Collision::apply(Particle p, Vector dt, short index) {
    
    for (short i = 0; i < Demo::NUM_PARTICLES; i++) {
    
        
        
        if (pool[i].p_id != p.p_id) {
            
            Vector delta;
            
            delta.set(pool[i].pos->x, pool[i].pos->y);
            delta.operator-=(*p.pos);
                        
            float distance  = p.pos->distance(*pool[i].pos);
            float rad       = p.radius + pool[i].radius;
            
            if (distance <= rad) {
                
               //cout << "overlap" << endl;
                
                float dist = delta.length();
                
                float o = (p.radius + pool[i].radius) - dist;
                
                
                //cout << o << " " << dist << endl;
                
                float mt = p.mass + pool[i].mass;
                
                float r1 = pool[i].mass / mt;
                float r2 = p.mass / mt;
                
                Vector v = delta.clone();
                v.normalize();
                v.operator*=(o * -r1);
                p.pos->operator+(v);                
                
                delta.normalize();
                delta.operator*=(o * r2);
                
                pool[i].pos->operator+=(delta);
            }
        
        }
    }
    
   
}

