function setup() {
    createCanvas(900, 600, WEBGL);
    angleMode(DEGREES);    
}

function draw() {
    
    camera(0,-500,height*1.3,0,0,0,0,1,0);
    background(125);
    rectMode(CENTER);
    push();
        rotateY(frameCount);
        translate(400,0,0);
        noStroke();
        ambientMaterial(255);
        pointLight(0,255,0,0,0,0);
        pointLight(0,255,0,10,0,0);
        sphere(50);
        ellipse(0,0,200,200);
    pop();
    circle(0,0,300);
}
