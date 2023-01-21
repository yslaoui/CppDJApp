var stepSize = 20;
var n;
var n1;
function setup() {
  createCanvas(500, 500);
}
///////////////////////////////////////////////////////////////////////
function draw() {
  rectMode(CENTER)
  background(125);
  colorGrid();
  compassGrid();
}
///////////////////////////////////////////////////////////////////////
 
function colorGrid(){
  // your code here
  for (var i=0; i<25; i++) {
    for (var j=0; j<25; j++) {
      // tile position
      var tileX = width*i/25 + stepSize/2;
      var tileY = height*j/25 + stepSize/2;
      
      //tile color
      var mouseMap = map(mouseX, 0,width, 20,40);
      var n = noise(tileX/1000, tileY/1000, frameCount/mouseMap);
      var from = color(255,0,0);
      var to = color(0,0,255);
      var inter = lerpColor(from, to, n);

      // draw tile
      fill(inter);
      noStroke();
      rect(tileX,tileY, stepSize, stepSize);      
    }
  }
}
///////////////////////////////////////////////////////////////////////

/*
Ideas for further development 
Make it your own by changing the colors and style.
Use the noise to change the color and length of the compass lines.
*/ 

function compassGrid(){
  // your code here
  stroke(0);
  for (var i=0; i<25; i++) {
    for (var j=0; j<25; j++) {
      // translate to the center of each tile and draw compasses
      var mouseMap2 = map(mouseX, 0,width, 20,40);
      var tileCenter = createVector(width*i/25 + stepSize/2, height*j/25 + stepSize/2);
      // Create noise
      n = noise(tileCenter.x/1000, tileCenter.y/1000, frameCount/mouseMap2);
      n1 = noise(tileCenter.x/1000, tileCenter.y/1000, frameCount/mouseMap2);
      // console.log(frameCount/mouseMap);
      // Create rotation
      var rot = map(n, 0, 1, 0, 720);
      var col = map(n1, 0, 1, 100, 255); // Extension: using noise to change the color of the line
      var len = map(n1, 0, 1, 10, 20); // Extension: Using noise to change the length of the line
      console.log(col);
      push();
        stroke(0,col,0);
        translate(tileCenter.x, tileCenter.y);
        rotate(radians(rot));
        line(0, len, 0, -len);
      pop();
    }
  }
}
