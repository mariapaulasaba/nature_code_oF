// The Nature of Code
// Daniel Shiffman
//
// C++ / openFrameworks
// chapter 2 exercise 2
// version by Maria Paula Saba
// based on Emmanuel Geoffray

#include "testApp.h"
#include "mover.h"

// Example 2: wind + gravity

vector<mover> movers;

//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowShape(640, 360);
    ofEnableSmoothing();
    ofBackground(255);
    movers.resize(5);
    for (unsigned int i = 0; i < movers.size(); i++){
        movers[i].setup();
        movers[i].setMass(ofRandom(0.1, 4));
        movers[i].setLocation(0, 0);
    }
    
    ofSetVerticalSync(true);
    
}

//--------------------------------------------------------------
void testApp::update(){
    ofVec2f wind(ofRandom(0, 0.1), 0);
    ofVec2f gravity(0, 0.1);
    for (unsigned int i = 0; i < movers.size(); i++){
        movers[i].applyForce(wind);
        movers[i].applyForce(gravity);
        movers[i].update();
        movers[i].checkEdges();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for (unsigned int i = 0; i < movers.size(); i++){
        movers[i].draw();
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
