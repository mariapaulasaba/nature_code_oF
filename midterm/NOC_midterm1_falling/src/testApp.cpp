#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
   // image.loadImage("desenho-de-cachorro.png");
   // image.loadImage("images.jpg");

    image.loadImage("leaves.jpg");
    
    ofSetWindowShape(image.width, image.height);
    
    ofBackground(0);
    

  
    
    for(int y = 0; y < image.getHeight(); y++){
        for(int x = 0; x < image.getWidth(); x++){
            
            ofVec2f pixelPosition;
            
            pixelPosition.x = ofMap(x, 0, image.getWidth(), 0, ofGetWidth());
            pixelPosition.y = ofMap(y, 0, image.getHeight(), 0, ofGetHeight());
            
            ofColor c = image.getPixelsRef().getColor(x, y);
            
            int b = c.getBrightness();
            
            if(b > 150){
        
                Mover m = *new Mover(pixelPosition, b);
                movers.push_back(m);
            }
            
        }
    }
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    ofVec2f gravity(0, 0.2);
    
    for(int i = 0; i < movers.size(); i++){
        
        if(!movers[i].isBack) movers[i].applyForce(gravity);

        movers[i].update();
        movers[i].airResistance();
        movers[i].checkEdges();
        
        if(movers[i].isBack) movers[i].goBack();
        
        
        
    
    }
  

}

//--------------------------------------------------------------
void testApp::draw(){
   
    
    for(int i = 0; i < movers.size(); i++){
        
        movers[i].draw();

        
    }
    
    


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    for(int i = 0; i < movers.size(); i++){
        for(int j = 0; j < movers.size(); j++){
            if(j != i){
                //ofVec2f repelForce = movers[j].repel(movers[i]);
              //  movers[i].applyForce(repelForce);
                
            }
            
        }
  
    }
    
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