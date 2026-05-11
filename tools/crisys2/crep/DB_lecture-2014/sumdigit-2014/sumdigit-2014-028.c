#include <stdio.h>
#include <math.h>

int sum_digit(int n);

int main(void)
{
  int a,b;

  printf("数字を入力してください。\n");
  scanf("%d",&a);

  b=sum_digit(a);
  printf("その数の桁の和を一桁になるまで計算すると、%dになります。\n",b);

  return 0;
}

int sum_digit(int n)
{
  int i;
  int x,y;
  int b[10];  //最大値は10桁。
  int c[2];  //和の最大値は、1999999999のときの82なので、必ず二けた以下。
  int d=0;

  c[1]=1;

  for(i=0;i<10;i++)
    {
      x=pow(10,i+1);
      y=pow(10,i);
      b[i] = (n%x-n%y)/y;
      d=d+b[i];
    }

  while(c[1] != 0)
    {
      c[0]=d%10;
      c[1]=(d%100-d%10)/10;
      d=c[0]+c[1];
    }
  return c[0];
}
