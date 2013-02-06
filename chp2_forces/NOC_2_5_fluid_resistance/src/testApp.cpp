// The Nature of Code
// Daniel Shiffman
//
// C++ / openFrameworks
// chapter 2 exercise 4
// version by Maria Paula Saba
//  Example: friction



#include "testApp.h"
#include "mover.h"
#include "liquid.h"



vector<mover> movers;

liquid water;


//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableSmoothing();
    ofBackground(255);
    movers.resize(7);
    
    water.setup(0, 400, ofGetWidth(), ofGetHeight()-400);
    
    
    for (unsigned int i = 0; i < movers.size(); i++){
        
        movers[i].setup();
        movers[i].setMass(ofRandom(1, 4));
        movers[i].setLocation(50+i*150, 0);
    }
    
    ofSetVerticalSync(true);
    
}

//--------------------------------------------------------------
void testApp::update(){
    ofVec2f wind(0.05, 0);
    
    
    for (unsigned int i = 0; i < movers.size(); i++){
        ofVec2f gravity(0, 0.1*movers[i].mass);
        
        float c = 0.01;
        float normal = 1;
        c  *= normal;
        
        ofVec2f friction;
        friction.set(movers[i].velocity);
        friction *= -1;
        friction.normalize();
        friction *= c;
        
        
        movers[i].applyForce(friction);
        //movers[i].applyForce(wind);
        movers[i].applyForce(gravity);
        movers[i].update();
        movers[i].checkEdges();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
 
    
    water.draw();

    
    for (unsigned int i = 0; i < movers.size(); i++){
        movers[i].draw();
        
        if (movers[i].isInside(water)) {
            movers[i].drag(water);
        }
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

        movers[i].begin();
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
