// Image of Husky Creative commons from Wikipedia:
// https://en.wikipedia.org/wiki/Dog#/media/File:Siberian_Husky_pho.jpg
var imgIn;
var matrix = [
    [1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64],
    [1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64],
    [1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64],
    [1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64],
    [1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64],
    [1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64],
    [1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64],
    [1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64, 1/64]
];

var currentFilter = "sepia";


/////////////////////////////////////////////////////////////////
function preload() {
    imgIn = loadImage("assets/husky.jpg");
}
/////////////////////////////////////////////////////////////////
function setup() {
    createCanvas((imgIn.width * 2), imgIn.height);
}
/////////////////////////////////////////////////////////////////
function draw() {
    background(125);
    image(imgIn, 0, 0);
    if (currentFilter === "sepia") {
      image(sepiaFilter(imgIn), imgIn.width, 0);
    } else if (currentFilter === "darkCorners") {
        image(darkCorners(imgIn), imgIn.width, 0);
    } else if (currentFilter === "radialBlur") {
        image(radialBlurFilter(imgIn), imgIn.width, 0);
    } else if (currentFilter === "border") {
        image(borderFilter(imgIn), imgIn.width, 0);
    }
    noLoop();
}
/////////////////////////////////////////////////////////////////
function mousePressed(){
  loop();
}
/////////////////////////////////////////////////////////////////
function earlyBirdFilter(img){
  var resultImg = createImage(imgIn.width, imgIn.height);
  resultImg = sepiaFilter(imgIn)
  // resultImg = darkCorners(resultImg);
  resultImg = radialBlurFilter(resultImg);
  // resultImg = borderFilter(resultImg)
  return resultImg;
}

function sepiaFilter(img) {
  var resultImg = createImage(img.width, img.height);
  img.loadPixels();
  resultImg.loadPixels();
  for (var i = 0; i < img.pixels.length; i += 4) {
    var r = img.pixels[i];
    var g = img.pixels[i + 1];
    var b = img.pixels[i + 2];
    resultImg.pixels[i] = (r * .393) + (g * .769) + (b * .189);
    resultImg.pixels[i + 1] = (r * .349) + (g * .686) + (b * .168);
    resultImg.pixels[i + 2] = (r * .272) + (g * .534) + (b * .131);
    resultImg.pixels[i + 3] = img.pixels[i + 3];
  }
  resultImg.updatePixels();
  return resultImg;
}

function darkCorners(img) {
  var resultImg = createImage(img.width, img.height);
  img.loadPixels();
  resultImg.loadPixels();
  var centerX = img.width / 2;
  var centerY = img.height / 2;
  for (var y = 0; y < img.height; y++) {
    for (var x = 0; x < img.width; x++) {
      var distance = dist(x, y, centerX, centerY);
      var dynLum = map(distance, 0, 450, 1, 0);
      dynLum = constrain(dynLum, 0.4, 2);
      var index = (x + y * img.width) * 4;
      resultImg.pixels[index] = img.pixels[index] * dynLum;
      resultImg.pixels[index + 1] = img.pixels[index + 1] * dynLum;
      resultImg.pixels[index + 2] = img.pixels[index + 2] * dynLum;
      resultImg.pixels[index + 3] = img.pixels[index + 3];
    }
  }
  resultImg.updatePixels();
  return resultImg;
}

function radialBlurFilter(img) {
  var resultImg = createImage(img.width, img.height);
  resultImg = img.get();
  var kernelSize = 15;
  var kernel = [];
  for (var i = 0; i < kernelSize * kernelSize; i++) {
    var x = i % kernelSize;
    var y = floor(i / kernelSize);
    var d = dist(x, y, kernelSize / 2, kernelSize / 2);
    var v = map(d, kernelSize / 2, 0, 1, 0.5);
    kernel.push(v);
  }
  var centerX = img.width / 2;
  var centerY = img.height / 2;
  resultImg.loadPixels();
  for (var y = 0; y < img.height; y++) {
    for (var x = 0; x < img.width; x++) {
      var index = (x + y * img.width) * 4;
      var d = dist(x, y, centerX, centerY);
      var dynBlur = constrain(map(d, 0, min(img.width, img.height) / 2, 1, 0), 0, 1);
      var c = convolution(img, x, y, kernel, kernelSize, 0);
      resultImg.pixels[index + 0] = c[0] * dynBlur + img.pixels[index + 0] * (1 - dynBlur);
      resultImg.pixels[index + 1] = c[1] * dynBlur + img.pixels[index + 1] * (1 - dynBlur);
      resultImg.pixels[index + 2] = c[2] * dynBlur + img.pixels[index + 2] * (1 - dynBlur);
      resultImg.pixels[index + 3] = img.pixels[index + 3];
    }
  }
  resultImg.updatePixels();
  return resultImg;
}



function convolution(img, x, y, kernel, kernelSize, offset) {
  var r, g, b, a;
  r = g = b = a = 0;
  var kernelHalf = floor(kernelSize / 2);
  for (var ky = 0; ky < kernelSize; ky++) {
    for (var kx = 0; kx < kernelSize; kx++) {
      var posx = x + kx - kernelHalf;
      var posy = y + ky - kernelHalf;
      if (posx >= 0 && posx < img.width && posy >= 0 && posy < img.height) {
        var index = (posx + posy * img.width) * 4;
        var weight = kernel[kx + ky * kernelSize];
        r += img.pixels[index] * weight;
        g += img.pixels[index + 1] * weight;
        b += img.pixels[index + 2] * weight;
        a += img.pixels[index + 3] * weight;
      }
    }
  }
  r = constrain(r+offset, 0, 255);
  g = constrain(g+offset, 0, 255);
  b = constrain(b+offset, 0, 255);
  a = constrain(a+offset, 0, 255);
  return [r, g, b, a];
}

function borderFilter(img) {
  var buffer = createGraphics(img.width, img.height);
  buffer.image(img, 0, 0);
  buffer.strokeWeight(20);
  buffer.stroke(0);
  buffer.noFill();
  buffer.rect(0, 0, img.width, img.height, 30);
  return buffer;
}


function keyPressed() {
  if (key === '1') {
      currentFilter = "sepia";
  } else if (key === '2') {
      currentFilter = "darkCorners";
  } else if (key === '3') {
      currentFilter = "radialBlur";
  } else if (key === '4') {
      currentFilter = "border";
  }
  loop();
}








