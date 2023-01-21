class Spaceship {

  constructor(){
    this.velocity = new createVector(0, 0);
    this.location = new createVector(width/2, height/2);
    this.acceleration = new createVector(0, 0);
    this.maxVelocity = 5;
    this.bulletSys = new BulletSystem();
    this.size = 50;
  }

  run(){
    this.bulletSys.run();
    this.draw();
    this.move();
    this.edges();
    this.interaction();
  }

  draw(){
    fill(125);
    triangle(this.location.x - this.size/2, this.location.y + this.size/2,
        this.location.x + this.size/2, this.location.y + this.size/2,
        this.location.x, this.location.y - this.size/2);
    fill(255,0,0);
    if (keyIsDown(UP_ARROW)){
      rect(this.location.x - this.size/10, this.location.y + this.size/2, 10,20);
    }
    if (keyIsDown(DOWN_ARROW)){
      rect(this.location.x - this.size/10, this.location.y - this.size/2-20, 10,20);
    }
  }


 /*  Step 3: In spaceship.js update the move() function similarly to how the move() function works in asteroidSystem. 
 Make sure you limit the velocity vector to maxVelocity so that the spaceship does not accelerate too much. Notice how, unless we fire the rockets 
 in the opposite direction, the spaceship will keep moving. There is no friction in empty space.
 In Asteroid.js
  //moves all asteroids
  move(){
    for (var i=0; i<this.locations.length; i++){
      this.velocities[i].add(this.accelerations[i]);
      this.locations[i].add(this.velocities[i]);
      this.accelerations[i].mult(0);
    }
  }

 */ 
 move(){
      // YOUR CODE HERE (4 lines)
      this.velocity.add(this.acceleration);
      this.location.add(this.velocity);
      this.acceleration.mult(0);
      this.velocity.limit(this.maxVelocity);

  }

  applyForce(f){
    this.acceleration.add(f);
  }

  /*
  Step 2: In spaceship.js update the interaction() function and fill out the missing information 
  in order to simulate the correct behavior in the system. When the left arrow is pressed the spaceship
   should move left, when the right arrow is pressed it should move right and so on. 
  Please note that the spaceship won't move until you have completed the next step too.
 */
  interaction(){
      if (keyIsDown(LEFT_ARROW)){
        this.applyForce(createVector(-0.1, 0));
      }
      if (keyIsDown(RIGHT_ARROW)){
      // YOUR CODE HERE (1 line)
        this.applyForce(createVector(0.1, 0));
      }
      if (keyIsDown(UP_ARROW)){
      // YOUR CODE HERE (1 line)
      this.applyForce(createVector(0, -0.1));
      }
      if (keyIsDown(DOWN_ARROW)){
      // YOUR CODE HERE (1 line)
      this.applyForce(createVector(0, 0.1));
      }
  }

  fire(){
    this.bulletSys.fire(this.location.x, this.location.y);
  }

  edges(){
    if (this.location.x<0) this.location.x=width;
    else if (this.location.x>width) this.location.x = 0;
    else if (this.location.y<0) this.location.y = height;
    else if (this.location.y>height) this.location.y = 0;
  }


 /*
 Step 9: In spaceship.js complete the setNearEarth() function. When the spaceship enters the earth's 
 atmosphere it's affected by the earth's gravity. Create a "downwards-pointing" 
 vector of strength 0.05 which pulls the spaceship towards the earth. The atmosphere 
 a lso introduces friction and the spaceship can't move forever like in empty space. 
 It will decelerate unless it fires its engines. Create a force called friction that's 30
  times smaller than the velocity of the spaceship, points the opposite direction to 
  velocity and is then applied in the the opposite direction.*/ 

  setNearEarth(){
    //YOUR CODE HERE (6 lines approx)
    var gravity = createVector(0,0.05);
    var friction = this.velocity.copy();
    friction = friction.mult(-1/30);
    this.applyForce(gravity);
    this.applyForce(friction);
  }
}
