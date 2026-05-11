
#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int modulus(int a, int b);
int power(int a, int b);

int (*p[6]) (int x, int y);

int main(void)
{
  int result;
  int i, j, op;

  p[0] = sum; /* sum()のアドレスを取得する */
  p[1] = subtract; /* subtract()のアドレスを取得する */
  p[2] = mul; /* mul()のアドレスを取得する */
  p[3] = div; /* div()のアドレスを取得する */
  p[4] = modulus; /*modulus()のアドレスを取得する*/
  p[5] = power; /*power()のアドレスを取得する*/

  printf("2つの数字を入力してください: ");
  scanf("%d%d", &i, &j);
  printf("0: 加算、1: 減算、2: 乗算、3: 除算、4: 余り、5: べき乗\n");
  do {
    printf("演算の番号を入力してください: ");
    scanf("%d", &op);
  } while ((op < 0) || (op > 5));

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
  if (b)
    return a / b;
  else
    return 0;
}

int modulus(int a, int b)
{
  if (b)
    return a % b;
  else
    return 0;
}

int power(int a, int b)
{
  int k;
  if(b == 0)
    return 1;
  else if(b > 0)
    for (k = 1; b > 0; --b)
      k = k * a;
    return k;
}
