#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){


    image.loadImage("shapes-01.jpg");
    
   
    
    ofBackground(0);
    
    ps.resize(3);
  
    
    for(int y = 0; y < image.getHeight(); y+=2){
        for(int x = 0; x < image.getWidth(); x+=2){
            
            ofVec2f pixelPosition;
            
            pixelPosition.x = ofMap(x, 0, image.getWidth(), 0, ofGetWidth());
            pixelPosition.y = ofMap(y, 0, image.getHeight(), 0, ofGetHeight());
            
            ofColor c = image.getPixelsRef().getColor(x, y);
            
            int b = c.getBrightness();
            
            if(c.r > 200 && c.b < 10 && c.g < 10){
            
                ps[2].addMover(pixelPosition, c);
            }
           
            if(c.b > 200 && c.r < 10 && c.g < 10){
                
                ps[1].addMover(pixelPosition, c);
            }
            
            if(c.r > 200 && c.b < 10 && c.g > 200){
                
                ps[0].addMover(pixelPosition, c);
            }
        }
            
        
    }
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    
    
    for(int i = 0; i < ps.size(); i++){
      
        ps[i].update();
    
    }
  

}

//--------------------------------------------------------------
void testApp::draw(){
    //ofSetColor(255);
    //image.draw(0,0, ofGetWidth(), ofGetHeight());

    
    for(int i = 0; i < ps.size(); i++){
        
        ps[i].draw();

        
   
    
     
        
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


    for(int i = 0; i < ps.size(); i++){
        
        ps[i].launch(i);
        
        
   
        
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