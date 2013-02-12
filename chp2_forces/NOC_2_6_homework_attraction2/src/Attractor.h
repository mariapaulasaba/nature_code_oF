#pragma once

#include "ofMain.h"
#include "Mover.h"


class Attractor {
    
public:
    float mass;
    ofVec2f location;
    
    void setup();
    void update();
    void draw();
    
    ofVec2f attract(Mover m);
    
    void setLocation(int x, int y);
    
    
    
private:
    float G;

    
};
