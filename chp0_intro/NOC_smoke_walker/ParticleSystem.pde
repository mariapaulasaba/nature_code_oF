class ParticleSystem {

  ArrayList<Particle> particles;    // An arraylist for all the particles
  PVector origin;        // An origin point for where particles are birthed
  PImage img;
  
  ParticleSystem(int num, PVector v, PImage img_) {
    particles = new ArrayList<Particle>();              // Initialize the arraylist
    origin = v.get();                        // Store the origin point
    img = img_;
    for (int i = 0; i < num; i++) {
      particles.add(new Particle(origin, img));    // Add "num" amount of particles to the arraylist
    }
  }

  void run() {
    Iterator<Particle> it = particles.iterator();
    while (it.hasNext()) {
      Particle p = it.next();
      p.run();
      if (p.dead()) {
        it.remove();
      }
    }
  }
  
  // Method to add a force vector to all particles currently in the system
  void applyForce(PVector dir) {
    // Enhanced loop!!!
    for (Particle p: particles) {
      p.applyForce(dir);
    }
  }
  
 
  void addParticle(float smokeX, float smokeY) {
    particles.add(new Particle(new PVector(smokeX, smokeY),img));
  }

  void addParticle(Particle p) {
    particles.add(p);
  }

  // A method to test if the particle system still has particles
  boolean dead() {
    if (particles.isEmpty()) {
      return true;
    } else {
      return false;
    }
  }

}






// A simple Particle class, renders the particle as an image

class Particle {
  PVector loc;
  PVector vel;
  PVector acc;
  float lifespan;
  PImage img;

  Particle(PVector l,PImage img_) {
    acc = new PVector(0,0);
    float vx = (float) generator.nextGaussian()*0.3;
    float vy = (float) generator.nextGaussian()*0.3 - 1.0;
    vel = new PVector(vx,vy);
    loc = l.get();
    lifespan = 100.0;
    img = img_;
  }

  void run() {
    update();
    render();
  }
  
  // Method to apply a force vector to the Particle object
  // Note we are ignoring "mass" here
  void applyForce(PVector f) {
    acc.add(f);
  }

  //function to change origin co-ordinates
  void changeOrigin(float xco, float yco) {
    loc = new PVector(xco, yco);
  } 

  

  // Method to update location
  void update() {
    vel.add(acc);
    loc.add(vel);
    acc.mult(0); // clear Acceleration
    lifespan -= 2.5;

  }

  // Method to display
  void render() {
//    loc.x = mouseX;
//    loc.y = mouseY;
    imageMode(CENTER);
    tint(255,lifespan);
    image(img,loc.x,loc.y);
  }

  // Is the particle still useful?
  boolean dead() {
    if (lifespan <= 0.0) {
      return true;
    } else {
      return false;
    }
  }
}
