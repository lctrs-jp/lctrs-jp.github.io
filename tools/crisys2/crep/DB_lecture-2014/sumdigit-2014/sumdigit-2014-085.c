#include <stdio.h>
#include <string.h>
#include <math.h>

int gassan(int n);
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

int gassan(int n)
//各桁の和を求める操作を一回だけ行う関数
{

  int keta, k, end, nn;

  k = 1;
  end = 1;
  nn = n;

  //nnが一桁になるまで、nnを10で割り続ける
  //得られた桁数はketaに取る
  while(end != 0){
    if(0 <= nn && nn <= 9){
      keta = k;
      end = 0;
    }else{
      nn = nn / 10;
      k++;
    }
  }

  int kurai[20], j, gen;//kurai[j]はnのj桁目の値 genは桁数を減じるのに使う
  //以下の計算の具体例
  //n = 70000
  //keta = 5(上で求めた)
  //kurai[5] = (70000 - gen)/10^4
  //gen = gen + kurai[5] * 10^4
  //kurai[4] = (70000 - gen)/10^3
  //gen = gen + kurai[4] * 10^3
  //以上の操作を,kurai[1]が得られるまで続ける
  j = keta;
  gen = 0;
  while(j != 0){
    kurai[j] = (n - gen) / pow(10, j-1);
    gen = gen + kurai[j] * pow(10, j-1);
    j--;
  }

  int wa;//nの各桁の和
  j = 1;
  wa = 0;

  while (j <= keta){
    wa = wa + kurai[j];
    j++;
  }

  return wa;
}

int sum_digit(int n)
// 各桁の和を求める関数．
// 一桁の値が得られるまで,
//gassan()で各桁の和を取り続ける.
{
  int finish; 
  finish  = 1;

  int kekka;
  kekka = gassan(n);

  while(finish != 0){
    if(0 <= kekka && kekka <= 9){
      finish = 0;
    }else{
      kekka = gassan(kekka);
    }
  }
  
  return kekka;
}
