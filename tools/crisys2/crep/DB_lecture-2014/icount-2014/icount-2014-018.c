#include <stdio.h>

/* 文字列に含まれる各数字の個数を表示するプログラム*/
int main()
{
  char num[102];
  int i,a[10];/* a[]は各数字の個数を入れる*/
  for (i=0; i<10; i++){
    a[i] = 0;
  }

  printf("数字列を入力してください(長さ100以下) : ");
  fgets(num, 102, stdin);

  for (i=0; num[i]!='\n'; i++){

    /* 数字以外は飛ばす*/
    if (num[i]<48 || num[i]>58)
      continue;

    /* 文字列の数字を整数に変換し、a[]に１を加える*/
    a[((int)num[i])-48]++;
  }

  for (i=0; i<10; i++){
    printf("%d は %d個含まれています.\n", i ,a[i]);
  }

  return 0;
}
