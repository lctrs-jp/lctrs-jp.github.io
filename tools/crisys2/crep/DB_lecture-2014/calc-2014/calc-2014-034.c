#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int modulus(int a, int b);
int power(int x, int y);

/* ポインタ配列を初期化する */
int (*p[6]) (int x, int y) = {
  sum, subtract, mul, div, modulus, power
};

int main(void)
{
  int result, i, j, op;

  printf("2 つの数字を入力してください: ");
  scanf("%d%d", &i, &j);
  printf("0: 加算、1: 減算、2: 乗算、3: 除算、4: 剰余、5: べき乗\n");
  do {
    printf("演算の番号を入力してください: ");
    scanf("%d", &op);
  } while ((op < 0) || (op > 5));

  result = (*p[op]) (i, j);
  printf("%d", result);

  return 0;
}

int sum(int a, int b)
{
  return a + b;
}

int subtract(int a, int b)
{
  return a - b;
}

int mul(int a, int b)
{
  return a * b;
}

int div(int a, int b)
{
  if(b)
    return a / b;
  else
    return 0;
}

int modulus(int a, int b)
{
  if(b)
    return a % b;
  else
    return 0;
}

int power(int x, int y)
{
  int i = 1;

  while(y > 0){
    i = i * x;
    y--;
  }

  return i;
}
