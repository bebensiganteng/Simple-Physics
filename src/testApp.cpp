#include "testApp.h"

;

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableSmoothing();
    
    ofSetFrameRate(30);
    
    // For attraction demo
    //demo.setupAttraction();
    
    // For verlet demo
    demo.setupVerlet();
}

//--------------------------------------------------------------
void testApp::update(){
    demo.step();
}

//--------------------------------------------------------------
void testApp::draw(){
    
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
void testApp::keyPressed(int key){
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
   // cout << "-->" << x << "-->" << y << endl;
    
    demo.mouse.pos->set(x, y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    //theball.x = ofRandom(ofGetWindowWidth());
    //theball.y = ofRandom(ofGetWindowHeight());
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}