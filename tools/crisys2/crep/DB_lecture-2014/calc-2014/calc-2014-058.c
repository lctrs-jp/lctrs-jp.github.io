#include<stdio.h>
int sum(int a,int b);
int subtract(int a,int b);
int mul(int a, int b);
int div(int a,int b);
int modulus(int a,int b);
int power(int a,int b);

int(*p[6])(int x,int y);

int main(void)
{
  int result;
  int i,j,op;

  p[0]=sum;
  p[1]=subtract;
  p[2]=mul;
  p[3]=div;
  p[4]=modulus;
  p[5]=power;

  printf("2つの数字を入力してください:");
  scanf("%d%d",&i,&j);
  printf("0:加算,1:減算,2:乗算,3:除算,4:剰余,5:累乗\n");
  do{
    printf("演算の番号を入力してください:");
    scanf("%d",&op);
  }while((op<0)&&(op>3));

  result=(*p[op])(i,j);
  printf("%d\n",result);

  return 0;
}

int sum(int a,int b)
{
  return a+b;
}

int subtract(int a,int b)
{
  return a-b;
}

int mul(int a,int b)
{
  return a*b;
}

int div(int a,int b)
{
  if(b)
    return a/b;
  else
    return 0;
}

int modulus(int a,int b)
{
  return a%b;
}

int power(int a,int b)
{
  int k=1;
  int m;
  for(m=0;m<b;m++)
    k=k*a;
  return k;
}
