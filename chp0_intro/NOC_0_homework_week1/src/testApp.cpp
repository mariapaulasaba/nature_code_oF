// The Nature of Code
// Daniel Shiffman
//
// C++ / openFrameworks
// chapter 0 exercise gaussian distribution
// version by Maria Paula Saba
// based on http://quentinmckay.wordpress.com/2010/06/01/simple-gaussian-openframeworks/
//

#include "testApp.h"

double drand()   /* uniform distribution, [0..1] */
{
   // return (rand()+1.0)/(RAND_MAX+1.0);
    return ofRandom(1);

}


double random_normal()  /* normal distribution, centered on 0, std dev 1 */
{
    return sqrt(-2*log(drand())) * cos(2*M_PI*drand());
}



void testApp::setup(){
	ofSetWindowShape(200, 200);
	ofBackground(0, 0, 0);
	ofSetBackgroundAuto(false);
	ofEnableSmoothing();
    
    ofSetVerticalSync(true);
    ofSetFrameRate(10);

}

void testApp::draw(){
	ofEnableAlphaBlending();
	ofFill();
	ofSetColor(0, 0, 0, 10);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	ofDisableAlphaBlending();
	
	float xloc = (float)random_normal();
	float stdDev = 10;
	float mean = ofGetWidth()/2;
	xloc = (xloc * stdDev) + mean;
	
	ofSetColor(255, 255, 255);
	ofEllipse(xloc, ofGetHeight()/2, 8, 8);
	ofNoFill();
	ofEllipse(xloc, ofGetHeight()/2, 8, 8);
    
    
    float xloc2 = ofRandom(ofGetWidth());
    ofSetColor(255, 0, 0);
    ofEllipse(xloc2, ofGetHeight()-50, 8, 8);
}