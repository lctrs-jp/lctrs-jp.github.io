#include <string.h>
#include <stdio.h>

int mystrlen(char str[80]);

void mystrcpy(char cpy[80],char str[80]);

void mystrcat(char str1[80],char str2[80]);

int mystrcmp(char str1[80],char str2[80]);

int main()
{
  char str1[80],str2[80];
  int i;

  printf("第一の文字列を入力してください: ");
  fgets(str1,80,stdin);
  printf("第二の文字列を入力してください: ");
  fgets(str2,80,stdin);

  /*文字の長さを確認します。*/
  printf("%s は　%d 文字の長さです。\n",str1,mystrlen(str1));
  printf("%s は　%d 文字の長さです。\n",str2,mystrlen(str2));

  i=mystrcmp(str1,str2);
  if (!i)
    printf("文字列は等しい\n");
  else if (i<0)
    printf("%sは%sより小さい\n",str1,str2);
  else
    printf("%sは%sより大きい\n",str1,str2);

  if ((strlen(str1)+strlen(str2))<80){
    mystrcat(str1,str2);
    printf("%s %s",str1,str2);
  }
  mystrcpy(str1,str2);
  printf("%s %s",str1,str2);

  return 0;
}

int mystrlen(char str[80])
{
  int i;
  i=0;
  while(str[i+1])
    i=i+1;
  return i;
}

void mystrcpy(char cpy[80],char str[80])
{
  int i;
  for(i=0;str[i];i++){
    cpy[i]=str[i];
  }
  cpy[i]='\0';
}

void mystrcat(char str1[80],char str2[80])
{
  int i,j;
  i=0;
  while(str1[i])
    i=i+1;
  j=0;
  while(str1[j]){
    str1[i+j-1]=str2[j];
    j++;
  }
}

int mystrcmp(char str1[80],char str2[80])
{
  int i,j;
  i=0,j=1;
  while(str1[i]==str2[i]){
    if(str1[i]=='\0'){
      if(str2[i]=='\0'){
        j=0;
        break;
      }
    }
    i++;
  }

  if(j==1){
    if (str1[i]<str2[i]){
      j=-1;
    }
  }
  return j;
}
