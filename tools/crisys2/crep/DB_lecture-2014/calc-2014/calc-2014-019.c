#include <stdio.h>
/* 電卓*/

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int modulus(int a, int b);
int power(int x, int y);

int (*p[6]) (int x, int y)={ /* 計算を行う関数へのポインタ*/
  sum, subtract, mul, div, modulus, power
};

int main(void)
{
  int result;
  int i, j, op, x=0;

  printf("２つの数字を入力してください： ");
  scanf("%d%d", &i, &j);
  printf("0:加算、1:減算、2:乗算、3:除算、4:余り、5:累乗\n");
  do{
    printf("演算の番号を入力してください： ");
    scanf("%d", &op);
    if(x > 10) /* 入力が１０回以内に行われない時*/
      return 1;
    x++; 
  }while((op < 0) || (op > 5));

  result = (*p[op])(i,j); /* opで指定された計算を行う*/
  printf("%d\n", result);

  return 0;
}


/* それぞれの計算を行う関数*/
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
  return a % b;
}

int power(int x, int y)
{
  if(y == 0)
    return 1;
  else  if(y == 1)
    return x;
  else
    return x * power(x , y-1);
}
