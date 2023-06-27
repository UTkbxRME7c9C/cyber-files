#include "funcs.h"
#include "ctype.h"

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
}
void countFreq(cipher *test){
  for(int i = 0; i < 26; i++){
    test->Lfreq[i] = (double)test->Lcount[i]/test->total;
  }
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
    //if (one->Lfreq[i] != 0 && two->Lfreq[i] != 0)
		result += pow((one->Lfreq[i])-(two->Lfreq[i]), 2.0);
	}
	result = sqrt(result);
	return result;
}
