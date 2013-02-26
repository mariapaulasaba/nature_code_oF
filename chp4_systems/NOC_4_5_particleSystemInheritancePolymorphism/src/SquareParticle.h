#pragma once
#include "ofMain.h"
#include "Particle.h"



class SquareParticle : public Particle{
    
public:
    
   SquareParticle(ofVec2f origin);
   void run();
   void display();
   void update();
    
};