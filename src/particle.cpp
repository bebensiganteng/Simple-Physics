//
//  particle.cpp
//  myFirstApp
//
//  Created by Rachmad Hidayat on 6/25/13.
//
//

#include "particle.h"

short Particle::GUID = 0;

Particle::Particle () {
    p_id = GUID++;
    
    // TODO: add some cute color
    r = ofRandom(255);
    g = ofRandom(255);
    b = ofRandom(255);
    
    oldpos.pos = new Vector();
    oldpos.acc = new Vector();
    oldpos.vel = new Vector();
}

//Particle::~Particle() {
//    delete pos;
//    delete acc;
//    delete vel;
//}

//void Particle::setPos(Vector &_pos) {
//    pos = &_pos;
//}

void Particle::moveTo(float x, float y) {
    
    pos->set(x, y);
    oldpos.pos->set(x, y);
    
    //cout << "Particle::moveTo-> " << oldpos.pos->x << " " << oldpos.pos->y << endl;
    

}

void Particle::setMass(float _mass = 1.0) {
    
    mass    = _mass;
    massInv = 1.0/mass;
    
}

void Particle::setRadius(float _radius = 1.0) {
    
    radius      = _radius;
    radiusSq    = radius * radius;
    
}

