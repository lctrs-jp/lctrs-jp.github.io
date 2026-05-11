#include <stdio.h>
#include <math.h>

int sum(int a,int b);
int sub(int a,int b);
int mul(int a,int b);
int div(int a,int b);
int mod(int a,int b);
int power(int a,int b);

int (*p[6])(int x,int y);

int main(void)
{
  int result;
  int i,j,num;

  p[0]=sum;
  p[1]=sub;
  p[2]=mul;
  p[3]=div;
  p[4]=mod;
  p[5]=power;

  printf("２つの数字を入力してください。\n");
  scanf("%d%d",&i,&j);
  printf("0:加算 1:減算 2:乗算 3:除算 4:余り 5:べき乗\n");

  num=6;
  for(;num<0||5<num;){
    printf("演算の番号を入力してください。\n");
    scanf("%d",&num);
  }

  result=(*p[num])(i,j);
  printf("%d\n",result);

  return 0;
}

int sum(int a,int b){
  return a+b;
}
int sub(int a, int b){
  return a-b;
}
int mul(int a,int b){
  return a*b;
}
int div(int a,int b){
  if(b)
  return a/b;
  else
    return 0;
}
int mod(int a,int b){
  if(b)
    return a%b;
  else
    return 0;
}
int power(int a,int b){
  return pow(a,b);
}
