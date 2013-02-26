#pragma once
#include "ofMain.h"


class Particle{
	
public:
	
    
    Particle(ofVec2f origin);
    
    virtual void run();
    virtual void update();
	virtual void display();
	Boolean isDead();
	
	
	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;
	float lifespan;
    
    
};


