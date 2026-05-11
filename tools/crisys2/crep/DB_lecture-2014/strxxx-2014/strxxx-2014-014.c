#include <stdio.h>
#include <string.h>

void mystrcpy(char trg[], char src[])
{
  int i = 0;
  while( ( trg[i] = src[i] )!= '\0' ){
    i++;
  }
  return void;  
}

void mystrcat(char trg[], char src[])
{
  char * startp = trg;
  trg += strlen(trg);
  strcpy(trg, src);
  return void;
}

int mystrlen(char trg[])
{
  int i = 0;
  while(trg[i] != '\0'){
    i++;
  }
  return i;
}

main()
{
  char str1[80], str2[80];
  int i;

  printf("第一の文字列を入力してください: ");
  gets(str1);
  printf("第二の文字列を入力してください: ");
  gets(str2);

  /* 文字列の長さを比較する */
  printf("%s は %d 文字の長さです\n", str1, mystrlen(str1));
  printf("%s は %d 文字の長さです\n", str2, mystrlen(str2)); 
 
  /* 文字列を比較する */
  i = strcmp(str1, str2);
  if (!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%s は %s より小さい\n", str1, str2);
  else 
    printf("%s は %s より大きい\n", str1, str2);

  /* 十分なスペースがあれば、str2をstr1の最後に連結する */
  if ((strlen(str1) + strlen(str2)) < 80) {
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }
  

  /* str2をstr1にコピーする */
  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}
