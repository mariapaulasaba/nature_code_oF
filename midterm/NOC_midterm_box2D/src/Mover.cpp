//
//  Mover.cpp
//  NOC_midterm2
//
//  Created by Maria Paula Saba dos Reis on 3/6/13.
//
//

#include "Mover.h"


void Mover::setupTheCustomData(const ofVec2f & position, ofColor c){

    setData(new Data());
    Data * theData = (Data*)getData();
    
    theData->initPosition = position;
    theData->cor = c;

}


void Mover::draw() {
    Data* theData = (Data*)getData();
    if(theData) {
        float radius = getRadius();
        ofPushMatrix();
        ofTranslate(getPosition());
        ofRotateZ(getRotation());
        ofSetColor(theData->cor);
        ofFill();
        ofCircle(0, 0, radius);
        
        ofPopMatrix();
    }
}


void Mover::goBack(){
    Data* theData = (Data*)getData();
    if(theData) {
        
  
        //addAttractionPoint(theData->initPosition.x, theData->initPosition.y, 0.2);
        
        float radius = getRadius();
        ofPushMatrix();
        ofTranslate(getPosition());
        ofRotateZ(getRotation());
        ofSetColor(theData->cor);
        ofFill();
        ofCircle(0, 0, radius);
        
        ofPopMatrix();
    }


}

