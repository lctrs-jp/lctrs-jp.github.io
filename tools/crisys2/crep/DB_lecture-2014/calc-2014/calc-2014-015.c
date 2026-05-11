#include <stdio.h>
int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int modulus(int a, int b);
int power(int a, int b);
int (*p[6]) (int x, int y);
int main(void){
  int result, i, j, op;
  p[0] = sum; /* sum() のアドレスを取得する*/
  p[1] = subtract; /* subtract() のアドレスを取得する*/
  p[2] = mul; /* mul() のアドレスを取得する*/
  p[3] = div; /* div() のアドレスを取得する*/
  p[4] = modulus; /* modulus()のアドレスを取得する*/
  p[5] = power;
  printf("2 つの数字を入力してください: ");
  scanf("%d%d", &i, &j);
  printf("0: 加算、1: 減算、2: 乗算、3: 除算、4:剰余、5:べき乗\n");
  do {
    printf("演算の番号を入力してください: ");
    scanf("%d", &op);
  } while ((op < 0) || (op > 5));
  result = (*p[op]) (i, j);
  printf("%d",result);

  return 0;
}

int sum(int a, int b)
{
  return a+b;
}

int subtract(int a, int b)
{
  return a-b;
}

int mul(int a, int b)
{
  return a*b;
}

int div(int a, int b)
{
  if(b)
    return a/b;
  else
    return 0;
}

int modulus(int a, int b)
{
  if(b)
    return a%b;
  else
    return 0;
}

int power(int a,int b)
{
  int l=a;

  if(b){
    for(;b>1;b--)
      a=a*l;   
    return a;}
  else return 1;

}
