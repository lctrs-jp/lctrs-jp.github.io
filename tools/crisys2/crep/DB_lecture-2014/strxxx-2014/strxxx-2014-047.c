#include<stdio.h>
#include<string.h>

void  mystrcpy(char str1[80], char str2[80]);
void mystrcat(char str1[80],char  str2[80]);
int mystrlen (char str[80]);
int main (void)

{
  char str1[80], str2[80];
  int i;

  printf("第１の文字列を入力してください:");
  gets(str1);
  printf("第２の文字列を入力してください:");
  gets(str2);

  /*文字列の長さを確認する*/
  printf("%s は  %d 文字の長さです\n", str1,mystrlen(str1));
  printf("%s は  %d 文字の長さです\n", str2,mystrlen(str2));

  /*文字の長さを比較する*/
  i= strcmp(str1,str2);
  if(!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%s は %s より小さい\n",str1,str2);
else
    printf("%s は %s より大きい\n",str1,str2);

  /*十分なスペースがあれば、str2をstr1の最後に連結する*/
  if ((mystrlen(str1) +mystrlen(str2) )< 80)
    {mystrcat(str1,str2);      printf("%s\n", str1);
	}

  /*str1をstr2にコピー*/
  mystrcpy(str1,str2);
      printf("%s %s\n", str1, str2);
      return 0;
}
/*自作strcpy*/
void mystrcpy(char str1[80], char str2[80])
{int a;
  a=0 ;
  
  while(a <80)  
{
str1[a] = str2[a];
 a=a++;}

 return ;   }
/*自作strcat*/
void mystrcat(char str1[80],char  str2[80])
{ int k,l,kk;
  kk=0;
  
  for ( k=0 ; str1[k]!='\0' ;k++ )
    {kk=kk++;}
    for(l=0;str2[l]!='\0';l++)
      {
	str1[kk+l]=str2[l];
	if(l>80)
	  break;}
    str1[kk+l]='\0';
      return  ;
}
/*自作strlen*/
int mystrlen (char str[80])
{int n,nn;
  nn=0;
  for(n=0;str[n]!='\0';n++)
    {nn=nn++;}
        return nn;}

