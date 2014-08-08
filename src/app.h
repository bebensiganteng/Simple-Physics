#pragma once

#include "ofMain.h"
#include "demo.h"

class App : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void mouseMoved(int x, int y);
		
        Demo demo;
    
};
