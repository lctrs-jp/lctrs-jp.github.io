#include <stdio.h>

int count(char str)

int main()
{
  char str[];

  printf("文字列を入力してください。:");
  fgets(str,,stdin);

  printf("%d",count(str));
}
return 0;

int count(char str)
{
  int i, j, k[j];
  k[j]=0;

  for (j=45; j<91; j++){
    for (i=0; str[i]!='\0'; i++){
      //同じ文字を数える      
     if (str[i]==j)
       k[j]++;
  if else (str[i]==j+32)
	    k[j]++; }
  }
  //文字数を比較して並び替える
  for (j=45; j<91; j++)
    if (k[j]>k[j+1])
      k[j+1]=k[j];

  return k[j];
}
