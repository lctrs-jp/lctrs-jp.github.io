#include<stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int modulus(int a, int b);
int power(int x, int y);

int(*p[6]) (int x, int y);

int main()
{
  int result;
  int i, j, op;

  p[0] = sum; //sumのアドレスを取得する
  p[1] = subtract; //subtractのアドレス
  p[2] = mul; //mulのアドレス
  p[3] = div; //divのアドレス
  p[4] = modulus; //modulsのアドレス
  p[5] = power; //powerのアドレス

  printf("2つの数字を入力してください:");
  scanf("%d%d", &i, &j);
  printf("0: 加算、1: 減算、2: 乗算、3: 除算、4: 剰余、5: べき乗\n");
  do{
    printf("演算の番号を入力してください:");
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
  if(b)
    return a % b;
  else
    return 0;
}

int power(int x, int y)
{
  int ans = 1;
  int i;

  for(i = 0; i < y; i++)
    ans = ans * x;

  return ans;
}
