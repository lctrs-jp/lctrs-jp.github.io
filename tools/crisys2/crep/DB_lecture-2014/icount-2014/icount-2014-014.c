#include <stdio.h>
#include <string.h>

int main(void)
{
  char a[100];
  int i, j, k;
  
  //文字列を入力
  printf("文字列を入力してください:");
  fgets(a, 100, stdin);

  //数字のみの文字列にする
  for(j=0,k=0; j<10; j++){
    for(i=0; i<strlen(a); i++){
      if(a[i]==j+48){
	k=k+1;}}
      printf("%dは%d個含まれています。\n",j,k);
      k=0;}

  return 0;
}
	
