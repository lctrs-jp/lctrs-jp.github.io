#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int modulus(int a, int b);
int power(int a, int b);
//ポインタ配列を初期化
int (*p[6]) (int x, int y) = {sum, subtract, mul, div, modulus, power};

int main (void)
{
  int result;
  int i, j, op;

  printf("2つの数字を入力してください\n1つめ： ");
  scanf("%d", &i);
  printf("2つめ： ");
  scanf("%d", &j);
  printf("0：加算、1：減算、2：乗算、3：除算、4：余りをだす、5：べき乗\n")\
;

  do {
    printf("演算の番号を入力してください：");
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

int modulus(int a, int b)
{
  return a % b;
}

int power(int a, int b)
{
  if(b)
    return a * power(a, b - 1);
  else
    return 1;
}
