//
//  Spring.cpp
//  NOC_3_11_Spring
//
//  Created by Maria Paula Saba dos Reis on 2/18/13.
//
//

#include "Spring.h"


void Spring::setup(float x, float y, int l){
    anchor.set(x,y);
    len = l;
    k = 0.02;

}




ofVec2f Spring::connect(Bob b){
    
    ofVec2f springForce;
    springForce = b.location - anchor;
    
    float d = springForce.length();
    float stretch = d - len;
    
    springForce.normalize();
    springForce = springForce * -1 * k * stretch;
    
    
    return springForce;
}






void Spring::display(Bob b){
    
    ofSetColor(0);
    ofSetLineWidth(5);
    ofNoFill();
    ofLine(b.location.x, b.location.y, anchor.x, anchor.y);
    ofSetLineWidth(1);

   
}
