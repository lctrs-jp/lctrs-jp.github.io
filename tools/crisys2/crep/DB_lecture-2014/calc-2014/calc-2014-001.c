#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int power(int x, int y);	// int型なので暗黙の了解としてy>=0
int modulus(int x, int y);

int (*p[6]) (int x, int y) = {
  sum, subtract, mul, div, power, modulus
};

int main(void)
{
  int result;
  int i, j, op;

  printf("2つの数字を入力してください: ");
  scanf("%d%d", &i, &j);
  printf("0: 加算、1: 減算、2: 乗算、3: 除算、4: べき乗、5: 剰余\n");
  do {
    printf("演算の番号を入力してください: ");
    scanf("%d", &op);
  } while((op < 0) || (op > 5));

  result = (*p[op]) (i, j);
  printf("%d\n", result);

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

int power(int x, int y)
{
  if(y > 0)
    return x * power(x, y-1);
  else
    return 1;
}

int modulus(int x, int y)
{
  return x % y;
}
