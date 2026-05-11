#include<string.h>
#include<stdio.h>

void mystrcpy(char trg[],char src[]);
void mystrcat(char trg[],char src[]);
int mystrlen(char trg[]);
int main (void)
{
  char str1[80],str2[80];
  int i;

  printf("第一の文字列を入力してください: ");
  fgets(str1,80,stdin);
  printf("第二の文字列を入力してください: ");
  fgets(str2,80,stdin);

  printf("%sは %d文字の長さです \n",str1,mystrlen(str1)-1); 
  printf("%sは %d文字の長さです \n",str2,mystrlen(str2)-1);


  i=strcmp(str1,str2);
  if (!i)
    printf("文字列は等しい\n");
  else if(i<0)
    printf("%sは%sより小さい\n",str1,str2);
  else
    printf("%sは%sより大きい\n",str1,str2);


  if ((strlen(str1)+strlen(str2))<80)
    {  
      mystrcat(str1,str2);
  printf("%s\n",str1);
    }

  mystrcpy(str1,str2);
  printf("%s\n",str2);
    printf("%s %s\n",str1,str2);
  return 0;
}


void mystrcpy(char trg[],char src[])
{
  int k;
  for (k=0;k<80;k++)
    src[k]=trg[k];
}
void mystrcat(char trg[],char src[])
{
  int i;
  int len;

  len=mystrlen(trg);
  for(i=0;src[i]!='\0';i++,len++)
    {trg[len]=src[i];}
  trg[len]='\0';
}

int mystrlen(char trg[])
{
  int a=0;
  for(a=0;trg[a]!='\0';a++);
       return a;

}
