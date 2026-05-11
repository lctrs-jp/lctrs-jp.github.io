#include <stdio.h>
int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int modulus(int a, int b);
int power(int a, int b);

int(*p[6])(int x, int y) = {sum, subtract, mul, div, modulus, power};

int main(void)
{
  int result, i, j, op;

  p[0] = sum;
  p[1] = subtract;
  p[2] = mul;
  p[3] = div;
  p[4] = modulus;
  p[5] = power;

  printf("２つの数字を入力してください:");
  scanf("%d %d", &i, &j);
  printf("0:加算、1:減算、2:乗算、3:除算 4:剰余 5:累乗\n");
do
  {
    printf("演算の番号を入力してください:");
    scanf("%d", &op);
  }
 while((op < 0) || (op > 5));
 result = (*p[op])(i, j);

 printf("%d\n", result);

 return 0;
}

int sum(int a,int b) /* 加算 */
{
  return a + b;
}

int subtract(int a, int b) /* 減算 */
{
  return a - b;
}

int mul(int a,int b) /* 乗算 */
{
  return a * b;
}

int div(int a,int b) /* 除算 */
{
  if(b)
    return a / b;
  else
    return 0;
}

int modulus(int a, int b) /* 剰余 */
{
  if(b != 0)
    return a % b;
  else
    printf("数を0で割ることはできません\n" );
    return 0;
}

int power(int a, int b) /* 累乗 */
{
  int n, i; 
  i = 1;
  n = 1;
  
  for(i = 1; i <= b; i++)
    {
      n = n * a;
    }
  return n;
} 
