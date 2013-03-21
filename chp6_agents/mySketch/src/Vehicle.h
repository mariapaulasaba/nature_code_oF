#pragma once

#include "ofMain.h"

class Vehicle {

  public:
    void setup(){
      location.set(30, 30);
      velocity.set(0, 0);
      acceleration.set(0, 0);
      r = 12;
      maxSpeed = 3;
      maxForce = 0.2;
    }

    // Method to update location
    void update(){
      // Update velocity
      velocity += acceleration;
      // Limit speed
      velocity.limit(maxSpeed);
      location += velocity;
      // Reset acceleration to 0 each cycle
      acceleration *= 0;

      history.push_back(location);
      if (history.size() > 100){
        history.pop_front();
      }
    }

    void applyForce(const ofVec2f & force) {
      // We could add mass here if we want A = F / M
      acceleration += force;
    }

    void applyBehaviors(vector<Vehicle> vehicles, const ofVec2f mouse) {
      ofVec2f separateForce = separate(vehicles);
      ofVec2f seekForce = seek(mouse);
      separateForce *= 5;
      seekForce *= 1;
      applyForce(separateForce);
      applyForce(seekForce); 
    }
 
    // Separation
    // Method checks for nearby vehicles and steers away
    ofVec2f separate (vector<Vehicle> vehicles) {
      float desiredseparation = r*2;
      ofVec2f sum;
      int count = 0;

      // For every boid in the system, check if it's too close

      // one step further in stl C++ programming
      // we're using iterators:
      vector<Vehicle>::iterator other;
      for (other = vehicles.begin(); other < vehicles.end(); other++) {
        float d = (location - other->getLocation()).length();
        // If the distance is greater than 0 and less than an arbitrary amount (0 when you are yourself)
        if ((d > 0) && (d < desiredseparation)) {
          // Calculate vector pointing away from neighbor
          ofVec2f diff = location - other->getLocation();
          diff.normalize();
          diff /= d;        // Weight by distance
          sum += diff;
          count++;            // Keep track of how many
        }
      }
      // Average -- divide by how many
      if (count > 0) {
        sum /= count;
        // Our desired vector is the average scaled to maximum speed
        sum.normalize();
        sum *= maxSpeed;
        // Implement Reynolds: Steering = Desired - Velocity
        ofVec2f steer = sum - velocity;
        steer.limit(maxForce);

        return steer;
      }
      return ofVec2f(0, 0);
    }

    // Wraparound
    void borders() {
      if (location.x < -r) location.x = ofGetWidth()+r;
      if (location.y < -r) location.y = ofGetHeight()+r;
      if (location.x > ofGetWidth()+r) location.x = -r;
      if (location.y > ofGetHeight()+r) location.y = -r;
    }

    void boundaries() {
      float d = 25;

      ofVec2f desired;

      if (location.x < d) {
        desired = ofVec2f(maxSpeed, velocity.y);
      } 
      else if (location.x > ofGetWidth() -d) {
        desired = ofVec2f(-maxSpeed, velocity.y);
      } 

      if (location.y < d) {
        desired = ofVec2f(velocity.x, maxSpeed);
      } 
      else if (location.y > ofGetHeight()-d) {
        desired = ofVec2f(velocity.x, -maxSpeed);
      } 

      if (desired != 0) {
        desired.normalize();
        desired *= maxSpeed;
        ofVec2f steer = desired - velocity;
        steer.limit(maxForce);
        applyForce(steer);
      }
    }  

    // A method that calculates a steering force towards a target
    // STEER = DESIRED MINUS VELOCITY
    void arrive(const ofVec2f & target) {
      ofVec2f desired = target - location;  // A vector pointing from the location to the target
      float d = desired.length();
      // Normalize desired and scale with arbitrary damping within 100 pixels
      desired.normalize();
      if (d < 100) {
        float m = ofMap(d, 0, 100, 0, maxSpeed);
        desired *= m;
      } else {
        desired *= maxSpeed;
      }

      // Steering = Desired minus velocity
      ofVec2f steer = desired - velocity;
      steer.limit(maxForce);  // Limit to maximum steering force

      applyForce(steer);
    }

    // A method that calculates a steering force towards a target
    // STEER = DESIRED MINUS VELOCITY
    ofVec2f seek(const ofVec2f & target) {
      ofVec2f desired = target - location;  // A vector pointing from the location to the target

      // Normalize desired and scale to maximum speed
      desired.normalize();
      desired *= maxSpeed;
      // Steering = Desired minus velocity
      ofVec2f steer = desired - velocity;
      steer.limit(maxForce);  // Limit to maximum steering force

      return steer;
    }

    void draw(){
      ofFill();
      ofSetColor(175);
      ofPushMatrix();
      ofTranslate(location.x, location.y);
      ofEllipse(0, 0, r, r);
      ofPopMatrix();
    }

    void setLocation( float x, float y){
      location.set(x, y);
    }

    void setVelocity( float x, float y){
      velocity.set(x, y);
    }

    void setMaxForce( float f){maxForce = f;}
    void setMaxSpeed( float s){maxSpeed = s;}

    const ofVec2f& getLocation() const{
      return location;
    }

    const ofVec2f& getVelocity() const{
      return velocity;
    }

  private:
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float r;
    float maxForce;
    float maxSpeed;

    deque<ofVec2f> history;
    
};
