#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
    ofEnableSmoothing();
    

}

//--------------------------------------------------------------
void testApp::update(){
     x = r * cos(theta);
     y = r * sin(theta);
    
    theta += 0.01;
    r += 0.09;
    
    angle += 0.1;

}

//--------------------------------------------------------------
void testApp::draw(){
    
   ofSetCircleResolution(50);
    ofSetColor(0);
    ofFill();

    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    
    ofRotate(angle);
     ofCircle(x, y, 16, 16);
   
    
  


    

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