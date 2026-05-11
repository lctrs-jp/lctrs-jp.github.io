#include<stdio.h>
#include<math.h>

int sum(int a, int b);
int subtract(int a,int b);
int mul(int a,int b);
int div(int a, int b);
int modulus(int a,int b);
int power(int a,int b);

int (*p[6]) (int x,int y);
 
int main()
{
  int result;
  int i,j,op;

  p[0]=sum;
  p[1]=subtract;
  p[2]=mul;
  p[3]=div;
  p[4]=modulus;
  p[5]=power;

  printf("２つの数字を入力してください：");
  scanf("%d%d",&i,&j);
  printf("０：加算、１：減算、２：乗算、３：除算、４：剰余、５：べき乗\n");
  do{
    printf("演算の番号を入力してください：");
    scanf("%d",&op);
  }while((op<0)||(op>5));

  result=(*p[op]) (i,j);
  printf("%d",result);

  return 0;
}

int sum(int a,int b)
{
  return a+b;
}

int subtract(int a, int b)
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
  return pow(a,b);
}
