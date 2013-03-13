#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    jpg.loadImage("Cabaret_by_robwooly.jpg");
    png.loadImage("Cabaret_by_robwooly2.png");
 //   jpg.loadImage("sorriso.jpg");
  //  png.loadImage("sorriso.png");
 
    ofBackground(0);
    

    ofEnableAlphaBlending();
    
  
    
    for(int y = 0; y < png.getHeight(); y++){
        for(int x = 0; x < png.getWidth(); x+=2){
            
            
            ofVec2f pixelPosition;
            
            pixelPosition.x = ofMap(x, 0, jpg.getWidth(), 0, ofGetWidth());
            pixelPosition.y = ofMap(y, 0, jpg.getHeight(), 0, ofGetHeight());
            
            ofColor c = png.getPixelsRef().getColor(x, y);
           // ofColor cor = ofColor(c.r, c.g, c.b, 100);
            int b = c.getBrightness();
 
            if(b < 230){
                Mover m = *new Mover(pixelPosition, c);
            movers.push_back(m);
            }
            
        }
    }
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    
    
    for(int i = 0; i < movers.size(); i++){

        movers[i].update();
        movers[i].airResistance();
        movers[i].checkEdges();
        
        if(movers[i].isBack) movers[i].goBack();
    }
  

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    jpg.draw(0,0);

    
    for(int i = 0; i < movers.size(); i++){
        
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

    for(int i = 0; i < movers.size(); i++){
        movers[i].isBack = !movers[i].isBack;

        if(!movers[i].isBack){
        ofVec2f force = ofVec2f(ofRandom(-100,100), ofRandom(-100,100));
        movers[i].applyForce(force);
        }
        

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