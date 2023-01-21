var img;

// We load the image inside the premoad function because we do not the setup() and draw() function to be called until the image is loaded
function preload() {
    img = loadImage('assets/myimg.jpg');
    angleMode(DEGREES);
}

function setup() {
    createCanvas(900, 600, WEBGL);
    
}

function draw() {
    background(0);
    texture(img);
    noStroke();
    rotateY(frameCount);
    // box(300);
    plane(500,500);
}
