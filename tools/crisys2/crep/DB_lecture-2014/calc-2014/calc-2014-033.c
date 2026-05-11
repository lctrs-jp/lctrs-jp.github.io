#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int power(int a, int b);
int modulus(int a, int b);

int (*p[6]) (int x, int y);

int main(void)
{
  int result;
  int i, j, op;

  p[0] = sum;
  p[1] = subtract;
  p[2] = mul;
  p[3] = div;
  p[4] = power;
  p[5] = modulus;
  printf("二つの数字を入力してください\n");
  scanf("%d%d", &i, &j);
  printf("0:加算\n1:減算\n2:乗算\n3:除算\n4:べき乗\n5:剰余算\n");
  do {
    printf("演算の番号を入力してください:\n");
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

int power(int a, int b)
{
  int ans;
  
  for (ans = 1; b > 0; b--){
    ans = ans * a;
  }

  return ans;
}

int modulus(int a, int b)
{
  /* 0で割った余りと、a < bのとき、0を返す */
  if (a < b)
    return 0;
  else if(b)
    return a % b;
  else
    return 0;
}
