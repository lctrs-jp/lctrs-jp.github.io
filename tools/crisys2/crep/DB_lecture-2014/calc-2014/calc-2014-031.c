#include <stdio.h>
#include <math.h>

int sum(int a,int b);
int subtract(int a,int b);
int mul(int a,int b);
int div(int a,int b);
int mod(int a,int b); //剰余関数を追加
int power(int a,int b); //べき乗関数を追加
int (*p[6])(int x,int y);

int main(void)
{
  int result,i,j,op;

  p[0]=sum;
  p[1]=subtract;
  p[2]=mul;
  p[3]=div;
  p[4]=mod;
  p[5]=power;

  printf("２つの数字を入力してください: ");
  scanf("%d%d",&i,&j);
  printf("0: 加算、1: 減算、2: 乗算、3: 除算、4: 剰余、5: べき乗\n");
  do{
    printf("演算の番号を入力してください: ");
    scanf("%d",&op);
  }while((op<0) || (op>5)); //範囲を5までに変更
  result =(*p[op])(i,j);

  printf("答えは、%dです。\n",result);

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

int mod(int a,int b)
{
  return a%b;
}

int power(int a,int b)
{
  return pow(a,b); //math.hの関数を使用
}
