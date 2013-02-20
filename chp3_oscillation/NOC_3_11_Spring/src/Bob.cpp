//
//  Bob.cpp
//  NOC_3_11_Spring
//
//  Created by Maria Paula Saba dos Reis on 2/18/13.
//
//

#include "Bob.h"
#include "Spring.h"


void Bob::setup(float x, float y){
    location.set(x, y);
    velocity.set(0,0);
    acceleration.set(0,0);
    dragOffset.set(0,0);

}




void Bob::update(){
    velocity += acceleration;
    velocity *= damping;
    location += velocity;
    
    acceleration *= 0;
}

void Bob::applyForce(const ofVec2f & force){
    ofVec2f f(force/mass);
    acceleration += f;

}



void Bob::display(){
    
    if (dragging) ofSetColor(0);
    else  ofSetColor(175);
    ofFill();
    ofCircle(location.x, location.y, mass*2);
    
}



void Bob::clicked(int mx, int my){
    float d = ofDist(mx, my, location.x, location.y);
    if(d< 2*mass){
        dragging = true;
        dragOffset.x = location.x-mx;
        dragOffset.y = location.y-my;
    }
}


void Bob::stopDragging(){
        dragging = false;
    
}
    
    
    
void Bob::drag(int mx, int my){

    if(dragging){
        location.x = mx + dragOffset.x;
        location.y = my + dragOffset.y;
        
    }
}



void Bob::constrainLength(float minLen, float maxLen){
    ofVec2f anchor(ofGetWidth()/2, 10);
    ofVec2f dir;
    dir = location - anchor;
    
    float d = dir.length();
    
    if(d < minLen){
        dir.normalize();
        dir *= minLen;
        
        location = anchor + dir;
        velocity *= 0;
    }
    
    else if(d > maxLen){
        dir.normalize();
        dir *= maxLen;
        
        location = anchor + dir;
        velocity *= 0;
        
    }
}
