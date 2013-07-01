//
//  particle.h
//  myFirstApp
//
//  Created by Rachmad Hidayat on 6/25/13.
//
//

#ifndef __myFirstApp__particle__
#define __myFirstApp__particle__

#include <iostream>
#include "ofMain.h"
#include "vector.h"
#include "oldPosition.h"

class Particle {
    
    public:
    
        static short GUID;
    
        bool fixed;
    
        float mass;
        float radius;
        float radiusSq;
        float massInv;
    
        short p_id;
        short r;
        short g;
        short b;
    
        Vector *pos;
        Vector *acc;
        Vector *vel;
    
        OldPosition oldpos;
            
        Particle();
    
        //TODO
        // Something wrong with this, physics.h
        // when i add these
        //Particle(const Particle&);
        //Particle& operator=(const Particle&);
        //~Particle();
    
        //void setPos(Vector &_pos);
        void moveTo(float x, float y);
    
        void setMass(float);
        void setRadius(float);
    
};

#endif /* defined(__myFirstApp__particle__) */
