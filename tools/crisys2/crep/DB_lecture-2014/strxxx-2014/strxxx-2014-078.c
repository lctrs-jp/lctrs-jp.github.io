#include <stdio.h>


void mystrcpy(char trg[80],char src[80]){
  int t;
  for(t=0;t<80;t++)
    trg[t]=src[t];
}
void mystrcat(char trg[80],char src[80]){
  int t,s;
  for(s=0;;s++)
  if(trg[s]=='\0')
    break;
  for(t=0;t<80;t++,s++)
    trg[s]=src[t];
}

int mystrlen(char trg[80]){
  int s;
  for(s=0;;s++)
    if(trg[s]=='\0')
      break;
  return s;
}

int main(void)
{
  char str1[80],str2[80];
  int i;

  printf("第１の文字列を入力してください: ");
  gets(str1);
  printf("第２の文字列を入力してください: ");
  gets(str2);

  printf("%sは%d文字の長さです\n",str1,mystrlen(str1));
  printf("%sは%d文字の長さです\n",str2,mystrlen(str2));

  if((mystrlen(str1)+mystrlen(str2))<80){
    mystrcat(str1,str2);
    printf("%s\n",str1);
  }

  mystrcpy(str1,str2);
  printf("%s %s\n",str1,str2);

  return 0;
}

