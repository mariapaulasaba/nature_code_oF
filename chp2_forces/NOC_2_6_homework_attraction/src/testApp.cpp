#include "testApp.h"
#include "Mover.h"
#include "Attractor.h"




//--------------------------------------------------------------
void testApp::setup(){

    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofBackground(0);
    movers.resize(500);
    attractors.resize(5);
    
    
    for (unsigned int i = 0; i < movers.size(); i++){
        
        movers[i].setup();
        movers[i].setMass(0.5);
        movers[i].setLocation(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
    
    for (unsigned int i = 0; i < attractors.size(); i++){
        
        attractors[i].setup(200*i);
    }
    
    ofSetVerticalSync(true);
// ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){
    for (unsigned int i = 0; i < movers.size(); i++){
        
        //ofVec2f gravity(0, 0.1*movers[i].mass);
        //movers[i].applyForce(gravity);
        
        unsigned int a;
        int prob = ofRandom(5);
        
        if(movers[i].location.x < ofGetWidth()/3) a = 0;
        else if(movers[i].location.x > ofGetWidth()/3 && movers[i].location.x < 2*ofGetWidth()/3) a = 2;
        else a = 4;
        
     //   a = (int) prob;
        
        
            
        ofVec2f force(attractors[a].attract(movers[i]));
           
            
        movers[i].applyForce(force);
        movers[i].update();
        movers[i].checkEdges();
        
        
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(0, 0, 0, 4);
    ofFill();
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    
    
    for (unsigned int i = 0; i < movers.size(); i++){
        movers[i].draw();
    }
    
    for (unsigned int i = 0; i < attractors.size(); i++){
     //   attractors[i].draw();
        
        
    }
    

    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    for (unsigned int i = 0; i < movers.size(); i++){
        movers[i].velocity.set(0,0);
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}