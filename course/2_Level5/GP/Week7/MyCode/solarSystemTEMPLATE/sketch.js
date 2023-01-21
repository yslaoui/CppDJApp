/*
Step 1:  Create an earth of color blue and size 80. Move it to orbit 300 pixels. Hint: You should only use transformations to achieve this. 

Step 2: Rotate the earth around the sun at velocity "speed". Make sure you use the radians() function inside the rotate() call.

Step 3: Make the earth spin around its axis at velocity "speed" too. You should now have an earth that rotates around its axis and around the sun.

Step 4: Add a moon of color white and size 30 to the earth at an orbit of 100 pixels. Make the moon rotate at velocity -speed*2 so it spins the opposite way to the way the earth rotates. Make sure that your moon, while spinning around the earth, always shows the same side to earthlings (ie earthlings should not be able to see the so-called 'dark side of the moon').

Step 5: Make the sun spin around its axis, as it really does, at a slow speed/3.

Step 6: Extend the sketch by adding one more celestial body by implementing one of the ideas for further development. 

Step 7: Submit the file to the 'Staff Graded Assignment: Mid-term assignment submissions' located in the end of week 10.  

Ideas for further development:
  What if the moon had an asteroid that was stuck in orbit around the moon? Can you add a smaller celestial body that is rotating around the moon.

Pretend that earth, like Mars, has two moons. Can you add another different sized moon that rotates around the earth at a different speed with a different distance from the earth? This moon should also only show the one side to the earth.      

*/ 


var speed;

function setup() {
    createCanvas(1500, 1500);
}

function draw() {
    background(0);
    speed = frameCount;

    push();
    translate(width/2, height/2);
    // SUN
    var sunSpeed = speed/3;
    rotate(radians(sunSpeed%360));
    celestialObj(color(255,150,0), 200); 
        // EARTH
        push();
        rotate(radians(speed%360));
        translate(0,-300);
        celestialObj(color(0,0,255), 80); 
            // MOON 1
            push();
            var moonSpeed = -speed*2;
            rotate(radians(moonSpeed%360));
            translate(0,100);        
            celestialObj(color(255,255,255), 30); 
                // Asteroid
                push();
                var asteroidSpeed = 10*speed;
                rotate(radians(asteroidSpeed%360));
                translate(0,30);        
                celestialObj(color(180,20,87), 25); 
                pop();                                
            pop();  
            
            // Extension: MOON 2
            push();
            var moonSpeed = -speed*4;
            rotate(radians(moonSpeed%360));
            translate(100,100);        
            celestialObj(color(255,255,255), 30);                   
            pop();  
                        
        pop();
    pop();

}

function celestialObj(c, size){
    strokeWeight(5);
    fill(c);
    stroke(0);
    ellipse(0, 0, size, size);
    line(0, 0, size/2, 0);
}
