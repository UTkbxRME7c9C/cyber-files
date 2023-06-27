#include "funcs.h"
int main(int argc, char *argv[]){
	if (argc!=3){
		printf("add file names (text1) (text2) \n");
		exit(1);
	}
  cipher *fileone = malloc(sizeof(cipher));
  cipher *filetwo = malloc(sizeof(cipher));
  FILE* file1 = fopen(argv[1],"r");
  FILE* file2 = fopen(argv[2],"r");
  countLetters(fileone, file1);
  countLetters(filetwo, file2);
  countFreq(fileone);
  countFreq(filetwo);
  double num = getDist(fileone, filetwo);
  printf("distance : %f\n", num);
  free(fileone);
  free(filetwo);
  fclose(file1);
  fclose(file2);
}
