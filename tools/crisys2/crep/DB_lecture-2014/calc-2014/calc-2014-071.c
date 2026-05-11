#include <stdio.h>

int sum(int a, int b);
int substract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int rest(int a, int b);
int power(int a, int b);

int (*p[6]) (int x, int y);

int main(void)
{
  int result;
  int i, j, op;

  p[0] = sum; /*sumのアドレスを取得する*/
  p[1] = substract; /*substractのアドレスを取得する*/
  p[2] = mul; /*mulのアドレスを取得する*/
  p[3] = div; /*divのアドレスを取得する*/
  p[4] = rest; /*restのアドレスを取得する*/
  p[5] = power; /*powerのアドレスを取得する*/

  printf("２つの数字を入力してください: ");
  scanf("%d%d", &i, &j);
  printf("0: 加算、1: 減算、2: 乗算、3: 除算、4: 剰余算、5: べき乗\n");
  do {
    printf("演算の番号を入力してください: ");
    scanf("%d", &op);
  } while ((op < 0) || (op > 5));

  result = (*p[op]) (i,j);
  printf("%d", result);

  return 0;
}

int sum(int a, int b)
{
  return a + b;
}

int substract(int a, int b)
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

int rest(int a, int b)
{
  if(b)
    return a % b;
  else
    return 0;
}

int power(int a, int b)
{
 int p, q = 1;
  for(p = 1; p <= b; p++)
    q = q * a;
  return q;  
}
   
