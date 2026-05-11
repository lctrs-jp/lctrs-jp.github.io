#include<stdio.h>
#include<math.h>

int sum(int a, int b);
int subtract(int a,int b);
int mul(int a, int b);
int div(int a, int b);
int power(int a, int b);

int (*p[5]) (int x, int y);

int main()
{
  int result;
  int i , j , op;
 
  p[0] = sum; //sumのアドレスを取得
  p[1] = subtract; //subtractのアドレスを取得
  p[2] = mul; //mulのアドレスを取得
  p[3] = div; //divのアドレスを取得
  p[4] = power; //powerのアドレスを取得

  printf("2つの数字を入力してください:");
  scanf("%d%d", &i , &j );
  printf("0:加算,1:減算,2:乗算,3:除算,4:べき乗算\n");
  do{
    printf("演算の番号を入力してください:");
    scanf("%d",&op);
  }while((op < 0)||(op > 4));

  result = (*p[op]) (i,j);
  printf("演算結果は%d",result);

  return 0;
}

int sum(int a, int b)
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

int div(int a, int b)
{
  return a / b;
} 

int power(int a, int b)
{
  int k;
  int save = a;
  for(k = 0; k < (b - 1); k++)
    a = a * save;

  return a;
}
