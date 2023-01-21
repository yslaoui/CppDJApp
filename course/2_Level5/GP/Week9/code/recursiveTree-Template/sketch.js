var startSize;
var calls;

function setup() {
  createCanvas(900,900);
  background(200); 
  fill(0);
  noStroke();
  noSmooth();
  rectMode(CENTER); 
  startSize = pow(3, 6); // 3^6
  calls = 0;
}


function draw() {
  translate(width/2, height/2);
  rect(0,0,startSize/3,startSize/3); 
  yow(startSize); 
  noLoop(); // no dynamic, we do not update
}

function yow(side) {
  calls++; //
  side = side/3;
  //if size greater than 1 pixel keep dividing
  if (side >= 1) {
    fill(0);
    rect(0,0,side,side);

    push();
    translate(-side,0);
    yow(side);
    pop();

    push();
    translate(-side,-side);
    yow(side);
    pop();

    push();
    translate(0,-side);
    yow(side);
    pop();

    push();
    translate(side,-side);
    yow(side);
    pop();

    push();
    translate(side,0);
    yow(side);
    pop();

    push();
    translate(side,side);
    yow(side);
    pop();

    push();
    translate(0,side);
    yow(side);
    pop();

    push();
    translate(-side,side);
    yow(side);
    pop();
  }    
}

