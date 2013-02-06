// Daniel Shiffman
// The Nature of Code
// http://www.shiffman.net/

// A random walker object!

class Walker {
  float x, y;
  float tx, ty;


  Walker() {
    tx = 0;
    ty = 10000;
    x = map(noise(tx), 0, 1, 0, width);
    y = map(noise(ty), 0, 1, 0, height);
  }


  // Randomly move according to floating point values
  void step() {

    x = map(noise(tx), 0, 1, 0, width);
    y = map(noise(ty), 0, 1, 0, height);

    tx += 0.01;
    ty += 0.01;

  }
  
  float valueX(){
   return x;
  }
  
  float valueY(){
  return y;
  }
}

