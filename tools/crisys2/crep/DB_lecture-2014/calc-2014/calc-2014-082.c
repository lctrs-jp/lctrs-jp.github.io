#include <stdio.h>

int sum(int x, int y);
int subtract(int x, int y);
int mul(int x, int y);
int div(int x, int y);
int modulus(int x, int y);
int power(int x, int y);

int(*p[6]) (int x, int y) = {
  sum, subtract, mul, div, modulus, power
};

int main(void)
{
  int result;
  int i, j, op;

  printf("２つの数字を入力してください: ");
  scanf("%d%d", &i, &j);
  printf("0: 加算、1: 減算、2: 乗算、3: 除算、");
  printf("4: 剰余、5: べき乗\n");
  do {
    printf("演算の番号を入力してください: ");
    scanf("%d", &op);
  } while (op < 0 || op > 5);

  result = (*p[op]) (i, j);
  printf("%d", result);

  return 0;
}

int sum(int x, int y)
{
  return x + y;
}

int subtract(int x, int y)
{
  return x - y;
}

int mul(int x, int y)
{
  return x * y;
}

int div(int x, int y)
{
  if (y)
    return x / y;
  else
    return 0;
}

int modulus(int x, int y)
{
  if (y)
    return x % y;
  else
    return 0;
}

int power(int x, int y)
{
  int temp;

  temp = 1;
  for(; y > 0; y--)
    temp = temp * x;

  return temp;
}
