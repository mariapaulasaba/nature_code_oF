#pragma once
#include "ofMain.h"


class Particle{
	
public:
	
    
    Particle(ofVec2f origin);
    
    void run();
    void update();
	void display();
	Boolean isDead();
	
    
	
	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;
	float lifespan;
    
    
};


