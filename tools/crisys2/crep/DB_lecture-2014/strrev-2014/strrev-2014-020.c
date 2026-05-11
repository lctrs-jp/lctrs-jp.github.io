#include<stdio.h>
#include<string.h>

void reverse(char trg[], char src[]);

int main(void) {

  char src[255], trg[255];
  int i;

  printf("文字列を入力してください:");
  fgets (src, 255, stdin );

  for(i = 0;i <= strlen(src); i++) {
    trg[i] = src[strlen(src)-i];
      printf("%c", trg[i]);  
  }
  printf("\n"); 
 return 0;
}
