//
//  liquid.cpp
//  NOC_2_5_fluid_resistance
//
//  Created by Maria Paula Saba dos Reis on 2/6/13.
//
//

#include "liquid.h"


void liquid::setup(float x_, float y_, float w_, float h_){
    x = x_;
    y = y_;
    w = w_;
    h = h_;
    
    c = 0.1;
    
}

void liquid::draw(){
    ofSetColor(100);
    ofFill();
    ofRect(x, y, w, h);
    
    
}