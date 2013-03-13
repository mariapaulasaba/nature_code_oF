#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"


class Data {
public:
	ofVec2f initPosition;
    ofColor cor;
};



// A Custom Particle extending the box2d circle
class Mover : public ofxBox2dCircle {
	
public:
	void setupTheCustomData(const ofVec2f & initPosition, ofColor cor);
    
	void draw();
    
    void goBack();
    

    
};
