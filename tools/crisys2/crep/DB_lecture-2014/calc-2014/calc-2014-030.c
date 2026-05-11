#include<stdio.h>

int sum(int x, int y);
int modulus(int x, int y);
int power(int x, int y);

int(*p[3])(int x, int y);

int main()
{
  int result;
  int i, j, op;

  p[0] = sum;
  p[1] = modulus;
  p[2] = power;

  printf("2つの数字を入力してください:");
  scanf("%d%d", &i, &j);
  printf("0:加算, 1:余剰, 2:べき乗\n");
  do{
    printf("演算の番号を入力してください:");
    scanf("%d" , &op);
  }while ((op < 0) || (op > 2));

  result = (*p[op])(i,j);
  printf("%d" , result);

    return 0;
}

int sum(int x, int y)
{
  return x + y;
}

int modulus(int x, int y)
{
  return x % y;
}

int power(int x, int y)
{
  int pow = 1;
  for(; y > 0; y--){
    pow = pow * x;
  }
  return pow;
}
