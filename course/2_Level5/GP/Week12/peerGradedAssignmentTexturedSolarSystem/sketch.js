var sunImg;
var earthImg;
var moonImg;
var starsBuffer;
var starLocs;
var randomStar;


function preload(){
    sunImg = loadImage('assets/sun.jpg');
    earthImg = loadImage('assets/earth.jpg');
    moonImg = loadImage('assets/moon.jpg');
}


function setup() {
    angleMode(DEGREES);  
    createCanvas(900, 600, WEBGL);
    starsBuffer = createGraphics(width,height);
    starsBuffer.background(0);
    starsBuffer.fill(255);
    starLocs = [];
    for (var i=0; i<200; i++) {
        starLocs.push(createVector(random(width/2), random(height/2)));
    
    }

}




function draw() {

    //************ Basic setup
    camera(0,-500,height*1.3,0,0,0,0,1,0);
    rectMode(CENTER);

    //************ sun
    noStroke();
    push();
        rotateY(-frameCount);
        texture(sunImg);
        sphere(100);
    pop();

    //************  earth
    push();
        pointLight(255,255,255,0,0,0);
        pointLight(255,255,255,10,0,0);
        rotateY(-frameCount);
        translate(400,0,0);
        noStroke();
        ambientMaterial(255);
        texture(earthImg);
        sphere(75);    
    pop();

    //************ plane in the background
    
    starsBuffer.background(0);
    
    // Making stars flicker
    for (var i=0; i< starLocs.length; i++)  {
        if (random() < 0.001) {
            starLocs[i].x = random(width);
            starLocs[i].x = random(height);
        }
    }

    // Drawing the stars on the buffer
    for (var i=0; i<starLocs.length; i++) {
        starsBuffer.rect(starLocs[i].x, starLocs[i].y, 2,2);
    }

    // Applying the buffer to the canvas

    push();
        rotateX(35);
        translate(-width/2, -height/2,-height);
        image(starsBuffer, -width*2,-height*2, width*8, height*8);
        // texture(starsBuffer);
        // translate(0,0-height);
        // plane(width,height);
    pop();
}
 