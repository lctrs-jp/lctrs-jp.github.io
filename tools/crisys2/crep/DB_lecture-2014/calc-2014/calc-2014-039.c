#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int power(int x, int y);
int modulus(int x, int y);

int (*p[6]) (int x, int y);

int main (void)
{
  int result;
  int i, j, op;

  p[0] = sum; //sum()のアドレスを取得する
  p[1] = subtract;
  p[2] = mul;
  p[3] = div;
  p[4] = power;
  p[5] = modulus;

  printf("2つの数字を入力してください:");
  scanf("%d%d", &i, &j);
  printf("0:加算\n1:減算\n2:乗算\n3:除算\n4:べき乗\n5:剰余算\n");
  
  do {
    printf("演算の番号を入力してください:");
    scanf("%d",&op);
  }while ((op < 0) || (op > 5));

  result = (*p[op]) (i,j);
  printf("%d\n",result);

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
  if (b)
    return a / b;
  else
    return 0;
}

int power(int x, int y)
{
  int i, j;

  j = x;
  
  for(i = 1; i < y; i++){
    j = j * x;
  }

  return j;
}

int modulus(int x, int y)
{
  return x % y;
}
