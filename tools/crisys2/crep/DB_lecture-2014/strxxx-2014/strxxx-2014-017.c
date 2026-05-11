#include<string.h>
#include<stdio.h>

char mystrcpy (char str1[],char str2[]);
char mystrcat (char str1[],char str2[]);
int mystrlen (char str1[]);

int main (void)
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
    printf("文字列は等し\n");
  else if(i<0)
    printf("%sは%sより小さい\n",str1,str2);
  else
    printf("%sは%sより大きい\n",str1,str2);

  if((mystrlen(str1)+mystrlen(str2))<80){
	mystrcat(str1,str2);
	printf("%s%s\n",str1,str2);
    }

    mystrcpy(str1,str2);
    printf("%s%s\n",str1,str2);

    return 0;
}

char mystrcpy(char str1[],char str2[])
{
  int i;

  for(i=0;i<80;i++)
    str1[i] = str2[i];

  return str1[80],str2[80];
}

char mystrcat (char str1[],char str2[])
{
  int i,j;
  for(i=0;str1[i];i++)
    ;
  for(j=0;str2[j];j++)
    str1[j+1]=str2[j];

  return str1[80],str2[80];
}

int mystrlen (char str1[])
{
  int i;
  for(i=0;str1[i];i++)
    ;
  return i-1;
}
