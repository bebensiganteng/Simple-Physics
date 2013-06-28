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
    
    //cout << "Particle: " << p_id << endl;
    
    //oldpos->(*new Vector());
    //oldpos.setPos(*new Vector());
    
    r = ofRandom(255);
    g = ofRandom(255);
    b = ofRandom(255);
    
    oldpos.pos = new Vector();
    oldpos.acc = new Vector();
    oldpos.vel = new Vector();
}

//Particle::~Particle() {
//    delete pos;
//}

//void Particle::setPos(Vector &_pos) {
//    pos = &_pos;
//}

void Particle::moveTo(float x, float y) {
    
    pos->copy(x, y);
    oldpos.pos->copy(x, y);
    
    //cout << "x: " << oldpos.pos->x << " y: " << oldpos.pos->y << endl;
}

void Particle::setMass(float _mass = 1.0) {
    mass = _mass;
    massInv = 1.0/mass;
}

void Particle::setRadius(float _radius = 1.0) {
    radius = _radius;
    radiusSq = radius * radius;
}

//void Particle::update(int dt, short index) {
//    if (!fixed) {
//        //
//    }
//}