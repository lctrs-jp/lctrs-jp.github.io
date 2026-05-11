#include<stdio.h>

int sum(int a,int b);
int subtract(int a,int b);
int mul(int a,int b);
int div(int a,int b);
int modulus(int a,int b);
int power(int a,int b);

int(*p[6])(int x,int y)={sum,subtract,mul,div,modulus,power};

int main(void)
{
  int result;
  int i,j,op;

  printf("２つの文字の入力してください:");
  scanf("%d%d",&i,&j);
  printf("0:加算、1:減算、2:乗算、3:除算、4:剰余、5:べき乗\n");
  do{printf("演算番号を入力してください:");
    scanf("%d",&op);
  }while((op<0)||(op>5));

  result=(*p[op])(i,j);
  printf("%d\n",result);

  return 0;
 }

int sum(int a,int b)
{return a+b;}

int subtract(int a,int b)
{return a-b;}

int mul(int a,int b)
{return a*b;}

int div(int a,int b)
{if(b)
return a/b;
  else
    return 0;}

int modulus(int a,int b)
{return a%b;}

int power(int a,int b)
{int c=1,n=0;
  if(b>0) 
    { do{c=c*a;
    n++;}
while(n!=b);
      return c;  }
  if(b==0)
  return 1;
  if(b<0&&a!=1)
    return 0;
  if(b<0&&a==1)
    return 1;}
