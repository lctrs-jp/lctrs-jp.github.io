#include<stdio.h>
#include<string.h>

int main()
{
  char str[5];
  int i,j,k=0,l,total=0;

  printf("文字列を入力してください（"A"～"ZZZZZ"）。");
  gets (str);

  for (i=0;i<strlen(str); i++){
    j = str[i] - 'A'+1;
    l =1 ;
    for(k = strlen(str)-i;k>1;k--)
      l = l*26;
    total = total+l*j;
  }

  printf("入力された文字列の26進数表示:%d\n",total);
  return 0;
}
