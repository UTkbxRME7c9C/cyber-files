// Encoding and Decoding text onto image using PVD

// Name of file that is being encoded
String imageName = "ducks.png";
// Message to encode
String textToEncode = "Steganography is the practice of representing information within another message or physical object, in such a manner that the presence of the information is not evident to human inspection.";
// Name of file that has or will have encoded text
String modImageName = "modifiedDucks.png";

//ENCODE: encoder mode, needs imageName, textToEncode, and modImageName for saving
//DECODE: decoder mode, needs modImageName, prints text.
char MODE = DECODE;

//GRAYSCALE: encode using grayscale pixel method
//COLOR    : encode using colored pixel method
char IMGTYPE = COLOR;

PImage img;

void setup(){
  if (MODE == ENCODE){
    // Load image and set window size
    img = loadImage(imageName);
    windowResize(img.width,img.height);
    //Encode text into PImage
    if (IMGTYPE == GRAYSCALE){
      textEncodeGrayscale(img, textToEncode);
    } else {
      textEncodeColor(img, textToEncode);
    }
    //Saves the image
    img.save("data/"+modImageName);
  } else if (MODE == DECODE){
    img = loadImage(modImageName);
    windowResize(img.width,img.height);
    //Decode image and store text into string
    String decoded;
    if (IMGTYPE == GRAYSCALE){
      decoded = textDecodeGrayscale(img);
    } else {
      decoded = textDecodeColor(img);
    }
    //Print text
    println(decoded);
  }
}

void draw(){
  image(img, 0,0);
}
