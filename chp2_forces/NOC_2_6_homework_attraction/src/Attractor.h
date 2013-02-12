#pragma once

#include "ofMain.h"
#include "Mover.h"


class Attractor {
    
public:
    
    void setup(unsigned int i);
    void update();
    void draw();
    ofVec2f attract(Mover m);
    
    void setLocation(int x, int y);
    
    
    
private:
    float mass;
    ofVec2f location;
    float G;
};
