////////////////////////////////////////////////////////////////
function setupGround(){
  ground = Bodies.rectangle(500, 600, 1000, 40, {
    isStatic: true, angle: 0
  });
  World.add(engine.world, [ground]);
}

////////////////////////////////////////////////////////////////
function drawGround(){
  push();
  fill(128);
  drawVertices(ground.vertices);
  pop();
}
////////////////////////////////////////////////////////////////
/*
Step 1: Amend the setupPropeller() function in physics.js to setup 
a static body of type rectangle at location (150, 480) of size (200, 15),
 similar to how the ground is created. Use the global variable propeller for
this. The initial angle is equal to the global variable angle which we provided.
 Add the propeller to the world.
*/ 
function setupPropeller(){
  // your code here
  propeller = Bodies.rectangle(150, 480, 200, 15, {
     isStatic: true,angle: angle
  });
  World.add(engine.world, [propeller]);
  
}
////////////////////////////////////////////////////////////////
/*
Step 2: In the drawPropeller() function 
* set the angle of the propeller  equal to the global variable angle. 
* Set the angular velocity equal to the  global variable angleSpeed already provided for you. 
* Update the variable  angle by angleSpeed. This will make sure the propeller actually moves at a 
rate of angleSpeed between frames. 
* Draw the propeller using the  drawVertices() helper function just like in the drawGround() function. 
* In sketch.js, amend the keyPressed() function so that when the left arrow is
pressed, the angle speed is incremented by 0.01. Do the opposite when the 
right arrow is pressed. If you’ve done things right when you start your 
sketch you should be able to control the propeller on screen using the left 
and right arrows.
*/ 
//updates and draws the propeller
function drawPropeller(){
  push();
  // your code here
  Body.setAngle(propeller, angle);
  Body.setAngularVelocity(propeller, angleSpeed); 
  angle += angleSpeed;
  fill(255);
  drawVertices(propeller.vertices);
  
  pop();
}
////////////////////////////////////////////////////////////////
function setupBird(){
  var bird = Bodies.circle(mouseX, mouseY, 20, {friction: 0,
      restitution: 0.95 });
  Matter.Body.setMass(bird, bird.mass*10);
  World.add(engine.world, [bird]);
  birds.push(bird);
}
////////////////////////////////////////////////////////////////
/*
Step 3: When ‘b’ is pressed a bird is created wherever the mouse is by 
calling the setupBird() function. Study that function. At the moment the
program does not draw birds. Amend the drawBirds() function to loop over 
the birds array and draw them using the drawVertices() helper function. 
Use the isOffScreen() function to check if the bird has left the screen and, 
if it has, remove it from the physics world using the removeFromWorld() 
helper function provided and from the array. Remember to also decrement your
for-loop counter in order not to break your code! Pressing ‘b’ should now 
create a new bird where the mouse is which flies away upon impact with the 
moving propeller.
*/ 


function drawBirds(){
  push();
  //your code here
  fill(255,0,0);
  for (var i=0; i<birds.length; i++) {
    drawVertices(birds[i].vertices);
    if (isOffScreen(birds[i])) {
      removeFromWorld(birds[i]);
      birds.splice(i, 1);   
    }
  }
  pop();
}
////////////////////////////////////////////////////////////////
//creates a tower of boxes
function setupTower(){
  /*
  Step 4: Amend the setupTower() function to create a tower of boxes as 
  shown in the picture above. Tower should be six boxes high, three boxes
  wide. Each box should be of size 80x80 pixels. (Hint: Create a nested for
  loop and push bodies of type rectangle on the boxes array provided). 
  Also push a random shades of green onto the colors array. We’ll use 
  those colors to draw the boxes later. Remember to add the boxes to the 
  world.
  */ 
  //you code here
  stack = Composites.stack(700, 220, 3, 6, 0, 0, function(x, y) {
    return Bodies.rectangle(x, y, 80, 80, {
      render: {
        fillStyle: 'blue',
        strokeStyle: 'black'
      }
    });
  }
  );
  World.add(engine.world, [stack]);
  // colors
  for(var i=0; i<6; i++) {
    for (var j=0; j<3; j++) {
      colors.push(255*random(0,1));
    }
  }  
}
////////////////////////////////////////////////////////////////
//draws tower of boxes
/*
Step 5: In the drawTower() function loop over the boxes array and 
draw each box using the drawVertices() helper function. Remember 
to use the random colors you created inside the colors array. 
You should now see a tower of boxes in different shades of green like in the image above.*/ 

function drawTower(){
  //your code here
  for (var i=0; i<stack.bodies.length; i++) {
    fill(0, colors[i],0);
    drawVertices(stack.bodies[i].vertices);
    if (isOffScreen(stack.bodies[i])) {
      removeFromWorld(stack.bodies[i]);
      stack.bodies.splice(i, 1);   
    }
  }


}
////////////////////////////////////////////////////////////////
/*
Step 6: Amend the setupSlingshot() function to initialise the global 
variable slingshotBird as a body of type circle in a similar place as shown 
in the image above. Give the circle zero friction and a restitution of 0.95. 
Set the mass of the slingshotBird as ten times its original mass, just like 
we have done for each of the birds in the setupBird() function.
Initialise also the global variable slingshotConstraint as a constraint that
behaves and looks like the one shown above. Give it a stiffness of 0.01 and 
damping of 0.0001.
Remember to add both the bird and the constraint to the world and make sure 
they appear where they are in the image above.

*/ 
function setupSlingshot(){
//your code here
slingshotBird = Bodies.circle(200,250,20, {friction: 0, restitution: 0.95});
Matter.Body.setMass(slingshotBird, slingshotBird.mass*10);
  // System : A body constrained by a fixed point more elastically
  slingshotConstraint = Constraint.create({
      // No bodyA. We want poly2 to be attached to a fixed point in the world
      pointA: {x:200, y:200}, //grab from its center
      bodyB: slingshotBird,
      pointB: {x:-0, y:0}, //Coordinates relative to the center
      stiffness:0.01, // Makes the join elastic
      damping: 0.0001
  })
  World.add(engine.world, [slingshotBird, slingshotConstraint]);




}
////////////////////////////////////////////////////////////////

/*
Step 7: Amend the drawSlingshot() function and use the drawVertices() 
and drawConstraint() helper functions to draw the slingshot bird and 
slingshot constraint. If you’ve done things right you should now be able 
to control the slingshot with the mouse. Drag to extend, release mouse to 
release bird. Pressing ‘r’ resets the slingshot.


*/ 
//draws slingshot bird and its constraint
function drawSlingshot(){
  push();
  // your code here
  fill(255,165,0);
  drawVertices(slingshotBird.vertices);
  stroke(128);
  strokeWeight(3);
  drawConstraint(slingshotConstraint);
  pop();
}
/////////////////////////////////////////////////////////////////
function setupMouseInteraction(){
  var mouse = Mouse.create(canvas.elt);
  var mouseParams = {
    mouse: mouse,
    constraint: { stiffness: 0.05 }
  }
  mouseConstraint = MouseConstraint.create(engine, mouseParams);
  mouseConstraint.mouse.pixelRatio = pixelDensity();
  World.add(engine.world, mouseConstraint);
}
