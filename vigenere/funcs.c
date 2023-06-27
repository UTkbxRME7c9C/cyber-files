#include "funcs.h"
#include <math.h>
void countFreq(cipher *test){
  for(int i = 0; i < 26; i++){
    test->Lfreq[i] = (double)test->Lcount[i]/test->total;
  }
}
void countLetters(cipher *test, FILE* filechk){
  char letter = fgetc(filechk);
  while(letter!=EOF){
    if (isalpha(letter)){
      test->total++;
      letter=toupper(letter);
      letter-=65;
      test->Lcount[letter]++;
    }
    letter=fgetc(filechk);
  }
  countFreq(test);
}

void countForString(cipher *test, char *s){
  char tmpchr=0;
  for(int i=0; s[i]!='\0';i++){
    if (isalpha(s[i])){
      test->total++;
      tmpchr = toupper(s[i]);
      tmpchr-=65;
      test->Lcount[tmpchr]++;
    }
  }
  countFreq(test);
}

void resetCipher(cipher *test){
  test->total=0;
  for (int i = 0; i < 26; i++){
    test->Lcount[i]=0;
    test->Lfreq[i]=0;
  }
}

double getDist(cipher *one, cipher *two){
	double result = 0.0;
	for (int i = 0; i < 26; i++){
		result += pow((one->Lfreq[i])-(two->Lfreq[i]), 2.0);
	}
	result = sqrt(result);
	return result;
}

void setupString(char *msg){
	int j = 0;
	for(int i = 0; i < strlen(msg); i++){
		if (isalpha(msg[i])){
			msg[j] = toupper(msg[i]);
			j++;
		}
	}
	msg[j]='\0';
}



void encode(char *msg, char *key){
	for(int i = 0;i<strlen(msg);i++){
		msg[i]='A'+(msg[i]+key[i%strlen(key)]+26) % 26;
	}
}

void decode(char *msg, char *key){
	for(int i = 0;i<strlen(msg);i++){
		msg[i]='A'+(msg[i]-key[i%strlen(key)]+26) % 26;
	}
}
