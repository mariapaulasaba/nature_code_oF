///
//  Wave.cpp
//  NOC_3__homework
//
//  Created by Maria Paula Saba dos Reis on 2/19/13.
//
//

#include "Wave2.h"
void Wave::setup(int x, int y, int w, int h){
    
    startAngle = 0;
    angleVel = 0.1;
    
    size = 3;
    
    startX = x;
    startY = y;
    width = w;
    height = h;
    
    vel = ofRandom(0.1,0.3);
    
}


void Wave::update(){
    angle = startAngle;
    
    
    startAngle += vel;
    
    
    
}



void Wave::display(){
    
    
    for (int x = startX; x <= startX + width; x+= 1) {
        float y = ofMap(sin(angle), 1, -1, startY, startY+height);
        
        
        ofSetColor(0);
        ofNoFill();
        
        if(x == startX+width) ofSetColor(255,0,0);
        else ofSetColor(0, 50);
        ofFill();
        ofCircle(x, y, size);
        
        angle += angleVel;
    }
    
    
    
    
    
}
