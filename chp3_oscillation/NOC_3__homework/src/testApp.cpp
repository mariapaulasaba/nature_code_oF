#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    ofSetVerticalSync(true);
    
    movers.resize(500);

    for(unsigned int i = 0; i < movers.size(); i++){
        movers[i].setup();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(unsigned int i = 0; i < movers.size(); i++){
    
        
        movers[i].update();
        movers[i].checkEdges();
    }
    
    ofEnableBlendMode(<#ofBlendMode blendMode#>)
    }

//--------------------------------------------------------------
void testApp::draw(){
    for(unsigned int i = 0; i < movers.size(); i++){

        
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
    ofVec2f mouse(x,y);
    
    for(unsigned int i = 0; i < movers.size(); i++){
        movers[i].setTarget(mouse, ofRandom(2));
    }

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    for(unsigned int i = 0; i < movers.size(); i++){
        ofVec2f random(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
        movers[i].setTarget(random, 1);
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