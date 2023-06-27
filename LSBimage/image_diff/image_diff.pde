
PImage cat1;
PImage cat2;

void setup(){
 size(1200,600);
 cat1 = loadImage("cat.png");
 cat2 = loadImage("modifiedCat.png");
 
 cat1.loadPixels();
 cat2.loadPixels();
 for(int i = 0; i < (cat1.pixels).length;i++){
   int r = (int)red(cat2.pixels[i]);
   int b = (int)blue(cat2.pixels[i]);
   if ((r&7)==0 && (b&7)==0){
     cat2.pixels[i]=color(0,255,0);
   }
   if (cat1.pixels[i] != cat2.pixels[i]){
     if ((r&7)==1 || (b&7)==1){
       cat2.pixels[i]=color(255,0,255); 
     }
   }
 }
 cat2.updatePixels();
}
void draw(){
  image(cat2,0,0);
}
