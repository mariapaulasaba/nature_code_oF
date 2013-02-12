#pragma once

#include "ofMain.h"
#include "Mover.h"


class Attractor {
    
public:
    
    void setup();
    void update();
    void draw();
    ofVec2f attract(Mover m);
    

    
    
    
private:
    float mass;
    ofVec2f location;
    float G;
};
