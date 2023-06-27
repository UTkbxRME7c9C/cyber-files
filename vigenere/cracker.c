#include "funcs.h"

int main(int argc, char *argv[]){
	if (argc!=2){
		printf("add file names (cipher)\n");
		exit(1);
	}
  cipher *txtsum = malloc(sizeof(cipher));
  cipher *alicesum = malloc(sizeof(cipher));
  FILE* alice = fopen("alice.txt","r");
  if (alice == NULL){
    printf("No alice.txt found \n");
  }
  countLetters(alicesum, alice);
  fclose(alice);

  char *text;
  FILE* ciphertxt = fopen(argv[1],"r");
  fseek(ciphertxt, 0, SEEK_END);
  int length = ftell(ciphertxt);
  fseek(ciphertxt, 0, SEEK_SET);
  text = malloc(length);
  fread(text,1,length,ciphertxt);
  fclose(ciphertxt);
  for(int i = 0; i < strlen(text); i++){
    if (text[i]=='\n') text[i]='\0';
  }
  setupString(text);

  char *txtcpy = strdup(text);
  double bestfreq = 1.0;

  char *realtext = strdup(text);
  double realfreq = 1;

  int boxlen = 10;
  char boxes[boxlen][strlen(text)];


	for(int i = 1; i <= boxlen; i++){
    for (int j = 0; j < strlen(text); j++){
      strncat(boxes[j%i], &text[j],1);
    }
    for(int a = 0; a < i; a++){
      for(int counter = 0; counter < 26; counter++){
        for(int b = 0; b < strlen(boxes[a]); b++){
          boxes[a][b] = 'A'+((boxes[a][b]-'A'+1)%26);
        }
				//printf("%s\n\n",boxes[a]);
        countForString(txtsum, boxes[a]);
				//printf("%f\n\n",getDist(alicesum, txtsum));
        if (bestfreq > getDist(alicesum, txtsum)){
          strcpy(txtcpy, boxes[a]);
          bestfreq = getDist(alicesum, txtsum);
        }
        resetCipher(txtsum);
      }
      strcpy(boxes[a],txtcpy);
			bestfreq = 1;
    }
    memset(txtcpy,0,sizeof(*txtcpy));
		int tee=-1;
    for(int j = 0; j < strlen(text); j++){
			if((j%i)==0) tee++;
			strncat(txtcpy, &boxes[j%i][tee], 1);
    }
    countForString(txtsum, txtcpy);
		if (realfreq > getDist(alicesum, txtsum)){
			strcpy(realtext, txtcpy);
			realfreq = getDist(alicesum, txtsum);
		}
		resetCipher(txtsum);
    for(int a = 0; a < i; a++){
      memset(boxes[a],0,sizeof(boxes[a]));
    }
  }
	printf("%s\n\n",realtext);
  free(text);
  free(alicesum);
	free(txtsum);
}
