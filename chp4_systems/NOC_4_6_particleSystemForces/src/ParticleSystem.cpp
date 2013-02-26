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
        
        particles[i].run();
        
        if(particles[i].isDead()){
            
            particles.erase(particles.begin() + i);
            
        }
        
    }
}


void ParticleSystem::addParticle(){
  
    particles.push_back(Particle(origin));

}


void ParticleSystem::applyForce(const ofVec2f &force){
    
    for(int i = 0; i < particles.size(); i++){
        particles[i].applyForce(force);
    }

}
