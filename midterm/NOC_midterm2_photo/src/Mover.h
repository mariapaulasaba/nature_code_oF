#pragma once
#include "ofMain.h"


class Mover {
    
public:
    float mass;
    ofVec2f location, initialLoc;
    ofVec2f velocity;
    ofVec2f acceleration;
    
    Mover(const ofVec2f & position , ofColor cor);
    void applyForce(const ofVec2f & force);
    void update();
    void draw();
    
    void setMass(float m);
    
    void goBack();
    void checkEdges();
    void airResistance();
    
    Boolean isBack;
    ofColor color;
    
    float maxForce;
    float maxSpeed;
    
    
    
};
