#include <stdio.h>

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
// 各桁の和を求める関数．
// ただし和が2桁以上なら，さらに各桁の和を計算し，
// 1桁になるまで繰り返す．
{
  int a[10], b[10], l[10], m[10], j, k, sum, sum2;

  sum = 0;
  a[0] = n / 10;
  l[0] = n % 10;
  for(j = 0; a[j] != 0; j++){
    a[j+1] = a[j] / 10;
    l[j+1] = a[j] % 10;
    sum = sum + l[j+1];
  }
  sum = sum + l[0];

  while(sum > 9){
    sum2 = 0;
    b[0] = sum / 10;
    m[0] = sum % 10;
    for(k = 0; b[k] != 0; k++){
      b[k+1] = b[k] / 10;
      m[k+1] = b[k] % 10;
      sum2 = sum2 + m[k+1];
    }
    sum = sum2 + m[0];
  }

  return sum;
}
