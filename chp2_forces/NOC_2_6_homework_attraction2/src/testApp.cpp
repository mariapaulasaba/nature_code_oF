#include "testApp.h"
#include "Mover.h"
#include "Attractor.h"



//--------------------------------------------------------------
void testApp::setup(){

    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofBackground(0);
    movers.resize(2500);
    attractors.resize(1);
    
    
    for (unsigned int i = 0; i < movers.size(); i++){
        
        movers[i].setup();
        movers[i].setMass(ofRandom(0.1, 0.5));
        movers[i].setLocation(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
  
      for (unsigned int i = 0; i < attractors.size(); i++){
   
                 attractors[i].setup();
            
    }
    
    
    ofSetVerticalSync(true);
    //ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){
    for (unsigned int i = 0; i < movers.size(); i++){
        
        //ofVec2f gravity(0, 0.1*movers[i].mass);
        //movers[i].applyForce(gravity);
    
        
        ofVec2f force(attractors[0].attract(movers[i]));
        movers[i].applyForce(force);
        
        movers[i].update();
        movers[i].checkEdges();
        movers[i].resist();
        
       
        
    }
    
    for (unsigned int i = 0; i < attractors.size(); i++){
        
        attractors[i].setLocation(mouseX, mouseY);
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
   // ofSetColor(0, 0, 0, 4);
   // ofFill();
   // ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    
    
    for (unsigned int i = 0; i < movers.size(); i++){
        movers[i].draw();
    }
    
    for (unsigned int i = 0; i < attractors.size(); i++){
      attractors[i].draw();
        
        
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
    for (unsigned int i = 0; i < movers.size(); i++){
        
               
     //   movers[i].repel(movers);

        
        
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