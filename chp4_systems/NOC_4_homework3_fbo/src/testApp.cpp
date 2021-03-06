#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
	ofEnableSmoothing();
    ofBackground(0);
    
    ofSetBackgroundAuto(false);
   
    ofVec2f origin(ofRandom(100, ofGetWidth()-100), ofRandom(50, ofGetHeight()-200));
 
    ParticleSystem *p = new ParticleSystem(origin);
    ps.push_back(p);
    
    fire.setup(ofGetWidth(), ofGetHeight());
}



//--------------------------------------------------------------
void testApp::update(){
    
    if (ofGetElapsedTimeMillis()%1000 > 100 && ofGetElapsedTimeMillis()%1000 < 150) {
        ofVec2f origin(ofRandom(100, ofGetWidth()-100), ofRandom(50, ofGetHeight()-200));
        
        ParticleSystem *p = new ParticleSystem(origin);
        ps.push_back(p);
    }
    
      
    ofEnableAlphaBlending();
    ofSetColor(0,90);
    ofFill();
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    
    ofVec2f gravity(0, 0.05);
        
    for(int i = 0; i < ps.size(); i++){
        
        ps[i]->applyForce(gravity);
   
        
                
        if(ps[i]->eraseSystem()){
            
            ps.erase(ps.begin());            
        }
        
                  
  
        
    }
    
    cout << ps.size() << endl;

    
    

}

//--------------------------------------------------------------
void testApp::draw(){
   
//    for(int i = 0; i < ps.size(); i++){
//
//    ps[i]->run();
//	
//    }
    
    fire.renderToFbo(1.005, ps);
    fire.getFbo().draw(0,0);

    
    
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
    
    ofVec2f mouse(x,y);
    
    ParticleSystem * m = new ParticleSystem(mouse);
 
    ps.push_back(m);

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