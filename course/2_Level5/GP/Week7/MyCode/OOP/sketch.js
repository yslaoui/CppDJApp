var state = false;
var button1;
var button2;

function setup() {
    createCanvas(1500, 1500);
    background(0);
    button1 = new Button(200,200,200,100);
    button2 = new Button(100,100,50,50);
}

function draw() {   
    background(125);
    button1.draw();
    button2.draw();
}

function mousePressed() {
    button1.flick(mouseX, mouseY);
    button2.flick(mouseX, mouseY);
}

class Button {
    constructor(x, y, w, h) {
        this.state = false;
        this.locX = x;
        this.locY = y;
        this.w = w;
        this.h = h;
    }

    draw() {
        if (this.state) {
            fill(255);
        }
        else {
            fill(0);
        }
        rect(this.locX, this.locY, this.w, this.h);
    }

    flick(x,y) {
        if (x > this.locX && x < (this.locX+this.w) && y > this.locY && y < (this.locY+this.h)) {
            this.state = !this.state;
        }
    }


}
