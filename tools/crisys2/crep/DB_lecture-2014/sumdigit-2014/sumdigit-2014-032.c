#include <stdio.h>

int sum_digit(int n); // 各桁の和を1桁にして返す関数
int expten(int m);
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
  int figure[10];//桁は10桁までしかない
  int i,k;
  int result;
  result=n;

  while(0<1) {
    //各位の値をfigure変数に代入
    for(i=0;i<10;i++) {
      figure[i]=(result/(expten(i)))%10;
    }
    //各位の値の和をresultに代入
    result=0;
    for(i=0;i<10;i++) {
      result+=figure[i];
    }
    //resultが1桁ならwhileループを抜ける
    if (result<10) {
      break;
    }
  }
  return result;
}

//10を引数の数だけべき乗した値を返すだけの関数
int expten(int m) {
  int j;
  int ret=1;
  for(j=0;j<m;j++){
    ret=ret*10;
  }
  return ret;
}
