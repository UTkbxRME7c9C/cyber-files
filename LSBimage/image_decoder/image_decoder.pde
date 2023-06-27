import java.util.Arrays;
import java.util.ArrayList;

PImage img;

void setup(){
 img=loadImage("modifiedCat.png");
 img.loadPixels();
 ArrayList<Integer> parts = new ArrayList<Integer>();
 for (int i = 0; i < (img.pixels).length;i++){
   if((((int)blue(img.pixels[i]))&7)==0 && (((int)red(img.pixels[i]))&7)==0){
      parts.add(((int)green(img.pixels[i]))&3);
   }
 }
 String text = "";
 for(int i = 0; i < parts.size();i+=4){
   int newchar= parts.get(i);
   newchar=(newchar<<2)|parts.get(i+1);
   newchar=(newchar<<2)|parts.get(i+2);
   newchar=(newchar<<2)|parts.get(i+3);
   text=text+((char)newchar);
 }
 println(text);
}

void draw(){
 image(img,0,0, width,height);
 exit();
}
