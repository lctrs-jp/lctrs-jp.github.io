#include <stdio.h>

void mystrcpy(char trg[],char src[]);
void mystrcat(char trg[],char src[]);
int mystrlen(char trg[]);
void n_remove(char trg[]);

int main() {
  char str1[80];
  char str2[80];
  /*
    getsがコンパイラに弾かれたため、例5.2.1とは異なるがfgetsを用いた
    fgetsを用いると改行コード\nが含まれるため、
    取り除くための関数n_removeを作成している
  */
  printf("第1の文字列を入力してください: ");
  fgets(str1,80,stdin);
  printf("第2の文字列を入力してください: ");
  fgets(str2,80,stdin);

  n_remove(str1);
  n_remove(str2);

  //mystrlen
  printf("%s は %d 文字の長さです\n",str1,mystrlen(str1));
  printf("%s は %d 文字の長さです\n",str2,mystrlen(str2));

  //mystrcmpは無いため、省略

  //mystrcat
  if ((mystrlen(str1)+mystrlen(str2))<80){
    mystrcat(str1,str2);
    printf("%s\n",str1);
  }

  //mystrcpy
  mystrcpy(str1,str2);
  printf("%s %s\n",str1,str2);

  return 0;
}

void mystrcpy(char trg[],char src[]){
  int icpy,jcpy;
  //trgを初期化
  jcpy=mystrlen(trg);//for文の要素に関数を入れてもうまくいかないので変数へ代入し利用
  for(icpy=0;icpy<jcpy;icpy++){
    trg[icpy]='\0';
  }
  //コピー作業
  jcpy=mystrlen(src);
  for(icpy=0;icpy<jcpy;icpy++){
    trg[icpy]=src[icpy];
  }
  return;
}

void mystrcat(char trg[],char src[]){
  int icat;
  int jcat=mystrlen(src);
  int kcat=mystrlen(trg);
  for(icat=0;icat<jcat+1;icat++){//+1はNULL文字用
    trg[icat+kcat]=src[icat];
  }
  return;
}

int mystrlen(char trg[]){
  int ilen;
  for(ilen=0;ilen>=0;ilen++){
    if (trg[ilen]=='\0') {
      return ilen;
    }
  }
}

void n_remove(char trg[]){
  if (trg[mystrlen(trg)-1]='\n') {
      trg[mystrlen(trg)-1]='\0';
  }
  return ;
}
