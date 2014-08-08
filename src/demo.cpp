//
//  demo.cpp
//  myFirstApp
//
//  Created by Rachmad Hidayat on 6/25/13.
//
//

#include "demo.h"

#define DOT_SIZE 5
#define MASS 20

short Demo::NUM_PARTICLES = 2;
short Demo::CLOTH_SIZE    = 10;
short Demo::CLOTH_ROW     = 50;
short Demo::CLOTH_COLS    = 50;

Demo::Demo() {
    mouse.fixed = true;
    mouse.pos   = new Vector();
    scount      = 0;
}

void Demo::setupAttraction() {
    
    // add attraction
    attraction.setup(*mouse.pos, 1200, 1200);
    
    // add repulsion
    repulsion.setup(*mouse.pos, 200, -2000);
    
    max.set(ofGetWindowWidth(), ofGetWindowHeight());
    
    bounds.setMinMax(min, max);
    
    // Push all the behaviour
    physic.vBehaviour.push_back(&attraction);
    physic.vBehaviour.push_back(&repulsion);
    physic.vBehaviour.push_back(&bounds);
    physic.vBehaviour.push_back(&collision);
    
    // add integrator
    physic.integrator = new Verlet();
    //physic.integrator = new Euler();
    
    // Add objects
    physic.particles = new Particle[NUM_PARTICLES];
        
    for (short i = 0; i < NUM_PARTICLES; i++) {
        
        physic.particles[i].fixed = false;
        
        physic.particles[i].pos = new Vector();        
        physic.particles[i].acc = new Vector();
        physic.particles[i].vel = new Vector();
        
        physic.particles[i].moveTo(
            ofRandom(ofGetWindowWidth()),
            ofRandom(ofGetWindowHeight())
        );
        
        physic.particles[i].setMass(ofRandom(MASS));
        physic.particles[i].setRadius(physic.particles[i].mass * 4);
        
    }
    
    // add particles to the pool for vector look-up
    collision.pool = physic.particles;

}

void Demo::setupVerlet() {
    
    physic.integrator = new Verlet();
    //physic.timeStep = 1.0/200;
    
    mouse.setMass(10);
    
    //add gravity
    physic.vBehaviour.push_back(&force);
    
    // add integrator
    physic.integrator = new Verlet();
    
    //weave particles
    NUM_PARTICLES    = CLOTH_ROW * CLOTH_COLS;
    physic.particles = new Particle[NUM_PARTICLES];
    
    short sx = (ofGetWindowWidth() - (CLOTH_COLS * CLOTH_SIZE)) * 0.5;
    short sy = (ofGetWindowHeight() - (CLOTH_ROW * CLOTH_SIZE)) * 0.5;
    
    short x, y, count = 0;
    
    
    // add vector for the verlet
    vector< vector<Particle> > vParticle;
    
    for (x = 0; x < CLOTH_COLS; x++) {
        
        vector<Particle> row;
        
        for (y = 0; y < CLOTH_ROW; y++) {
            
            
            physic.particles[count].fixed = (y == 0) ? true : false;
            
            physic.particles[count].pos = new Vector();
            physic.particles[count].acc = new Vector();
            physic.particles[count].vel = new Vector();
            
            physic.particles[count].moveTo(
                (sx + x * CLOTH_SIZE),
                (sy + y * CLOTH_SIZE)
           );
            
            physic.particles[count].setRadius(DOT_SIZE);
            physic.particles[count].setMass(10);
            
            row.push_back(physic.particles[count]);
                                    
            count++;
            
        }
        
        vParticle.push_back(row);
        
    }
    
    count = 0;
    
    for (x = 0; x < vParticle.size(); x++) {
        
        for (y = 0; y < vParticle[x].size(); y++) {
            
            if (x > 0) {
                
                Spring spring;
                
                spring.setup(
                    physic.particles[count],
                    vParticle[x-1][y],
                    CLOTH_SIZE,
                    0.5
                );
                
                physic.vSpring.push_back(spring);
                
            }
            
            if (y > 0) {
                
                Spring spring;
                
                spring.setup(
                              physic.particles[count],
                              vParticle[x][y-1],
                              CLOTH_SIZE,
                              0.5
                              );

                physic.vSpring.push_back(spring);                
            }
            
            count++;
            
            
        }
    }
        
    Spring spring;
    
    spring.setup(mouse, vParticle[CLOTH_COLS/2][CLOTH_ROW/2], 4, 4);
    physic.vSpring.push_back(spring);
    
    //vParticle[0][0].fixed = true;
//    vParticle[CLOTH_COLS - 1][0].fixed = true;
    

}

void Demo::step() {
    
    physic.step(NUM_PARTICLES);
    
    
    //force.g.x = 50 * sin(0.0005 * scount++);
}


