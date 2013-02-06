float x, y;
Random generatorX, generatorY;

float sdX, sdY, meanX, meanY;



void setup() {
  size(800, 800);
  background(0);
  generatorX = new Random();
  generatorY = new Random();

  sdX = 100;
  sdY = 0;
  meanX = width/2;
  meanY = 200;
}


void draw() {
  fill(0,10);
  rect(0,0,width, height);
  stroke(255, 150);
  noFill();

  x = (float) generatorX.nextGaussian();
  x = sdX * x + meanX;
  y = (float) generatorY.nextGaussian();
  y = sdY * y + meanY;


  ellipse(x, y, 50, 50);

  if(frameCount%100 == 0) {
    
    float prob = random(1);
    
    if(prob > 0.9){
    meanY = meanY + random(-50,50);   
    }
    else{
    
    meanY = meanY + random(-300,300);
    }

    if (meanY > height || meanY < 0) meanY = height/2;    
  }
  
  
}


void mousePressed() {

  meanY = mouseY;
}


void keyPressed(){
 
  background(0);
}

