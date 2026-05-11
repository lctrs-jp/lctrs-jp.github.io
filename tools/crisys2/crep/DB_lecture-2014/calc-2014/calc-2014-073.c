#include <stdio.h>
int sum(int a, int b);     /* 2数の和を計算する関数 */
int subtract(int a, int b);/* 2数の差を計算する関数 */
int mul(int a, int b);     /* 2数の積を計算する関数 */
int div(int a, int b);     /* a / b の商を計算する関数 */
int modulus(int a, int b); /* a / b の余りを計算する関数 */
int power(int a, int b);   /* a ^ b を計算する関数 */

int (*p[6]) (int x, int y);

int main(void){
  int result, i, j, op;
  p[0] = sum;      /* sum()の呼び出し */
  p[1] = subtract; /* subtract()の呼び出し */
  p[2] = mul;      /* mul()の呼び出し */
  p[3] = div;      /* div()の呼び出し */
  p[4] = modulus;  /* modulus()の呼び出し */
  p[5] = power;    /* power()の呼び出し */

  printf("2つの数字を入力してください。:　");
  scanf("%d%d", &i, &j);
  printf("0: 加算、1: 減算、2: 乗算、3: 除算 、4: 剰余、5: 乗算\n");
  do{
    printf("演算の番号を入力してください。：　");
    scanf("%d", &op);
  }
  while((op < 0) || (op > 5));
    result = (*p[op])(i, j);
    printf("計算結果：%d \n", result);
  return 0;
}

  int sum(int x, int y){
    int ans;
    ans = x + y;
    return ans;
  }
  int subtract(int x, int y){
    int ans;
    ans = x - y;
    return ans;
  }
  int mul(int x, int y){
    int ans;
    ans = x * y;
    return ans;
  }
  int div(int x, int y){
    int ans;
    if(y){
    ans = x / y;
    return ans;
    }
    else
      return 0; /* 割る数が0のとき、計算例外として0を表示する */
  } 
  int modulus(int x, int y){
  int ans;
  if(y){
  ans = x % y;
  return ans;
  }
  else
    return 0; /* 割る数が0のとき、計算例外として0を表示する */
  }
  int power(int x, int y){
    int ans;
    if(x == 0 && y == 0)
      ans = 0; /* 指数と底が0のとき計算不可として0を表示する */
    else if(y == 0)
      ans = 1; /* 指数が0のとき1を表示する */
    else{
      ans = x;
      y--; 
      for( ;y > 0; y--)
	ans = ans * x;
    }
    return ans;
  }

