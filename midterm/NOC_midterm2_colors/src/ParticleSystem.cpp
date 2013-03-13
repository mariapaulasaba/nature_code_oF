//
//  ParticleSystem.cpp
//  NOC_4_3_particleSystem
//
//  Created by Maria Paula Saba dos Reis on 2/20/13.
//
//

#include "ParticleSystem.h"


ParticleSystem::ParticleSystem(){
    
}



void ParticleSystem::update(){
    for(int i = 0; i < movers.size(); i++){
        
        movers[i].update();
        movers[i].airResistance();
        movers[i].checkEdges();
        
        if(movers[i].isBack) movers[i].goBack();
}
}

void ParticleSystem::draw(){

    for(int i = 0; i < movers.size(); i++){

    movers[i].draw();
    }

}

void ParticleSystem::addMover(const ofVec2f & initPosition, ofColor cor){
   
    Mover m = *new Mover(initPosition, cor);
 
    movers.push_back(m);
    
}


void ParticleSystem::launch(int j){

    for(int i = 0; i < movers.size(); i++){
        movers[i].isBack = !movers[i].isBack;
        
        if(!movers[i].isBack){
            
            ofVec2f force = ofVec2f(ofRandom(-2,2), ofRandom(-2,2));
            force*= j;
            
            movers[i].applyForce(force);
        }
        

}
}
