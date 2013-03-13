#pragma once

#include "ofMain.h"


class Mover {
    
public:
    float mass;
    ofVec2f location;
    ofVec2f velocity;
    int id;
  
    void setup(int i);
    
    void applyForce(const ofVec2f & force);
    void update();
    void draw();
    
    void setMass(float m);
    void setLocation( float x, float y);
    void checkEdges();
    
    void resist();
    ofVec2f repel(Mover m);
    
private:
    ofVec2f acceleration;
    float G;

};
