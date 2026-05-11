#include<stdio.h>
#include<string.h>

void reverse(char trg[],char src[]);

int main()
{
  char trg[50],src[50];
  printf("数かアルファベットを入力してください");
  fgets(src,50,stdin);

  reverse(trg,src);

  printf("%s\n" , trg);
 
 return 0;
}

void reverse(char trg[],char src[])
{
  int i,j;
  i=strlen(src);
   
  for(j=0;i>=0;i--,j++)
    trg[j]=src[i-1];
  return ;
}

