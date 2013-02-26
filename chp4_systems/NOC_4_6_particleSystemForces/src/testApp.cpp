#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
	ofEnableSmoothing();
    ofBackground(255);
    
    ofVec2f origin(ofGetWidth()/2, 50);
 
    
    ps.push_back(ParticleSystem(origin));
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofVec2f gravity(0, 0.05);
    
    for(int i = 0; i < ps.size(); i++){
    ps[i].addParticle();
        
        
    ps[i].applyForce(gravity);

    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
   
    for(int i = 0; i < ps.size(); i++){

    ps[i].run();
	
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
    
    ofVec2f mouse(x,y);
    
    
    ps.push_back(ParticleSystem(mouse));

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