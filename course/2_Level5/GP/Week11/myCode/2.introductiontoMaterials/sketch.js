function setup() {
    createCanvas(900, 600, WEBGL);
}

function draw() {
    
    background(125);
    //100 is the size, 20,20 is the resolution. If you increase the resolution you loose the lines thhat create the 3D effects without colors
    // sphere(100,20,20);
    // // High resolution the ellipse looks like cicrke and looses its fullness
    // sphere(100,50,50);

    //*************** Normal material ******* 
    // give 3D-ness of "fulness" to material by applying colors as function of position
    /*
    normalMaterial();
    sphere(100,50,50);
    */
     
    //*************** Ambient material with ambient light ******* 
    // reflects light shown on it. If no light is shown, it turns black
    // Create an ambient light of color green. Because the object is red, the ellipse will look black
    /*
    ambientLight(0,255,0);
    ambientMaterial(0,255,0);
    sphere(100,50,50);    
    */
    // So instead let's shine a green light on a white object and it will look green indeed
    /*
    ambientLight(255,0,0);
    ambientMaterial(255);
    sphere(100,50,50);    
    */
    
    //*************** Ambient material with point light ******* 
    // Because light is shining from everywhere you are loosing a lot of the details. 
    // To see the details let's use a point light that shines from point (x, y, z) = (-500,100, 0)
    /*
    pointLight(0,255,0, -500, 100, 0);
    ambientMaterial(255);
    sphere(100,50,50);    
    */
    // We can make the light point be the mouse. Note that mouseX and mouseY are defined relative to the topleft of the canvas
    /*
    pointLight(0,255,0,mouseX-width/2, mouseY-height/2, 100);
    ambientMaterial(255);
    sphere(100,50,50);    
    */
   // We can mix a fixed point light with a dynamic light. Notice that colors blend when we superpose them
    /*
    pointLight(0,255,0, mouseX-width/2, mouseY-height/2, 100);
    pointLight(255,0,0,-200, 100);
    ambientMaterial(255);
    sphere(100,50,50);    
    */
    //*************** Specular material with point light ******* 
    
    /*
    specularMaterial(255);
    pointLight(255,0,0, mouseX-width/2, mouseY-height/2, 100);
    pointLight(0,255,0,-200, 100);
    // we choose low resolution to reinforce the 3D metallic effect
    // we chose noStroke() which removes the 3D lines introduced by low resolution
    noStroke();
    sphere(100,20,20);    
    */
    //*************** Ambient material with Directional light ******* 
    noStroke();
    ambientMaterial(255);
    // Directinal light we just specify the direction towards which its lights
    // to do that we enter the coordinates of a normal vector as 4th, 5th and 6th parameter
    // (1,0,0) means a normal vector that points to the right from a point that is infinitely distant from the left side
    directionalLight(255,0,0,1,0,0)    
    sphere(100,20,20);
}
