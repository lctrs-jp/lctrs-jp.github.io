#include<string.h>
#include<stdio.h>


void mystrcpy(char mys1[], char mys2[]);
void mystrcat(char mys1[], char mys2[]);
int mystlen(char mys1[]);

int main(void)
{
  char str1[80],str2[80];
  int i;

  printf("一つ目の文字を入力してください:");
  fgets(str1,80,stdin);
  printf("二つ目の文字を入力してください:");
  fgets(str2,80,stdin);

  printf("%sは%d文字の長さです\n", str1,mystrlen(str1));
  printf("%sは%d文字の長さです\n", str2,mystrlen(str2));

  i=strcmp(str1,str2);
  if(!i)
    printf("文字列は等しいです\n");
  else if (i < 0)
    printf("%sは%sより小さい\n",str1,str2);
  else
    printf("%sは%sより大きい\n",str2,str1);
  
  if((strlen(str1)+strlen(str2))<80){
    mystrcat(str1,str2);
    printf("%s\n",str1);
  }

  mystrcpy(str1,str2);
  printf("%s %s\n",str1,str2);

  return 0;
}

void mystrcpy(char mys1[],char mys2[])
{
  int i;
  
  for(i=0;mys1[i] || mys2[i];i++)
    mys1[i]=mys2[i];
}

void mystrcat(char mys1[], char mys2[])
{
  int i,j;
  for (i = 0;mys1[i];i++) ;

  for (j = 0;mys2[j];j++) mys1[i++] = mys2[j];
}			    			    

int mystrlen(char mys1[])
{
  int i;
  for (i = 0;mys1[i];i++);

  return i=1;
}
