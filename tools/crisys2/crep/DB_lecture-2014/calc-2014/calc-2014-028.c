#include<stdio.h>

int sum(int a,int b);
int subtract(int a,int b);
int mul(int a,int b);
int div(int a,int b);
int modulas(int a,int b);
int power(int a,int b);

int (*p[6]) (int x,int y);

int main(void)
{
  int result,i,j,op;

  p[0]=sum;
  p[1]=subtract;
  p[2]=mul;
  p[3]=div;
  p[4]=modulas;
  p[5]=power;

  printf("２つの数を入力してください\n");
  scanf("%d%d",&i,&j);
  printf("０：加算１：減算２：乗算３：除算４：余り５：べき乗\n");
  do{
    printf("演算の番号を入力してください\n");
    scanf("%d",&op);
  }while((op<0)||(op>5));

 result=(*p[op])(i,j);
 printf("%d",result);
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
  return a/b;
}

int modulas(int a,int b)
{
  return a%b;
}

int power(int a,int b)
{
  int k,i;
  k=1;
  for(i=0;i<b;i++)
    k=k*a;
  return k;
}
