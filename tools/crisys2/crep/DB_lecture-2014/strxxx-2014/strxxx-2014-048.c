#include<stdio.h>
#include<string.h>
 
int mystrlen(char trg[])
{
  int i=0;
  for(i=0;trg[i]!='\0';i++);
  return i;
}

void mystrcat(char trg[], char src[])
{
  int i=0;
  int len=mystrlen(trg);
  
  for(i=0;src[i]!='\0';i++){
    trg[i+len]=src[i];
  }
  trg[i+len]=src[i];
}

void mystrcpy(char*trg, char*src)
{
  while(*trg++=*src++);
}
int main(void)
{
  char str1[80], str2[80];
  int i;
  
  printf("第1の文字列を入力してください:");
  gets(str1);
  printf("第2の文字列を入力してください:");
  gets(str2);

  printf("%sは%d文字の長さです\n", str1, strlen(str1));
  printf("%sは%d文字の長さです\n", str2, strlen(str2));

  i=strcmp(str1, str2);
  if(i==0)
    printf("文字列は等しい\n");
  else if(i<0)
    printf("%sは%sより小さい\n",str1,str2);
  else
    printf("%sは%sより大きい\n",str1,str2);

  if((mystrlen(str1) + mystrlen(str2))<80){
    mystrcat(str1,str2);
      printf("%s\n",str1);
  }

  mystrcpy(str1, str2);
  printf("%s %s\n",str1,str2);

  return 0;
}
