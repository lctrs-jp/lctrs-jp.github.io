#include<stdio.h>
#include<string.h>

char mystrcpy(char src[],char trg[]);
char mystrcat(char src[],char trg[]);
int mystrlen(char trg[]);

int main()
{ char src[80];
  char trg[80];
  

  printf("第一の文字列\n");
  gets(trg);
  printf("第二の文字列\n");
  gets(src);

  printf("%sは%d文字の長さです\n",trg,mystrlen(trg));
  printf("%sは%d文字の長さです\n",src,mystrlen(src));
  
  mystrcat(trg,src);
  
  printf("連結した文字列は%sです\n",trg);

  mystrcpy(trg,src);

  printf("コピーした文字列は%s\n",trg);

  return 0;
}


char mystrcpy(char src[], char trg[])
{
  int i;
  
  for( i = 0; src[i] != '\0'; i++){
  
    src[i] = trg[i];
  }
  return src[i];
     }

int mystrlen(char trg[])
{
  int i = 0;

  while( trg[i] !='\0')
    i++;

  return i;

}

char mystrcat(char trg[],char src[])
{
  int i = 0;
  int j = 0;
  while( trg[i] != '\0')
    i++;
  while( src[j] != '\0' ){
    trg[i] = src[j];
    i++;
    j++;
  }
  return trg[i];
 }
