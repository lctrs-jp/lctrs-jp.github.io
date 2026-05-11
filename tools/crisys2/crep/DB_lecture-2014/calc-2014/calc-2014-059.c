#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int modulus(int a, int b);
int power(int a, int b);

int (*p[6]) (int x, int y);

int main()
{
  int result;
  int i, j, op;

  p[0] = sum;
  p[1] = subtract;
  p[2] = mul;
  p[3] = div;
  p[4] = modulus;
  p[5] = power;

  printf("２つの数字を入力してください。:");
  scanf("%d%d", &i, &j);
  printf("0:加算, 1:減算, 2:乗算, 3:除算, 4:剰余算, 5:べき算 \n");
  do{
    printf("演算の番号を入力してください。:");
    scanf("%d", &op);
  }while( (op < 0) || (op > 5) );

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
  if( b != 0 ) 
    return a / b;
  else
    return 0;
}

int modulus(int a, int b)
{
  if( b != 0 ) 
    return a % b;
  else
    return 0;
}

int power(int a, int b)
{
  int ans = 1;
  int i;

  for( i = 0; i < b; i++ )
    ans = ans * a;

  return ans;
}

