#include <stdio.h>
#include <stdlib.h>

int sum(int a,int b);
int subtruct(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int power(int a, int b);
int last(int a, int b);

int main()
{
  int result;
  int i,j ,op;

  printf ("二つの文字を入力してください: ");
  scanf("%d%d", &i, &j);
  printf("0: 加算 1:減算 2:乗算 3:除算 4:余り 5:べき乗\n");
  do {
    printf("演算の番号を押してください: ");
    scanf("%d", &op);
  }while ((op<0) || (op>5));

  result = (*p[op]) (i, j);
  printf("%d", result);

  return 0;
}

int sum(int a,int b)
{
  return *(int*)i - *(int*)j;
}

int modulus(int a, int b);
{
  return a % b;
}
