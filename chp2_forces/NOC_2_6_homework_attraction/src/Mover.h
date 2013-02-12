#pragma once

#include "ofMain.h"

class Mover {
    
public:
    float mass;
    ofVec2f location;
    ofVec2f velocity;
   
    void setup();
    void applyForce(const ofVec2f & force);
    void update();
    void draw();
    
    void setMass(float m);
    void setLocation( float x, float y);
    void checkEdges();
    
    
    
private:
    ofVec2f acceleration;
};
