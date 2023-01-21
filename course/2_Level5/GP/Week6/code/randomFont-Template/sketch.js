/*
In this programming exercise, you’re asked to use the points that make up the word
 to generate an interesting new font like in the image above.

Warning: Remember, use Bracket’s live view to view your sketch.
Loading fonts will not work when the html is viewed independently in chrome.

randomFont-Template

Steps to complete  
Step 1: Start by downloading the template project attached.

Step 2:  In the draw() function loop over the points array. This array has the locations of the points that make up the word “code”, p5.js textToPoints() returns an array of p5.js points. Display them as circles at their x and y coordinates using ellipse().

Step 3: In the loop over the points array, use the random() function to add a random amount to the x and y coordinates of each point in order to make it appear in a new location. HINT: the random() function will return a different range of values depending on how many arguments are passed into it, look at the p5.js random() reference to remind yourself. 

Step 4: Use mouseX to vary the range the random() function takes to generate the value that you add to the location of each point. HINT: you can use the map() function to map mouseX to a new range.

Notice that the sketch stops generating new patterns when the mouse 
stops moving. That’s because at the bottom of the draw() function 
the noLoop() command is called which stops the sketch from looping 
further. At the same time, inside the mouseMoved() function we call
 the loop() function which reactivates the sketch when the mouse is 
 moved.
*/ 


var font;
function preload() {
  font = loadFont('assets/Calistoga-Regular.ttf');
}
var points;
var blur;

function setup() {
  createCanvas(900, 400);
  fill(255, 104, 204, 150);
  noStroke();

  points = font.textToPoints('c o d e', 50, 300, 300, {
    sampleFactor: .3,
    simplifyThreshold: 0
  });

}

function draw() {
    background(0);
    blur = map(mouseX, 0,width, 10,50);
    console.log(blur);

    // *** your code here ****
    // Step 2:  In the draw() function loop over the points array. 
    // This array has the locations of the points that make up the word
    //  “code”, p5.js textToPoints() returns an array of p5.js points.
    //  Display them as circles at their x and y coordinates using ellipse().
    
    // Step 3: In the loop over the points array, use the random() function 
    // to add a random amount to the x and y coordinates of each point in 
    // order to make it appear in a new location. HINT: the random() 
    // function will return a different range of values depending on how 
    // many arguments are passed into it, look at the p5.js random()
    //  reference to remind yourself. 

    for (var i=0; i<points.length; i++) {
      ellipse(points[i].x+random(blur), points[i].y+random(blur), 20, 20);
    }
    noLoop();
}

function mouseMoved(){
    loop();
}
