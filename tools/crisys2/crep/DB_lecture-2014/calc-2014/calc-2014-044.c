#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int power(int a, int b);

int (*p[5]) (int x, int y) = {
    sum, subtract, mul, div, power
};

int main(void)
{
  int result;
  int i, j, op;

  printf("2つの数字を入力してください: ");
  scanf("%d%d", &i, &j);
  printf("0: 加算、1: 減算、2: 乗算、3: 除算、4:べき乗\n");

  do {
    printf("演算の番号を入力してください: ");
    scanf("%d", &op);
  } while((op < 0) || (op > 4));

  result = (*p[op]) (i, j);
  printf("%d\n", result);

  return 0;
}

int sum(int a, int b)
{
  return  a + b;
}

int subtract(int a, int b)
{
  return a - b;
}

int mul(int a,int b)
{
  return a * b;
}

int div(int a, int b)
{
  if (b)
    return a / b;
  else
    return 0;
}

int power(int a, int b)
{
  int n, m = 1;
  for(n = 0; n < b; n++)
    m = m * a;
  return m;
}
