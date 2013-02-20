#pragma once

#include "ofMain.h"



class Wave {
    
public:
    void setup(int x, int y, int w, int h);
    void update();
    void display();
    void setTarget(const ofVec2f & target, float diff);
    
    
    int startX, width;
    
private:
    float startAngle = 0;
    float angleVel;
    float angle;
    
    int size;
    int  startY, height;
    float vel;
    
    
    
    
    
};