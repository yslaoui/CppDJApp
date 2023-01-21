function setup() {
    createCanvas(900, 600);
    background(0);
}

function draw() {
    background(125);
    var myMouse = createVector(mouseX, mouseY);
    var center = createVector(width/2,height/2);
    myMouse.sub(center);
    translate(width/2, height/2);
    ellipse(0,0,5,5);
    strokeWeight(3);
    fill(255);
    console.log(myMouse);
    line(0,0,myMouse.x, myMouse.y);
}
