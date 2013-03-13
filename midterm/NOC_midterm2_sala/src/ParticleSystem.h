#pragma once
#include "ofMain.h"
#include "Mover.h"

class ParticleSystem{
    
    
private:
    
    ofImage target;
    ofImage png;
    vector<Mover> movers;
    
    
    
public:
    
    void setup(string name, int cx, int cy, int w, int h);
    void update();
    void draw();
    void drawExplosion();
    void drawTarget(int mx, int my);
    void explode(int mx, int my);
    void goBack(int mx, int my);
    
    int centerX, centerY;
    int width, height;
    int timer;
    Boolean timerStart;
    
};