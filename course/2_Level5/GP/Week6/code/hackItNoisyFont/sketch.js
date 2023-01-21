/*

In this programming exercise, you’re asked to use the points that make up 
the word to generate a font-based animation as shown in the image above.

Warning: Use Bracket’s live view to view your sketch. Loading fonts will not
work when the html is viewed independently in the browser.

Steps to complete
Step 1: Download the template code attached.

Step 2: In the draw() function loop over the points array. This array has 
the locations of the points that make up the word “code”, p5.js textToPoints()
returns an array of p5.js points. Display them as circles at their x and y 
coordinates using ellipse().

Step 3: 

Within the for loop, calculate a value nX that is generated from the noise() 
function.Pass into the noise() function the frameCount correctly scaled. 
Map that to a value between -amt and amt where amt is equal to 20.

Add that value returned from map() to the coordinate of each point. 
Do the same for nY. If you’ve done things right the entire word should 
move diagonally. That’s because every point is getting the same noise value
 as we’re only passing the frameCount to it.

Step 4: Make nX be different for each point by adding the point´s x and y
coordinate to the frameCount and passing that to noise instead. 
Do the same for nY. If you’ve done things right each point now should move 
independently for the others, but they are still each moving diagonally. 
That’s because the nX and nY value of each point is the same.

Step 5: Add a number (any number) to the parameters you pass to nY. 
This way we are decoupling the nX and nY values from each other as nY reads
 from a different point in the noise graph.

Make it your own!
Bonus 1: Play with amt. Set it to be dependent on mouseX and have it range 
from 0 to 80. (Hint: use map() for that)

Bonus 2: Play with different colors.

Bonus 3: Play with the size of the dots.

Bonus 4: Play with the trail the particles leave by modifying the 
fill of the rect in the draw function. Connect it with mouseY!





*/ 



var points;
var font;
var amt;
function preload() {
  font = loadFont('assets/Calistoga-Regular.ttf');
}

//////////////////////////////////////////////////////////////////////
function setup() {
  createCanvas(900, 400);
  background(0);
  amt = 20;

  points = font.textToPoints('c o d e', 50, 300, 300, {
    sampleFactor: .3,
    simplifyThreshold: 0
  });
}

//////////////////////////////////////////////////////////////////////

/*
Step 4: Make nX be different for each point by adding the point´s x and y
coordinate to the frameCount and passing that to noise instead. 
Do the same for nY. If you’ve done things right each point now should move 
independently for the others, but they are still each moving diagonally. 
That’s because the nX and nY value of each point is the same.

*/ 

function draw() {

  
     
    console.log(frameCount%100);
    for (var i=0; i<points.length; i++) {
      var nX = noise(frameCount+points[i].x);
      var nY = noise(frameCount+points[i].y+100);  
      var offsetX = map(nX,0,1,-amt,amt);
      var offsetY = map(nX,0,1,-amt,amt);
      ellipse(points[i].x+offsetX, points[i].y+offsetY, 30,30);
    }
    

    // **** Your code here ****
}
