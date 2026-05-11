#include <stdio.h>
#include <string.h>

void many(char str[]);//もっとも出現回数の多い文字を数える関数

int main(void)
{
  int i, j;
  char test[]="aaabc";
  
  many(test[]);
  printf("最大の文字は:%s\n",test[0]);
  printf("文字の個数は:%d\n",j);

  return 0;
}

void many(char str[])
{
  int i,j,k,l,m;
  m=0;
  j=0;
  for(k='a',l='A'; k='z'; k++,l++){
    for(i=0; str[i]!='\0'; i++){
      if(str[i]=k)
	j=j+1;
      else if(str[i]=l)
	j=j+1;}
    if(j>=m){
      str[0]=str[i];
      m=j;
    }}
  return;
}
