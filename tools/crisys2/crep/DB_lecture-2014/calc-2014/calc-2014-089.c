#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);
int power(int a, int b);

int (*p[6]) (int x, int y) = {
  sum, subtract, mul, div, mod, power
};

int main(void)
{
  int result;
  int i, j, op;
  printf("２つの数字を入力してください: ");
  scanf("%d%d",&i, &j);
  printf("0： 加算,１：減算、２：乗算、３：除算、４：合同式、５：べき乗\n");
  do{
     printf("演算の番号を入力してください: ");
     scanf("%d", &op);
  } while((op < 0) || (op > 5));

  result = (*p[op]) (i, j);
  printf("%d\n", result);
  return 0;
}

int sum(int a,int b)
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
  if( b != 0)
    return a / b;
  else
    return 0;
}

int mod(int a, int b)
{
  return a % b;
}

int power(int a, int b)
{
  int i = a;
  for(; b > 1; b--)
    i = i * a;
  return i;
}
