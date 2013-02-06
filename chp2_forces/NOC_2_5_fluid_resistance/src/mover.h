#pragma once

#include "ofMain.h"
#include "liquid.h"

class mover {
    
public:
    ofVec2f velocity;
    float mass;
    
    
    
    void setup();
    void applyForce(const ofVec2f & force);
    void update();
    void draw();
    void begin();
    
    void setMass(float m);
    void setLocation( float x, float y);
    void checkEdges();
    Boolean isInside(liquid l);
    void drag(liquid l);
    
    
private:
    ofVec2f location;
    // ofVec2f velocity;
    ofVec2f acceleration;
};
