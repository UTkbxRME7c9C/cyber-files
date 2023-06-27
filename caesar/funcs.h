#ifndef FUNCS_H
#define FUNCS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct cipher{
	double Lfreq[26];
	int Lcount[26];
	int total;
}cipher;

void countLetters(cipher *test, FILE* filechk);

void countFreq(cipher *test);

void countForString(cipher *test, char *s);

void resetCipher(cipher *test);

double getDist(cipher *one, cipher *two);
#endif
