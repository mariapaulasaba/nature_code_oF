#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    //ofSetFrameRate(25);
	ofEnableSmoothing();
    ofBackground(255);
    
    ofVec2f origin(ofGetWidth()/2, 50);
      
    ps.push_back(ParticleSystem(origin));
}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i = 0; i < ps.size(); i++){
    ps[i].addParticle();
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