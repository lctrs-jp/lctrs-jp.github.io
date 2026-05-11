#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int modulus(int a, int b);
int power(int a, int b);

//ポインタ配列の初期化
int (*p[6]) (int x, int y) = {
  sum, subtract, mul, div, modulus, power
    };

int main(void)
{
  int result;
  int i, j, op;

  printf("２つの数字を入力してください： ");
  scanf("%d%d", &i, &j);
  printf("0: 加算、1: 減算、2: 乗算、3: 除算、4: 剰余、5: べき乗\n");
  do {
    printf("演算の番号を入力してください： ");
    scanf("%d", &op);
  } while((op < 0) || (op > 5));

  result = (*p[op]) (i, j);
  printf("演算結果： %d\n", result);

  return 0;
}

//加算を行う関数
int sum(int a, int b)
{
  return (a + b);
}

//減算を行う関数
int subtract(int a, int b)
{
  return (a - b);
}

//乗算を行う関数
int mul(int a, int b)
{
  return (a * b);
}

//除算を行う関数
int div(int a, int b)
{
  if (b)
    return (a / b);
  else
    return 0;
}

//剰余を求める関数
int modulus(int a, int b)
{
  if (b)
    return (a % b);
  else
    return 0;
}

//べき乗を行う関数
int power(int a, int b)
{
  int i, j = a;

  if (b) {
    for(i = 1; i < b; i++)
      j = j * a;
    return j;
  }
  else
    return 1;
}
