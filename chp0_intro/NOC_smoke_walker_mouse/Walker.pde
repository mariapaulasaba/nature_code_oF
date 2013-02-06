// Daniel Shiffman
// The Nature of Code
// http://www.shiffman.net/

// A random walker object!

class Walker {
  PVector location;


  Walker() {
    location = new PVector( width/2, height/2);
    
  }


  // Randomly move according to floating point values
  void step() {

    float r = random(1);

    if (r < 0.5) {
       PVector mouse= new PVector(mouseX, mouseY);

      PVector velocity = PVector.sub(mouse, location);
      velocity.normalize();
      location.add(velocity);
      
    }

    else{
      location.x += (int) random(-2, 2);
      location.y += (int) random(-2, 2);
    }

    location.x = constrain(location.x, 0, width-1);
    location.y = constrain(location.y, 0, height-1);
  }

  float valueX() {
    return location.x;
  }

  float valueY() {
    return location.y;
  }
}

