#include <stdio.h>

void mystrcpy(char trg[], char src[]);
int mystrcmp(char trg[], char src[]);
void mystrcat(char trg[], char src[]);
int mystrlen(char trg[]);

int main()
{

  int i ;
  char str1[80], str2[80];

  printf("第一の文字列を入力してください: ");
  gets(str1);
  printf("第二の文字列を入力してください: ");
  gets(str2);

  //文字列の長さを確認する
  printf("%s は %d 文字の長さです\n", str1, mystrlen(str1));
  printf("%s は %d 文字の長さです\n", str2, mystrlen(str2));

  //文字を比較する
  i = mystrcmp(str1, str2);
  if(!i){ 
    printf("文字列は等しい\n");
  } else if(i < 0){
    printf("%s は %s より小さい\n", str1, str2);
  } else {
    printf("%s は %s より大きい\n", str1, str2);
  }

  //十分なスペースがあれば末尾にコピーする
  if(mystrlen(str1) + mystrlen(str2) < 80){
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }

  //str2をstr1にコピー
  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);
  return 0;
}


void mystrcpy(char trg[], char src[])
{
  int i;
  for (i = 0; i < 80 ; i++){
    trg[i] = src[i];
  }
}

int mystrcmp(char trg[], char src[])
{  
  int i;
  for( i = 0; i < 80; i++){
    if(trg[i] < src[i])
      return -1;
    else if(trg[i] > src[i])
      return 1;
    else if(trg[i] == '\0' && src[i] == '\0')
      break;
  }
  return 0;
}


void mystrcat(char trg[], char src[])
{
  int i;
  int j = mystrlen(trg);
  for( i = 0; i < 80; i++)
    trg[j + i] = src[i];

}


int mystrlen(char trg[])
{
  int i;
  for( i = 0; trg[i] != '\0'; i++){}
  return i;
}
