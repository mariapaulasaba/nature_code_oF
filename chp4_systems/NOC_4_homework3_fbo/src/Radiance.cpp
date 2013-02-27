

#include "Radiance.h"
#include "testApp.h"

Radiance::Radiance(){
    ping = NULL;
    pong = NULL;
}

Radiance::~Radiance(){
    cleanup();
}

void Radiance::setup(int width, int height){
    cleanup();
    ping = new ofFbo();
	pong = new ofFbo();
	ping->allocate(ofGetWidth(), ofGetHeight(), GL_RGB16F);
	pong->allocate(ofGetWidth(), ofGetHeight(), GL_RGB16F);
    clearedFbo = false;
    //----extras
}

void Radiance::cleanup(){
    if(ping!=NULL) {
		delete ping;
		ping = NULL;
	}
	
	if(pong!=NULL) {
		delete pong;
		pong = NULL;
	}
}

void Radiance::step(){
}

ofFbo &Radiance::getFbo(){
    return *pong;
}

void Radiance::renderToFbo(float scale, vector<ParticleSystem*> ps){
    
    if(!clearedFbo) {
		pong->begin();
		ofClear(0, 0, 0, 0);
		pong->end();
		clearedFbo = true;
	}
	ping->begin();
	{
        
        ofEnableBlendMode(OF_BLENDMODE_ADD);
		ofClear(0, 0, 0, 0);
		glColor4f(255, 255, 255, .89);
		
		glPushMatrix();
		glTranslatef(ofGetWidth()/2, ofGetHeight()/2, 1);
		float s = scale;
		
		glScalef(s, s, 1);
		pong->setAnchorPercent(0.5, 0.5);
		
		pong->draw(0, 0);
		glPopMatrix();
        
		glColor4f(255, 255, 255, 0.05);
        
        for(int i = 0; i < ps.size(); i++){
            
            ps[i]->run();
            
        }

        ofEnableBlendMode(OF_BLENDMODE_ADD);
        
    }
    ping->end();
    
    pong->setAnchorPercent(0, 0);
    //ofSetHexColor(0xFF0000);
    
    
    // do the ping-pong
    ofFbo *temp = ping;
    ping = pong;
    pong = temp;
}


