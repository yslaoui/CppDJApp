function setup() {
    createCanvas(900, 600);
    background(0);
    angleMode(DEGREES);
}

function draw() {
    background(0);
    stroke(255);

    translate(0, height/2);

    beginShape();
    for (var x=0; x<width; x++) {
        var wave1 = sin(x+frameCount) * height/4;
        var wave2 = sin(x*10+frameCount) * height/20;
        var wave3 = noise(x/10+frameCount/100)*200;
        
        noFill();
        vertex(x, wave1 + wave2 + wave3);
    }
    endShape();
}
