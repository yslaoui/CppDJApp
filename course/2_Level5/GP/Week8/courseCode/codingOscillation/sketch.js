function setup() {
    createCanvas(900, 600);
    background(0);
    angleMode(DEGREES);
}

function draw() {
    background(0);
    fill(255);
    translate(width/2, height/2)
    var amp = width/2;
    var period = 360; // It takes period/60 seconds for the ball to get back to place 
    var phase = 0; // starting angle
    var freq = 1;
    var locX = sin(frameCount*6*freq+phase) * amp;
    ellipse(locX, 0, 30, 30);
}
