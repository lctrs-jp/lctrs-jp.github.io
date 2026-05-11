#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int modulas(int a, int b);
int power(int a, int b);

int(*p[6])(int x, int y)  = {
  sum, subtract, mul, div, modulas, power
};

int main(void)
{
  int result;
  int i,j, op;

  printf("二つの数字を入力してください:");
  scanf("%d%d", &i, &j);
  printf("0: 加算、1:減算、2:乗算、3:除算、4:剰余、5:べき乗\n");
  do{
    printf("演算の番号を入力してください:");
    scanf("%d", &op);
  }while((op < 0) || (op > 5));

  result = (*p[op]) (i, j);
  printf("%d", result);

  return 0;
}
int sum(int a, int b)
{
  return a + b;
}

int subtract(int a , int b)
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

int modulas(int a, int b)
{
  if(b)
    return a % b;
  else
    return 0;
}

int power(int a, int b)
{
  int k ,t;
  if(b != 0){
    t = a;
    for( k = 1;k < b; k++){
      t = t * a;
    }
    return t;
  }
  else
    return 1;
}
