// The Nature of Code
// Daniel Shiffman
//
// C++ / openFrameworks
// chapter 1 exercise 1.11
// version by Maria Paula Saba
// based on Emmanuel Geoffray
//

#include "testApp.h"
#include "mover.h"

vector<mover> bolas;


//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowShape(640,360);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofBackground(0);
    
    bolas.resize(1020);
    
    for(unsigned int i = 0; i < bolas.size(); i++){
        bolas[i].setup();
    }
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::update(){
    //  ofVec2f mouse(ofGetMouseX(),ofGetMouseY());
    
    for(unsigned int i = 0; i < bolas.size(); i++){
        bolas[i].update();
        bolas[i].checkEdges();
        // bolas[i].setTarget(mouse, ofRandom(2));
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(unsigned int i = 0; i < bolas.size(); i++){
        bolas[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    ofVec2f mouse(x,y);
    
    for(unsigned int i = 0; i < bolas.size(); i++){
        bolas[i].setTarget(mouse, ofRandom(2));
    }
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
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