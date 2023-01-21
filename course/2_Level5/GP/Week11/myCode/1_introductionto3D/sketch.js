function setup() {
    createCanvas(900, 600, WEBGL);
    // Make everything you pass to the rotate function degrees and not radians
    angleMode(DEGREES);
}

function draw() {
    background(125);
    // Notice how the center of the workd is the middle of the canvas
    /*
    ellipse(0,0,30,30);
    rect(0,0,100,100);
    
    
    //***** First let us create a 2D object and rotate it******


    // If you want a rectangle whose center is the center of the canvas you still need to use rectmode
    rectMode(CENTER);
    // Rotate the rectnagle around the x-axis. Comment out the previously drawn rectangle and ellipse to see the rotation clearly
    rotateX(frameCount);
    rect(0, 0, 100, 100);
    

    //***** Second let us create a 3D object and rotate it******

    rectMode(CENTER);
    rotateX(frameCount);
    // rotateY(frameCount);
    // rotateZ(frameCount);
    box(200);
    */ 

    //***** Third let us create a 3D object and rotate it around the center of the screen like if it was a planet******

    rectMode(CENTER);
    // Understand that when you do rotate Y, it means that both the x and y axis rotate around the y axis, because everything rotates around the y axis     
    rotateY(frameCount);
    translate(200,0,0);
    // rotateY(frameCount);
    // rotateZ(frameCount);
    box(100);


    

}
