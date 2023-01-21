
var time = 1000;
var nX;
var nY;

function setup() {
    createCanvas(900, 600);
    background(0);
    rectMode(CENTER); // When I define a rectangle the location is the center not the topleft
}

function draw() {
    background(0);
    nX = noise(time);
    nY = noise(time+5);  // attention if noise(time) then nX=nY ie you generate the same random value
    // see p5 documentation. Returns the Perlin noise value at specified coordinates
    // noise returns a random value between 0 and 1
    var locX = map(nX, 0,1,0,width);
    var g = map(nX, 0,1,0,255);
    var locY = map(nY,0,1,0,height);

    var rotZ = map(nX, 0,1,-25,25);
    translate(locX, locY);
    rotate(rotZ);
    fill(0,g,0);
    rect(0,0,100,100);
    time += 0.01;
    // The shape moves around teh center of the screen because that is where the majority of teh distribution lies
    // if we do translate(random(width), height/2) the value can be anywhere to the left or right    
    // So it is a different behavior
}
