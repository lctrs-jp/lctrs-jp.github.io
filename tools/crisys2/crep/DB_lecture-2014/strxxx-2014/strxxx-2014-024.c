File Edit Options Buffers Tools C Help
#include<string.h>
#include<stdio.h>

void mystrcpy(char trg[],char src[])
{
  int i;

  for(i=0;src[i]!='\0';i++)
    trg[i]=src[i];
  trg[i]='\0';

}

void mystrcat(char trg[],char src[])
{
  int i,k;

  for(i=0;trg[i]!='\0';i++)
     ;
  for(k=0;src[k]!='\0';i++,k++)
    trg[i-1]=src[k];
  trg[i]='\0';
}

int mystrlen(char trg[])
{
  int i=0;

  for(i=0;trg[i]!='\0';i++)
   ;
  return i;
}

int main(void)
{
  char str1[80],str2[80];
  int i;

  printf("第一の文字列を入力してください:");
  fgets(str1,80,stdin);
  printf("第二の文字列を入力してください:");
  fgets(str2,80,stdin);

  printf("%sは%d文字の長さです\n",str1,mystrlen(str1));
  printf("%sは%d文字の長さです\n",str2,mystrlen(str2));

  i=strcmp(str1,str2);
  if(!i)
    printf("文字列は等しい\n");
  else if(i<0)
    printf("%sは%sより小さい\n",str1,str2);
  else
    printf("%sは%sより大きい\n",str1,str2);

  if((mystrlen(str1)+mystrlen(str2))<80){
    mystrcat(str1,str2);
    printf("%s\n",str1);
  }

  mystrcpy(str1,str2);
  printf("%s %s\n",str1,str2);

  return 0;
}