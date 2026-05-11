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
  int sum;
  int a[10];
  int i, x;

  if( n > 9 )
    {
      sum = n;
      
      
      while( sum > 9 )//1桁になるまで繰り返し
	{
	  x = 1;
	  /* 各桁の数の抽出 */	  
	  for( i = 0; i < 9; i++ ) 
	    {
	      x = x * 10;
	      a[i] = ( sum % x ) / ( x / 10 ); 
	      	    }
	  a[9] = sum / x;//バグの回避のため、別で用意
	  
	  /* 和をとる */
	  sum = a[0] + a[1] + a[2] + a[3] + a[4] +
                a[5] + a[6] + a[7] + a[8] + a[9]; 
	}
      
      n = sum;
    }      


  return n;
}
