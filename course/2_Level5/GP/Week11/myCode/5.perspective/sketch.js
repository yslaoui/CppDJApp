function setup() {
    createCanvas(900, 600, WEBGL);
    angleMode(DEGREES); // To set the perspective angle in degrees
}

function draw() {
    background(125);

    camera(0, -200, height, 0,0,0, 0,1,0);
    
    // **** First parameter: the angle of view
    // perspective(60); // That is the default view
    //perspective(120);

    // *** Second parameter: the aspect ratio
    /*
    perspective(60, width/height); //the default value is the aspect ratio of the canvas
    perspective(60, 4/4);
    */

    // *** Third parameter: the planes
    // the last two parameters are the near plane and the far plane
    // perspective(60, width/height, mouseY); // Here mouseY controls the near plane. as mouseY increases, the shape gets clipped because the near plane gets further away
    perspective(60, width/height, mouseY, mouseX); // mouseX controls for far plane. ANs mouseX decreases the far plae gets closer


    // Setting some scene: A rod that extends into the scene, further away from the viewer, so that we can see that clipping thing
    normalMaterial();
    for (var i=-600; i<=600; i+=150) {
        push();
        translate(i,0, 0);
        box(80,80,500); // box of size x=80, y=80, z=500.
        pop();
    }
    


}
