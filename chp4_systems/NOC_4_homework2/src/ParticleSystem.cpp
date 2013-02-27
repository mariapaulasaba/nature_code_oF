//
//  ParticleSystem.cpp
//  NOC_4_3_particleSystem
//
//  Created by Maria Paula Saba dos Reis on 2/20/13.
//
//

#include "ParticleSystem.h"


 ParticleSystem::ParticleSystem(ofVec2f location, ofImage img){
     
    origin = location;
     lifeTime = 0;
     numParticles = ofRandom(50,120);
     
     int chooseColor = ofRandom(5);
     
     if(chooseColor < 1) cor = ofColor(255, 0, 0);
     else if (chooseColor < 2) cor  = ofColor(255, 0, 100);
     else if (chooseColor < 3) cor  = ofColor(0, 100, 255);
     else if (chooseColor < 4) cor  = ofColor(0, 255, 100);
     else  cor  = ofColor(255, 100, 0);
     
     image = img;
     
     for(int i = 0; i < numParticles; i ++){
     
         Particle * p = new Particle(origin, cor, image);
         particles.push_back(p);
     
     }
     
     
     
  //   fire.setup(200, 200);

}



void ParticleSystem::run(){
    for(int i = particles.size()-1; i >= 0; i--){
       
       
        ofEnableBlendMode(OF_BLENDMODE_ADD);
                
        particles[i]->run();
 
     //   fire.renderToFbo(1.005, particles[i]);
     //   fire.getFbo().draw(particles[i]->location.x-100,particles[i]->location.y-100);
        
        
        if(particles[i]->isDead()){
            
            particles.erase(particles.begin() + i);
            lifeTime++;
            
        }
        
        
        
    }
    


}


void ParticleSystem::addParticle(){
  

}


Boolean ParticleSystem::eraseSystem(){
    if(lifeTime == numParticles)return true;
    else return false;

}

void ParticleSystem::applyForce(const ofVec2f &force){
    
    for(int i = 0; i < particles.size(); i++){
        particles[i]->applyForce(force);
    }

}
