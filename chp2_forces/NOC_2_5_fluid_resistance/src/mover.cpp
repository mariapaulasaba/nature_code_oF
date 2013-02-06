//
//  mover.cpp
//  NOC_2_5_fluid_resistance
//
//  Created by Maria Paula Saba dos Reis on 2/6/13.
//
//

#include "mover.h"


void mover::setup(){
    location.set(0, 0);
    velocity.set(0, 0);
    acceleration.set(0, 0);
    
    
    mass = 1;
}

void mover::applyForce(const ofVec2f & force){
    ofVec2f f(force/mass);
    acceleration += f;
}

void mover::update(){
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
}

void mover::draw(){
    ofSetColor(175);
    ofFill();
    ofEllipse(location, mass * 16, mass * 16);
    
    ofSetColor(0);
    ofNoFill();
    ofEllipse(location, mass * 16, mass * 16);
    
}

void mover::begin(){
    location.y = 0;
    velocity.set(0, 0);
    acceleration.set(0, 0);
    
}


void mover::setMass(float m){
    mass = m;
}

void mover::setLocation( float x, float y){
    location.set(x, y);
}

void mover::checkEdges(){
    
    if (location.x > ofGetWidth()){
        velocity.x *= -1;
        location.x = ofGetWidth();
    } else if (location.x < 0){
        velocity.x *= -1;
        location.x = 0;
    }
    
    if (location.y > ofGetHeight()){
        // velocity.y *= -1;
        location.y = ofGetHeight();
    }
}

Boolean mover::isInside(liquid l){
    if(location.x>l.x && location.x<l.x+l.w && location.y>l.y && location.y<l.y+l.h)return true;
    else return false;
    
}


void mover::drag(liquid l){
    
    float speed = velocity.length();
    float dragMagnitude = l.c * speed * speed;
    
    ofVec2f drag;
    drag.set(velocity);
    drag *= -1;
    drag.normalize();
    
    
    drag *= dragMagnitude;
    applyForce(drag);
}
