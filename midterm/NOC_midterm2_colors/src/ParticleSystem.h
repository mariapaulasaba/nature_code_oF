#pragma once
#include "ofMain.h"
#include "Mover.h"

class ParticleSystem{
    
    
private:
    
    vector<Mover> movers;
    ofVec2f origin;
    
    
    
public:
    
    ParticleSystem();
    void update();
    void draw();
    void addMover(const ofVec2f & initPosition, ofColor cor);
    void launch(int i);
    
};