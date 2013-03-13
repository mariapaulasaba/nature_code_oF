#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
   // image.loadImage("desenho-de-cachorro.png");
   // image.loadImage("images.jpg");
    image.loadImage("leaves.jpg");
   //image.loadImage("champ03.jpg");
    
    
    //ofSetWindowShape(image.width, image.height);
    
    ofBackground(0);
    

  
    
    for(int y = 0; y < image.getHeight(); y++){
        for(int x = 0; x < image.getWidth(); x++){
            
            ofVec2f pixelPosition;
            
            pixelPosition.x = ofMap(x, 0, image.getWidth(), 0, ofGetWidth());
            pixelPosition.y = ofMap(y, 0, image.getHeight(), 0, ofGetHeight());
            
            ofColor c = image.getPixelsRef().getColor(x, y);
            
            int b = c.getBrightness();
            
            //if(c.r > 200 && c.b < 100 && c.g < 100){
            if(b > 150){
                Mover m = *new Mover(pixelPosition, c);
                movers.push_back(m);
            }
            
        }
    }
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    
    
    for(int i = 0; i < movers.size(); i++){
       // if(movers[i].color.r > 200 && movers[i].color.b < 100 && movers[i].color.g < 100){

        movers[i].update();
        movers[i].airResistance();
        movers[i].checkEdges();
        
        if(movers[i].isBack) movers[i].goBack();
       // }
    }
  

}

//--------------------------------------------------------------
void testApp::draw(){
    //ofSetColor(255);
    //image.draw(0,0, ofGetWidth(), ofGetHeight());

    
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
        ofVec2f force = ofVec2f(ofRandom(-2,2), ofRandom(-2,2));
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