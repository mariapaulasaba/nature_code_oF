#pragma once

#include "ofMain.h"
#include "Bob.h"

class Spring{
    
private:
    float len;
    float k;
    

    
public:
    
    void setup(float x, float y, int l);
    ofVec2f connect(Bob b);
    void display(Bob b);
    
    ofVec2f anchor;

    
};


