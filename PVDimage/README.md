# Image Steganography Project 

Showcasing steganography methods to hide information inside images.

Group Name: 3.HoI.HossainR

Names: Isaac Ho, Rafayet Hossain

[Presentation](PRESENTATION.md)

[Homework](HOMEWORK.md)

[Worklogs](WORKLOG.md)

## Installation

Requires Processing 4 (latest version tested 4.2): https://processing.org/download

Add any images (.png, .jpg, .gif, .tga) to PVD/data

On processing open PVD.pde, and change setting variables as needed (lines 3-16):
```processing
// Name of file that is being encoded
String imageName = "ducks.png";
// Message to encode
String textToEncode = "This is being encoded using PVD encoding thing";
// Name of file that has or will have encoded text
String modImageName = "modifiedducks.png";

//ENCODE: encoder mode, needs imageName, textToEncode, and modImageName for saving
//DECODE: decoder mode, needs modImageName, prints text.
char MODE = ENCODE;

//GRAYSCALE: encode using grayscale pixel method
//COLOR    : encode using colored pixel method
char IMGTYPE = GRAYSCALE;
```

Press run.
