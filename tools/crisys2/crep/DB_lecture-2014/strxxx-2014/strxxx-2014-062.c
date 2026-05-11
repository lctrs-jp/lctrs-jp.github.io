#include <string.h>
#include <stdio.h>

void mystrcpy(char trg[], char src[]);
void mystrcat(char trg[], char src[]);
int mystrlen(char trg[]);

int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("第1の文字列を入力してください:");
  gets(str1);
  printf("第2の文字列を入力してください:");
  gets(str2);

  printf("%s は %d 文字の長さです\n", str1, mystrlen(str1) );
  printf("%s は %d 文字の長さです\n", str2, mystrlen(str2) );


  i = strcmp(str1, str2);
  if(!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%s は %s より小さい\n", str1, str2);
  else
    printf("%s は %s より大きい\n", str1, str2);


  if( (mystrlen(str1) + mystrlen(str2) ) < 80){
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }


  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}


void mystrcpy(char str1[], char str2[])
{
  int i;

  for(i = 0; str2[i] != '\0'; i++){
    str1[i] = str2[i];
  }
  str1[i] = '\0';

}

void mystrcat(char str1[], char str2[])
{
  int i;

  int len = mystrlen(str1);

  for(i = 0; str2[i] != '\0'; i++){
    str1[i + len] = str2[i];
  }

  str1[i + len] = '\0';

}

int mystrlen(char trg[])
{
  int i = 0;

  for(i = 0; trg[i] != '\0'; i++)
    ;
  return i;

}
