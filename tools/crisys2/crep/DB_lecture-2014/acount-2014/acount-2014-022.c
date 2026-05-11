#include <stdio.h>

int main()
{
  char str[101];
  int i, j, count[1000];

  printf("文字列を入力してください(長さ100以下): ");
  fgets(str,101,stdin);

  for(i=0; i<='z'; i++)
    for(j=0; str[j]!='\0'; j++)
      if(str[j] == i || str[i] == i+'a'-'A')
	count[i]++;



  printf("最頻出文字は %c\n",);
