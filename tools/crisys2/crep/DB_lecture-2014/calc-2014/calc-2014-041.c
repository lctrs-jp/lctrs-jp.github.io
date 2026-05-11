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
  p[4] = modulus;
  p[5] = power;

  printf("2つの数字を入力してください: ");
  scanf("%d%d", &i, &j);
  printf("0: 加算、1: 減算、2: 乗算、3: 除算、４：あまり、５：べき乗 \n");
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
  if (b)
    return a / b;
  else
    return 0;
}

int modulus(int a, int b)
{
  return a%b;
}

int power(int a, int b)
{int n, m=a;
  if(b==0)
    return 1;
  else if(b==1)
    return a;
  else if(b>1)
    for(n=1;n<b;n++)
      m=m*a;
  return m;
}
    
   
