#include <stdio.h>

int sum(int m, int n);
int subtract(int m, int n);
int mul(int m, int n );
int div(int m, int n);
int modulus(int m, int n);
int power(int a, int b);

int (*p[6])(int a, int b)={
  sum, subtract, mul, div, modulus, power
};

int main(void)
{
  int result, x, y, op;
  printf("二つの数字を入力してください：");
  scanf("%d%d", &x,&y);
  printf("0:加算　1:減算　2:乗算　3:除算　4:剰余　5:べき算\n");
  do{
    printf("演算の番号を入力してください：");
    scanf("%d", &op);
  } while((op<0)||(op>5));

  result=(*p[op])(x,y);
  printf("%d",result);

  return 0;
}

int sum(int m, int n)
{
  return m+n;
}

int subtract(int m, int n)
{
  return m-n;
}

int mul(int m,int n)
{
  return m*n;
}

int div(int m, int n)
{
  if(n)
    return m/n;
  else  
    return 0;
}

int modulus(int m, int n)
{
  if(n)
    return m%n;
  else
    return 0;
}

int power(int a,int b)
{
  int x=1;

  while(b>0){
    x=x*a;
    b--;
  }

  return x;
}


 
