#include<stdio.h>

int sum1(int i);
int sum2(int j);

int main()
{
 int num;
 printf("Input a natural number: ");
 scanf("%d", &num);
printf("result by sum1: %d\n",sum1(num));
printf("result by sum2: %d\n",sum2(num));
return 0;
}

int sum1(int i)
{
int a, b;
b=0;
if(i<0) return 0;
else
 {
  for(a=0;a<=i;a++)
 {
   b=b+a;}
  return b;
 }
}

int sum2(int j)
{
  if(j<0)return 0;
 else {
 return (sum2(j-1)+j);
}
}
