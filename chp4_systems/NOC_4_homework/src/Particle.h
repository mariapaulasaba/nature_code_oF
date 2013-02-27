#pragma once
#include "ofMain.h"


class Particle{
	
public:
	
    
    Particle(const ofVec2f origin, ofColor c);
    
    void run();
    void update();
	void display();
	Boolean isDead();
	void applyForce(const ofVec2f & force);
    
	
	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;
    float mass;
	float lifespan;
    
    vector < ofPoint > points;
    int size;
    ofColor cor;
    
    
};


