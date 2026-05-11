#include <string.h>
#include <stdio.h>

int mystrlen(char str[]);
void mystrcpy(char tag[],char src[]);
void mystrcat(char tag[],char src[]);

int main(void)
{
  char str1[80],str2[80];
  int i;
  printf("第１の文字列を入力してください： ");
  gets(str1);
  printf("第２の文字列を入力してください： ");
  gets(str2);

  printf("%sは%d文字の長さです\n",str1,mystrlen(str1));
  printf("%sは%d文字の長さです\n",str2,mystrlen(str2));

  i=strcmp(str1,str2);
  if (!i)
    printf("文字列は等しい\n");
  else if (i<0)
    printf("%s は %s より小さい\n",str1,str2);
  else
    printf("%s は %s より大きい\n",str1,str2);

  if ((mystrlen(str1)+mystrlen(str2))<80)
    {
      mystrcat(str1,str2);
      printf("%s\n",str1);
    }

  mystrcpy(str1,str2);
  printf("%s %s\n",str1,str2);

  return 0;
}

int mystrlen(char str[])
{
  int i=0,l=0;


  while(str[i])
    {
      l++;
      i++;
    }

  return l;
}

void mystrcpy(char tag[],char src[])
{
  int i,j=0;
  i=mystrlen(src);

  while(j<=i)
    {
      tag[j]=src[j];
      j++;
    }
  return;
}

void mystrcat(char tag[],char src[])
{
  int i,j,k=0;
  i=mystrlen(tag);
  j=mystrlen(src);

  while(k<=j)
    {
      tag[i+k]=src[k];
      k++;
    }
  return;
}
