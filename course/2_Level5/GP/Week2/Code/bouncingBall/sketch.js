var ball;

function setup() {
    createCanvas(900, 600);
    background(0);
    ball = new Ball();
}

function draw() {
    background(0); // this one is important to eease the previoius ball as it moves
    ball.run();
    }
        

class Ball {
    constructor() {
        this.location = createVector(random(width), random(height));
        this.speed = createVector(random(-2,2), random(-2,2));
    }

    run() {
        this.draw();
        this.move();
        this.bounce();
    }

    draw() {
        fill(125);
        ellipse(this.location.x, this.location.y, 30)
    }

    move() {
        this.location.add(this.speed);
    }

    bounce() {
        if (this.location.x < 0 || this.location.x > width) this.speed.x *= -1;
        if (this.location.y < 0 || this.location.y > height) this.speed.y *= -1;
    }
}



