
ParticleSystem ps;
Random generator;
Walker w;



void setup(){
  size(800,400);
  frameRate(20);
  w = new Walker();


  
  //smoke generator
  generator = new Random();
  PImage img = loadImage("texture.png");
  ps = new ParticleSystem(0,new PVector(width/2+5,height/2-28),img); 
}


void draw(){
  background(0);
  
  noStroke();

  w.step();




    
   // Calculate a "wind" force based on mouse horizontal position
  float dx = map(mouseX,0,width,0.2,-0.2);
  PVector wind = new PVector(dx,0);
  ps.applyForce(wind);
  ps.run();
  for (int i = 0; i < 2; i++) {
    ps.addParticle(w.valueX(), w.valueY());
  }   
     
  

}


