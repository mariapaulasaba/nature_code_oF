//
//  ParticleSystem.cpp
//  NOC_midterm1
//
//  Created by Maria Paula Saba on 3/11/13.
//
//

#include "ParticleSystem.h"


void ParticleSystem::setup(string name, int cx, int cy, int w, int h){
    target.loadImage("mira2.png");
    png.loadImage(name);

    centerX = cx;
    centerY = cy;
    width = w;
    height = h;
    
    for(unsigned int y = 0; y < 600; y++){
        for(unsigned int x = 0; x < 900; x++){
            
            
            ofVec2f pixelPosition;
            
            pixelPosition.x = ofMap(x, 0, 900, 0, ofGetWidth());
            pixelPosition.y = ofMap(y, 0, 600, 0, ofGetHeight());
            
            ofColor c = png.getPixelsRef().getColor(x, y);
            int b = c.getBrightness();
            
            if(b < 230){
                Mover m = *new Mover(pixelPosition, c);
                movers.push_back(m);
            }
            
        }
    }
    
    timer = 0;
    timerStart = false;
}


void ParticleSystem::update(){
   
   

    for(unsigned int i = 0; i < movers.size(); i++){
        
        movers[i].update();
        movers[i].airResistance();
        //movers[i].checkEdges();
        
        if(movers[i].isBack) movers[i].goBack();
        
    
        
    }
    

    
    if(timerStart) timer++;
    else timer = 0;
}


void ParticleSystem::draw(){  

    for(unsigned int i = 0; i < movers.size(); i++){
        if(movers[i].location == movers[i].initialLoc) movers[i].draw();
    }
    
}


void ParticleSystem::drawExplosion(){

    
    for(unsigned int i = 0; i < movers.size(); i++){
        
        float dist = ofDist(movers[i].location.x, movers[i].location.y, movers[i].initialLoc.x, movers[i].initialLoc.y);
        
        if(movers[i].location != movers[i].initialLoc && dist < 20*movers[i].velocity.length()){
            
            movers[i].draw();
        
        }
    
    }

}



void ParticleSystem::drawTarget(int mx, int my){
    
    
    if(mx > centerX-width/2 && mx < centerX+width/2 && my > centerY-height/2 && my < centerY+height/2){
        
        target.draw(mx, my);
    }
    
}



void ParticleSystem::explode(int mx, int my){

    if(mx > centerX-width/2 && mx < centerX+width/2 && my > centerY-height/2 && my < centerY+height/2){
    

        
        for(unsigned int i = 0; i < movers.size(); i++){
        movers[i].isBack = !movers[i].isBack;
        
        if(!movers[i].isBack){
            ofVec2f force = ofVec2f(ofRandom(-100,100), ofRandom(-100,100));
            movers[i].applyForce(force);
            timerStart = true;
        }
        
        
    }
    }
}
    
void ParticleSystem::goBack(int mx, int my){
    
   // if(mx < centerX-width/2 || (mx > centerX+width/2 || my < centerY-height/2 || my > centerY+height/2)){
    if(timer > 200){
        for(unsigned int i = 0; i < movers.size(); i++){
            
            movers[i].isBack = true;
            
            timerStart = false;
        }}
  //  }
}
