//
//  ParticleSystem.cpp
//  NOC_4_3_particleSystem
//
//  Created by Maria Paula Saba dos Reis on 2/20/13.
//
//

#include "ParticleSystem.h"


 ParticleSystem::ParticleSystem(ofVec2f location){
    origin = location;

}



void ParticleSystem::run(){
    for(int i = particles.size()-1; i >= 0; i--){
        
        particles[i]->run();
        
        
        if(particles[i]->isDead()){
            
            particles.erase(particles.begin() + i);
            
        }
        
    }
}


void ParticleSystem::addParticle(){
  
    float r = ofRandom(1) ;
    if (r < 0.2) {
        
		Particle * p = new Particle(origin);
		particles.push_back(p);
    }
    else {
        
        SquareParticle * s = new SquareParticle(origin);
        particles.push_back(s);
    }

}