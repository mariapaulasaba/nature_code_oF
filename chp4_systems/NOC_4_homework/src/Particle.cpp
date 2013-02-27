//
//  Particle.cpp
//  NOC_4_3_particleSystem
//
//  Created by Maria Paula Saba dos Reis on 2/20/13.
//
//

#include "Particle.h"


 Particle::Particle(const ofVec2f o, ofColor c){
    
	acceleration = ofVec2f(0, 0);
	velocity.set(ofRandom(-5,5), ofRandom(-5,5));
	location = o;
	lifespan = 255.0;
	
     mass = 1;
     size = ofRandom(2,5);
     
     cor = c;
}

void Particle::run(){
    
    update();
    display();
    
}

void Particle::applyForce(const ofVec2f &force){
    ofVec2f f(force/mass);
    acceleration += f;


}

void Particle::update(){
    
	velocity += acceleration;
	location += velocity;
	lifespan -= 2.0;
    
    velocity *= 0.99;
    
    acceleration *= 0;
    
    ofPoint temp;
	temp.x = location.x;
	temp.y = location.y;
	points.push_back(temp);
	
    if (points.size() > 20){
		points.erase(points.begin());
	}
	
}


void Particle::display(){
    
	
	ofSetColor(cor, lifespan);
    
    
	ofFill();
    ofSetCircleResolution(100);
   	ofCircle(location.x, location.y, size);
    
    
    ofNoFill();
	ofCircle(location.x, location.y, size);
    
    
  
    
    
    
    ofBeginShape();
	for (int i = 0; i < points.size(); i++){
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape(); 
	
	
}


Boolean Particle::isDead(){
    
	if(lifespan < 0.0) return true;
	else return false;
	
}
