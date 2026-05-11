//10月23日の課題２
//例5.2-1を変更してstrlen(),strcmp(),strcat(),strcpyを
//自作のものに置き換えたプログラム
//文字列１、文字列２の文字数を表示
//文字列２を文字列１の後ろに結合した結果を表示
//文字列２を文字列１にコピーし２つの文字列を表示
//（注）文字列は７９文字まで
#include <stdio.h>
#include <string.h>	//文字列を扱う関数に必要

int mystrlen(char trg[]);
int mystrcmp(char trg1[], char trg2[]);
void mystrcat(char trg[], char src[]);
void mystrcpy(char trg[], char src[]);

int main()
{
  char str1[80], str2[80];
  char *p1, *p2;
  int i;

  //文字列を入力
  printf("第１の文字列を入力してください: ");
  fgets(str1, 80, stdin);
  printf("第２の文字列を入力してください: ");
  fgets(str2, 80, stdin);

  //\nを\0に置き換える
  p1 = strchr(str1, '\n');
  p2 = strchr(str2, '\n');
  if (p1 != NULL){
    *p1 = '\0';
  }
  if (p2 != NULL){
    *p2 = '\0';
  }

  //文字列の長さを確認する
  //  printf("%s は %2d 文字の長さです\n", str1 ,strlen(str1));
  //  printf("%s は %2d 文字の長さです\n", str2 ,strlen(str2));
  printf("%s は %d 文字の長さです\n", str1, mystrlen(str1));
  printf("%s は %d 文字の長さです\n", str2, mystrlen(str2));

  //文字列を比較する
  //  i = strcmp(str1, str2);
  i = mystrcmp(str1, str2);
  if (!i){
    printf("文字列は等しい\n");
  }else if (i < 0){
    printf("%s は %s より小さい\n", str1, str2);
  }else{
    printf("%s は %s より大きい\n", str1, str2);
  }

  //十分なスペースがあれば、str2をstr1の最後に連結する
  //  if ((strlen(str1) + strlen(str2)) < 80){
  //    strcat(str1, str2);
  //    printf("%s\n", str1);
  //  }
  if ((mystrlen(str1) + mystrlen(str2)) < 80){
      mystrcat(str1, str2);
      printf("%s\n", str1);
  }

  //str2をstr1にコピーする
  //  strcpy(str1, str2);
  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}

//受け取った文字列の文字数を返す関数
int mystrlen(char trg[])
{
  int i;

  for (i = 0; i < 80; i++){
    if (trg[i] == '\0'){
      break;
    }
  }

  return i;
}

//文字列を比較して１の方が小さければ-1、同じなら0、１の方が大きければ1を返す関数
int mystrcmp(char trg1[], char trg2[])
{
  int a = 0;
  int i;

  for (i = 0; i < 80; i++){
    if (trg1[i] == trg2[i]){
      continue;
    }else if (trg1[i] < trg2[i]){
      a = -1;
      break;
    }else{
      a = 1;
      break;
    }
  }

  return a;
}

//文字列２を文字列１の後ろに結合する関数
void mystrcat(char trg[], char src[])
{
  int i, len_trg, len_src;

  len_trg = mystrlen(trg);
  len_src = mystrlen(src);
  for (i = 0; i <= len_src; i++){
    trg[i+len_trg] = src[i];
  }
}

//文字列２を文字列１にコピーする関数
void mystrcpy(char trg[], char src[])
{
  int i;
 
  for (i = 0; i <= mystrlen(src); i++){
    trg[i] = src[i];
  }
}
