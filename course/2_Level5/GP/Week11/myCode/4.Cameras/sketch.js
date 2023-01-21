function setup() {
    createCanvas(900, 600, WEBGL);
    angleMode(DEGREES);
}

function draw() {
    
    // *********Simple camera effect *******//
    // Play with the values of c to see the camera going in and out
    /*
    var c = 0.5;
    var zloc = c * height;
    // camera settings: positionned on the z axis ie closer to me at zloc, the direction is poiting towards the origin at (0,0,0), and it is pointing upwards at (0,1,0))
    camera(0,0,zloc,0,0,0,0,1,0);
    */

    // *********Flying bee camera effect *******//
    /*
    // Camera behavior: oscillate from 0 to 1 to never go behind the canvas. Remember sin oscillates between -1 and 1 so we add 1. We do not want to sick camera to canvas so add 200 
    var zLoc = (sin(frameCount)+1)/2 * height + 200;
    // zloc2 below is exactly the same as zloc1. It is computed differently
    var zloc2 = map(sin(frameCount),-1,1,200,800)
    //zloc3 uses noise function. the input to noise must be different between x , y and z otherwise it will return the same value for them
    var xloc3 = map(noise(frameCount/100),0,1,-500,500);
    var yloc3 = map(noise(frameCount/100+100),0,1,-500,500);
    var zloc3 = map(noise(frameCount/100+150),0,1,300,800);
    // camera now is like an organic bee flying but always pointing to the center of the torus
    camera(xloc3,yloc3,zloc3,0,0,0,0,1,0);
    */

    // *********Camera circling around the object *******//
    /*
    // To rotate in circle around the y axis, make x a cosin position and y the corresponding sin poistion
    var xloc = cos(frameCount) * height;
    var yloc = sin(frameCount*3) * 300; // create an up and down effect. optional
    var zloc = sin(frameCount) * height;
    // camera now is like an organic bee flying but always pointing to the center of the torus
    camera(xloc,0,zloc,0,0,0,0,1,0);
    */

    // *********Playing with where the camera is poiting at (the second 3-uple) *******//
    /*
    // focuse of the camera goes from -300 to +300 back and forth
    var xAim = sin(frameCount) * 300;
    camera(0,0,height,xAim,0,0,0,1,0);
    */

    // *********Playing with orientation (the 3rd 3-uple) *******//
    // we make orientation the "diagonal" vector (1,1,0)
    camera(0,0,height,0,0,0,1,1,0);

   
    


    // Draw something
    background(125);
    normalMaterial();
    torus(200,50,50,50);
    translate(0,100,0);
    rotateX(90);
    fill(200);
    plane(500,500)


}
