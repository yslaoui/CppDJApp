var ball;

function setup() {
    createCanvas(900, 600);
    background(0);
    ball = new Ball();
}

function draw() {
    ball.run();
    }
        

class Ball {
    constructor() {
        this.location = createVector(width/2, height/2);
        this.previousLocation = createVector(width/2, height/2);
        this.speed = createVector(0, 0);
        this.acceleration = createVector(0);
    }

    run() {
        this.draw();
        this.move();
        this.edges();
    }

    draw() {
        stroke(125);
        strokeWeight(3);
        // ellipse(this.location.x, this.location.y, 30);
        this.speed.limit(5); // limits the magnitude of the speed
        line(this.location.x, this.location.y, this.previousLocation.x, this.previousLocation.y);
        this.previousLocation = this.location.copy();

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

    edges() {
        if (this.location.x < 0) this.location.x = width;
        else if (this.location.x > width) this.location.x = 0;
        else if (this.location.y < 0) this.location.y = height;
        else if (this.location.y > height) this.location.y = 0;
    }
}

  

