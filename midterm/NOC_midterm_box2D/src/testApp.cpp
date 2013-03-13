#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    ofSetLogLevel(OF_LOG_NOTICE);
	ofSetVerticalSync(true);
	
	// Box2d
	box2d.init();
	box2d.setGravity(0, 20);
	box2d.createGround();
	box2d.setFPS(30.0);
    
    image.loadImage("leaves.jpg");
    ofSetWindowShape(image.width, image.height);
    

    for(int y = 0; y < image.getHeight(); y+=4){
        for(int x = 0; x < image.getWidth(); x+=4){
            
            ofVec2f pixelPosition;
            
            pixelPosition.x = ofMap(x, 0, image.getWidth(), 0, ofGetWidth());
            pixelPosition.y = ofMap(y, 0, image.getHeight(), 0, ofGetHeight());
            
            ofColor c = image.getPixelsRef().getColor(x, y);
            
            int b = c.getBrightness();
            
            if(b > 220){
                
                Mover m = *new Mover();
                m.setPhysics(3.0, 0.53, 0.9);
                m.setup(box2d.getWorld(), pixelPosition.x, pixelPosition.y, 3);
                m.setupTheCustomData(pixelPosition, c);
                movers.push_back(m);
            }
            
        }
	

        isGravityOn = true;
}
}

//--------------------------------------------------------------
void testApp::update(){
	box2d.update();
    
    
	for(int i=0; i<movers.size(); i++) {
    
        if(isGravityOn){
          	box2d.setGravity(0, 10);
            movers[i].setPhysics(3.0, 0.53, 0.1);
    }
        else{
			box2d.setGravity(0, 0);
            movers[i].setPhysics(3.0, 0.53, 0.1);

         }

		
	}

}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<movers.size(); i++) {
        if(isGravityOn){
           movers[i].draw();

        }
        else{
           movers[i].goBack();

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
    isGravityOn = !isGravityOn;
    
 
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