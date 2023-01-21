function setup() {
    createCanvas(800, 800);
  }
  ////////////////////////////////////////////////////
  function draw() {
    background(255,160,122); // Ligh salmon
    fill(0);
    translate(100,100);
    rect(0,0,200,200);
    push();
    translate(200,200); //You translate from the latest translation point. Translation is transitive
    fill(255,0,0);
    ellipse(0,0,20,20);
    pop();
    // Now we are back to the origin before the push
    fill(255,0,0);
    ellipse(0,0,20,20);
  }