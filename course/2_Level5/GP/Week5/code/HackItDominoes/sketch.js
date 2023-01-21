/*
This is a challenge for students to do some investigative work of their own into Matter.js. You should read the Matter.js documentation about composites. You can look at an available demo of how to implement a composite along with the code for that demo.

Setup the dominoes above. Start by using the template code attached.

dominoes-Template

Add code in setupDominoes() function using a composite.

Add code in the drawDominoes() function to draw the pieces using the drawVertices() helper function. Remember to loop through each object in the stack.
*/



// Example is based on examples from:
// http://brm.io/matter-js/
// https://github.com/shiffman/p5-matter
// https://github.com/b-g/p5-matter-examples

// module aliases
var Engine = Matter.Engine;
var Render = Matter.Render;
var World = Matter.World;
var Bodies = Matter.Bodies;
var Composites = Matter.Composites;

var engine;
var ball;
var ground;
var stack;

function setup() {
  createCanvas(1200, 600);

  // create an engine
  engine = Engine.create();

  ball = Bodies.circle(30, 0, 20, {restitution:1, friction: 0, density: 0.003});

  var options = {isStatic: true, angle: Math.PI * 0};
  ground = Bodies.rectangle(width/2, 500, width, 10, options);
  smallGround = Bodies.rectangle(50, 470, 100, 10, {isStatic: true, angle: Math.PI * 0.2});

  setupDominoes();


  // add all of the bodies to the world
  World.add(engine.world, [ground, ball, smallGround, stack]);

  
}
/////////////////////////////////////////////////////////
function draw() {
  background(0);
  Engine.update(engine);

  fill(255);
  drawVertices(ball.vertices);

  drawDominoes();

  fill(128);
  drawVertices(ground.vertices);
  drawVertices(smallGround.vertices);
}
/////////////////////////////////////////////////////////
// Add code in setupDominoes() function using a composite.
// atter.Composites.stack(xx, yy, columns, rows, columnGap, rowGap, callback)
function setupDominoes(){
   // your code here
   stack = Composites.stack(100, 250, 35, 1, 10, 0, function(x, y) {
    return Bodies.rectangle(x, y, 10, ground.position.y-250, {
      render: {
        fillStyle: 'orange',
        strokeStyle: 'black'
      }
    });
  });  
}
/////////////////////////////////////////////////////////
function drawDominoes(){
  // your code here
  // drawVertices(stack.vertices);
  for (var i=0; i<stack.bodies.length; i++) {
    drawVertices(stack.bodies[i].vertices);
  }
}
/////////////////////////////////////////////////////////
// ********* HELPER FUNCTIONS **********
/////////////////////////////////////////////////////////
function drawVertices(vertices) {
  beginShape();
  for (var i = 0; i < vertices.length; i++) {
    vertex(vertices[i].x, vertices[i].y);
  }
  endShape(CLOSE);
}
