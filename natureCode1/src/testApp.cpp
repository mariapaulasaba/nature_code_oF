#include "testApp.h"
#include "mover.h"

mover Bola;


//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowShape(640,360);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofBackground(255);
    Bola.setup();
    
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::update(){
    Bola.update();
    Bola.checkEdges();
    ofVec2f mouse(ofGetMouseX(),ofGetMouseY());
    Bola.setTarget(mouse);
}

//--------------------------------------------------------------
void testApp::draw(){
    Bola.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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