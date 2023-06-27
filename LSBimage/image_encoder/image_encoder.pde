import java.util.Arrays;

 //for code that runs one time place all code in setup.
 PImage img;
 
//print the last 4 digits of a binary number
void printBinary(int x){
  for(int i=7; i>=0;i--){
    print((x>>i)&1);
  }
  println();
}
 
 void setup(){
   size(1200,600);
   String message = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+|\':.,?";
   //String message = "The message is encoded using LSBSteganography only when the red/blue values end in 000.";
   img = loadImage("cat.png");

   //to check size for display purposes, if you want to display the image
   //in a processing window
   //println(img.width,img.height);

   //load the image into an array of pixels.
   img.loadPixels();
   //you can use img.pixels[index] to access this array


   //STEP ONE
   //convert the string into an array of ints in the range 0-3
   int[]parts = new int[message.length() * 4];
   
   int index = 0;
   for(int i = 0; i < message.length(); i++){
     char letter = message.charAt(i);
     for(int j = 6; j >= 0; j-=2){
      parts[index] = ((letter>>j)&3);
      index++;
     }
   }
   println(Arrays.toString(parts));
   //add those values to the correct pixels!
   //when the red and blue end in 000, modify the last 2 bits of green.
   //when no more message is left to encode, change the end of the red+blue from 000 to 001.
   index = 0;
   for (int i = 0; i < (img.pixels).length;i++){
     int r = (int)red(img.pixels[i]);
     int g = (int)green(img.pixels[i]);
     int b = (int)blue(img.pixels[i]);

     if((r&7)==0 && (b&7)==0 ){
       if (index < parts.length){
         g &= ~1;
         g &= ~2;
         g |= parts[index];
         index++;
       }else{
         r |= 1;
         b |= 1;
       }
     }
     img.pixels[i] = color(r,g,b);
   }
   //write the pixel array to the image.
   img.updatePixels();
   //save the image to disk.
   img.save("modifiedCat.png");
   exit();
 }
