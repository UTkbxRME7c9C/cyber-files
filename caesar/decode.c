#include "funcs.h"
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	if (argc!=2){
		printf("add file names (cipher)\n");
		exit(1);
	}
  cipher *alicesum = malloc(sizeof(cipher));
  cipher *tmpsum = malloc(sizeof(cipher));
	cipher *tmpsum2 = malloc(sizeof(cipher));

  FILE* alice = fopen("alice_in_wonderland.txt", "r");
  countLetters(alicesum, alice);
  countFreq(alicesum);


  FILE* file = fopen(argv[1],"r");
  fseek(file,0,SEEK_END);
  int len=ftell(file);
  char *filestr = malloc(len);
  fseek(file,0,SEEK_SET);
  fread(filestr,1,len, file);
  double Bestfreq=1;
  char *newfilestr = malloc(len);

	char *reversestr=malloc(len);
	strcpy(reversestr, filestr);
	for(int i = 0; i < strlen(filestr);i++){
		if (isalpha(filestr[i])){
			if (filestr[i] >= 'a' && filestr[i] <= 'z'){
				reversestr[i]= 'z'-((reversestr[i]-'a')%26);
			} else if (filestr[i] >= 'A' && filestr[i] <= 'Z'){
				reversestr[i]= 'Z'-((reversestr[i]-'A')%26);
			}
		}
	}
  for(int a = 0; a < 26;a++){
    for(int i = 0; i < strlen(filestr);i++){
			if (filestr[i] == '\n'){
				reversestr[i] = 0;
				filestr[i]=0;
			}
      if(isalpha(filestr[i])){
        if (filestr[i] >= 'a' && filestr[i] <= 'z'){
					reversestr[i]= 'a'+((reversestr[i]-'a'+1)%26);
          filestr[i]= 'a'+((filestr[i]-'a'+1)%26);
        } else if (filestr[i] >= 'A' && filestr[i] <= 'Z'){
					reversestr[i]= 'A'+((reversestr[i]-'A'+1)%26);
          filestr[i]= 'A'+((filestr[i]-'A'+1)%26);
        }
      }
    }
    countForString(tmpsum, filestr);
		countForString(tmpsum2, reversestr);
    //printf("%s %f \n", filestr, getDist(alicesum, tmpsum));
    if (Bestfreq>getDist(alicesum, tmpsum)){
      Bestfreq = getDist(alicesum, tmpsum);
      strcpy(newfilestr, filestr);
    }
		if (Bestfreq>getDist(alicesum, tmpsum2)){
      Bestfreq = getDist(alicesum, tmpsum2);
      strcpy(newfilestr, reversestr);
    }
    resetCipher(tmpsum);
		resetCipher(tmpsum2);
  }
  printf("%s\n", newfilestr);

  fclose(file);
  fclose(alice);
  free(alicesum);
  free(filestr);
  free(tmpsum);
	free(tmpsum2);
}
