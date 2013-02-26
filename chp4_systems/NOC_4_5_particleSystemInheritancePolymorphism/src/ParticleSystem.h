#pragma once
#include "ofMain.h"
#include "Particle.h"
#include "SquareParticle.h"


class ParticleSystem{

    
    
public:
    
    ParticleSystem(ofVec2f location);
    void run();
    void addParticle();
    
    vector<Particle*> particles;
    ofVec2f origin;
};