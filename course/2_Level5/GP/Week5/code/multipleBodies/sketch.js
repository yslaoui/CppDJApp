// module aliases -- nicknames that make the command shorter 
var Engine = Matter.Engine;
var Render = Matter.Render;
var World = Matter.World;
var Bodies = Matter.Bodies;
var Body = Matter.Body;


// Global variables 
var engine;
var box1; // A body that we will create
var ground; // a ground for the ball to bounce on
var boxes = [];
var propeller;
var angle = 0; // Angle for the propeller
var angleSpeed = 0.1; // Angular speed of propeller. Amound by which the angle increases between two frames



function setup() {
    createCanvas(900,600);
    // create en engine
    engine = Engine.create();

    // we create our first body and the ground
        // box is falling with gravity. Restitution is the energy with which it bounces
    box1 = Bodies.rectangle(50,0,50,50, {restitution:0.8, friction: 0.5});
    // ground and propeller are not falling because of gravity
    ground = Bodies.rectangle(500,500,500,10, {isStatic: true, angle: Math.PI * -0.06});
    propeller = Bodies.rectangle (width/2, height/2, 300, 15, {isStatic: true, angle: angle})

    // We add all the bodies to the word
    World.add(engine.world, [box1, ground, propeller]);

}

function draw() {
    // Update the engine at each loop of the draw() function
    background(0);
    Engine.update(engine);

    // Draw the object . Check in console engine.world.bodies 
    fill(255);
    drawVertices(box1.vertices);
    drawVertices(propeller.vertices);
    Body.setAngle(propeller, angle);
    // At this point, at each frame the angle of the propeller is incremented, but within that frame, it is as if the boxes
    // are hitting a frame that is fixed. We need to tell matter.js that the propeller is actually hitting
    // the boxes with some velocity.We do this by giving the propeller an angularSpeed > 0. note that 
    // angular speed is a propertuy of the propeller (do a console.log propeller.angularSpeed)
    Body.setAngularVelocity(propeller, angleSpeed); 
    angle += angleSpeed;
    // Now, instead of simply landing on the propeller, the boxes are hit by the propeller and are projected


    if (random(1)<0.2) generateObject(width/2, 0); // The if statement slows down the generation process to every 5th frame.
    for (var i=0; i<boxes.length; i++) {
        drawVertices(boxes[i].vertices);
        if (isOffScreen(boxes[i])) {
            // Remove box from physics engine
            World.remove(engine.world, boxes[i]);
            
            
            //  Remove box from drawing. Chck in console boxes.length
            boxes.splice(i,1);
            // the next box will not be checked because it is moved one position down and the iterator moves one position up
            //So we need to reexecute the code at i beforemoving to i+1
            // We achieve this this way
            i--;

        }

        // 
        
    }

    // Draw the grounds 
    fill(125);
    drawVertices(ground.vertices);
}

// Function that generates objects at position x and y
function generateObject(x,y) {
    var b = Bodies.rectangle(x,y, random(10,30), random(10,30), {restitution: 0.8, friction: 0.5})
    boxes.push(b);
    // Tells the physics engine to keep calculating the object position
    World.add(engine.world,[b]);

}

// Function that eliminates objects When off screen
// Which will prevent then physics engine from slowing down
function isOffScreen(body) {
    // returns true if y position > height
    var pos = body.position;
    return (pos.y>height || pos.x <0 || pos.x >width);
} 


function drawVertices(vertices) {
    beginShape();
    for (var i=0; i<vertices.length; i++) {
        vertex(vertices[i].x, vertices[i].y);
    }
    endShape(CLOSE);
}
