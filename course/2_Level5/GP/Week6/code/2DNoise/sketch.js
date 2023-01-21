function setup() {
    createCanvas(100, 100);
    background(0);
}

function draw() {
    background(0);
    noiseDetail(7);
    noiseGrid();
}


function noiseGrid() {
    // Give each pixel a random color
    for (var x=0; x<width; x++) {
        for (var y=0; y<innerHeight; y++) {
            var n = noise(x/100,y/100, frameCount/50); //A step of 1 is huge for the noise function so we divide by 100
            var c = map(n,0,1,0,255)
            stroke(c);
            point(x,y);
        }  

    }
}


