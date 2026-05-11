#include <string.h>
#include <stdio.h>
double mystrcpy();
double mystrcat();
double mystrlen();

int main()
{
  char str1[80],str2[80];
  int i;

  printf("第一の文字列を入力してください:");
  fgets(str1,80,stdin);
  printf("第二の文字列を入力してください:");
  fgets(str2,80,stdin);

  printf("%s は %d 文字の長さです\n",str1,mystrlen(str1));
  printf("%s は %d 文字の長さです\n",str2,mystrlen(str2));

  i=strcmp(str1,str2);
  if(!i)
    printf("文字列は等しい\n");
  else if(i<0)
    printf("%s は %s より小さい\n",str1,str2);
  else
    printf("%s は %s より大きい\n",str1,str2);

if((mystrlen(str1)+mystrlen(str2))<80){
  mystrcat(str1,str2);
  printf("%s\n",str1);
}
  mystrcpy(str1,str2);
  printf("%s %s\n",str1,str2);

  return 0;
}


double mystrlen(const str1)
{
  int l;
  l=0;
  while(str1!='\0') {
      l++;  
  }
  return l;
  }

double mystrcpy(str1,str2)
{
  char j;
  j=str2;

  while(str2!='\0'){
    str1=str2;
      str1++;
      str2++;
  }
  str1='\0';
  return j;
  }

double mystrcat(str1,str2)
{
  while(str1!='\0')
    str1++;

  while(str2!='\0'){
    str1=str2;
  str1++;
  str2++;
  }
  return str1;
}
