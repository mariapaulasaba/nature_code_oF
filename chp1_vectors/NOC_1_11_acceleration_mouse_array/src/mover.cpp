//
//  mover.cpp
//  NOC_1_11_acceleration_mouse_array
//
//  Created by Maria Paula Saba dos Reis on 2/19/13.
//
//

#include "mover.h"

void Mover::setup(){
    location.set(ofRandomWidth(), ofRandomHeight());
    velocity.set(0, 0);
    topSpeed = 6;
    size = ofRandom(16);
    cor = ofRandom(255);
}

void Mover::setTarget(const ofVec2f & target, float diff){
    acceleration = target - location;
    acceleration.normalize();
    acceleration *= diff;
}

void Mover::update(){
    // acceleration towards the mouse is set in testApp::draw
    velocity += acceleration;
    velocity.limit(topSpeed);
    location += velocity;
}

void Mover::draw(){
    ofSetColor(cor, 125);
    ofEllipse(location, size, size);
}

void Mover::checkEdges(){
    
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