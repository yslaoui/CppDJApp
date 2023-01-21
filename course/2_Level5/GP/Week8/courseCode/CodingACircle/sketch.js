function setup() {
    createCanvas(900, 600);
    background(0);
    //  By default p5 reads angles in radians. We change that to degrees
    // otherwise we would write radians(theta)
    angleMode(DEGREES);
}

function draw() {
    // background(0);
    // We remove background(0) to keep all the drawn circles
    noStroke()
    translate(width/2, height/2);
    fill(255);
    // We incrememnt the radius to get the archimedian spiral
    var radius = frameCount/10;
    // Framecount changes from 0 to 60 in one second. So theta will increase by 60 degrees every second
    var theta = frameCount;    
    var x = cos(theta) * radius;
    var y = sin(theta) * radius;
    ellipse(x, y, 15, 15);
    

}
