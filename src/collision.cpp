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
            
            ofVec2f p1(p.pos->x, p.pos->y);
            ofVec2f p2(pool[i].pos->x, pool[i].pos->y);
            
            float distance = p1.distance(p2);
            
            float rad = p.radius + pool[i].radius;
            
            //cout << distance << endl;
            
            if (distance <= rad) {
                
                //p1.normalize();
                //p2.normalize();
                
                //float dot = p1.dot(p2);
                
                //cout << "dot: " << dot << endl;
                
                Vector v1;
                
                v1.copy(p.pos->x, p.pos->y);
                v1.norm();
                v1.scale(-1);
                
                cout << v1.x << " " << v1.y << endl;
                p.pos->add(v1);
            }
        
        }
    }
    
   
}

