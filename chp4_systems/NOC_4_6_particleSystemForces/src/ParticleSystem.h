#pragma once
#include "ofMain.h"
#include "Particle.h"

class ParticleSystem{

    
private:
    
    vector<Particle> particles;
    ofVec2f origin;
    
    
    
public:
    
    ParticleSystem(ofVec2f location);
    void run();
    void addParticle();
    void applyForce(const ofVec2f & force);

};