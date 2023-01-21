// Matter.js module aliases
var Engine = Matter.Engine;
var Render = Matter.Render;
var World = Matter.World;
var Bodies = Matter.Bodies;
var Constraint = Matter.Constraint;
var MouseConstraint = Matter.MouseConstraint;
var Mouse = Matter.Mouse;


// Global variables 
var engine;
var ground; // a ground for the ball to bounce on
var canvas;

// System 1 - Two bodies constrained together
var poly1A;
var poly1B;
var constraint1;

// System 2 - One body constrained to a fixed point
var poly2;
var constraint2;

// System 3
var poly3;
var constraint3;


function setup() {
    canvas = createCanvas(900,600);
    // create en engine
    engine = Engine.create();

    // ground 
    ground = Bodies.rectangle(width/2,height-20,800,10, {isStatic: true, angle: 0});
    World.add(engine.world, [ground]);
    
    // Mouse
    var mouse = Mouse.create(canvas.elt) // canvas is a p5.js construct. canvas.elt returns the actual HTML element. We get the mouse position on the canvas
    var mouseParams = {
      mouse: mouse
    }; // We put the mouse position into a mouseParams object.
    var mouseConstraint = MouseConstraint.create(engine, mouseParams); // We create a mouse constraint object. Attention mouseContraint is an instance of class MouseConstraint
    mouseConstraint.mouse.pixelratio = pixelDensity(); // Not necessary for my computer. This is for computers with low pixel density
    World.add(engine.world, mouseConstraint);  // We add the mouse constraint to the world

    // System 1: Two bodies constrained together
    poly1A = Bodies.polygon(700,100,6,20);
    poly1B = Bodies.polygon(700,250,1,50);
    constraint1 = Constraint.create({
        bodyA: poly1A,
        point1A: {x:0, y:0}, //grab from its center
        bodyB: poly1B,
        pointB: {x:-10, y:-10}, //Coordinates relative to the center
        stiffness:0.01 // Makes the join elastic
    })
    World.add(engine.world, [poly1A, poly1B, constraint1]);

    // System 2: A body constrained by a fixed point
    poly2 = Bodies.polygon(300,200,5,40);
    constraint2 = Constraint.create({
        // No bodyA. We want poly2 to be attached to a fixed point in the world
        pointA: {x:150, y:50}, //grab from its center
        bodyB: poly2,
        pointB: {x:-10, y:-20}, //Coordinates relative to the center
        stiffness:0.01 // Makes the join elastic
    })
    World.add(engine.world, [poly2, constraint2]);


    // System 3: A body constrained by a fixed point more elastically
    poly3 = Bodies.polygon(400,100,4,30);
    constraint3 = Constraint.create({
        // No bodyA. We want poly2 to be attached to a fixed point in the world
        pointA: {x:400, y:120}, //grab from its center
        bodyB: poly3,
        pointB: {x:-10, y:-20}, //Coordinates relative to the center
        stiffness:0.001, // Makes the join elastic
        damping: 0.05 // The return movement is softened a bit
    })
    World.add(engine.world, [poly3, constraint3]);

}

function draw() {
    // Update the engine at each loop of the draw() function
    background(0);
    Engine.update(engine);

    // Drawing the constraint
    stroke(128);
    strokeWeight(3);
    drawConstraint(constraint1);
    drawConstraint(constraint2);
    drawConstraint(constraint3);

    // Draw the grounds 
    strokeWeight(1);
    drawVertices(ground.vertices);
    drawVertices(poly1A.vertices);
    drawVertices(poly1B.vertices);
    drawVertices(poly2.vertices);
    drawVertices(poly3.vertices);
}

// ***********HELPER FUNCTIONS *************//
function drawConstraint(constraint) {
    var offsetA = constraint.pointA;
    var posA = {x:0, y:0};
    if (constraint.bodyA) {
      posA = constraint.bodyA.position;
    }
    var offsetB = constraint.pointB;
    var posB = {x:0, y:0};
    if (constraint.bodyB) {
      posB = constraint.bodyB.position;
    }
    line(
      posA.x + offsetA.x,
      posA.y + offsetA.y,
      posB.x + offsetB.x,
      posB.y + offsetB.y
    );
  }



function drawVertices(vertices) {
    beginShape();
    for (var i=0; i<vertices.length; i++) {
        vertex(vertices[i].x, vertices[i].y);
    }
    endShape(CLOSE);
}


