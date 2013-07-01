#include "app.h"

//--------------------------------------------------------------
void App::setup(){
    
    ofEnableSmoothing();
    
    ofSetFrameRate(30);
    
    // For attraction demo
//    demo.setupAttraction();
    
    // For verlet demo
    demo.setupVerlet();
    
    Vector test;
//
    test.set(10,10);
    
    Vector d = test.clone();
    
    cout << "D: " << d.x << " " << d.y << endl;
//
//    cout << "--> " << test.length() << endl;
//    cout << "lengthSquared: " << test.lengthSquared() << endl;
}

//--------------------------------------------------------------
void App::update(){
    demo.step();
}

//--------------------------------------------------------------
void App::draw(){
    
    ofBackground(ofColor::black);
    
    for (short i = 0; i < demo.NUM_PARTICLES; i++) {
        ofSetColor(
            demo.physic.particles[i].r,
            demo.physic.particles[i].g,
            demo.physic.particles[i].b
        );
        
        ofCircle(
            demo.physic.particles[i].pos->x,
            demo.physic.particles[i].pos->y,
            demo.physic.particles[i].radius
        );
    }
    
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
}

//--------------------------------------------------------------
void App::mouseMoved(int x, int y){
    demo.mouse.pos->set(x, y);
}
