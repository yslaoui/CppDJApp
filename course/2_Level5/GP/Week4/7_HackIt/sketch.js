// Example is based on examples from:
// http://brm.io/matter-js/
// https://github.com/shiffman/p5-matter
// https://github.com/b-g/p5-matter-examples

/*
• Add code in setupCatapult() that initialises the global catapult variable as a rectangle (the white rectangle). 
• Add also a constraint right in the middle of the white rectangle that has a stiffness of 1 and length of 0.
• Add the catapult and the constraint to the world.
• Add code to drawCatapult() to draw the catapult like in drawGround().
• Add a bit more code that sets up the red rectangle you see in the image, that acts as a support. Add the catapultSpace to the world.
• Add code to drawCatapult() to draw the catapultSpacer like in drawGround().
• Add code to setupBalls() to setup two balls like in the example above. Set the density of ball1 to 0.01 so that the ball has a lot of weight.
• Add code to drawBalls() to draw the two balls you created.

*/

// module aliases
var Engine = Matter.Engine;
var Render = Matter.Render;
var World = Matter.World;
var Bodies = Matter.Bodies;
var Constraint = Matter.Constraint;
var Vector = Matter.Vector;

// Global variables
var engine;
var ground;

var ball1;
var ball2;

var catapult;
var catapultSpacer; // This is the red rectangle that acts as support
var constraint;

function setup() {
  createCanvas(800, 600);
  engine = Engine.create(); // create an engine
  setupCatapult();
  setupBalls();
  setupGround();

// Add also a constraint right in the middle of the white rectangle that
//  has a stiffness of 1 and length of 0.

  // Constraint 1: At the middle of the catapult
  constraint = Constraint.create({
    bodyA : catapult,
    pointB: Vector.clone(catapult.position), // pointA = pointB so length is 0
    stiffness: 1,
    length: 0
  })

  // Add the catapult and the constraint to the world.
  World.add(engine.world, [catapult, catapultSpacer, constraint, ball1, ball2]);
}
/////////////////////////////////////////////////////////////
function draw() {
  background(0);
  Engine.update(engine);
  drawBalls();
  drawCatapult();
  drawGround();
  // Add a bit more code that sets up the red rectangle you see in the image, that acts as a support. Add the catapultSpace to the world.


}
/////////////////////////////////////////////////////////////

// •  Add code in setupCatapult() that initialises the global catapult
//  variable as a rectangle (the white rectangle). 

function setupCatapult(){
  // Attention rectangle is defined from the center in matter.js
  // Catapult must not be static in order for it to move
  catapult = Bodies.rectangle(0.5*width, 0.8*height, 0.8*width,20, );
  // Red rectangle below the catapult that support it. Attention if you define it as a rect in draw() directly it will have nophysical effect !
  catapultSpacer = Bodies.rectangle(
    catapult.position.x-250,
    catapult.position.y + 50,20,75, {isStatic: true});
}
/////////////////////////////////////////////////////////////
// •  Add code to drawCatapult() to draw the catapult like in drawGround().
// •  Add code to drawCatapult() to draw the catapultSpacer like in drawGround().

function drawCatapult(){
  // your code here
  noStroke();
  fill(255);
  drawVertices(catapult.vertices);
  fill(255,0,0);
  drawVertices(catapultSpacer.vertices);

}
//  Add code to setupBalls() to setup two balls like in the example above. 
// Set the density of ball1 to 0.01 so that the ball has a lot of weight.

/////////////////////////////////////////////////////////////
function setupBalls(){

  // your code here
  ball1 = Bodies.circle(catapult.position.x-200,0,20);
  ball2 = Bodies.circle(catapult.position.x+200,0,60,{density: 0.01});
}
/////////////////////////////////////////////////////////////
function drawBalls(){
  // your code here
  fill(0,0,255);
  drawVertices(ball1.vertices);
  drawVertices(ball2.vertices);
}
/////////////////////////////////////////////////////////////
function setupGround(){
  ground = Bodies.rectangle(400, height-10, 810, 25, {isStatic: true});
  World.add(engine.world, [ground]);
}
/////////////////////////////////////////////////////////////
function drawGround(){
  noStroke();
  fill(128);
  drawVertices(ground.vertices);
}
////////////////////////////////////////////////////////////////
// ******* HELPER FUNCTIONS *********
// DO NOT WRITE BELOW HERE
/////////////////////////////////////////////////////////////
function drawVertices(vertices) {
  beginShape();
  for (var i = 0; i < vertices.length; i++) {
    vertex(vertices[i].x, vertices[i].y);
  }
  endShape(CLOSE);
}


