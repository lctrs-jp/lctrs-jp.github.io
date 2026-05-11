#include<stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int power(int a, int b);

int (*p[5]) (int x, int y);

int main (void)
{
  int result;
  int i, j, op;

  p[0] = sum; 
  p[1] = subtract;
  p[2] = mul;
  p[3] = div;
  p[4] = beki;
 
  printf("2つの数字を入力してください: "); 
  scanf("%d%d", &i, &j);  
  printf("0: 加算、1: 減算、2: 乗算、3: 除算、4:べき乗計算\n");
do  
  { 
    printf("演算の番号を入力してください: ");
    scanf("%d", &op);
  }
 while ((op < 0) || (op > 4));

 result = (*p[op]) (i, j);
 printf("%d", result);
   return 0;
  }

 int sum(int a,int b)
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
int power(int a, int b)
{
  int c,d;
  c = 1;
  for(d = 1;d <= b; d++)
    c = c * a;
  return c;
}
 int div(int a, int b)
 {
   if (b)
     return a / b;
   else 
     return 0;
}

 
