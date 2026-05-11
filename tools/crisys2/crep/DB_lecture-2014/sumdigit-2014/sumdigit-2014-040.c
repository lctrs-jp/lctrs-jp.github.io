/*
一般にこれは9で割った余り(但し割り切れたら9)であるので求める関数は
int sum_digit(int n){
	if(n % 9) return 9;
	else return n % 9;
}
で済むが、敢えて問題の定義通りに関数を置くことにする。
*/
#include <stdio.h>
#include <math.h>

int sum_digit(int n); // 各桁の和を1桁にして返す関数

/* main()関数は変更しない */
int main(void)
{
  int i;
  int test[][2] = { /* 入力と正しい出力のペア*/
    {9,9},
    {10,1},
    {0,0},
    {55,1},
    {123,6},
    {128,2},
    {255,3},
    {123456789,9},
    {888888888,9},
    {2147483647,1},
    {-999,0} /* テストの終わり．このテストは実行されない */
  };
  
  i = 0;
  while (test[i][0] != -999){
    if (sum_digit(test[i][0]) == test[i][1])
      printf("テスト%d は成功\n",i+1);
    else{
      printf("テスト%d は失敗!!\n",i+1);
      printf("  作った関数の出力: %d\n",sum_digit(test[i][0]));
      printf("  期待される結果  : %d\n",test[i][1]);
    }
    
    i++;
  }
  return 0;
}

/* 以下の関数を変更する */
int sum_digit(int n)
{
	int i, sum;
	while(n >= 10){
		sum = 0;
		for(i = 9; i >= 0; i--){
			sum += (int)(n / (int)(pow(10.0, i)));
			n -= ((int)(n / (int)(pow(10.0, i)))) * (int)pow(10.0, i);
		}
		n = sum;
	}
  return n;
}
