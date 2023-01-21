function setup() {
    createCanvas(900, 600);
    background(0);
    randomSeed(0); // The seed starting point of the random function is the same. Therefore the random() function generates teh same series of numbers everytime it is called 
    // ransomSeed(50) would produce a different pattern
}

function draw() {
    var randX = random(0, width); // Random number between 0 and width. can be written as random(width) and the 0 is optionnal
    var randY = random(0, height);

    noStroke();
    fill(random(255), 0, 0, random(255));
    var size= random(10,25);
    ellipse(randX, randY, size, size);

}

var r = random(0,1);
if (r<0.3) {} // X happens with 30% probability
else if (r<0.9) {} // Y happens with 60% probability
else {} // Z happens with 10% probability