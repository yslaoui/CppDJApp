var circle;
var mouse;
var walker1;

function setup() {
    createCanvas(900, 600);
    background(0);
    randomSeed(100);
    walker1 = new Walker();
    
}

function draw() {
    background(0); // clear the screen at each loop
    walker1.draw();
}

class Walker {
    constructor() {
        this.x = width/2;
        this.y = height/2;
        this.radius = 50;
    }

    draw() {
        mouse = createVector(mouseX, mouseY);
        if(dist(mouse.x, mouse.y, this.x, this.y) < this.radius) {
            this.x += random(-10, 10);
            this.y += random(-10, 10);    
    }   
        ellipse(this.x, 
                this.y, 
                this.radius,
                this.radius);
    }
}


