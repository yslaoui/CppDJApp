var secLength  =  160;
var minLength  =  140;
var hourLength =  90;
var secWidth   =  1;
var minWidth   =  3;
var hourWidth  =  5;
var circleRadius = 400; 



function setup() {
    createCanvas(900, 700);
    background(0);
}

function draw() {
    background(255);
    translate(400,400);
    ellipse(0,0,circleRadius,circleRadius);

    // seconds hand
    strokeWeight(secWidth);
    var secAngle = map(second(),0,60,0,360);
    push();
    stroke(200,0,0);
    rotate(radians(secAngle));
    line(0,0,0,-secLength);
    pop();

    // minutes hand
    strokeWeight(minWidth);
    var minAngle = map(minute(),0,60,0,360);
    push();
    rotate(radians(minAngle));
    line(0,0,0,-minLength);
    pop();

    // hours hand
    strokeWeight(hourWidth);
    var hourAngle = map(hour(),0,12,0,360);
    push();
    rotate(radians(hourAngle));
    line(0,0,0,-hourLength);
        // Hour ellipse
        push(); 
         translate(0, -hourLength + 20);
         ellipse(0,0,20,20);
        pop();
    pop();
    
    // Hour marks
    var tickAngle = 360/12;
    for (var i=0; i<12; i++) {
        push();
        rotate(radians(tickAngle*i));
        translate(0,-circleRadius/2);
        line(0,0,0,20);
        pop();
    } 
    
    

}
