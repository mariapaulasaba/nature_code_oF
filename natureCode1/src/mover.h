#pragma once

#include "ofMain.h"

class mover {
    
public:
    void setup(){
        location.set(ofRandomWidth(), ofRandomHeight());
        velocity.set(0, 0);
        topSpeed = 6;
    }
    
    void setTarget(const ofVec2f & target){
        acceleration = target - location;
        acceleration.normalize();
        acceleration *= 1.5;
    }
    
    void update(){
        // acceleration towards the mouse is set in testApp::draw
        velocity += acceleration;
        velocity.limit(topSpeed);
        location += velocity;
    }
    
    void draw(){
        ofSetColor(175);
        ofEllipse(location, 16, 16);
    }
    
    void checkEdges(){
        
        if (location.x > ofGetWidth()){
            location.x = 0;
        } else if (location.x < 0){
            location.x = ofGetWidth();
        }
        
        if (location.y > ofGetHeight()){
            location.y = 0;
        } else if (location.y < 0){
            location.y = ofGetHeight();
        }
        
    }
    
private:
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float topSpeed;
};
