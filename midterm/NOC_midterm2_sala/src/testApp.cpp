#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    jpg.loadImage("sala.jpg");
    mira.loadImage("mira.png");
    objetos.resize(12);
    
 
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    ofHideCursor();
    
    
    objetos[1].setup("cats.png", 495, 307, 45, 32);
    objetos[9].setup("almofada.png", 345, 314, 100, 70);
    objetos[2].setup("bandeja.png", 80, 300, 150, 45);
    objetos[4].setup("copo.png", 397, 364, 26, 40);
    objetos[10].setup("almofada2.png", 825, 363, 150, 210);
    objetos[5].setup("livros.png", 210, 280, 70, 30);
    objetos[6].setup("livros2.png", 390, 495, 60, 55 );
    objetos[7].setup("macbook.png", 408, 415, 100, 30);
    objetos[11].setup("quadro.png", 615, 157, 130, 190);
    objetos[8].setup("planta.png", 426, 283, 65, 90);
    objetos[0].setup("shoes.png", 590, 493, 110, 50);
    objetos[3].setup("thor.png", 130, 473, 50, 50);

}

//--------------------------------------------------------------
void testApp::update(){
    
    
    
    for(unsigned int i = 0; i < objetos.size(); i++){
        objetos[i].update();
 
        objetos[i].goBack(mouseX, mouseY);
        
    }
  

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    jpg.draw(0,0, ofGetWidth(), ofGetHeight());

    
    for(unsigned int i = 0; i < objetos.size(); i++){
        
        objetos[i].draw();
        
    }
   
    
    for(unsigned int i = 0; i < objetos.size(); i++){
        
        objetos[i].drawExplosion();
        
    }
    
    
    ofSetColor(255);
    mira.draw(mouseX-10, mouseY-10);

    for(unsigned int i = 0; i < objetos.size(); i++){
        
        objetos[i].drawTarget(mouseX-10, mouseY-10);
        
        
        
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

    
    for(unsigned int i = 0; i < objetos.size(); i++){
        
        objetos[i].explode(mouseX, mouseY);

        
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