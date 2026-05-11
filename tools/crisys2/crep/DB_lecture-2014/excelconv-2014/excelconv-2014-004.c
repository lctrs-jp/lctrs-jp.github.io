//11月22日の課題
//エクセルの列名を10進数で表現するプログラム
#include <stdio.h>
#include <stdlib.h>	//exit()
#include <string.h>	//strlen()
#include <math.h>	//pow()

int Atoi(char *str, int n);	//列名を１０進数に変換する関数
//int alph_to_num(char c);	//大文字のアルファベットを整数に変換する関数

int main(int argc, char *argv[])
{
  int sum=0;
  int i, len;

  //エラー処理
  //引数を確認
  if (argc != 2){
    printf("引数は１つです\n");
    exit(1);
  }
  len = strlen(argv[1]);	//argv[1]があれば
  //大文字のみか確認
  for (i = 0; i < len; i++){
    if (*(argv[1]+i) < 65 || 90 < *(argv[1]+i)){
      printf("アルファベットの大文字以外変換できません\n");
      exit(1);
    }
  }
  //範囲を確認
  if (len < 1 || 5 < len){
    printf("範囲はA～ZZZZZです\n");
    exit(1);
  }

  sum = Atoi(argv[1], len);
  printf("%d\n", sum);

  return 0;
}

//"ABC"なら3, 3 + 26*2, 3+26*2 + 26^2*1の数列で考える
//a_n = 26^(n-1)*x_n + a_(n-1)  この漸化式で計算
//x_nはｎ桁目の値  ABの場合x_1 = 2, x_2 = 1
int Atoi(char *str, int n)
{
  if (n <= 0)
    return 0;
  else
    return pow(26, n-1) * (*(str + strlen(str) - n) - 64) + Atoi(str, n - 1);
    //return pow(26,n-1)*alph_to_num(*(str+strlen(str)-n))+Atoi(str,n-1);
}

/*
int alph_to_num(char c)
{
  return c - 64;
}
*/
