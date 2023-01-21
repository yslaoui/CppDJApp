var buffer;

function setup() {
    createCanvas(900, 600, WEBGL);
    noStroke();
    // create a buffer, ie a canvas, of width 300 and height 300.
    buffer = createGraphics(500,300);
    buffer.background(255);
    angleMode(DEGREES);
    
}

function draw() {
    background(0);
    buffer.fill(255,0,255);
    buffer.noStroke();
    // at each draw create a small random ellipse on the buffer
    buffer.ellipse(random(buffer.width), random(buffer.height),10,10);
    rotateY(frameCount);
    // Take this buffer and use it as teh texture of a box
    texture(buffer);
    // box(200);
    sphere(100,30,30);

}
