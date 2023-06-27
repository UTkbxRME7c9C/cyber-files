#include "funcs.h"

int main(int argc, char *argv[]){
	if (argc!=3){
		printf("add file names (cipher) (key)\n");
		exit(1);
	}
  FILE* ciphertxt = fopen(argv[1],"r");
  FILE* keytxt = fopen(argv[2],"r");
  char *text;
  char *key;

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

  fseek(keytxt, 0, SEEK_END);
  length = ftell(keytxt);
  fseek(keytxt, 0, SEEK_SET);
  key = malloc(length);
  fread(key,1,length,keytxt);
  fclose(keytxt);
  for(int i = 0; i < strlen(key); i++){
    if (key[i]=='\n') key[i]='\0';
  }

	decode(text, key);
	printf("%s \n",text);	
}
