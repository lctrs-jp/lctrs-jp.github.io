#include<string.h>
#include<stdio.h>

void mystrcpy(char trg[], char src[]);
void mystrcat(char trg[], char src[]);

int mystrlen(char trg[]);
int main()
{
  char str1[80], str2[80];
  int i, a;

  printf("第一の文字列を入力してください: ");
  gets(str1);
  printf("第二の文字列を入力してください: ");
  gets(str2);

  /*文字列の長さを確認する*/
  printf("%s は %d 文字の長さです\n", str1, mystrlen(str2));

  /*十分なスペースがあれば、str2をstr1の最後にに連結する*/
  if((mystrlen(str1) + mystrlen(str2)) < 80) {
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }

  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}

/*str2をsttiにコピーする関数を定義する*/
void mystrcpy(char trg[], char src[]){
  int i;
  i = 0;
  while( i < 80 ){
    trg[i] = src[i];
    i++;
  }
}

/*str2をstr1に付与する関数を定義する*/
void mystrcat(char trg[], char src[]){
  int i, a;
  i = mystrlen(trg);
  a = 0;
  while( i < 80, a < 80 ){
    trg[i] = src[a];
  i++;
  a++;
  }
}
int mystrlen(char trg[]){
  int i;
  i = 0;
  while(trg[i]){
    i++;
  }
  return i;
}
