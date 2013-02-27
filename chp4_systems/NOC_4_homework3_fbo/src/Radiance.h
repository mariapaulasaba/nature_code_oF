#ifndef __floaters__radiance__
#define __floaters__radiance__

#include "ofMain.h"
#include "Particle.h"
#include "ParticleSystem.h"


class Radiance{
public:
    
    Radiance();
    ~Radiance();
    void setup(int width, int height);
    void renderToFbo(float scale, vector<ParticleSystem*> ps);
    void step();
    ofFbo &getFbo();
    
private:
    
    ofFbo *ping;
    ofFbo *pong;
    void cleanup();
    
    
    bool clearedFbo;
    
    
};


#endif /* defined(__floaters__radiance__) */
