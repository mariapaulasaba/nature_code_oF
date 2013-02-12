//
//  mover.cpp
//  NOC_2_5_fluid_resistance
//
//  Created by Maria Paula Saba dos Reis on 2/6/13.
//
//

#include "Mover.h"


void Mover::setup(){
    location.set(0, 0);
    velocity.set(0, 0);
    acceleration.set(0, 0);
    
    mass = 1;
}

void Mover::applyForce(const ofVec2f & force){
    ofVec2f f(force/mass);
    acceleration += f;
}

void Mover::update(){
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;

   

    
    
}


void Mover::draw(){
    ofSetColor(175);
    ofFill();
    ofEllipse(location, mass * 16, mass * 16);
    
    ofSetColor(0);
    ofNoFill();
    ofEllipse(location, mass * 16, mass * 16);
    
}



void Mover::setMass(float m){
    mass = m;
}

void Mover::setLocation( float x, float y){
    location.set(x, y);
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
        velocity.y *= -1;
        location.y = ofGetHeight();
    }else if (location.y < 0){
        velocity.y *= -1;
        location.y = 0;
    }
}



void Mover::resist(){
    
    float speed = velocity.length();
    float dragMagnitude = 0.01 * speed * speed;
    
    ofVec2f resistance;
    resistance.set(velocity);
    resistance *= -1;
    resistance.normalize();
    
    
    resistance*= dragMagnitude;
    applyForce(resistance);
}


void Mover::repel(vector <Mover> m){
    for (unsigned int i = 0; i < m.size(); i++){
  
     ofVec2f repelForce;
     repelForce = m[i].location - location;
     
        
     applyForce(repelForce);
    }
    
}
