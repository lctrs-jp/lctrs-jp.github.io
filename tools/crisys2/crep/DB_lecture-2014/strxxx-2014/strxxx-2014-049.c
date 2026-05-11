#include<stdio.h>
#include<string.h>

int mystrlen(char trg[])
{
  int num;
  num = strlen(trg);
  return num;
}

void mystrcat(char trg[],char src[])
{
  strcat(trg,src);
  return;
}

void mystrcpy(char trg[],char src[])
{
  strcpy(trg,src);
  return;
}

int main()
{
  char str1[80], str2[80];
  int i;
  printf("第1の文字列を入力してください:");
  gets(str1);
  printf("第2の文字列を入力してください;");
  gets(str2);
  printf("%sは%d文字の長さです\n",str1,mystrlen(str1));
  printf("%sは%d文字の長さです\n",str2,mystrlen(str2));

  if((mystrlen(str1) + strlen(str2)) < 80){
    mystrcat(str1,str2);
    printf("%s\n",str1);
  }

  mystrcpy(str1,str2);
  printf("%s %s\n", str1, str2);

  return 0;
}
