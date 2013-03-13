//
//  Mover.cpp
//  NOC_midterm1
//
//  Created by Maria Paula Saba dos Reis on 2/28/13.
//
//

#include "Mover.h"


Mover::Mover(const ofVec2f & position, ofColor cor){
    initialLoc = position;
    location = position;
    velocity.set(0, 0);
    acceleration.set(0, 0);
    
    color = cor;
    isBack = false;
    mass = 1;
    maxForce = 0.1;
    maxSpeed = 4;
}

void Mover::applyForce(const ofVec2f & force){
    ofVec2f f(force/mass);
    acceleration += f;
}



void Mover::goBack( ){
    
    
    ofVec2f forceBack =  initialLoc - location;
    float l = forceBack.length();
    forceBack.normalize();
    
    if(l < 100) {
        float m = ofMap(l, 0, 100, 0, maxSpeed);
        forceBack *= m;
    }
    else{
        forceBack*= maxSpeed;
    }
    
    ofVec2f steer = forceBack - velocity;
    steer.limit(maxForce);
    applyForce(steer);
    

    
}


void Mover::update(){
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;

}

void Mover::draw(){
    ofSetColor(color);
    ofFill();
    ofCircle(location, mass);
    
    ofSetColor(color);
    ofNoFill();
    ofCircle(location, mass);
    
}




void Mover::checkEdges(){
    
    if (location.x > ofGetWidth()){
        velocity.x *= -1;
        location.x = ofGetWidth();
    } else if (location.x < 0){
        velocity.x *= -1;
        location.x = 0;
    }
    
    if (location.y > ofGetHeight()){
        velocity.y = 0;
        location.y = ofClamp(location.y, 0, ofGetHeight());

    }
}


void Mover::airResistance(){
    
    float speed = velocity.length();
    float dragMagnitude = 0.005 * speed * speed;
    
    ofVec2f drag;
    drag.set(velocity);
    drag *= -1;
    drag.normalize();
    
    
    drag *= dragMagnitude;
    applyForce(drag);

}


ofVec2f Mover::repel(Mover m){
    ofVec2f repelForce = location - m.location;
    
    float d = repelForce.length();
    repelForce.normalize();
    
    float strenght = (0.1 * mass * m.mass)/ d*d;
    
    repelForce*= strenght;
    return repelForce;
    
    
}
