#include<stdio.h>

int sum(int a,int b);
int subtract(int a,int b);
int mul(int a,int b);
int div(int a,int b);
int modulus(int a,int b);/*余り出力*/
int power(int a,int b);/*aのb乗*/

int(*p[6])(int x,int y);

int main()
{int result,i,j,op;

  p[0]=sum;
  p[1]=subtract;
  p[2]=mul;
  p[3]=div;
  p[4]=modulus;
  p[5]=power;

  printf("You should put two number baby.\n");
  scanf("%d%d",&i,&j);
  printf("0:sum 1:subtract 2:mul 3:div 4:modulas 5:power \n");
  do{
    printf("choice number baby.\n");
    scanf("%d",&op);
  }while((op < 0) || (op > 6));

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
  if(b)
    return a/b;
  else
    printf("error");
      return 0;
}

int modulus(int a,int b)
{
  return a%b;
}

int power(int a,int b)
{
  int q,z;
  z=a;
  for(q=1;q<b;q++)
    z=z*a;
  return z;
}
