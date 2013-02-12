#include "testApp.h"
#include "Mover.h"
#include "Attractor.h"

vector<Mover> movers;

Attractor a;


//--------------------------------------------------------------
void testApp::setup(){

    ofEnableSmoothing();
    ofBackground(255);
    a.setup();
    movers.resize(100);
    
    
    for (unsigned int i = 0; i < movers.size(); i++){
        
        movers[i].setup();
        movers[i].setMass(ofRandom(0.1, 4));
        movers[i].setLocation(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
    
    ofSetVerticalSync(true);

}

//--------------------------------------------------------------
void testApp::update(){
    for (unsigned int i = 0; i < movers.size(); i++){
        
        //ofVec2f gravity(0, 0.1*movers[i].mass);
        //movers[i].applyForce(gravity);
        
        ofVec2f force(a.attract(movers[i]));
        
        movers[i].applyForce(force);
        movers[i].update();
        movers[i].checkEdges();
        
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    a.draw();
    
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