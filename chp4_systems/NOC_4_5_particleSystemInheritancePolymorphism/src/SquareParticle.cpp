//
//  SquareParticle.cpp
//  NOC_4_5_particleSystemInheritancePoly
//
//  Created by Maria Paula Saba dos Reis on 2/24/13.
//
//

#include "SquareParticle.h"



SquareParticle:: SquareParticle(ofVec2f origin) : Particle::Particle(origin){

}

void SquareParticle::run(){
    
    update();
    display();
    

}


void SquareParticle::display(){

    ofSetColor(lifespan);
	ofFill();
   	ofRect(location.x, location.y, 5, 5);
    
    ofNoFill();
   	ofRect(location.x, location.y, 5, 5);

	

}


void SquareParticle::update(){
    
	velocity += acceleration;
	location += velocity;
	lifespan += 3.0;
	
	
}