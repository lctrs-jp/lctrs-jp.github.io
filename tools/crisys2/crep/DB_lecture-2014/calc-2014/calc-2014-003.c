#include <stdio.h>


int sum(int a, int b);
int subtruct(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int power(int a, int b);
int modulus(int a, int b);

/*初期化*/
int (*p[6])(int x, int y)={
  sum, subtruct, mul, div, power, modulus};

int main(void)
{

  int result;
  int i, j, op;
  printf("数字を二つ入力してください\n");
  scanf("%d%d",&i,&j);
  printf("0:sum 1:sub 2:mul 3:div 4:pwr 5:mod\n");
  do{
    printf("演算の番号を選んでください\n");
    scanf("%d",&op);
  }while((op<0)||(op>5));

  result=(*p[op]) (i,j);
  printf("%d\n",result);
  return 0;
}

int sum(int a,int b)
{return a+b;}

int subtruct(int a,int b)
{return a-b;}

int mul(int a,int b)
{return a*b;}

int div(int a,int b)
{
  if (b) return a/b;
  else return 0;} 

int power(int a, int b)
{int n=0,m=1;

    for(n=0;n<b;n++){
      m=m*a;}
    return m;}

int modulus(int a, int b)
{
  if (b) return a%b;
  else return 0;
}
