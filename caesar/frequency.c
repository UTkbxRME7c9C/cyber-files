#include "funcs.h"
int main(int argc, char *argv[]){
	if (argc!=2){
		printf("add file names (text)\n");
		exit(1);
	}
  cipher *filesum = malloc(sizeof(cipher));
  FILE* file = fopen(argv[1],"r");
  countLetters(filesum, file);\
  countFreq(filesum);
  for(int i=0; i < 26; i++){
    printf("%c %f\n", (i+65),filesum->Lfreq[i]);
  }
  free(filesum);
  fclose(file);
}
