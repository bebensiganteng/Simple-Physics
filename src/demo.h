//
//  demo.h
//  myFirstApp
//
//  Created by Rachmad Hidayat on 6/25/13.
//
//

#ifndef __myFirstApp__demo__
#define __myFirstApp__demo__

#include <iostream>
#include <math.h>

#include "ofMain.h"
#include "vector.h"
#include "physics.h"
#include "particle.h"
#include "edgeBounce.h"
#include "attraction.h"
#include "collision.h"
#include "behaviour.h"
#include "euler.h"
#include "verlet.h"
#include "force.h"
#include "spring.h"

class Demo {
    public:
    
        static short NUM_PARTICLES;
    
        // for cloth simulation
        static short CLOTH_SIZE;
        static short CLOTH_ROW;
        static short CLOTH_COLS;
    
        Demo();
    
        //TODO
        // add rule of 5?!?!
        // http://stackoverflow.com/questions/4782757/rule-of-three-becomes-rule-of-five-with-c11
        Demo(const Demo&);
        Demo& operator=(const Demo&);
        ~Demo() {};
    
        Physics physic;
    
        Particle mouse;
        
        Vector min;
        Vector max;
    
        double scount;
        
        Attraction attraction;
        Attraction repulsion;
    
        EdgeBounce bounds;
        Collision collision;
        Force force;
    
        void setupAttraction();
        void setupVerlet();
        void step();

};

#endif /* defined(__myFirstApp__demo__) */
