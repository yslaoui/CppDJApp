var ball;

function setup() {
    createCanvas(900, 600);
    background(0);
    balls = [];
    for (var i=0; i<100; i++) {
        balls[i] = new Ball();
    }
}

function draw() {
    for (var i=0; i<100; i++) {
        balls[i].run();
    }
    
    }
        

class Ball {
    constructor() {
        var randomX = width/2 + random(-100,100);
        var randomY = height/2 + random(-100,100);
        this.location = createVector(randomX, randomY);
        this.previousLocation = createVector(randomX, randomY);
        this.speed = createVector(0, 0);
        this.acceleration = createVector(0);
    }

    run() {
        this.draw();
        this.move();
    }

    draw() {
        stroke(255);
        line(this.location.x, this.location.y, this.previousLocation.x, this.previousLocation.y);
        this.previousLocation = this.location.copy();
        this.speed.limit(5);
        // strokeWeight(3);
        // // ellipse(this.location.x, this.location.y, 30);
        // this.speed.limit(5); // limits the magnitude of the speed
        
    }

    move() {
        this.speed.add(this.acceleration);
        this.location.add(this.speed);
        // Creating a normalized vector of direction from the ball pointing to the mouse
        var mouse = createVector(mouseX, mouseY);
        var gravity = p5.Vector.sub(mouse, this.location);
        gravity.normalize();
        gravity.mult(0.3);
        // Make acceleration equal to gravity
        this.acceleration = gravity;
    }


}

  

