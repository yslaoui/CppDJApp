let confLocs = [];
let confTheta = [];
let heightSlider;
let speedSlider;



function setup() {
    createCanvas(900, 800, WEBGL);
    for (let i = 0; i < 200; i++) {
        let x = random(-500, 500);
        let y = random(-800, 0);
        let z = random(-500, 500);
        confLocs.push(createVector(x, y, z));
        confTheta.push(random(0, 360));
      }
    
    heightSlider = createSlider(50, 200, 100, 1);
    heightSlider.position(10, 10);
    
    speedSlider = createSlider(0.01, 0.1, 0.05, 0.01);
    speedSlider.position(20, 50);



}

function confetti() {
    for (let i = 0; i < confLocs.length; i++) {
      confLocs[i].y += 1;
      confTheta[i] += 10;
      push();
      translate(confLocs[i].x, confLocs[i].y, confLocs[i].z);
      rotateY(radians(confTheta[i]));
      plane(15, 15);
      pop();
      if (confLocs[i].y > 0) {
        confLocs[i].y = -800;
        }
    }
  }

function draw() {
    
    background(125);
    // Camera
    let radius = 800;
    let camX = sin(frameCount * 0.01) * radius;
    let camZ = cos(frameCount * 0.01) * radius;
    camera(camX, -600, camZ, 0, 0, 0, 0, 1, 0);

    // Material
    normalMaterial();
    noStroke();
    strokeWeight(2);
    angleMode(DEGREES);
    
    let cubeHeight = heightSlider.value()/100;
    let speed = speedSlider.value();
    for (let x = -400; x <= 400; x += 50) {
        for (let z = -400; z <= 400; z += 50) {
          let distance = dist(x, 0, z, 0, 0, 0);
          let length = map(sin(distance + frameCount * speed), -1, 1, 100, 300);
          push();
          translate(x, 0, z);
          box(50, length*cubeHeight, 50);
          pop();
        }
      }
    confetti();
     
      
      
      
      
      
      
    
}
