#ifndef FUNCS_H
#define FUNCS_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
typedef struct cipher{
	double Lfreq[26];
	int Lcount[26];
	int total;
}cipher;

void countFreq(cipher *test);

void countLetters(cipher *test, FILE* filechk);

void countForString(cipher *test, char *s);

void resetCipher(cipher *test);

double getDist(cipher *one, cipher *two);
void setupString(char *a);
void encode(char *msg, char *key);
void decode(char *msg, char *key);
#endif
