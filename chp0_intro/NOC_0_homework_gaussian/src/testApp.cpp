// The Nature of Code
// Daniel Shiffman
//
// C++ / openFrameworks
// chapter 0 exercise gaussian distribution
// version by Maria Paula Saba
// based on http://quentinmckay.wordpress.com/2010/06/01/simple-gaussian-openframeworks/
//

#include "testApp.h"


float xpos;
float ypos;
float size;

float tx, ty;



void testApp::setup(){
	ofBackground(0, 0, 0);
	ofSetBackgroundAuto(false);
	ofEnableSmoothing();
    
    ofSetVerticalSync(true);
    //ofSetFrameRate(10);

    xpos = ofGetWidth()/2;
    ypos = ofGetHeight()/2;
    
    tx = 0;
    ty = 1000;
    
}



void testApp::update(){}
void testApp::draw(){

	ofEnableAlphaBlending();
    
    //background transparent
	ofFill();
	ofSetColor(0, 0, 0, 10);
    ofSetRectMode(OF_RECTMODE_CORNER);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	
    
    //getting the normal distribution
//	if(ofGetFrameNum()%10) {
        size = (float)random_normal();
 //   }
    
    
    float stdDev = 25;
	float mean = ofGetWidth()/2;
	size = (size * stdDev) + mean;
    
    
    //bigger circle
	ofSetColor(255, 255, 255, 50);
    ofSetCircleResolution(600);
	ofEllipse(ofGetWidth()/2, ofGetHeight()/2, size, size);
    ofNoFill();
    ofEllipse(ofGetWidth()/2, ofGetHeight()/2, size, size);
    
    

    
    
    
    //red small circles
    ofSetColor(255, 0, 0);
   
    if(drand() > 0.2){
    float xloc = ofRandom(ofGetWidth()/2, ofGetWidth());
    ofEllipse(xloc, ofGetHeight()-50, 8, 8);
        
        
    float xloc2 = ofRandom(ofGetWidth()/2);
    ofEllipse(xloc2, 50, 8, 8);
    }
    
    else{
        float xloc = ofRandom(ofGetWidth()/2);
        ofEllipse(xloc, ofGetHeight()-50, 8, 8);
        
        float xloc2 = ofRandom(ofGetWidth()/2, ofGetWidth());
        ofEllipse(xloc2, 50, 8, 8);
    }
    
    
    
    
    
    //black guy
    ofFill();
   
 	ofSetColor(255, 255, 255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofRect(ofGetWidth()/2, ofGetHeight()/2, 300, 300);
    
    float n = ofNoise(1);
    
    xpos = ofMap(ofNoise(tx), 0, 1, ofGetWidth()/2-150, ofGetWidth()/2+150, true);
    ypos = ofMap(ofNoise(ty), 0, 1, ofGetHeight()/2-150, ofGetHeight()/2+150, true);

    tx = tx + 0.01;
    ty = ty + 0.01;
    
    ofSetColor(0);
    ofRect(xpos, ypos, 5, 5);
    
    
    //console
    cout << size << endl;
}



double testApp::drand(){  /* uniform distribution, [0..1] */

    // return (rand()+1.0)/(RAND_MAX+1.0);
    return ofRandom(1);
    
}


double testApp::random_normal(){  /* normal distribution, centered on 0, std dev 1 */

    return sqrt(-2*log(drand())) * cos(2*M_PI*drand());
}
