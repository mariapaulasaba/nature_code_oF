//
//  Attractor.cpp
//  NOC_2_6_Attraction
//
//  Created by Maria Paula Saba dos Reis on 2/6/13.
//
//

#include "Attractor.h"
#include "Mover.h"


void Attractor::setup(){
    location.set(ofGetWidth()/2,ofGetHeight()/2);
    mass = 20;
    G = 0.4;
}


void Attractor::draw(){
    ofSetColor(0);
    ofCircle(location.x, location.y, mass/2);
}


ofVec2f Attractor::attract(Mover m){
    ofVec2f force;
    
    force = location - m.location;
    
    
    float distance = force.length();
    distance = ofClamp(distance,5.0,25.0);
    force.normalize();
    
    float strength = (G * mass * m.mass) / (distance * distance);
    
    force *= strength;
    return force;
}



