function setup() {
    createCanvas(900, 600, WEBGL);
    angleMode(DEGREES);
    background(0);
}

function draw() {
    background(125);
    normalMaterial();
    rectMode(CENTER);
    // #1
    push();
    translate(-width/2+150,-150,0);
    rotateX(frameCount);
    plane(100);
    pop();
    // #2 Notice that you put rotatex Before translate you get a planet-like effect
    push();
    translate(0,-150,0);
    rotateX(frameCount);
    box(100);
    pop();
    // #3
    push();
    translate(width/2-150,-150,0);
    rotateX(frameCount);
    cylinder(75);
    pop();
    // #4
    push();
    translate(-width/2+150,150,0);
    rotateX(frameCount);
    cone(75);
    pop();
    // #5 Notice that you put rotatex Before translate you get a planet-like effect
    push();
    translate(0,150,0);
    rotateX(frameCount);
    torus(75);
    pop();
    // #6
    push();
    translate(width/2-150,150,0);
    rotateX(frameCount);
    sphere(75);
    pop();

    

    
    


}
