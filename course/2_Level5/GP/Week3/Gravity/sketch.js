var ball;

function setup() {
    createCanvas(900, 600);
    background(0);
    ball = new Ball();
}

function draw() {
    background(0); // this one is important to ease the previous ball as it moves    
    var gravity = createVector(0, 0.1);
    ball.applyForce(gravity);
    ball.run();
       
    }
        

class Ball {
    constructor() {
        this.location = createVector(width/2, height/2);
        this.speed = createVector(0, 0);
        this.acceleration = createVector(0,0);

    }

    run() {
        this.draw();
        this.move();
        this.edges();
    }

    draw() {
        fill(125);
        ellipse(this.location.x, this.location.y, 30);
        this.speed.limit(10); // limits the magnitude of the speed        
    }

    move() {
        this.speed.add(this.acceleration);
        this.location.add(this.speed);
        this.acceleration.mult(0);
        var friction = this.speed.copy();
        friction.normalize();
        friction.mult(-0.01);
        this.applyForce(friction);
    }

    edges() {
        if (this.location.x < 0 || this.location.x > width || this.location.y < 0 ||this.location.y > height ) {
            this.speed.mult(-1);
        } 
    }

    applyForce(force) {
        this.acceleration.add(force);
    }
}

  

