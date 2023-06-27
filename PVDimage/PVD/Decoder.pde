
String textDecodeGrayscale(PImage obs){
  // Load pixel array
  obs.loadPixels();
  // Initialize variables
  int blockRange = 0, large = 0, small = 0, curChar = 0, ccShift = 0, diff = 0;  
  StringBuilder text = new StringBuilder();
  
  // Go through pixel array
  pixiter:
  for(int i = 0; i < ((obs.pixels).length)-1; i+=2){
    int pix1 = (obs.pixels[i])&255;
    int pix2 = (obs.pixels[i+1])&255;
    // Determine the larger and smaller pixels.
    large = (pix1 >= pix2) ? pix1 : pix2;
    small = (pix1 >= pix2) ? pix2 : pix1;
    
    // Calculate difference and the block range.
    diff = large - small;
    for (int k=0; k<ranges.length; k++) {
      if (ranges[k] > diff) {
        blockRange = k-1;
        break;
      }
    }
    // Check if the pixels are able to have encoded data. If not, skip.
    if (((255 - large) < (ranges[blockRange+1] - ranges[blockRange]))
       || (small < (ranges[blockRange+1] - ranges[blockRange]))) {
      continue;
    }
    // Using the block range, go through the amount of bits that are encoded in difference
    for (int j=bitSize[blockRange]-1; j>=0; j--) {
      // Place bit as first bit in character
      curChar = (curChar<<1) | ((diff>>j)&1);
      // Check if eight bits are encoded
      if (ccShift == 7) {
        ccShift = 0;
        // Check if the character is zero. Since a zero character indicates the end of a string, there is no need to go any further.
        if (curChar == 0) break pixiter;
        text.append((char)curChar);
        curChar = 0;
      } else {ccShift++;}
    }
  }
  return text.toString(); 
}

String textDecodeColor(PImage obs){
  obs.loadPixels();
  int blockRange = 0, large = 0, small = 0, curChar = 0, ccShift = 0, diff=0;
  StringBuilder text = new StringBuilder();
  
  pixiter:
  for(int p = 0; p < (obs.pixels).length; p++){
    // Initialize color values
    int red = obs.pixels[p] >> 16 & 0xFF;
    int green = obs.pixels[p] >> 8 & 0xFF;
    int blue = obs.pixels[p] & 0xFF;
    
    // Get the large/small values for red-green
    large = (red >= green) ? red : green;
    small = (red >= green) ? green : red;

    diff = large - small;
    for (int k=0; k<ranges.length; k++) {
      if (ranges[k] > diff) {
        blockRange = k-1;
        break;
      }
    }
    if (((255 - large) >= (ranges[blockRange+1] - ranges[blockRange]))
       && (small >= (ranges[blockRange+1] - ranges[blockRange]))) {
      for (int j=bitSize[blockRange]-1; j>=0; j--) {
        curChar = (curChar<<1) | ((diff>>j)&1);
        if (ccShift == 7) {
          ccShift = 0;
          if (curChar == 0) break pixiter;
          text.append((char)curChar);
          curChar = 0;
        } else {ccShift++;}
      }
    }
    
    // Get the large/small values for green-blue
    large = (blue >= green) ? blue : green;
    small = (blue >= green) ? green : blue;
    
    diff = large - small;
    for (int k=0; k<ranges.length; k++) {
      if (ranges[k] > diff) {
        blockRange = k-1;
        break;
      }
    }
    if (((255 - large) >= (ranges[blockRange+1] - ranges[blockRange]))
       && (small >= (ranges[blockRange+1] - ranges[blockRange]))) {
      for (int j=bitSize[blockRange]-1; j>=0; j--) {
        curChar = (curChar<<1) | ((diff>>j)&1);
        if (ccShift == 7) {
          ccShift = 0;
          if (curChar == 0) break pixiter;
          text.append((char)curChar);
          curChar = 0;
        } else {ccShift++;}
      }
    }
    
  }
  return text.toString(); 
}
