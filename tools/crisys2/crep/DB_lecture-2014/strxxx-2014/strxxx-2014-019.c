#include<stdio.h>

int mystrlen(char x[]);
void mystrcat(char x[], char y[]);
void mystrcpy(char x[], char y[]);

int main(void) {

  char str1[80], str2[20];
  int i;
 
  printf("第一の文字列を入力してください:");
  fgets (str1, 80, stdin);
  printf("第二の文字列を入力してください:");
  fgets (str2, 20, stdin);

  //文字列の長さを確認する//
  printf("%sは%d文字の長さです\n", str1, mystrlen(str1)-1);
  printf("%sは%d文字の長さです\n", str2, mystrlen(str2)-1);

  //十分なスペースがあれば、str2をstr1の最後に連結する//
  if (( mystrlen(str1) + mystrlen(str2) ) < 80) {
    mystrcat(str1,str2);
    printf("%s\n", str1);
  }

  //str2をstr1にコピーする//
  mystrcpy(str1,str2);
  printf("%s%s\n", str1, str2);

  
  return 0;
}

int mystrlen(char x[]) {

  int len = 0;
  while (x[len]) len++;

  return len;
}

void mystrcat(char x[],char y[]) {

  int i, lenx, leny;
  lenx = mystrlen(x);
  leny = mystrlen(y);
  
  for(i = lenx;i <= (lenx +leny + 1); i++) {
    x[i] = y[i - lenx];
  }
  return ; 
}

void mystrcpy(char x[],char y[]) {
  
  int i;
  for(i = 0;i <= (mystrlen(y) + 1 ); i++) {
    x[i] = y[i];
  }
  return ;
}  
