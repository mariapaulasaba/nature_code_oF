#include "testApp.h"

int w = 500;
int h = 500;
ofImage img;

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(50);
    ofBackground(0);
    img.allocate(w,h,OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int y=0; y<h; y++) {
        for (int x=0; x<w; x++) {
            
            float a = x * .01;
            float b = y * .01;
            float c = ofGetFrameNum() / 50.0;
            
            float noise = ofNoise(a,b,c) * 255;
            
            float color = noise>200 ? ofMap(noise,200,255,0,255) : 0;
            
            img.getPixels()[y*w+x] = color;
        }
    }
    
    img.reloadTexture();
}

//--------------------------------------------------------------
void testApp::draw(){
    img.draw(0,0);
}