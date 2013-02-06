#include "testApp.h"


int w = 500;
int h = 500;
ofImage img;
float color;

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(50);
    ofBackground(0);
    img.allocate(w,h,OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int y=0; y< h; y++) {
        for (int x=0; x< w; x++) {
            
            float a = x * 0.01;
            float b = y * 0.01;
            float c = ofGetFrameNum() / 50.0;
            
            float noise = ofNoise(a, b, c) * 255;

            
            if(noise>200){
                color = ofMap(noise, 200, 255, 0 ,255);
            }
            else{
                color = 0;
            }
            
            int px = y*w+x;
            
        
            img.getPixels()[px] = color;
             
            
        
        

        }
    }
    
    img.reloadTexture();
}

//--------------------------------------------------------------
void testApp::draw(){
    img.draw(0,0, ofGetWidth(), ofGetHeight());
}