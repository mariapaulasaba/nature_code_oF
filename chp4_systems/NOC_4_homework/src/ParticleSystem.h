#pragma once
#include "ofMain.h"
#include "Particle.h"
#include "Radiance.h"


class ParticleSystem{

    
private:
    
    vector<Particle*> particles;
    ofVec2f origin;
    
    
    
public:
    
    ParticleSystem(ofVec2f location);
    void run();
    void addParticle();
    void applyForce(const ofVec2f & force);
    Boolean eraseSystem();
    int lifeTime, numParticles;
    ofColor cor;
    
    
    Radiance fire;

};