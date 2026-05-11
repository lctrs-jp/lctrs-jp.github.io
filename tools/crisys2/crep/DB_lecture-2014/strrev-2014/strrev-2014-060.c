#include<stdio.h>

void reverse(char trg[],char src[]);

int main(void){
  
  char str[10],rev[10];
  printf("文字列を入力\n");
  scanf("%10s",&str);
  
  reverse(rev,str);
  printf("%s\n%s\n",str,rev);
  return 0;
}
void reverse(char trg[],char src[]){
  int i,j;
  for(i = 0;src[i];i++);
  trg[i] = src[i];
  for(j = 0;j < i;j++){
    trg[j] = src[(i-1) - j];
  }
  return;
}
